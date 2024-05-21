.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_high_tem_alarm:

6.3 高温アラーム
====================================

次に、サーミスター、プッシュボタン、ポテンショメータ、LCDを使用して、高温アラームデバイスを作成します。
LCD1602は、サーミスターで検出される温度と、ポテンショメータを使用して調整できる高温閾値を表示します。
閾値は同時にEEPROMに保存されるため、現在の温度が閾値を超えると、ブザーが鳴ります。

**必要な部品**

このプロジェクトには、以下の部品が必要です。

一式を購入するのは確かに便利です。こちらがリンクです:

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
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**回路図**

.. image:: img/wiring_high_tem.png
   :align: center

**配線図**

.. image:: img/6.3_high_tem_alarm_bb.png
    :width: 800
    :align: center

**コード**

.. note::

    * ファイル ``6.3.high_tem_alarm.ino`` は、 ``3in1-kit\learning_project\6.3.high_tem_alarm`` のパスの下で直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。
    * ここでは ``LiquidCrystal I2C`` ライブラリが使用されています。 **Library Manager** からインストールできます。

        .. image:: ../img/lib_liquidcrystal_i2c.png
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1341b79d-c87e-4cea-ad90-189c2ebf40ee/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされた後、LCD1602はサーミスターで検出される温度と高温閾値を表示します。この閾値はポテンショメータを使用して調整することができます。閾値は同時にEEPROMに保存されるため、現在の温度が閾値を超えると、ブザーが鳴ります。

.. note::
    コードと配線が問題ないのに、LCDが内容を表示しない場合は、背面のポテンショメータを回して調整してください。


**どのように動作するのか？**

#. ボタン、ブザー、I2C LCD1602の初期化を行い、EEPROMの値を読み取ります。また、ボタンの状態を読み取るために、ここでは割り込みも使用されています。

    .. code-block:: arduino

        void setup()
        {
            pinMode(buzzerPin, OUTPUT);
            pinMode(buttonPin, INPUT);
            lcd.init();
            lcd.backlight();
            upperTem = EEPROM.read(0);
            delay(1000);
            attachInterrupt(digitalPinToInterrupt(buttonPin), buttonState, FALLING);
        }

    * この割り込みはボタンの状態を読み取るために使用されます。ボタンが押されると、 ``buttonPin`` が低から高に変わります。
    * 割り込みが発生すると、buttonState関数が呼び出され、変数stateの値が切り替えられます。
    * ``FALLING`` は、 ``buttonPin`` が低から高になるときに割り込みが発生することを意味します。

#. 高温のしきい値を設定するため、メインプログラム内でstateが1の場合（ボタンが押されると0と1の間で切り替わる）に ``upperTemSetting()`` 関数が呼び出され、そうでなければ ``monitoringTemp()`` が呼び出され、現在の温度と設定されたしきい値が表示されます。

    .. code-block:: arduino

        void loop()
        {
            if (state == 1)
            {
                upperTemSetting();
            }
            else {
                monitoringTemp();
            }
        }

#. ``upperTemSetting()`` 関数について。

    .. code-block:: arduino

        void upperTemSetting()
        {
            int setTem = 0;

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Adjusting...");
            lcd.setCursor(0, 1);
            lcd.print("Upper Tem: ");

            while (1) {
                lcd.setCursor(11, 1);
                setTem = map(analogRead(potPin), 0, 1023, 0, 100);
                lcd.print(setTem);
                if (state == 0)
                {
                    EEPROM.write(0, setTem);
                    upperTem = setTem;
                    lcd.clear();
                    return;
                }
            }
        }

    * この関数を使うとしきい値を設定できます。この関数に入ると、LCD1602に現在のしきい値が表示され、これはポテンショメータを使って変更することができます。このしきい値はEEPROMに保存され、ボタンが再び押されると終了します。

#. ``monitoringTemp()`` 関数について。

    .. code-block:: arduino

        void monitoringTemp()
        {
            long a = analogRead(temPin);
            float tempC = beta / (log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;
            float tempF = 1.8 * tempC + 32.0;
            lcd.setCursor(0, 0);
            lcd.print("Temp: ");
            lcd.print(tempC);
            lcd.print(char(223));
            lcd.print("C   ");
            lcd.setCursor(0, 1);
            lcd.print("Upper: ");
            lcd.print(upperTem);
            lcd.print(char(223));
            lcd.print("C   ");
            delay(300);
            if (tempC >= upperTem)
            {
                digitalWrite(buzzerPin, HIGH);
                delay(50);
                digitalWrite(buzzerPin, LOW);
                delay(10);
            }
            else
            {
                digitalWrite(buzzerPin, LOW);
            }
        }

    * この関数を使用すると、温度を表示し、アラームを設定することができます。
    * サーミスタの値が読み取られ、それからセ氏温度に変換され、LCD1602に表示されます。
    * 設定されたしきい値もLCDに表示されます。
    * 現在の温度がしきい値よりも高い場合、ブザーがアラームを鳴らします。
