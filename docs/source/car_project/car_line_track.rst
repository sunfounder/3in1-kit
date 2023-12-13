.. _follow_the_line:

4. Die Linie verfolgen
======================

Das Auto ist mit einem Linienverfolgungsmodul ausgestattet, mit dem es einer schwarzen Linie folgen kann.

Wenn das Linienverfolgungsmodul die schwarze Linie erkennt, dreht sich der rechte Motor, während der linke Motor stehen bleibt. Dadurch bewegt sich das Auto einen Schritt nach vorne links. Während sich das Auto bewegt und das Modul von der Linie wegbewegt, dreht sich der linke Motor und der rechte Motor bleibt stehen. Das Auto bewegt sich einen Schritt nach rechts, um zur Linie zurückzukehren. Die beiden oben genannten Schritte wiederholen sich, sodass das Auto der schwarzen Linie folgen kann.

Bevor Sie mit dem Projekt beginnen, sollten Sie eine Kurvenkarte mit schwarzem Klebeband erstellen. Die empfohlene Linienbreite liegt zwischen 0,8-1,5 cm, und der Drehwinkel sollte nicht weniger als 90 Grad betragen.

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

    *   - KOMPONENTENÜBERSICHT
        - KAUF LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_track`
        - |link_track_buy|

**Verdrahtung**

Dies ist ein digitales Linienverfolgungsmodul. Bei Erkennung einer schwarzen Linie gibt es den Wert 1 aus; bei Erkennung einer weißen Linie den Wert 0. Zusätzlich können Sie über das Potentiometer auf dem Modul seinen Erfassungsabstand einstellen.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/mlCQgAq4elo?si=ZFmHeA6bVsDCPG0p" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Bauen Sie den Schaltkreis gemäß dem folgenden Diagramm auf.

.. list-table:: 
    :header-rows: 1

    * - Linienverfolgungsmodul
      - R3 Board
    * - S
      - 2
    * - V+
      - 5V
    * - G
      - GND

.. image:: img/car_4.png
    :width: 800


**Das Modul anpassen**

Vor Beginn des Projekts müssen Sie die Empfindlichkeit des Moduls anpassen.

Verkabeln Sie entsprechend dem obigen Diagramm und schalten Sie das R3-Board ein (entweder direkt über das USB-Kabel oder das 9V Batterieknopfkabel), ohne den Code hochzuladen.

Kleben Sie ein schwarzes Elektroband auf den Tisch und stellen Sie den Wagen darauf.

Beobachten Sie die Signal-LED am Modul, um sicherzustellen, dass sie auf dem weißen Tisch leuchtet und auf dem schwarzen Band erlischt.

Wenn dies nicht der Fall ist, müssen Sie das Potentiometer am Modul anpassen, damit es den oben beschriebenen Effekt erzielt.

.. image:: img/line_track_cali.JPG

**Code**

.. note::

    * Öffnen Sie die Datei ``4.follow_the_line.ino`` im Pfad ``3in1-kit\car_project\4.follow_the_line``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/2779e9eb-b7b0-4d47-b8c0-78fed39828c3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem der Code auf das R3-Board hochgeladen wurde, richten Sie das Linienverfolgungsmodul unter dem Auto an der schwarzen Linie aus, und Sie werden sehen, wie das Auto der Linie folgt.

**Wie funktioniert das?**

In diesem Code werden die beiden Motoren entsprechend dem Wert des Linienverfolgungsmoduls mikrorotiert, sodass das Auto der schwarzen Linie folgt.

#. Fügen Sie die Pin-Definition für das Linienverfolgungsmodul hinzu, hier ist es auf ``INPUT`` eingestellt. Initialisieren Sie hier auch den seriellen Monitor und setzen Sie die Baudrate auf 9600bps.

    .. code-block:: arduino

        ...
        const int lineTrack = 2;
        Serial.begin(9600);
        void setup() {
            ...
            pinMode(lineTrack, INPUT);
        }

#. Lesen Sie den Wert des Linienverfolgungsmoduls. Wenn es 1 ist, lassen Sie das Auto nach links vorfahren; andernfalls fahren Sie nach rechts vor. Sie können auch den seriellen Monitor öffnen, indem Sie auf das Lupensymbol in der oberen rechten Ecke klicken, um die Änderung des Wertes des Linienverfolgungsmoduls auf der schwarzen und weißen Linie vor dem Ausstecken des USB-Kabels zu sehen.

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

    Im Gegensatz zur Links-Rechts-Drehfunktion im Projekt :ref:`car_move_code` sind hier nur kleine Links-Rechts-Drehungen erforderlich. Sie müssen daher nur den Wert von ``A_1A`` oder ``B_1B`` jedes Mal anpassen. Wenn Sie zum Beispiel nach vorne links fahren (``moveLeft()``), müssen Sie die Geschwindigkeit nur auf ``A_1A`` setzen und alle anderen auf 0, damit der rechte Motor im Uhrzeigersinn dreht und der linke Motor nicht bewegt.

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

    Wird zur Kommunikation zwischen dem Arduino-Board und einem Computer oder anderen Geräten verwendet

    * ``Serial.begin()``: Legt die Datenrate in Bits pro Sekunde (Baud) für die serielle Datenübertragung fest.
    * ``Serial.println()``: Gibt Daten am seriellen Port als menschenlesbaren ASCII-Text aus, gefolgt von einem Wagenrücklaufzeichen (ASCII 13 oder '\r') und einem Zeilenumbruchszeichen (ASCII 10 oder '\n').

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    Mit ``if else`` lässt sich der Codefluss besser steuern als mit der einfachen if-Anweisung, da mehrere Tests gruppiert werden können.
