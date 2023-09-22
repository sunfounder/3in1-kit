.. _connect_blynk:

1.4 Verbindung des R3-Boards mit Blynk herstellen
------------------------------------------------------

#. Verbinden Sie das ESP8266-Modul erneut mit dem R3-Board. Hier wird die Software-Serienschnittstelle verwendet, sodass TX und RX mit den Pins 2 und 3 des R3-Boards verbunden werden.

    .. note::

        Das ESP8266-Modul benötigt einen hohen Strom, um eine stabile Betriebsumgebung zu gewährleisten. Stellen Sie daher sicher, dass die 9V-Batterie angeschlossen ist.

    .. image:: img/wiring_23.jpg

#. Öffnen Sie die Datei ``1.connect.ino`` im Pfad ``3in1-kit\iot_project\1.connect`` oder kopieren Sie diesen Code in die **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/1c0c1a8f-2551-484f-9f4f-d5d4117cc864/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Ersetzen Sie die folgenden drei Codezeilen, die Sie von der **Device info**-Seite Ihres Kontos kopieren können. Diese drei Zeilen ermöglichen es Ihrem R3-Board, Ihr Blynk-Konto zu finden.

    .. code-block:: arduino

        #define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
        #define BLYNK_DEVICE_NAME "Device"
        #define BLYNK_AUTH_TOKEN "YourAuthToken"
    
    .. image:: img/sp20220614174721.png

#. Geben Sie die ``ssid`` und das ``password`` des von Ihnen verwendeten WLANs ein.

    .. code-block:: arduino

        char ssid[] = "ssid";
        char pass[] = "password";

#. Laden Sie den Code auf das R3-Board, öffnen Sie dann den seriellen Monitor und stellen Sie die Baudrate auf 115200 ein. Wenn das R3-Board erfolgreich mit Blynk kommuniziert, zeigt der serielle Monitor das Zeichen ``ready`` an.

    .. image:: img/sp220607_170223.png

    .. note::
    
        Wenn die Meldung ``ESP antwortet nicht`` erscheint, befolgen Sie bitte diese Schritte:

        * Stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.
        * Setzen Sie das ESP8266-Modul zurück, indem Sie den Pin RST für 1 Sekunde mit GND verbinden und dann trennen.
        * Drücken Sie die Reset-Taste auf dem R3-Board.

        Manchmal müssen Sie den obigen Vorgang 3-5 Mal wiederholen. Bitte haben Sie Geduld.

#. Der Status von Blynk ändert sich von **offline** zu **online**.

    .. image:: img/sp220607_170326.png
