.. _iot_blink:

2. Get Data from Blynk
=================================

You will learn how to control the circuit with Blynk in this chapter. Let's light up the LEDs over the Internet!

**Wiring**

.. image:: img/wiring_led.jpg

* :ref:`cpn_uno`
* :ref:`cpn_breadboard`
* :ref:`cpn_esp8266`
* :ref:`cpn_resistor`
* :ref:`cpn_led`



**Dashboard**

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

**Code**

Open the ``2.get_data_from_blynk.ino`` file under the path of ``3in1-kit\iot_project\2.get_data_from_blynk``, or copy this code into **Arduino IDE**, for detailed tutorials, please refer to :ref:`ar_upload_code`.

.. note::
    Before using the sample code, be sure to replace the ``Template ID``, ``Device Name``, and ``Auth Token`` with your own. You also need to enter the ``ssid`` and ``password`` of the WiFi you are using.



.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/06b187a8-dabf-4866-b38c-742e0446cc3f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



After uploading the code to the R3 board, wait for the serial monitor shows ``ready`` and the status of Blynk changes to online, you can use the switch widget on Blynk to control the LED connected to the R3 board.


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


