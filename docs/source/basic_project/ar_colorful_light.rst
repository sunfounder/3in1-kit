.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_rgb:

2.2 Luz Colorida
===================

Como sabemos, la luz puede superponerse. Por ejemplo, mezclar luz azul y verde da luz cian, luz roja y verde da luz amarilla.
Esto se llama "El método aditivo de mezcla de colores".

* `Color aditivo - Wikipedia <https://en.wikipedia.org/wiki/Additive_color>`_

Basado en este método, podemos usar los tres colores primarios para mezclar la luz visible de cualquier color según diferentes proporciones específicas. Por ejemplo, el naranja se puede producir con más rojo y menos verde.

¡En este capítulo, usaremos el LED RGB para explorar el misterio de la mezcla de colores aditivos!

El LED RGB es equivalente a encapsular un LED Rojo, un LED Verde y un LED Azul bajo una misma tapa de lámpara, y los tres LED comparten un pin de cátodo común.
Dado que se proporciona una señal eléctrica para cada pin de ánodo, se puede mostrar la luz del color correspondiente.
Cambiando la intensidad de la señal eléctrica de cada ánodo, se pueden producir varios colores.


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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|


**Esquemático**

.. image:: img/circuit_2.2_rgb.png


Los pines PWM 11, 10 y 9 controlan los pines Rojo, Verde y Azul del LED RGB respectivamente, y conectan el pin de cátodo común a GND.
Esto permite que el LED RGB muestre un color específico al superponer luz en estos pines con diferentes valores de PWM.



**Cableado**

.. image:: img/rgb_led_sch.png

Un LED RGB tiene 4 pines: el pin más largo es el pin de cátodo común, que generalmente se conecta a GND,
el pin izquierdo junto al pin más largo es Rojo, y los 2 pines a la derecha son Verde y Azul.


.. image:: img/colorful_light_bb.jpg
    :width: 500
    :align: center

**Código**

Aquí, podemos elegir nuestro color favorito en software de dibujo (como paint) y mostrarlo con el LED RGB.

.. note::

   * Puedes abrir el archivo ``2.2.colorful_light.ino`` en la ruta ``3in1-kit\basic_project\2.analogWrite\2.2.colorful_light``. 
   * O copia este código en **Arduino IDE**.
   
   * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/5d70e864-4f34-4090-b65d-904350091936/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. image:: img/edit_colors.png

Escribe el valor RGB en ``color_set()``, y podrás ver el LED RGB iluminarse con los colores que desees.


**¿Cómo funciona?**

En este ejemplo, la función utilizada para asignar valores a los tres pines de RGB se empaqueta en una subfunción independiente ``color()``.

.. code-block:: arduino

    void color (unsigned char red, unsigned char green, unsigned char blue)
    {
        analogWrite(redPin, red);
        analogWrite(greenPin, green);
        analogWrite(bluePin, blue);
    }

En ``loop()``, el valor RGB funciona como un argumento de entrada para llamar a la función ``color()`` y así lograr que el RGB emita diferentes colores.

.. code-block:: arduino

    void loop() 
    {    
        color(255, 0, 0); //  red 
        delay(1000); 
        color(0,255, 0); //  green  
        delay(1000);  
        color(0, 0, 255); //  blue  
        delay(1000);
    }
