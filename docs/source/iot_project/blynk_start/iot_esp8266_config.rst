.. _config_esp8266:

1.0 Konfiguration des ESP8266
===============================

Das ESP8266-Modul, das im Kit enthalten ist, ist bereits mit der AT-Firmware vorgebrannt. Sie müssen jedoch seine Konfiguration ändern, indem Sie den untenstehenden Schritten folgen.


1. Bauen Sie den Schaltkreis.

    .. image:: img/iot_1_at_set_bb.jpg
        :width: 800

2. Öffnen Sie die Datei ``1.set_software_serial.ino`` im Pfad ``3in1-kit\iot_project\1.set_software_serial``. Oder kopieren Sie diesen Code in die **Arduino IDE**.

    .. code-block:: Arduino

        #include <SoftwareSerial.h>
        SoftwareSerial espSerial(2, 3); //Rx,Tx

        void setup() {
            // Setzen Sie hier Ihren Setup-Code ein, der einmal ausgeführt wird:
            Serial.begin(115200);
            espSerial.begin(115200);
        }

        void loop() {
            if (espSerial.available()) {
                Serial.write(espSerial.read());
            }
            if (Serial.available()) {
                espSerial.write(Serial.read());
            }
        }

3. Klicken Sie auf das Lupen-Symbol (Serial Monitor) in der oberen rechten Ecke und setzen Sie die Baudrate auf **115200**. (Es kann sein, dass Sie einige Informationen wie ich erhalten, oder auch nicht. Das spielt keine Rolle, gehen Sie einfach zum nächsten Schritt weiter.)

    .. image:: img/sp20220524113020.png

    .. warning::
        
        * Wenn ``ready`` nicht erscheint, können Sie versuchen, das ESP8266-Modul zurückzusetzen (RST mit GND verbinden) und den Serial Monitor erneut zu öffnen.

        * Zudem, wenn das Ergebnis ``OK`` lautet, müssen Sie möglicherweise die Firmware erneut brennen. Bitte schauen Sie unter :ref:`burn_firmware` nach Details. Wenn Sie das Problem immer noch nicht lösen können, machen Sie bitte einen Screenshot vom Serial Monitor und senden Sie ihn an sevice@sunfounder.com. Wir werden Ihnen so schnell wie möglich helfen.

4. Klicken Sie auf **NEWLINE DROPDOWN BOX**, wählen Sie im Dropdown-Menü ``both NL & CR`` aus und geben Sie ``AT`` ein. Wenn OK zurückgegeben wird, bedeutet dies, dass der ESP8266 erfolgreich eine Verbindung zum R3-Board hergestellt hat.

    .. image:: img/sp20220524113702.png

5. Geben Sie ``AT+CWMODE=3`` ein und der verwaltete Modus wird auf **Station und AP** Koexistenz geändert.

    .. image:: img/sp20220524114032.png

6. Um später die Software-Seriennummer verwenden zu können, müssen Sie ``AT+UART=9600,8,1,0,0`` eingeben, um die Baudrate des ESP8266 auf 9600 zu ändern.

    .. image:: img/PIC4_sp220615_150321.png

.. 7. Ändern Sie nun die Baudrate des Serial Monitors auf 9600 und versuchen Sie, ``AT`` einzugeben. Wenn OK zurückgegeben wird, bedeutet dies, dass die Einstellung erfolgreich war.

..     .. image:: img/PIC5_sp220615_150431.png

