.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_threshold:

5.2 Schwellenwert
=======================

In vielen Projekten werden Sie auf solch ein Bedürfnis stoßen.
"Wenn xxx ein bestimmtes Level erreicht, dann..."

Zum Beispiel in einem Smart Home: Wenn die Lichtintensität unter 50 Lux fällt, schalte das Licht ein;
Ein weiteres Beispiel ist auf dem Computer-Motherboard: Wenn die Betriebstemperatur des CPUs über 65 Grad Celsius steigt, schalte den Lüfter ein, und so weiter.

In diesen Anforderungen spiegelt sich das Schlüsselwort "Schwellenwert" wider.

Wir können den Wert des Schwellenwerts anpassen, um den Schaltkreis besser an individuelle Bedürfnisse anzupassen.
Zum Beispiel: Wenn ich eine hellere Wohnatmosphäre bevorzuge, kann ich den Schwellenwert für das automatische Licht im Smart Home auf 80 Lux erhöhen.
Ein weiteres Beispiel: Das Lüftungsumfeld meines Studios ist nicht sehr gut und der Kühlbedarf höher, dann kann der Schwellenwert für das automatische Lüftereinschalten auf 50 Grad Celsius angepasst werden.

Hier verwenden wir einen Bodenfeuchtigkeitssensor und 2 LEDs, um einen Pflanzentopf-Monitor zu erstellen. Wenn der Boden zu trocken ist, leuchtet die rote LED; wenn der Boden feucht genug ist, leuchtet die grüne LED. Sie müssen die Schwellenwerte manuell anpassen, um die Trockenheit und Feuchtigkeit des Bodens zu bestimmen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schaltplan**

.. image:: img/circuit_8.2_threshold.png

**Verkabelung**

.. image:: img/threshold_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.2.threshold.ino`` unter dem Pfad ``3in1-kit\basic_project\5.2.threshold``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/9936413a-6e6c-4e57-b0c6-5df58dd48a3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, und wenn Ihr Schwellenwert richtig eingestellt ist, wird die rote LED aufleuchten, wenn der Boden trocken ist, um Sie daran zu erinnern, dass Sie gießen müssen; nach dem Gießen wird die grüne LED aufleuchten.

**Wie funktioniert das?**

.. code-block:: Arduino

    ...

    void loop() {
        int sensorValue = analogRead(soilMoisture);
        Serial.println(sensorValue);
        if (sensorValue > threshold) {
            digitalWrite(redPin, HIGH); // Rote LED einschalten
            digitalWrite(greenPin, LOW); // Grün ausschalten
        } else {
            digitalWrite(greenPin, HIGH); // Grüne LED einschalten
            digitalWrite(redPin, LOW); // Rot ausschalten
        }
    }
    ...

Zunächst setzen Sie einen ``Schwellenwert`` und lesen dann den Wert des Bodenfeuchtigkeitsmoduls aus, dessen Wert mit steigendem Feuchtigkeitsgrad abnimmt. Wenn der aktuell gelesene Wert größer als der gesetzte ``Schwellenwert`` ist, lassen Sie die rote LED leuchten, andernfalls schalten Sie die grüne LED ein.

Dieser ``Schwellenwert`` muss je nach tatsächlicher Situation angepasst werden. Sie können zuerst den Code hochladen, dann den seriellen Monitor öffnen, um den Wert zu überprüfen, den Wert in feuchten und trockenen Zuständen aufzeichnen und dann einen Mittelwert als ``Schwellenwert`` wählen.
