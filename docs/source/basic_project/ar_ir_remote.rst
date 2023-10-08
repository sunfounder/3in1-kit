.. _ar_receiver:

5.11.2 IR-Empfänger
=========================

In diesem Projekt lernen Sie, wie Sie einen IR-Empfänger verwenden.

Ein Infrarot-Empfänger ist eine Komponente, die Infrarotsignale empfängt. Er kann Infrarotstrahlen eigenständig empfangen und Signale ausgeben, die mit dem TTL-Level kompatibel sind. 
Er ähnelt von der Größe her einem normal verpackten Transistor und eignet sich für alle Arten von Infrarot-Fernbedienungen und Infrarotübertragungen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können diese auch separat über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_receiver`
        - \-

**Schaltplan**

.. image:: img/circuit_7.2_receiver.png

**Verkabelung**

In diesem Beispiel verbinden wir den linken Pin des IR-Empfängers mit Pin 11,
den mittleren Pin mit GND und den rechten Pin mit 5V.

.. image:: img/ir_remote_control_bb.jpg

**Code**

.. note::

    * Öffnen Sie die Datei ``5.11.ir_receiver.ino`` unter dem Pfad ``3in1-kit\basic_project\5.11.ir_receiver``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Hier wird die Bibliothek ``IRremote`` verwendet. Sie können sie über den **Library Manager** installieren.
  
        .. image:: ../img/lib_irremote.png


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1141d808-cc26-4589-ae5c-d1834033ac3d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem Sie die Codes auf das R3-Board hochgeladen haben, können Sie den
aktuellen Wert der gedrückten Taste der IR-Fernbedienung auf dem
Seriellen Monitor anzeigen lassen.

**Wie funktioniert das?**

Dieser Code ist für die Verwendung mit einer Infrarot (IR) Fernbedienung und der ``IRremote`` Bibliothek entwickelt. Hier ist die Erklärung:

#. Einbindung von Bibliotheken: Dies beinhaltet die ``IRremote`` Bibliothek, welche Funktionen zur Arbeit mit IR-Fernbedienungen bereitstellt.

    .. code-block:: arduino

        #include <IRremote.h>

#. Definiert den Arduino-Pin, an den der Signal-Pin des IR-Sensors angeschlossen ist, und deklariert eine Variable zur Speicherung des zuletzt decodierten IR-Wertes.

    .. code-block:: arduino

        const int IR_RECEIVE_PIN = 11;  // Pinnummer für den IR-Sensor definieren
        String lastDecodedValue = "";  // Variable zum Speichern des zuletzt decodierten Wertes

#. Initialisiert die serielle Kommunikation mit einer Baudrate von 9600. Initialisiert den IR-Empfänger am angegebenen Pin (``IR_RECEIVE_PIN``) und aktiviert die LED-Rückmeldung (falls zutreffend).

    .. code-block:: arduino

        void setup() {
            Serial.begin(9600);                                     // Serielle Kommunikation mit 9600 Baudrate starten
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // IR-Empfänger starten

#. Die Schleife läuft kontinuierlich, um eingehende IR-Fernbedienungssignale zu verarbeiten.

    .. code-block:: arduino

        void loop() {
            if (IrReceiver.decode()) {
                String decodedValue = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (decodedValue != "ERROR" && decodedValue != lastDecodedValue) {
                    Serial.println(decodedValue);
                    lastDecodedValue = decodedValue;  // Aktualisiert den zuletzt decodierten Wert
                }
                IrReceiver.resume();  // Empfang des nächsten Wertes ermöglichen
            }
        }
    
    * Überprüft, ob ein IR-Signal empfangen und erfolgreich decodiert wurde.
    * Decodiert den IR-Befehl und speichert ihn in ``decodedValue`` mit einer benutzerdefinierten Funktion ``decodeKeyValue()``.
    * Überprüft, ob der decodierte Wert kein Fehler ist und sich vom zuletzt decodierten Wert unterscheidet.
    * Gibt den decodierten IR-Wert auf dem seriellen Monitor aus.
    * Aktualisiert ``lastDecodedValue`` mit dem neuen decodierten Wert.
    * Setzt den IR-Signalempfang für das nächste Signal fort.
