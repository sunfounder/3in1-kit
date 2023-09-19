.. _sh_move:

3.2 Movement
==================

This project is based on :ref:`sh_test` to make the car move in all directions.

Before we start programming, let's review the working principle of L9110 module.

Here is the truth table of Motor B:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B
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



Programming
-------------------

Now create blocks to make the car, forward, backward, left and right rotation and stop respectively.


**1. Move Forward**

The right motor turns clockwise and the left motor turns counterclockwise to move the car forward.

.. image:: img/2_forward.png

**2. Move Backward**

Backward is just the opposite, the right motor needs to turn counterclockwise, the left motor clockwise.

.. image:: img/2_backward.png

**3. Turn Left**

The left and right motors turn clockwise at the same time to make the car turn left.

.. image:: img/2_turn_left.png

**4. Turn Right**

Similarly, turn the left and right motors counterclockwise to turn the car to the right.

.. image:: img/2_turn_right.png

**5. Stop**

Stop the car by setting all motors to 0.

.. image:: img/2_stop.png

**6. Make the car move**

Make the car move forward, backward, left and right for 1 second, then stop. Since all blocks are placed in the [Forever] block, you will see that the car repeats the above actions.

.. image:: img/2_move.png