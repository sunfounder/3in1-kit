.. _ar_dht11:


5.11.2 Temperature - Humidity
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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_dht11`
        - \-

**Schematic**

.. image:: img/circuit_7.3_dht11.png

**Wiring**

.. image:: img/5.11_dht11_bb.png

**Code**

.. note::

    * Open the ``5.11.temperature_humidity.ino`` file under the path of ``3in1-kit\learning_project\5.11.temperature_humidity``.
    * Or copy this code into **Arduino IDE**.
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c5b4c902-f39d-45a6-9a17-1308056041a8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After the code is uploaded successfully, you will see the Serial Monitor continuously print out the temperature and humidity, and as the program runs steadily, these two values will become more and more accurate.

**How it works?**

The function of the module is included in the library ``dht.h``.

.. code-block:: arduino

    #include <dht.h> 

Library Functions:

.. code-block:: arduino
    
    dht

Creates a new instance of the ``dht`` class.

.. code-block:: arduino

    int read11(uint8_t pin)

This function will return CHECK values.

* ``DHTLIB_OK`` means that DHT-11 is in good condition;
* ``DHTLIB_ERROR_CHECKSUM`` represents that the value may be abnormal;
* ``DHTLIB_ERROR_TIMEOUT`` indicates that there is timeout.

The function will store the detected humidity and temperature into the
variables with the same name in ``dht`` class.

The variables can be called and used directly in the main program.
(e.g. ``Serial.println(DHT.temperature,1);`` )