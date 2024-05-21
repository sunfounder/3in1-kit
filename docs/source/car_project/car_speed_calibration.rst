.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _speed_calibration:

11. Speed Calibration
===========================

In getting the car to move forward, you may find that the car does not travel in a straight line.
This is because the two motors may not have the same speed at the factory. 
But we can write offset to the two motors to make their rotational speeds converge.

In this project, 
we will learn to store the offset into `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_, the point of this is that after each calibration, 
all projects can get the offset value directly from the EEPROM, 
so that the car can go in a straight line smoothly.


**Wiring**

This project is the same wiring as :ref:`car_move_code`.



**How to play?**

1. Open the ``11.speed_calibration.ino`` file under the path of ``3in1-kit\car_project\11.speed_calibration``. Or copy this code into **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/66dc7ee5-31a5-418e-9aa2-43e7820cf5e6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


2. After the code is uploaded successfully, connect the car with 9V battery, put it on the ground and let it move forward to see which side it is offset to.

* If the car moves to the left front, it means the right motor speed is too fast and needs to be reduced.

    .. code-block:: arduino

        EEPROM.write(1, 100) // 1 means the right motor, 100 means 100% speed, can be set to 90, 95, etc., depending on the actual situation.

* If the car moves to the right, it means the left motor speed is too fast and needs to be reduced.

    .. code-block:: arduino

        EEPROM.write(0, 100) // 0 means the right motor, 100 means the speed is 100%, can be set to 90, 95, etc., depending on the actual situation. 3.

3. After modifying the code, upload the code to R4 board to see the effect. Repeat the above steps until the car is almost straight.

4. This offset will be recorded in `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_, you only need to read this offset when you use it in other projects, take :ref:`car_ir_obstacle` as an example.


.. code-block:: arduino
    :emphasize-lines: 1,3,4,27,28,50,51

    #include <EEPROM.h>

    float leftOffset = 1.0;
    float rightOffset = 1.0;

    const int A_1B = 5;
    const int A_1A = 6;
    const int B_1B = 9;
    const int B_1A = 10;

    const int rightIR = 7;
    const int leftIR = 8;

    void setup() {
        Serial.begin(9600);

        //motor
        pinMode(A_1B, OUTPUT);
        pinMode(A_1A, OUTPUT);
        pinMode(B_1B, OUTPUT);
        pinMode(B_1A, OUTPUT);

        //IR obstacle
        pinMode(leftIR, INPUT);
        pinMode(rightIR, INPUT);

        leftOffset = EEPROM.read(0) * 0.01;//read the offset of the left motor
        rightOffset = EEPROM.read(1) * 0.01;//read the offset of the right motor
    }

    void loop() {

        int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
        int right = digitalRead(rightIR);
        int speed = 150;

        if (!left && right) {
            backLeft(speed);
        } else if (left && !right) {
            backRight(speed);
        } else if (!left && !right) {
            moveBackward(speed);
        } else {
            moveForward(speed);
        }
    }

    void moveForward(int speed) {
        analogWrite(A_1B, 0);
        analogWrite(A_1A, int(speed * leftOffset));
        analogWrite(B_1B, int(speed * rightOffset));
        analogWrite(B_1A, 0);
    }

    void moveBackward(int speed) {
        analogWrite(A_1B, speed);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, speed);
    }

    void backLeft(int speed) {
        analogWrite(A_1B, speed);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, 0);
    }

    void backRight(int speed) {
        analogWrite(A_1B, 0);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, speed);
    }

