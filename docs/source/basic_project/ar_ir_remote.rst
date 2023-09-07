.. _ar_receiver:

5.11.2 IR Receiver
=========================


In this project, you will learn to use IR Receiver. 

An infrared-receiver is a component which receives infrared signals and can independently receive infrared rays and output signals compatible with TTL level. 
It is similar with a normal plastic-packaged transistor in size and is suitable for all kinds of infrared remote control and infrared transmission.



**Schematic**

.. image:: img/circuit_7.2_receiver.png

**Wiring**



In this example, we wire up the left pin of IR Receiver to pin 11, 
the middle pin to GND, and the right pin to 5V.

.. image:: img/ir_remote_control_bb.jpg


* :ref:`cpn_uno`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_receiver`

**Code**

.. note::

    * Open the ``5.11.ir_receiver.ino`` file under the path of ``3in1-kit\basic_project\5.11.ir_receiver``.
    * Or copy this code into **Arduino IDE**.
    * The ``IRremote`` library is used here, you can install it from the **Library Manager**.
  
        .. image:: ../img/lib_irremote.png


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1141d808-cc26-4589-ae5c-d1834033ac3d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

After uploading the codes to the R3 board, you can see that the
current value of the pressed button of IR Remote Controller displays on
the serial monitor.

**How it works?**

This code is designed to work with an infrared (IR) remote control using the ``IRremote`` library. Here's the breakdown:

#. Include Libraries: This includes the ``IRremote`` library, which provides functions to work with IR remote controls.

    .. code-block:: arduino

        #include <IRremote.h>

#. Defines the Arduino pin to which the IR sensor's signal pin is connected and declares a variable to store the last decoded IR value.

    .. code-block:: arduino

        const int IR_RECEIVE_PIN = 11;  // Define the pin number for the IR Sensor
        String lastDecodedValue = "";  // Variable to store the last decoded value

#. Initializes serial communication at a baud rate of 9600. Initializes the IR receiver on the specified pin (``IR_RECEIVE_PIN``) and enables LED feedback (if applicable).

    .. code-block:: arduino

        void setup() {
            Serial.begin(9600);                                     // Start serial communication at 9600 baud rate
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver
        }

#. The loop runs continuously to process incoming IR remote signals.

    .. code-block:: arduino

        void loop() {
            if (IrReceiver.decode()) {
                String decodedValue = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (decodedValue != "ERROR" && decodedValue != lastDecodedValue) {
                    Serial.println(decodedValue);
                    lastDecodedValue = decodedValue;  // Update the last decoded value
                }
                IrReceiver.resume();  // Enable receiving of the next value
            }
        }
    
    * Checks if an IR signal is received and successfully decoded.
    * Decodes the IR command and stores it in ``decodedValue`` using a custom ``decodeKeyValue()`` function.
    * Checks if the decoded value is not an error and is different from the last decoded value.
    * Prints the decoded IR value to the serial monitor.
    * Updates the ``lastDecodedValue`` with the new decoded value.
    * Resumes IR signal reception for the next signal.