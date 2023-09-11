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

3. After modifying the code, upload the code to R3 board to see the effect. Repeat the above steps until the car is almost straight.

4. This offset will be recorded in `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_, you only need to read this offset when you use it in other projects, take :ref:`car_ir_obstacle` as an example.


.. code-block:: arduino
    :emphasize-lines: 1,3,4,27,28,50,51

    #include <EEPROM.h>

    float leftOffset = 1.0;
    float rightOffset = 1.0;

    const int in1 = 5;
    const int in2 = 6;
    const int in3 = 9;
    const int in4 = 10;

    const int rightIR = 7;
    const int leftIR = 8;

    void setup() {
        Serial.begin(9600);

        //motor
        pinMode(in1, OUTPUT);
        pinMode(in2, OUTPUT);
        pinMode(in3, OUTPUT);
        pinMode(in4, OUTPUT);

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
        analogWrite(in1, 0);
        analogWrite(in2, int(speed * leftOffset));
        analogWrite(in3, int(speed * rightOffset));
        analogWrite(in4, 0);
    }

    void moveBackward(int speed) {
        analogWrite(in1, speed);
        analogWrite(in2, 0);
        analogWrite(in3, 0);
        analogWrite(in4, speed);
    }

    void backLeft(int speed) {
        analogWrite(in1, speed);
        analogWrite(in2, 0);
        analogWrite(in3, 0);
        analogWrite(in4, 0);
    }

    void backRight(int speed) {
        analogWrite(in1, 0);
        analogWrite(in2, 0);
        analogWrite(in3, 0);
        analogWrite(in4, speed);
    }

