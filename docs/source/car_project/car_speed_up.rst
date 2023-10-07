.. _car_speed:

3. スピードアップ
===================

デジタル信号(HIGH/LOW)に加えて、L9110モジュールの入力は、出力の速度を制御するためのPWM信号も受け取ることができます。

つまり、 ``AnalogWrite()`` を使用して車の移動速度を制御することができます。

このプロジェクトでは、車の前進速度を徐々に変更させます。まず加速し、次に減速します。

**配線**

このプロジェクトの配線は :ref:`car_move_code` と同じです。

**コード**

.. note::

    * ``3in1-kit\car_project\3.speed_up`` のパスの下にある ``3.speed_up.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c15276c1-2359-4de6-ac82-a14a72e041c6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

プログラムが実行されると、車は徐々に加速し、その後徐々に減速します。

**仕組みは？**

このプロジェクトの目的は、L9110モジュールの入力ピンに異なるPWM値を書き込むことで、車の前進速度を制御することです。

#. ``for()``文を使用して、 ``speed`` を5のステップで与え、0から255までの値を書き込むことで、車の前進速度の変化を確認できます。

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

    :ref:`car_move_code` はL9110モジュールの入力ピンに直接高/低レベルを与えますが、ここでは高レベルを与える必要がある場所に ``speed`` パラメータを渡します。

    .. code-block:: arduino

        void moveForward(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, speed);
            analogWrite(B_1B, speed);
            analogWrite(B_1A, 0);
        }

* `for <https://www.arduino.cc/reference/en/language/structure/control-structure/for/>`_

``for`` 文は、波括弧で囲まれた一連の文を繰り返し実行するために使用されます。増分カウンタは通常、ループを増分および終了するために使用されます。

    .. code-block:: arduino

        for (initialization; condition; increment){
        // 文;
        }

    * ``initialization``: 最初に一度だけ実行されます。
    * ``condition``: ループの各回で条件がテストされ、それが真であれば、文のブロックと増分が実行され、その後再び条件がテストされます。条件がfalseになると、ループは終了します。
    * ``increment``: 条件が真である場合、ループを通じて実行されます。

