.. _ar_ir_obstacle:

3.3 障害物を検出する
===================================

このモジュールは、前方の障害物の存在を判断するために、車やロボットに一般的に取り付けられています。また、ハンドヘルドデバイスや水道蛇口など、幅広い用途で使用されています。

**必要な部品**

このプロジェクトには、以下の部品が必要です。

全体のキットを購入すると非常に便利です。こちらがリンクです：

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

    *   - コンポーネント紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

**回路図**

.. image:: img/circuit_3.3_obstacle.png

デジタルピン2は、IR障害物回避モジュールの信号を読み取るために使用されます。IRセンサーモジュールのVCCを5Vに、GNDをGNDに、OUTをデジタルピン2に接続します。

**配線図**

.. image:: img/detect_the_obstacle_bb.jpg
    :width: 800
    :align: center

**コード**

.. note::

   * ``3in1-kit\basic_project\3.3.detect_the_obstacle`` のパスの下で ``3.3.detect_the_obstacle.ino`` ファイルを開くことができます。
   * または、このコードを **Arduino IDE** にコピーします。
   
   * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/535a0304-684e-481d-b85d-403911b3a4e2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

IR障害物回避モジュールが前方に何か障害物を検出すると、シリアルモニターに[0]が表示されます。それ以外の場合は、[1]が表示されます。
