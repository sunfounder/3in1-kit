.. _ar_calibration:

5.14 Kalibrierung
==========================

Wenn Sie analoge Eingangskomponenten verwenden, wie Fotowiderstände, Bodenfeuchtigkeitssensoren usw., stellen Sie möglicherweise fest, dass deren Messbereich nicht 0 bis 1023 beträgt, sondern eher ein Bereich wie 0 bis 800 oder 600 bis 1000. Denn unter normalen Bedingungen ist es unmöglich, die Grenzen dieser Geräte zu erreichen.

In diesem Fall kann eine Technik zur Kalibrierung der Sensoreingänge verwendet werden. Beim Start sollte das Steuerboard den Sensor fünf Sekunden lang messen und die höchsten und niedrigsten Werte aufzeichnen. Diese fünfsekündige Messung definiert die minimalen und maximalen erwarteten Werte der Messungen im Zyklus.

In diesem Projekt verwenden wir einen Fotowiderstand und einen passiven Summer, um ein Spiel zu implementieren, das einem `theremin <https://en.wikipedia.org/wiki/Theremin>`_ ähnelt, unter Verwendung der oben beschriebenen Kalibrierungstechnik.

.. note::
    Das `theremin <https://en.wikipedia.org/wiki/Theremin>`_ ist ein elektronisches Musikinstrument, das keinen physischen Kontakt erfordert. Es erzeugt verschiedene Töne, indem es die Position der Hände des Spielers erkennt.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

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
        - \-
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

**Schaltplan**

.. image:: img/circuit_8.8_calibration.png

**Verdrahtung**

.. image:: img/5.14_calibration_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.14.calibration.ino`` unter dem Pfad ``3in1-kit\learning_project\5.14.calibration``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/9cbcaae0-3c9d-4e33-9957-548f92a9aab7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, leuchtet die LED auf und wir haben 5 Sekunden Zeit, um den Erfassungsbereich des Fotowiderstands zu kalibrieren. Dies liegt daran, dass wir uns jedes Mal in einer anderen Lichtumgebung befinden könnten, wenn wir ihn verwenden (z.B. unterscheidet sich die Lichtintensität zwischen Mittag und Dämmerung).

Zu diesem Zeitpunkt müssen wir unsere Hände über dem Fotowiderstand auf und ab schwingen, und der Bewegungsbereich der Hand wird auf den Spielbereich dieses Instruments kalibriert.

Nach 5 Sekunden erlischt die LED und wir können unsere Hände über den Fotowiderstand schwingen, um zu spielen.




**Wie funktioniert das?**

#. Initialwerte und Pins aller Komponenten festlegen.

    .. code-block:: arduino

        const int buzzerPin = 9;
        const int ledPin = 8;
        const int photocellPin = A0;  //photoresistor attach to A2
    
        int lightLow = 1023;
        int lightHigh = 0;
    
        int sensorValue = 0;        // value read from the sensor
        int pitch = 0;           // sensor value converted into LED 'bars'
    
        unsigned long previousMillis = 0;
        const long interval = 5000;

#. Ein Kalibrierungsprozess in ``setup()`` einrichten.

    .. code-block:: arduino

        void setup()
        {
            pinMode(buzzerPin, OUTPUT); // make buzzer output
            pinMode(ledPin, OUTPUT); // make the LED pin output

            /* calibrate the photoresistor max & min values */
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

    Der Ablauf ist wie folgt:

    * Verwendung von ``millis()`` zur Zeitmessung mit einem Intervall von 5000ms.

    .. code-block:: arduino

        previousMillis = millis();
        ...
        while (millis() - previousMillis <= interval) {
        ...
        }

    * Während dieser fünf Sekunden wird mit der Hand um den Fotowiderstand gewedelt, die maximalen und minimalen Werte des erkannten Lichts werden erfasst und den Variablen ``lightHigh`` und ``lightLow`` zugewiesen.

    .. code-block:: arduino
        
        sensorValue = analogRead(photocellPin);
        if (sensorValue > lightHigh) {
            lightHigh = sensorValue;
        }
        if (sensorValue < lightLow) {
            lightLow = sensorValue;
        }

#. Nun können Sie dieses Theremin spielen. Lesen Sie den Wert des Fotowiderstands in ``sensorValue`` und übertragen Sie ihn aus dem kleinen Bereich in den großen Bereich, um ihn als Frequenz des Summers zu verwenden. 

    .. code-block:: arduino

        void loop()
        {
        /* play*/
        sensorValue = analogRead(photocellPin); //read the value of A0
        pitch = map(sensorValue, lightLow, lightHigh, 50, 6000);  // map to the buzzer frequency
        if (pitch > 50) {
            tone(buzzerPin, pitch, 20);
        }
        delay(10);
        }

