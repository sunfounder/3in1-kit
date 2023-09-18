.. _ar_beep:

1.2 ビープ
==================
アクティブブザーはLEDを点灯させるのと同じくらい簡単に使える典型的なデジタル出力デバイスです！

キットには2種類のブザーが含まれています。
アクティブブザーを使用する必要があります。裏返してみると、密封された背面（露出しているPCBではない）が必要なものです。

.. image:: img/buzzer.png

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

全体のキットを購入するのは非常に便利です。リンクはこちら：

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

    *   - コンポーネント紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_buzzer`
        - \-

**回路図**

.. image:: img/circuit_1.2_beep.png

**配線図**

.. image:: img/wiring_active_buzzer.png
    :width: 400
    :align: center

**コード**

.. note::

   * ファイル ``1.2.beep.ino`` を ``3in1-kit\basic_project\1.2.beep`` のパスで開くことができます。
   * または、このコードを **Arduino IDE** にコピーします。
   
   * あるいは、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/95570ca2-11c6-404c-a23f-bf03094d8085/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、毎秒ビープ音が聞こえます。
