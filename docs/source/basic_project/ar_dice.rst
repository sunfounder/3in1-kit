.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_eeprom:

6.2 Digital Dice
=============================

Here we use button, 7-segment and 74hc595 to make an electronic dice. 
Each time the button is pressed, a random number ranging from 1 to 6 is generated and displayed on the 7-segment Display.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|

**Schematic**

.. image:: img/circuit_8.9_eeprom.png

**Wiring**

.. image:: img/wiring_electronic_dice.png
    :width: 800
    :align: center

**Code**

.. note::

    * Open the ``6.2.electronic_dice.ino`` file under the path of ``3in1-kit\basic_project\6.2.electronic_dice``.
    * Or copy this code into **Arduino IDE**.
    
    * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8d8ad340-b1de-4518-917b-caaf07e4baf4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

When the code is uploaded successfully, the 7-segment Display will display 0-7 in a fast scroll, and when you press the button, it will display a random number and stop scrolling. The scrolling display starts again when you press the button again.

**How it works?**

This project is based on :ref:`ar_segment` with a button to start/pause the scrolling display on the 7-segment Display.

#. Initialize each pin and read the value of the button.

    .. code-block:: arduino

        void setup ()
        {

            ...
            attachInterrupt(digitalPinToInterrupt(buttonPin), rollDice, FALLING);
        }

    * The interrupt is used here to read the state of the button. The default value of ``buttonPin`` is low, which changes from low to high when the button is pressed.
    * ``rollDice`` represents the function to be called when the interrupt is triggered, it is used to toggle the value of the variable ``state``.
    * ``FALLING`` means the interrupt is triggered when the ``buttonPin`` goes from low to high.

#. When the variable ``state`` is 0, the function ``showNumber()`` is called to make the 7-segment Display randomly display a number between 1 and 7.

    .. code-block:: arduino

        void loop()
        {
            if (state == 0) {
                showNumber((int)random(1, 7));
                delay(50);
            }
        }

#. About ``rollDice()`` function.

    .. code-block:: arduino

        void rollDice() {
            state = !state;
        }
    
    When this function is called, it toggles the value of state, such as 1 last time and 0 this time.

#. About ``showNumber()`` function.

    .. code-block:: arduino

        void showNumber(int num) {
            digitalWrite(STcp, LOW); //ground ST_CP and hold low for as long as you are transmitting
            shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
            //return the latch pin high to signal chip that it
            //no longer needs to listen for information
            digitalWrite(STcp, HIGH); //pull the ST_CPST_CP to save the data
        }
    
    This is the code inside ``loop()`` in the project :ref:`ar_segment` into the function ``showNumber()``.