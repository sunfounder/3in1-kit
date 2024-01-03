.. _follow_your_hand:

7. Sigue a tu Mano
=========================

Imagina este coche como tu mascota aquí, y cuando le saludes con la mano, vendrá corriendo hacia ti.

**Componentes Necesarios**

Para este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí tienes el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS DE ESTE KIT
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

**Cableado**

Conecta el módulo ultrasónico y los 2 módulos de evitación de obstáculos IR al mismo tiempo.

Conecta el ultrasónico a la placa R3 de la siguiente manera.

.. list-table:: 
    :header-rows: 1

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

El cableado de los 2 módulos de evitación de obstáculos IR a la placa R3 es como sigue.

.. list-table:: 
    :header-rows: 1

    * - Módulo IR Izquierdo
      - Placa R3
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

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

**Código**

.. note::

    * Abre el archivo ``7.follow_your_hand.ino`` en la ruta ``3in1-kit\car_project\7.follow_your_hand``.
    * O copia este código en el **Arduino IDE**.
    
    * O sube el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/584e42c8-8842-4db0-93b5-f6f949b6ffca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Coloca el coche en el suelo después de haber subido el código con éxito. Pon tu mano cerca de 5*10 cm delante del coche, y este seguirá tu mano hacia adelante. Si pones tu mano cerca del módulo IR Obstacle en ambos lados, también girará en la dirección correspondiente.

**¿Cómo funciona?**

Este proyecto es una combinación de los dos proyectos anteriores :ref:`car_ultrasonic` y :ref:`car_ir_obstacle`, pero el efecto implementado es diferente. Los 2 proyectos anteriores detectan un obstáculo hacia atrás, pero aquí se detecta que tu mano seguirá la dirección hacia adelante o girará.
El flujo de trabajo de este proyecto es el siguiente.

* Lee la distancia detectada por el módulo ultrasónico y el valor de ambos módulos infrarrojos.
* Si la distancia es de 5~10cm, deja que el coche se mueva con tu mano.
* Si el módulo IR izquierdo detecta tu mano, gira a la izquierda.
* Si el módulo IR derecho detecta tu mano, gira a la derecha.
* Si ni el módulo infrarrojo ni el módulo ultrasónico detectan tu mano, deja que el coche se detenga.

.. code-block:: arduino

    void loop() {

        float distance = readSensorData();

        int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
        int right = digitalRead(rightIR);
        int speed = 150;

        if (distance>5 && distance<10){
            moveForward(speed);
        }
        if(!left&&right){
            turnLeft(speed);
        }else if(left&&!right){
            turnRight(speed);
        }else{
            stopMove();
        }
    }