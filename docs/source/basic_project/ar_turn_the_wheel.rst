.. _ar_motor:

1.3 Motor
============================

A motor is a typical digital output device, and it is used in the same way as an LED.
However, the motor needs to be driven with a large current, and the large current may damage the main control board such as R3 board.
Therefore, an L9110 module is used in this occasion, which is a good helper for the R3 board to control the motor safely.

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
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

**Schematic**


.. image:: img/circuit_1.3_wheel_l9110.png


**Wiring**


.. image:: img/1.3_motor_l9110_bb.png
    :width: 800
    :align: center

**Code**

.. note::

   * You can open the file ``1.3.turn_the_wheel.ino`` under the path of ``3in1-kit\basic_project\1.3.turn_the_wheel``. 
   * Or copy this code into **Arduino IDE**.
   
   * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/5f8e4f33-883b-4c06-9516-f1754ea2121d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
