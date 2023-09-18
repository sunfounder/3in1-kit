.. _speed_calibration:

11. 速度のキャリブレーション
===============================

車を前進させる際、車がまっすぐ進まないことがあるかもしれません。
これは、工場での2つのモーターの速度が同じでないためです。
しかし、2つのモーターにオフセットを書き込むことで、それらの回転速度を一致させることができます。

このプロジェクトでは、オフセットを `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ に保存する方法を学びます。この目的は、キャリブレーション後に、すべてのプロジェクトがEEPROMから直接オフセット値を取得できるようにするためです。
これにより、車はスムーズに直線で進むことができます。

**配線図**

このプロジェクトの配線は :ref:`car_move_code` と同じです。

**遊び方は？**

1. ``3in1-kit\car_project\11.speed_calibration`` のパス下の ``11.speed_calibration.ino`` ファイルを開く。または、このコードを **Arduino IDE** にコピーします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/66dc7ee5-31a5-418e-9aa2-43e7820cf5e6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

2. コードが正常にアップロードされたら、車を9Vのバッテリーに接続し、地面に置いて前進させ、どちら側にオフセットされているかを確認します。

* 車が左前方に移動する場合、右モーターの速度が速すぎることを意味し、減速する必要があります。

    .. code-block:: arduino

        EEPROM.write(1, 100) // 1は右モータを意味し、100は速度が100%であることを意味します。実際の状況に応じて90、95などに設定することができます。

* 車が右に移動する場合、左モーターの速度が速すぎることを意味し、減速する必要があります。

    .. code-block:: arduino

        EEPROM.write(0, 100) // 0は左モーターを意味し、100は速度が100%であることを意味します。実際の状況に応じて90、95などに設定することができます。

3. コードを変更した後、R3ボードにコードをアップロードして効果を確認します。車がほぼまっすぐになるまで上記の手順を繰り返します。

4. このオフセットは `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ に記録されます。他のプロジェクトで使用する際にこのオフセットを読み込むだけでよく、 :ref:`car_ir_obstacle` が一例として取られます。



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

        //motor
        pinMode(in1, OUTPUT);
        pinMode(in2, OUTPUT);
        pinMode(in3, OUTPUT);
        pinMode(in4, OUTPUT);

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

