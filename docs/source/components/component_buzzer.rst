.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_buzzer:

Buzzer
=======

.. image:: img/buzzer.png
    :width: 600

Como un tipo de zumbador electrónico con estructura integrada, los buzzers, que son alimentados por corriente continua (DC), se utilizan ampliamente en computadoras, impresoras, fotocopiadoras, alarmas, juguetes electrónicos, dispositivos electrónicos automotrices, teléfonos, temporizadores y otros productos electrónicos o dispositivos de voz.

Los buzzers se pueden clasificar en activos y pasivos (ver la siguiente imagen). Gira el buzzer de modo que sus pines queden hacia arriba, y el buzzer con una placa de circuito verde es un buzzer pasivo, mientras que el que está envuelto con cinta negra es un buzzer activo.

La diferencia entre un buzzer activo y uno pasivo:

Un buzzer activo tiene una fuente oscilante incorporada, por lo que emitirá sonidos al ser electrificado. Pero un buzzer pasivo no tiene tal fuente, por lo que no emitirá un pitido si se usan señales de DC; en su lugar, necesitas usar ondas cuadradas cuya frecuencia esté entre 2K y 5K para activarlo. El buzzer activo suele ser más caro que el pasivo debido a sus múltiples circuitos oscilantes incorporados.

A continuación se muestra el símbolo eléctrico de un buzzer. Tiene dos pines con polos positivo y negativo. Con un + en la superficie representa el ánodo y el otro es el cátodo.

.. image:: img/buzzer_symbol.png
    :width: 150

Puedes verificar los pines del buzzer, el más largo es el ánodo y el más corto es el cátodo. Por favor, no los confundas al conectar, de lo contrario, el buzzer no emitirá sonido.

`Buzzer - Wikipedia <https://en.wikipedia.org/wiki/Buzzer>`_

**Ejemplo**

* :ref:`ar_beep` (Proyecto Básico)
* :ref:`ar_passive_buzzer` (Proyecto Básico)
* :ref:`iot_music` (Proyecto IoT)
