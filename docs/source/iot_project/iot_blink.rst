.. _iot_blink:

2. Get Data from Blynk
=================================

You will learn how to control the circuit with Blynk in this chapter. Let's light up the LEDs over the Internet!

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
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

**1. Build the Cirduit**

.. note::

    The ESP8266 module requires a high current to provide a stable operating environment, so make sure the 9V battery is plugged in.

.. image:: img/wiring_led.jpg

**2. Edit Dashboard**

#. Go to the **Quickstart Device** you created earlier, click on the menu icon in the upper right corner and select **edit dashboard**.

    .. image:: img/sp220609_112825.png

#. Datastreams allow the widgets on Blynk and the code on the R3 board to recognize each other. To experience the complete configuration process, remove all Datastreams from the Datastreams page.

    .. image:: img/sp220609_114723.png

#. Please read the warning carefully and confirm it is correct before deleting the Datastreams.

    .. image:: img/sp220609_114929.png

#. Create a Datastream of type **Virtual Pin**, which will be used to control the LED using Blynk's switch.

    .. image:: img/sp220609_115124.png

#. Configure the **Virtual Pin**. As the button and LED only need to be ON and OFF, set DATA TYPE to ``Integer`` and MIN and MAX to ``0`` and ``1``. 

    .. image:: img/sp220609_115520.png

#. Go to the **Web Dashboard** page and delete the existing widgets.

    .. image:: img/sp220609_133707.png

#. Drag and drop a **switch** widget from the **Widget Box** on the left.

    .. image:: img/sp220609_114508.png

#. Now to set it up.

    .. image:: img/sp20220615180127.png

#. Select **Datastream** as the one you set earlier.

    .. image:: img/sp220609_133741.png

#. After selecting Datastream, you will see a few custom settings, then press Save.

    .. image:: img/sp220609_133950.png

#. Finally, click **Save And Apply**.

    .. image:: img/sp220609_141733.png

**3. Run the Code**

#. Open the ``2.get_data_from_blynk.ino`` file under the path of ``3in1-kit\iot_project\2.get_data_from_blynk``, or copy this code into **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b187a8-dabf-4866-b38c-742e0446cc3f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Replace the ``Template ID``, ``Device Name``, and ``Auth Token`` with your own. You also need to enter the ``ssid`` and ``password`` of the WiFi you are using. For detailed tutorials, please refer to :ref:`connect_blynk`.

#. After selecting the correct board and port, click the **Upoad** button.

    .. image:: img/2_upload.png

#. Open the Serial monitor(set baudrate to 115200) and wait for a prompt such as a successful connection to appear.

    .. image:: img/2_ready.png

    .. note::

        If the message ``ESP is not responding`` appears when you connect, please follow these steps.

        * Make sure the 9V battery is plugged in.
        * Reset the ESP8266 module by connecting the pin RST to GND for 1 second, then unplug it.
        * Press the reset button on the R3 board.

        Sometimes, you may need to repeat the above operation 3-5 times, please be patient.

#. Back at Blynk, you can see that the status has changed to online and you can now use the switch widget on blynk to control the LED connected to the R3 board.

    .. image:: img/2_blynk_button.png

#. If you want to use Blynk on mobile devices, please refer to :ref:`blynk_mobile`.


**How it works?**


The difference between the code in this project and the code in the previous chapter :ref:`connect_blynk` is the following lines.


.. code-block:: arduino

    const int ledPin=6;

    BLYNK_WRITE(V0)
    {
        int pinValue = param.asInt(); // assigning incoming value from pin V0 to a variable
        // You can also use:
        // String i = param.asStr();
        // double d = param.asDouble();
        digitalWrite(ledPin,pinValue);
    }

    void setup()
    {
        pinMode(ledPin,OUTPUT);
    }


Regarding the ``pinMode`` and ``digitalWrite`` of the ledPin, I'm sure you're already familiar with them, so I won't go over them again. What you need to focus on is the ``BLYNK_WRITE(V0)`` function.

What it will do is that when the value of Blynk's ``V0`` changes, Blynk.Cloud will tell your device "I am writing to **Virtual Pin** V0", and your device will be able to perform something once it gets this information.

We created the V0 Datastream in the previous step and applied it to the Switch Widget.
This means that every time we operate the Switch Widget, ``BLYNK_WRITE(V0)`` will be triggered.

We write two instructions in this function.

.. code-block:: arduino

    int pinValue = param.asInt();

Get the value of V0 and assign it to the variable ``pinValue``.

.. code-block:: arduino

    digitalWrite(ledPin,pinValue);

Write the value of V0 obtained to the ledPin, so that the Switch widget on Blynk can control the LED.


