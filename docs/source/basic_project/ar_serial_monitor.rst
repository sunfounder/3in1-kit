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

3.0 シリアルモニター
=============================

Arduino IDEには、コンピュータからArduinoボードへ（USB経由で）メッセージを送信することができるシリアルモニターがあります。また、Arduinoからのメッセージを受信することもできます。

このプロジェクトでは、Arduinoボードからデータを受信する方法を学びます。

.. note::

    Uno、Nano、Mini、Megaでは、0ピンと1ピンがコンピュータとの通信に使用されています。これらのピンに何かを接続すると、ボードへのアップロードの失敗を含む通信の干渉が発生する可能性があります。

**シリアルモニターの使用方法**

1. Arduino IDEを開き、以下のコードを貼り付けます。

    .. code-block:: arduino

        // セットアップルーチンはリセットボタンを押すと一度だけ実行されます:
        void setup() {
            // シリアル通信を9600ビット/秒で初期化:
            Serial.begin(9600);
        }

        // ループルーチンは永遠に繰り返し実行されます:
        void loop() {
            int number = 100;
            Serial.println(number);
            Serial.println("Hello world");
            delay(100);         // 安定した読み取りのための間隔
        }

   * `Serial.begin() <https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/>`_: シリアルデータ伝送のビットレート（ボーレート）を設定します。ここでは9600に設定。
   * `Serial.println() <https://www.arduino.cc/reference/en/language/functions/communication/serial/println/>`_: キャリッジリターン文字 (ASCII 13, '\r') および改行文字 (ASCII 10, '\n') に続く人間が読めるASCIIテキストとしてシリアルポートにデータを出力します。このコマンドは `Serial.print() <https://www.arduino.cc/reference/en/language/functions/communication/serial/print/>`_ と同じ形式を取ります。

2. コードをアップロードするための正しいボードとポートを選択します。
3. ツールバーで虫眼鏡のアイコンをクリックして、シリアルモニターをオンにします。

.. image:: img/serial1.png
    :align: center

4. これがシリアルモニターの画面です。

.. image:: img/serial2.png
    :align: center

* **1**: 自動的にスクロールするかしないかを選択するオプション。
* **2**: シリアルモニタに表示されるデータの前にタイムスタンプを表示するオプション。
* **3**: 終了選択、Arduinoに送信されるデータに追加される終了文字を選択します。選択肢には以下が含まれます：

        * **行の終わりなし** は入力したものだけを送信;
        * **改行** は ``\n`` で、入力した後にASCIIの改行コードを送信;
        * **キャリッジリターン** は ``\r`` で、入力した後にASCIIのキャリッジリターン文字を送信;
        * **NL & CRの両方** は ``\r\n`` で、入力した後にキャリッジリターンと改行の両方の文字を送信。
* **4**: ArduinoボードとPCとの通信速度を選択します。この値は ``Serial.begin()`` で設定した値と同じでなければなりません。
* **5**: 出力コンソール上の全テキストをクリア。
* **6**: Arduinoボードに文字を送信するためのテキストボックス。チュートリアルは :ref:`ar_serial_read` を参照してください。
