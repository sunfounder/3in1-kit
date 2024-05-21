.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_reed:

Interruptor de lengüeta (Reed Switch)
==========================================

.. image:: img/reed.png

El Interruptor de Lengüeta es un interruptor eléctrico que funciona por medio de un campo magnético aplicado. Fue inventado por Walter B. Ellwood de los Laboratorios Bell Telephone en 1936 y patentado en Estados Unidos el 27 de junio de 1940, bajo el número de patente 2264746.

El principio de funcionamiento de un interruptor de lengüeta es muy simple. Dos lengüetas (generalmente hechas de hierro y níquel, dos metales) que se superponen en los puntos finales están selladas en un tubo de vidrio, con las dos lengüetas superpuestas y separadas por un pequeño espacio (solo unos pocos micrones). El tubo de vidrio está lleno de un gas inerte de alta pureza (como nitrógeno), y algunos interruptores de lengüeta están hechos para tener un vacío en su interior para mejorar su rendimiento a altos voltajes.

La lengüeta actúa como un conductor de flujo magnético. Las dos lengüetas no están en contacto cuando aún no están en funcionamiento; al pasar por un campo magnético generado por un imán permanente o una bobina electromagnética, el campo magnético aplicado hace que las dos lengüetas tengan diferentes polaridades cerca de sus extremos, y cuando la fuerza magnética supera la fuerza de resorte de las lengüetas mismas, las dos lengüetas se atraen para conducir el circuito; cuando el campo magnético se debilita o desaparece, las lengüetas se liberan debido a su propia elasticidad, y las superficies de contacto se separarán para abrir el circuito.

.. image:: img/reed_sche.png

* `Interruptor de Lengüeta - Wikipedia <https://en.wikipedia.org/wiki/Reed_switch>`_

**Ejemplo**

* :ref:`ar_reed` (Proyecto Básico)
* :ref:`iot_gate` (Proyecto IoT)
