.. _ar_reversing_aid:

6.4 Reversing Aid
===================

With the development of science and technology, a lot of high-tech
products have been installed in cars, among which the reversing assist
system is one of them. Here we use ultrasonic module, LCD, LED and
buzzer to make a simple ultrasonic reversing assist system.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Schematic Diagram**

.. image:: img/image265.png
    :width: 800
    :align: center

**Fritzing Circuit**

.. image:: img/6.4_reversing_aid_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * You can open the file ``6.4_reversingAid.ino`` under the path of ``3in1-kit\learning_project\6.4_reversingAid`` directly.
    * Or copy this code into Arduino IDE 1/2.
    * The ``LiquidCrystal I2C`` library is used here, you can install it from the **Library Manager**.

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d6848669-fe79-42e9-afd7-0f083f96a6d6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After the code is successfully uploaded, the current detected distance will be displayed on the LCD. Then the buzzer will change the sounding frequency according to different distances.

.. note::
    If the code and wiring are fine, but the LCD still does not display content, you can turn the potentiometer on the back.

**How it works?**

In this project, we need to avoid the interference between the LCD
screen and the alarm system as much as possible (for example, the LED
flicker time is too long and the LCD refresh is delayed), so please
avoid using the ``delay()`` statement and use two separate intervals to
control the working frequency of the LCD and alarm system respectively.
Its workflow is shown in the flow chart. For analysis of Interval
function, refer to :ref:`ar_interval`.

.. image:: img/Part_three_1_Example_Explanation.png
   :align: center
