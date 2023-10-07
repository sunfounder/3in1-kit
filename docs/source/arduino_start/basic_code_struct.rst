Arduinoプログラムの構造
===========================

新しいスケッチファイルを見てみましょう。数行のコードが書かれていますが、実際には「空の」スケッチです。
このスケッチを開発ボードにアップロードすると、何も起こりません。

.. code-block:: C

    void setup() {
    // ここに初期設定のコードを記述し、一度だけ実行します:

    }

    void loop() {
    // ここにメインのコードを記述し、繰り返し実行します:

    }

``setup()`` と ``loop()`` を削除して、スケッチを本当の ``blank`` ファイルにすると、検証に合格しないことがわかるだろう。
これらは人間の骨格に相当し、欠かせないものです。

スケッチ作成時には、まず ``setup()`` が実行され、ボードに電源が供給されたりリセットされたりした後、その内部のコード（ ``{}`` 内部）が一度だけ実行されます。 
``loop()`` はメインの機能を書くためのもので、 ``setup()`` 実行後に繰り返し実行されるコードを内部に記述します。

setup() と loop() の理解を深めるために、以下の四つのスケッチを使用します。それぞれの目的はArduinoのオンボードLEDを点滅させることです。順番に各実験を実行して、具体的な効果を記録してください。

* スケッチ1: オンボードLEDを連続して点滅させる。

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // ここに初期設定のコードを記述し、一度だけ実行します:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // ここにメインのコードを記述し、繰り返し実行します:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

* スケッチ2: オンボードLEDを一度だけ点滅させる。

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // ここに初期設定のコードを記述し、一度だけ実行します:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // ここにメインのコードを記述し、繰り返し実行します:
    }

* スケッチ3: オンボードLEDをゆっくり点滅させた後、早く点滅させる。

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // ここに初期設定のコードを記述し、一度だけ実行します:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // ここにメインのコードを記述し、繰り返し実行します:
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* スケッチ4: エラーを報告する。

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // ここに初期設定のコードを記述し、一度だけ実行します:
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // ここにメインのコードを記述し、繰り返し実行します:
    }    

これらのスケッチを利用して、 ``setup-loop`` のいくつかの特徴をまとめることができます。

* ボードに電源が供給された後、 ``loop()`` は繰り返し実行されます。
* ボードに電源が供給された後、 ``setup()`` は一度だけ実行されます。
* ボードに電源が供給された後、まず ``setup()`` が実行され、次に ``loop()`` が実行されます。
* コードは ``setup()`` または ``loop()`` の ``{}`` の範囲内に書かれる必要があり、その枠組みの外に出るとエラーとなります。

.. note::  
    ``digitalWrite(13,HIGH)`` のような命令はオンボードLEDを制御するためのもので、後の章でその使用方法を詳しく説明します。
