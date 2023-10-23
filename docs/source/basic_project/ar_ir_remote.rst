.. _ar_receiver:

5.11.2 IR-Empfänger
=========================

In diesem Projekt lernen Sie die Verwendung eines IR-Empfängers kennen.

Ein Infrarot-Empfänger ist eine Komponente, die Infrarotsignale empfängt und in der Lage ist, Infrarotstrahlen unabhängig zu empfangen und Signale auszugeben, die mit dem TTL-Niveau kompatibel sind. 
Er hat ungefähr die Größe eines gewöhnlichen Transistors in Plastikverpackung und eignet sich für alle Arten von Infrarot-Fernbedienungen und Infrarotübertragungen.

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

Sie können diese auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_receiver`
        - \-

**Schaltplan**

.. image:: img/circuit_7.2_receiver.png

**Verdrahtung**

In diesem Beispiel verbinden wir den linken Pin des IR-Empfängers mit Pin 11, 
den mittleren Pin mit GND und den rechten Pin mit 5V.

.. image:: img/5.11_ir_recv_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``5.11.ir_receiver.ino`` im Pfad ``3in1-kit\learning_project\5.11.ir_receiver``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Hier wird die Bibliothek ``IRremote`` verwendet. Sie können sie über den **Library Manager** installieren.
  
        .. image:: ../img/lib_irremote.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1141d808-cc26-4589-ae5c-d1834033ac3d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Nachdem Sie die Codes auf das R4-Board hochgeladen haben, können Sie sehen, dass 
der aktuelle Wert der gedrückten Taste der IR-Fernbedienung im Serienmonitor angezeigt wird.

**Wie funktioniert das?**

Dieser Code ist so konzipiert, dass er mit einer Infrarot-(IR-)Fernbedienung zusammen mit der ``IRremote``-Bibliothek funktioniert. Hier die Erklärung:

#. Bibliotheken einbinden: Hier wird die ``IRremote``-Bibliothek eingebunden, die Funktionen zur Arbeit mit IR-Fernbedienungen bietet.

    .. code-block:: arduino

        #include <IRremote.h>

#. Definiert den Arduino-Pin, an den der Signalpin des IR-Sensors angeschlossen ist, und deklariert eine Variable, um den zuletzt dekodierten IR-Wert zu speichern.

    .. code-block:: arduino

        const int IR_RECEIVE_PIN = 11;  // Define the pin number for the IR Sensor

#. Initialisiert die serielle Kommunikation mit einer Baudrate von 9600. Startet den IR-Empfänger am angegebenen Pin (``IR_RECEIVE_PIN``) und aktiviert die LED-Rückmeldung (falls zutreffend).

    .. code-block:: arduino

        void setup() {
            Serial.begin(9600);                                     // Start serial communication at 9600 baud rate
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver
        }

#. Die Schleife läuft kontinuierlich ab, um eingehende IR-Fernbedienungssignale zu verarbeiten.

    .. code-block:: arduino

        void loop() {
            if (IrReceiver.decode()) {
                String decodedValue = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (decodedValue != "ERROR") {
                    Serial.println(decodedValue);
                    delay(100);
                }
                IrReceiver.resume();  // Enable receiving of the next value
            }
        }
    
    * Überprüft, ob ein IR-Signal empfangen und erfolgreich dekodiert wurde.
    * Dekodiert den IR-Befehl und speichert ihn in ``decodedValue`` mit Hilfe einer benutzerdefinierten Funktion ``decodeKeyValue()``.
    * Überprüft, ob der dekodierte Wert kein Fehler ist.
    * Gibt den dekodierten IR-Wert auf dem seriellen Monitor aus.
    * Setzt den IR-Signalempfang für das nächste Signal fort.
