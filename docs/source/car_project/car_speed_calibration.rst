.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _speed_calibration:

11. 速度のキャリブレーション
=============================

車を前進させる際、車がまっすぐ進まないことがあります。
これは、工場出荷時に2つのモーターの速度が同じでない可能性があるためです。
しかし、2つのモーターにオフセットを書き込むことで、それらの回転速度を収束させることができます。

このプロジェクトでは、 `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ にオフセットを保存する方法を学びます。この目的は、各キャリブレーション後、すべてのプロジェクトがEEPROMから直接オフセット値を取得できるようにするため、車がスムーズにまっすぐ進むことができます。

**配線**

このプロジェクトの配線は :ref:`car_move_code` と同じです。

**遊び方は？**

1. ``3in1-kit\car_project\11.speed_calibration`` のパスの下にある ``11.speed_calibration.ino`` ファイルを開きます。または、このコードを **Arduino IDE** にコピーします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/66dc7ee5-31a5-418e-9aa2-43e7820cf5e6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


2. コードが正常にアップロードされた後、車を9Vのバッテリーに接続し、地面に置いて前進させ、どちら側にオフセットされているかを確認します。

* 車が左前方に進む場合、右モーターの速度が速すぎることを意味し、速度を減少させる必要があります。

    .. code-block:: arduino

        EEPROM.write(1, 100) // 1 means the right motor, 100 means 100% speed, can be set to 90, 95, etc., depending on the actual situation.

* 車が右側に移動する場合、左モーターの速度が速すぎることを意味し、速度を減少させる必要があります。

    .. code-block:: arduino

        EEPROM.write(0, 100) // 0 means the right motor, 100 means the speed is 100%, can be set to 90, 95, etc., depending on the actual situation. 3.

3. コードを変更した後、R3ボードにコードをアップロードして効果を確認します。車がほぼまっすぐになるまで上記の手順を繰り返します。

4. このオフセットは `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ に記録されます。他のプロジェクトで使用する際には、このオフセットを読み取るだけでよく、 :ref:`car_ir_obstacle` を例として参照してください。

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

