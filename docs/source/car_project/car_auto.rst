.. _self_driving:

8. 自動運転車
=========================

このプロジェクトは、 :ref:`car_ultrasonic` と :ref:`car_ir_obstacle` の2つのプロジェクトの組み合わせです。
2つの赤外線障害物回避モジュールは短距離またはエッジ検出を行い、
超音波モジュールは車が自由に走行する過程で障害物に衝突しないことを確認するための長距離検出を行います。

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

    * ``3in1-kit\car_project\8.self_driving_car`` のパスの下にある ``8.self_driving_car.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0a74a7b1-ead6-4bea-ab5a-4da71f27f82f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、車は自由に走行します。両側のIR障害物モジュールが障害物を検出すると、緊急回避のために逆方向に移動します。車の正面2~10cmに障害物がある場合、左にバックアップし、方向を調整して前進します。

**どのように動作するのか？**

このプロジェクトのワークフローは以下の通りです。

* 左右のIR障害物回避モジュールの値を優先して読み取ります。
* 左のIRモジュールが0（障害物を検出）、右のIRモジュールが1の場合、車を左にバックアップします。
* 右のIRモジュールが0（障害物検出）の場合、車を右にバックアップします。
* 2つのIRモジュールが同時に障害物を検出すると、車はバックアップします。
* それ以外の場合は、超音波モジュールによって検出された距離を読み取ります。
* 距離が50cm以上の場合、車を前進させます。
* 距離が2-10cmの場合、転回する前に車を後進させます。
* 距離が10-50cmの場合、車を低速で前進させます。

.. code-block:: arduino

    void loop() {

        int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
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
            if (distance > 50) { // Safe
                moveForward(200);
            } else if (distance < 10 && distance > 2) {  // Attention
                moveBackward(200);
                delay(1000);
                backLeft(150);
                delay(500);
            } else {
                moveForward(150);
            }
        }
    }

