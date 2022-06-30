.. _ar_lcd1602:

6.1 Liquid Crystal Display
===============================

An I2C LCD1602 is composed of an LCD1602 and an I2C module, LCD1602 can be used to display characters, numbers, etc., but need to take up a lot of pins of the main control, after configuring an I2C module, only 2 I/0 pins are needed to drive this LCD1602.

Now look at how to make this I2C CDL1602 work.


**Schematic**


.. image:: img/circuit_7.1_lcd1602.png

**Wiring**

.. image:: img/lcd_bb.jpg

.. note::
    The SDA and SCL of the R3 board are the pins A4 and A5.

* :ref:`cpn_uno`
* :ref:`cpn_wires`
* :ref:`cpn_i2c_lcd1602`

**Code**

.. note::

    * Open the ``6.1.liquid_crystal_display.ino`` file under the path of ``3in1-kit\learning_project\6.1.liquid_crystal_display``.
    * Or copy this code into **Arduino IDE**.
    * For detailed tutorials, please refer to :ref:`ar_upload_code`.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b4f91d26-166a-41ca-8394-b75944332611/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After the code is uploaded successfully, you will see "Hello, Sunfounder!" on the I2C LCD1602.


**How it works?**

By calling the library ``LiquidCrystal_I2C.h``, you can easily drive the LCD. 

.. code-block:: arduino

    #include "LiquidCrystal_I2C.h"

Library Functions：

.. code-block:: arduino

    LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)

Creates a new instance of the ``LiquidCrystal_I2C`` class that represents a
particular LCD attached to your Arduino board.

* ``lcd_AddR``: The address of the LCD defaults to 0x27.
* ``lcd_cols``: The LCD1602 has 16 columns.
* ``lcd_rows``: The LCD1602 has 2 rows.


.. code-block:: arduino

    void init()

Initialize the lcd.

.. code-block:: arduino

    void backlight()

Turn the (optional) backlight on.

.. code-block:: arduino

    void nobacklight()

Turn the (optional) backlight off.

.. code-block:: arduino

    void display()

Turn the LCD display on.

.. code-block:: arduino

    void nodisplay()

Turn the LCD display off quickly.

.. code-block:: arduino

    void clear()

Clear display, set cursor position to zero.

.. code-block:: arduino

    void setCursor(uint8_t col,uint8_t row)

Set the cursor position to col,row.

.. code-block:: arduino

    void print(data,BASE)

Prints text to the LCD.

* ``data``: The data to print (char, byte, int, long, or string).
* ``BASE (optional)``: The base in which to print numbers: BIN for binary (base 2), DEC for decimal (base 10), OCT for octal (base 8), HEX for hexadecimal (base 16).
