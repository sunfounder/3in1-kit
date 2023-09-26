6.5 反応ゲーム
==========================

私たちの身体には様々な反応時間があります。例として、聴覚の反応時間、視覚の反応時間、触感の反応時間などがあります。

反応時間は日常生活において多くの影響を及ぼします。例えば、運転中に反応時間が普段より遅いと、重大な結果を招く可能性があります。

このプロジェクトでは、3つのボタンと2つのLEDを使用して、私たちの視覚的な反応時間を計測します。

Arduinoのシリアルモニターは「waiting...」というメッセージを表示します。
Readyボタンを押すと、ランダムな時間が経過した後に2つのLEDのうちの1つがランダムに点灯します。被験者は対応するボタンをできるだけ早く押すことが重要です。
ArduinoはLEDが点灯するタイミングと、人が対応するボタンを押すタイミングとの時間差を記録し、Arduinoのシリアルモニターに計測した反応時間を出力します。

**必要な部品**

このプロジェクトには以下の部品が必要です。

一式をまとめて購入すると便利です。以下のリンクを参照してください：

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
    *   - :ref:`cpn_button`
        - |link_button_buy|

**回路図**

.. image:: img/wiring_reaction_game.png
    :align: center

**配線図**

.. image:: img/6.5_reaction_game_bb.png
    :align: center

**コード**

.. note::

    * ファイル ``6.5_reaction_time.ino`` を ``3in1-kit\learning_project\6.5_reversingAid`` のパスから直接開くことができます。
    * または、このコードをArduino IDEにコピーします。
    
    * ``LiquidCrystal_I2C`` ライブラリを追加していることを確認してください。詳しいチュートリアルは :ref:`install_libraries_ar` を参照してください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/4313dd1c-e1d2-4939-ae20-0a5b82a12390/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**どのように動作するのか？**

#. ボタンとLEDを初期化し、2つの割り込みを使用してボタンのステータスを読み取ります。

    .. code-block:: arduino

        void setup()
        {
            ...
            attachInterrupt(digitalPinToInterrupt(buttonPin1), pressed1, FALLING);
            attachInterrupt(digitalPinToInterrupt(buttonPin2), pressed2, FALLING);
            ...
        }

#. ``rstBtn`` ボタンが押されると、ゲームが再開します。2msから5msの間のランダムな時間で、LEDのうちの1つを点灯させます。

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

    * flagが-1で ``rstBtn`` ボタンが押された場合、 ``random()`` 関数を使用して2-5sのランダムな時間を生成します。
    * この時間はLEDの点灯を制御するために使用されます。
    * 2つのLEDの点灯も ``randomTime % 2`` でランダムに生成されます。flagが0ならLED1が点灯、1ならLED2が点灯します。

#. ``pressed1()`` 関数について

    .. code-block:: arduino

        void pressed1() {
            if (flag == -1) {
                return;
            }
            if (flag == 0) {
                int currentTime = millis();
                Serial.print("Correct! You reaction time is :");
                Serial.print(currentTime - timer);
                Serial.println(" ms");
            } else if (flag == 1) {
                Serial.println("Wrong Click!");
            }
            flag = -1;
        }

    これはボタン1が押されたときにトリガーされる関数です。ボタン1が押され、その時のflagが0であれば、反応時間が出力されます。それ以外の場合、クリックエラーが表示されます。

#. ``pressed2()`` 関数について

    .. code-block:: arduino

        void pressed2() {
            if (flag == -1) {
                return;
            }
            if (flag == 1) {
                int currentTime = millis();
                Serial.print("Correct! You reaction time is : ");
                Serial.print(currentTime - timer);
                Serial.println(" ms");
            } else if (flag == 0) {
                Serial.println("Wrong Click!");
            }
            flag = -1;
        }

    これはボタン2が押されたときにトリガーされる関数です。ボタン2が押され、その時のflagが1であれば、反応時間が出力されます。それ以外の場合、クリックエラーが表示されます。



