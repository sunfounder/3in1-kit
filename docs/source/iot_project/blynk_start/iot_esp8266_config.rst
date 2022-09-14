1.1 Configuring the ESP8266
===============================

The ESP8266 module that comes with the kit is already pre-burned with AT firmware, but you still need to modify its configuration by following the steps below.

1. Plug the R3 board directly into your computer with USB cable, then copy the following code to the Arduino IDE and :ref:`ar_upload_code` to the R3 board.

    .. code-block:: arduino

        const int tx = 1;
        const int rx = 0;
        void setup() {
            pinMode(rx,INPUT_PULLUP);
            pinMode(tx,INPUT_PULLUP); 
        }

        void loop() {
        }

2. Build the circuit.

    .. note::

        The ESP8266 module requires a high current to provide a stable operating environment, so make sure the 9V battery is plugged in.


    .. image:: img/wiring_01.jpg

3. You will be able to see information about the ESP8266 module if you click the magnifying glass icon(Serial Monitor) in the upper right corner and set the baud rate to **115200**.

    .. image:: img/sp20220524113020.png

    .. note::

        If "ready" doesn't appear, you can try to reset the ESP8266 module by connecting the RST pin on the ESP8266 adapter board to GND and unplugging it after about 1 second.

4. Click on **NEWLINE DROPDOWN BOX**, select ``both NL & CR`` in the drop down option, enter ``AT``, if it returns OK, it means ESP8266 has successfully established connection with R3 board.

    .. image:: img/sp20220524113702.png

    .. warning::
        If you enter AT and it does not return OK, but you have reset the ESP8266 module, please take a screenshot of the serial monitor and send it to sevice@sunfounder.com, we will help you solve the problem as soon as possible.

5. Enter ``AT+CWMODE=3`` and the managed mode will be changed to **Station and AP** coexistence.

    .. image:: img/sp20220524114032.png

6. In order to use the software serial later, you must input **AT+UART=9600,8,1,0,0** to modify the ESP8266's baud rate to 9600.

    .. image:: img/PIC4_sp220615_150321.png

7. Now change the serial monitor baud rate to 9600, try to enter ``AT``, if it returns OK, it means the setting is successful.


    .. image:: img/PIC5_sp220615_150431.png

