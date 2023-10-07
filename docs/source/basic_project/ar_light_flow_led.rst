6.1 光によって制御される流れるLED
=====================================

光抵抗またはフォトセルは、光によって変化する可変抵抗です。光抵抗の抵抗は、入射光の強度が増加すると減少します。言い換えれば、これは光電導を示しています。光抵抗は、光感応検出回路や、光と暗闇に反応するスイッチ回路に適用できます。

光抵抗の抵抗は、入射光の強度によって変化します。光の強度が高くなると、抵抗は減少し、光の強度が低くなると、抵抗は増加します。この実験では、光の強度を示すために8つのLEDを使用します。光の強度が十分に高いと、すべてのLEDが点灯します。光がない場合、すべてのLEDは消えます。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

キット全体を購入するのは確かに便利です、リンクはこちら：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクから、それぞれの部品も購入することができます。

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**回路図**

.. image:: img/circuit_6.1_light_led.png

**配線図**

.. image:: img/light_control_led.png
    :width: 800
    :align: center

**コード**

.. note::

    * ``3in1-kit\basic_project\6.1.light_control_led`` のパスの下で ``6.1.light_control_led.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/859e1688-5801-400e-9409-f844ca9b7da7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

光抵抗に光を当てると、いくつかのLEDが点灯します。もっと光を当てると、さらに多くのLEDが点灯します。暗い環境に置くと、すべてのLEDが消えます。

**どのように動作するのか？**

.. code-block:: arduino

    void loop() 
    {
        sensorValue = analogRead(photocellPin); // A0の値を読む
        ledLevel = map(sensorValue, 300, 1023, 0, NbrLEDs); // LEDの数にマップする
        for (int led = 0; led < NbrLEDs; led++)
        {
            if (led < ledLevel ) // ledがledLevelより小さい場合、以下のコードを実行します
            {
                digitalWrite(ledPins[led], HIGH); // レベルより低いピンをオンにする
            }
            else 
            {
                digitalWrite(ledPins[led],LOW); // レベルより高いピンをオフにする
            }
        }
    }

``map()`` 関数を使用することで、光抵抗の値を8つのLEDにマップすることができます。例えば、sensorValueが560の場合、ledLevelは4となり、この時点でledPins[0]からledPins[4]までが点灯し、ledPins[5]からledPins[7]までが消灯することになります。

