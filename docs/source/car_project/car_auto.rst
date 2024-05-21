.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _self_driving:

8. 自動運転車
=========================

このプロジェクトは、 :ref:`car_ultrasonic` および :ref:`car_ir_obstacle` の2つのプロジェクトの組み合わせです。 
2つの赤外線障害物回避モジュールは短距離または端の検出を行い、
超音波モジュールは長距離の検出を行い、自由に運転する過程で車が障害物にぶつからないことを確認します。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

一式を購入するのは便利です。リンクはこちら：

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

R4ボードに超音波を以下のように接続します。

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

R4ボードへの2つのIR障害物回避モジュールの接続方法は次の通りです。

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

    * パス ``3in1-kit\car_project\8.self_driving_car`` の下にある ``8.self_driving_car.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * あるいは、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0a74a7b1-ead6-4bea-ab5a-4da71f27f82f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、車は自由に運転します。両側のIR遮断モジュールが障害物を検出すると、緊急回避のために反対方向に移動します。車の正面2〜10cm以内に障害物がある場合、車は左にバックアップして方向を調整し、前進します。

**どのように動作するのか？**

このプロジェクトのワークフローは以下の通りです。

* 左右のIR障害物回避モジュールの値を優先的に読み取ります。
* 左のIRモジュールが0（障害物検出）で、右のIRモジュールが1の場合、車は左にバックアップします。
* 右のIRモジュールが0（障害物検出）の場合、車は右にバックアップします。
* 2つのIRモジュールが同時に障害物を検出すると、車はバックアップします。
* それ以外の場合は、超音波モジュールによって検出された距離を読み取ります。
* 距離が50cm以上の場合、車を前進させます。
* 距離が2-10cmの場合、車を旋回する前にバックアップします。
* 距離が10-50cmの場合、車は低速で前進します。

.. code-block:: arduino

    void loop() {

        int left = digitalRead(leftIR);   // 0: 遮蔽物あり 1: 空
        int right = digitalRead(rightIR);

        if (!left && right) {
            backLeft(150);
        } else if (left && !right) {
            backRight(150);
        } else if (!left && !right) {
            moveBackward(150);
        } else {
            float distance = readSensorData();
            Serial.println(distance);
            if (distance > 50) { // 安全
                moveForward(200);
            } else if (distance < 10 && distance > 2) { // 注意
                moveBackward(200);
                delay(1000);
                backLeft(150);
                delay(500);
            } else {
                moveForward(150);
            }
        }
    }

