.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_moving_mouse:

2.5 Ratón en Movimiento
=========================

Hoy vamos a hacer un juguete de ratón controlado por un potenciómetro.

Cuando se hace clic en la bandera verde, el ratón en el escenario se mueve hacia adelante, y cuando giras el potenciómetro, el ratón cambiará la dirección del movimiento.

.. image:: img/6_mouse.png

Aprenderás
---------------------

- Principio del potenciómetro
- Leer pin analógico y rangos
- Mapear un rango a otro
- Mover y cambiar la dirección del sprite

Componentes Necesarios
-------------------------

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
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

Construir el Circuito
-----------------------

El potenciómetro es un elemento resistivo con 3 terminales, los pines laterales se conectan a 5V y GND, y el pin central se conecta a A0. Después de la conversión por el convertidor ADC de la placa Arduino, el rango de valores es de 0-1023.

.. image:: img/circuit/potentiometer_circuit.png

Programación
------------------

**1. Elegir un sprite**

Elimina el sprite predeterminado, haz clic en el botón **Choose a Sprite** en la esquina inferior derecha del área de sprites, introduce **mouse** en la caja de búsqueda y luego haz clic para añadirlo.

.. image:: img/6_sprite.png

**2. Crear una variable**.

Crea una variable llamada **value** para almacenar el valor leído del potenciómetro.

Una vez creada, verás **value** aparecer dentro de la paleta **Variables** y en estado marcado, lo que significa que esta variable aparecerá en el escenario.

.. image:: img/6_value.png

**3. Leer el valor de A0**

Almacena el valor leído de A0 en la variable **value**.

* [set my variable to 0]: Establece el valor de la variable.
* [read analog pin A0]: Lee el valor de A0~A5 en el rango de 0-1023.

.. image:: img/6_read_a0.png

Para poder leer todo el tiempo, necesitas usar el bloque [forever]. Haz clic en este script para ejecutarlo, gira el potenciómetro en ambas direcciones y verás que el rango de valores es de 0-1023.

.. image:: img/6_1023.png

**4. Mover el sprite**

Usa el bloque [move steps] para mover el sprite, ejecuta el script y verás el sprite moverse desde el medio hacia la derecha.

.. image:: img/6_move.png

**5. Cambiando la dirección del sprite**

Ahora cambia la dirección del movimiento del sprite por el valor de A0. Dado que el valor de A0 varía de 0-1023, pero la dirección de rotación del sprite es de -180~180, se necesita usar un bloque [map].

También añade [when green flag clicked] al principio para iniciar el script.

* [`point in direction <https://en.scratch-wiki.info/wiki/Point_in_Direction_()_(block)>`_]: Establece el ángulo de dirección del sprite, de la paleta **Motion**.
* [map from to]: Mapea un rango a otro rango.

.. image:: img/6_direction.png

