.. _ar_serial_read:

5.12 Serial Read
======================

You may have noticed this when using the ``Serial.print()`` function.
Since there is printing, is there reading? What is the text box on the Serial Monitor used for?
Yes, you guessed it, there are ways to control programs and circuits by entering information through the text box on the Serial Monitor.

In this project, we will use the I2C LCD1602 to display the text entered in the Serial Monitor in order to experience the usage of ``Serial.read()``.



**Schematic**

.. image:: img/circuit_7.1_lcd1602.png

**Wiring**

.. image:: img/lcd_bb.jpg
    :width: 800
    :align: center


* :ref:`cpn_uno`
* :ref:`cpn_wires`
* :ref:`cpn_i2c_lcd1602`

**Code**

.. note::

    * Open the ``5.12.serial_read.ino`` file under the path of ``3in1-kit\learning_project\5.12.serial_read``.
    * Or copy this code into **Arduino IDE**.
    * For detailed tutorials, please refer to :ref:`ar_upload_code`.
    * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/a6197c53-6969-402e-8930-84a9165397b9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
After the code is uploaded successfully, you can enter text in the text box on the serial monitor, and the LCD will display the information.


**How it works?**

    .. code-block:: arduino

        void loop()
        {
        // when characters arrive over the serial port...
            if (Serial.available()) {
                // wait a bit for the entire message to arrive
                delay(100);
                // clear the screen
                lcd.clear();
                // read all the available characters
                while (Serial.available() > 0) {
                    // display each character to the LCD
                    lcd.write(Serial.read());
                }
            }
        }

* ``Serial.available()`` can get the number of characters available in the incoming stream when you type something from the textbox. Since there are two terminators in the input, you actually have 3 characters when you type ``A``, and 4 characters when you type ``AB``.
* ``Serial.read()`` will take the first character from the incoming stream. For example, if you typed ``AB`` , calling ``Serial.read()`` only once, will get the character ``A``; The second call, you will get ``B``; the third and fourth call, you will get two end symbols; calling this function when the input stream has no characters available will result in an error.

To sum up, it is common to combine the above two, using a ``while`` loop to read all characters entered each time.

    .. code-block:: arduino

        while (Serial.available() > 0) {
            Serial.print(Serial.read());
        }

By the way, if you don't use ``Serial.read()`` to get characters from the incoming stream, the characters from the incoming stream will be stacked together.
For example, if you type ``A`` followed by ``AB``, the incoming stream will accumulate 7 characters.