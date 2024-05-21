.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _car_speed:

3. 速度の上昇
===================

デジタル信号（HIGH/LOW）に加えて、L9110モジュールの入力はPWM信号も受け取ることができ、出力の速度を制御します。

言い換えれば、 ``AnalogWrite()`` を使用して車の移動速度を制御することができます。

このプロジェクトでは、車が前進速度を徐々に変えるようにしました。最初に加速し、その後減速します。

**配線**

このプロジェクトの配線は :ref:`car_move_code` と同じです。

**コード**

.. note::

    * ``3in1-kit\car_project\3.speed_up`` のパスの下の ``3.speed_up.ino`` ファイルを開く。
    * または、このコードを **Arduino IDE** にコピーする。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードする。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c15276c1-2359-4de6-ac82-a14a72e041c6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

プログラムが実行されると、車は徐々に加速し、次に徐々に減速します。

**どのように動作するのか？**

このプロジェクトの目的は、L9110モジュールの入力ピンに異なるPWM値を書き込むことで、車の前進速度を制御することです。

#. ``for()`` 文を使用して、0から255までの値を5のステップで ``speed`` に与えることで、車の前進速度の変化を確認できます。

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

    :ref:`car_move_code` ではL9110モジュールの入力ピンに直接高/低レベルを与えていますが、ここでは高レベルを与える必要がある場所に ``speed`` パラメータを渡します。

    .. code-block:: arduino

        void moveForward(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, speed);
            analogWrite(B_1B, speed);
            analogWrite(B_1A, 0);
        }

* `for <https://www.arduino.cc/reference/en/language/structure/control-structure/for/>`_

``for`` 文は、波括弧で囲まれた文のブロックを繰り返し実行するために使用されます。インクリメントカウンタは通常、ループのインクリメントと終了のために使用されます。

    .. code-block:: arduino

        for (initialization; condition; increment) {
        // statement(s);
        }

    * ``initialization``: 最初に一度だけ実行されます。
    * ``condition``: ループを通じて毎回、conditionがテストされる; それが真の場合、文のブロックとインクリメントが実行され、その後conditionが再びテストされる。conditionがfalseになると、ループは終了する。
    * ``increment``: conditionがtrueのときにループを通じて実行されます。

