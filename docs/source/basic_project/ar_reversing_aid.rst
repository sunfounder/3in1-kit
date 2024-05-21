.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_reversing_aid:

6.4 Rückwärts-Hilfssystem
=============================

Mit dem Fortschritt von Wissenschaft und Technologie wurden viele Hightech-Produkte in Autos eingebaut. Eines davon ist das Rückwärts-Hilfssystem. In diesem Projekt verwenden wir ein Ultraschallmodul, LCD, LED und Buzzer, um ein einfaches ultraschallbasiertes Rückwärts-Hilfssystem zu erstellen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist sicherlich praktisch, ein ganzes Set zu kaufen, hier der Link:

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
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Schaltplan**

.. image:: img/image265.png
    :width: 800
    :align: center

**Verdrahtung**

.. image:: img/6.4_reversing_aid_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Sie können die Datei ``6.4_reversingAid.ino`` direkt im Pfad ``3in1-kit\learning_project\6.4_reversingAid`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.
    * Die Bibliothek ``LiquidCrystal I2C`` wird hier verwendet. Sie können diese aus dem **Library Manager** installieren.

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d6848669-fe79-42e9-afd7-0f083f96a6d6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, wird die aktuell erkannte Entfernung auf dem LCD angezeigt. Der Buzzer ändert dann die Tonfrequenz je nach Entfernung.

.. note::
    Wenn Code und Verkabelung in Ordnung sind, das LCD aber dennoch keinen Inhalt anzeigt, können Sie das Potentiometer auf der Rückseite drehen.

**Wie funktioniert das?**

Dieser Code hilft uns, ein einfaches Entfernungsmessgerät zu erstellen, das die Entfernung zwischen Objekten messen und Feedback über ein LCD-Display und einen Buzzer geben kann.

Die ``loop()``-Funktion enthält die Hauptlogik des Programms und läuft kontinuierlich. Werfen wir einen genaueren Blick auf die ``loop()``-Funktion.

#. Schleife zum Lesen der Entfernung und Aktualisieren von Parametern

    In der ``loop`` liest der Code zuerst die vom Ultraschallmodul gemessene Entfernung und aktualisiert den Intervall-Parameter basierend auf der Entfernung.

    .. code-block:: arduino

        // Update the distance
        distance = readDistance();

        // Update intervals based on distance
        if (distance <= 10) {
            intervals = 300;
        } else if (distance <= 20) {
            intervals = 500;
        } else if (distance <= 50) {
            intervals = 1000;
        } else {
            intervals = 2000;
        }

#. Überprüfen, ob es Zeit zum Piepen ist

    Der Code berechnet den Unterschied zwischen der aktuellen Zeit und der vorherigen Piep-Zeit. Wenn der Unterschied größer oder gleich der Intervall-Zeit ist, löst er den Buzzer aus und aktualisiert die vorherige Piep-Zeit.

    .. code-block:: arduino

        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= intervals) {
            Serial.println("Beeping!");
            beep();
            previousMillis = currentMillis;
        }

#. LCD-Display aktualisieren

    Der Code löscht das LCD-Display und zeigt dann "Dis:" und die aktuelle Entfernung in Zentimetern auf der ersten Zeile an.


    .. code-block:: arduino

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dis: ");
        lcd.print(distance);
        lcd.print(" cm");

        delay(100);
