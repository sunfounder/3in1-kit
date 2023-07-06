.. _self_driving:

8. Self-Driving Car
=========================

This project is a combination of the two projects :ref:`car_ultrasonic` and :ref:`car_ir_obstacle`. 
2 infrared obstacle avoidance modules do short distance or edge detection, 
and ultrasonic modules do long distance detection to confirm that the car does not hit an obstacle during the free driving process.


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


* :ref:`cpn_uno`
* :ref:`cpn_l298n` 
* :ref:`cpn_tt_motor`
* :ref:`cpn_ultrasonic`
* :ref:`cpn_avoid` 

**Code**

.. note::

    * Open the ``8.self_driving_car.ino`` file under the path of ``3in1-kit\car_project\8.self_driving_car``.
    * Or copy this code into **Arduino IDE**.
    
    * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0a74a7b1-ead6-4bea-ab5a-4da71f27f82f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

The car will drive freely once the code has been uploaded successfully. When the IR obstruction module on both sides detects an obstacle, it will move in the opposite direction for emergency evasion; if there is an obstacle within 2~10cm directly in front of the car, it will back up to the left, adjust its direction, and then move forward.


**How it works?**

The workflow of this project is as follows.

* Priority read the value of left and right IR obstacle avoidance module.
* If the left IR module is 0 (obstacle detected), the right IR module is 1, let the car back up to the left.
* If the right IR module is 0 (obstacle detected), let the car back up to the right.
* If 2 IR modules detect the obstacle at the same time, the car will back up.
* Otherwise read the distance detected by the ultrasonic module.
* If the distance is greater than 50cm, let the car go forward.
* If the distance is between 2-10cm, let the car backward before turning.
* If the distance is between 10-50cm, let the car go forward at low speed.


.. code-block:: arduino

    void loop() {

        int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
        int right = digitalRead(rightIR);

        if (!left && right) {
            backLeft(150);
        } else if (left && !right) {
            backRight(150);
        } else if (!left && !right) {
            moveBackward(150);
        } else {
            float distance = readSensorData();
            Serial.println(distance);
            if (distance > 50) { // Safe
                moveForward(200);
            } else if (distance < 10 && distance > 2) { // Attention
                moveBackward(200);
                delay(1000);
                backLeft(150);
                delay(500);
            } else {
                moveForward(150);
            }
        }
    }

