.. _car_ir_obstacle:

5. Mit dem Hindernisvermeidungs-Modul spielen
===============================================

Zwei Infrarot-Hindernisvermeidungsmodule sind vorne am Auto montiert. Sie dienen dazu, nahegelegene Hindernisse zu erkennen.

In diesem Projekt darf das Auto frei nach vorne fahren. Bei einem Hindernis kann es dieses umgehen und in anderen Richtungen weiterfahren.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist sicherlich praktisch, ein komplettes Set zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name
        - ARTIKEL IN DIESEM SET
        - LINK
    *   - 3 in 1 Starter-Set
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
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

**Verdrahtung**

Das Hindernisvermeidungs-Modul ist ein einstellbarer Infrarot-Näherungssensor. Sein Ausgang ist normalerweise hoch und wird niedrig, wenn ein Hindernis erkannt wird.

Bauen Sie die Schaltung gemäß dem untenstehenden Diagramm.

.. list-table:: 
    :header-rows: 1

    * - Linkes IR-Modul
      - R3-Platine
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - Rechtes IR-Modul
      - R3-Platine
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_5.png
    :width: 800

**Modul justieren**

Bevor Sie mit dem Projekt beginnen, müssen Sie den Erkennungsabstand des Moduls einstellen.

Nach der oben gezeigten Verdrahtung, schalten Sie die R3-Platine ein (entweder durch direktes Anschließen des USB-Kabels oder durch Anschließen des 9V-Batteriekabels), ohne den Code hochzuladen.

Platzieren Sie ein Notizbuch oder ein anderes flaches Objekt etwa 5 cm vor der IR-Hindernisvermeidung.

Verwenden Sie dann einen Schraubendreher, um das Potentiometer auf dem Modul zu drehen, bis die Signalanzeige auf dem Modul gerade aufleuchtet, um den maximalen Erkennungsabstand von 5 cm einzustellen.

Verfahren Sie auf die gleiche Weise, um ein weiteres Infrarot-Modul einzustellen.

.. image:: img/ir_obs_cali.jpg

**Code**

.. note::

    * Öffnen Sie die Datei ``5.obstacle_avoidance_module.ino`` im Pfad ``3in1-kit\car_project\5.obstacle_avoidance_module``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.

    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/289ca80d-009f-4f60-b36d-1da6c5e10233/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Das Auto fährt vorwärts, sobald der Code erfolgreich hochgeladen wurde. Wenn das linke Infrarot-Modul ein Hindernis erkennt, fährt es rückwärts nach links; erkennt das rechte Infrarot-Modul ein Hindernis, fährt es rückwärts nach rechts; erkennen beide Seiten ein Hindernis, fährt es geradlinig rückwärts.

**Wie funktioniert das?**

Dieses Projekt basiert auf den Werten der linken und rechten Infrarot-Hindernisvermeidungsmodule, um dem Auto die entsprechende Aktion ausführen zu lassen.

#. Fügen Sie die Pin-Definition für die 2 Hindernisvermeidungsmodule hinzu, hier sind sie auf ``INPUT`` gesetzt.

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
    * Andernfalls fährt das Auto weiter vorwärts.


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

* `&& <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicaland/>`_: Logisches UND ergibt nur dann true, wenn beide Operanden wahr sind.

* `! <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicalnot/>`_: Logisches NICHT ergibt true, wenn der Operand falsch ist und umgekehrt.

