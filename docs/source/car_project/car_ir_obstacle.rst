.. _car_ir_obstacle:

5. 障害物回避モジュールで遊ぶ
===============================================

車の前部には2つの赤外線障害物回避モジュールが取り付けられており、近くの障害物を検出するのに使用できます。

このプロジェクトでは、車は自由に前進することができ、障害物に遭遇した場合、それを回避して他の方向に移動を続けることができます。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

全てのキットをまとめて購入するのは非常に便利です。こちらがリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクから別々に購入することもできます。

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
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

**配線図**

障害物回避モジュールは、距離を調整可能な赤外線近接センサーであり、障害物を検出した場合には通常の出力は高く、低くなります。

以下の図に従って回路を作成してください。

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

.. image:: img/car_avoid.jpg
    :width: 800

**モジュールの調整**

プロジェクトを開始する前に、モジュールの検出距離を調整する必要があります。

上記の図に従って配線し、R3ボードに電源を供給してください（USBケーブルを直接接続するか、9Vの電池ケーブルを取り付けることによって）。コードをアップロードせずに、IR障害物回避の前に約5cmのノートや他の平らな物を置きます。

次に、モジュールの信号インジケータがちょうど点灯するまで、モジュール上のポテンショメータをドライバーで回して、最大検出距離を5cmに調整します。

もう一つの赤外線モジュールも同じ方法で調整します。

.. image:: img/ir_obs_cali.jpg


**コード**

.. note::

    * ``3in1-kit\car_project\5.obstacle_avoidance_module`` のパスの下で ``5.obstacle_avoidance_module.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/289ca80d-009f-4f60-b36d-1da6c5e10233/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、車は前進します。左の赤外線モジュールが障害物を検出すると、車は左に後退します。右の赤外線モジュールが障害物を検出すると、車は右に後退します。両方の側面で障害物を検出すると、車はまっすぐ後退します。

**どのように動作するか？**

このプロジェクトは、左右の赤外線障害物回避モジュールの値に基づいて、車に適切な動作をさせるものです。

#. 2つの障害物回避モジュールのピン定義を追加します。ここでは、 ``INPUT`` に設定されています。

    .. code-block:: arduino

        ...
        const int rightIR = 7;
        const int leftIR = 8;

        void setup() {
        ...

        //IR障害物
            pinMode(leftIR, INPUT);
            pinMode(rightIR, INPUT);
        }

#. 左右の赤外線モジュールの値を読み取り、車に対応する動作をさせます。

    .. code-block:: arduino

        void loop() {

            int left = digitalRead(leftIR);   // 0: 障害物あり  1: 空
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

    * 左のIRモジュールが0（障害物検出）で、右のIRモジュールが1の場合、車は左に後退します。
    * 右のIRモジュールが0（障害物検出）の場合、車は右に後退します。
    * 2つのIRモジュールが同時に障害物を検出すると、車は後退します。
    * それ以外の場合、車は前進し続けます。

#. ``backLeft()`` 関数について。

    右のモーターが反時計回りに回転し、左のモーターが回転していない場合、車は左に後退します。 

    .. code-block:: arduino

        void backLeft(int speed) {
            analogWrite(in1, speed);
            analogWrite(in2, 0);
            analogWrite(in3, 0);
            analogWrite(in4, 0);
        }

#. ``backLeft()`` 関数について。

    左のモーターが時計回りに回転し、右のモーターが回転していない場合、車は右に後退します。

    .. code-block:: arduino

        void backRight(int speed) {
            analogWrite(in1, 0);
            analogWrite(in2, 0);
            analogWrite(in3, 0);
            analogWrite(in4, speed);
        }

* `&& <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicaland/>`_: 両方のオペランドが真の場合にのみ、論理ANDは真を返します。

* `! <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicalnot/>`_: オペランドが偽の場合、論理NOTは真を返します。

