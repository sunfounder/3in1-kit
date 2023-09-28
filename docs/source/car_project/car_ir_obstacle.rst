.. _car_ir_obstacle:

5. Spielen mit dem Hindernisvermeidungs-Modul
===============================================

Zwei Infrarot-Hindernisvermeidungsmodule sind an der Vorderseite des Autos angebracht, mit denen nahegelegene Hindernisse erkannt werden können.

In diesem Projekt kann das Auto frei vorwärts fahren. Wenn es auf ein Hindernis trifft, kann es dieses vermeiden und in andere Richtungen weiterfahren.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist sicherlich praktisch, ein komplettes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch über die untenstehenden Links einzeln kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENEINFÜHRUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

**Verdrahtung**

Das Hindernisvermeidungsmodul ist ein infraroter Näherungssensor mit einstellbarer Entfernung. Sein Ausgang ist normalerweise hoch und wird niedrig, wenn ein Hindernis erkannt wird.

Bauen Sie den Schaltkreis entsprechend dem untenstehenden Diagramm auf.

.. list-table:: 
    :header-rows: 1

    * - Linkes IR-Modul
      - R4 Board
    * - AUSGANG
      - 8
    * - ERDE
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - Rechtes IR-Modul
      - R4 Board
    * - AUSGANG
      - 7
    * - ERDE
      - GND
    * - VCC
      - 5V

.. image:: img/car_5.png
    :width: 800

**Modul einstellen**

Bevor Sie mit dem Projekt beginnen, müssen Sie den Erfassungsabstand des Moduls anpassen.

Verkabeln Sie gemäß dem obigen Schema, schalten Sie das R4-Board ein (entweder indem Sie das USB-Kabel direkt einstecken oder das 9V-Batteriekabel anschließen), ohne den Code hochzuladen.

Stellen Sie ein Notizbuch oder ein anderes flaches Objekt etwa 5 cm vor das IR-Hindernisvermeidungsmodul.

Verwenden Sie dann einen Schraubenzieher, um das Potentiometer auf dem Modul so zu drehen, dass die Signalanzeige auf dem Modul gerade aufleuchtet, um seinen maximalen Erfassungsabstand von 5 cm einzustellen.

Verwenden Sie die gleiche Methode, um ein weiteres Infrarotmodul anzupassen.

.. image:: img/ir_obs_cali.jpg


**Code**

.. note::

    * Öffnen Sie die Datei ``5.obstacle_avoidance_module.ino`` im Pfad ``3in1-kit\car_project\5.obstacle_avoidance_module``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/289ca80d-009f-4f60-b36d-1da6c5e10233/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Das Auto wird vorwärts fahren, sobald der Code erfolgreich hochgeladen wurde. Wenn das linke Infrarot-Modul ein Hindernis erkennt, fährt es rückwärts nach links; erkennt das rechte Infrarot-Modul ein Hindernis, fährt es rückwärts nach rechts; erkennen beide Seiten ein Hindernis, fährt es geradlinig rückwärts.

**Wie funktioniert das?**

Dieses Projekt basiert auf den Werten der linken und rechten Infrarot-Hindernisvermeidungsmodule, um das Auto die entsprechende Aktion ausführen zu lassen.

#. Fügen Sie die Pin-Definition für die 2 Hindernisvermeidungsmodule hinzu, hier sind sie auf ``INPUT`` eingestellt.

    .. code-block:: arduino

        ...
        const int rightIR = 7;
        const int leftIR = 8;

        void setup() {
        ...

        //IR obstacle
            pinMode(leftIR, INPUT);
            pinMode(rightIR, INPUT);
        }


#. Lesen Sie die Werte der linken und rechten Infrarotmodule und lassen Sie das Auto die entsprechende Aktion ausführen.

    .. code-block:: arduino

        void loop() {

            int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
            int right = digitalRead(rightIR);
            int speed = 150;

            if (!left && right) {
                backLeft(speed);
            } else if (left && !right) {
                backRight(speed);
            } else if (!left && !right) {
                moveBackward(speed);
            } else {
                moveForward(speed);
            }
        }

    * Wenn das linke IR-Modul 0 ist (Hindernis erkannt) und das rechte IR-Modul 1 ist, fährt das Auto rückwärts nach links.
    * Wenn das rechte IR-Modul 0 ist (Hindernis erkannt), fährt das Auto rückwärts nach rechts.
    * Wenn beide IR-Module gleichzeitig ein Hindernis erkennen, fährt das Auto rückwärts.
    * Ansonsten wird das Auto weiter vorwärts fahren.


#. Über die Funktion ``backLeft()``.

    Wenn der rechte Motor gegen den Uhrzeigersinn dreht und der linke Motor nicht dreht, fährt das Auto rückwärts nach links.

    .. code-block:: arduino

        void backLeft(int speed) {
            analogWrite(A_1B, speed);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, 0);
        }

#. Über die Funktion ``backRight()``.

    Wenn der linke Motor im Uhrzeigersinn dreht und der rechte Motor nicht dreht, fährt das Auto rückwärts nach rechts.

    .. code-block:: arduino

        void backRight(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, speed);
        }

* `&& <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicaland/>`_: Logisches UND ergibt nur dann wahr, wenn beide Operanden wahr sind.

* `! <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicalnot/>`_: Logisches NICHT ergibt wahr, wenn der Operand falsch ist und umgekehrt.
