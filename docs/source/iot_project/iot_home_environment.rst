.. _iot_home:

5. Überwachung des häuslichen Umfelds
===========================================

In diesem Kapitel werden wir Blynk verwenden, um einen Monitor für die häusliche Umgebung zu erstellen.
Mit dem DHT11 und dem Fotowiderstand können Sie die Temperatur, Luftfeuchtigkeit und Lichtintensität eines Raumes messen.
Indem Sie diese Werte an Blynk senden, können Sie die Umgebung Ihres Zuhauses über das Internet überwachen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktischer, ein komplettes Set zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Alternativ können Sie diese auch über die untenstehenden Links einzeln erwerben.

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_dht11`
        - \-

**1. Den Schaltkreis aufbauen**

.. note::

    Das ESP8266-Modul benötigt einen hohen Strom, um eine stabile Betriebsumgebung zu gewährleisten. Stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.

.. image:: img/wiring_dht11.jpg

**2. Dashboard bearbeiten**

#. Für die Erfassung von Luftfeuchtigkeitswerten erstellen Sie einen **Datastream** vom Typ **Virtual Pin** auf der **Datastream**-Seite. Legen Sie den DATENTYP auf **Double** und MIN und MAX auf **0** und **100** fest. Setzen Sie auch die Einheiten auf **Percentage, %**.

    .. image:: img/sp220610_145748.png

#. Erstellen Sie anschließend einen **Datastream** vom Typ **Virtual Pin** zur Erfassung der Temperatur. Legen Sie den DATENTYP auf ``Double``, MIN und MAX auf ``-30`` und ``50`` und die Einheiten auf **Celsius, °C** fest.

    .. image:: img/sp220610_145811.png

#. Erstellen Sie zudem einen **Datastream** vom Typ **Virtual Pin** zur Erfassung der Lichtintensität. Nutzen Sie den Standarddatentyp - **Integer** mit den Werten MIN und MAX, die auf ``0`` und ``1024`` festgelegt sind.

    .. image:: img/sp220610_145834.png

#. Navigieren Sie zur **Wed Dashboard**-Seite, ziehen Sie zwei **Label**-Widgets und weisen Sie ihnen die Datenströme **V4** und **V5** zu. Ziehen Sie ein **Gauge**-Widget und setzen Sie den Datenstrom auf **V6**. In den Widget-Einstellungen können Sie **Farbwechsel basierend auf Wert** aktivieren und die passende Farbe wählen, um das Widget ansprechender und intuitiver zu gestalten.

.. image:: img/sp220610_150400.png
    :align: center



**3. Den Code ausführen**

#. Öffnen Sie die Datei ``5.home_environment_monitoring.ino`` unter dem Pfad ``3in1-kit\iot_project\5.home_environment_monitoring`` oder kopieren Sie diesen Code in die **Arduino IDE**.

    .. note::

        * Hier wird die ``DHT sensor library`` verwendet. Sie können sie über den **Library Manager** installieren.

            .. image:: ../img/lib_dht11.png

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/4f0ad85e-8aff-4df9-99dd-c6741aed8219/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Ersetzen Sie die ``Template ID``, ``Device Name`` und ``Auth Token`` durch Ihre eigenen Angaben. Sie müssen auch das ``ssid`` und das ``password`` des von Ihnen verwendeten WLANs eingeben. Für detaillierte Anleitungen verweisen Sie bitte auf :ref:`connect_blynk`.
#. Nach Auswahl des richtigen Boards und Ports klicken Sie auf die **Upoad**-Taste.

#. Öffnen Sie den seriellen Monitor (Baudrate auf 115200 einstellen) und warten Sie, bis eine Meldung wie eine erfolgreiche Verbindung erscheint.

    .. image:: img/2_ready.png

    .. note::

        Wenn beim Verbinden die Meldung ``ESP antwortet nicht`` erscheint, befolgen Sie bitte diese Schritte.

        * Stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.
        * Setzen Sie das ESP8266-Modul zurück, indem Sie den RST-Pin für 1 Sekunde auf GND setzen und dann trennen.
        * Drücken Sie die Reset-Taste auf dem R3-Board.

        Manchmal müssen Sie den oben beschriebenen Vorgang 3-5 Mal wiederholen, bitte haben Sie Geduld.

#. Nun sehen Sie die aktuelle Umgebungstemperatur, Luftfeuchtigkeit und Lichtintensität auf Blynk.

    .. image:: img/sp220610_150400.png
        :align: center

#. Wenn Sie Blynk auf mobilen Geräten verwenden möchten, verweisen Sie bitte auf :ref:`blynk_mobile`.

    .. image:: img/mobile_home.jpg

**Wie funktioniert das?**

Diese beiden Funktionen werden verwendet, um die Temperatur, Luftfeuchtigkeit und Lichtintensität des Raumes zu ermitteln.


.. code-block:: arduino

    int readLight(){
        return analogRead(lightPin);
    }

    bool readDHT() {

        // Das Lesen von Temperatur oder Luftfeuchtigkeit dauert etwa 250 Millisekunden!
        // Sensormessungen können auch bis zu 2 Sekunden "alt" sein (es ist ein sehr langsamer Sensor)
        humidity = dht.readHumidity();
        // Temperatur als Celsius lesen (Standardwert)
        temperature = dht.readTemperature();

        // Überprüfen, ob eine Messung fehlgeschlagen ist und frühzeitig beenden (um es erneut zu versuchen).
        if (isnan(humidity) || isnan(temperature)) {
            Serial.println("Fehler beim Lesen des DHT-Sensors!");
            return false;
        }
        return true;
    }

Mit dem Blynk ``Timer`` werden die Umgebungstemperatur, Luftfeuchtigkeit und Lichtintensität jede Sekunde abgerufen und an den Datenstrom auf der Blynk Cloud gesendet, von wo aus die Widgets die Daten anzeigen.

.. code-block:: arduino

    void myTimerEvent()
    {
        bool chk = readDHT();
        int light = readLight();
        if(chk){
            Blynk.virtualWrite(V4,humidity);
            Blynk.virtualWrite(V5,temperature);
        }
        Blynk.virtualWrite(V6,light);
    }