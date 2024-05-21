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


このコードを使用すると、オブジェクト間の距離を測定し、LCDディスプレイとブザーを通じてフィードバックを提供するシンプルな距離測定装置を作成できます。

``loop()`` 関数はプログラムの主要なロジックを含み、連続して実行されます。 ``loop()`` 関数について詳しく見てみましょう。

#. 距離を読み取り、パラメータを更新するループ

    ``loop`` 内で、コードはまず超音波モジュールで測定された距離を読み取り、その距離に基づいてインターバルパラメータを更新します。

    .. code-block:: arduino

        // Update the distance
        distance = readDistance();

        // Update intervals based on distance
        if (distance <= 10) {
            intervals = 300;
        } else if (distance <= 20) {
            intervals = 500;
        } else if (distance <= 50) {
            intervals = 1000;
        } else {
            intervals = 2000;
        }

#. ビープ音を鳴らすタイミングを確認

    コードは現在の時間と前回のビープ音の時間の差を計算し、その差がインターバル時間以上であれば、ブザーを鳴らして前回のビープ音の時間を更新します。

    .. code-block:: arduino

        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= intervals) {
            Serial.println("Beeping!");
            beep();
            previousMillis = currentMillis;
        }

#. LCDディスプレイを更新

    コードはLCDディスプレイをクリアし、最初の行に"Dis:"と現在の距離（センチメートル）を表示します。

    .. code-block:: arduino

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dis: ");
        lcd.print(distance);
        lcd.print(" cm");

        delay(100);

