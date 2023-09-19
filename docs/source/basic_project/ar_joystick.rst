.. _ar_joystick:

4.3 Toggle the Joystick
================================

The joystick should be very familiar to anyone who plays video games regularly.
It is usually used to move characters or rotate the screen.

Our movements can be read by the Joystick, which works on a very simple principle.
It consists of two potentiometers that are perpendicular to each other.
These two potentiometers measure the analog value of the joystick in both vertical and horizontal directions, producing a value (x,y) in a planar right-angle coordinate system.


This kit also includes a joystick with a digital input. It is activated when the joystick is pressed.


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
    *   - :ref:`cpn_joystick`
        - \-

**Schematic**

.. image:: img/circuit_5.3_joystick.png

.. note::
    The SW pin is connected to a 10K pull-up resistor, 
    the reason is to be able to get a stable high level on the SW pin (Z axis) when the joystick is not pressed; 
    otherwise the SW is in a suspended state and the output value may vary between 0/1.

**Wiring**

.. image:: img/toggle_the_joystick_bb.jpg
    :width: 800
    :align: center

**Code**

.. note::

    * Open the ``4.3.toggle_the_joystick.ino`` file under the path of ``3in1-kit\basic_project\4.3.toggle_the_joystick``.
    * Or copy this code into **Arduino IDE**.
    
    * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f678a03f-546c-42ed-bfae-b8c7daa5eec9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Open the serial monitor after the code has been uploaded successfully to see the x,y,z values of the joystick.

* The x-axis and y-axis values are analog values that vary from 0 to 1023.
* The Z-axis is a digital value with a status of 1 or 0 ( when pressed , it is 0 ).