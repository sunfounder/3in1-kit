.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_analog_read:

4. Analog Read
======================

The Arduino can read the connected analog sensors through the analog pins.

The R3 board contains a multi-channel, 10-bit analog-to-digital converter. This means it maps the input voltage between 0 and the operating voltage (5V or 3.3V) to an integer value between 0 and 1023.

You need the ``analogRead(pin)`` function to read the value of the analog pin.

* ``analogRead(pin)``: Read the value from the specified analog pin.

   **Syntax**
      analogRead(pin)

   **Parameters**
        * ``pin``: the name of the analog input pin to read from (A0 to A5).

   **Returns**
      0-1023. Data type: int.


**Example of Analog Read**

.. code-block:: arduino

   int analogPin = A0; // device connected to analog pin A0
                     // outside leads to ground and +5V
   int val = 0;  // variable to store the value read

   void setup() {
      Serial.begin(9600);           //  setup serial
   }

   void loop() {
      val = analogRead(analogPin);  // read the input pin
      Serial.println(val);          // debug value
   }


**Notes and Warnings**

* The analog pins are A0-A5.
* You don't need to call ``pinMode()`` before calling the analog pin, but if the pin was previously set to ``OUTPUT``, the function ``analogRead()`` will not work properly, in which case you need to call ``pinMode()`` to set it back to ``INTPUT``.

**Related Components**

Below are the related components, you can click in to learn how to use them.

.. toctree::
    :maxdepth: 2

    ar_turn_the_knob
    ar_photoresistor
    ar_joystick
    ar_moisture
    ar_thermistor