.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_table_lamp:

2.1 Lámpara de Mesa
=====================

Aquí, conectamos un LED en la protoboard y hacemos que el sprite controle el parpadeo de este LED.

Cuando se hace clic en el sprite del Botón en el escenario, el LED parpadeará 5 veces y luego se detendrá.

.. image:: img/2_button.png

Aprenderás
---------------------

- Protoboard, LEDs y Resistencias
- Construir un circuito en una protoboard
- Eliminar y seleccionar sprites
- Cambiar disfraces
- Establecer un número limitado de bucles de repetición

Componentes Necesarios
------------------------

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

Construir el Circuito
-----------------------

Sigue el diagrama a continuación para construir el circuito en la protoboard.

Dado que el ánodo del LED (el pin más largo) está conectado al pin 9 a través de una resistencia de 220Ω, y el cátodo del LED está conectado a GND, puedes encender el LED dándole al pin 9 un nivel alto.

.. image:: img/circuit/led_circuit.png

Programación
------------------

La programación completa se divide en 3 partes, la primera parte es seleccionar el sprite deseado, la segunda parte es cambiar el disfraz del sprite para que parezca clickeable, y la tercera parte es hacer parpadear el LED.

**1. Selecciona el sprite Button3**

Elimina el sprite Tobi existente utilizando el botón Eliminar en la esquina superior derecha y selecciona un sprite de nuevo.

.. image:: img/2_tobi.png

Aquí, seleccionamos el sprite **Button3**.

.. image:: img/2_button3.png

Haz clic en Disfraces en la esquina superior derecha y verás que el sprite Button3 tiene 2 disfraces, establecemos **button3-a** para liberar y **button3-b** para presionar.

.. image:: img/2_button3_2.png

**2. Cambiando disfraces**.

Cuando se hace clic en el sprite (**paleta de Eventos**), cambia al disfraz para **button3-b** (**paleta de Aspectos**).

.. image:: img/2_switch.png

**3. Hacer parpadear el LED 5 veces**

Usa el bloque [Repeat] para hacer parpadear el LED 5 veces (High-> LOW cycle), recuerda cambiar el pin 13 al pin 9, y finalmente cambia el disfraz de nuevo a **button3-a**.

* [Repeat 10]: número limitado de bucles de repetición, puedes establecer el número de repeticiones tú mismo, de la **paleta de Control**.

.. image:: img/2_led_on_off.png

