.. _follow_your_hand:

7. 手を追いかける車
=========================

この車をペットと考えてください。あなたが手を振ると、その車はあなたのもとへと駆けてきます。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

キットを購入するのが便利です。以下がリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

下記のリンクから部品を個別に購入することも可能です。

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

**配線図**

超音波モジュールと2つのIR障害物回避モジュールを同時に接続します。

R3ボードに超音波を次のように接続します。

.. list-table:: 
    :header-rows: 1

    * - 超音波モジュール
      - R3ボード
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

2つのIR障害物回避モジュールのR3ボードへの配線は次の通りです。

.. list-table:: 
    :header-rows: 1

    * - 左IRモジュール
      - R3ボード
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - 右IRモジュール
      - R3ボード
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_avoid_ultrasonic.jpg
    :width: 800

**コード**

.. note::

    * ``3in1-kit\car_project\7.follow_your_hand`` のパスの下で ``7.follow_your_hand.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーペーストします。
    * あるいは、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/584e42c8-8842-4db0-93b5-f6f949b6ffca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされたら、車を地面に置きます。車の前に手を5〜10cm程度近づけると、車は手の方向に進むように追従します。IR障害物モジュールの両側に手を近づけると、対応する方向にも曲がります。

**どのように動作するのか？**

このプロジェクトは以前の二つのプロジェクト、 :ref:`car_ultrasonic` と  :ref:`car_ir_obstacle` の組み合わせですが、実現される効果は異なります。以前の2つのプロジェクトは障害物を後ろで検出していましたが、ここでは手が前方または回転方向に追従するのを検出します。
このプロジェクトのワークフローは次のとおりです。

* 超音波モジュールによって検出された距離と両方の赤外線モジュールの値を読み取ります。
* 距離が5〜10cmの場合、車を手に合わせて動かします。
* 左のIRモジュールが手を検出した場合、左に曲がります。
* 右のIRモジュールが手を検出した場合、右に曲がります。
* 赤外線モジュールも超音波モジュールも手を検出しない場合、車を停止させます。

.. code-block:: arduino

    void loop() {

        float distance = readSensorData();

        int left = digitalRead(leftIR);   // 0: 遮断 1: 空
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