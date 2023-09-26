.. _ar_threshold:

5.2 閾値
=======================

多くのプロジェクトで、以下のようなニーズに遭遇するでしょう。
「xxxがあるレベルに達したら、その後…」

例えば、スマートホームでは、光の強度が50Lux以下の場合、ライトを点灯する。
もう一つの例として、コンピュータのマザーボードでは、CPUの動作温度が65度以上になるとファンを起動する、など。

これらの要件では、「閾値」というキーワードが反映されています。

閾値の値を調整することで、回路の動作を個々のニーズに合わせて調整することができます。
例えば、私がもっと明るい生活環境を好む場合、スマートホームの自動照明の閾値を80Luxに上げることができます。
また、私のスタジオの換気環境があまり良くなく、放熱要求が高い場合、自動ファン開始の閾値を50度に調整することができます。

ここでは、土の湿度センサーと2つのLEDを使用して、鉢のモニターを作成します。土が乾燥していると赤いLEDが点灯し、土が十分に湿っていると緑のLEDが点灯します。土の乾燥と湿潤を判定する閾値は手動で調整する必要があります。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

一式を購入するのが便利です、リンクはこちら:

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
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**回路図**

.. image:: img/circuit_8.2_threshold.png

**配線図**

.. image:: img/5.2_threshold_bb.png
    :width: 600
    :align: center

**コード**

.. note::

    * ``3in1-kit\learning_project\5.2.threshold`` のパスの下の ``5.2.threshold.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/9936413a-6e6c-4e57-b0c6-5df58dd48a3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードが正常にアップロードされた後、閾値が正しく設定されていれば、土が乾燥していると赤いLEDが点灯し、水をやる必要があることを知らせてくれます。水をやった後、緑のLEDが点灯します。

**動作原理**

.. code-block:: Arduino

    ...

    void loop() {
        int sensorValue = analogRead(soilMoisture);
        Serial.println(sensorValue);
        if (sensorValue > threshold) {
            digitalWrite(redPin, HIGH); // 赤いLEDを点灯
            digitalWrite(greenPin, LOW); // 緑
        } else {
            digitalWrite(greenPin, HIGH); // 緑のLEDを点灯
            digitalWrite(redPin, LOW); // 赤
        }
    }
    ...

まず、 ``threshold`` の値を設定し、次に土の湿度モジュールの値を読み取ります。湿度レベルが上がると、その値は減少します。現在読み取った値が設定した ``threshold`` よりも大きい場合、赤いLEDを点灯させます。それ以外の場合は、緑のLEDを点灯させます。

この ``threshold`` の値は、実際の状況に応じて調整する必要があります。まずコードをアップロードして、シリアルモニターを開いて値を確認します。湿潤と乾燥の状態での値を記録し、その中間の値を ``threshold`` の値として選びます。
