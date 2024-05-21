.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_low_temperature:

2.7 Alarma de Baja Temperatura
==================================

En este proyecto, haremos un sistema de alarma de baja temperatura, cuando la temperatura esté por debajo del umbral, el sprite **Copo de Nieve** aparecerá en el escenario.

.. image:: img/9_tem.png

Aprenderás
---------------------

- Principio de funcionamiento del termistor
- Operaciones multivariables y sustractivas

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
    *   - :ref:`cpn_thermistor` 
        - |link_thermistor_buy|

Construir el Circuito
-----------------------

Un termistor es un tipo de resistencia cuya resistencia depende fuertemente de la temperatura, más que en las resistencias estándar, y existen dos tipos de resistencias, PTC (la resistencia aumenta con la temperatura) y NTC (la resistencia disminuye con la temperatura).

Construye el circuito según el siguiente diagrama.

Un extremo del termistor está conectado a GND, el otro extremo está conectado a A0, y una resistencia de 10K está conectada en serie a 5V.

Aquí se utiliza el termistor NTC, así que cuando la temperatura aumenta, la resistencia del termistor disminuye, la división de voltaje en A0 disminuye y el valor obtenido de A0 disminuye, y viceversa aumenta.

.. image:: img/circuit/thermistor_circuit.png

Programación
------------------

**1. Seleccionar un sprite**

Elimina el sprite predeterminado, haz clic en el botón **Choose a Sprite** en la esquina inferior derecha del área de sprites, introduce **Snowflake** en la caja de búsqueda y luego haz clic para añadirlo.

.. image:: img/9_snow.png

**2. Crear 2 variables**

Crea dos variables, **before** y **current**, para almacenar el valor de A0 en diferentes casos.

.. image:: img/9_va.png

**3. Leer el valor de A0**

Cuando se hace clic en la bandera verde, se lee el valor de A0 y se almacena en la variable **before**.

.. image:: img/9_before.png

**4. Leer nuevamente el valor de A0**

En [forever], lee nuevamente el valor de A0 y almacénalo en la variable **current**.

.. image:: img/9_current.png

**5. Determinar los cambios de temperatura**

Utilizando el bloque [if else], determina si el valor actual de A0 es 50 mayor que antes, lo que representa una disminución de la temperatura. En este punto, haz que el sprite **Snowflake** se muestre, de lo contrario, ocúltalo.

* [-] y [>]: operadores de sustracción y comparación de la paleta **Operators**.

.. image:: img/9_show.png
