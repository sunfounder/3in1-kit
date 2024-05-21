.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _iot_blink:

2. Daten von Blynk abrufen
=================================

In diesem Kapitel erfahren Sie, wie Sie den Schaltkreis mit Blynk steuern können. Lassen Sie uns die LEDs über das Internet leuchten!

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK
    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

**1. Schaltkreis aufbauen**

.. note::

    Das ESP8266-Modul benötigt einen hohen Strom, um eine stabile Betriebsumgebung zu gewährleisten. Stellen Sie daher sicher, dass die 9V-Batterie angeschlossen ist.

.. image:: img/wiring_led.jpg

**2. Dashboard bearbeiten**

#. Gehen Sie zum **Quickstart Device**, das Sie zuvor erstellt haben, klicken Sie auf das Menüsymbol in der oberen rechten Ecke und wählen Sie **edit dashboard**.

    .. image:: img/sp220609_112825.png

#. Datastreams ermöglichen es den Widgets auf Blynk und dem Code auf dem R3-Board, sich gegenseitig zu erkennen. Um den vollständigen Konfigurationsprozess zu erleben, entfernen Sie alle Datastreams von der Datastreams-Seite.

    .. image:: img/sp220609_114723.png

#. Bitte lesen Sie die Warnung sorgfältig durch und bestätigen Sie vor dem Löschen der Datastreams, dass sie korrekt ist.

    .. image:: img/sp220609_114929.png

#. Erstellen Sie einen Datastream des Typs **Virtual Pin**, der zum Steuern der LED mit Blynks Schalter verwendet wird.

    .. image:: img/sp220609_115124.png

#. Konfigurieren Sie den **Virtual Pin**. Da der Knopf und die LED nur EIN und AUS sein müssen, setzen Sie DEN DATENTYP auf ``Integer`` und MIN und MAX auf ``0`` und ``1``.

    .. image:: img/sp220609_115520.png

#. Gehen Sie zur **Web Dashboard**-Seite und löschen Sie die vorhandenen Widgets.

    .. image:: img/sp220609_133707.png

#. Ziehen Sie ein **switch**-Widget aus dem **Widget Box** links in den Arbeitsbereich.

    .. image:: img/sp220609_114508.png

#. Nun geht es an die Einrichtung.

    .. image:: img/sp20220615180127.png

#. Wählen Sie **Datastream** wie zuvor eingestellt.

    .. image:: img/sp220609_133741.png

#. Nach Auswahl von Datastream sehen Sie einige benutzerdefinierte Einstellungen. Drücken Sie dann auf Speichern.

    .. image:: img/sp220609_133950.png

#. Klicken Sie abschließend auf **Save And Apply**.

    .. image:: img/sp220609_141733.png


**3. Den Code ausführen**

#. Öffnen Sie die Datei ``2.get_data_from_blynk.ino`` unter dem Pfad ``3in1-kit\iot_project\2.get_data_from_blynk``, oder kopieren Sie diesen Code in die **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b187a8-dabf-4866-b38c-742e0446cc3f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Ersetzen Sie die ``Template ID``, ``Device Name`` und ``Auth Token`` durch Ihre eigenen. Geben Sie auch die ``ssid`` und das ``password`` Ihres WiFi ein. Für detaillierte Anleitungen verweisen Sie bitte auf :ref:`connect_blynk`.

#. Wählen Sie das richtige Board und den richtigen Port aus und klicken Sie auf den **Upoad**-Button.

    .. image:: img/2_upload.png

#. Öffnen Sie den Seriellen Monitor (Baudrate auf 115200 einstellen) und warten Sie auf eine Aufforderung, z.B. eine erfolgreiche Verbindung.

    .. image:: img/2_ready.png

    .. note::

        Wenn beim Verbinden die Meldung ``ESP antwortet nicht`` erscheint, befolgen Sie bitte diese Schritte.

        * Stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.
        * Setzen Sie das ESP8266-Modul zurück, indem Sie den Pin RST für 1 Sekunde auf GND legen und dann wieder entfernen.
        * Drücken Sie den Reset-Button auf dem R3-Board.

        Manchmal müssen Sie den obigen Vorgang 3-5 Mal wiederholen, bitte haben Sie Geduld.

#. Zurück bei Blynk sehen Sie, dass der Status auf online geändert wurde und Sie können nun das Schalter-Widget auf Blynk verwenden, um die an das R3-Board angeschlossene LED zu steuern.

    .. image:: img/2_blynk_button.png

#. Wenn Sie Blynk auf mobilen Geräten verwenden möchten, verweisen Sie bitte auf :ref:`blynk_mobile`.

**Wie funktioniert das?**

Der Unterschied zwischen dem Code in diesem Projekt und dem Code im vorherigen Kapitel :ref:`connect_blynk` sind die folgenden Zeilen.

.. code-block:: arduino

    const int ledPin=6;

    BLYNK_WRITE(V0)
    {
        int pinValue = param.asInt();// Zuweisen des eingehenden Werts von Pin V0 zu einer Variablen
         // Sie können auch Folgendes verwenden:
         // String i = param.asStr();
         // double d = param.asDouble();
        digitalWrite(ledPin,pinValue);
    }

    void setup()
    {
        pinMode(ledPin,OUTPUT);
    }

Bezüglich der ``pinMode`` und ``digitalWrite`` des ledPin bin ich sicher, dass Sie bereits damit vertraut sind, deshalb werde ich sie nicht noch einmal erklären. Worauf Sie sich konzentrieren müssen, ist die Funktion ``BLYNK_WRITE(V0)``.

Was sie macht ist, dass, wenn der Wert von Blynks ``V0`` sich ändert, Blynk.Cloud Ihrem Gerät mitteilt "Ich schreibe auf den **Virtual Pin** V0", und Ihr Gerät wird in der Lage sein, etwas auszuführen, sobald es diese Information erhält.

Wir haben im vorherigen Schritt den V0 Datastream erstellt und ihn dem Switch-Widget zugewiesen.
Das bedeutet, dass jedes Mal, wenn wir das Switch-Widget bedienen, ``BLYNK_WRITE(V0)`` ausgelöst wird.

Wir schreiben zwei Anweisungen in dieser Funktion.

.. code-block:: arduino

    int pinValue = param.asInt();

Holen Sie sich den Wert von V0 und weisen Sie ihn der Variable ``pinValue`` zu.

.. code-block:: arduino

    digitalWrite(ledPin,pinValue);

Schreiben Sie den erhaltenen Wert von V0 auf den ledPin, sodass das Schalter-Widget auf Blynk die LED steuern kann.


