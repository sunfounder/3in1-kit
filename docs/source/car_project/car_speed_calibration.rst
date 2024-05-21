.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _speed_calibration:

11. Geschwindigkeitskalibrierung
==============================================

Beim Vorwärtsbewegen des Autos stellen Sie möglicherweise fest, dass das Auto nicht geradeaus fährt. 
Das liegt daran, dass die beiden Motoren möglicherweise ab Werk nicht die gleiche Geschwindigkeit haben. 
Wir können jedoch einen Ausgleich für die beiden Motoren schreiben, damit sich ihre Drehgeschwindigkeiten angleichen.

In diesem Projekt 
werden wir lernen, den Ausgleich in `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ zu speichern. Der Sinn dahinter ist, dass nach jeder Kalibrierung 
alle Projekte den Ausgleichswert direkt aus dem EEPROM abrufen können, 
damit das Auto reibungslos geradeaus fährt.

**Verdrahtung**

Dieses Projekt hat die gleiche Verdrahtung wie :ref:`car_move_code`.

**Wie spielt man?**

1. Öffnen Sie die Datei ``11.speed_calibration.ino`` im Pfad ``3in1-kit\car_project\11.speed_calibration``. Oder kopieren Sie diesen Code in die **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/66dc7ee5-31a5-418e-9aa2-43e7820cf5e6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

2. Nachdem der Code erfolgreich hochgeladen wurde, verbinden Sie das Auto mit einer 9V-Batterie, stellen Sie es auf den Boden und lassen Sie es vorwärts fahren, um zu sehen, zu welcher Seite es verschoben ist.

* Wenn das Auto nach links vorne fährt, bedeutet das, dass die Geschwindigkeit des rechten Motors zu hoch ist und reduziert werden muss.

    .. code-block:: arduino

        EEPROM.write(1, 100) // 1 bedeutet der rechte Motor, 100 bedeutet 100% Geschwindigkeit, kann je nach tatsächlicher Situation auf 90, 95 usw. gesetzt werden.

* Wenn das Auto nach rechts fährt, bedeutet das, dass die Geschwindigkeit des linken Motors zu schnell ist und reduziert werden muss.

    .. code-block:: arduino

        EEPROM.write(0, 100) // 0 bedeutet der linke Motor, 100 bedeutet die Geschwindigkeit beträgt 100%, kann je nach tatsächlicher Situation auf 90, 95 usw. gesetzt werden.

3. Nach der Code-Änderung laden Sie den Code auf das R3-Board hoch, um die Wirkung zu sehen. Wiederholen Sie die obigen Schritte, bis das Auto fast gerade fährt.

4. Dieser Ausgleich wird in `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ aufgezeichnet. Sie müssen diesen Ausgleich nur abrufen, wenn Sie ihn in anderen Projekten verwenden, nehmen Sie :ref:`car_ir_obstacle` als Beispiel.

.. code-block:: arduino
    :emphasize-lines: 1,3,4,27,28,50,51

    #include <EEPROM.h>

    float leftOffset = 1.0;
    float rightOffset = 1.0;

    const int A_1B = 5;
    const int A_1A = 6;
    const int B_1B = 9;
    const int B_1A = 10;

    const int rightIR = 7;
    const int leftIR = 8;

    void setup() {
        Serial.begin(9600);

        //motor
        pinMode(A_1B, OUTPUT);
        pinMode(A_1A, OUTPUT);
        pinMode(B_1B, OUTPUT);
        pinMode(B_1A, OUTPUT);

        //IR obstacle
        pinMode(leftIR, INPUT);
        pinMode(rightIR, INPUT);

        leftOffset = EEPROM.read(0) * 0.01;//read the offset of the left motor
        rightOffset = EEPROM.read(1) * 0.01;//read the offset of the right motor
    }

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

    void moveForward(int speed) {
        analogWrite(A_1B, 0);
        analogWrite(A_1A, int(speed * leftOffset));
        analogWrite(B_1B, int(speed * rightOffset));
        analogWrite(B_1A, 0);
    }

    void moveBackward(int speed) {
        analogWrite(A_1B, speed);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, speed);
    }

    void backLeft(int speed) {
        analogWrite(A_1B, speed);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, 0);
    }

    void backRight(int speed) {
        analogWrite(A_1B, 0);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, speed);
    }

