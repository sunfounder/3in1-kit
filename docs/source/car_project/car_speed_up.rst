.. _car_speed:

3. スピードアップ
===================

デジタル信号（HIGH/LOW）に加えて、L298Nの入力はPWM信号も受け取ることができ、これにより出力の速度を制御することができます。

つまり、 ``AnalogWrite()`` を使用して車の移動速度を制御することができます。

このプロジェクトでは、車が前進する速度を徐々に変えるようにしています。最初は加速し、その後は減速します。

**配線図**

このプロジェクトの配線は、 :ref:`car_move_code` と同じです。

**コード**

.. note::

    * ``3in1-kit\car_project\3.speed_up`` のパスの下で ``3.speed_up.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/4253e39c-3990-4a47-8a2a-047497b76e2d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

プログラムが実行されると、車は徐々に加速し、その後徐々に減速します。

**どのように動作するのか？**

このプロジェクトの目的は、IN1~IN4に異なるPWMの値を書き込むことで、車の前進速度を制御することです。

#. ``for()`` 文を使用して、0から255までの値を5のステップで ``speed`` に与え、車の前進速度の変化を確認します。

    .. code-block:: arduino

        void loop() {
            for(int i=0;i<=255;i+=5){
                moveForward(i);
                delay(500);
            }
            for(int i=255;i>=0;i-=5){
                moveForward(i);
                delay(500);
            }
        }

#. ``moveForward()`` 関数について。

    :ref:`car_move_code` ではIN1~IN4に直接高/低のレベルを与えていましたが、ここでは高いレベルを与える必要がある場所に ``speed`` パラメータを渡します。

    .. code-block:: arduino

        void moveForward(int speed) {
            analogWrite(in1, 0);
            analogWrite(in2, speed);
            analogWrite(in3, speed);
            analogWrite(in4, 0);
        }

* `for <https://www.arduino.cc/reference/en/language/structure/control-structure/for/>`_

``for`` 文は、波括弧で囲まれた文のブロックを繰り返し実行するために使用されます。増分カウンタは通常、ループを増分および終了するために使用されます。

    .. code-block:: arduino

        for (initialization; condition; increment) {
        // statement(s);
        }

    * ``initialization``: 最初に一度だけ実行されます。
    * ``condition``: ループを通るたびに、conditionがテストされます。trueであれば、文のブロックと増分が実行され、その後で再びconditionがテストされます。conditionがfalseになると、ループは終了します。
    * ``increment``: conditionがtrueのとき、ループを通じて実行されます。
