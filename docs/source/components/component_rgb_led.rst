.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_rgb:

LED RGB
=================

.. image:: img/rgb_led.png
    :width: 100
    
Los LEDs RGB emiten luz en varios colores. Un LED RGB empaqueta tres LEDs de rojo, verde y azul en una carcasa de plástico transparente o semitransparente. Puede mostrar varios colores cambiando el voltaje de entrada de los tres pines y superponiéndolos, lo que, según las estadísticas, puede crear 16,777,216 colores diferentes.

.. image:: img/rgb_light.png
    :width: 600

Los LEDs RGB se pueden clasificar en ánodo común y cátodo común. En este kit, se utiliza el último. El **cátodo común**, o CC, significa conectar los cátodos de los tres LEDs. Después de conectarlo con GND y enchufar los tres pines, el LED mostrará el color correspondiente.

Su símbolo de circuito se muestra en la figura.

.. image:: img/rgb_symbol.png
    :width: 300

Un LED RGB tiene 4 pines: el más largo es GND; los otros son Rojo, Verde y Azul. Toca su carcasa de plástico y encontrarás un corte. El pin más cercano al corte es el primer pin, marcado como Rojo, luego GND, Verde y Azul en orden.

.. image:: img/rgb_pin.jpg
    :width: 200

**Ejemplo**

* :ref:`ar_rgb` (Proyecto Básico)
* :ref:`ar_threshold` (Proyecto Básico)
* :ref:`sh_colorful_ball` (Proyecto Scratch)
