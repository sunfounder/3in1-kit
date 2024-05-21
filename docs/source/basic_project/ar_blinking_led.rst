.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_blink:

1.1 ¡Hola, LED! 
=======================================

Así como imprimir “¡Hola, mundo!” es el primer paso para aprender a programar, usar un programa para activar un LED es la introducción tradicional para aprender programación física.

**Componentes Necesarios**

En este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS EN ESTE KIT
        - ENLACE
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

También puedes comprarlos por separado en los enlaces a continuación.

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

**Esquemático**

.. image:: img/circuit_1.1_led.png

El principio de este circuito es simple y la dirección de la corriente se muestra en la figura. Cuando el pin 9 emite un nivel alto (5V), el LED se encenderá después de la resistencia limitadora de corriente de 220ohm. Cuando el pin 9 emite un nivel bajo (0v), el LED se apagará.

**Cableado**

.. image:: img/wiring_led.png
    :width: 400
    :align: center

**Código**

.. note::

   * Puedes abrir el archivo ``1.1.hello_led.ino`` en la ruta ``3in1-kit\basic_project\1.1.hello_led``.
   * O copia este código en **Arduino IDE**.
   
   * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/0497f915-5bf8-41a2-8e0f-b013130a57f5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de cargar el código con éxito, verás el LED parpadeando.

**¿Cómo funciona?**

Aquí, conectamos el LED al pin digital 9, por lo que necesitamos declarar una variable int llamada ledpin al principio del programa y asignarle un valor de 9.

.. code-block:: arduino

    const int ledPin = 9;


Ahora, inicializa el pin en la función ``setup()``, donde necesitas inicializar el pin en modo ``OUTPUT``.

.. code-block:: arduino

    void setup() {
        pinMode(ledPin, OUTPUT);
    }

En ``loop()``, se utiliza ``digitalWrite()`` para proporcionar una señal de nivel alto de 5V para ledpin, lo que provocará una diferencia de voltaje entre los pines del LED y lo encenderá.

.. code-block:: arduino

    digitalWrite(ledPin, HIGH);

Si la señal de nivel se cambia a LOW, la señal de ledPin volverá a 0 V para apagar el LED.

.. code-block:: arduino

    digitalWrite(ledPin, LOW);

Se requiere un intervalo entre encendido y apagado para permitir que las personas vean el cambio, 
por lo que usamos un código ``delay(1000)`` para dejar que el controlador no haga nada durante 1000 ms.

.. code-block:: arduino

    delay(1000);   