.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!
    
.. _connect_blynk:

1.3 Verbindung des R4-Boards mit Blynk herstellen
======================================================

#. Schließen Sie das ESP8266-Modul und das R4-Board erneut an. Hier wird die Software-Serielle verwendet, daher sind TX und RX jeweils an die Pins 2 und 3 des R4-Boards angeschlossen.

    .. note::

        Das ESP8266-Modul benötigt einen hohen Strom, um eine stabile Betriebsumgebung zu gewährleisten. Stellen Sie daher sicher, dass die 9V-Batterie angeschlossen ist.

    .. image:: img/iot_1.4_bb.png


#. Klicken Sie auf die Seite **devices** und Sie sehen das neue Gerät, das Sie gerade erstellt haben. Klicken Sie dann auf Entwicklertools.

    .. image:: img/blynk_copy_developer.png

#. Und Sie sehen ``TEMPLATE_ID``, ``DEVICE_NAME`` und ``AUTH_TOKEN`` in den **Firmware info** und müssen diese später kopieren.

    .. image:: img/blynk_copy_firmwareinfo.png


#. Öffnen Sie die Datei ``1.connect.ino`` unter dem Pfad ``3in1-kit\iot_project\1.connect``. Oder kopieren Sie diesen Code in die **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/1c0c1a8f-2551-484f-9f4f-d5d4117cc864/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Ersetzen Sie die folgenden drei Codezeilen, die Sie von der **Firmware info**-Seite Ihres Kontos kopieren können. Diese drei Codezeilen ermöglichen es Ihrem R4-Board, Ihr Blynk-Konto zu finden.

    .. code-block:: arduino

        #define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
        #define BLYNK_DEVICE_NAME "Device"
        #define BLYNK_AUTH_TOKEN "YourAuthToken"
    

#. Tragen Sie die ``ssid`` und das ``password`` des von Ihnen verwendeten WLANs ein.

    .. code-block:: arduino

        char ssid[] = "ssid";
        char pass[] = "password";

#. Laden Sie den Code auf das R4-Board, öffnen Sie dann den seriellen Monitor und stellen Sie die Baudrate auf 115200 ein. Wenn das R4-Board erfolgreich mit Blynk kommuniziert, zeigt der serielle Monitor den Schriftzug ``ready`` an.

    .. image:: img/blynk_connect_network.png
        
    .. note::
    
        Wenn beim Verbinden die Meldung ``ESP reagiert nicht`` erscheint, befolgen Sie bitte diese Schritte.

        * Stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.
        * Setzen Sie das ESP8266-Modul zurück, indem Sie den RST-Pin für 1 Sekunde mit GND verbinden und dann trennen.
        * Drücken Sie den Reset-Knopf auf dem R4-Board.

        Manchmal müssen Sie den obigen Vorgang 3-5 Mal wiederholen. Bitte haben Sie Geduld.

#. Der Status von Blynk wird von **offline** auf **online** wechseln.

    .. image:: img/sp220607_170326.png
