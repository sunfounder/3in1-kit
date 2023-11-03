.. _car_move:

1. Move
===============

.. image:: ../components/img/l9110_module.jpg
    :width: 500
    :align: center

Before we start programming, let's review the working principle of L9110 module.

Here is the truth table of Motor B:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - The state of Motor B
    * - 1
      - 0
      - Rotate clockwise
    * - 0
      - 1
      - Rotate counterclockwise
    * - 0
      - 0
      - Brake
    * - 1
      - 1
      - Stop

Here is the truth table of Motor A:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - The state of Motor B
    * - 1
      - 0
      - Rotate clockwise
    * - 0
      - 1
      - Rotate counterclockwise
    * - 0
      - 0
      - Brake
    * - 1
      - 1
      - Stop


* :ref:`cpn_l9110`

**Forward**

Now let's connect the input of L9110 module directly to 12V and GND respectively to make the car move.


1. Connect R4 board, L9110 module and 2 motors.


.. image:: img/car_1.png
    :width: 800

2. Connect B-1B(B-2A) and A-1A to VCC, and B-1A and A-1B to GND, then you will be able to see the car moving forward.


.. image:: img/1.move_4.png 
    :align: center

If not both turn forward, but the following situations occur, 
you need to readjust the wiring of the two motors.

* If both motors turn backward at the same time (left motor turns clockwise, right motor turns counterclockwise), swap the wiring of the left and right motors at the same time, OA(A) and OB(A) swap, OA(B) and OB(B) swap.
* If the left motor turns backward (clockwise rotation), exchange the wiring of OA(B) and OB(B) of the left motor.
* If the right motor turns backward (counterclockwise rotation), swap the wiring of OA(A) and OB(A) of the right motor.


**Backward**

Connect B-1B(B-2A)  and A-1A to GND, and B-1A  and A-1B to VCC, then you will be able to see the car moving backward.


.. image:: img/1.move_back.png 
    :width: 800



**Turn Left**

If you want to make the car turn left, that is, make both motors turn clockwise. 
You need to connect B-1A  and A-1A to GND, and B-1B(B-2A)  and A-1B to VCC.


.. image:: img/1.move_left.png 
    :width: 800


**Turn Right**

Conversely, if you want to turn the car to the right, that is, make both motors turn counterclockwise. 
You need to connect B-1A  and A-1A to VCC and B-1B(B-2A) and A-1B to GND.


.. image:: img/1.move_right.png 
    :width: 800



**Stop**

To stop the motor, connect the inputs on the same side to 12V or GND at the same time, e.g. connect B-1A  and B-1B(B-2A) to 12V or 5V at the same time, and the same for A-1A and A-1B.

This is of course theoretical and needed later on when controlling with code. Here remove the power supply to the car can stop it.