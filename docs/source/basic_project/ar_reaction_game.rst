.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

6.5 反応時間ゲーム
==========================

私たちの体は、オーディオRT、ビジュアルRT、タッチRTなど、多くの反応時間を持っています。

反応時間は、運転中の通常よりも遅い反応時間が重大な結果を招くことがあるなど、私たちの日常生活に多くの影響を及ぼします。

このプロジェクトでは、3つのボタンと2つのLEDを使用して、私たちの視覚的な反応時間を測定します。

Arduinoのシリアルモニターには「waiting...」というメッセージが表示されます。
Readyボタンを押すと、2つのLEDのうちの1つがランダムな時間間隔後にランダムに点灯する必要があります。テスターができるだけ早く対応するボタンを押すことが重要です。
Arduinoは、LEDが点灯したときと、人が対応するボタンを押したときとの時間差を記録し、Arduinoのシリアルモニターに測定された応答時間を表示します。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

一式をまとめて購入すると確実に便利です。リンクはこちらです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクからそれぞれ購入することもできます。

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
    *   - :ref:`cpn_button`
        - |link_button_buy|

**回路図**

.. image:: img/wiring_reaction_game.png
    :align: center

**配線図**

.. image:: img/reaction_game.png
    :align: center

**コード**

.. note::

    * ファイル ``6.5_reaction_time.ino`` を ``3in1-kit\basic_project\6.5_reversingAid`` のパスで直接開くことができます。
    * また、このコードをArduino IDE 1/2にコピーすることもできます。

    * ``LiquidCrystal_I2C`` ライブラリを追加していることを確認してください。詳しいチュートリアルは :ref:`install_libraries_ar` を参照してください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/4313dd1c-e1d2-4939-ae20-0a5b82a12390/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**どのように動作するのか？**

#. ボタンとLEDを初期化し、ボタンの状態を読むためにここで2つの割り込みを使用します。

    .. code-block:: arduino

        void setup()
        {
            ...
            attachInterrupt(digitalPinToInterrupt(buttonPin1), pressed1, FALLING);
            attachInterrupt(digitalPinToInterrupt(buttonPin2), pressed2, FALLING);
            ...
        }

#. ``rstBtn`` ボタンが押されると、ゲームが再開します。2から5msのランダムな時間で、LEDの1つを点灯させます。

    .. code-block:: arduino

        void loop()
        {
            if (flag == -1 && digitalRead(rstBtn) == LOW) {
                digitalWrite(ledPin1, LOW);
                digitalWrite(ledPin2, LOW);
                Serial.println("Waiting...");
                int randomTime = random(2000, 5000);
                delay(randomTime);

                timer = millis();
                flag = randomTime % 2;
                Serial.println("Light!");

                if (flag == 0) {
                    digitalWrite(ledPin1, HIGH);
                } else if (flag == 1) {
                    digitalWrite(ledPin2, HIGH);
                }
            }
            delay(200);
        }

    * フラグが-1で ``rstBtn`` ボタンが押されたとき、 ``random()`` 関数を使って2-5秒のランダムな時間を生成する。
    * この時間は、LEDの点灯制御に使われる。
    * また、2 つの LED の点灯は ``randomTime % 2`` によって 0 と 1 でランダムに生成されます。 flag が 0 の場合、LED1 が点灯します。 1 の場合、LED2 が点灯します。

#. ``pressed1()`` 関数について

    .. code-block:: arduino

        void pressed1() {
            if (flag == -1) {
                return;
            }
            if (flag == 0) {
                int currentTime = millis();
                Serial.print("Correct! Your reaction time is: ");
                Serial.print(currentTime - timer);
                Serial.println(" ms");
            } else if (flag == 1) {
                Serial.println("Wrong Click!");
            }
            flag = -1;
        }

    これはボタン1が押されたときに起動される関数である。ボタン1が押されたとき、このときフラグが0であれば応答時間が出力され、そうでなければ押下エラーが促される。

#. ``pressed2()`` 関数について

    .. code-block:: arduino

        void pressed2() {
            if (flag == -1) {
                return;
            }
            if (flag == 1) {
                int currentTime = millis();
                Serial.print("Correct! Your reaction time is: ");
                Serial.print(currentTime - timer);
                Serial.println(" ms");
            } else if (flag == 0) {
                Serial.println("Wrong Click!");
            }
            flag = -1;
        }
    
    これはボタン2が押されたときに起動される関数である。ボタン2が押されたとき、このときフラグが1であれば応答時間が出力され、そうでなければ押下エラーが促される。