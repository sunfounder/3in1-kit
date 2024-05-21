.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_led:

LED
==========

.. image:: img/LED.png
    :width: 400

El diodo emisor de luz semiconductor es un tipo de componente que puede convertir la energía eléctrica en energía lumínica a través de uniones PN. Según la longitud de onda, se puede clasificar en diodo láser, diodo emisor de luz infrarroja y diodo emisor de luz visible, comúnmente conocido como diodo emisor de luz (LED).

El diodo tiene conductividad unidireccional, por lo que el flujo de corriente será como indica la flecha en el símbolo del circuito en la figura. Solo puedes proporcionar al ánodo una potencia positiva y al cátodo una negativa. Así, el LED se iluminará.

.. image:: img/led_symbol.png


Un LED tiene dos pines. El más largo es el ánodo y el más corto, el cátodo. Hay que tener cuidado de no conectarlos al revés. Hay una caída de voltaje fija en el LED, por lo que no se puede conectar directamente con el circuito porque el voltaje de suministro puede superar esta caída y causar que el LED se queme. El voltaje directo del LED rojo, amarillo y verde es de 1.8 V y el del blanco es de 2.6 V. La mayoría de los LEDs pueden soportar un máximo de 20 mA, por lo que necesitamos conectar una resistencia limitadora de corriente en serie.

La fórmula del valor de la resistencia es la siguiente:

    R = (Vsupply – VD)/I

**R** representa el valor de resistencia de la resistencia limitadora de corriente, **Vsupply** el voltaje de suministro, **VD** la caída de voltaje e **I** la corriente de trabajo del LED.

Aquí está la introducción detallada del LED: `LED - Wikipedia <https://en.wikipedia.org/wiki/Light-emitting_diode>`_.

**Ejemplo**

* :ref:`ar_blink` (Proyecto Básico)
* :ref:`ar_fading` (Proyecto Básico)
* :ref:`iot_blink` (Proyecto IoT)
* :ref:`sh_breathing_led` (Proyecto Scratch)
* :ref:`sh_table_lamp` (Proyecto Scratch)

