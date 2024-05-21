.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _sh_test:

3.1 Test the Car
======================

Here, you will learn how to write scripts to make the car go forward, but you need to refer to :ref:`car_projects` to assemble the car and to get a basic understanding of it.

But before you start the project, you need to know the steps to use PictoBlox in :ref:`upload_mode`.

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

Build the Circuit
-----------------------

The L9110 motor driver module is a high power motor driver module for driving DC and stepper motors. The L9110 module can control up to 4 DC motors, or 2 DC motors with direction and speed control.


Connect the wires between the L9110 module and the R3 board according to the diagram below.


.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L9110 Module
      - R3 Board
      - Motor
    * - A-1B
      - 5
      - 
    * - A-1A
      - 6
      - 
    * - B-1B(B-2A)
      - 9
      - 
    * - B-1A
      - 10
      - 
    * - OB(B)
      - 
      - Black wire of right motor
    * - OA(B)
      - 
      - Red wire of right motor
    * - OB(A)
      - 
      - Black wire of left motor
    * - OA(A)
      - 
      - Red wire of left motor

.. image:: img/car_2.png
    :width: 800

Programming
-------------------

**1. Let the car go forward**

Based on the above wiring, we know that pins 5 and 6 are used to control the right motor rotation and pins 9 and 10 are used for the left motor rotation. Now let's write a script to make the car go forward.

After selecting Board as Arduino Uno, switch to :ref:`upload_mode` and write the script according to the following diagram.

.. image:: img/1_test1.png

Click the **Upload Code** button to upload the code to the R3 board. When it's done, you will see the two motors of the car moving forward (if you put the car on the ground, it will move forward in a straight line, but maybe the car will go in a curve because the speed of the two motors is a bit different). 

If not both turn forward, but the following situations occur, you need to readjust the wiring of the two motors.

* If both motors turn backward at the same time (left motor turns clockwise, right motor turns counterclockwise), swap the wiring of the left and right motors at the same time, OA(A) and OB(A) swap, OA(B) and OB(B) swap.
* If the left motor turns backward (clockwise rotation), exchange the wiring of OA(B) and OB(B) of the left motor.
* If the right motor turns backward (counterclockwise rotation), swap the wiring of OA(A) and OB(A) of the right motor.


**2. Creating block**

In order to make the script more clean and easy to use, here we put all the blocks that control the forward movement into a block, and when using it, just call this block directly.

Click **Make a Block** in the **My Blocks** palette.

.. image:: img/1_test31.png

Enter the name of the block - **forward** and check **Add an input**, set the input name to **speed**.

.. image:: img/1_test32.png

Drag and drop the blocks that control the cars forward into **forward**, note that you need to add the parameter - **speed** to pin6 and pin9.

.. image:: img/1_test33.png

Call the created block in the [Forward] block - **forward**. In Upload mode, the [When Arduino Uno starts up] block must be added at the beginning.

* The motor rotation speed range is 100 ~ 255.

.. image:: img/1_test3.png
    
**3. Adjusting the speed of motors**

Since there may be a slight difference in the speed of the 2 motors, resulting in the car not being able to move along a straight line, we can give the left and right motors different speeds to keep the car moving along a straight line as much as possible.

Since my car will move slowly to the right front, so here reduce the speed of the left motor.

.. image:: img/1_test2.png




