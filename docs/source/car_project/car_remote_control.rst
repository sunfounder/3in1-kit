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

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/M8buGWCkYcI?si=spLK2KP363rkN6sl" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>


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

このプロジェクトの効果は、IRリモートコントロールのキー値を読み取って車を移動させることです。さらに、ピン13のLEDが点滅して、赤外線信号の受信が成功したことを示します。

#. ``IRremote`` ライブラリをインポートします。 **Library Manager** からインストールできます。

    .. code-block:: arduino

        #include <IRremote.h>

        const int IR_RECEIVE_PIN = 12;  // Define the pin number for the IR Sensor

#. ボーレート9600でシリアル通信を初期化します。指定されたピン(``IR_RECEIVE_PIN``)でIRレシーバを初期化し、LEDフィードバックを有効にします(該当する場合)。

    .. code-block:: arduino

        ...

        void setup() {

            ...
            //IRリモート
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver
            Serial.println("REMOTE CONTROL START");
        }

#. リモートコントロールのキーを押すと、赤外線受信機がどのキーが押されたかを知り、それに応じて車が移動します。

    .. code-block:: arduino

        void loop() {

            if (IrReceiver.decode()) {
                //    Serial.println(results.value,HEX);
                String key = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (key != "ERROR") {
                    Serial.println(key);

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
    * デコードされた値がエラーでないかを確認します。
    * シリアルモニターにデコードされたIR値を出力します。
    * 次の信号のIR信号受信を再開します。

