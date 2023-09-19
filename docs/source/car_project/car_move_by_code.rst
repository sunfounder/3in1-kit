.. _car_move_code:

2. Move by Code
======================

In the previous project, we have tried to control the operation of the motor by using different level signals for the input of the L298N.

If we modify the level signals through the program, then we can control the movement of the car in a flexible way.
Here we connect the pins IN1~IN4 of L298N to pins 5, 6, 9 and 10 on the R3 board in turn.

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


**Wiring**


The L298N motor driver module is a high power motor driver module for driving DC and stepper motors. The L298N module can control up to 4 DC motors, or 2 DC motors with direction and speed control.

Connect the wires between the L298N module and the R3 board according to the diagram below.


.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L298N
      - R3 Board
      - Motor
    * - IN1
      - 5
      - 
    * - IN2
      - 6
      - 
    * - IN3
      - 9
      - 
    * - IN4
      - 10
      - 
    * - OUT1
      - 
      - Black wire of right motor
    * - OUT2
      - 
      - Red wire of right motor
    * - OUT3
      - 
      - Black wire of left motor
    * - OUT4
      - 
      - Red wire of left motor

.. image:: img/car_motor1.jpg
    :width: 800

**Code**

.. note::

    * Open the ``2.move.ino`` file under the path of ``3in1-kit\car_project\2.move``.
    * Or copy this code into **Arduino IDE**.
    
    * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d9c830d3-1371-4867-a2e7-18d85d0b9d25/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


After the code is uploaded, the car will move forward, backward, left and right for two seconds respectively.

**How it works?**

This project is basically the same as the previous one, which is to make the car move forward, backward, left and right and stop by giving different levels from IN1 to IN4.

#. Initialize the pin wiring of IN1~IN4.

    .. code-block:: arduino

        const int in1 = 5;
        const int in2 = 6;
        const int in3 = 9;
        const int in4 = 10;

        void setup() {
            pinMode(in1, OUTPUT);
            pinMode(in2, OUTPUT);
            pinMode(in3, OUTPUT);
            pinMode(in4, OUTPUT);
        }

#. Set IN1~IN4 to different high or low levels to control the rotation of the left and right motors, and then encapsulate them in individual functions.

    .. code-block:: arduino

        void moveForward() {
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
        }

        void moveBackward() {
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
        }
        ...
#. Call these functions in ``loop()``.

    .. code-block:: arduino

        void loop() {
            moveForward();
            delay(2000);
            stopMove();
            delay(500);

            moveBackward();
            delay(2000);
            stopMove();
            delay(500);
        ...

* `digitalWrite(pin, value) <https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/>`_

    * ``pin``: the Arduino pin number.
    * ``value``: HIGH or LOW.
    
    Write a HIGH or a LOW value to a digital pin. If the pin has been configured as an ``OUTPUT`` with ``pinMode()``, its voltage will be set to the corresponding value: 5V (or 3.3V on 3.3V boards) for HIGH, 0V (ground) for LOW.


* `pinMode(pin, mode) <https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/>`_

    * ``pin``: the Arduino pin number to set the mode of.
    * ``mode``: INPUT, OUTPUT, or INPUT_PULLUP.
    
    Configures the specified pin to behave either as an input or an output.

* `delay(ms) <https://www.arduino.cc/reference/en/language/functions/time/delay/>`_

    * ``ms``: the number of milliseconds to pause. Allowed data types: unsigned long.

    Pauses the program for the amount of time (in milliseconds) specified as parameter. (There are 1000 milliseconds in a second.)
