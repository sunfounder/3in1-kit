.. _self_driving:

8. 自動運転車
=========================

このプロジェクトは、:ref:`car_ultrasonic` と :ref:`car_ir_obstacle` の二つのプロジェクトを組み合わせたものです。 
2つの赤外線障害物回避モジュールは、短距離やエッジの検出を行い、
超音波モジュールは長距離検出を行って、自由な運転過程で車が障害物にぶつからないことを確認します。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

全体のキットを購入するのが確かに便利です、リンクはこちらです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクから、部品を個別に購入することもできます。

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

超音波をR3ボードに以下のように配線します。

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

2つのIR障害物回避モジュールのR3ボードへの配線は以下の通りです。

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

    * ``3in1-kit\car_project\8.self_driving_car`` のパスの下の ``8.self_driving_car.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0a74a7b1-ead6-4bea-ab5a-4da71f27f82f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、車は自由に走り始めます。両側のIR障害物モジュールが障害物を検出すると、緊急回避のために逆方向に移動します。もし車の正面2~10cm以内に障害物がある場合、左にバックアップして方向を調整し、その後前進します。

**どのように動作するのか？**

このプロジェクトのワークフローは以下の通りです。

* 左右のIR障害物回避モジュールの値を優先して読み取ります。
* 左のIRモジュールが0（障害物検出）、右のIRモジュールが1の場合、車を左にバックアップさせます。
* 右のIRモジュールが0（障害物検出）の場合、車を右にバックアップさせます。
* 2つのIRモジュールが同時に障害物を検出する場合、車はバックアップします。
* それ以外の場合は、超音波モジュールによって検出された距離を読み取ります。
* 距離が50cm以上の場合、車を前進させます。
* 距離が2-10cmの場合、転回する前に車を後退させます。
* 距離が10-50cmの場合、車を低速で前進させます。


.. code-block:: arduino

    void loop() {

        int left = digitalRead(leftIR);   // 0: 遮断 1: 空
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
            } else if (distance < 10 && distance > 2) { // 注目
                moveBackward(200);
                delay(1000);
                backLeft(150);
                delay(500);
            } else {
                moveForward(150);
            }
        }
    }

