.. _ar_ir_obstacle:

3.3 障害物を検出する
===================================

このモジュールは、前方の障害物の存在を判断するために車やロボットに一般的に取り付けられています。また、携帯デバイスや水道の蛇口など、幅広い用途で使用されています。

**必要な部品**

このプロジェクトには、以下の部品が必要です。

キット全体を購入するのは非常に便利です。こちらがリンクです:

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
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

**回路図**

.. image:: img/circuit_3.3_obstacle.png

デジタルピン2はIR障害物回避モジュールの信号を読むために使用されます。IRセンサーモジュールのVCCを5Vに、GNDをGNDに、OUTをデジタルピン2に接続します。

**配線図**

.. image:: img/3.3_detect_the_obstacle_bb.png
    :width: 800
    :align: center

**コード**

.. note::

   * ``3in1-kit\learning_project\3.3.detect_the_obstacle`` のパスの下にある ``3.3.detect_the_obstacle.ino`` ファイルを開くことができます。
   * または、このコードを **Arduino IDE** にコピーしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/535a0304-684e-481d-b85d-403911b3a4e2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

IR障害物回避モジュールが前方に何かをブロックしていることを検出すると、シリアルモニターに[0]が表示され、それ以外の場合は[1]が表示されます。
