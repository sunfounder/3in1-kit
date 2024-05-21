.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_74hc_7seg:

5.15 EEPROM
==============

`EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ ist ein Speicher, sodass die darin gespeicherten Daten nicht gelöscht werden, wenn das Hauptsteuerbrett ausgeschaltet wird. Sie können es verwenden, um einige Daten zu speichern und diese beim nächsten Einschalten wieder auszulesen.

Als Beispiel könnten Sie einen Sportzähler erstellen, der aufzeichnet, wie viele Seilsprünge Sie täglich machen.

Sie können auch Daten in einem Programm schreiben und sie in einem anderen auslesen. Wenn Sie zum Beispiel an einem Auto-Projekt arbeiten und die Geschwindigkeiten der beiden Motoren nicht übereinstimmen, können Sie ein Kalibrierungsprogramm schreiben, um den Ausgleichswert für die Motorgeschwindigkeit zu speichern.

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

Sie können sie auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**Schaltplan**

.. image:: img/circuit_515_eeprom.png

**Verdrahtung**

.. image:: img/5.15_eeprom_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``5.15.eeproom.ino`` im Pfad ``3in1-kit\learning_project\5.15.eeproom``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7378341f-9c1a-4171-814f-c76c109e1e67/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Um diesen Schaltkreis zu verwenden, drücken Sie einfach den Knopf, um die Aufnahme zu starten, und geben die gewünschten Informationen über ein Potentiometer ein. Das Board wird nun Ihre Aktionen endlos wiederholen (und bei jeder Wiederholung blinkt eine LED), bis Sie den Knopf erneut drücken, um neue Aktionen aufzunehmen. Sie können auch die Aufnahmezeit ändern, indem Sie die Werte von resolution und recordTime ändern.

**Wie funktioniert das?**

#. Importieren Sie die ``EEPROM.h`` Bibliothek und initialisieren Sie den EEPROM-Speicher.

    .. code-block:: arduino

        ...
        #include <EEPROM.h>//used to store recorded values

        ...
        float resolution = 1000;//MUST be less than EEPROM.length()
        float recordTime = 5; //delay time
        bool recording = false;
        ...
    
    Bitte beachten Sie, dass ``/MUST be less than EEPROM.length()``, in ``setup()`` wird der Speicher Ihres Board-EEPROMs ausgedruckt, welcher für Ihr Board 1024 sein sollte. Wenn Sie ein anderes Board verwenden, können Sie den Wert der Variable ``resolution`` ändern.


#. Das EEPROM-Speicher Ihres Boards ausdrucken.

    .. code-block:: arduino

        void setup() {
            ...
            Serial.begin(9600);
            //Serial.println(EEPROM.length());
        }

    Um die Größe des EEPROM-Speichers Ihres Boards herauszufinden, kommentieren Sie die Zeile ``Serial.println(EEPROM.read(i))`` aus. Dies wird die Größe des EEPROM im seriellen Monitor ausgeben, und Sie können den Wert der Variable ``resolution`` entsprechend ändern.

#. Sobald ein Tastendruck erkannt wird, beginnt die Aufzeichnung und die benötigten Informationen werden über ein Potentiometer eingegeben. Nun wiederholt das Board Ihre Aktion endlos (und blinkt bei jeder Wiederholung eine LED) bis Sie die Taste erneut drücken, um eine neue Aktion aufzuzeichnen.

    .. code-block:: arduino

        void loop() {
            if (recording == true) {//record
                for (int i = 1; i <= resolution; i++) {
                    digitalWrite(ledPin, HIGH); //light status led
                    int val = map(analogRead(A0), 0, 1023, 0, 180);
                    EEPROM.write(i, val);
                    //Serial.println(EEPROM.read(i));
                    myServo.write(val);
                    delay(recordTime);
                }
                digitalWrite(ledPin, LOW); //turn off status led
                delay(1000);//give time for person
                recording = false;
            }
            else {
                for (int i = 1; i <= resolution; i++) {//playback
                    if (digitalRead(buttonPin) == 0) {//stop playback and record new values
                        recording = true;
                        break;
                    }
                    int readval = EEPROM.read(i);
                    myServo.write(readval);
                    //Serial.println(readval);
                    delay(recordTime);
                }
                digitalWrite(ledPin, HIGH); //show a new repeat
                delay(100);
                digitalWrite(ledPin, LOW);
            }
        }

    * Die Variable ``recording`` auf true setzen, wenn die Taste gedrückt wird.
    * Wenn die Variable ``recording`` true ist, beginnt die Aufzeichnung im Speicherbereich.
    * Den Wert des Potentiometers auslesen und auf 0-180 mappen, um ihn im EEPROM zu speichern und die Drehung des Servos zu steuern.
    * Die LED leuchtet zu Beginn der Aufzeichnung und erlischt am Ende.
    * Die aufgezeichnete Aktion mit einem kurzen Blinken der LED wiederholen, um Sie an eine neue Wiederholung zu erinnern.

#. Über die ``EEPROM``-Bibliothek.

    Hier sind einige ihrer Funktionen.

    * ``write(address,value)``: Schreibt ein Byte ins EEPROM.

        * ``address``: der Ort, an den geschrieben werden soll, beginnend bei 0 (int)
        * ``value``: der zu schreibende Wert, von 0 bis 255 (Byte)
        * Ein EEPROM-Schreibvorgang dauert 3,3 ms. Das EEPROM hat eine angegebene Lebensdauer von 100.000 Schreib-/Löschzyklen, daher sollten Sie vorsichtig sein, wie oft Sie darauf schreiben.

    * ``Read(address)``: Liest ein Byte aus dem EEPROM. Orte, die noch nie beschrieben wurden, haben den Wert 255.

    * ``update(address,value)``: Schreibt ein Byte ins EEPROM. Der Wert wird nur geschrieben, wenn er sich von dem bereits unter der gleichen Adresse gespeicherten unterscheidet.

        * Ein EEPROM-Schreibvorgang dauert 3,3 ms. Da das EEPROM eine Lebensdauer von 100.000 Schreib-/Löschzyklen hat, kann die Verwendung dieser Funktion anstelle von write() Zyklen sparen, wenn die geschriebenen Daten sich nicht oft ändern.

    * ``EEPROM.put(address, data)``: Schreibt jeden Datentyp oder jedes Objekt ins EEPROM.

        * ``address``: der Ort, von dem gelesen werden soll, beginnend bei 0 (int)
        * ``data``: die zu lesenden Daten, kann ein einfacher Typ (z. B. float) oder eine benutzerdefinierte Struktur sein.
        * Diese Funktion verwendet EEPROM.update(), um den Schreibvorgang durchzuführen, schreibt also den Wert nicht erneut, wenn er sich nicht geändert hat.

    * ``EEPROM.get(address, data)``: Liest jeden Datentyp oder jedes Objekt aus dem EEPROM.

        * ``address``: der Ort, von dem gelesen werden soll, beginnend bei 0 (int)
        * ``data``: die zu lesenden Daten, kann ein einfacher Typ (z. B. float) oder eine benutzerdefinierte Struktur sein.



