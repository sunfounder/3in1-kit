.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ard_serial_monitor:

3.0 シリアルモニタ
=============================

Arduino IDEには、コンピュータからArduinoボードへのメッセージを送信（USB経由）およびArduinoからのメッセージを受信するためのシリアルモニタがあります。

このプロジェクトでは、Arduinoボードからデータを受信する方法を学びます。

.. note::

    Uno、Nano、Mini、Megaでは、ピン0および1がコンピュータとの通信に使用されます。これらのピンに何かを接続すると、ボードへのアップロードが失敗する原因となる通信の妨害が発生する場合があります。

**シリアルモニタの使用方法**

1. Arduino IDEを開き、以下のコードを貼り付けます。

    .. code-block:: arduino

        // setupルーチンはリセットを押すと一度実行されます:
        void setup() {
            // 9600ビット毎秒でシリアル通信を初期化:
            Serial.begin(9600);
        }

        // loopルーチンは永遠に繰り返し実行されます:
        void loop() {
            int number = 100;
            Serial.println(number);
            Serial.println("Hello world");
            delay(100);         // 安定した読み取りのための遅延
        }

   * `Serial.begin() <https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/>`_: シリアルデータ伝送のビット毎秒のデータレートを設定します。この場合は9600に設定されています。
   * `Serial.println() <https://www.arduino.cc/reference/en/language/functions/communication/serial/println/>`_: データをシリアルポートにASCIIテキストとして人間が読める形式で出力し、キャリッジリターン文字（ASCII 13または '\r'）および改行文字（ASCII 10または '\n'）に続きます。このコマンドは `Serial.print() <https://www.arduino.cc/reference/en/language/functions/communication/serial/print/>`_ と同じ形式を取ります。

2. コードをアップロードするための正しいボードとポートを選択します。
3. ツールバーで、シリアルモニタを起動するための虫眼鏡アイコンをクリックします。

.. image:: img/serial1.png
    :align: center

4. これがシリアルモニタです。

.. image:: img/serial2.png
    :align: center

* **1**: 自動スクロールと非スクロールの選択オプション。
* **2**: シリアルモニタに表示されるデータの前にタイムスタンプを表示するオプション。
* **3**: 終了選択、Arduinoに送信されるデータに追加される終了文字を選択します。選択肢には次のものがあります：

        * **No line Ending** は入力したものだけを送信します；
        * **Newline** は ``\n`` で、入力後にASCIIの新しい行コードを送信します；
        * **Carriage Return** は ``\r`` で、入力後にASCIIキャリッジリターン文字を送信します；
        * **Both NL & CR** は ``\r\n`` で、入力後にキャリッジリターンと新しい行の両方の文字を送信します。
* **4**: ArduinoボードとPCの間の通信速度を選択します。この値は ``Serial.begin()`` で設定した値と同じでなければなりません。
* **5**: 出力コンソール上の全テキストをクリアします。
* **6**: Arduinoボードへの文字送信のためのテキストボックスです。チュートリアルについては、 :ref:`ar_serial_read` を参照してください。

