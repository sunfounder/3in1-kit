.. _speed_calibration:

11. Geschwindigkeitskalibrierung
====================================

Wenn Sie versuchen, das Auto vorwärts zu bewegen, stellen Sie möglicherweise fest, dass es nicht geradeaus fährt. 
Dies liegt daran, dass die beiden Motoren ab Werk möglicherweise nicht dieselbe Geschwindigkeit haben. 
Wir können jedoch einen Offset für die beiden Motoren schreiben, damit ihre Drehgeschwindigkeiten konvergieren.

In diesem Projekt lernen wir, den Offset im `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ zu speichern. Der Vorteil davon ist, dass nach jeder Kalibrierung alle Projekte den Offsetwert direkt aus dem EEPROM abrufen können, sodass das Auto reibungslos geradeaus fahren kann.

**Verdrahtung**

Die Verkabelung dieses Projekts entspricht :ref:`car_move_code`.

**Wie spielt man das?**

1. Öffnen Sie die Datei ``11.speed_calibration.ino`` im Pfad ``3in1-kit\car_project\11.speed_calibration`` oder kopieren Sie diesen Code in die **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/98757b03-349c-45e9-bd46-383921999a2f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

2. Nachdem der Code erfolgreich hochgeladen wurde, verbinden Sie das Auto mit einer 9V-Batterie, setzen Sie es auf den Boden und lassen Sie es vorwärts fahren, um zu sehen, zu welcher Seite es versetzt ist.

* Wenn das Auto nach links vorne fährt, bedeutet das, dass die Geschwindigkeit des rechten Motors zu hoch ist und reduziert werden muss.

    .. code-block:: arduino

        EEPROM.write(1, 100) // 1 steht für den rechten Motor, 100 bedeutet 100% Geschwindigkeit. Dies kann je nach tatsächlicher Situation auf 90, 95 usw. eingestellt werden.

* Wenn das Auto nach rechts fährt, bedeutet das, dass die Geschwindigkeit des linken Motors zu hoch ist und reduziert werden muss.

    .. code-block:: arduino

        EEPROM.write(0, 100) // 0 steht für den linken Motor, 100 bedeutet 100% Geschwindigkeit. Dies kann je nach tatsächlicher Situation auf 90, 95 usw. eingestellt werden.

3. Nachdem Sie den Code geändert haben, laden Sie den Code auf das R3-Board hoch, um den Effekt zu sehen. Wiederholen Sie die obigen Schritte, bis das Auto fast gerade fährt.

4. Dieser Offset wird im `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ gespeichert. Sie müssen diesen Offset nur lesen, wenn Sie ihn in anderen Projekten verwenden, zum Beispiel in :ref:`car_ir_obstacle`.

.. code-block:: arduino
    :emphasize-lines: 1,3,4,27,28,50,51

    #include <EEPROM.h>

    float leftOffset = 1.0;
    float rightOffset = 1.0;

    const int in1 = 5;
    const int in2 = 6;
    const int in3 = 9;
    const int in4 = 10;

    const int rightIR = 7;
    const int leftIR = 8;

    void setup() {
        Serial.begin(9600);

        //Motor
        pinMode(in1, OUTPUT);
        pinMode(in2, OUTPUT);
        pinMode(in3, OUTPUT);
        pinMode(in4, OUTPUT);

        //IR-Hindernis
        pinMode(leftIR, INPUT);
        pinMode(rightIR, INPUT);

        leftOffset = EEPROM.read(0) * 0.01; // Offset des linken Motors lesen
        rightOffset = EEPROM.read(1) * 0.01; // Offset des rechten Motors lesen
    }

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

    void moveForward(int speed) {
        analogWrite(in1, 0);
        analogWrite(in2, int(speed * leftOffset));
        analogWrite(in3, int(speed * rightOffset));
        analogWrite(in4, 0);
    }

    void moveBackward(int speed) {
        analogWrite(in1, speed);
        analogWrite(in2, 0);
        analogWrite(in3, 0);
        analogWrite(in4, speed);
    }

    void backLeft(int speed) {
        analogWrite(in1, speed);
        analogWrite(in2, 0);
        analogWrite(in3, 0);
        analogWrite(in4, 0);
    }

    void backRight(int speed) {
        analogWrite(in1, 0);
        analogWrite(in2, 0);
        analogWrite(in3, 0);
        analogWrite(in4, speed);
    }

