.. _iot_blink:

2. Daten von Blynk abrufen
=================================

In diesem Kapitel lernen Sie, wie Sie den Schaltkreis mit Blynk steuern können. Lassen Sie uns die LEDs über das Internet einschalten!

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können diese auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - \-
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

.. image:: img/iot_2_bb.png

**2. Dashboard bearbeiten**

#. Gehen Sie zum **Quickstart Device**, das Sie zuvor erstellt haben, klicken Sie auf das Menüsymbol in der oberen rechten Ecke und wählen Sie **edit dashboard**.

    .. image:: img/sp220609_112825.png

#. Datastreams ermöglichen es den Widgets auf Blynk und dem Code auf Ihrem Board, einander zu erkennen. Um den vollständigen Konfigurationsprozess zu erleben, entfernen Sie alle Datastreams von der Datastreams-Seite.

    .. image:: img/sp220609_114723.png

#. Bitte lesen Sie die Warnung sorgfältig und bestätigen Sie, dass sie korrekt ist, bevor Sie die Datastreams löschen.

    .. image:: img/sp220609_114929.png

#. Erstellen Sie einen Datastream vom Typ **Virtual Pin**, der zum Steuern der LED mit Blynks Schalter verwendet wird.

    .. image:: img/sp220609_115124.png

#. Konfigurieren Sie den **Virtual Pin**. Da der Button und die LED nur EIN oder AUS benötigen, stellen Sie DATENTYP auf ``Integer`` und MIN und MAX auf ``0`` und ``1``.

    .. image:: img/sp220609_115520.png

#. Gehen Sie zur **Web Dashboard**-Seite und löschen Sie die vorhandenen Widgets.

    .. image:: img/sp220609_133707.png

#. Ziehen Sie ein **switch**-Widget aus der **Widget-Box** auf der linken Seite und legen Sie es ab.

    .. image:: img/sp220609_114508.png

#. Nun zur Einrichtung.

    .. image:: img/sp20220615180127.png

#. Wählen Sie **Datastream** als den zuvor eingerichteten aus.

    .. image:: img/sp220609_133741.png

#. Nachdem Sie Datastream ausgewählt haben, sehen Sie einige benutzerdefinierte Einstellungen. Drücken Sie dann auf Speichern.

    .. image:: img/sp220609_133950.png

#. Klicken Sie abschließend auf **Save And Apply**.

    .. image:: img/sp220609_141733.png

**3. Den Code ausführen**

#. Öffnen Sie die Datei ``2.get_data_from_blynk.ino`` im Pfad ``3in1-kit\iot_project\2.get_data_from_blynk`` oder kopieren Sie diesen Code in die **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b187a8-dabf-4866-b38c-742e0446cc3f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Ersetzen Sie die ``Template ID``, den ``Device Name`` und den ``Auth Token`` durch Ihre eigenen. Sie müssen auch die ``ssid`` und das ``password`` Ihres WLANs eingeben. Für detaillierte Anleitungen verweisen Sie bitte auf :ref:`connect_blynk`.

#. Wählen Sie das richtige Board und den richtigen Port aus und klicken Sie auf den **Upoad**-Button.

    .. image:: img/2_upload.png

#. Öffnen Sie den seriellen Monitor (Baudrate auf 115200 einstellen) und warten Sie auf eine Meldung wie eine erfolgreiche Verbindung.

    .. image:: img/2_ready.png

    .. note::

        Wenn die Meldung ``ESP is not responding`` erscheint, befolgen Sie bitte diese Schritte.

        * Stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.
        * Setzen Sie das ESP8266-Modul zurück, indem Sie den Pin RST 1 Sekunde lang auf GND verbinden und dann trennen.
        * Drücken Sie die Reset-Taste auf Ihrem Board.

        Manchmal müssen Sie den oben genannten Vorgang 3-5 Mal wiederholen. Bitte haben Sie Geduld.

#. Zurück bei Blynk können Sie sehen, dass der Status auf online geändert wurde und Sie können nun das Schalter-Widget auf Blynk verwenden, um die LED auf dem R4-Board zu steuern.

    .. image:: img/2_blynk_button.png

#. Wenn Sie Blynk auf mobilen Geräten verwenden möchten, verweisen Sie bitte auf :ref:`blynk_mobile`.


**Wie funktioniert das?**

Der Unterschied zwischen dem Code in diesem Projekt und dem Code im vorherigen Kapitel :ref:`connect_blynk` sind die folgenden Zeilen.

.. code-block:: arduino

    const int ledPin=6;

    BLYNK_WRITE(V0)
    {
        int pinValue = param.asInt(); // assigning incoming value from pin V0 to a variable
        // You can also use:
        // String i = param.asStr();
        // double d = param.asDouble();
        digitalWrite(ledPin,pinValue);
    }

    void setup()
    {
        pinMode(ledPin,OUTPUT);
    }

Bezüglich des ``pinMode`` und des ``digitalWrite`` des ledPin bin ich sicher, dass Sie bereits vertraut sind, also werde ich sie nicht noch einmal durchgehen. Worauf Sie sich konzentrieren sollten, ist die Funktion ``BLYNK_WRITE(V0)``.

Was es tun wird: Wenn sich der Wert von Blynks ``V0`` ändert, wird Blynk.Cloud Ihrem Gerät mitteilen: "Ich schreibe an **Virtual Pin** V0", und Ihr Gerät wird in der Lage sein, etwas auszuführen, sobald es diese Information erhält.

Wir haben im vorherigen Schritt den V0 Datastream erstellt und ihn dem Schalter-Widget zugewiesen.
Das bedeutet, dass jedes Mal, wenn wir das Schalter-Widget betätigen, ``BLYNK_WRITE(V0)`` ausgelöst wird.

Wir schreiben zwei Anweisungen in diese Funktion.

.. code-block:: arduino

    int pinValue = param.asInt();

Holen Sie sich den Wert von V0 und weisen Sie ihn der Variable ``pinValue`` zu.

.. code-block:: arduino

    digitalWrite(ledPin,pinValue);

Schreiben Sie den erlangten Wert von V0 auf den ledPin, damit das Schalter-Widget auf Blynk die LED steuern kann.

