.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_digital_write:

1. Digital Write
==============================

**Digital Write** is to output or write a digital signal to a digital pin. The digital signal has only two states, 0 or 1, 0V or 5V, so it allows some components, such as the LED and buzzer, to be on or off.

On the Arduino R3 board, there are 14 digital I/0 pins from 0 to 13, now use the ``pinMode()`` and ``digitalWrite()`` functions to write a high or low level to these digital pins.


* ``pinMode(pin, mode)``: Configure the specific pin as ``INPUT`` or ``OUTPUT``, here it needs to be set as ``OUTPUT``. 

   **Syntax**
      pinMode(pin, mode)

   **Parameters**
    * ``pin``: the Arduino pin number to set the mode of.
    * ``mode``: ``INPUT``, ``OUTPUT``, or ``INPUT_PULLUP``.


* ``digitalWrite(pin, value)``: Write a high level (5V) or a low level (0V) to a digital pin to change the operating state of the component. If the pin has been configured as an OUTPUT with pinMode(), its voltage will be set to the corresponding value: 5V (or 3.3V on 3.3V boards) for HIGH, 0V (ground) for LOW.


   **Syntax**
      digitalWrite(pin, value)

   **Parameters**
    * ``pin``: the Arduino pin number.
    * ``value``: ``HIGH`` or ``LOW``.

**Example of Digital Write:**

.. code-block:: arduino

   const int pin = 13;

   void setup() {
      pinMode(pin, OUTPUT);    // sets the digital pin as output
   }

   void loop() {
      digitalWrite(pin, HIGH); // sets the digital pin on
      delay(1000);            // waits for a second
      digitalWrite(pin, LOW);  // sets the digital pin off
      delay(1000);            // waits for a second
   }

.. image:: img/1_led.jpg


**Notes and Warnings**

* The pins 0~13 are all digital pins.
* Do not use pins 0 and 1, as they are used to communicate with the computer. Connecting anything to these pins will interfere with communication, including causing the upload board to fail.
* If the digital pins are used up, the analog pins (A0-A5) can also be used as digital pins.

**Related Components**

Below are the related components, you can click in to learn how to use them.

.. toctree::
   :maxdepth: 2

   ar_blinking_led
   ar_active_buzzer
   ar_turn_the_wheel
   ar_pumping


