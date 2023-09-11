.. _follow_your_hand:

7. Follow Your Hand
=========================

Think of this car as your pet here, and when you will wave to him, it comes running to you.

**Required Components**

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l298n`
        - |link_l298n_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

**Wiring**

Connect the ultrasonic module and the 2 IR obstacle avoidance modules at the same time.

Wire the ultrasonic to the R3 board as follows.

.. list-table:: 
    :header-rows: 1

    * - Ultrasonic Module
      - R3 Board
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

The wiring of the 2 IR obstacle avoidance modules to the R3 board is as follows.

.. list-table:: 
    :header-rows: 1

    * - Left IR Module
      - R3 Board
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - Right IR Module
      - R3 Board
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_avoid_ultrasonic.jpg
    :width: 800

**Code**

.. note::

    * Open the ``7.follow_your_hand.ino`` file under the path of ``3in1-kit\car_project\7.follow_your_hand``.
    * Or copy this code into **Arduino IDE**.
    
    * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/584e42c8-8842-4db0-93b5-f6f949b6ffca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Place the car on the ground after the code has been uploaded successfully. Place your hand close to 5*10cm in front of the car, and it will follow your hand forward. If you put your hand close to the IR Obstacle module on both sides, it will also turn to the corresponding direction.


**How it works?**

This project is a combination of the previous two projects :ref:`car_ultrasonic` and :ref:`car_ir_obstacle`, but the implemented effect is different. The previous 2 projects are detecting an obstacle backwards, but here it is detecting that your hand will follow the forward or turn direction.
The workflow of this project is as follows.

* Read the distance detected by the ultrasonic module and the value of both infrared modules.
* If the distance is 5~10cm, let the car move with your hand.
* If the left IR module detects your hand, turn left.
* If the right IR module detects your hand, turn right.
* If neither the infrared module nor the ultrasonic module detects your hand, let the car stop.

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