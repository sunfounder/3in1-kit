.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_lcd1602:

5.11.1 Liquid Crystal Display
===============================

An I2C LCD1602 is composed of an LCD1602 and an I2C module, LCD1602 can be used to display characters, numbers, etc., but need to take up a lot of pins of the main control, after configuring an I2C module, only 2 I/0 pins are needed to drive this LCD1602.

Now look at how to make this I2C CDL1602 work.

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
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

**Schematic**

.. image:: img/circuit_7.1_lcd1602.png

**Wiring**

.. image:: img/5.11_lcd_bb.png
    :width: 800
    :align: center

.. note::
    The SDA and SCL of the R4 board are the pins A4 and A5.

**Code**

.. note::

    * Open the ``5.11.liquid_crystal_display.ino`` file under the path of ``3in1-kit\learning_project\5.11.liquid_crystal_display``.
    * Or copy this code into **Arduino IDE**.
    * The ``LiquidCrystal I2C`` library is used here, you can install it from the **Library Manager**.

        .. image:: ../img/lib_liquidcrystal_i2c.png
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e49c4936-2530-4890-b86c-1017d11eae6e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
After the code is uploaded successfully, you will see "SunFounder", "Hello World" on the I2C LCD1602.

.. note::
    If the code and wiring are fine, but the LCD still does not display content, you can turn the potentiometer on the back.

**How it works?**

By calling the library ``LiquidCrystal_I2C.h``, you can easily drive the LCD. 

.. code-block:: arduino

    #include "LiquidCrystal_I2C.h"

Library Functions: 

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
