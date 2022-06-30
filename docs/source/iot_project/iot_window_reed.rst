
.. _iot_window:

3. Push Data to Blynk
=============================

This chapter will show you how to send data to Blynk.

We create a door and window detection device here. The circuit with the reed switch is placed next to the door and window, and the magnet is mounted on the edge of the door and window.
When the door or window is closed, the Reed Switch will be turned on by the magnetic force and the corresponding pin value on the R3 board will change.
Blynk.cloud will receive this value so that you can see if your house's doors and windows are closed even when you're away from home. 

Now we will use an LED widget in Blynk to indicate if your windows and doors are closed (i.e. if the Reed Switch is on or off).


**Wiring**

.. image:: img/wiring_reed.jpg

* :ref:`cpn_uno`
* :ref:`cpn_breadboard`
* :ref:`cpn_esp8266`
* :ref:`cpn_reed`


**Dashboard**

#. Create a **Datastream** of type **Virtual Pin** in the **Datastream** page to get the value of Reed Switch. Set the DATA TYPE to **Integer** and MIN and MAX to **0** and **1**.

    .. image:: img/sp220609_162548.png

#. Drag and drop an **LED widget** on the **Wed Dashboard** page, at a value of 1, it will light up (with color), otherwise it will be white.

    .. image:: img/sp220609_163350.png

#. In the settings page of the **LED widget**, select **Datastream** as **Reed(V1)**, and save it.

    .. image:: img/sp220609_163502.png

**Code**

Open the ``3.push_data_to_blynk.ino`` file under the path of ``3in1-kit\iot_project\3.push_data_to_blynk``, or copy this code into **Arduino IDE**, for detailed tutorials, please refer to :ref:`ar_upload_code`.

.. note::
    Before using the sample code, be sure to replace the ``Template ID``, ``Device Name``, and ``Auth Token`` with your own. You also need to enter the ``ssid`` and ``password`` of the WiFi you are using.


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/e81b0024-c11e-4507-8d43-aeb3b6656c2c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



After uploading the code to the R3 board, wait for the serial monitor to show ``ready`` and the status of Blynk to change to online, at which point Blynk will show the status of your doors and windows.
If your doors and windows are closed, the LED widget will be green, otherwise, it will be gray.



**How it works?**


For this example, you should focus on the following lines. "Write data every second to Blynk Cloud's V1 Datastream" is defined by these lines.

.. code-block:: arduino

    BlynkTimer timer;

    void myTimerEvent()
    {
        Blynk.virtualWrite(V1, pinValue);
    }

    void setup()
    {
        timer.setInterval(1000L, myTimerEvent);
    }

    void loop()
    {
        timer.run(); // Initiates BlynkTimer
    }

Blynk library provides a built-in timer, first we create a timer object.

.. code-block:: arduino

    BlynkTimer timer;

Set the timer interval in ``setup()``, here we set to execute the ``myTimerEvent()`` function every 1000ms

.. code-block:: arduino

    timer.setInterval(1000L, myTimerEvent);


Run BlynkTimer in ``loop()``.

.. code-block:: arduino

    timer.run();

Edit the custom function ``myTimerEvent()``, the code ``Blynk.virtualWrite(V1, pinValue)`` is used to write the data pinValue for V1.

.. code-block:: arduino

    void myTimerEvent()
    {
        Blynk.virtualWrite(V1, pinValue);
    }

