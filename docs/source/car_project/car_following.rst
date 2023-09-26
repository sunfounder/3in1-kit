.. _follow_your_hand:

7. 手を追う車
=========================

この車をペットのように考えて、手を振ると車があなたの方に走ってきます。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

キット全体を購入するのは確かに便利です。以下がリンクです：

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

**配線図**

超音波モジュールと2つのIR障害物回避モジュールを同時に接続します。

R4ボードに超音波を次のように配線します。

.. list-table:: 
    :header-rows: 1

    * - 超音波モジュール
      - R4ボード
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

R4ボードへの2つのIR障害物回避モジュールの配線は次のとおりです。

.. list-table:: 
    :header-rows: 1

    * - 左IRモジュール
      - R4ボード
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - 右IRモジュール
      - R4ボード
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_7_8.png
    :width: 800

**コード**

.. note::

    * ``3in1-kit\car_project\7.follow_your_hand`` のパスの下で ``7.follow_your_hand.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。

    * または、 `Arduino ウェブエディター <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/584e42c8-8842-4db0-93b5-f6f949b6ffca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされたら、車を地面に置きます。車の前で5*10cmの距離で手を近づけると、車はあなたの手を前に追って進みます。IR障害物モジュールの両側に手を近づけると、対応する方向に転向します。

**動作原理**

このプロジェクトは前の2つのプロジェクト、 :ref:`car_ultrasonic` と :ref:`car_ir_obstacle` 、の組み合わせですが、実装された効果は異なります。前の2つのプロジェクトは障害物を後ろから検知していましたが、このプロジェクトでは、あなたの手が前進または方向転換を追いかけるのを検知しています。
このプロジェクトのワークフローは以下の通りです。

* 超音波モジュールによって検知された距離と、両方の赤外線モジュールの値を読み取ります。
* 距離が5〜10cmの場合、車をあなたの手と一緒に動かします。
* 左のIRモジュールがあなたの手を検知した場合、左に曲がります。
* 右のIRモジュールがあなたの手を検知した場合、右に曲がります。
* 赤外線モジュールも超音波モジュールもあなたの手を検知しない場合、車を停止させます。

.. code-block:: arduino

    void loop() {

        float distance = readSensorData();

        int left = digitalRead(leftIR);   // 0: 遮蔽物あり 1: 空
        int right = digitalRead(rightIR);
        int speed = 150;

        if (distance>5 && distance<10){
            moveForward(speed);
        }
        if(!left&&right){
            turnLeft(speed);
        }else if(left&&!right){
            turnRight(speed);
        }else{
            stopMove();
        }
    }