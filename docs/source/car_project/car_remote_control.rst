.. _car_remote:

9. Fernbedienung
=================================

Dieses Kit wird mit einem IR-Empfänger geliefert, mit dem Sie ein Auto mithilfe einer IR-Fernbedienung steuern können.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist sicherlich praktisch, ein komplettes Kit zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3-in-1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENVORSTELLUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_receiver`
        - \-

**Verdrahtung**

Bauen Sie jetzt den Schaltkreis gemäß dem untenstehenden Diagramm.

.. list-table:: 
    :header-rows: 1

    * - IR-Empfänger
      - R3 Platine
    * - OUT
      - 12
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - LED
      - R3 Platine
    * - Anode (Der längere Pin)
      - 13
    * - Kathode
      - GND

.. image:: img/car_9.png
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``9.remote_control.ino`` im Pfad ``3in1-kit\car_project\9.remote_control``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Hier wird die Bibliothek ``IRremote`` verwendet. Sie können sie über den **Library Manager** installieren.
  
        .. image:: ../img/lib_irremote.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/7c78450d-fcd2-4288-a00d-499c71ad2d52/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, drücken Sie die Taste auf der Fernbedienung. Die LED blinkt einmal, um anzuzeigen, dass das Signal empfangen wurde, und das Auto bewegt sich entsprechend der gedrückten Taste. Sie können die folgenden Tasten verwenden, um das Auto zu steuern.

* **+**: Beschleunigen
* **-**: Verlangsamen
* **1**: Vorwärts nach links
* **2**: Vorwärts
* **3**: Vorwärts nach rechts
* **4**: Links abbiegen
* **6**: Rechts abbiegen
* **7**: Rückwärts nach links
* **8**: Rückwärts
* **9**: Rückwärts nach rechts

**Wie funktioniert es?**

Das Ziel dieses Projekts ist es, das Auto durch Auslesen des Tastenwerts der IR-Fernbedienung zu bewegen. Zusätzlich wird eine LED hinzugefügt, um anzuzeigen, dass das IR-Signal erfolgreich empfangen wurde.

#. Importieren Sie die Bibliothek ``IRremote``. Sie können diese aus dem **Library Manager** installieren.

    .. code-block:: arduino

        #include <IRremote.h>

        const int IR_RECEIVE_PIN = 12;  // Define the pin number for the IR Sensor
        String lastDecodedValue = "";   // Variable to store the last decoded value

#. Initialisieren Sie den IR-Empfänger und die LED.

    .. code-block:: arduino

        ...
        const int ledPin = 13;
        ...

        void setup() {

            ...
            //IR remote
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver // Start the receiver
            Serial.println("REMOTE CONTROL START");

            //LED
            pinMode(ledPin, OUTPUT);
        }

#. Wenn Sie die Tasten auf der Fernbedienung drücken, blinkt die LED und der Infrarotempfänger erkennt, welche Taste gedrückt wurde. Anschließend bewegt sich das Auto entsprechend dem zugehörigen Tastenwert.

    .. code-block:: arduino

        void loop() {

            if (IrReceiver.decode()) {
                //    Serial.println(results.value,HEX);
                String key = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (key != "ERROR" && key != lastDecodedValue) {
                    Serial.println(key);
                    lastDecodedValue = key;  // Update the last decoded value
                    blinkLED();

                    if (key == "+") {
                        speed += 50;
                    } else if (key == "-") {
                        speed -= 50;
                    } else if (key == "2") {
                        moveForward(speed);
                        delay(1000);
                    ...
                    }
                    IrReceiver.resume();  // Enable receiving of the next value

            }
        }

    * Überprüft, ob ein IR-Signal empfangen und erfolgreich decodiert wurde.
    * Decodiert den IR-Befehl und speichert ihn in ``key`` mit einer benutzerdefinierten Funktion ``decodeKeyValue()``.
    * Überprüft, ob der decodierte Wert kein Fehler ist und sich von dem zuletzt decodierten Wert unterscheidet.
    * Gibt den decodierten IR-Wert auf dem seriellen Monitor aus.
    * Aktualisiert ``lastDecodedValue`` mit dem neuen decodierten Wert.
    * Setzt den IR-Signalempfang für das nächste Signal fort.

#. Über die Funktion ``blinkLED()``.

    Wenn diese Funktion aufgerufen wird, sollte die LED dreimal blinken.

    .. code-block:: arduino

        void blinkLED() {
                for (int i = 0; i < 3; i++) {
                digitalWrite(ledPin, HIGH);
                delay(50);
                digitalWrite(ledPin, LOW);
                delay(50);
            }
        }

