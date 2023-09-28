.. _self_driving:

8. Selbstfahrendes Auto
=========================

Dieses Projekt kombiniert die beiden Projekte :ref:`car_ultrasonic` und :ref:`car_ir_obstacle`. 
2 Infrarot-Hindernisvermeidungsmodule führen Kurzstrecken- oder Kantenerkennungen durch, 
und Ultraschallmodule sorgen für Langstreckenerkennung, um sicherzustellen, dass das Auto während des freien Fahrens kein Hindernis trifft.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen, hier ist der Link:

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

Verdrahten Sie das Ultraschallmodul wie folgt mit dem R4-Board.

.. list-table:: 
    :header-rows: 1

    * - Ultraschallmodul
      - R4 Board
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

Die Verdrahtung der 2 IR-Hindernisvermeidungsmodule zum R4-Board ist wie folgt:

.. list-table:: 
    :header-rows: 1

    * - Linkes IR-Modul
      - R4 Board
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - Rechtes IR-Modul
      - R4 Board
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_7_8.png
    :width: 800


**Code**

.. note::

    * Öffnen Sie die Datei ``8.self_driving_car.ino`` unter dem Pfad ``3in1-kit\car_project\8.self_driving_car``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0a74a7b1-ead6-4bea-ab5a-4da71f27f82f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Sobald der Code erfolgreich hochgeladen wurde, wird das Auto frei fahren. Wenn das IR-Hindernismodul auf beiden Seiten ein Hindernis erkennt, wird es sich zur Notausweichung in die entgegengesetzte Richtung bewegen; befindet sich ein Hindernis direkt vor dem Auto im Abstand von 2~10cm, wird es nach links zurücksetzen, seine Richtung anpassen und dann vorwärts fahren.

**Wie funktioniert das?**

Der Ablauf dieses Projekts ist wie folgt.

* Priorität beim Auslesen der Werte des linken und rechten IR-Hindernisvermeidungsmoduls.
* Wenn das linke IR-Modul 0 ist (Hindernis erkannt) und das rechte IR-Modul 1 ist, soll das Auto nach links zurücksetzen.
* Wenn das rechte IR-Modul 0 ist (Hindernis erkannt), soll das Auto nach rechts zurücksetzen.
* Wenn beide IR-Module gleichzeitig ein Hindernis erkennen, wird das Auto zurücksetzen.
* Ansonsten wird der Abstand, der vom Ultraschallmodul erkannt wurde, ausgelesen.
* Wenn der Abstand größer als 50cm ist, soll das Auto vorwärts fahren.
* Wenn der Abstand zwischen 2-10cm liegt, soll das Auto zurücksetzen, bevor es abbiegt.
* Wenn der Abstand zwischen 10-50cm liegt, soll das Auto mit geringer Geschwindigkeit vorwärts fahren.


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

