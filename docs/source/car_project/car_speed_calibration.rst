.. _speed_calibration:

11. Geschwindigkeitskalibrierung
==================================

Wenn Sie das Auto vorwärts bewegen, stellen Sie möglicherweise fest, dass es nicht geradeaus fährt.
Dies liegt daran, dass die beiden Motoren ab Werk möglicherweise nicht die gleiche Geschwindigkeit haben.
Wir können jedoch einen Offset zu den beiden Motoren hinzufügen, um ihre Drehgeschwindigkeiten anzugleichen.

In diesem Projekt
werden wir lernen, den Offset im `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ zu speichern. Der Vorteil davon ist, dass nach jeder Kalibrierung 
alle Projekte den Offset-Wert direkt aus dem EEPROM abrufen können,
damit das Auto reibungslos geradeaus fährt.

**Verdrahtung**

Dieses Projekt hat die gleiche Verdrahtung wie :ref:`car_move_code`.

**Wie spielt man?**

1. Öffnen Sie die Datei ``11.speed_calibration.ino`` im Pfad ``3in1-kit\car_project\11.speed_calibration``. Oder kopieren Sie diesen Code in die **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/66dc7ee5-31a5-418e-9aa2-43e7820cf5e6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

2. Nachdem der Code erfolgreich hochgeladen wurde, verbinden Sie das Auto mit einer 9V-Batterie, stellen Sie es auf den Boden und beobachten Sie, zu welcher Seite es versetzt ist.

* Wenn das Auto nach links vorne fährt, bedeutet dies, dass die Geschwindigkeit des rechten Motors zu hoch ist und reduziert werden muss.

    .. code-block:: arduino

        EEPROM.write(1, 100) // 1 means the right motor, 100 means 100% speed, can be set to 90, 95, etc., depending on the actual situation.

* Wenn das Auto nach rechts fährt, bedeutet dies, dass die Geschwindigkeit des linken Motors zu hoch ist und reduziert werden muss.

    .. code-block:: arduino

        EEPROM.write(0, 100) // 0 means the right motor, 100 means the speed is 100%, can be set to 90, 95, etc., depending on the actual situation. 3.

3. Nachdem Sie den Code geändert haben, laden Sie den Code auf das R4-Board, um den Effekt zu sehen. Wiederholen Sie die oben genannten Schritte, bis das Auto fast geradeaus fährt.

4. Dieser Offset wird im `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ gespeichert. Sie müssen diesen Offset nur lesen, wenn Sie ihn in anderen Projekten verwenden, nehmen Sie zum Beispiel :ref:`car_ir_obstacle`.

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

