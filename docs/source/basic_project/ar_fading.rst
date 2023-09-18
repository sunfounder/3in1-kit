.. _ar_fading:

2.1 フェージング
=================

このプロジェクトは :ref:`ar_blink` に似ていますが、信号の種類が異なります。
前者はデジタル信号（0&1）を出力してLEDの点灯/消灯を制御するのに対し、このプロジェクトはアナログ信号を出力してLEDの明るさを調節します。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

キット全体を購入すると非常に便利です。リンクは以下の通りです。

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクから、個別にも購入可能です。

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

**回路図**

.. image:: img/circuit_1.1_led.png

**配線図**

.. image:: img/wiring_led.png
    :width: 500
    :align: center

**コード**

.. note::

   * ``3in1-kit\basic_project\2.analogWrite\2.1.fading`` のパスの下の ``2.1.fading.ino`` ファイルを開くことができます。
   * または、このコードを **Arduino IDE** にコピーしてください。
   
   * あるいは、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8a7e52a4-fcb3-4c3b-98ff-f3f657822d72/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードが正常にアップロードされた後、LEDが息を吹きかえしているのが見えます。
