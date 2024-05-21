.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_servo:

5.5 Use Internal Library
=======================================

In the Arduino IDE, you can use many built-in libraries by adding the corresponding ``.h`` file directly to your code.

This project uses the ``Servo`` library to drive the Servo, so that it can rotate between 0° and 180°.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|


**Schematic**


.. image:: img/circuit_6.2_servo.png

In this project, we use PWM pin 9 to drive the Servo, and get the orange
wire of the servo connected to the PWM pin 9, the red one to 5V, and the
brown one to GND.

**Wiring**

.. image:: img/swinging_servo_bb.jpg

**Code**

.. note::

    * Open the ``5.5.use_internal_library.ino`` file under the path of ``3in1-kit\basic_project\5.5.use_internal_library``.
    * Or copy this code into **Arduino IDE**.
    
    * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fa27db71-b191-4eda-b5c7-bbbe5f2652ca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Once you finish uploading the codes to the R3 board, you can see the servo arm rotating in the range 0°~180°.

**How it works?**

By calling the library ``Servo.h``, you can drive the servo easily. 

.. code-block:: arduino

    #include <Servo.h> 

Library Functions: 

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