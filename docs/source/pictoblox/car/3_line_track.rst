.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _sh_line:

3.3 Follow the line
======================

The car is equipped with a Line Track module, which can be used to make the car follow the black line.

Before starting the project, you need to build a curve map with black line tape, the recommended line width is between 0.8-1.5cm and the angle of the turn should not be less than 90 degrees.

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
    *   - :ref:`cpn_track`
        - |link_track_buy|

Build the Circuit
-----------------------

This is a digital Line Tracking module, when a black line is detected, it outputs 1; when a white line is detected, it outputs a value of 0. In addition, you can adjust its sensing distance through the potentiometer on the module.

Build the circuit according to the following diagram.

.. list-table:: 

    * - Line Tracking Module
      - R3 Board
    * - S
      - 2
    * - V+
      - 5V
    * - G
      - GND

.. image:: img/car_4.png
    :width: 800

Adjust the Module
-----------------------

Before starting the project, you need to adjust the sensitivity of the module.

Wiring according to the above diagram, then power up the R3 board (either directly into the USB cable or the 9V battery button cable), without uploading the code.

Stick a black electrical tape on the table and put the cart on it.

Observe the signal LED on the module to make sure it lights up on the white table and goes off on the black tape.

If not, you need to adjust the potentiometer on the module, so that it can do the above effect.

.. image:: img/line_track_cali.JPG


Programming
------------

Now create 2 blocks that allow the car to move either to the left front or to the right front.

**1. Move to the left front**

When the right motor is turned clockwise and the left motor is left unmoved, the car is moved slightly to the left front.

.. image:: img/3_forward_left.png

**2. Moving to the right front**

Similarly, when the left motor is turned counterclockwise and the left motor does not move, the car moves slightly to the right.

.. image:: img/3_forward_left.png

**3. Line Tracking**

Read the value of Line Tracking module, if it is 1, it means black line has been detected, let the car move forward to the left, otherwise move forward to the right.

.. image:: img/3_follow.png

After uploading the code to the R3 board, then align the Line Tracking module under the car with the black line, and you will see the car following the line.