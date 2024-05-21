.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _car_ultrasonic:

6. Spielen mit dem Ultraschallmodul
=====================================

Im Projekt :ref:`car_ir_obstacle` werden die 2 Infrarot-Hindernisvermeidungsmodule zur Hindernisvermeidung verwendet, aber die Erkennungsdistanz des IR-Hindernisvermeidungsmoduls ist kurz, wodurch das Auto möglicherweise zu spät kommt, um den Hindernissen auszuweichen.

In diesem Projekt verwenden wir ein Ultraschallmodul für eine Langstreckenerkennung, damit das Auto Hindernisse aus einer größeren Entfernung erkennen und eine Entscheidung treffen kann.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3-in-1 Starter-Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Verdrahtung**

Ein Ultraschallsensormodul ist ein Instrument, das die Entfernung zu einem Objekt mit Ultraschallwellen misst.
Es hat zwei Sonden. Eine sendet Ultraschallwellen und die andere empfängt die Wellen und wandelt die Sende- und Empfangszeit in eine Entfernung um, wodurch die Entfernung zwischen dem Gerät und einem Hindernis erfasst wird.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/qx9ZH-YnAkg?si=wfrsDrmGCPa2nYPD" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Bauen Sie die Schaltung entsprechend dem folgenden Diagramm auf.

.. list-table:: 
    :header-rows: 1

    * - Ultraschallmodul
      - R3 Board
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

.. image:: img/car_6.png
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``6.ultrasonic_module.ino`` im Pfad ``3in1-kit\car_project\6.ultrasonic_module``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/ae97f966-9d72-40e6-aa9f-e0767ddf5bd5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, richten Sie das Auto auf die Wand. Wenn der Abstand zu groß ist, fährt es vorwärts; wenn es zu nah ist, fährt es rückwärts; wenn es sich in sicherer Entfernung befindet, hält es an.

**Wie funktioniert das?**

Dieses Projekt basiert auf der vom Ultraschallmodul gelesenen Entfernung, um das Auto entsprechend zu bewegen.

#. Fügen Sie die Pin-Definition für das Ultraschallmodul hinzu, ``trigPin`` wird verwendet, um Ultraschallwellen zu senden, setzen Sie es also auf ``OUTPUT``; ``echoPin`` wird auf ``INPUT`` gesetzt, um Ultraschallwellen zu empfangen.


    .. code-block:: arduino

        ...
        const int trigPin = 3;
        const int echoPin = 4;

        void setup() {
        ...

        //ultrasonic
            pinMode(echoPin, INPUT);
            pinMode(trigPin, OUTPUT);
        }

#. Zuerst lesen Sie den Abstandswert, der vom Ultraschallmodul erhalten wurde. Wenn der Abstand größer als 25 ist, lassen Sie das Auto vorwärts fahren; wenn der Abstand zwischen 2-10cm liegt, lassen Sie das Auto rückwärts fahren, ansonsten (zwischen 10~25) stoppen.

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

#. Über die Funktion ``readSensorData()``.

    Der Sender des Ultraschallmoduls sendet alle 2us ein 10us Rechteckwellensignal, und der Empfänger empfängt ein High-Level-Signal, wenn sich ein Hindernis im Bereich befindet. Verwenden Sie die Funktion ``pulseIn()``, um die Zeit vom Senden bis zum Empfangen aufzuzeichnen, teilen Sie durch die Schallgeschwindigkeit von 340m/s und dann durch 2. Das Ergebnis ist die Entfernung zwischen diesem Modul und dem Hindernis in Einheiten: cm.

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

    * ``pin``: die Nummer des Arduino-Pins, auf dem Sie den Impuls lesen möchten. Zulässige Datentypen: int.
    * ``value``: Typ des zu lesenden Pulses: entweder HIGH oder LOW. Zulässige Datentypen: int.

    Liest einen Impuls (entweder HIGH oder LOW) an einem Pin. Wenn zum Beispiel der Wert HIGH ist, wartet ``pulseIn()`` darauf, dass der Pin von LOW auf HIGH wechselt, beginnt mit der Zeitmessung und wartet dann darauf, dass der Pin LOW wird und stoppt die Zeitmessung.

