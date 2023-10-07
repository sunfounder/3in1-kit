.. _car_remote:

9. リモートコントロール
=================================

このキットにはIR受信機が付属しており、IRリモートコントロールを使用して車の動きを制御できます。

**必要な部品**

このプロジェクトには、以下の部品が必要です。

キット全体を購入するのは確かに便利です。リンクは以下のとおりです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットに含まれるアイテム
        - リンク
    *   - 3 in 1スターターキット
        - 380+
        - |link_3IN1_kit|

以下のリンクからも別々に購入できます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - 部品の紹介
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

**配線**

以下の図に従って回路を組み立ててください。

.. list-table:: 
    :header-rows: 1

    * - IR受信機
      - R3ボード
    * - OUT
      - 12
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - LED
      - R3ボード
    * - アノード（長いピン）
      - 13
    * - カソード
      - GND

.. image:: img/car_9.png
    :width: 800

**コード**

.. note::

    * ``3in1-kit\car_project\9.remote_control``のパスの下にある ``9.remote_control.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    * ここで ``IRremote`` ライブラリが使用されています。 **Library Manager** からインストールできます。
  
        .. image:: ../img/lib_irremote.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/7c78450d-fcd2-4288-a00d-499c71ad2d52/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


コードが正常にアップロードされると、リモートコントロールのボタンを押すと、LEDが点滅し、IR受信機がどのキーが押されたかを知り、それに応じて車が移動します。以下のキーを押して車を制御できます。

* **+**: 加速
* **-**: 減速
* **1**: 左前方へ進む
* **2**: 前進
* **3**: 右前方へ進む
* **4**: 左折
* **6**: 右折
* **7**: 左後退
* **8**: 後退
* **9**: 右後退


**動作の原理は？**

このプロジェクトの効果は、IRリモートコントロールのキー値を読み取って車を移動させることです。さらに、IR信号が正常に受信されたことを示すLEDが追加されています。

#. ``IRremote`` ライブラリをインポートします。 **Library Manager** からインストールできます。

    .. code-block:: arduino

        #include <IRremote.h>

        const int IR_RECEIVE_PIN = 12;  // Define the pin number for the IR Sensor
        String lastDecodedValue = "";   // Variable to store the last decoded value

#. IR受信機とLEDを初期化します。

    .. code-block:: arduino

        ...
        const int ledPin = 13;
        ...

        void setup() {

            ...
            //IRリモート
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver
            Serial.println("REMOTE CONTROL START");


            //LED
            pinMode(ledPin, OUTPUT);
        }

#. リモートコントロールのキーを押すと、LEDが点滅し、赤外線受信機がどのキーが押されたかを知り、それに応じて車が移動します。

    .. code-block:: arduino

        void loop() {

            if (IrReceiver.decode()) {
                //    Serial.println(results.value,HEX);
                String key = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (key != "ERROR" && key != lastDecodedValue) {
                    Serial.println(key);
                    lastDecodedValue = key;  // 最後に解読された値を更新する
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
    * IRコマンドをデコードし、 ``key`` に格納するカスタム ``decodeKeyValue()`` 関数を使用します。
    * デコードされた値がエラーでなく、前回のデコードされた値と異なるかどうかを確認します。
    * シリアルモニターにデコードされたIR値を出力します。
    * ``lastDecodedValue`` を新しいデコード値で更新します。
    * 次の信号のIR信号受信を再開します。

#. ``blinkLED()`` 関数について。

    この関数が呼び出されると、LEDがオンオフを3回繰り返すことで、LEDが3回点滅するのが見えるようにします。

    .. code-block:: arduino

        void blinkLED() {
                for (int i = 0; i < 3; i++) {
                digitalWrite(ledPin, HIGH);
                delay(50);
                digitalWrite(ledPin, LOW);
                delay(50);
            }
        }
