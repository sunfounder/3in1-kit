.. _burn_firmware:

Wie kann die Firmware für das ESP8266-Modul neu geflasht werden?
==================================================================

Firmware mit R3 neu flashen
---------------------------------------

**1. Schaltkreis aufbauen**

Verbinden Sie das ESP8266 mit dem SunFounder R3 Board.

    .. image:: img/connect_esp8266.png
        :width: 800

**2. Firmware flashen**

* Befolgen Sie die folgenden Schritte, um die Firmware unter **Windows** zu flashen.

    #. Firmware und Flash-Tool herunterladen.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Nach dem Entpacken sehen Sie 4 Dateien.

        .. image:: img/bat_firmware.png
    
        * ``BAT_AT_V1.7.1.0_1M.bin``: Die Firmware, die auf das ESP8266-Modul geflasht wird.
        * ``esptool.exe``: Dies ist ein Kommandozeilen-Tool für Windows.
        * ``install_r3.bat``: Dieses Kommandopaket ist für das Windows-System. Ein Doppelklick auf diese Datei führt alle darin enthaltenen Befehle aus.
        * ``install_r4.bat``: Ähnlich wie ``install_r3.bat``, jedoch speziell für das UNO R4 Board.

    #. Doppelklicken Sie auf ``install_r3.bat``, um das Flashen der Firmware zu starten. Wenn Sie die folgende Aufforderung sehen, wurde die Firmware erfolgreich installiert.

        .. image:: img/install_firmware.png

        .. note::
            Wenn das Flashen fehlschlägt, überprüfen Sie bitte die folgenden Punkte.

            * Setzen Sie das ESP8266-Modul zurück, indem Sie RST am ESP8266-Adapter auf GND setzen und dann wieder entfernen.
            * Überprüfen Sie, ob die Verkabelung korrekt ist.
            * Stellen Sie sicher, dass der Computer Ihr Board korrekt erkannt hat und der Port nicht belegt ist.
            * Öffnen Sie die install.bat-Datei erneut.

* Um die Firmware auf einem **Mac OS**-System zu flashen, befolgen Sie diese Schritte.

    #. Verwenden Sie die folgenden Befehle, um Esptool zu installieren. Esptool ist ein Python-basiertes, Open-Source-Tool, um mit dem ROM-Bootloader in Espressif-Chips zu kommunizieren.

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. Wenn Esptool korrekt installiert wurde, gibt es eine Nachricht wie [usage: esptool] aus, wenn Sie ``python3 -m esptool`` ausführen.

    #. Firmware herunterladen.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Nach dem Entpacken sehen Sie 3 Dateien.

        .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: Die Firmware, die auf das ESP8266-Modul geflasht wird.
        * ``esptool.exe``: Dies ist ein Kommandozeilen-Tool für Windows.
        * ``install_r3.bat``: Dieses Kommandopaket ist für das Windows-System.
        * ``install_r4.bat``: Ähnlich wie ``install_r3.bat``, jedoch speziell für das UNO R4 Board.

    #. Öffnen Sie ein Terminal und navigieren Sie mit dem Befehl ``cd`` in den gerade heruntergeladenen Firmware-Ordner. Führen Sie dann den folgenden Befehl aus, um die vorhandene Firmware zu löschen und die neue Firmware zu flashen.

        .. code-block::

            python3 -m esptool --chip esp8266 --before default_reset erase_flash
            python3 -m esptool --chip esp8266 --before default_reset write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. Wenn Sie die folgende Aufforderung sehen, wurde die Firmware erfolgreich installiert.

        .. image:: img/install_firmware_macos.png

        .. note::
            Wenn das Flashen fehlschlägt, überprüfen Sie bitte die folgenden Punkte.

            * Setzen Sie das ESP8266-Modul zurück, indem Sie RST am ESP8266-Adapter auf GND setzen und dann wieder entfernen.
            * Überprüfen Sie, ob die Verkabelung korrekt ist.
            * Stellen Sie sicher, dass der Computer Ihr Board korrekt erkannt hat und der Port nicht belegt ist.
            * Öffnen Sie die install.bat-Datei erneut.

**3. Test**

#. Auf Basis der ursprünglichen Verkabelung verbinden Sie IO1 mit 3V3.

    .. image:: img/connect_esp826612.png
        :width: 800

#. Sie können Informationen über das ESP8266-Modul sehen, wenn Sie auf das Lupensymbol (Serial Monitor) in der oberen rechten Ecke klicken und die Baudrate auf **115200** einstellen.

    .. image:: img/sp20220524113020.png

    .. note::

        * Wenn ``ready`` nicht erscheint, können Sie versuchen, das ESP8266-Modul zurückzusetzen (verbinden Sie RST mit GND) und den Serial Monitor erneut zu öffnen.

#. Klicken Sie auf das **NEWLINE DROPDOWN BOX**, wählen Sie ``both NL & CR`` aus dem Dropdown-Menü aus, geben Sie ``AT`` ein. Wenn die Antwort OK lautet, bedeutet dies, dass das ESP8266 erfolgreich eine Verbindung mit dem R3-Board hergestellt hat.

    .. image:: img/sp20220524113702.png

Jetzt können Sie :ref:`config_esp8266` folgen, um den Arbeitsmodus und die Baudrate des ESP8266-Moduls einzustellen.

Wie man die Firmware mit R4 neu aufspielt
-----------------------------------------------

**1. Den Schaltkreis aufbauen**

Verbinden Sie ESP8266 und das Arduino UNO R4 Board.

    .. image:: img/faq_at_burn_bb.jpg
        :width: 800

**2. Laden Sie den folgenden Code auf R4 hoch**

.. code-block:: Arduino

    void setup() {
        Serial.begin(115200);
        Serial1.begin(115200);
    }

    void loop() {
        if (Serial.available()) {      // Wenn Daten über Serial (USB) eintreffen,
            Serial1.write(Serial.read());   // werden diese gelesen und über Serial1 (Pins 0 & 1) gesendet.
        }
            if (Serial1.available()) {     // Wenn Daten über Serial1 (Pins 0 & 1) eintreffen,
            Serial.write(Serial1.read());   // werden diese gelesen und über Serial (USB) gesendet.
        }
    }

**3. Firmware aufspielen**

* Folgen Sie diesen Schritten, um die Firmware unter **Windows** aufzuspielen.

    #. Firmware und Brenn-Tool herunterladen.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Nach dem Entpacken werden Sie 4 Dateien sehen.

        .. image:: img/bat_firmware.png
    
        * ``BAT_AT_V1.7.1.0_1M.bin``: Die auf das ESP8266 Modul aufzuspielende Firmware.
        * ``esptool.exe``: Ein Kommandozeilen-Tool für Windows.
        * ``install_r3.bat``: Ein Befehlspaket für das Windows-System. Ein Doppelklick auf diese Datei führt alle enthaltenen Befehle aus.
        * ``install_r4.bat``: Ähnlich wie ``install_r3.bat``, jedoch speziell für das UNO R4 Board.

    #. Doppelklicken Sie auf ``install_r4.bat``, um das Aufspielen der Firmware zu starten. Wenn Sie die folgende Aufforderung sehen, wurde die Firmware erfolgreich installiert.

        .. image:: img/install_firmware.png

        .. note::
            Wenn das Aufspielen fehlschlägt, überprüfen Sie bitte die folgenden Punkte:

            * Setzen Sie das ESP8266-Modul zurück, indem Sie RST am ESP8266-Adapter an GND anschließen und dann wieder entfernen.
            * Überprüfen Sie, ob die Verkabelung korrekt ist.
            * Stellen Sie sicher, dass Ihr Computer Ihr Board korrekt erkannt hat und der Port nicht belegt ist.
            * Öffnen Sie die install.bat-Datei erneut.

* Um die Firmware unter **Mac OS** aufzuspielen, befolgen Sie diese Schritte:

    #. Installieren Sie Esptool mit den folgenden Befehlen. Esptool ist ein Python-basiertes, Open-Source-Tool, um mit dem ROM-Bootloader in Espressif-Chips zu kommunizieren.

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. Wenn esptool korrekt installiert wurde, gibt es eine Nachricht wie [usage: esptool] aus, wenn Sie ``python3 -m esptool`` ausführen.

    #. Firmware herunterladen.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Nach dem Entpacken werden Sie 4 Dateien sehen.

        .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: Die auf das ESP8266 Modul aufzuspielende Firmware.
        * ``esptool.exe``: Ein Kommandozeilen-Tool für Windows.
        * ``install_r3.bat``: Ein Befehlspaket für das Windows-System.
        * ``install_r4.bat``: Ähnlich wie ``install_r3.bat``, jedoch speziell für das UNO R4 Board.

    #. Öffnen Sie ein Terminal und navigieren Sie mit dem ``cd``-Befehl in den gerade heruntergeladenen Firmware-Ordner. Führen Sie dann den folgenden Befehl aus, um die vorhandene Firmware zu löschen und die neue Firmware aufzuspielen.

        .. code-block::

            python3 -m esptool --chip esp8266 --before no_reset_no_sync erase_flash
            python3 -m esptool --chip esp8266 --before no_reset_no_sync write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. Wenn Sie die folgende Aufforderung sehen, wurde die Firmware erfolgreich installiert.

        .. image:: img/install_firmware_macos.png

        .. note::
            Wenn das Aufspielen fehlschlägt, überprüfen Sie bitte die folgenden Punkte:

            * Setzen Sie das ESP8266-Modul zurück, indem Sie RST am ESP8266-Adapter an GND anschließen und dann wieder entfernen.
            * Überprüfen Sie, ob die Verkabelung korrekt ist.
            * Stellen Sie sicher, dass Ihr Computer Ihr Board korrekt erkannt hat und der Port nicht belegt ist.
            * Öffnen Sie die install.bat-Datei erneut.

**4. Testen**

#. Auf Basis der ursprünglichen Verkabelung verbinden Sie IO1 mit 3V3.

    .. image:: img/faq_at_burn_check_bb.jpg
        :width: 800

#. Sie werden Informationen über das ESP8266-Modul sehen, wenn Sie auf das Lupen-Icon (Serial Monitor) in der oberen rechten Ecke klicken und die Baudrate auf **115200** einstellen.

    .. image:: img/sp20220524113020.png

    .. note::

        * Wenn ``ready`` nicht erscheint, können Sie versuchen, das ESP8266-Modul zurückzusetzen (RST mit GND verbinden) und den Serial Monitor erneut zu öffnen.

#. Klicken Sie auf das **NEWLINE DROPDOWN BOX** und wählen Sie im Dropdown-Menü ``both NL & CR`` aus. Geben Sie ``AT`` ein. Wenn "OK" zurückgegeben wird, bedeutet dies, dass ESP8266 erfolgreich eine Verbindung mit Ihrem Board hergestellt hat.

    .. image:: img/sp20220524113702.png

Nun können Sie :ref:`config_esp8266` folgen, um den Arbeitsmodus und die Baudrate des ESP8266-Moduls einzustellen.
