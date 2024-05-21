.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_high_tem_alarm:

6.3 Hochtemperaturalarm
====================================

Als Nächstes werden wir mithilfe von Thermistor, Druckknopf, Potentiometer und LCD ein Hochtemperaturalarmgerät bauen.
Das LCD1602 zeigt die vom Thermistor erfasste Temperatur sowie den Hochtemperaturschwellenwert an, 
der mit einem Potentiometer eingestellt werden kann.
Der Schwellenwert wird gleichzeitig auf dem EEPROM gespeichert. Überschreitet die aktuelle Temperatur den Schwellenwert,
ertönt der Summer.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM SET
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
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**Schaltplan**

.. image:: img/wiring_high_tem.png
   :align: center

**Verdrahtung**

.. image:: img/tem_alarm.png
    :width: 800
    :align: center

**Code**

.. note::

    * Sie können die Datei ``6.3.high_tem_alarm.ino`` direkt im Pfad ``3in1-kit\basic_project\6.3.high_tem_alarm`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE 1/2.
    * Hier wird die Bibliothek ``LiquidCrystal I2C`` verwendet. Sie können sie aus dem **Library Manager** installieren.

        .. image:: ../img/lib_liquidcrystal_i2c.png
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1341b79d-c87e-4cea-ad90-189c2ebf40ee/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, zeigt das LCD1602 die vom Thermistor erfasste Temperatur sowie den Hochtemperaturschwellenwert an, der mit einem Potentiometer eingestellt werden kann. Der Schwellenwert wird gleichzeitig auf dem EEPROM gespeichert. Überschreitet die aktuelle Temperatur den Schwellenwert, ertönt der Summer.

.. note::
    Wenn der Code und die Verkabelung korrekt sind, das LCD jedoch immer noch keinen Inhalt anzeigt, können Sie das Potentiometer auf der Rückseite drehen.


**Wie funktioniert das?**

#. Initialisieren Sie den Knopf, den Summer und das I2C LCD1602 und lesen Sie die EEPROM-Werte aus. Hier wird auch ein Interrupt verwendet, um den Status des Knopfes zu lesen.

    .. code-block:: arduino

        void setup()
        {
            pinMode(buzzerPin, OUTPUT);
            pinMode(buttonPin, INPUT);
            lcd.init();
            lcd.backlight();
            upperTem = EEPROM.read(0);
            delay(1000);
            attachInterrupt(digitalPinToInterrupt(buttonPin), buttonState, FALLING);
        }
    
    * Der Interrupt wird hier verwendet, um den Zustand des Knopfes zu lesen. Wenn der Knopf gedrückt wird, wechselt ``buttonPin`` von niedrig auf hoch.
    * Die Funktion buttonState wird aufgerufen, wenn der Interrupt ausgelöst wird, und sie wechselt den Wert der Variable state.
    * ``FALLING`` bedeutet, dass der Interrupt auftritt, wenn ``buttonPin`` von niedrig auf hoch geht.

#. Um den Hochtemperaturschwellenwert festzulegen, wird die Funktion ``upperTemSetting()`` aufgerufen, wenn state 1 ist (state wechselt zwischen 0 und 1 bei Knopfdruck) im Hauptprogramm, ansonsten wird ``monitoringTemp()`` aufgerufen, um die aktuelle Temperatur und den eingestellten Schwellenwert anzuzeigen.

    .. code-block:: arduino

        void loop()
        {
            if (state == 1)
            {
                upperTemSetting();
            }
            else {
                monitoringTemp();
            }
        }

#. Über die Funktion ``upperTemSetting()``.

    .. code-block:: arduino

        void upperTemSetting()
        {
            int setTem = 0;

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Adjusting...");
            lcd.setCursor(0, 1);
            lcd.print("Upper Tem: ");

            while (1) {
                lcd.setCursor(11, 1);
                setTem = map(analogRead(potPin), 0, 1023, 0, 100);
                lcd.print(setTem);
                if (state == 0)
                {
                    EEPROM.write(0, setTem);
                    upperTem = setTem;
                    lcd.clear();
                    return;
                }
            }
        }

    * Mit dieser Funktion kann ein Schwellenwert festgelegt werden. Betreten Sie diese Funktion, zeigt das LCD1602 den aktuellen Schwellenwert an, der mit dem Potentiometer geändert werden kann. Dieser Schwellenwert wird im EEPROM gespeichert und beim erneuten Drücken des Knopfes verlassen.

#. Über die Funktion ``monitoringTemp()``.

    .. code-block:: arduino

        void monitoringTemp()
        {
        long a = analogRead(temPin);
        float tempC = beta / (log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;
        float tempF = 1.8 * tempC + 32.0;
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(tempC);
        lcd.print(char(223));
        lcd.print("C   ");
        lcd.setCursor(0, 1);
        lcd.print("Upper: ");
        lcd.print(upperTem);
        lcd.print(char(223));
        lcd.print("C   ");
        delay(300);
        if (tempC >= upperTem)
        {
            digitalWrite(buzzerPin, HIGH);
            delay(50);
            digitalWrite(buzzerPin, LOW);
            delay(10);
        }
        else
        {
            digitalWrite(buzzerPin, LOW);
        }
        }

    * Mit dieser Funktion können Sie die Temperatur anzeigen und einen Alarm einstellen.
    * Der Wert des Thermistors wird gelesen und dann mittels der Formel in die Celsius-Temperatur umgerechnet und auf dem LCD1602 angezeigt.
    * Der eingestellte Schwellenwert wird ebenfalls auf dem LCD angezeigt.
    * Wenn die aktuelle Temperatur höher als der Schwellenwert ist, gibt der Summer einen Alarm aus.
