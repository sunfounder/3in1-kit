.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _follow_your_hand:

7. Folge deiner Hand
=========================

Betrachte dieses Auto hier als dein Haustier. Wenn du ihm zuwinkst, kommt es sofort zu dir gelaufen.

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

Du kannst sie auch einzeln über die untenstehenden Links kaufen.

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

Schließe das Ultraschallmodul und die beiden IR-Hindernisvermeidungsmodule gleichzeitig an.

Die Verbindung des Ultraschallmoduls mit dem R4-Board erfolgt wie folgt.

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

Die Verkabelung der beiden IR-Hindernisvermeidungsmodule zum R4-Board ist wie folgt.

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

    * Öffnen Sie die Datei ``7.follow_your_hand.ino`` im Pfad ``3in1-kit\car_project\7.follow_your_hand``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/584e42c8-8842-4db0-93b5-f6f949b6ffca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Stellen Sie das Auto auf den Boden, nachdem der Code erfolgreich hochgeladen wurde. Halten Sie Ihre Hand in einem Abstand von 5*10cm vor das Auto, und es wird Ihrer Hand folgen. Wenn Sie Ihre Hand nahe am IR-Hindernismodul auf beiden Seiten positionieren, wird es auch in die entsprechende Richtung abbiegen.

**Wie funktioniert das?**

Dieses Projekt kombiniert die beiden vorherigen Projekte :ref:`car_ultrasonic` und :ref:`car_ir_obstacle`, aber die umgesetzte Wirkung ist anders. In den vorherigen 2 Projekten wurde ein Hindernis rückwärts erkannt, hier jedoch wird erkannt, dass Ihre Hand der Vorwärts- oder Abbiege-Richtung folgt.
Der Arbeitsablauf dieses Projekts ist wie folgt:

* Lese den vom Ultraschallmodul erkannten Abstand und den Wert beider Infrarotmodule.
* Wenn der Abstand 5~10cm beträgt, lasse das Auto Ihrer Hand folgen.
* Wenn das linke IR-Modul Ihre Hand erkennt, biege links ab.
* Wenn das rechte IR-Modul Ihre Hand erkennt, biege rechts ab.
* Wenn weder das Infrarotmodul noch das Ultraschallmodul Ihre Hand erkennen, lasse das Auto anhalten.


.. code-block:: arduino

    void loop() {

        float distance = readSensorData();

        int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
        int right = digitalRead(rightIR);
        int speed = 150;

        if (distance>5 && distance<10){
            moveForward(speed);
        }
        if(!left&&right){
            turnLeft(speed);
        }else if(left&&!right){
            turnRight(speed);
        }else{
            stopMove();
        }
    }