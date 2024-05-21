
.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _follow_the_line:

4. Der Linie folgen
======================

Das Auto ist mit einem Linienverfolgungsmodul ausgestattet, mit dem es der schwarzen Linie folgen kann.

Wenn das Linienverfolgungsmodul die schwarze Linie erkennt, dreht sich der rechte Motor, während der linke Motor stillsteht, sodass das Auto einen Schritt nach links vorne macht.
Während das Auto sich bewegt und das Modul von der Linie wegrückt, dreht sich der linke Motor und der rechte Motor bleibt stehen. Das Auto wird einen Schritt nach rechts machen, um zur Linie zurückzukehren.
Wiederholen Sie die oben genannten Schritte, kann das Auto entlang der schwarzen Linie fahren.

Bevor Sie mit dem Projekt beginnen, müssen Sie eine Kurvenkarte mit schwarzem Klebeband erstellen. Die empfohlene Linienbreite liegt zwischen 0,8-1,5 cm und der Winkel der Kurve sollte nicht weniger als 90 Grad betragen.

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
    *   - :ref:`cpn_track`
        - |link_track_buy|

**Verdrahtung**

Dies ist ein digitales Linienverfolgungsmodul. Wenn eine schwarze Linie erkannt wird, gibt es 1 aus; bei Erkennung einer weißen Linie gibt es den Wert 0 aus. Darüber hinaus können Sie den Erfassungsabstand über das Potentiometer am Modul einstellen.

Bauen Sie den Schaltkreis gemäß dem folgenden Diagramm.

.. list-table:: 
    :header-rows: 1

    * - Linienverfolgungsmodul
      - R4-Platine
    * - S
      - 2
    * - V+
      - 5V
    * - G
      - GND

.. image:: img/car_4.png
    :width: 800

**Das Modul einstellen**

Bevor Sie mit dem Projekt beginnen, müssen Sie die Empfindlichkeit des Moduls einstellen.

Verkabeln Sie gemäß dem obigen Diagramm und versorgen Sie dann die R4-Platine mit Strom (entweder direkt über das USB-Kabel oder das 9V Batteriekabel), ohne den Code hochzuladen.

Kleben Sie ein schwarzes Isolierband auf den Tisch und stellen Sie den Wagen darauf.

Beobachten Sie die Signal-LED am Modul, um sicherzustellen, dass sie auf dem weißen Tisch leuchtet und auf dem schwarzen Band erlischt.

Wenn nicht, müssen Sie das Potentiometer am Modul so einstellen, dass es den oben beschriebenen Effekt erzielen kann.

.. image:: img/line_track_cali.JPG


**Code**

.. note::

    * Öffnen Sie die Datei ``4.follow_the_line.ino`` im Pfad ``3in1-kit\car_project\4.follow_the_line``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/2779e9eb-b7b0-4d47-b8c0-78fed39828c3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem Sie den Code auf das R4-Board geladen haben, richten Sie das Linienverfolgungsmodul unter dem Auto an der schwarzen Linie aus, und Sie werden sehen, dass das Auto der Linie folgt.

**Wie funktioniert das?**

In diesem Code werden die beiden Motoren entsprechend dem Wert des Linienverfolgungsmoduls mikrorotiert, sodass Sie sehen können, wie das Auto der schwarzen Linie folgt.

#. Fügen Sie die Pin-Definition für das Linienverfolgungsmodul hinzu. Hier ist es auf ``INPUT`` eingestellt. Initialisieren Sie hier auch den Seriellen Monitor und setzen Sie die Baudrate auf 9600bps.

    .. code-block:: arduino

        ...
        const int lineTrack = 2;
        Serial.begin(9600);
        void setup() {
            ...
            pinMode(lineTrack, INPUT);
        }

#. Lesen Sie den Wert des Linienverfolgungsmoduls aus. Wenn dieser 1 ist, lassen Sie das Auto nach links vorwärts fahren; ansonsten fahren Sie nach rechts vorwärts. Sie können auch den Seriellen Monitor öffnen, indem Sie auf das Lupensymbol in der oberen rechten Ecke klicken, um die Änderung des Linienverfolgungsmodulwertes auf der schwarz-weißen Linie zu sehen, bevor Sie das USB-Kabel ausstecken.

    .. code-block:: arduino
    
        void loop() {

            int speed = 150;

            int lineColor = digitalRead(lineTrack); // 0:white    1:black
            Serial.println(lineColor); 
            if (lineColor) {
                moveLeft(speed);
            } else {
                moveRight(speed);
            }
        }

#. Über die Funktionen ``moveLeft()`` und ``moveRight()``.

    Anders als die Links-Rechts-Drehfunktion im Projekt :ref:`car_move_code` sind hier nur kleine Links-Rechts-Drehungen erforderlich. Daher müssen Sie nur den Wert von ``A_1A`` oder ``B_1B`` jedes Mal anpassen. Zum Beispiel, wenn Sie sich nach links vorne bewegen (``moveLeft()``), müssen Sie nur die Geschwindigkeit auf ``A_1A`` setzen und alle anderen auf 0. Dies bewirkt, dass der rechte Motor im Uhrzeigersinn dreht und der linke Motor sich nicht bewegt.

    .. code-block:: arduino
    
        void moveLeft(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, speed);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, 0);
        }

        void moveRight(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, speed);
            analogWrite(B_1A, 0);
        }

* `Serial <https://www.arduino.cc/reference/en/language/functions/communication/serial/>`_

    Wird zur Kommunikation zwischen dem Arduino-Board und einem Computer oder anderen Geräten verwendet.

    * ``Serial.begin()``: Legt die Datenrate in Bits pro Sekunde (Baud) für die serielle Datenübertragung fest.
    * ``Serial.println()``: Gibt Daten als menschenlesbaren ASCII-Text an den seriellen Port weiter, gefolgt von einem Car-Return-Zeichen (ASCII 13 oder '\r') und einem Newline-Zeichen (ASCII 10 oder '\n').

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    Das ``if else`` ermöglicht im Vergleich zur einfachen if-Anweisung eine größere Kontrolle über den Codefluss, da mehrere Tests gruppiert werden können.
