.. _ar_reversing_aid:

6.4 駐車補助
===================

科学技術の発展に伴い、多くのハイテク製品が車に取り付けられています。その中で、バックアップアシストシステムはその一つです。このプロジェクトでは、超音波モジュール、LCD、LED、およびブザーを使用して、シンプルな超音波駐車補助システムを作成します。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入するのが便利です。リンクはこちら：

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
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**回路図**

.. image:: img/image265.png
    :width: 800
    :align: center

**配線図**

.. image:: img/backcar.png
    :width: 800
    :align: center

**コード**

.. note::

    * ``3in1-kit\basic_project\6.4_reversingAid`` のパスの下の ``6.4_reversingAid.ino`` ファイルを直接開くことができます。
    * または、このコードをArduino IDE 1/2にコピーします。
    * ここでは ``LiquidCrystal I2C`` ライブラリが使用されています。 **Library Manager** からインストールできます。

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d6848669-fe79-42e9-afd7-0f083f96a6d6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードのアップロードが成功すると、現在検出された距離がLCDに表示されます。そして、ブザーは異なる距離に応じて音の周波数を変えます。

.. note::
    コードと配線が正しいのに、LCDに内容が表示されない場合は、裏側のポテンショメーターを回してみてください。

**どのように動作するのか？**

このプロジェクトでは、LCD画面とアラームシステムの間の干渉をできるだけ避ける必要があります（例えば、LEDの点滅時間が長すぎるとLCDのリフレッシュが遅れる）。そのため、 ``delay()`` 文を使用せず、LCDとアラームシステムの動作周波数をそれぞれ制御するための2つの別々のインターバルを使用してください。そのワークフローはフローチャートで示されています。Interval関数の解析については、 :ref:`ar_interval` を参照してください。

.. image:: img/Part_three_1_Example_Explanation.png
   :align: center
