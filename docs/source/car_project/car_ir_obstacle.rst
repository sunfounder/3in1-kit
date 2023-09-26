.. _car_ir_obstacle:

5. 障害物回避モジュールを使って遊ぼう
===============================================

車の前部には二つの赤外線障害物回避モジュールが取り付けられており、近くの障害物を検出することができます。

このプロジェクトでは、車は自由に前進することができ、障害物に遭遇した場合、それを回避して他の方向に移動を続けることができます。

**必要な部品**

このプロジェクトには以下の部品が必要です。

全体のキットを購入すると非常に便利です、リンクはこちら：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

下のリンクから個別に購入することもできます。

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
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

**配線図**

障害物回避モジュールは、障害物を検出したときに低く、通常は高い出力を持つ距離調整可能な赤外線近接センサーです。

下の図に従って回路を組み立ててください。

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

.. image:: img/car_5.png
    :width: 800

**モジュールの調整**

プロジェクトを開始する前に、モジュールの検出距離を調整する必要があります。

上の図に従って配線し、R4ボードに電源を供給します（USBケーブルを直接差し込むか、9Vのバッテリーケーブルをスナップするかのいずれか）、コードはアップロードしません。

IR障害物回避の前方約5cmの位置にノートや他の平らな物を置きます。

その後、モジュールの信号インジケータがちょうど点灯するまで、モジュール上のポテンショメータをドライバーで回して、最大検出距離を5cmに調整します。

同じ方法で別の赤外線モジュールも調整してください。

.. image:: img/ir_obs_cali.jpg


**コード**

.. note::

    * ``3in1-kit\car_project\5.obstacle_avoidance_module`` のパス下で ``5.obstacle_avoidance_module.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/289ca80d-009f-4f60-b36d-1da6c5e10233/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、車は前進します。左の赤外線モジュールが障害物を検出すると、左側に後退します；右の赤外線モジュールが障害物を検出すると、右側に後退します；両方の赤外線モジュールが障害物を検出すると、直接後退します。

**どのように動作しますか？**

このプロジェクトは、左右の赤外線障害物回避モジュールの値に基づいて、車に適切な動作をさせるものです。

#. 2つの障害物回避モジュールのピン定義を追加します。ここでは ``INPUT`` に設定されています。

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

#. 左右の赤外線モジュールの値を読み取り、車に対応する動作をさせます。

    .. code-block:: arduino

        void loop() {

            int left = digitalRead(leftIR);   // 0: 障害物あり  1: 空き
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

    * 左IRモジュールが0（障害物を検出）で、右IRモジュールが1の場合、車を左に後退させます。
    * 右IRモジュールが0（障害物を検出）の場合、車を右に後退させます。
    * 2つのIRモジュールが同時に障害物を検出すると、車は後退します。
    * それ以外の場合、車は前進し続けます。

#. ``backLeft()`` 関数について。

    右モーターが反時計回りに回転し、左モーターが回転しないと、車は左に後退します。

    .. code-block:: arduino

        void backLeft(int speed) {
            analogWrite(A_1B, speed);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, 0);
        }

#. ``backRight()`` 関数について。

    左モーターが時計回りに回転し、右モーターが回転しないと、車は右に後退します。

    .. code-block:: arduino

        void backRight(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, speed);
        }

* `&& <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicaland/>`_: 両方のオペランドが真の場合にのみ真となる論理AND。

* `! <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicalnot/>`_: オペランドが偽の場合に真となり、その逆もまた真となる論理NOT。

