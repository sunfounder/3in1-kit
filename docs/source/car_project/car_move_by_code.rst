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

2. Bewegung durch Code
======================

Im vorherigen Projekt haben wir versucht, den Betrieb des Motors durch Verwendung verschiedener Pegelsignale für den Eingang des L9110-Moduls zu steuern.

Wenn wir die Pegelsignale über das Programm ändern, können wir die Bewegung des Autos flexibel steuern.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - TEILE IN DIESEM SET
        - LINK
    *   - 3-in-1 Starter-Set
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
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-

**Verdrahtung**

Verbinden Sie die Drähte zwischen dem L9110-Modul und dem R3-Board gemäß dem untenstehenden Diagramm.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L9110 Modul
      - R3 Board
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
      - Schwarzer Draht des rechten Motors
    * - OA(B)
      - 
      - Roter Draht des rechten Motors
    * - OB(A)
      - 
      - Schwarzer Draht des linken Motors
    * - OA(A)
      - 
      - Roter Draht des linken Motors

.. image:: img/car_2.png
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``2.move.ino`` im Pfad ``3in1-kit\car_project\2.move``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6ff67dfb-a1c1-474b-a106-6acbb3a39e6f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nach dem Hochladen des Codes auf das R3-Board richten Sie das Linienverfolgungsmodul unter dem Auto auf die schwarze Linie aus und Sie werden sehen, wie das Auto der Linie folgt.

**Wie funktioniert das?**

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/Dpxpb4wSq5k?si=ep6p_jzhm-DPU9w4" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Dieses Projekt ist im Wesentlichen dasselbe wie das vorherige und beinhaltet, dass das Auto vorwärts, rückwärts, links und rechts fährt, sowie durch Bereitstellung verschiedener Signalpegel an den Eingabepins des L9110-Moduls anhält.

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

#. Legen Sie die Eingangspins auf verschiedene hohe oder niedrige Pegel, um die Drehung der linken und rechten Motoren zu steuern, und kapseln Sie sie in einzelne Funktionen.

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
    
    Schreibt einen HIGH- oder LOW-Wert auf einen digitalen Pin. Wenn der Pin mit ``pinMode()`` als ``OUTPUT`` konfiguriert wurde, wird seine Spannung auf den entsprechenden Wert gesetzt: 5V (oder 3,3V auf 3,3V-Platinen) für HIGH, 0V (Masse) für LOW.

* `pinMode(pin, mode) <https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/>`_

    * ``pin``: die Arduino-Pin-Nummer, für die der Modus eingestellt werden soll.
    * ``mode``: INPUT, OUTPUT oder INPUT_PULLUP.
    
    Konfiguriert den angegebenen Pin, um sich entweder als Eingang oder als Ausgang zu verhalten.

* `delay(ms) <https://www.arduino.cc/reference/en/language/functions/time/delay/>`_

    * ``ms``: die Anzahl der Millisekunden zum Pausieren. Zulässige Datentypen: unsigned long.

    Pausiert das Programm für die angegebene Zeit (in Millisekunden). (Es gibt 1000 Millisekunden in einer Sekunde.)
