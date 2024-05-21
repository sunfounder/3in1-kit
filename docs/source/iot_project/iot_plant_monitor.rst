.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _iot_plant:

6. Pflanzenüberwachung
==========================

Das Ziel dieses Projekts ist es, ein intelligentes Bewässerungssystem zu erstellen, das die aktuelle Temperatur, Luftfeuchtigkeit, Lichtintensität und Bodenfeuchtigkeit erkennt und diese auf Blynk anzeigt.

Sobald Sie den Schalter in der Blynk Cloud umlegen, beginnt die Pumpe zu arbeiten und die Pflanzen werden bewässert.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM SET
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können diese auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENVORSTELLUNG
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
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_pump`
        - \-

**1. Schaltung aufbauen**

.. note::

    Das ESP8266-Modul benötigt einen hohen Strom, um eine stabile Betriebsumgebung zu gewährleisten. Stellen Sie also sicher, dass die 9V-Batterie angeschlossen ist.

.. image:: img/wiring_6_plant_monitor_bb.png
    :width: 800

**2. Dashboard bearbeiten**

#. Die in den vorherigen Projekten erstellten Datenströme müssen gespeichert werden und werden auch in diesem Projekt verwendet.

#. Zur Aufzeichnung der Bodenfeuchtigkeit erstellen Sie einen weiteren **Datastream** vom Typ **Virtual Pin** auf der **Datastream**-Seite. Stellen Sie den DATENTYP auf ``Integer`` und MIN und MAX auf ``0`` und ``1024``.

    .. image:: img/sp220610_155221.png

#. Gehen Sie nun zur **Wed Dashboard**-Seite, ziehen Sie 2 **Label**-Widgets und setzen Sie ihre Datenströme auf **V4** bzw. **V5**; ziehen Sie 2 **Gauge**-Widgets und setzen Sie ihre Datenströme auf **V6** und **V7**; ziehen Sie zuletzt ein **Switch**-Widget und setzen Sie dessen Datenstrom auf **V0**.

    .. image:: img/sp220610_155350.png

**3. Code ausführen**

Öffnen Sie die Datei ``6.plant_monitoring.ino`` unter dem Pfad ``3in1-kit\iot_project\6.plant_monitoring`` oder kopieren Sie diesen Code in die **Arduino IDE**.

    .. note::

        * Hier wird die ``DHT sensor library`` verwendet. Sie können sie über den **Library Manager** installieren.

            .. image:: ../img/lib_dht11.png

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/f738bcb5-4ee2-475b-b683-759e6b2041b0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Ersetzen Sie die ``Template ID``, den ``Gerätenamen`` und den ``Auth Token`` durch Ihre eigenen Angaben. Geben Sie auch die ``ssid`` und das ``Passwort`` des von Ihnen verwendeten WLANs ein. Für detaillierte Anleitungen verweisen Sie bitte auf :ref:`connect_blynk`.
#. Nach Auswahl des richtigen Boards und Ports klicken Sie auf die Schaltfläche **Upoad**.

#. Öffnen Sie den Serienmonitor (Baudrate auf 115200 einstellen) und warten Sie auf eine Aufforderung, wie z.B. eine erfolgreiche Verbindung.

    .. image:: img/2_ready.png

    .. note::

        Wenn die Meldung ``ESP antwortet nicht`` erscheint, wenn Sie sich verbinden, folgen Sie bitte diesen Schritten.

        * Stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.
        * Setzen Sie das ESP8266-Modul zurück, indem Sie den Pin RST für 1 Sekunde mit GND verbinden und dann trennen.
        * Drücken Sie den Reset-Knopf auf dem R3-Board.

        Manchmal müssen Sie die oben genannte Operation 3-5 Mal wiederholen. Bitte haben Sie Geduld.

#. Zurück zu Blynk, Sie sehen die aktuelle Temperatur, Luftfeuchtigkeit, Lichtintensität und Bodenfeuchtigkeit. Sie können die Pumpe die Pflanzen bewässern lassen, falls notwendig, indem Sie das Button Control-Widget anklicken.

    .. image:: img/sp220610_155350.png

#. Wenn Sie Blynk auf mobilen Geräten verwenden möchten, verweisen Sie bitte auf :ref:`blynk_mobile`.

    .. image:: img/mobile_plant.jpg

**Wie funktioniert das?**

Dieses ``BLYNK_WRITE`` bewirkt, dass Blynks **Switch**-Widget die Pumpe startet, wenn es EIN ist und sie ausschaltet, wenn es AUS ist.

.. code-block:: arduino

    BLYNK_WRITE(V0)
    {
        if(param.asInt()==1){
            digitalWrite(pumpA,HIGH);
        }else{
            digitalWrite(pumpA,LOW); 
        }
    }

Diese drei Funktionen werden verwendet, um die aktuelle Umgebungstemperatur, Luftfeuchtigkeit, Lichtintensität und Bodenfeuchtigkeit zu erhalten.

.. code-block:: arduino

    int readMoisture(){
        return analogRead(moisturePin);
    }

    int readLight(){
        return analogRead(lightPin);
    }

    bool readDHT() {

        // Reading temperature or humidity takes about 250 milliseconds!
        // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
        humidity = dht.readHumidity();
        // Read temperature as Celsius (the default)
        temperature = dht.readTemperature();

        // Check if any reads failed and exit early (to try again).
        if (isnan(humidity) || isnan(temperature)) {
            Serial.println("Failed to read from DHT sensor!");
            return false;
        }
        return true;
    }

Mit dem Blynk ``Timer`` werden die Umgebungstemperatur, Luftfeuchtigkeit, Lichtintensität und Bodenfeuchtigkeit jede Sekunde abgerufen und an den Datenstrom auf der **Blynk Cloud** gesendet, von dem aus die Widgets die Daten anzeigen.



.. code-block:: arduino

    void myTimerEvent()
    {
        bool chk = readDHT();
        int light = readLight();
        int moisture = readMoisture();
        if(chk){
            Blynk.virtualWrite(V4,humidity);
            Blynk.virtualWrite(V5,temperature);
        }
        Blynk.virtualWrite(V6,light);
        Blynk.virtualWrite(V7,moisture);
    }
