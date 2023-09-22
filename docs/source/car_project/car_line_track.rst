.. _follow_the_line:

4. Der Linie folgen
======================

Das Auto ist mit einem Linienverfolgungsmodul ausgestattet, mit dem das Auto der schwarzen Linie folgen kann.

Wenn das Linienverfolgungsmodul die schwarze Linie erkennt, dreht sich der rechte Motor, während der linke Motor stillsteht, sodass das Auto einen Schritt nach links vorne macht.
Während sich das Auto bewegt, wird das Linienmodul von der Linie weg bewegt. Dann dreht sich der linke Motor und der rechte Motor nicht. Das Auto wird einen Schritt nach rechts machen, um zur Linie zurückzukehren.
Wiederholen Sie die obigen beiden Schritte, kann das Auto entlang der schwarzen Linie fahren.

Bevor Sie mit dem Projekt beginnen, müssen Sie eine Kurvenkarte mit schwarzem Linienband erstellen. Die empfohlene Linienbreite liegt zwischen 0,8-1,5 cm und der Winkel der Kurve sollte nicht weniger als 90 Grad betragen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM SET
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENEINFÜHRUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l298n`
        - |link_l298n_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_track`
        - |link_track_buy|

**Verdrahtung**

Dies ist ein digitales Linienverfolgungsmodul. Bei Erkennung einer schwarzen Linie gibt es den Wert 1 aus; bei Erkennung einer weißen Linie gibt es den Wert 0 aus. Außerdem können Sie seinen Erfassungsabstand über das Potentiometer auf dem Modul einstellen.

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

.. image:: img/car_track.jpg
    :width: 800

**Das Modul einstellen**

Bevor Sie mit dem Projekt beginnen, müssen Sie die Empfindlichkeit des Moduls einstellen.

Verkabeln Sie gemäß dem obigen Diagramm und schalten Sie dann das R3-Board ein (entweder direkt über das USB-Kabel oder das 9V-Batteriekabel), ohne den Code hochzuladen.

Kleben Sie ein schwarzes Isolierband auf den Tisch und stellen Sie den Wagen darauf.

Beobachten Sie die Signal-LED auf dem Modul, um sicherzustellen, dass sie auf dem weißen Tisch leuchtet und auf dem schwarzen Band erlischt.

Wenn nicht, müssen Sie das Potentiometer auf dem Modul einstellen, damit es den oben beschriebenen Effekt erzielt.

.. image:: img/line_track_cali.JPG


**Code**

.. note::

    * Öffnen Sie die Datei ``4.follow_the_line.ino`` im Verzeichnis ``3in1-kit\car_project\4.follow_the_line``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/452d0e93-8c2f-49c6-80e0-5a2f653145bb/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem Sie den Code auf das R3-Board hochgeladen haben, richten Sie das Linienverfolgungsmodul unter dem Auto auf die schwarze Linie aus. Anschließend wird das Auto der Linie folgen.

**Wie funktioniert das?**

In diesem Code werden die beiden Motoren je nach Wert des Linienverfolgungsmoduls mikro-rotiert, so dass das Auto der schwarzen Linie folgen kann.

#. Fügen Sie die Pin-Definition für das Linienverfolgungsmodul hinzu, hier wird es auf ``INPUT`` gesetzt. Initialisieren Sie auch den Seriellen Monitor und stellen Sie die Baudrate auf 9600bps ein.

    .. code-block:: arduino

        ...
        const int lineTrack = 2;
        Serial.begin(9600);
        void setup() {
            ...
            pinMode(lineTrack, INPUT);
        }

#. Lesen Sie den Wert des Linienverfolgungsmoduls aus. Ist er 1, soll das Auto nach links vorfahren; ansonsten nach rechts vorfahren. Sie können auch den Seriellen Monitor öffnen, indem Sie auf das Lupensymbol in der oberen rechten Ecke klicken, um den Wert des Linienverfolgungsmoduls auf der schwarz-weißen Linie vor dem Herausziehen des USB-Kabels zu sehen.

    .. code-block:: arduino
    
        void loop() {

            int speed = 150;

            int lineColor = digitalRead(lineTrack); // 0:weiß    1:schwarz
            Serial.println(lineColor); 
            if (lineColor) {
                moveLeft(speed);
            } else {
                moveRight(speed);
            }
        }

#. Über die Funktionen ``moveLeft()`` und ``moveRight()``.

    Im Gegensatz zur Links-Rechts-Drehfunktion im Projekt :ref:`car_move_code` sind hier nur kleine Links-Rechts-Drehungen erforderlich. Daher müssen Sie nur den Wert von IN2 oder IN3 jeweils anpassen. Zum Beispiel, wenn Sie nach vorne links fahren (``moveLeft()``), müssen Sie die Geschwindigkeit nur für IN2 setzen und alle anderen auf 0, damit der rechte Motor im Uhrzeigersinn dreht und der linke Motor nicht bewegt wird.

    .. code-block:: arduino
    

        void moveLeft(int speed) {
            analogWrite(in1, 0);
            analogWrite(in2, speed);
            analogWrite(in3, 0);
            analogWrite(in4, 0);
        }

        void moveRight(int speed) {
            analogWrite(in1, 0);
            analogWrite(in2, 0);
            analogWrite(in3, speed);
            analogWrite(in4, 0);
        }

* `Serial <https://www.arduino.cc/reference/en/language/functions/communication/serial/>`_

    Wird für die Kommunikation zwischen dem Arduino-Board und einem Computer oder anderen Geräten verwendet.

    * ``Serial.begin()``: Legt die Datenrate in Bits pro Sekunde (Baud) für die serielle Datenübertragung fest.
    * ``Serial.println()``: Gibt Daten als menschenlesbaren ASCII-Text, gefolgt von einem Car-Return-Zeichen (ASCII 13 oder '\r') und einem Newline-Zeichen (ASCII 10 oder '\n'), an den seriellen Port aus.

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    Das ``if else`` ermöglicht im Vergleich zur einfachen if-Anweisung eine größere Kontrolle über den Codeablauf, da mehrere Tests gruppiert werden können.
