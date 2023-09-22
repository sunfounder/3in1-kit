.. _car_ir_obstacle:

5. Spielen mit dem Hindernisvermeidungsmodul
===============================================

Zwei Infrarot-Hindernisvermeidungsmodule sind an der Vorderseite des Autos montiert und können dazu verwendet werden, nahegelegene Hindernisse zu erkennen.

In diesem Projekt darf sich das Auto frei vorwärts bewegen. Wenn es auf ein Hindernis trifft, kann es dieses vermeiden und in andere Richtungen weiterfahren.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können diese auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENVORSTELLUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l298n`
        - |link_l298n_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

**Verdrahtung**

Das Hindernisvermeidungsmodul ist ein abstandseinstellbarer Infrarot-Näherungssensor, dessen Ausgang normalerweise hoch ist und auf niedrig schaltet, wenn ein Hindernis erkannt wird.

Bauen Sie nun den Schaltkreis gemäß dem untenstehenden Diagramm.

.. list-table:: 
    :header-rows: 1

    * - Linkes IR-Modul
      - R3-Board
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - Rechtes IR-Modul
      - R3-Board
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_avoid.jpg
    :width: 800

**Modul einstellen**

Bevor Sie mit dem Projekt beginnen, müssen Sie die Erkennungsentfernung des Moduls einstellen.

Verkabeln Sie entsprechend dem obigen Diagramm, schalten Sie das R3-Board ein (entweder durch direktes Einstecken des USB-Kabels oder durch Anschließen des 9V-Batteriekabels), ohne den Code hochzuladen.

Stellen Sie ein Notebook oder ein anderes flaches Objekt etwa 5 cm vor das IR-Hindernisvermeidungsmodul.

Drehen Sie dann mit einem Schraubendreher das Potentiometer am Modul, bis die Signalleuchte am Modul gerade aufleuchtet, um seine maximale Erkennungsentfernung von 5 cm einzustellen.

Verfahren Sie auf die gleiche Weise, um ein weiteres Infrarotmodul einzustellen.

.. image:: img/ir_obs_cali.jpg


**Code**

.. note::

    * Öffnen Sie die Datei ``5.obstacle_avoidance_module.ino`` im Pfad ``3in1-kit\car_project\5.obstacle_avoidance_module``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/02f5fb43-4943-4942-9cbe-ca3487d4b433/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Das Auto wird sich vorwärts bewegen, sobald der Code erfolgreich hochgeladen wurde. Wenn das linke Infrarotmodul ein Hindernis erkennt, wird es nach links rückwärts fahren; wenn das rechte Infrarotmodul ein Hindernis erkennt, wird es nach rechts rückwärts fahren; wenn beide Seiten ein Hindernis erkennen, wird es gerade rückwärts fahren.

**Wie funktioniert das?**

Dieses Projekt basiert auf den Werten der linken und rechten Infrarot-Hindernisvermeidungsmodule, um dem Auto die entsprechende Aktion zu ermöglichen.

#. Fügen Sie die Pin-Definition für die 2 Hindernisvermeidungsmodule hinzu, hier sind sie als ``INPUT`` eingestellt.

    .. code-block:: arduino

        ...
        const int rightIR = 7;
        const int leftIR = 8;

        void setup() {
        ...

        //IR-Hindernisvermeidung
            pinMode(leftIR, INPUT);
            pinMode(rightIR, INPUT);
        }


#. Lesen Sie die Werte der linken und rechten Infrarotmodule aus und lassen Sie das Auto die entsprechende Aktion durchführen.

    .. code-block:: arduino

        void loop() {

            int left = digitalRead(leftIR);   // 0: Blockiert  1: Frei
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

    * Wenn das linke IR-Modul 0 ist (Hindernis erkannt) und das rechte IR-Modul 1, soll das Auto nach links zurücksetzen.
    * Wenn das rechte IR-Modul 0 ist (Hindernis erkannt), soll das Auto nach rechts zurücksetzen.
    * Wenn beide IR-Module gleichzeitig ein Hindernis erkennen, wird das Auto rückwärts fahren.
    * Andernfalls wird das Auto weiter vorwärts fahren.

#. Über die Funktion ``backLeft()``.

    Wenn der rechte Motor gegen den Uhrzeigersinn dreht und der linke Motor nicht dreht, wird das Auto nach links zurückfahren.

    .. code-block:: arduino

        void backLeft(int speed) {
            analogWrite(in1, speed);
            analogWrite(in2, 0);
            analogWrite(in3, 0);
            analogWrite(in4, 0);
        }

#. Über die Funktion ``backLeft()``.

    Wenn der linke Motor im Uhrzeigersinn dreht und der rechte Motor nicht dreht, wird das Auto nach rechts zurückfahren.

    .. code-block:: arduino

        void backRight(int speed) {
            analogWrite(in1, 0);
            analogWrite(in2, 0);
            analogWrite(in3, 0);
            analogWrite(in4, speed);
        }

* `&& <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicaland/>`_: Logisches UND ergibt nur dann wahr, wenn beide Operanden wahr sind.

* `! <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicalnot/>`_: Logisches NICHT ergibt wahr, wenn der Operand falsch ist, und umgekehrt.

