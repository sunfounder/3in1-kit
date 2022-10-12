.. _config_esp8266:

1.1 Configuring the ESP8266
===============================

The ESP8266 module that comes with the kit is already pre-burned with AT firmware, but you still need to modify its configuration by following the steps below.


1. Build the circuit.

    .. image:: img/connect_esp826612.png
        :width: 800

2. You will be able to see information about the ESP8266 module if you click the magnifying glass icon(Serial Monitor) in the upper right corner and set the baud rate to **115200**.

    .. image:: img/sp20220524113020.png

    .. warning::
        
        * If ``ready`` doesn't appear, you can try to reset the ESP8266 module(connect RST to GND) and re-open the Serial Monitor.

        * In addition, if the result is OK, you may need to re-burn the firmware, please refer to :ref:`burn_firmware` for details. If you still can't solve it, please take a screenshot of the serial monitor and send it to sevice@sunfounder.com, we will help you solve the problem as soon as possible.

3. Click on **NEWLINE DROPDOWN BOX**, select ``both NL & CR`` in the drop down option, enter ``AT``, if it returns OK, it means ESP8266 has successfully established connection with R3 board.

    .. image:: img/sp20220524113702.png

4. Enter ``AT+CWMODE=3`` and the managed mode will be changed to **Station and AP** coexistence.

    .. image:: img/sp20220524114032.png

5. In order to use the software serial later, you must input **AT+UART=9600,8,1,0,0** to modify the ESP8266's baud rate to 9600.

    .. image:: img/PIC4_sp220615_150321.png

6. Now change the serial monitor baud rate to 9600, try to enter ``AT``, if it returns OK, it means the setting is successful.


    .. image:: img/PIC5_sp220615_150431.png

