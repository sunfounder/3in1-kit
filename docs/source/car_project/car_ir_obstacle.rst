.. _car_ir_obstacle:

5. 障害物回避モジュールで遊ぶ
===============================================

車の前部には2つの赤外線障害物回避モジュールが取り付けられており、近くの障害物を検出するのに使用できます。

このプロジェクトでは、車は自由に前進することが許されており、障害物に遭遇した場合、それを避けて他の方向に移動を続けることができます。

**必要なコンポーネント**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入することは非常に便利です。こちらがリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットのアイテム数
        - リンク
    *   - 3 in 1 スターターキット
        - 380+
        - |link_3IN1_kit|

以下のリンクからそれぞれの部品を別々に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネント紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

**配線**

障害物回避モジュールは、出力が通常高く、障害物が検出されると低くなる距離調整可能な赤外線近接センサーです。

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/vadNtXwITFc?si=gY4Ww31zmcs8AObP" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>


以下の図に従って回路を組み立てます。

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

.. image:: img/car_5.png
    :width: 800

**モジュールの調整**

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/calibrate_ir.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>

プロジェクトを開始する前に、モジュールの検出距離を調整する必要があります。

上記の図に従って配線し、R3ボードに電源を供給します（USBケーブルを直接差し込むか、9Vのバッテリーケーブルをスナップしてください）。コードをアップロードせずに。

車のIR障害物回避の前にノートや他の平らな物体を約5cm置きます。

次に、モジュール上のポテンショメーターを回して、モジュールの信号インジケーターがちょうど点灯するまで調整し、最大検出距離を5cmに調整します。

同じ方法で別の赤外線モジュールを調整します。

.. image:: img/ir_obs_cali.jpg

**コード**

.. note::

    * ``3in1-kit\car_project\5.obstacle_avoidance_module`` のパスの下にある ``5.obstacle_avoidance_module.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。

    * または、`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/289ca80d-009f-4f60-b36d-1da6c5e10233/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、車は前進します。左の赤外線モジュールが障害物を検出すると、左に後退します。右の赤外線モジュールが障害物を検出すると、右に後退します。両方の側面で障害物が検出された場合、後退します。

**動作原理は？**

このプロジェクトは、左と右の赤外線障害物回避モジュールの値に基づいて車が適切なアクションを実行するものです。

1. 2つの障害物回避モジュールのピン定義を追加します。ここでは ``INPUT`` に設定されています。

    .. code-block:: arduino

        ...
        const int rightIR = 7;
        const int leftIR = 8;

        void setup() {
        ...

        //IR障害物回避
            pinMode(leftIR, INPUT);
            pinMode(rightIR, INPUT);
        }

2. 左および右の赤外線モジュールの値を読み取り、車に対応するアクションを実行させます。

    .. code-block:: arduino

        void loop() {

            int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
            int right = digitalRead(rightIR);
            int speed = 150;

            if (!left && right) {
                backLeft(speed);
            } else if (left && !right) {
                backRight(speed);
            } else if (!left && !right) {
                moveBackward(speed);
            } else {
                moveForward(speed);
            }
        }

    * 左のIRモジュールが0（障害物検出）で、右のIRモジュールが1の場合、車を左に後退させます。
    * 右のIRモジュールが0（障害物検出）の場合、車を右に後退させます。
    * 2つのIRモジュールが同時に障害物を検出すると、車は後退します。
    * それ以外の場合、車は前進し続けます。

3. ``backLeft()`` 関数について。

    右のモーターが反時計回りに回転し、左のモーターが回転しない場合、車は左に後退します。

    .. code-block:: arduino

        void backLeft(int speed) {
            analogWrite(A_1B, speed);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, 0);
        }

4. ``backLeft()`` 関数について。

    左のモーターが時計回りに回転し、右のモーターが回転しない場合、車は右に後退します。

    .. code-block:: arduino

        void backRight(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, speed);
        }

* `&& <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicaland/>`_: ロジカルANDは、両方のオペランドが真の場合にのみ真となります。

* `! <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicalnot/>`_: ロジカルNOTは、オペランドが偽の場合は真、逆の場合は偽となります。
