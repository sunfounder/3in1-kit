.. _ar_potentiometer:

4.1 ノブを回す
===================

ポテンショメータは、3つの端子を持つ抵抗コンポーネントであり、その抵抗値は一定の変化に従って調整できます。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

一式を購入すると確かに便利です。以下がリンクです：

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**回路図**

.. image:: img/circuit_5.1_potentiometer.png

この例では、アナログピン(A0)を使用して、ポテンショメータの値を読み取ります。ポテンショメータの軸を回転させることで、これらの3つのピンの間での抵抗の分布を変更し、中央のピンの電圧を変更できます。中央と5Vに接続された外部ピンとの間の抵抗がほぼゼロに近く（中央ともう一方の外部ピンとの間の抵抗がほぼ10kΩに近い場合）、中央のピンの電圧は5Vに近くなります。逆の操作（中央と5Vに接続された外部ピンとの間の抵抗がほぼ10kΩに近い）は、中央のピンの電圧が0Vに近くなるでしょう。

**配線図**

.. image:: img/4.1_turn_thek_knob_bb.png
    :width: 600
    :align: center

**コード**

.. note::

   * ``3in1-kit\learning_project\4.1.turn_the_knob`` のパスの下にある ``4.1.turn_the_knob.ino`` ファイルを開くことができます。
   * または、このコードを **Arduino IDE** にコピーします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d931f2c9-74bc-4a53-8531-39a21a07dbaf/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

ボードにコードをアップロードすると、シリアルモニタを開いてピンの読み取り値を確認できます。ポテンショメータの軸を回転させると、シリアルモニタは「0」~「1023」の値を表示します。
