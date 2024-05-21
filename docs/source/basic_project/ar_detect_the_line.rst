.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_line_track:

3.4 Detect the Line
===================================

The line tracking module is used to detect whether there are black areas on the ground, such as black lines pasted with electrical tape.

One of its LEDs emits appropriate infrared light to the ground, and the black surface has a relatively strong ability to absorb light and a weaker reflection ability. White surfaces are the opposite.
If it detects reflected light, it means the ground is currently white. If not detected, it means black.

That's how it works.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_track`
        - |link_track_buy|

**Schematic**

.. image:: img/circuit_3.4_line.png

The digital pin 2 is used to read the
signal of line track module. We get the VCC of the module connected to 5V, 
GND to GND, OUT to digital pin 2.

**Wiring**

.. image:: img/detect_the_line_bb.jpg
    :width: 500
    :align: center

**Code**

.. note::

   * You can open the file ``3.4.detect_the_line.ino`` under the path of ``3in1-kit\basic_project\3.4.detect_the_line``. 
   * Or copy this code into **Arduino IDE**.
   
   * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9795add6-c838-4a66-b484-0c39f252a7b4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

When the line tracking module detects there is black line, there appears [1] on the Serial Monitor; otherwise, [0] is displayed.
