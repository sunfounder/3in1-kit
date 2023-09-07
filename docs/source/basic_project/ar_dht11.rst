.. _ar_dht11:


5.11.3 Temperature - Humidity
=======================================

Humidity and temperature are closely related from the physical quantity itself to the actual people's life.
The temperature and humidity of human environment will directly affect the thermoregulatory function and heat transfer effect of human body.
It will further affect the thinking activity and mental state, thus affecting the efficiency of our study and work.

Temperature is one of the seven basic physical quantities in the International System of Units, which is used to measure the degree of hot and cold of an object.
Celsius is one of the more widely used temperature scales in the world, expressed by the symbol "℃".

Humidity is the concentration of water vapor present in the air.
The relative humidity of air is commonly used in life and is expressed in %RH. Relative humidity is closely related to temperature.
For a certain volume of sealed gas, the higher the temperature, the lower the relative humidity, and the lower the temperature, the higher the relative humidity.

.. image:: img/Dht11.png

The dht11, a digital temperature and humidity sensor, is provided in this kit. It uses a capacitive humidity sensor and thermistor to measure the surrounding air and outputs a digital signal on the data pin.



**Schematic**

.. image:: img/circuit_7.3_dht11.png

**Wiring**

.. image:: img/dht11_bb.jpg


* :ref:`cpn_uno`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_dht11`

**Code**

.. note::

    * Open the ``5.11.temperature_humidity.ino`` file under the path of ``3in1-kit\basic_project\5.11.temperature_humidity``.
    * Or copy this code into **Arduino IDE**.
    * The ``DHT sensor library`` is used here, you can install it from the **Library Manager**.

        .. image:: ../img/lib_dht11.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c5b4c902-f39d-45a6-9a17-1308056041a8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After the code is uploaded successfully, you will see the Serial Monitor continuously print out the temperature and humidity, and as the program runs steadily, these two values will become more and more accurate.

**How it works?**

#.  Includes the ``DHT.h`` library, which provides functions to interact with the DHT sensors. Then, set the pin and type for the DHT sensor.

    .. code-block:: arduino

        #include "DHT.h"

        #define DHTPIN 11  // Set the pin connected to the DHT11 data pin
        #define DHTTYPE DHT11 // DHT 11 

        DHT dht(DHTPIN, DHTTYPE);

#. Initializes serial communication at a baud rate of 115200 and initializes the DHT sensor.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            Serial.println("DHT11 test!");
            dht.begin();
        }

#. In the ``loop()`` function, read temperature and humidity values from the DHT11 sensor, and print them to the serial monitor.

    .. code-block:: arduino

        void loop() {
            // Wait a few seconds between measurements.
            delay(2000);

            // Reading temperature or humidity takes about 250 milliseconds!
            // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
            float humidity = dht.readHumidity();
            // Read temperature as Celsius (the default)
            float temperture = dht.readTemperature();

            // Check if any reads failed and exit early (to try again).
            if (isnan(humidity) || isnan(temperture)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
            // Print the humidity and temperature
            Serial.print("Humidity: "); 
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("Temperature: "); 
            Serial.print(temperture);
            Serial.println(" *C");
        }

    * The ``dht.readHumidity()`` function is called to read the humidity value from the DHT sensor.
    * The ``dht.readTemperature()`` function is called to read the temperature value from the DHT sensor.
    * The ``isnan()`` function is used to check if the readings are valid. If either the humidity or temperature value is NaN (not a number), it indicates a failed reading from the sensor, and an error message is printed.
