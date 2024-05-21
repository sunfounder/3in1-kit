.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _car_move_code:

2. Steuerung durch Code
=========================

Im vorherigen Projekt haben wir versucht, den Betrieb des Motors zu steuern, indem wir für den Eingang des L9110-Moduls verschiedene Pegelsignale verwendet haben.

Wenn wir die Pegelsignale durch das Programm ändern, können wir die Bewegung des Autos flexibel steuern.

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

**Verdrahtung**

Verbinden Sie die Kabel zwischen dem L9110-Modul und dem R4-Board gemäß dem untenstehenden Diagramm.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L9110 Modul
      - R4 Board
      - Motor
    * - A-1B
      - 5
      - 
    * - A-1A
      - 6
      - 
    * - B-1B(B-2A)
      - 9
      - 
    * - B-1A
      - 10
      - 
    * - OB(B)
      - 
      - Schwarzes Kabel des rechten Motors
    * - OA(B)
      - 
      - Rotes Kabel des rechten Motors
    * - OB(A)
      - 
      - Schwarzes Kabel des linken Motors
    * - OA(A)
      - 
      - Rotes Kabel des linken Motors

.. image:: img/car_2.png
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``2.move.ino`` im Pfad ``3in1-kit\car_project\2.move``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6ff67dfb-a1c1-474b-a106-6acbb3a39e6f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nach dem Hochladen des Codes wird das Auto jeweils für zwei Sekunden vorwärts, rückwärts, links und rechts fahren.


**Wie funktioniert das?**

Dieses Projekt entspricht im Wesentlichen dem vorherigen. Es beinhaltet das Vorwärts-, Rückwärts-, Links- und Rechtsfahren des Autos sowie das Anhalten, indem verschiedene Signalpegel an die Eingangspins des L9110-Moduls gesendet werden.

#. Initialisieren Sie die Pins des L9110-Moduls.

    .. code-block:: arduino

        const int A_1B = 5;
        const int A_1A = 6;
        const int B_1B = 9;
        const int B_1A = 10;

        void setup() {
            pinMode(A_1B, OUTPUT);
            pinMode(A_1A, OUTPUT);
            pinMode(B_1B, OUTPUT);
            pinMode(B_1A, OUTPUT);
        }

#. Legen Sie die Eingangspins auf unterschiedlich hohe oder niedrige Pegel, um die Drehung der linken und rechten Motoren zu steuern, und kapseln Sie sie in einzelne Funktionen.

    .. code-block:: arduino

        void moveForward() {
            digitalWrite(A_1B, LOW);
            digitalWrite(A_1A, HIGH);
            digitalWrite(B_1B, HIGH);
            digitalWrite(B_1A, LOW);
        }

        void moveBackward() {
            digitalWrite(A_1B, HIGH);
            digitalWrite(A_1A, LOW);
            digitalWrite(B_1B, LOW);
            digitalWrite(B_1A, HIGH);
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

    * ``pin``: die Arduino-Pin-Nummer.
    * ``value``: HIGH oder LOW.
    
    Schreibt einen HIGH- oder LOW-Wert an einen digitalen Pin. Wenn der Pin mit ``pinMode()`` als ``OUTPUT`` konfiguriert wurde, wird seine Spannung auf den entsprechenden Wert gesetzt: 5V (oder 3,3V bei 3,3V-Boards) für HIGH, 0V (Masse) für LOW.

* `pinMode(pin, mode) <https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/>`_

    * ``pin``: die Arduino-Pin-Nummer, für die der Modus festgelegt werden soll.
    * ``mode``: INPUT, OUTPUT oder INPUT_PULLUP.
    
    Konfiguriert den angegebenen Pin entweder als Eingang oder Ausgang.

* `delay(ms) <https://www.arduino.cc/reference/en/language/functions/time/delay/>`_

    * ``ms``: die Anzahl der Millisekunden zum Pausieren. Erlaubte Datentypen: unsigned long.

    Pausiert das Programm für die angegebene Zeit (in Millisekunden). (In einer Sekunde sind 1000 Millisekunden.)

