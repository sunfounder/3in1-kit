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

6.4 Einparkhilfe
===================

Mit der Entwicklung von Wissenschaft und Technik wurden viele High-Tech-Produkte in Autos eingebaut, unter denen das Einparkhilfesystem eines der bekanntesten ist. In diesem Projekt nutzen wir ein Ultraschallmodul, LCD, LED und Buzzer, um ein einfaches Ultraschall-Einparkhilfesystem zu erstellen.

**Benötigte Bauteile**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist sicherlich praktisch, ein komplettes Set zu kaufen, hier ist der Link:

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

.. image:: img/backcar.png
    :width: 800
    :align: center

**Code**

.. note::

    * Sie können die Datei ``6.4_reversingAid.ino`` direkt im Pfad ``3in1-kit\basic_project\6.4_reversingAid`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE 1/2.
    * Hier wird die Bibliothek ``LiquidCrystal I2C`` verwendet. Sie können sie aus dem **Library Manager** installieren.

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d6848669-fe79-42e9-afd7-0f083f96a6d6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, wird die aktuell erkannte Entfernung auf dem LCD angezeigt. Der Buzzer wird dann die Klangfrequenz je nach Entfernung ändern.

.. note::
    Wenn der Code und die Verdrahtung korrekt sind, aber das LCD dennoch keinen Inhalt anzeigt, können Sie das Potentiometer auf der Rückseite drehen.

**Wie funktioniert das?**

Dieser Code hilft uns, ein einfaches Entfernungsmessgerät zu erstellen, das die Entfernung zwischen Objekten messen kann und Feedback über ein LCD-Display und einen Summer liefert.

Die Funktion ``loop()`` enthält die Hauptlogik des Programms und läuft kontinuierlich. Schauen wir uns die Funktion ``loop()`` genauer an.

#. Schleife zum Auslesen der Entfernung und Aktualisieren von Parametern

    In der ``loop`` liest der Code zuerst die vom Ultraschallmodul gemessene Entfernung aus und aktualisiert den Intervall-Parameter basierend auf dieser Entfernung.

    .. code-block:: arduino

        // Entfernung aktualisieren
        distance = readDistance();

        // Intervalle basierend auf der Entfernung aktualisieren
        if (distance <= 10) {
            intervals = 300;
        } else if (distance <= 20) {
            intervals = 500;
        } else if (distance <= 50) {
            intervals = 1000;
        } else {
            intervals = 2000;
        }

#. Überprüfen, ob es Zeit für einen Signalton ist

    Der Code berechnet die Differenz zwischen der aktuellen Zeit und der letzten Signalton-Zeit. Wenn die Differenz größer oder gleich der Intervallzeit ist, löst er den Summer aus und aktualisiert die letzte Signalton-Zeit.

    .. code-block:: arduino

        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= intervals) {
            Serial.println("Beeping!");
            beep();
            previousMillis = currentMillis;
        }

#. LCD-Anzeige aktualisieren

    Der Code löscht das LCD-Display und zeigt dann "Dis:" und die aktuelle Entfernung in Zentimetern in der ersten Zeile an.

    .. code-block:: arduino

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dis: ");
        lcd.print(distance);
        lcd.print(" cm");

        delay(100);
