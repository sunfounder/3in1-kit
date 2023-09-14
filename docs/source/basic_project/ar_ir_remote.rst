.. _ar_receiver:

5.11.3 IR Receiver
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
    


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1141d808-cc26-4589-ae5c-d1834033ac3d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

After uploading the codes to the R3 board, you can see that the
current value of the pressed button of IR Remote Controller displays on
the serial monitor.

**How it works?**

There are two important parts to notice in this program.

#. The code uses an extra file ``decodeKeyValue.ino`` to decode the values in
class ``decode_result`` into key name. The file will be opened together with
the main file.

#. Import the library ``IRremote``, here you will need to refer to :ref:`add_libraries_ar` to add this library.

    .. code-block:: arduino

        const int recvPin = 11;

        IRrecv irrecv(recvPin);
        decode_results results;

    * ``IRrecv irrecv(recvPin)``: Create an instance of the ``IRrecv`` class, specifying the pins it's attached to.
    * ``decode_results results``: Create an instance of the ``decode_results`` class, which is the result returned by the decoder.

#. Initialize the IR receiver and set the baudrate of the Serial Monitor to 9600bps.

    .. code-block:: arduino

        void setup()
        {
            Serial.begin(9600);
            irrecv.enableIRIn(); // Start the receiver
        }
#. When you press a key on the remote control, the serial monitor will print the key name if it is received by the IR receiver.


    .. code-block:: arduino

        void loop() {
            if (irrecv.decode(&results)) {
                //Serial.println(results.value,HEX);
                if (decodeKeyValue(results.value)!="ERROR")
                {
                    Serial.println(decodeKeyValue(results.value));
                }
                irrecv.resume(); // Receive the next value
            }
        }

    * ``irrecv.decode(&results)``: Decodes the received IR message. Returns 0 if no data ready, 1 if data ready. Results of decoding are stored in ``results``.
    * ``decodeKeyValue(results.value)``: ``results.value`` is the decoded value, usually in 8-bit hexadecimal, and ``decodeKeyValue()`` is to convert these values to the key names on the remote control.
    * ``irrecv.resume()``: Restart for receiving an other value.