.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_receiver:

5.11.2 IR Receiver
=========================

In this project, you will learn to use IR Receiver. 

An infrared-receiver is a component which receives infrared signals and can independently receive infrared rays and output signals compatible with TTL level. 
It is similar with a normal plastic-packaged transistor in size and is suitable for all kinds of infrared remote control and infrared transmission.

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
    *   - :ref:`cpn_receiver`
        - \-

**Schematic**

.. image:: img/circuit_7.2_receiver.png

**Wiring**

In this example, we wire up the left pin of IR Receiver to pin 11, 
the middle pin to GND, and the right pin to 5V.

.. image:: img/5.11_ir_recv_bb.png

**Code**

.. note::

    * Open the ``5.11.ir_receiver.ino`` file under the path of ``3in1-kit\learning_project\5.11.ir_receiver``.
    * Or copy this code into **Arduino IDE**.
    * The ``IRremote`` library is used here, you can install it from the **Library Manager**.
  
        .. image:: ../img/lib_irremote.png



.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1141d808-cc26-4589-ae5c-d1834033ac3d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

After uploading the codes to the R4 board, you can see that the
current value of the pressed button of IR Remote Controller displays on
the serial monitor.

**How it works?**

This code is designed to work with an infrared (IR) remote control using the ``IRremote`` library. Here's the breakdown:

#. Include Libraries: This includes the ``IRremote`` library, which provides functions to work with IR remote controls.

    .. code-block:: arduino

        #include <IRremote.h>

#. Defines the Arduino pin to which the IR sensor's signal pin is connected.

    .. code-block:: arduino

        const int IR_RECEIVE_PIN = 11;  // Define the pin number for the IR Sensor


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
                if (decodedValue != "ERROR") {
                    Serial.println(decodedValue);
                    delay(100);
                }
                IrReceiver.resume();  // Enable receiving of the next value
            }
        }
    
    * Checks if an IR signal is received and successfully decoded.
    * Decodes the IR command and stores it in ``decodedValue`` using a custom ``decodeKeyValue()`` function.
    * Checks if the decoded value is not an error.
    * Prints the decoded IR value to the serial monitor.
    * Resumes IR signal reception for the next signal.