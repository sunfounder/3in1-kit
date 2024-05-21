.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_motor:

1.3 Turn the Wheel
============================

A motor is a typical digital output device, and it is used in the same way as an LED.
However, the motor needs to be driven with a large current, 
and the large current may damage the main control board such as R4 board.
Therefore, an motor driver module is used in this occasion, 
which is a good helper for the R4 board to control the motor safely.

.. **Schematic**

.. .. image:: img/circuit_1.3_wheel.png

.. IN1~IN4 are the inputs of the L298N module, and OUT1~OUT4 are the outputs.

.. A simple way to use them is: input high level for INx, OUTx will output high level; input low level for INx, OUTx will output low level.
.. Connecting the two ends of the motor to OUT1 and OUT2, inputting opposite level signals for IN1 and IN2 will make the motor rotate. OUT3 and OUT4 can be used in the same way.

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
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

**Schematic**


.. image:: img/circuit_1.3_wheel_l9110.png


**Wiring**

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L9110S
      - R4 Board
      - Motor
    * - VCC
      - 5V
      - 
    * - GND
      - GND
      - 
    * - B-1B(B-2A)
      - 9
      -
    * - B-1A
      - 10
      - 
    * - OA
      - 
      - one wire of the motor
    * - OB
      - 
      - one wire of the motor

.. image:: img/1.3_turn_the_wheel_bb.png
    :width: 800
    :align: center

**Code**

.. note::

   * You can open the file ``1.3.turn_the_wheel.ino`` under the path of ``3in1-kit\learning_project\1.3.turn_the_wheel``. 
   * Or copy this code into **Arduino IDE**.
   
   

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/5f8e4f33-883b-4c06-9516-f1754ea2121d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
