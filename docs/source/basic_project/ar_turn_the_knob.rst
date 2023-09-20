.. _ar_potentiometer:

4.1 Turn the Knob
===================

Potentiometer is a resistor component with 3 terminals and its resistance value can be
adjusted according to some regular variation.

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
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**Schematic**

.. image:: img/circuit_5.1_potentiometer.png

In this example, we use the analog pin (A0) to read the value
of the potentiometer. By rotating the axis of the potentiometer, you can
change the distribution of resistance among these three pins, changing
the voltage on the middle pin. When the resistance between the middle
and a outside pin connected to 5V is close to zero (and the resistance
between the middle and the other outside pin is close to 10kΩ), the
voltage at the middle pin is close to 5V. The reverse operation (the
resistance between the middle and a outside pin connected to 5V is close
to 10kΩ) will make the voltage at the middle pin be close to 0V.

**Wiring**

.. image:: img/4.1_turn_thek_knob_bb.png
    :width: 600
    :align: center

**Code**

.. note::

   * You can open the file ``4.1.turn_the_knob.ino`` under the path of ``3in1-kit\learning_project\4.1.turn_the_knob``. 
   * Or copy this code into **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d931f2c9-74bc-4a53-8531-39a21a07dbaf/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
After uploading the codes to the board, you can open the serial
monitor to see the reading value of the pin. When rotating the axis of
the potentiometer, the serial monitor will print the value
「0」~「1023」. 