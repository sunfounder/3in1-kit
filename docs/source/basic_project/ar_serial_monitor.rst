.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ard_serial_monitor:

3.0 Serial Monitor
=============================

In the Arduino IDE, there is a serial monitor that allows you to send messages from your computer to the Arduino board (via USB) and also to receive messages from the Arduino.

So in this project we will learn how to receive data from the Arduino board.

.. note::

    On Uno, Nano, Mini, and Mega, pins 0 and 1 are used for communication with the computer. Connecting anything to these pins can interfere with that communication, including causing failed uploads to the board.


**Using the Serial Monitor**

1. Open the Arduino IDE, and paste the following code in it.

    .. code-block:: arduino

        // the setup routine runs once when you press reset:
        void setup() {
            // initialize serial communication at 9600 bits per second:
            Serial.begin(9600);
        }

        // the loop routine runs over and over again forever:
        void loop() {
            int number = 100;
            Serial.println(number);
            Serial.println("Hello world");
            delay(100);         // delay in between reads for stability
        }

   * `Serial.begin() <https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/>`_: Sets the data rate in bits per second (baud) for serial data transmission, here set to 9600.
   * `Serial.println() <https://www.arduino.cc/reference/en/language/functions/communication/serial/println/>`_.

2. Select the correct board and port to upload the code.
3. In the toolbar, click the magnifying glass icon to turn on Serial Monitor.

.. image:: img/serial1.png
    :align: center

4. Here is the Serial Monitor.

.. image:: img/serial2.png
    :align: center

* **1**: Option to select between automatically scroll and not scroll.
* **2**: Option to show timestamp prior to data displayed on Serial Monitor.
* **3**: Ending selection, select the ending characters appended to data sent to Arduino. Selection includes:

        * **No line Ending** just sends what you type; 
        * **Newline** is ``\n`` and will sends an ASCII new line code after what you type;
        * **Carriage Return** is ``\r``, which will send an ASCII carriage return character after what you type; 
        * **Both NL & CR** is ``\r\n`` which will send both a carriage return and a new line character after what you type.
* **4**: Select communication speed between Arduino board and PC. This value MUST be the same as the value set in ``Serial.begin()``.
* **5**: Clear all text on the output console.
* **6**: A textbox to send characters to the Arduino board, see :ref:`ar_serial_read` for a tutorial.

