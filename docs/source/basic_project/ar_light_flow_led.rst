6.1 光感知配列
=====================================

フォトレジスタまたはフォトセルは、光によって変動する抵抗器です。フォトレジスタの抵抗は、入射光の強度が増加するにつれて減少します。言い換えれば、フォトコンダクティビティを示します。フォトレジスタは、光感知検出回路や、光と闇で動作するスイッチング回路に適用することができます。

フォトレジスタの抵抗は、入射光の強度によって変わります。光の強度が高くなると、抵抗は減少します。光の強度が低くなると、抵抗は増加します。
この実験では、光の強度を示すために8つのLEDを使用します。光の強度が高いほど、多くのLEDが点灯します。光の強度が十分に高い場合、すべてのLEDが点灯します。光がない場合、すべてのLEDは消灯します。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

一式を購入するのは非常に便利です、リンクはこちらです:

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**回路図**

.. image:: img/circuit_6.1_light_led.png

**配線図**

.. image:: img/6.1_light_flow_led_bb.png
    :width: 600
    :align: center

**コード**

.. note::

    * ``3in1-kit\learning_project\6.1.light_control_led`` のパスの下の ``6.1.light_control_led.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーしてください。
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/859e1688-5801-400e-9409-f844ca9b7da7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
フォトレジスタに光を当てると、いくつかのLEDが点灯します。さらに光を当てると、さらに多くのLEDが点灯します。暗い環境に置くと、すべてのLEDが消えます。

**どのように動作するのか？**

.. code-block:: arduino

    void loop() 
    {
        sensorValue = analogRead(photocellPin); // A0の値を読み取る
        ledLevel = map(sensorValue, 300, 1023, 0, NbrLEDs); // LEDの数にマッピングする
        for (int led = 0; led < NbrLEDs; led++)//
        {
            if (led < ledLevel ) // ledがledLevelよりも小さい場合、以下のコードを実行します。
            {
                digitalWrite(ledPins[led], HIGH); // レベル以下のピンをオンにする
            }
            else 
            {
                digitalWrite(ledPins[led],LOW); // レベル以上のピンをオフにする
            }
        }
    }

``map()`` 関数を使用して、フォトレジスタの値を8つのLEDにマッピングすることができます。例えば、sensorValueが560の場合、ledLevelは4となります。この時点で、ledPins[0]からledPins[4]が点灯し、ledPins[5]からledPins[7]が消灯することになります。
