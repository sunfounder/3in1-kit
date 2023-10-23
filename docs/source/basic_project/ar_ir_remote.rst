.. _ar_receiver:

5.11.2 IR 受信機
=========================

このプロジェクトでは、IR 受信機の使用方法を学びます。

赤外線受信機は、赤外線信号を受信するコンポーネントで、独立して赤外線を受信し、TTLレベルと互換性のある信号を出力できます。
通常のプラスチックパッケージのトランジスタと同じサイズで、あらゆる種類の赤外線リモコンや赤外線送信に適しています。

**必要な部品**

このプロジェクトで必要なコンポーネントは以下の通りです。

一式を購入するのは非常に便利です。以下にリンクを示します。

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
    *   - :ref:`cpn_receiver`
        - \-

**回路図**

.. image:: img/circuit_7.2_receiver.png

**配線図**

この例では、IR 受信機の左ピンをピン11に、中央ピンをGNDに、右ピンを5Vに接続します。

.. image:: img/5.11_ir_recv_bb.png

**コード**

.. note::

    * ``3in1-kit\learning_project\5.11.ir_receiver`` のパスで ``5.11.ir_receiver.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    * ここでは ``IRremote`` ライブラリを使用しています。 **Library Manager** からインストールできます。

        .. image:: ../img/lib_irremote.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1141d808-cc26-4589-ae5c-d1834033ac3d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

R4ボードにコードをアップロードすると、IRリモートコントローラの押されたボタンの現在の値がシリアルモニタに表示されます。

**どのように動作するのか？**

このコードは、 ``IRremote`` ライブラリを使用して赤外線（IR）リモートコントロールと連携して動作するように設計されています。以下に詳細を示します：

#. ライブラリのインクルード:  ``IRremote`` ライブラリをインクルードして、IRリモートコントロールと連携する関数を提供します。

    .. code-block:: arduino

        #include <IRremote.h>

#. IRセンサのシグナルピンが接続されているArduinoのピンを定義し。

    .. code-block:: arduino

        const int IR_RECEIVE_PIN = 11;  // IRセンサのピン番号を定義

#. ボーレート9600でシリアル通信を初期化します。指定されたピン（ ``IR_RECEIVE_PIN`` ）でIR受信機を初期化し、LEDフィードバックを有効にします（該当する場合）。

    .. code-block:: arduino

        void setup() {
            Serial.begin(9600);                                     // ボーレート9600でシリアル通信を開始
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // IR受信機を開始
        }

#. ループは、入力されるIRリモート信号を継続的に処理するために継続的に実行されます。

    .. code-block:: arduino

        void loop() {
            if (IrReceiver.decode()) {
                String decodedValue = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (decodedValue != "ERROR") {
                    Serial.println(decodedValue);
                    delay(100);
                }
                IrReceiver.resume();  // Enable receiving of the next value
            }
        }

    * IR信号が受信され、正常にデコードされたかどうかを確認します。
    * ``decodeKeyValue()`` 関数を使用してIRコマンドをデコードし、 ``decodedValue`` に保存します。
    * デコードされた値がエラーでないか確認します
    * デコードされたIRの値をシリアルモニタに出力します。
    * 次の信号のためのIR信号受信を再開します。
