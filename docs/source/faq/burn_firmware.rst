.. _burn_firmware:

Wie lädt man die Firmware für das ESP8266-Modul erneut hoch?
==============================================================

Firmware mit R4 erneut hochladen
----------------------------------------

**1. Schaltkreis aufbauen**

Verbinden Sie ESP8266 und das Arduino UNO R4 Board.

    .. image:: img/faq_at_burn_bb.jpg
        :width: 800

**2. Folgenden Code auf R4 hochladen**

.. code-block:: Arduino

    void setup() {
        Serial.begin(115200);
        Serial1.begin(115200);
    }

    void loop() {
        if (Serial.available()) {      // If anything comes in Serial (USB),
            Serial1.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
        }
            if (Serial1.available()) {     // If anything comes in Serial1 (pins 0 & 1)
            Serial.write(Serial1.read());   // read it and send it out Serial (USB)
        }
    }

**3. Firmware hochladen**

* Folgen Sie den untenstehenden Schritten zum Hochladen der Firmware, wenn Sie **Windows** verwenden.

    #. Firmware und Brenntool herunterladen.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Nach dem Entpacken sehen Sie 4 Dateien.

        .. .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: Die Firmware, die auf das ESP8266-Modul gebrannt wird.
        * ``esptool.exe``: Ein Befehlszeilen-Utility für Windows.
        * ``install_r3.bat``: Dies ist das Befehlspaket für das Windows-System.
        * ``install_r4.bat``: Ähnlich wie ``install_r3.bat``, aber speziell für das UNO R4 Board.

    #. Doppelklicken Sie auf ``install_r4.bat``, um das Brennen der Firmware zu starten. Wenn Sie die folgende Aufforderung sehen, wurde die Firmware erfolgreich installiert.

        .. image:: img/install_firmware.png

        .. note::
            Wenn das Brennen fehlschlägt, überprüfen Sie bitte die folgenden Punkte.

            * Setzen Sie das ESP8266-Modul zurück, indem Sie den RST am ESP8266-Adapter an GND anschließen und dann entfernen.
            * Überprüfen Sie, ob die Verdrahtung korrekt ist.
            * Stellen Sie sicher, dass Ihr Computer Ihr Board erkannt hat und der Port nicht belegt ist.
            * Öffnen Sie die install.bat-Datei erneut.

* Zum Brennen der Firmware befolgen Sie diese Schritte, wenn Sie das **Mac OS** System verwenden.

    #. Installieren Sie Esptool mit den folgenden Befehlen. Esptool ist ein Python-basiertes, Open-Source- und plattformunabhängiges Hilfsprogramm, um mit dem ROM-Bootloader in Espressif-Chips zu kommunizieren.

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. Wenn esptool ordnungsgemäß installiert ist, gibt es eine Meldung wie [usage: esptool] aus, wenn Sie ``python3 -m esptool`` ausführen.

    #. Firmware herunterladen.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Nach dem Entpacken sehen Sie 4 Dateien.

        .. .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: Die Firmware, die auf das ESP8266-Modul gebrannt wird.
        * ``esptool.exe``: Ein Befehlszeilen-Utility für Windows.
        * ``install_r3.bat``: Dies ist das Befehlspaket für das Windows-System.
        * ``install_r4.bat``: Ähnlich wie ``install_r3.bat``, aber speziell für das UNO R4 Board.

    #. Öffnen Sie ein Terminal und navigieren Sie mit dem ``cd``-Befehl in den Ordner mit der heruntergeladenen Firmware. Führen Sie dann den folgenden Befehl aus, um die vorhandene Firmware zu löschen und die neue Firmware zu brennen.

        .. code-block::

            python3 -m esptool --chip esp8266 --before no_reset_no_sync erase_flash
            python3 -m esptool --chip esp8266 --before no_reset_no_sync write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. Wenn Sie die folgende Aufforderung sehen, wurde die Firmware erfolgreich installiert.

        .. image:: img/install_firmware_macos.png

        .. note::
            Wenn das Brennen fehlschlägt, überprüfen Sie bitte die folgenden Punkte.

            * Setzen Sie das ESP8266-Modul zurück, indem Sie den RST am ESP8266-Adapter an GND anschließen und dann entfernen.
            * Überprüfen Sie, ob die Verdrahtung korrekt ist.
            * Stellen Sie sicher, dass Ihr Computer Ihr Board erkannt hat und der Port nicht belegt ist.
            * Öffnen Sie die install.bat-Datei erneut.

**4. Test**

#. Auf Grundlage der ursprünglichen Verkabelung verbinden Sie IO1 mit 3V3.

    .. image:: img/faq_at_burn_check_bb.jpg
        :width: 800

#. Sie können Informationen über das ESP8266-Modul sehen, wenn Sie auf das Lupensymbol (Serial Monitor) in der oberen rechten Ecke klicken und die Baudrate auf **115200** einstellen.

    .. image:: img/sp20220524113020.png

    .. note::

        * Wenn ``ready`` nicht erscheint, können Sie versuchen, das ESP8266-Modul zurückzusetzen (verbinden Sie RST mit GND) und den Serial Monitor erneut zu öffnen.

#. Klicken Sie auf **NEWLINE DROPDOWN BOX**, wählen Sie im Dropdown-Menü ``both NL & CR``, geben Sie ``AT`` ein. Wenn OK zurückgegeben wird, bedeutet dies, dass ESP8266 erfolgreich eine Verbindung mit Ihrem Board hergestellt hat.

    .. image:: img/sp20220524113702.png

Nun können Sie weiterhin :ref:`config_esp8266` folgen, um den Arbeitsmodus und die Baudrate des ESP8266-Moduls einzustellen.







Firmware mit R3 erneut aufspielen
---------------------------------------

**1. Schaltung aufbauen**

Verbinden Sie ESP8266 mit dem SunFounder R3-Board.

    .. image:: img/connect_esp8266.png
        :width: 800

**2. Firmware brennen**

* Befolgen Sie die folgenden Schritte, um die Firmware unter **Windows** zu brennen.

    #. Firmware und Brenn-Tool herunterladen.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Nach dem Entpacken sehen Sie 4 Dateien.

        .. .. image:: img/bat_firmware.png
    
        * ``BAT_AT_V1.7.1.0_1M.bin``: Die Firmware, die auf das ESP8266-Modul gebrannt wird.
        * ``esptool.exe``: Ein Befehlszeilen-Tool für Windows.
        * ``install_r3.bat``: Ein Befehlspaket für das Windows-System. Ein Doppelklick auf diese Datei führt alle Befehle in der Datei aus.
        * ``install_r4.bat``: Wie ``install_r3.bat``, aber speziell für das UNO R4-Board.

    #. Doppelklicken Sie auf ``install_r3.bat``, um den Brennvorgang der Firmware zu starten. Wenn Sie die folgende Aufforderung sehen, wurde die Firmware erfolgreich installiert.

        .. image:: img/install_firmware.png

        .. note::
            Wenn das Brennen fehlschlägt, überprüfen Sie bitte folgende Punkte:

            * Setzen Sie das ESP8266-Modul zurück, indem Sie RST am ESP8266-Adapter an GND anschließen und dann abziehen.
            * Überprüfen Sie, ob die Verkabelung korrekt ist.
            * Stellen Sie sicher, dass Ihr Computer Ihr Board korrekt erkannt hat und der Port nicht belegt ist.
            * Öffnen Sie die install.bat-Datei erneut.

* Um die Firmware unter **Mac OS** zu brennen, folgen Sie diesen Schritten:

    #. Installieren Sie Esptool mit den folgenden Befehlen. Esptool ist ein in Python geschriebenes, Open-Source, plattformunabhängiges Tool, um mit dem ROM-Bootloader in Espressif-Chips zu kommunizieren.

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. Wenn esptool ordnungsgemäß installiert ist, gibt es eine Nachricht wie [usage: esptool] aus, wenn Sie ``python3 -m esptool`` ausführen.

    #. Firmware herunterladen.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Nach dem Entpacken sehen Sie 4 Dateien.

        .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: Die Firmware, die auf das ESP8266-Modul gebrannt wird.
        * ``esptool.exe``: Ein Befehlszeilen-Tool für Windows.
        * ``install_r3.bat``: Ein Befehlspaket für das Windows-System.
        * ``install_r4.bat``: Wie ``install_r3.bat``, aber speziell für das UNO R4-Board.

    #. Öffnen Sie ein Terminal und verwenden Sie den ``cd``-Befehl, um in den gerade heruntergeladenen Firmware-Ordner zu wechseln. Führen Sie dann den folgenden Befehl aus, um die vorhandene Firmware zu löschen und die neue Firmware neu zu brennen.

        .. code-block::

            python3 -m esptool --chip esp8266 --before default_reset erase_flash
            python3 -m esptool --chip esp8266 --before default_reset write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. Wenn Sie die folgende Aufforderung sehen, wurde die Firmware erfolgreich installiert.

        .. image:: img/install_firmware_macos.png

        .. note::
            Wenn das Brennen fehlschlägt, überprüfen Sie bitte folgende Punkte:

            * Setzen Sie das ESP8266-Modul zurück, indem Sie RST am ESP8266-Adapter an GND anschließen und dann abziehen.
            * Überprüfen Sie, ob die Verkabelung korrekt ist.
            * Stellen Sie sicher, dass Ihr Computer Ihr Board korrekt erkannt hat und der Port nicht belegt ist.
            * Öffnen Sie die install.bat-Datei erneut.

**3. Test**

#. Auf Basis der ursprünglichen Verkabelung verbinden Sie IO1 mit 3V3.

    .. image:: img/connect_esp826612.png
        :width: 800

#. Sie können Informationen über das ESP8266-Modul sehen, wenn Sie auf das Lupensymbol (Serial Monitor) in der oberen rechten Ecke klicken und die Baudrate auf **115200** einstellen.

    .. image:: img/sp20220524113020.png

    .. note::

        * Wenn ``ready`` nicht angezeigt wird, können Sie versuchen, das ESP8266-Modul zurückzusetzen (RST mit GND verbinden) und den Serial Monitor erneut zu öffnen.

#. Klicken Sie auf **NEWLINE DROPDOWN BOX**, wählen Sie im Dropdown-Menü ``both NL & CR``, geben Sie ``AT`` ein. Wenn OK zurückgegeben wird, bedeutet dies, dass das ESP8266 erfolgreich eine Verbindung zum R3-Board hergestellt hat.

    .. image:: img/sp20220524113702.png

Nun können Sie weiterhin :ref:`config_esp8266` folgen, um den Arbeitsmodus und die Baudrate des ESP8266-Moduls einzustellen.
