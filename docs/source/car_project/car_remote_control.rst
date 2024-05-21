.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _car_remote:

9. Fernbedienung
=================================

Dieses Kit enthält einen IR-Empfänger, der es ermöglicht, das Auto mit einer IR-Fernbedienung zu steuern.

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

Bauen Sie nun den Schaltkreis entsprechend dem untenstehenden Diagramm.

.. list-table:: 
    :header-rows: 1

    * - IR-Empfänger
      - R4-Platine
    * - OUT
      - 12
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - LED
      - R4-Platine
    * - Anode(Der längere Pin)
      - 13
    * - Kathode
      - GND

.. image:: img/car_9.png
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``9.remote_control.ino`` im Pfad ``3in1-kit\car_project\9.remote_control``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Hier wird die Bibliothek ``IRremote`` verwendet, die Sie über den **Library Manager** installieren können.
  
        .. image:: ../img/lib_irremote.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/7c78450d-fcd2-4288-a00d-499c71ad2d52/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, drücken Sie die Taste auf der Fernbedienung. Die LED wird einmal blinken, um anzuzeigen, dass das Signal empfangen wurde, und das Auto wird sich entsprechend der gedrückten Taste bewegen. Sie können die folgenden Tasten drücken, um das Auto zu steuern.


* **+**: Beschleunigen
* **-**: Verlangsamen
* **1**: Vorwärts nach links
* **2**: Vorwärts
* **3**: Vorwärts nach rechts
* **4**: Nach links drehen
* **6**: Nach rechts drehen
* **7**: Rückwärts nach links
* **8**: Rückwärts
* **9**: Rückwärts nach rechts

**Wie funktioniert das?**

Das Ziel dieses Projekts ist es, das Auto durch das Lesen des Tastenwertes der IR-Fernbedienung zu bewegen. Zusätzlich wird eine LED hinzugefügt, um anzuzeigen, dass das IR-Signal erfolgreich empfangen wurde.

#. Importieren Sie die ``IRremote``-Bibliothek. Sie können sie über den **Library Manager** installieren.

    .. code-block:: arduino

        #include <IRremote.h>

        const int IR_RECEIVE_PIN = 12;  // Define the pin number for the IR Sensor

#. Initialisiert die serielle Kommunikation mit einer Baudrate von 9600. Startet den IR-Empfänger am angegebenen Pin (``IR_RECEIVE_PIN``) und aktiviert die LED-Rückmeldung (falls zutreffend).


    .. code-block:: arduino

        ...

        void setup() {

            ...
            //IR remote
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the receiver
            Serial.println("REMOTE CONTROL START");
        }

#. Wenn Sie die Tasten auf der Fernbedienung drücken, der Infrarotempfänger erkennt, welche Taste gedrückt wurde. Anschließend bewegt sich das Auto entsprechend dem zugehörigen Tastenwert.

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
                    IrReceiver.resume();  // Enable receiving of the next value

            }
        }

    * Überprüft, ob ein IR-Signal empfangen und erfolgreich entschlüsselt wurde.
    * Entschlüsselt den IR-Befehl und speichert ihn in ``key`` mit Hilfe einer benutzerdefinierten ``decodeKeyValue()``-Funktion.
    * Überprüft, ob der entschlüsselte Wert kein Fehler ist.
    * Gibt den entschlüsselten IR-Wert auf dem seriellen Monitor aus.
    * Setzt den IR-Signalempfang für das nächste Signal fort.


