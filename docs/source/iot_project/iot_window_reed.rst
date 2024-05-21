.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _iot_window:

3. Push Data to Blynk
=============================

This chapter will show you how to send data to Blynk.

We create a door and window detection device here. The circuit with the reed switch is placed next to the door and window, and the magnet is mounted on the edge of the door and window.
When the door or window is closed, the Reed Switch will be turned on by the magnetic force and the corresponding pin value on the R4 board will change.
Blynk.cloud will receive this value so that you can see if your house's doors and windows are closed even when you're away from home. 

Now we will use an LED widget in Blynk to indicate if your windows and doors are closed (i.e. if the Reed Switch is on or off).

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
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_reed`
        - \-

**1. Build the Cirduit**

.. note::

    The ESP8266 module requires a high current to provide a stable operating environment, so make sure the 9V battery is plugged in.

.. image:: img/iot_3_bb.png

**2. Edit Dashboard**

#. Create a **Datastream** of type **Virtual Pin** in the **Datastream** page to get the value of Reed Switch. Set the DATA TYPE to **Integer** and MIN and MAX to **0** and **1**.

    .. image:: img/sp220609_162548.png

#. Drag and drop an **LED widget** on the **Wed Dashboard** page, at a value of 1, it will light up (with color), otherwise it will be white.

    .. image:: img/sp220609_163350.png

#. In the settings page of the **LED widget**, select **Datastream** as **Reed(V1)**, and save it.

    .. image:: img/sp220609_163502.png

**3. Run the Code**

#. Open the ``3.push_data_to_blynk.ino`` file under the path of ``3in1-kit\iot_project\3.push_data_to_blynk``, or copy this code into **Arduino IDE**.


    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/e81b0024-c11e-4507-8d43-aeb3b6656c2c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Replace the ``Template ID``, ``Device Name``, and ``Auth Token`` with your own. You also need to enter the ``ssid`` and ``password`` of the WiFi you are using. For detailed tutorials, please refer to :ref:`connect_blynk`.
#. After selecting the correct board and port, click the **Upoad** button.

#. Open the Serial monitor(set baudrate to 115200) and wait for a prompt such as a successful connection to appear.

    .. image:: img/2_ready.png

    .. note::

        If the message ``ESP is not responding`` appears when you connect, please follow these steps.

        * Make sure the 9V battery is plugged in.
        * Reset the ESP8266 module by connecting the pin RST to GND for 1 second, then unplug it.
        * Press the reset button on the R4 board.

        Sometimes, you may need to repeat the above operation 3-5 times, please be patient.

#. Now, Blynk will show the status of your doors and windows. If your doors and windows are closed, the LED widget will be green, otherwise, it will be gray.

#. If you want to use Blynk on mobile devices, please refer to :ref:`blynk_mobile`.



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

