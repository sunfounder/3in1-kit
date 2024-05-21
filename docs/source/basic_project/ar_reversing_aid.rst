.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_reversing_aid:

6.4 駐車補助
===================

科学技術の発展に伴い、多くの高度な技術製品が車に取り付けられています。その中で、バックアップ補助システムは一つです。この章では、超音波モジュール、LCD、LED、ブザーを使用して、シンプルな超音波駐車補助システムを作成します。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

全セットを購入すると非常に便利です。以下がリンクです:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

下のリンクから個別に購入することもできます。

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

.. image:: img/6.4_reversing_aid_bb.png
    :width: 800
    :align: center

**コード**

.. note::

    * ファイル ``6.4_reversingAid.ino`` を ``3in1-kit\learning_project\6.4_reversingAid`` のパスで直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。
    * ここでは ``LiquidCrystal I2C`` ライブラリを使用しています。 **Library Manager** からインストールできます。

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d6848669-fe79-42e9-afd7-0f083f96a6d6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、LCDに検出された現在の距離が表示されます。そして、距離に応じてブザーの音の頻度が変わります。

.. note::
    コードと配線が正しいのに、LCDに内容が表示されない場合は、裏面のポテンショメータを回して調整してください。

**どのように動作するのか？**

このコードは、物体との距離を測定し、LCDディスプレイとブザーを通じてフィードバックを提供するシンプルな距離測定デバイスを作成するのに役立ちます。

``loop()`` 関数はプログラムの主要なロジックを含み、継続的に実行されます。 ``loop()`` 関数を詳しく見てみましょう。

#. 距離を読み取り、パラメータを更新するループ

    ``loop`` 内のコードは、超音波モジュールで測定された距離を最初に読み取り、距離に基づいて間隔のパラメータを更新します。

    .. code-block:: arduino

        // 距離を更新
        distance = readDistance();

        // 距離に基づいて間隔を更新
        if (distance <= 10) {
            intervals = 300;
        } else if (distance <= 20) {
            intervals = 500;
        } else if (distance <= 50) {
            intervals = 1000;
        } else {
            intervals = 2000;
        }

#. ビープ音の時間かどうかを確認する

    コードは、現在の時間と前回のビープ音の時間との差を計算し、その差が間隔の時間以上の場合、ブザーをトリガーして、前回のビープ音の時間を更新します。

    .. code-block:: arduino

        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= intervals) {
            Serial.println("Beeping!");
            beep();
            previousMillis = currentMillis;
        }

#. LCDディスプレイを更新

    コードは、LCDディスプレイをクリアし、次に "Dis:" と現在の距離（センチメートル）を1行目に表示します。

    .. code-block:: arduino

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dis: ");
        lcd.print(distance);
        lcd.print(" cm");

        delay(100);
