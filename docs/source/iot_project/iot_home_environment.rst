.. _iot_home:


5. Home Environment Monitoring
================================

In this chapter, we will use Blynk to create a home environment monitor.
You can measure the temperature, humidity, and light intensity of a room using the DHT11 and photoresistor.
By sending these values to Blynk, you will be able to know the environment of your home via the internet.

**Wiring**

.. image:: img/wiring_dht11.jpg

* :ref:`cpn_uno`
* :ref:`cpn_breadboard`
* :ref:`cpn_esp8266`
* :ref:`cpn_photoresistor`
* :ref:`cpn_dht11`
* :ref:`cpn_resistor`

**Dashboard**


#. For recording humidity values, create a **Datastream** of type **Virtual Pin** on the **Datastream** page. Set the DATA TYPE to **Double** and MIN and MAX to **0** and **100**. Also set the units to **Percentage, %**.

    .. image:: img/sp220610_145748.png

#. Then create a **Datastream** of type **Virtual Pin** for recording the temperature. Set DATA TYPE to ``Double``, MIN and MAX to ``-30`` and ``50``, and units to **Celsius, °C**.

    .. image:: img/sp220610_145811.png

#. Also create a **Datastream** of type **Virtual Pin** to record the light intensity. Use the default data type - **Integer**, with MIN and MAX set to ``0`` and ``1024``.

    .. image:: img/sp220610_145834.png

#. Go to the **Wed Dashboard** page, drag two **Label** widgets and set their data streams to **V4** and **V5** respectively, and drag a **Gauge** widget and set the data stream to **V6**. Also in the widget setting, you can enable **Change color based on value** and select the appropriate color to make the widget look better and more intuitive.

.. image:: img/sp220610_150400.png


**Code**

Open the ``5.home_environment_monitoring.ino`` file under the path of ``3in1-kit\iot_project\5.home_environment_monitoring``, or copy this code into **Arduino IDE**, for detailed tutorials, please refer to :ref:`ar_upload_code`.

.. note::
    Before using the sample code, be sure to replace the ``Template ID``, ``Device Name``, and ``Auth Token`` with your own. You also need to enter the ``ssid`` and ``password`` of the WiFi you are using.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/4f0ad85e-8aff-4df9-99dd-c6741aed8219/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



After the code is successfully uploaded, you will see the current ambient temperature, humidity and light intensity on Blynk.

**How it works?**

These two functions are used to get the temperature, humidity and light intensity of the room.


.. code-block:: arduino

    int readLight(){
        return analogRead(lightPin);
    }

    bool readDHT() {
        Serial.print("DHT11, \t");
        int chk = DHT.read11(DHT11_PIN);
        switch (chk)
        {
            case DHTLIB_OK:
            Serial.print("OK,\t");
            roomHumidity = DHT.humidity;
            Serial.print(roomHumidity, 1);
            Serial.print(",\t");
            roomTemperature = DHT.temperature;
            Serial.println(roomTemperature, 1);
            //    delay(1000);
            return true;
            case DHTLIB_ERROR_CHECKSUM:
            Serial.println("Checksum error,\t");
            break;
            case DHTLIB_ERROR_TIMEOUT:
            Serial.println("Time out error,\t");
            //    delay(20);
            break;
            default:
            Serial.println("Unknown error,\t");
            break;
        }
        return false;
    }


With the Blynk ``Timer``, the ambient temperature, humidity, and light intensity are obtained every second and sent to the data stream on the Blynk Cloud, from which the widgets display the data.

.. code-block:: arduino

    void myTimerEvent()
    {
        bool chk = readDHT();
        int light = readLight();
        if(chk==true){
            Blynk.virtualWrite(V4,roomHumidity);
            Blynk.virtualWrite(V5,roomTemperature);
        }
        Blynk.virtualWrite(V6,light);
    }