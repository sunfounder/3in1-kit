.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _self_driving:

8. Autonomes Fahren
=========================

Dieses Projekt kombiniert zwei Projekte: :ref:`car_ultrasonic` und :ref:`car_ir_obstacle`. 
Die 2 Infrarot-Hindernisvermeidungsmodule dienen zur kurzfristigen oder Rand-Erkennung, 
während die Ultraschallmodule zur Fernerkennung verwendet werden, um sicherzustellen, dass das Auto während des freien Fahrens keinem Hindernis begegnet.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist sicherlich praktisch, ein komplettes Kit zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name
        - KOMPONENTEN IN DIESEM KIT
        - LINK
    *   - 3-in-1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Alternativ können Sie diese auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

**Verdrahtung**

Schließen Sie das Ultraschallmodul und die 2 IR-Hindernisvermeidungsmodule gleichzeitig an.

Verbinden Sie das Ultraschallmodul wie folgt mit dem R3-Board.

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

Die Verdrahtung der beiden IR-Hindernisvermeidungsmodule zum R3-Board ist wie folgt:

.. list-table:: 
    :header-rows: 1

    * - Linkes IR-Modul
      - R3 Board
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - Rechtes IR-Modul
      - R3 Board
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_7_8.png
    :width: 800

**Programmierung**

.. note::

    * Öffnen Sie die Datei ``8.self_driving_car.ino`` unter dem Pfad ``3in1-kit\car_project\8.self_driving_car``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Alternativ können Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hochladen.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0a74a7b1-ead6-4bea-ab5a-4da71f27f82f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Sobald der Code erfolgreich hochgeladen wurde, beginnt das Auto mit dem freien Fahren. Wenn das IR-Hindernisvermeidungsmodul auf beiden Seiten ein Hindernis erkennt, wird es in die entgegengesetzte Richtung für eine Notausweichbewegung fahren; wenn direkt vor dem Auto ein Hindernis in einem Abstand von 2~10cm ist, wird es rückwärts nach links fahren, seine Richtung korrigieren und dann vorwärts fahren.

**Wie funktioniert es?**

Der Arbeitsablauf dieses Projekts ist wie folgt.

* Lese zuerst den Wert des linken und rechten IR-Hindernisvermeidungsmoduls.
* Wenn das linke IR-Modul 0 ist (Hindernis erkannt) und das rechte IR-Modul 1 ist, lasse das Auto nach links zurückfahren.
* Wenn das rechte IR-Modul 0 ist (Hindernis erkannt), lasse das Auto nach rechts zurückfahren.
* Wenn beide IR-Module gleichzeitig ein Hindernis erkennen, wird das Auto rückwärts fahren.
* Ansonsten lies den vom Ultraschallmodul erkannten Abstand.
* Wenn der Abstand größer als 50 cm ist, lasse das Auto vorwärts fahren.
* Wenn der Abstand zwischen 2-10cm liegt, lasse das Auto zurückfahren, bevor es sich dreht.
* Wenn der Abstand zwischen 10-50cm liegt, lasse das Auto mit geringer Geschwindigkeit vorwärts fahren.

.. code-block:: arduino

    void loop() {

        int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
        int right = digitalRead(rightIR);

        if (!left && right) {
            backLeft(150);
        } else if (left && !right) {
            backRight(150);
        } else if (!left && !right) {
            moveBackward(150);
        } else {
            float distance = readSensorData();
            Serial.println(distance);
            if (distance > 50) { // Safe
                moveForward(200);
            } else if (distance < 10 && distance > 2) { // Attention
                moveBackward(200);
                delay(1000);
                backLeft(150);
                delay(500);
            } else {
                moveForward(150);
            }
        }
    }
