.. _car_remote:

9. リモートコントロール
=================================

このキットにはIR受信機が付属しており、IRリモートコントロールを使用して車の動きをコントロールすることができます。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入するのが確実に便利です。リンクは以下の通りです。

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
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_receiver`
        - \-

**配線図**

以下の図に従って回路を組み立ててください。

.. list-table:: 
    :header-rows: 1

    * - IR 受信機
      - R4 ボード
    * - OUT
      - 12
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - LED
      - R4 ボード
    * - アノード（長いピン）
      - 13
    * - カソード
      - GND

.. image:: img/car_9.png
    :width: 800

**コード**

.. note::

    * パス ``3in1-kit\car_project\9.remote_control`` の下にある ``9.remote_control.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    * ここでは ``IRremote`` ライブラリが使用されています。 **Library Manager** からインストールできます。
    
        .. image:: ../img/lib_irremote.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/7c78450d-fcd2-4288-a00d-499c71ad2d52/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされた後、リモートコントロールのボタンを押すと、LEDが一度点滅して信号を受信したことを示し、あなたが押したボタンに応じて車が動きます。車をコントロールするための以下のキーを押すことができます。

* **+**: 加速
* **-**: 減速
* **1**: 左へ前進
* **2**: 前進
* **3**: 右へ前進
* **4**: 左折
* **6**: 右折
* **7**: 左へ後退
* **8**: 後退
* **9**: 右へ後退



**どのように動作するのか？**

このプロジェクトの効果は、IRリモートコントロールのキー値を読み取ることで車を動かすことです。さらに、IR信号が正常に受信されたことを示すためにLEDが追加されています。

#. ``IRremote`` ライブラリをインポートし、 **Library Manager** からインストールできます。

    .. code-block:: arduino

        #include <IRremote.h>

        const int IR_RECEIVE_PIN = 12;  // IRセンサのピン番号を定義
        String lastDecodedValue = "";   // 最後にデコードされた値を保存する変数

#. IRレシーバとLEDを初期化します。

    .. code-block:: arduino

        ...
        const int ledPin = 13;
        ...

        void setup() {

            ...
            //IRリモート
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // IRレシーバを開始
            Serial.println("REMOTE CONTROL START");

            //LED
            pinMode(ledPin, OUTPUT);
        }

#. リモコンのキーを押すと、LEDが点滅し、赤外線レシーバはどのキーが押されたかを知り、それに応じて車が対応するキー値に従って動きます。

    .. code-block:: arduino

        void loop() {

            if (IrReceiver.decode()) {
                //    Serial.println(results.value,HEX);
                String key = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (key != "ERROR" && key != lastDecodedValue) {
                    Serial.println(key);
                    lastDecodedValue = key;  // 最後にデコードされた値を更新
                    blinkLED();

                    if (key == "+") {
                        speed += 50;
                    } else if (key == "-") {
                        speed -= 50;
                    } else if (key == "2") {
                        moveForward(speed);
                        delay(1000);
                    ...
                    }
                    IrReceiver.resume();  // 次の値の受信を有効にする

            }
        }

    * IR信号が受信され、正常にデコードされたかどうかを確認します。
    * カスタムの ``decodeKeyValue()`` 関数を使用してIRコマンドをデコードし、 ``key`` に保存します。
    * デコードされた値がエラーでなく、最後にデコードされた値と異なることを確認します。
    * デコードされたIR値をシリアルモニタに出力します。
    * 新しいデコード値で ``lastDecodedValue`` を更新します。
    * 次の信号のIR信号受信を再開します。

#. ``blinkLED()`` 関数について。

    この関数が呼び出されると、LEDが3回点滅するように、オン・オフを3回繰り返します。

    .. code-block:: arduino

        void blinkLED() {
                for (int i = 0; i < 3; i++) {
                digitalWrite(ledPin, HIGH);
                delay(50);
                digitalWrite(ledPin, LOW);
                delay(50);
            }
        }

