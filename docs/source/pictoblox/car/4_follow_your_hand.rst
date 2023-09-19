.. _sh_follow1:

3.4 Follow Your Hand
===========================

Think of this car as your pet here, and when you will wave to him, it comes running to you.

Required Components
---------------------

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
    *   - :ref:`cpn_l9110` 
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

Build the Circuit
-----------------------

An ultrasonic sensor module is an instrument that measures the distance to an object using ultrasonic sound waves. 
It has two probes. One is to send ultrasonic waves and the other is to receive the waves and transform the time of sending and receiving into a distance, thus detecting the distance between the device and an obstacle.

Now build the circuit according to the following diagram.

.. list-table:: 

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

.. image:: img/car_6.png
    :width: 800

Programming
------------

Create blocks to make the car go forward and stop.

.. image:: img/4_hand1.png

Put your hand in front of the car, then read the value of the ultrasonic module, if the detected distance of your hand is 5-10cm, then let the car go forward, otherwise stop.

.. image:: img/4_hand2.png