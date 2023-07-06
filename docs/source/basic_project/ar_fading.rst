.. _ar_fading:

2.1 Fading
=================

This project is similar to :ref:`ar_blink` , the difference is the signal type.
The former is to make the LED light on or off by outputting a digital signal (0&1), this project is to control the brightness of the LED by outputting an analog signal.



**Schematic**

.. image:: img/circuit_1.1_led.png



**Wiring**

.. image:: img/wiring_led.png
    :width: 500
    :align: center

* :ref:`cpn_uno`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_resistor`
* :ref:`cpn_led`

**Code**

.. note::

   * You can open the file ``2.1.fading.ino`` under the path of ``3in1-kit\learning_project\2.analogWrite\2.1.fading``. 
   * Or copy this code into **Arduino IDE**.
   
   * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.



.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8a7e52a4-fcb3-4c3b-98ff-f3f657822d72/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
After the code is uploaded successfully, you can see the LED breathing.