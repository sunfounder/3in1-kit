.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_shiftout:

5.9 ShiftOut(LED)
=======================

``shiftOut()`` hace que el 74HC595 emita 8 señales digitales. Envía el último bit del número binario a Q0 y la salida del primer bit a Q7. En otras palabras, escribir el número binario “00000001” hará que Q0 emita un nivel alto y Q1~Q7 emitan un nivel bajo.

En este proyecto, aprenderás a utilizar el 74HC595. El 74HC595 consta de un registro de desplazamiento de 8 bits y un registro de almacenamiento con salidas paralelas de tres estados. Convierte la entrada serial en salida paralela, lo que te permite ahorrar puertos IO de un MCU.

Específicamente, el 74hc595 puede reemplazar 8 pines para la salida de señal digital escribiendo un número binario de 8 bits.

* `Número binario - Wikipedia <https://en.wikipedia.org/wiki/Binary_number>`_

**Componentes Necesarios**

En este proyecto, necesitamos los siguientes componentes.

Definitivamente es conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ARTÍCULOS EN ESTE KIT
        - ENLACE
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

También puedes comprarlos por separado en los siguientes enlaces.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Esquema**

.. image:: img/circuit_6.4_74hc595.png

* Cuando MR (pin 10) está en nivel alto y OE (pin 13) en nivel bajo, los datos se ingresan en el borde ascendente de SHcp y pasan al registro de memoria a través del borde ascendente de SHcp.
* Si los dos relojes están conectados juntos, el registro de desplazamiento siempre está un pulso antes que el registro de memoria.
* Hay una entrada de desplazamiento serial (Ds), una salida serial (Q) y un botón de reinicio asincrónico (nivel bajo) en el registro de memoria.
* El registro de memoria emite un Bus con 8 bits paralelos y en tres estados.
* Cuando OE está habilitado (nivel bajo), los datos en el registro de memoria se emiten al bus (Q0 ~ Q7).

**Cableado**

.. image:: img/74hc595_bb.jpg
    :width: 800
    :align: center

**Código**

.. note::

    * Abre el archivo ``5.9.shiftout_led.ino`` en la ruta ``3in1-kit\basic_project\5.9.shiftout_led``.
    * O copia este código en el **Arduino IDE**.
    
    * O carga el código a través del `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/4c208eb3-67f0-40f7-999a-0eeca8b6b466/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Una vez que hayas cargado los códigos en la placa R3, verás que los LEDs se encienden uno tras otro.

**¿Cómo funciona?**

Declara un arreglo, 
guarda varios números binarios de 8 bits que se utilizan para cambiar el estado operativo de los ocho LEDs controlados por el 74HC595. 

.. code-block:: arduino

    int datArray[] = {B00000000, B00000001, B00000011, B00000111, B00001111, B00011111, B00111111, B01111111, B11111111};

Primero configura ``STcp`` a bajo nivel y luego a alto nivel. 
Esto generará un pulso de borde ascendente en STcp.

.. code-block:: arduino

    digitalWrite(STcp,LOW); 

``shiftOut()`` se usa para desplazar un byte de datos bit a bit, 
lo que significa desplazar un byte de datos en ``datArray[num]`` al registro de desplazamiento con 
el pin ``DS``. **MSBFIRST** significa moverse desde los bits más altos.

.. code-block:: arduino

    shiftOut(DS,SHcp,MSBFIRST,datArray[num]);

Después de ejecutar ``digitalWrite(STcp,HIGH)``, ``STcp`` estará en el borde ascendente. 
En ese momento, los datos en el registro de desplazamiento se moverán al registro de memoria. 

.. code-block:: arduino

    digitalWrite(STcp,HIGH);

Un byte de datos se transferirá al registro de memoria después de 8 veces. 
Luego, los datos del registro de memoria se envían al bus (Q0-Q7). 
Por ejemplo, desplazar ``B00000001`` encenderá el LED controlado por Q0 y apagará el LED controlado por Q1~Q7. 

