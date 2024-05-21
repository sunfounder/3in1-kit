.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_threshold:

5.2 しきい値
=======================

多くのプロジェクトで、次のような要求に直面します。
「xxxがあるレベルに達したとき、次に...」

例えば、スマートホームでは、光の強度が50Lux未満の場合、照明を点けます；
もう一つの例は、コンピュータのマザーボードで、CPUの動作温度が65℃以上の場合、ファンを起動します。

これらの要求で、"しきい値"というキーワードが反映されます。

しきい値の数値を調整することで、回路の動作を個々のニーズに合わせて最適化できます。
例えば、私が明るい生活環境を好む場合、スマートホームの自動照明のしきい値を80Luxに上げることができます。
もう一つの例は、私のスタジオの換気環境があまり良くなく、放熱の要求が高い場合、自動ファンの開始のしきい値を50℃に調整できます。

ここでは、土壌湿度センサーと2つのLEDを使用して、鉢のモニターを作ります。土壌が乾燥していると赤いLEDが点灯し、土壌が十分に湿っていると緑のLEDが点灯します。土壌の乾燥と湿潤を判断するためのしきい値を手動で調整する必要があります。

**必要な部品**

このプロジェクトには、以下の部品が必要です。

一式を購入するのは非常に便利です、リンクはこちらです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクから、部品を個別に購入することもできます。

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
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**回路図**

.. image:: img/circuit_8.2_threshold.png

**配線図**

.. image:: img/threshold_bb.png
    :width: 600
    :align: center

**コード**

.. note::

    * ``3in1-kit\basic_project\5.2.threshold`` のパス下の ``5.2.threshold.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/9936413a-6e6c-4e57-b0c6-5df58dd48a3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードが正しくアップロードされた後、しきい値が正しく設定されている場合、土壌が乾燥していると赤いLEDが点灯して水をやる必要があることを知らせます。水をやった後、緑のLEDが点灯します。

**どのように動作するのか？**

.. code-block:: Arduino

    ...

    void loop() {
        int sensorValue = analogRead(soilMoisture);
        Serial.println(sensorValue);
        if (sensorValue > threshold) {
            digitalWrite(redPin, HIGH); // 赤いLEDを点灯
            digitalWrite(greenPin, LOW); // 緑をオフ
        } else {
            digitalWrite(greenPin, HIGH); // 緑のLEDを点灯
            digitalWrite(redPin, LOW); // 赤をオフ
        }
    }
    ...

まず、 ``threshold`` 値を設定し、その後、土壌湿度モジュールの値を読み取ります。湿度が高くなるとその値は減少します。現在読み取った値が設定した ``threshold`` よりも大きい場合、赤いLEDを点灯させ、そうでない場合は緑のLEDを点灯させます。

この ``threshold`` 値は実際の状況に応じて調整する必要があります。まず、コードをアップロードし、シリアルモニタを開いて値を確認します。濡れている状態と乾燥している状態の値を記録し、その中間の値を ``threshold`` 値として選択します。
