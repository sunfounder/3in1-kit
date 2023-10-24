.. _car_remote:

9. Fernsteuerung
=================================

Dieses Set wird mit einem IR-Empfänger geliefert, der es ermöglicht, das Fahrzeug mit einer IR-Fernbedienung zu steuern.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen. Hier ist der Link:

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
    *   - :ref:`cpn_l298n`
        - |link_l298n_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_receiver`
        - \-

**Verdrahtung**

Bauen Sie den Schaltkreis nun gemäß dem untenstehenden Diagramm.

.. list-table:: 
    :header-rows: 1

    * - IR-Empfänger
      - R3-Board
    * - OUT
      - 12
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - LED
      - R3-Board
    * - Anode(Der längere Pin)
      - 13
    * - Kathode
      - GND

.. image:: img/car_remote.png
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``9.remote_control.ino`` im Pfad ``3in1-kit\car_project\9.remote_control``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Die Bibliothek ``IRremote`` wird hier verwendet. Sie können sie über den **Library Manager** installieren.
    
        .. image:: ../img/lib_irremote.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/b5d87f03-c8e9-49de-a6d1-3b51036e1f5c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, drücken Sie eine Taste auf der Fernbedienung. Die LED blinkt einmal, um anzuzeigen, dass das Signal empfangen wurde, und das Auto bewegt sich entsprechend der gedrückten Taste. Sie können die folgenden Tasten verwenden, um das Auto zu steuern:

* **+**: Beschleunigen
* **-**: Verlangsamen
* **1**: Vorwärts links
* **2**: Vorwärts
* **3**: Vorwärts rechts
* **4**: Nach links drehen
* **6**: Nach rechts drehen
* **7**: Rückwärts links
* **8**: Rückwärts
* **9**: Rückwärts rechts



**Wie funktioniert das?**

Das Ziel dieses Projekts ist es, das Auto durch Lesen des Schlüsselwerts der IR-Fernbedienung zu bewegen. Zusätzlich wird die LED an Pin 13 blinken, um den erfolgreichen Empfang des IR-Signals anzuzeigen.

#. Importieren Sie die ``IRremote``-Bibliothek. Sie können sie über den **Library Manager** installieren.

    .. code-block:: arduino

        #include <IRremote.h>

        const int IR_RECEIVE_PIN = 12;  // Definiere die Pin-Nummer für den IR-Sensor

#. Initialisiert die serielle Kommunikation mit einer Baudrate von 9600. Initialisiert den IR-Empfänger am angegebenen Pin (``IR_RECEIVE_PIN``) und aktiviert die LED-Rückmeldung (falls zutreffend).


    .. code-block:: arduino

        ...

        void setup() {

            ...
            //IR-Fernbedienung
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Starten Sie den IR-Empfänger
            Serial.println("REMOTE CONTROL START");
        }

#. Wenn Sie die Tasten auf der Fernbedienung drücken, der Infrarot-Empfänger erkennt, welche Taste gedrückt wurde. Anschließend bewegt sich das Auto entsprechend dem zugehörigen Schlüsselwert.

    .. code-block:: arduino

        void loop() {

            if (IrReceiver.decode()) {
                //    Serial.println(results.value,HEX);
                String key = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (key != "ERROR") {
                    Serial.println(key);

                    if (key == "+") {
                        speed += 50;
                    } else if (key == "-") {
                        speed -= 50;
                    } else if (key == "2") {
                        moveForward(speed);
                        delay(1000);
                    ...
                    }
                    IrReceiver.resume();  // Empfang des nächsten Werts ermöglichen

            }
        }

    * Überprüft, ob ein IR-Signal empfangen und erfolgreich dekodiert wurde.
    * Dekodiert den IR-Befehl und speichert ihn in ``key`` mit einer benutzerdefinierten Funktion ``decodeKeyValue()``.
    * Überprüft, ob der dekodierte Wert kein Fehler ist.
    * Gibt den dekodierten IR-Wert auf dem seriellen Monitor aus.
    * Setzt den IR-Signalempfang für das nächste Signal fort.

