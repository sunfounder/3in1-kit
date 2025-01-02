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

前のプロジェクトでは、L9110モジュールの入力に対して異なるレベルの信号を使用してモーターの動作を制御する方法を試みました。

プログラムを通じてレベル信号を変更すると、車の動きを柔軟に制御することができます。

**必要なコンポーネント**

このプロジェクトでは、以下のコンポーネントが必要です。

便利なのは、全体のキットを購入することです。リンクはこちら：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットに含まれるアイテム
        - リンク
    *   - 3 in 1 スターターキット
        - 380+
        - |link_3IN1_kit|

以下のリンクから個別に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネントの説明
        - 購入リンク

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-

**配線**

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/Dpxpb4wSq5k?si=ep6p_jzhm-DPU9w4" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>


以下の図に従って、L9110モジュールとR3ボードの間にワイヤを接続します。

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L9110 モジュール
      - R3 ボード
      - モーター
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
      - 右モーターの黒いワイヤ
    * - OA(B)
      - 
      - 右モーターの赤いワイヤ
    * - OB(A)
      - 
      - 左モーターの黒いワイヤ
    * - OA(A)
      - 
      - 左モーターの赤いワイヤ

.. image:: img/car_2.png
    :width: 800

**コード**

.. note::

    * ``3in1-kit\car_project\2.move`` のパスで ``2.move.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6ff67dfb-a1c1-474b-a106-6acbb3a39e6f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードをアップロードした後、車はそれぞれ2秒間前進、後退、左回転、右回転します。

**どのように動作するか？**

このプロジェクトは基本的に前のプロジェクトと同じで、L9110モジュールの入力ピンに異なる信号レベルを提供することで、車を前進、後退、左回転、右回転させるか、または停止させることができます。

#. L9110モジュールのピンを初期化します。

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

#. 左右のモーターの回転を制御するために入力ピンを異なる高または低レベルに設定し、それらを個別の関数でカプセル化します。

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

#. これらの関数を ``loop()`` で呼び出します。

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
    
    ピンをデジタルに設定して、HIGHまたはLOWの値を書き込みます。もしピンが ``pinMode()`` で ``OUTPUT`` として設定されていれば、その電圧は対応する値に設定されます：HIGHの場合は5V（3.3Vのボードでは3.3V）、LOWの場合は0V（接地）。

* `pinMode(pin, mode) <https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/>`_

    * ``pin``: モードを設定するArduinoのピン番号。
    * ``mode``: INPUT、OUTPUT、またはINPUT_PULLUP。
    
    指定されたピンが入力または出力として動作するように設定します。

* `delay(ms) <https://www.arduino.cc/reference/en/language/functions/time/delay/>`_

    * ``ms``: 一時停止するミリ秒数。許容されるデータタイプ: unsigned long。

    指定された時間（ミリ秒）だけプログラムを一時停止します。（1秒には1000ミリ秒があります。）

