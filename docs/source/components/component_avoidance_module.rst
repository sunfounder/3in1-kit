.. _cpn_avoid:

Obstacle Avoidance Module
===========================================


.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC**: Power supply, 3.3 ~ 5V DC.
* **GND**: Ground
* **OUT**: Signal pin, usually high level, and low level when an obstacle is detected.


The IR obstacle avoidance module has strong adaptability to environmental light, it has a pair of infrared transmitting and receiving tubes.

The transmitting tube emits infrared frequency, when the detection direction encounters an obstacle, the infrared radiation is received by the receiving tube, 
after the comparator circuit processing, the indicator will light up and output low level signal.

The detection distance can be adjusted by potentiometer, the effective distance range 2-30cm.

.. image:: img/IR_module.png
    :width: 600
    :align: center

**Example**

* :ref:`ar_ir_obstacle` (Basic Project)
* :ref:`car_ir_obstacle` (Car Project)
* :ref:`self_driving` (Car Project)
* :ref:`iot_gate` (IoT Project)
* :ref:`sh_shooting` (Scratch Project)
* :ref:`sh_tap_tile` (Scratch Project)






