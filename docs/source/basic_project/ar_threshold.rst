.. _ar_threshold:

5.2 Threshold
=======================

In many projects, you will encounter such a need.
"When xxx reaches a certain level, then..."

For example, in a smart home, when the light intensity is lower than 50Lux, turn on the light;
Another example is in the computer motherboard, if the operating temperature of the CPU is higher than 65 degrees Celsius, turn on the fan, and so on.

In these requirements, the keyword "threshold" is reflected.

We can adjust the value of the threshold to make the circuit operate more in line with individual needs.
For example, if I like a brighter living environment, I can increase the threshold of the automatic lights of the smart home to 80Lux.
Another example is that the ventilation environment of my studio is not very good, and the heat dissipation demand is higher, then the threshold value of automatic fan opening can be adjusted to 50 degrees Celsius.


Here we use soil moisture sensor and 2 LEDs to make a pot monitor. If the soil is too dry, the red LED will light up; if the soil is moist enough, the green LED will light up. You need to manually adjust the thresholds for determining the dryness and wetness of the soil.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schematic**

.. image:: img/circuit_8.2_threshold.png

**Wiring**

.. image:: img/threshold_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Open the ``5.2.threshold.ino`` file under the path of ``3in1-kit\basic_project\5.2.threshold``.
    * Or copy this code into **Arduino IDE**.
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/9936413a-6e6c-4e57-b0c6-5df58dd48a3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
After the code is uploaded successfully, if your threshold is set correctly, you will see the red LED light up when the soil is dry to remind you that you need to water; after watering, the green LED will light up.

**How it works**

.. code-block:: Arduino

    ...

    void loop() {
        int sensorValue = analogRead(soilMoisture);
        Serial.println(sensorValue);
        if (sensorValue > threshold) {
            digitalWrite(redPin, HIGH); // Turn the red LED
            digitalWrite(greenPin, LOW); // green
        } else {
            digitalWrite(greenPin, HIGH); // Turn on the green LED
            digitalWrite(redPin, LOW); // red
        }
    }
    ...

First set a ``threshold`` value and then read the value of the soil moisture module, its value decreases as the moisture level increases. If the value currently read is greater than the set ``threshold``, then let the red LED light up, otherwise it will turn on the green LED.

This ``threshold`` value needs to be adjusted according to the actual situation, you can upload the code first, then open the serial monitor to check the value, record the value in both wet and dry conditions, and then choose a middle value as the ``threshold`` value.


