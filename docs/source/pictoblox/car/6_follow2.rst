.. _sh_follow2:

3.6 Sigue tu Mano 2
==============================

En el proyecto :ref:`sh_follow1` solo se usa el módulo ultrasónico, puede seguir tu mano solo hacia adelante.

En este proyecto, utilizamos 2 módulos de evitación de obstáculos IR al mismo tiempo, para que el coche pueda seguir tu mano a la izquierda o a la derecha.

Componentes Necesarios
-------------------------

Para este proyecto, necesitamos los siguientes componentes.

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

También puedes comprarlos por separado en los siguientes enlaces.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110` 
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

Construye el Circuito
-----------------------

Conecta el módulo ultrasónico y los dos módulos IR de evitación de obstáculos al mismo tiempo.

El cableado entre el ultrasónico y la placa R3 es el siguiente.

.. list-table:: 

    * - Módulo Ultrasónico
      - Placa R3
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

El cableado de los 2 módulos IR de evitación de obstáculos a la placa R3 es el siguiente.

.. list-table:: 

    * - Módulo IR Izquierdo
      - Placa R3
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 

    * - Módulo IR Derecho
      - Placa R3
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_7_8.png
    :width: 800

Programación
---------------

El efecto que se desea lograr con este proyecto es el siguiente

* El ultrasónico detecta tu mano a unos 5-10 cm de distancia y hace que el coche siga.
* El módulo infrarrojo de la izquierda detecta tu mano y gira hacia la izquierda.
* El módulo IR derecho detecta tu mano y gira hacia la derecha.

**1. Crear un bloque**

Crea bloques que permitan al coche moverse hacia adelante, girar a la izquierda, girar a la derecha y detenerse.

.. image:: img/6_follow2_1.png

**2. Seguir para avanzar**

Lee el valor ultrasónico y si detecta tu mano a una distancia de 5-10 cm, haz que el coche siga.

.. image:: img/6_follow2_2.png

**3. Seguir para girar a la izquierda y a la derecha**

Lee los valores de los módulos IR izquierdo y derecho.

* Si el módulo IR izquierdo detecta tu mano, gira hacia la izquierda.
* Si el módulo IR derecho detecta tu mano, gira hacia la derecha.
* Si ninguno de los módulos IR ni el módulo ultrasónico detectan tu mano, haz que el coche se detenga.

.. image:: img/6_follow2_3.png
