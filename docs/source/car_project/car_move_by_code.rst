.. _car_move_code:

2. コードでの移動
======================

前のプロジェクトでは、L298Nの入力の異なるレベルの信号を使用してモーターの操作を制御しました。

プログラムを通じてレベル信号を変更することで、車の動きを柔軟に制御することができます。
ここでは、L298NのIN1〜IN4ピンをR3ボードの5、6、9、10ピンに順に接続します。

**必要な部品**

このプロジェクトには以下の部品が必要です。

キット全体を購入すると非常に便利です。リンクは以下のとおりです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクからそれぞれ個別に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネントの紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l298n`
        - |link_l298n_buy|
    *   - :ref:`cpn_tt_motor`
        - \-


**配線図**

L298Nモータードライバモジュールは、DCモーターとステッピングモーターを駆動するための高出力モータードライバモジュールです。L298Nモジュールは、最大で4台のDCモーター、または方向と速度の制御が可能な2台のDCモーターを制御することができます。

以下の図に従って、L298NモジュールとR3ボードの間にワイヤーを接続してください。

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L298N
      - R3ボード
      - モーター
    * - IN1
      - 5
      - 
    * - IN2
      - 6
      - 
    * - IN3
      - 9
      - 
    * - IN4
      - 10
      - 
    * - OUT1
      - 
      - 右モーターの黒ワイヤー
    * - OUT2
      - 
      - 右モーターの赤ワイヤー
    * - OUT3
      - 
      - 左モーターの黒ワイヤー
    * - OUT4
      - 
      - 左モーターの赤ワイヤー

.. image:: img/car_motor1.jpg
    :width: 800

**コード**

.. note::

    * ``3in1-kit\car_project\2.move`` のパスの下の ``2.move.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーしてください。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6ff67dfb-a1c1-474b-a106-6acbb3a39e6f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードをアップロードすると、車はそれぞれ2秒間で前進、後退、左右に移動します。


**どのように動作するのか？**

このプロジェクトは基本的に前回のものと同じで、IN1からIN4までの異なるレベルを与えることで車を前進、後退、左右に動かし、停止させるものです。

#. IN1~IN4のピン配線を初期化する。

    .. code-block:: arduino

        const int in1 = 5;
        const int in2 = 6;
        const int in3 = 9;
        const int in4 = 10;

        void setup() {
            pinMode(in1, OUTPUT);
            pinMode(in2, OUTPUT);
            pinMode(in3, OUTPUT);
            pinMode(in4, OUTPUT);
        }

#. 左右のモーターの回転を制御するためにIN1~IN4を異なるハイまたはローレベルに設定し、それらを個別の関数にカプセル化する。

    .. code-block:: arduino

        void moveForward() {
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
        }

        void moveBackward() {
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
        }
        ...

#. ``loop()`` でこれらの関数を呼び出す。

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
    
    デジタルピンにHIGHまたはLOWの値を書き込む。ピンが ``pinMode()`` で ``OUTPUT`` として設定されていれば、その電圧は対応する値に設定されます：HIGHの場合は5V（または3.3Vボードで3.3V）、LOWの場合は0V（グラウンド）。

* `pinMode(pin, mode) <https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/>`_

    * ``pin``: モードを設定するArduinoのピン番号。
    * ``mode``: INPUT、OUTPUT、またはINPUT_PULLUP。
    
    指定されたピンを入力または出力として動作するように設定します。

* `delay(ms) <https://www.arduino.cc/reference/en/language/functions/time/delay/>`_

    * ``ms``: 一時停止するミリ秒数。許可されるデータタイプ: unsigned long。

    パラメータとして指定された時間（ミリ秒）の間、プログラムを一時停止します。（1秒には1000ミリ秒があります。）

