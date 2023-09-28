.. _config_esp8266:

1.1 Konfiguration des ESP8266
===============================

Das ESP8266-Modul, das mit dem Kit geliefert wird, ist bereits mit der AT-Firmware vorgebrannt. Dennoch müssen Sie dessen Konfiguration ändern, indem Sie die untenstehenden Schritte befolgen.

1. Bauen Sie den Schaltkreis.

    .. image:: img/iot_1.1_at_set_bb.png
        :width: 800

2. Öffnen Sie die Datei ``1.set_software_serial.ino`` unter dem Pfad ``3in1-kit\iot_project\1.set_software_serial``. Oder kopieren Sie diesen Code in die **Arduino IDE**.

    .. code-block:: Arduino

        #include <SoftwareSerial.h>
        SoftwareSerial espSerial(2, 3); //Rx,Tx

        void setup() {
            // put your setup code here, to run once:
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

3. Klicken Sie auf das Lupensymbol (Serial Monitor) in der oberen rechten Ecke und setzen Sie die Baudrate auf **115200**. (Es kann sein, dass bei Ihnen Informationen angezeigt werden, wie bei mir, oder auch nicht. Das spielt keine Rolle, gehen Sie einfach zum nächsten Schritt weiter.)

    .. image:: img/sp20220524113020.png

    .. warning::

        * Wenn ``ready`` nicht erscheint, können Sie versuchen, das ESP8266-Modul zurückzusetzen (RST mit GND verbinden) und den Serial Monitor erneut zu öffnen.

        * Zudem, wenn das Ergebnis ``OK`` ist, müssen Sie möglicherweise die Firmware erneut brennen. Bitte beziehen Sie sich für Details auf :ref:`burn_firmware`. Wenn Sie das Problem immer noch nicht lösen können, nehmen Sie bitte einen Screenshot vom Serial Monitor und senden Sie diesen an sevice@sunfounder.com. Wir werden Ihnen so schnell wie möglich helfen.

4. Klicken Sie auf das **NEWLINE DROPDOWN BOX** und wählen Sie im Dropdown-Menü ``both NL & CR`` aus. Geben Sie ``AT`` ein. Wenn OK zurückgegeben wird, bedeutet das, dass ESP8266 erfolgreich eine Verbindung mit Ihrem Board hergestellt hat.

    .. image:: img/sp20220524113702.png

5. Geben Sie ``AT+CWMODE=3`` ein und der verwaltete Modus wird zu **Station and AP**-Koexistenz geändert.

    .. image:: img/sp20220524114032.png

6. Um später die Software-Serial verwenden zu können, müssen Sie ``AT+UART=9600,8,1,0,0`` eingeben, um die Baudrate des ESP8266 auf 9600 zu ändern.

    .. image:: img/PIC4_sp220615_150321.png

.. 7. Ändern Sie jetzt die Baudrate des Serial Monitors auf 9600, versuchen Sie ``AT`` einzugeben. Wenn OK zurückgegeben wird, bedeutet das, dass die Einstellung erfolgreich war.

..     .. image:: img/PIC5_sp220615_150431.png
