.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _follow_your_hand:

7. 手を追いかける
=========================

この車をここでのペットと考え、手を振ると、あなたの方へ走ってきます。

**必要なコンポーネント**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入すると非常に便利です、リンクは以下です：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットに含まれるアイテム
        - リンク
    *   - 3 in 1 スターターキット
        - 380+
        - |link_3IN1_kit|

以下のリンクからそれぞれ購入することもできます。

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

**配線**

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

R3ボードへの2つのIR障害物回避モジュールの配線は次のとおりです。

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

.. image:: img/car_7_8.png
    :width: 800

**コード**

.. note::

    * ``3in1-kit\car_project\7.follow_your_hand`` のパスの下にある ``7.follow_your_hand.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/584e42c8-8842-4db0-93b5-f6f949b6ffca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされた後、車を地面に置きます。車の前方に手を5*10cmの距離で置くと、車はあなたの手を追って前進します。両側のIR障害物モジュールに手を近づけると、対応する方向にも曲がります。

**どのように動作するのか？**

このプロジェクトは、前の2つのプロジェクト :ref:`car_ultrasonic` および :ref:`car_ir_obstacle` の組み合わせですが、実装された効果は異なります。前の2つのプロジェクトは障害物を後方に検出していますが、ここでは手が前進または回転方向に追従することを検出しています。
このプロジェクトのワークフローは以下の通りです。

* 超音波モジュールで検出された距離と両方の赤外線モジュールの値を読み取ります。
* 距離が5〜10cmの場合、車を手に合わせて動かします。
* 左のIRモジュールが手を検出すると、左に曲がります。
* 右のIRモジュールが手を検出すると、右に曲がります。
* 赤外線モジュールと超音波モジュールのどちらも手を検出しない場合、車を停止させます。

.. code-block:: arduino

    void loop() {

        float distance = readSensorData();

        int left = digitalRead(leftIR);   // 0: Obstructed, 1: Empty
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
