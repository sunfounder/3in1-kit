.. _car_move_code:

2. Steuerung durch Code
===============================

Im vorherigen Projekt haben wir versucht, den Motor durch verschiedene Pegelsignale am Eingang des L298N zu steuern.

Wenn wir die Pegelsignale über das Programm ändern, können wir die Bewegung des Autos flexibel steuern. 
Hier verbinden wir die Pins IN1~IN4 des L298N der Reihe nach mit den Pins 5, 6, 9 und 10 auf dem R3-Board.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

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

Sie können diese auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l298n`
        - |link_l298n_buy|
    *   - :ref:`cpn_tt_motor`
        - \-

**Verdrahtung**

Das L298N-Motortreibermodul ist ein leistungsstarkes Treibermodul für DC- und Schrittmotoren. Das L298N-Modul kann bis zu 4 Gleichstrommotoren steuern oder 2 Gleichstrommotoren mit Richtungs- und Geschwindigkeitssteuerung.

Verbinden Sie die Drähte zwischen dem L298N-Modul und dem R3-Board gemäß dem untenstehenden Diagramm.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L298N
      - R3 Board
      - Motor
    * - IN1
      - 5
      - 
    * - IN2
      - 6
      - 
    * - IN3
      - 9
      - 
    * - IN4
      - 10
      - 
    * - OUT1
      - 
      - Schwarzes Kabel des rechten Motors
    * - OUT2
      - 
      - Rotes Kabel des rechten Motors
    * - OUT3
      - 
      - Schwarzes Kabel des linken Motors
    * - OUT4
      - 
      - Rotes Kabel des linken Motors

.. image:: img/car_motor1.jpg
    :width: 800


**Code**

.. note::

    * Öffnen Sie die Datei ``2.move.ino`` im Pfad ``3in1-kit\car_project\2.move``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d9c830d3-1371-4867-a2e7-18d85d0b9d25/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code hochgeladen wurde, wird das Auto jeweils zwei Sekunden lang vorwärts, rückwärts, links und rechts fahren.

**Wie funktioniert das?**

Dieses Projekt entspricht im Wesentlichen dem vorherigen. Es soll das Auto durch Ausgabe verschiedener Pegel von IN1 bis IN4 vorwärts, rückwärts, links, rechts fahren und anhalten lassen.

#. Initialisieren Sie die Pin-Verdrahtung von IN1~IN4.

    .. code-block:: arduino

        const int in1 = 5;
        const int in2 = 6;
        const int in3 = 9;
        const int in4 = 10;

        void setup() {
            pinMode(in1, OUTPUT);
            pinMode(in2, OUTPUT);
            pinMode(in3, OUTPUT);
            pinMode(in4, OUTPUT);
        }

#. Setzen Sie IN1~IN4 auf verschiedene hohe oder niedrige Pegel, um die Rotation der linken und rechten Motoren zu steuern, und kapseln Sie sie dann in einzelne Funktionen.

    .. code-block:: arduino

        void moveForward() {
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
        }

        void moveBackward() {
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
        }
        ...

#. Rufen Sie diese Funktionen in ``loop()`` auf.

    .. code-block:: arduino

        void loop() {
            moveForward();
            delay(2000);
            stopMove();
            delay(500);

            moveBackward();
            delay(2000);
            stopMove();
            delay(500);
        ...

* `digitalWrite(pin, value) <https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/>`_

    * ``pin``: die Arduino-Pinnummer.
    * ``value``: HIGH oder LOW.
    
    Schreibt einen HIGH- oder LOW-Wert auf einen digitalen Pin. Wenn der Pin mit ``pinMode()`` als ``OUTPUT`` konfiguriert wurde, wird seine Spannung auf den entsprechenden Wert gesetzt: 5V (oder 3,3V bei 3,3V-Platinen) für HIGH, 0V (Masse) für LOW.

* `pinMode(pin, mode) <https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/>`_

    * ``pin``: die Arduino-Pinnummer, für die der Modus eingestellt werden soll.
    * ``mode``: INPUT, OUTPUT oder INPUT_PULLUP.
    
    Konfiguriert den angegebenen Pin, um entweder als Eingang oder als Ausgang zu fungieren.

* `delay(ms) <https://www.arduino.cc/reference/en/language/functions/time/delay/>`_

    * ``ms``: die Anzahl der Millisekunden zur Pause. Zulässige Datentypen: unsigned long.

    Unterbricht das Programm für die als Parameter angegebene Zeit (in Millisekunden). (Eine Sekunde enthält 1000 Millisekunden.)

