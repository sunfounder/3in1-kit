.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

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

#. ボーレート9600でシリアル通信を初期化します。指定されたピン（ ``IR_RECEIVE_PIN`` ）でIR受信機を初期化し、LEDフィードバックを有効にします（該当する場合）。


    .. code-block:: arduino

        ...

        void setup() {

            ...
            //IRリモート
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // IRレシーバを開始
            Serial.println("REMOTE CONTROL START");

        }

#. リモコンのキーを押すと、赤外線レシーバはどのキーが押されたかを知り、それに応じて車が対応するキー値に従って動きます。

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
                    IrReceiver.resume();  // Enable receiving of the next value

            }
        }

    * IR信号が受信され、正常にデコードされたかどうかを確認します。
    * カスタムの ``decodeKeyValue()`` 関数を使用してIRコマンドをデコードし、 ``key`` に保存します。
    * デコードされた値がエラーでないか確認します。
    * デコードされたIR値をシリアルモニタに出力します。
    * 次の信号のIR信号受信を再開します。
