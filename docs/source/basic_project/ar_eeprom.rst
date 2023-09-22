.. _ar_74hc_7seg:

5.15 EEPROM
==============

`EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ ist ein Speicher, dessen Daten nicht gelöscht werden, wenn das Hauptsteuerungsboard ausgeschaltet wird. Sie können es verwenden, um einige Daten zu speichern und diese beim nächsten Einschalten wieder abzurufen.

Als Beispiel könnten Sie einen Sportzähler erstellen, der verfolgt, wie oft Sie täglich Seil springen.

Sie können auch in einem Programm Daten darauf schreiben und in einem anderen Programm daraus lesen. Wenn Sie beispielsweise an einem Autoprojekt arbeiten und die Geschwindigkeiten der beiden Motoren nicht übereinstimmen, können Sie ein Kalibrierungsprogramm schreiben, um den Kompensationswert der Motorgeschwindigkeit zu speichern.

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

.. image:: img/eeprom_servo.png

**Code**

.. note::

    * Öffnen Sie die Datei ``5.15.eeproom.ino`` im Pfad ``3in1-kit\basic_project\5.15.eeproom``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7378341f-9c1a-4171-814f-c76c109e1e67/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Um diese Schaltung zu verwenden, drücken Sie einfach den Knopf, um die Aufnahme zu starten, und geben die gewünschten Informationen über ein Potentiometer ein. Nun wird das Board Ihre Aktionen endlos wiederholen (und bei jeder Iteration blinkt eine LED), bis Sie den Knopf erneut drücken, um neue Aktionen aufzunehmen. Sie können auch die Aufnahmezeit variieren, indem Sie die Werte von Auflösung und Aufnahmezeit ändern.



**Wie funktioniert das?**

#. Importieren Sie die Bibliothek ``EEPROM.h`` und initialisieren Sie den EEPROM-Speicher.

    .. code-block:: arduino

        ...
        #include <EEPROM.h>//wird verwendet, um aufgezeichnete Werte zu speichern

        ...
        float resolution = 1000;//MUSS kleiner sein als EEPROM.length()
        float recordTime = 5; //Verzögerungszeit
        bool recording = false;
        ...
    
    Beachten Sie, dass ``/MUST kleiner sein als EEPROM.length()``, in ``setup()`` wird der Speicher Ihres Boards EEPROM angezeigt, welcher für das SunFounder R3 Board 1024 sein sollte. Wenn Sie ein anderes Board verwenden, können Sie den Wert der Variable ``resolution`` anpassen.

#. Zeigen Sie den EEPROM-Speicher Ihres Boards an.

    .. code-block:: arduino

        void setup() {
            ...
            Serial.begin(9600);
            //Serial.println(EEPROM.length());
        }

    Um die Größe des EEPROM-Speichers Ihres Boards zu ermitteln, kommentieren Sie die Zeile ``Serial.println(EEPROM.read(i))`` aus. Dies wird die Größe des EEPROM im seriellen Monitor anzeigen, und Sie können den Wert der Variable ``resolution`` entsprechend ändern.

#. Sobald ein Tastendruck erkannt wird, beginnt die Aufzeichnung und die erforderlichen Informationen werden über ein Potentiometer eingegeben. Jetzt wiederholt das Board Ihre Aktion endlos (und eine LED blinkt bei jeder Wiederholung), bis Sie die Taste erneut drücken und eine neue Aktion aufzeichnen.

    .. code-block:: arduino

        void loop() {
            if (recording == true) {//aufzeichnen
                for (int i = 1; i <= resolution; i++) {
                    digitalWrite(ledPin, HIGH); //Lichtstatus-LED
                    int val = map(analogRead(A0), 0, 1023, 0, 180);
                    EEPROM.write(i, val);
                    //Serial.println(EEPROM.read(i));
                    myServo.write(val);
                    delay(recordTime);
                }
                digitalWrite(ledPin, LOW); //Status-LED ausschalten
                delay(1000);//Zeit für den Menschen geben
                recording = false;
            }
            else {
                for (int i = 1; i <= resolution; i++) {//Wiedergabe
                    if (digitalRead(buttonPin) == 0) {//Stoppen Sie die Wiedergabe und zeichnen Sie neue Werte auf
                        recording = true;
                        break;
                    }
                    int readval = EEPROM.read(i);
                    myServo.write(readval);
                    //Serial.println(readval);
                    delay(recordTime);
                }
                digitalWrite(ledPin, HIGH); //eine neue Wiederholung anzeigen
                delay(100);
                digitalWrite(ledPin, LOW);
            }
        }

    * Setzen Sie die Variable ``recording`` auf true, wenn die Taste gedrückt wird.
    * Wenn die Variable ``recording`` true ist, beginnen Sie mit der Aufzeichnung der Aktion im Speicherbereich.
    * Lesen Sie den Wert des Potentiometers und mappen Sie ihn auf 0-180, um ihn im EEPROM zu speichern und die Drehung des Servos zu steuern.
    * Die LED leuchtet zu Beginn der Aufzeichnung und erlischt am Ende.
    * Wiederholen Sie die aufgezeichnete Aktion mit einem kurzen Aufleuchten der LED, um Sie an eine neue Wiederholung zu erinnern.

#. Über die ``EEPROM``-Bibliothek.

    Hier sind einige ihrer Funktionen.

    * ``write(address,value)``: Schreibt ein Byte in das EEPROM.

        * ``address``: die Adresse, an die geschrieben werden soll, beginnend bei 0 (int)
        * ``value``: der zu schreibende Wert, von 0 bis 255 (byte)
        * Ein EEPROM-Schreibvorgang dauert 3,3 ms. Der EEPROM-Speicher hat eine angegebene Lebensdauer von 100.000 Schreib-/Löschzyklen, daher sollten Sie vorsichtig sein, wie oft Sie darauf schreiben.

    * ``Read(address)``: Liest ein Byte aus dem EEPROM. Orte, die noch nie beschrieben wurden, haben den Wert 255.

    * ``update(address,value)``: Schreibt ein Byte in das EEPROM. Der Wert wird nur geschrieben, wenn er sich von dem bereits an derselben Adresse gespeicherten unterscheidet.

        * Ein EEPROM-Schreibvorgang dauert 3,3 ms. Der EEPROM-Speicher hat eine angegebene Lebensdauer von 100.000 Schreib-/Löschzyklen, daher kann die Verwendung dieser Funktion anstelle von write() Zyklen sparen, wenn die geschriebenen Daten sich nicht oft ändern.

    * ``EEPROM.put(address, data)``: Schreibt jeden Datentyp oder jedes Objekt in das EEPROM.

        * ``address``: die Adresse, von der gelesen werden soll, beginnend bei 0 (int).
        * ``data``: die zu lesenden Daten, können ein primitiver Typ (z. B. float) oder eine benutzerdefinierte Struktur sein.
        * Diese Funktion verwendet EEPROM.update(), um den Schreibvorgang auszuführen, schreibt also den Wert nicht erneut, wenn er sich nicht geändert hat.

    * ``EEPROM.get(address, data)``: Liest jeden Datentyp oder jedes Objekt aus dem EEPROM.

        * ``address``: die Adresse, von der gelesen werden soll, beginnend bei 0 (int).
        * ``data``: die zu lesenden Daten, können ein primitiver Typ (z. B. float) oder eine benutzerdefinierte Struktur sein.



