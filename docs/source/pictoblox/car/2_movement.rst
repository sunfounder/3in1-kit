.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_move:

3.2 Movimiento
==================

Este proyecto se basa en :ref:`sh_test` para hacer que el coche se mueva en todas direcciones.

Antes de comenzar a programar, repasemos el principio de funcionamiento del módulo L9110.

Aquí está la tabla de verdad del Motor B:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - El estado del Motor B
    * - 1
      - 0
      - Gira en sentido horario
    * - 0
      - 1
      - Gira en sentido antihorario
    * - 0
      - 0
      - Frena
    * - 1
      - 1
      - Detiene

Aquí está la tabla de verdad del Motor A:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - El estado del Motor B
    * - 1
      - 0
      - Gira en sentido horario
    * - 0
      - 1
      - Gira en sentido antihorario
    * - 0
      - 0
      - Frena
    * - 1
      - 1
      - Detiene



Programación
-------------------

Ahora crea bloques para hacer que el coche avance, retroceda, gire a la izquierda y a la derecha y se detenga respectivamente.


**1. Mover hacia adelante**

El motor derecho gira en sentido horario y el motor izquierdo en sentido antihorario para mover el coche hacia adelante.

.. image:: img/2_forward.png

**2. Mover hacia atrás**

Hacia atrás es justo lo contrario, el motor derecho necesita girar en sentido antihorario, el motor izquierdo en sentido horario.

.. image:: img/2_backward.png

**3. Girar a la izquierda**

Los motores izquierdo y derecho giran en sentido horario al mismo tiempo para hacer que el coche gire a la izquierda.

.. image:: img/2_turn_left.png

**4. Girar a la derecha**

De manera similar, gira los motores izquierdo y derecho en sentido antihorario para girar el coche a la derecha.

.. image:: img/2_turn_right.png

**5. Detener**

Detén el coche estableciendo todos los motores en 0.

.. image:: img/2_stop.png

**6. Haz que el coche se mueva**

Haz que el coche se mueva hacia adelante, hacia atrás, a la izquierda y a la derecha durante 1 segundo, luego detente. Dado que todos los bloques están colocados en el bloque [Siempre], verás que el coche repite las acciones anteriores.

.. image:: img/2_move.png
