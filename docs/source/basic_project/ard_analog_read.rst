.. _ar_analog_read:

4. アナログ読み取り
======================

Arduinoはアナログピンを介して接続されたアナログセンサーの値を読み取ることができます。

R3ボードには、多チャンネル、10ビットのアナログ-デジタル変換器が含まれています。これは、入力電圧を0から動作電圧（5Vまたは3.3V）の間の整数値0から1023にマッピングすることを意味します。

アナログピンの値を読み取るには、 ``analogRead(pin)`` 関数が必要です。

* ``analogRead(pin)``: 指定されたアナログピンの値を読み取ります。

   **構文**
      analogRead(pin)

   **パラメータ**
        * ``pin``: 読み取りを行うアナログ入力ピンの名前（A0からA5）。

   **戻り値**
      0-1023。データ型: int。

**アナログ読み取りの例**

.. code-block:: arduino

   int analogPin = A0; // アナログピンA0に接続されたデバイス
                     // 外部はグラウンドと+5Vにつながる
   int val = 0;  // 読み取り値を保存する変数

   void setup() {
      Serial.begin(9600);           // シリアルのセットアップ
   }

   void loop() {
      val = analogRead(analogPin);  // 入力ピンを読み取る
      Serial.println(val);          // 値のデバッグ表示
   }

**注意点と警告**

* アナログピンはA0-A5です。
* アナログピンを呼び出す前に ``pinMode()`` を呼び出す必要はありませんが、ピンが以前 ``OUTPUT`` に設定されていた場合、 ``analogRead()`` 関数は正しく動作しません。その場合、 ``pinMode()`` を呼び出して ``INPUT`` に戻す必要があります。

**関連部品**

以下は関連する部品です。クリックして使用方法を学ぶことができます。


.. toctree::
    :maxdepth: 2

    ar_turn_the_knob
    ar_photoresistor
    ar_joystick
    ar_moisture
    ar_thermistor