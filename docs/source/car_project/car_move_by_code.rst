.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _car_move_code:

2. コードによる移動
======================

前のプロジェクトでは、L9110モジュールの入力に異なるレベルの信号を使用してモーターの動作を制御しました。

プログラムを通じてレベルの信号を変更すれば、車の動きを柔軟に制御することができます。

**必要な部品**

このプロジェクトには、以下の部品が必要です。

一式で購入すると便利です、リンクは以下の通りです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクから個別に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネントの紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-

**配線図**

以下の図に従って、L9110モジュールとR4ボードの間にワイヤを接続してください。

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L9110 モジュール
      - R4 ボード
      - モータ
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
      - 右モータの黒ワイヤ
    * - OA(B)
      - 
      - 右モータの赤ワイヤ
    * - OB(A)
      - 
      - 左モータの黒ワイヤ
    * - OA(A)
      - 
      - 左モータの赤ワイヤ

.. image:: img/car_2.png
    :width: 800

**コード**

.. note::

    * ``3in1-kit\car_project\2.move`` のパスの下の ``2.move.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6ff67dfb-a1c1-474b-a106-6acbb3a39e6f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードがアップロードされると、車はそれぞれ2秒間前進、後退、左折、右折をします。


**どのように動作するのか？**

このプロジェクトは基本的に前回のものと同じで、L9110モジュールの入力ピンに異なる信号レベルを提供することで、車を前進、後進、左折、右折させるだけでなく、停止させるものです。

#. L9110モジュールのピンを初期化する。

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

#. 左右のモーターの回転を制御するために入力ピンを異なる高さや低さのレベルに設定し、それを個別の関数にカプセル化する。

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

#. これらの関数を ``loop()`` で呼び出す。

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

    * ``pin``: Arduinoのピン番号。
    * ``value``: HIGHまたはLOW。
    
    デジタルピンにHIGHまたはLOWの値を書き込みます。ピンが ``pinMode()`` で ``OUTPUT`` として設定されている場合、その電圧は対応する値に設定されます：HIGHの場合は5V（3.3Vボードでは3.3V）、LOWの場合は0V（グランド）。

* `pinMode(pin, mode) <https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/>`_

    * ``pin``: モードを設定するArduinoのピン番号。
    * ``mode``: INPUT、OUTPUT、またはINPUT_PULLUP。
    
    指定されたピンを入力または出力として動作するように設定します。

* `delay(ms) <https://www.arduino.cc/reference/en/language/functions/time/delay/>`_

    * ``ms``: 一時停止するミリ秒数。許可されるデータタイプ: unsigned long。

    パラメータとして指定された時間（ミリ秒）の間、プログラムを一時停止します。（1秒は1000ミリ秒です。）
