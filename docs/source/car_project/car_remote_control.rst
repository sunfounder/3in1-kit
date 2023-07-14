.. _car_remote:

9. Remote Control
=================================


This kit comes with an IR receiver, which allows you to use an IR remote control to control the movement of the car.

**Wiring**

Now build the circuit according to the diagram below.

.. list-table:: 
    :header-rows: 1

    * - IR Receiver
      - R4 Board
    * - OUT
      - 12
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - LED
      - R4 Board
    * - Anode(The longer pin)
      - 13
    * - Cathode
      - GND

.. image:: img/car_remote.jpg
    :width: 800

* :ref:`cpn_uno`
* :ref:`cpn_l298n` 
* :ref:`cpn_tt_motor`
* :ref:`cpn_led`
* :ref:`cpn_receiver`

**Code**

.. note::

    * Open the ``9.remote_control.ino`` file under the path of ``3in1-kit\car_project\9.remote_control``.
    * Or copy this code into **Arduino IDE**.
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/7c78450d-fcd2-4288-a00d-499c71ad2d52/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


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

#. Import the library ``IRremote``, here you will need to refer to :ref:`add_libraries_ar` to add this library.


    .. code-block:: arduino

        #include <IRremote.h>
        const int recvPin = 12;
        IRrecv irrecv(recvPin);
        decode_results results;
    
    * ``IRrecv irrecv(recvPin)``: Create an instance of the ``IRrecv`` class, specifying the pins it's attached to.
    * ``decode_results results``: Create an instance of the ``decode_results`` class, which is the result returned by the decoder.

#. Initialize the IR receiver and the LED.

    .. code-block:: arduino

        ...
        const int ledPin = 13;
        ...

        void setup() {

            ...
            //UR remote
            irrecv.enableIRIn(); // Start the receiver
            Serial.println("REMOTE CONTROL START");

            //LED
            pinMode(ledPin, OUTPUT);
        }


#. When you press the keys on the remote control, the LED will blink and the infrared receiver will know which key is pressed, and then the car will move according to the corresponding key value.


    .. code-block:: arduino

        void loop() {

            if (irrecv.decode(&results)) {
                //    Serial.println(results.value,HEX);
                String key = decodeKeyValue(results.value);
                if ( key != "ERROR")
                {
                    Serial.println(key);
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
                irrecv.resume(); // Receive the next value
            }
        }

    * ``irrecv.decode(&results)``: Decodes the received IR message. Returns 0 if no data ready, 1 if data ready. Results of decoding are stored in ``results``.
    * ``decodeKeyValue(results.value)``: ``results.value`` is the decoded value, usually in 8-bit hexadecimal, and ``decodeKeyValue()`` is to convert these values to the key names on the remote control.
    * ``irrecv.resume()``: Restart for receiving an other value.

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

