.. _car_move:

1. Mover
===============

.. image:: ../components/img/l9110_module.jpg
    :width: 500
    :align: center

Antes de comenzar a programar, revisemos el principio de funcionamiento del módulo L9110.

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
      - Freno
    * - 1
      - 1
      - Parada

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
      - Freno
    * - 1
      - 1
      - Parada


* :ref:`cpn_l9110`

**Hacia adelante**

Ahora conectemos la entrada del módulo L9110 directamente a 12V y GND respectivamente para hacer que el coche se mueva.

.. raw:: html
    
  <iframe width="600" height="400" src="https://www.youtube.com/embed/ulD40OtsL7c?si=hJ9nyf8ePAWNp0-8" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

1. Conectar la placa R3, el módulo L9110 y 2 motores.


.. image:: img/car_1.png
    :width: 800

2. Conectar B-1B(B-2A) y A-1A a VCC, y B-1A y A-1B a GND, luego podrás ver el coche avanzando.


.. image:: img/1.move_4.png 
    :align: center

Si no ambos giran hacia adelante, sino que ocurren las siguientes situaciones, 
necesitarás reajustar el cableado de los dos motores.

* Si ambos motores giran hacia atrás al mismo tiempo (el motor izquierdo gira en sentido horario, el motor derecho gira en sentido antihorario), intercambia el cableado de los motores izquierdo y derecho al mismo tiempo, OA(A) y OB(A) se intercambian, OA(B) y OB(B) se intercambian.
* Si el motor izquierdo gira hacia atrás (rotación en sentido horario), intercambia el cableado de OA(B) y OB(B) del motor izquierdo.
* Si el motor derecho gira hacia atrás (rotación en sentido antihorario), intercambia el cableado de OA(A) y OB(A) del motor derecho.


**Hacia atrás**

Conectar B-1B(B-2A) y A-1A a GND, y B-1A y A-1B a VCC, luego podrás ver el coche retrocediendo.


.. image:: img/1.move_back.png 
    :width: 800



**Girar a la izquierda**

Si quieres hacer que el coche gire a la izquierda, es decir, hacer que ambos motores giren en sentido horario. 
Necesitas conectar B-1A y A-1A a GND, y B-1B(B-2A) y A-1B a VCC.


.. image:: img/1.move_left.png 
    :width: 800


**Girar a la derecha**

Por el contrario, si quieres girar el coche a la derecha, es decir, hacer que ambos motores giren en sentido antihorario. 
Necesitas conectar B-1A y A-1A a VCC y B-1B(B-2A) y A-1B a GND.


.. image:: img/1.move_right.png 
    :width: 800



**Detener**

Para detener el motor, conecta las entradas del mismo lado a 12V o GND al mismo tiempo, por ejemplo, conecta B-1A y B-1B(B-2A) a 12V o 5V al mismo tiempo, y lo mismo para A-1A y A-1B.

Esto es por supuesto teórico y se necesitará más adelante al controlar con código. Aquí quita la fuente de alimentación al coche para detenerlo.
