.. _ar_reed:

3.2 Feel the Magnetism
===============================

The most common type of reed switch contains a pair of magnetizable, flexible, metal reeds whose end portions are separated by a small gap when the switch is open. 

A magnetic field from an electromagnet or a permanent magnet will cause the reeds to attract each other, thus completing an electrical circuit.
The spring force of the reeds causes them to separate, and open the circuit, when the magnetic field ceases.

A common example of a reed switch application is to detect the opening of a door or windows, for a security alarm.



**Schematic**

.. image:: img/circuit_3.2_reed.png

By default, pin 2 is low; and will go high when the magnet is near the reed switch.

The purpose of the 10K resistor is to keep the pin 2 at a steady low level when no magnet is near.


**Wiring**


.. image:: img/feel_the_magnetism_bb.jpg
    :width: 600
    :align: center

* :ref:`cpn_uno`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_resistor`
* :ref:`cpn_reed`


**Code**

.. note::

   * You can open the file ``3.2.feel_the_magnetism.ino`` under the path of ``3in1-kit\basic_project\3.2.feel_the_magnetism``. 
   * Or copy this code into **Arduino IDE**.
   
   * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/d28c942e-5144-44a1-85d8-d5e6894fc5df/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
After the code is uploaded successfully, when a magnet is near the reed switch, the serial monitor will print 1.

