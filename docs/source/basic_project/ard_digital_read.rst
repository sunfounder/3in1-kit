.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_digital_read:

3. Digital Read
===================

Sensors capture real-world information, which is then communicated to the main board via pins (some digital, some analog) so that the computer can know the reality of the situation.

Therefore, the Arduino board can know the working status of digital sensors by reading the value of digital pins like buttons, IR obstacle avoidance module.


Here are the required functions.

* ``pinMode(pin, mode)``: Configure the specific pin as ``INPUT`` or ``OUTPUT``, here it needs to be set as ``INPUT``. 

   **Syntax**
      pinMode(pin, mode)

   **Parameters**
    * ``pin``: the Arduino pin number to set the mode of.
    * ``mode``: INPUT, OUTPUT, or INPUT_PULLUP.



* ``digitalRead(pin)``: Read the value (level state) from the specified digital pin.

   **Syntax**
      digitalRead(pin)

   **Parameters**
    * ``pin``: the Arduino pin number you want to read

   **Returns**
      HIGH or LOW


**Example of Digital Read**

.. code-block:: arduino

   int ledPin = 13;  // LED connected to digital pin 13
   int inPin = 7;    // pushbutton connected to digital pin 7
   int val = 0;      // variable to store the read value

   void setup() {
      pinMode(ledPin, OUTPUT);  // sets the digital pin 13 as output
      pinMode(inPin, INPUT);    // sets the digital pin 7 as input
   }

   void loop() {
      val = digitalRead(inPin);   // read the input pin
      digitalWrite(ledPin, val);  // sets the LED to the button's value
   }


**Notes and Warnings**

1. Pull Up & Pull Down.

    ``digitalRead()`` may produce random, indeterminate values if the pin is not getting a level signal. So directing the input pins to a known state can make the project more reliable.
    When using an input component such as a button, it is usually necessary to connect a pull-up or pull-down resistor in parallel to the digital input pin.

    Apart from connecting a pull-up resistor, you can also set the pin mode to ``INPUT_PULLUP`` in the code, for example ``pinMode(pin,INPUT_PULLUP)``. In this case, the pin will access the Atmega's built-in pull-up resistor via software, and it will have the same effect as connecting a pull-up resistor.

2. About Pin13.

    All digital pins (1-13) on the R4 board can be used as ``digitalRead()``.
    But digital pin 13 is more difficult to use as a digital input than other digital pins.
    Because it connects an LED and resistor, it is soldered on most boards.
    If you enable its internal 20k pull-up resistor, it will hang around 1.7V instead of the expected 5V because the onboard LED and series resistor pull the voltage level low, which means it always returns LOW. If you must use pin 13 as a digital input, set its ``pinMode()`` to INPUT and use an external pull-down resistor.

3. Analog pins.

    If the digital pins are not enough, the analog pins (A0-A5) can also be used as digital pins.
    It needs to be set to INPUT with ``pinMode(pin,mode)``.


**Related Components**

Below are the related components, you can click in to learn how to use them.

.. toctree::
    :maxdepth: 2

    ar_serial_monitor
    ar_button
    ar_reed
    ar_detect_the_obstacle
    ar_detect_the_line


