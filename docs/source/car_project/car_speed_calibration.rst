.. _speed_calibration:

11. 速度のキャリブレーション
===============================

車を前進させる際、車がまっすぐ進まないことがあります。
これは、工場出荷時に2つのモーターの速度が同じでないためです。
しかし、2つのモーターにオフセットを書き込むことで、その回転速度を一致させることができます。

このプロジェクトでは、
オフセットを `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ に保存する方法を学びます。これのポイントは、キャリブレーションの後、
すべてのプロジェクトがEEPROMから直接オフセット値を取得できるため、
車がスムーズにまっすぐ進むことができます。

**配線図**

このプロジェクトの配線は、 :ref:`car_move_code` と同じです。

**遊び方は？**

1. パス ``3in1-kit\car_project\11.speed_calibration`` の下の ``11.speed_calibration.ino`` ファイルを開く。または、このコードを **Arduino IDE** にコピーします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/66dc7ee5-31a5-418e-9aa2-43e7820cf5e6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

2. コードが正常にアップロードされた後、車に9Vのバッテリーを接続し、地面に置いて前進させ、どちらの方向にオフセットされているかを確認します。

* 車が左前方に移動する場合、右のモーターの速度が早すぎることを意味し、減速する必要があります。

    .. code-block:: arduino

        EEPROM.write(1, 100) // 1は右モーターを意味し、100は速度が100%であることを意味します。実際の状況に応じて90、95などに設定できます。

* 車が右に移動する場合、左のモーターの速度が早すぎることを意味し、減速する必要があります。

    .. code-block:: arduino

        EEPROM.write(0, 100) // 0は左モーターを意味し、100は速度が100%であることを意味します。実際の状況に応じて90、95などに設定できます。

3. コードを修正した後、R4ボードにコードをアップロードして効果を確認します。車がほぼまっすぐになるまで、上記の手順を繰り返します。

4. このオフセットは `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ に記録されます。他のプロジェクトで使用する際には、このオフセットを読むだけでよく、例として :ref:`car_ir_obstacle` を参照してください。



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

        leftOffset = EEPROM.read(0) * 0.01;//右モーターのオフセットを読み取る
        rightOffset = EEPROM.read(1) * 0.01;//右モーターのオフセットを読み取る
    }

    void loop() {

        int left = digitalRead(leftIR);   // 0: 遮蔽物あり 1: 空
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

