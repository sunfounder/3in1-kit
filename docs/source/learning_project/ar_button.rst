.. _ar_button:

3.1 Reading Button Value
==============================================


In the previous projects, we used the output function, in this chapter we will use the input function to input read the button value.



**Schematic**

.. image:: img/circuit_3.1_button.png

One side of the button pin is connected to 5V, 
and the other side pin is connected to pin 2, 
so when the button is pressed, 
pin 2 will be high. However, 
when the button is not pressed, 
pin 2 is in a suspended state and may be high or low. 
In order to get a stable low level when the button is not pressed, 
pin 2 needs to be reconnected to GND through a 10K pull-down resistor.



**Wiring**


.. image:: img/read_the_button_value_bb.jpg
    :width: 600
    :align: center


* :ref:`cpn_uno`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_resistor`
* :ref:`cpn_button`

**Code**

.. note::

   * You can open the file ``3.1.read_button_value.ino`` under the path of ``3in1-kit\learning_project\3.1.read_button_value``. 
   * Or copy this code into **Arduino IDE**.
   
   * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/b456ff57-4dfb-4231-9d91-f1e9a5777de2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After the code is uploaded successfully, click the magnifying glass icon in the upper right corner of the Arduino IDE (Serial Monitor).

.. image:: img/sp220614_152922.png

When you press the button, the Serial Monitor will print "1".


