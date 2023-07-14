.. _ar_servo:

5.5 Use Internal Library
=======================================


In the Arduino IDE, you can use many built-in libraries by adding the corresponding ``.h`` file directly to your code.

This project uses the ``Servo`` library to drive the Servo, so that it can rotate between 0° and 180°.


**Schematic**


.. image:: img/circuit_6.2_servo.png

In this project, we use PWM pin 9 to drive the Servo, and get the orange
wire of the servo connected to the PWM pin 9, the red one to 5V, and the
brown one to GND.

**Wiring**

.. image:: img/5.5_swinging_servo_bb.png

* :ref:`cpn_uno`
* :ref:`cpn_wires`
* :ref:`cpn_servo`

**Code**

.. note::

    * Open the ``5.5.use_internal_library.ino`` file under the path of ``3in1-kit\learning_project\5.5.use_internal_library``.
    * Or copy this code into **Arduino IDE**.
    
    * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fa27db71-b191-4eda-b5c7-bbbe5f2652ca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Once you finish uploading the codes to the R4 board, you can see the servo arm rotating in the range 0°~180°.

**How it works?**

By calling the library ``Servo.h``, you can drive the servo easily. 

.. code-block:: arduino

    #include <Servo.h> 

Library Functions：

.. code-block:: arduino

    Servo

Create **Servo** object to control a servo.

.. code-block:: arduino

    uint8_t attach(int pin); 

Call ``pinMode()`` to turn a pin into a servo driver and return 0 on failure.

.. code-block:: arduino

    void detach();

Release a pin from servo driving.

.. code-block:: arduino

    void write(int value); 

Set the angle of the servo in degrees, 0 to 180.

.. code-block:: arduino

    int read();

Return that value set with the last ``write()``.

.. code-block:: arduino

    bool attached(); 

Return 1 if the servo is currently attached.