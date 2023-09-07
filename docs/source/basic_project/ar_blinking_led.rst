.. _ar_blink:

1.1 Hello, LED! 
=======================================

Just as printing “Hello, world!” is the first step in learning to program, using a program to drive an LED is the traditional introduction to learning physical programming.



**Schematic**

.. image:: img/circuit_1.1_led.png

The principle of this circuit is simple and the current direction is shown in the figure. When pin 9 outputs high level(5V), the LED will light up after the 220ohm current limiting resistor. When pin 9 outputs low level (0v), the LED will turn off.

**Wiring**

.. image:: img/wiring_led.png
    :width: 400
    :align: center


* :ref:`cpn_uno`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_resistor`
* :ref:`cpn_led`



**Code**

.. note::

   * You can open the file ``1.1.hello_led.ino`` under the path of ``3in1-kit\basic_project\1.1.hello_led``. 
   * Or copy this code into **Arduino IDE**.
   
   * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.



.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/0497f915-5bf8-41a2-8e0f-b013130a57f5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After the code is uploaded successfully, you will see the LED blinking.

**How it works?**

Here, we connect the LED to the digital pin 9, so we need to declare an int variable called ledpin at the beginning of the program and assign a value of 9.

.. code-block:: arduino

    const int ledPin = 9;


Now, initialize the pin in the ``setup()`` function, where you need to initialize the pin to ``OUTPUT`` mode.

.. code-block:: arduino

    void setup() {
        pinMode(ledPin, OUTPUT);
    }

In ``loop()``, ``digitalWrite()`` is used to provide 5V high level signal for ledpin, which will cause voltage difference between LED pins and light LED up.

.. code-block:: arduino

    digitalWrite(ledPin, HIGH);

If the level signal is changed to LOW, the ledPin’s signal will be returned to 0 V to turn LED off.

.. code-block:: arduino

    digitalWrite(ledPin, LOW);


An interval between on and off is required to allow people to see the change, 
so we use a ``delay(1000)`` code to let the controller do nothing for 1000 ms.

.. code-block:: arduino

    delay(1000);   