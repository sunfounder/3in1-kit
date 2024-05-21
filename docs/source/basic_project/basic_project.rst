.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _basic_projects:

Proyectos Básicos
========================

Este capítulo se utiliza para aprender a controlar circuitos electrónicos usando Arduino.

Dependiendo de los componentes, los métodos básicos de control de Arduino se pueden dividir en cuatro tipos:

* :ref:`ar_digital_write`: Establece la tensión de salida del pin en alto o bajo, lo que se puede utilizar para encender y apagar la luz.
* :ref:`ar_analog_write`: Escribe el valor analógico (`onda PWM <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_) en el pin, lo que se puede utilizar para ajustar el brillo de la luz.
* :ref:`ar_digital_read`: Lee la señal de nivel del pin digital, lo que se puede utilizar para leer el estado de funcionamiento del interruptor.
* :ref:`ar_analog_read`: Lee el voltaje del pin analógico, lo que se puede utilizar para leer el estado de funcionamiento del mando.

También hay algunos componentes que requieren bibliotecas adicionales para su uso, y estos se agrupan bajo la sección :ref:`install_libraries_ar`.

Finalmente, el kit también proporciona algunos :ref:`ar_funny_project`, que incluye muchas manipulaciones simples y útiles.
Prueba esta sección del código y entenderás cómo funcionan la mayoría de los proyectos simples.

.. toctree::
    :maxdepth: 2

    ard_digital_write
    ard_analog_write
    ard_digital_read
    ard_analog_read
    ard_more_syntax
    ard_funny_project
