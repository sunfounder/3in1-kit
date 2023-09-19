.. _car_remote:

9. Remote Control
=================================

This kit comes with an IR receiver, which allows you to use an IR remote control to control the movement of the car.

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
    *   - :ref:`cpn_l298n`
        - |link_l298n_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_receiver`
        - \-

**Wiring**

Now build the circuit according to the diagram below.

.. list-table:: 
    :header-rows: 1

    * - IR Receiver
      - R3 Board
    * - OUT
      - 12
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - LED
      - R3 Board
    * - Anode(The longer pin)
      - 13
    * - Cathode
      - GND

.. image:: img/car_remote.jpg
    :width: 800

**Code**

.. note::

    * Open the ``9.remote_control.ino`` file under the path of ``3in1-kit\car_project\9.remote_control``.
    * Or copy this code into **Arduino IDE**.
    * The ``IRremote`` library is used here, you can install it from the **Library Manager**.
  
        .. image:: ../img/lib_irremote.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/b5d87f03-c8e9-49de-a6d1-3b51036e1f5c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


After the code is uploaded successfully, press the button on the remote control, the LED will blink once to represent that the signal has been received, and the car will move according to the button you pressed. You can press the following keys to control the car.

* **+**: Accelerate
* **-**: Decelerate
* **1**: Forward to the left
* **2**: Forward
* **3**: Forward to the right
* **4**: Turn left
* **6**: Turn right
* **7**: Backward to the left
* **8**: Backward
* **9**: Backward to the right


**How it works?**

The effect of this project is to make the car move by reading the key value of the IR remote control. In addition, an LED is added to indicate that the IR signal has been successfully received.

#. Import the ``IRremote`` library, you can install it from the **Library Manager**.


    .. code-block:: arduino

        #include <IRremote.h>

        const int IR_RECEIVE_PIN = 12;  // Define the pin number for the IR Sensor
        String lastDecodedValue = "";   // Variable to store the last decoded value

#. Initialize the IR receiver and the LED.

    .. code-block:: arduino

        ...
        const int ledPin = 13;
        ...

        void setup() {

            ...
            //IR remote
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver // Start the receiver
            Serial.println("REMOTE CONTROL START");


            //LED
            pinMode(ledPin, OUTPUT);
        }


#. When you press the keys on the remote control, the LED will blink and the infrared receiver will know which key is pressed, and then the car will move according to the corresponding key value.


    .. code-block:: arduino

        void loop() {

            if (IrReceiver.decode()) {
                //    Serial.println(results.value,HEX);
                String key = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (key != "ERROR" && key != lastDecodedValue) {
                    Serial.println(key);
                    lastDecodedValue = key;  // Update the last decoded value
                    blinkLED();

                    if (key == "+") {
                        speed += 50;
                    } else if (key == "-") {
                        speed -= 50;
                    } else if (key == "2") {
                        moveForward(speed);
                        delay(1000);
                    ...
                    }
                    IrReceiver.resume();  // Enable receiving of the next value

            }
        }

    * Checks if an IR signal is received and successfully decoded.
    * Decodes the IR command and stores it in ``key`` using a custom ``decodeKeyValue()`` function.
    * Checks if the decoded value is not an error and is different from the last decoded value.
    * Prints the decoded IR value to the serial monitor.
    * Updates the ``lastDecodedValue`` with the new decoded value.
    * Resumes IR signal reception for the next signal.

#. About the ``blinkLED()`` function.
    
    When this function is called, have the LED repeat the toggle from on-off three times so that you see the LED blink 3 times.

    .. code-block:: arduino

        void blinkLED() {
                for (int i = 0; i < 3; i++) {
                digitalWrite(ledPin, HIGH);
                delay(50);
                digitalWrite(ledPin, LOW);
                delay(50);
            }
        }

