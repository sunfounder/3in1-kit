.. _ar_high_tem_alarm:

6.3 高温度警報
====================================

次に、サーミスター、プッシュボタン、ポテンショメータ、そしてLCDを使用して、高温度警報装置を作成します。
LCD1602は、サーミスターによって検出された温度と、ポテンショメータを使用して調整できる高温度閾値を表示します。
閾値は同時にEEPROMに保存されるため、現在の温度が閾値を超えると、ブザーが鳴ります。

**必要な部品**

このプロジェクトには、以下の部品が必要です。

キット全体を購入することは確かに便利です、リンクはこちら：

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

.. image:: img/tem_alarm.png
    :width: 800
    :align: center

**コード**

.. note::

    * ``3in1-kit\basic_project\6.3.high_tem_alarm`` のパスの下にある ``6.3.high_tem_alarm.ino`` ファイルを直接開くことができます。
    * または、このコードをArduino IDE 1/2にコピーします。
    * ここでは ``LiquidCrystal I2C`` ライブラリが使用されています。 **Library Manager** からインストールできます。

        .. image:: ../img/lib_liquidcrystal_i2c.png
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1341b79d-c87e-4cea-ad90-189c2ebf40ee/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードのアップロードが成功すると、LCD1602はサーミスターによって検出された温度と高温度の閾値を表示します。閾値はポテンショメータで調整することができます。閾値は同時にEEPROMに保存されるため、現在の温度が閾値を超えると、ブザーが鳴ります。

.. note::
    コードと配線が正しい場合でも、LCDがコンテンツを表示しない場合は、背面のポテンショメータを回してください。


**どのように動作しますか？**

#. ボタン、ブザー、I2C LCD1602を初期化し、EEPROMの値を読み取ります。ボタンのステータスもここで読み取るために割り込みを使用しています。

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
    
    * この割り込みはボタンの状態を読み取るために使用されます。ボタンが押されると、 ``buttonPin`` はローよりハイに変わります。
    * 割り込みがトリガされると、buttonState関数が呼び出され、変数stateの値を切り替えます。
    * ``FALLING`` は、 ``buttonPin`` がローからハイに移行するときに割り込みが発生することを意味します。

#. 高温閾値を設定するには、メインプログラム内でstateが1のとき（ボタンを押すと0と1の間で切り替えられる）に ``upperTemSetting()`` 関数が呼び出され、それ以外の場合は ``monitoringTemp()`` が現在の温度と設定された閾値を表示するために呼び出されます。

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

    * この関数を使用して閾値を設定することができます。この関数に入ると、LCD1602に現在の閾値が表示され、ポテンショメータを使用してこの閾値を変更することができます。この閾値はEEPROMに保存され、ボタンが再び押されると終了します。

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
    * サーミスタの値は読み取られ、その後、式によって摂氏温度に変換され、LCD1602に表示されます。
    * 設定した閾値もLCDに表示されます。
    * 現在の温度が閾値を超えると、ブザーがアラームを鳴らします。
