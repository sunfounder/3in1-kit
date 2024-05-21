.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_calibration:

5.14 Kalibrierung
==========================

Wenn Sie analoge Eingangskomponenten wie Fotowiderstände, Bodenfeuchtigkeitssensoren usw. verwenden, stellen Sie möglicherweise fest, dass ihr Messbereich nicht 0 bis 1023 beträgt, sondern eher Bereiche wie 0 bis 800 oder 600 bis 1000, da es bei normalem Gebrauch unmöglich ist, die Grenzen dieser Geräte zu erreichen.

In solchen Fällen kann eine Technik zur Kalibrierung der Sensoreingänge angewendet werden. Beim Start sollte das Steuerbrett die Sensorwerte für fünf Sekunden messen und die höchsten und niedrigsten Werte aufzeichnen. Dieser fünfsekündige Messwert definiert die erwarteten Mindest- und Höchstwerte der Messwerte während des Zyklus.

In diesem Projekt verwenden wir einen Fotowiderstand und einen passiven Summer, um ein Spiel ähnlich dem `Theremin <https://en.wikipedia.org/wiki/Theremin>`_ unter Verwendung der oben beschriebenen Kalibrierungstechnik zu implementieren.

.. note::
    Das `Theremin <https://en.wikipedia.org/wiki/Theremin>`_ ist ein elektronisches Musikinstrument, das keinen physischen Kontakt erfordert. Es erzeugt unterschiedliche Töne, indem es die Position der Hände des Spielers erfasst.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist sicherlich praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können diese auch separat über die folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Schaltbild**

.. image:: img/circuit_8.8_calibration.png

**Verdrahtung**

.. image:: img/calibration_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.14.calibration.ino`` im Pfad ``3in1-kit\basic_project\5.14.calibration``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/9cbcaae0-3c9d-4e33-9957-548f92a9aab7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nach erfolgreichem Hochladen des Codes leuchtet die LED auf und wir haben 5 Sekunden Zeit, um den Erfassungsbereich des Fotowiderstands zu kalibrieren. Dies liegt daran, dass wir uns jedes Mal in einer anderen Lichtumgebung befinden könnten, wenn wir ihn verwenden (z.B. unterscheidet sich die Lichtintensität zwischen Mittag und Dämmerung).

In dieser Zeit sollten wir unsere Hände über dem Fotowiderstand auf und ab bewegen, und der Bewegungsbereich der Hand wird auf den Spielbereich dieses Instruments kalibriert.

Nach 5 Sekunden erlischt die LED und wir können mit unseren Händen über dem Fotowiderstand schwingen, um zu spielen.




**Wie funktioniert das?**

#. Legen Sie die Anfangswerte und Pins aller Komponenten fest.

    .. code-block:: arduino

        const int buzzerPin = 9;
        const int ledPin = 8;
        const int photocellPin = A0;  // Fotowiderstand ist an A2 angeschlossen

        int lightLow = 1023;
        int lightHigh = 0;

        int sensorValue = 0;        // vom Sensor gelesener Wert
        int pitch = 0;           // Sensorwert in LED-'Balken' umgewandelt

        unsigned long previousMillis = 0;
        const long interval = 5000;

#. Richten Sie einen Kalibrierungsprozess in ``setup()`` ein.

    .. code-block:: arduino

        void setup()
        {
            pinMode(buzzerPin, OUTPUT); // machen Sie alle LED-Pins zu Outputs
            pinMode(ledPin, OUTPUT);    // Den LED-Pin-Ausgang erstellen

            /* kalibriere die Maximal- und Minimalwerte des Fotowiderstands */
            previousMillis = millis();
            digitalWrite(ledPin, HIGH);
            while (millis() - previousMillis <= interval) {
                sensorValue = analogRead(photocellPin);
                if (sensorValue > lightHigh) {
                    lightHigh = sensorValue;
                }
                if (sensorValue < lightLow) {
                    lightLow = sensorValue;
                }
            }
            digitalWrite(ledPin, LOW);
        }

    Der Arbeitsablauf ist wie folgt:

    * Verwendung von ``millis()`` für die Zeitmessung mit einem Intervall von 5000 ms.

    .. code-block:: arduino

        previousMillis = millis();
        ...
        while (millis() - previousMillis <= interval) {
        ...
        }

    * Während dieser fünf Sekunden, bewegen Sie Ihre Hand um den Fotowiderstand. Die maximalen und minimalen Werte des erkannten Lichts werden erfasst und den Variablen ``lightHigh`` und ``lightLow`` entsprechend zugewiesen.

    .. code-block:: arduino
        
        sensorValue = analogRead(photocellPin);
        if (sensorValue > lightHigh) {
            lightHigh = sensorValue;
        }
        if (sensorValue < lightLow) {
            lightLow = sensorValue;
        }

#. Jetzt können Sie dieses Theremin spielen. Lesen Sie den Wert des Fotowiderstands in ``sensorValue`` und übertragen Sie ihn von einem kleinen Bereich in einen großen Bereich, um ihn als Frequenz des Buzzers zu verwenden.

    .. code-block:: arduino

        void loop()
        {
        /* spielen */
        sensorValue = analogRead(photocellPin); // Wert von A0 lesen
        pitch = map(sensorValue, lightLow, lightHigh, 50, 6000);  // auf die Buzzer-Frequenz abbilden
        if (pitch > 50) {
            tone(buzzerPin, pitch, 20);
        }
        delay(10);
        }

