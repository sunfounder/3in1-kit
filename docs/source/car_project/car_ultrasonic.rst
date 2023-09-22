.. _car_ultrasonic:

6. Spiel mit dem Ultraschallmodul
=====================================

Im Projekt :ref:`car_ir_obstacle` werden die 2 Infrarot-Hindernisvermeidungsmodule für die Hindernisvermeidung verwendet. Allerdings ist die Erkennungsreichweite des IR-Hindernisvermeidungsmoduls kurz, was dazu führen kann, dass das Auto zu spät reagiert, um Hindernissen auszuweichen.

In diesem Projekt verwenden wir ein Ultraschallmodul für Erkennungen über längere Distanzen, damit das Auto Hindernisse aus weiterer Entfernung wahrnehmen und entsprechend reagieren kann.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist sicherlich praktisch, ein gesamtes Set zu kaufen. Hier ist der Link:

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Verdrahtung**

Ein Ultraschallsensormodul ist ein Instrument, das mithilfe von Ultraschallwellen die Entfernung zu einem Objekt misst.
Es verfügt über zwei Sonden. Eine sendet Ultraschallwellen, die andere empfängt diese Wellen und wandelt die Zeit zwischen Senden und Empfangen in eine Entfernung um, wodurch die Entfernung zwischen dem Gerät und einem Hindernis erkannt wird.

Bauen Sie die Schaltung gemäß dem folgenden Diagramm auf.

.. list-table:: 
    :header-rows: 1

    * - Ultraschallmodul
      - R3-Board
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

.. image:: img/car_ultrasonic.jpg
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``6.ultrasonic_module.ino`` im Pfad ``3in1-kit\car_project\6.ultrasonic_module``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/cfa094c5-2dbf-4297-afbb-da2306ccc984/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, richten Sie das Auto auf eine Wand aus. Wenn der Abstand zu groß ist, fährt es vorwärts; ist er zu gering, fährt es rückwärts; befindet es sich in sicherem Abstand, hält es an.


**Wie funktioniert das?**

Dieses Projekt basiert auf der vom Ultraschallmodul gelesenen Entfernung, um das Auto entsprechend zu steuern.

#. Fügen Sie die Pin-Definition für das Ultraschallmodul hinzu. ``trigPin`` dient zum Senden von Ultraschallwellen und wird daher auf ``OUTPUT`` gesetzt; ``echoPin`` wird auf ``INPUT`` gesetzt, um Ultraschallwellen zu empfangen.

    .. code-block:: arduino

        ...
        const int trigPin = 3;
        const int echoPin = 4;

        void setup() {
        ...

        // Ultraschall
            pinMode(echoPin, INPUT);
            pinMode(trigPin, OUTPUT);
        }

#. Lesen Sie zuerst den vom Ultraschallmodul ermittelten Entfernungswert. Wenn die Entfernung größer als 25 ist, soll das Auto vorwärts fahren; wenn die Entfernung zwischen 2-10cm liegt, soll das Auto rückwärts fahren, sonst (zwischen 10~25) stoppen.

    .. code-block:: arduino

        void loop() {
            float distance = readSensorData();
            if (distance > 25) {
                moveForward(200);
            }
            else if (distance < 10 && distance > 2) {
                moveBackward(200);
            } else {
                stopMove();
            }
        }

#. Über die Funktion ``readSensorData()``:

    Der Sender des Ultraschallmoduls sendet alle 2us ein 10us Quadratwellensignal, und der Empfänger erhält ein High-Level-Signal, wenn sich ein Hindernis im Bereich befindet. Mit der Funktion ``pulseIn()`` wird die Zeit vom Senden bis zum Empfangen aufgezeichnet, durch die Schallgeschwindigkeit von 340m/s geteilt und dann durch 2 dividiert. Das Ergebnis ist der Abstand zwischen diesem Modul und dem Hindernis in Einheiten: cm.

    .. code-block:: arduino

        float readSensorData() {
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);
            float distance = pulseIn(echoPin, HIGH) / 58.00; //Entspricht (340m/s*1us)/2
            return distance;
        }

* `pulseIn(pin, value) <https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/>`_

    * ``pin``: Die Nummer des Arduino-Pins, an dem Sie den Impuls lesen möchten. Zulässige Datentypen: int.
    * ``value``: Art des zu lesenden Pulses: entweder HIGH oder LOW. Zulässige Datentypen: int.

    Liest einen Impuls (entweder HIGH oder LOW) an einem Pin. Wenn zum Beispiel der Wert HIGH ist, wartet ``pulseIn()`` darauf, dass der Pin von LOW auf HIGH wechselt, beginnt mit der Zeitmessung und wartet dann darauf, dass der Pin auf LOW geht und stoppt die Zeitmessung.

