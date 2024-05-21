.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_potentiometer:

Potenciómetro
===============

.. image:: img/potentiometer.png
    :align: center
    :width: 150

El potenciómetro es también un componente de resistencia con 3 terminales y su valor de resistencia puede ser ajustado según alguna variación regular.

Los potenciómetros vienen en varias formas, tamaños y valores, pero todos tienen en común lo siguiente:

* Tienen tres terminales (o puntos de conexión).
* Tienen un botón, tornillo o deslizador que se puede mover para variar la resistencia entre el terminal central y cualquiera de los terminales exteriores.
* La resistencia entre el terminal central y cualquiera de los terminales exteriores varía de 0 Ω hasta la resistencia máxima del potenciómetro a medida que se mueve el botón, tornillo o deslizador.

Aquí está el símbolo del circuito del potenciómetro.

.. image:: img/potentiometer_symbol.png
    :align: center
    :width: 400

Las funciones del potenciómetro en el circuito son las siguientes: 

#. Actuar como un divisor de tensión

    El potenciómetro es un resistor ajustable continuamente. Cuando ajustas el eje o la manija deslizante del potenciómetro, el contacto móvil se deslizará sobre el resistor. En este punto, se puede emitir un voltaje dependiendo del voltaje aplicado al potenciómetro y del ángulo al que haya girado el brazo móvil o el recorrido que haya realizado.

#. Actuar como un reostato

    Cuando el potenciómetro se usa como un reostato, conecta el pin central y uno de los otros 2 pines en el circuito. Así puedes obtener un valor de resistencia que cambia suavemente y de forma continua dentro del recorrido del contacto móvil.

#. Actuar como un controlador de corriente

    Cuando el potenciómetro actúa como un controlador de corriente, el terminal de contacto deslizante debe conectarse como uno de los terminales de salida.

Si quieres saber más sobre potenciómetros, consulta: `Potenciómetro - Wikipedia <https://en.wikipedia.org/wiki/Potentiometer>`_

**Ejemplo**

* :ref:`ar_potentiometer` (Proyecto Básico)
* :ref:`sh_moving_mouse` (Proyecto Scratch)
* :ref:`sh_breakout_clone` (Proyecto Scratch)

