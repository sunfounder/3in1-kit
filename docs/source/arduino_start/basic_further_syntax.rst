.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

スケッチの作成ルール
================================

あなたが友人にライトをつけてもらう場合、"ライトをつけてください"や"ライトオン、ブロ"と言うことができます。好きな口調で言うことができます。

しかし、Arduinoボードに何かをしてもらいたい場合は、Arduinoのプログラム作成ルールに従ってコマンドを入力する必要があります。

この章では、Arduino言語の基本的なルールを紹介し、自然言語をコードに変換する方法を理解するのに役立ちます。

もちろん、これは慣れるのに時間がかかるプロセスであり、初心者にとっては最もエラーが発生しやすい部分でもあるので、間違えることが多くても大丈夫です。何度も試してみてください。


セミコロン ``;``
------------------

手紙を書くときのように、各文の最後に句点を書いて終わりとするように、Arduino言語ではコマンドの終了をボードに伝えるために ``;`` を使用する必要があります。

「ボード上のLEDを点滅させる」というおなじみの例を取ってみましょう。正常なスケッチは次のようになります。

例:

.. code-block:: C

    void setup() {
        // ここに初期化コードを書く: 一度だけ実行されます
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // ここにメインのコードを書く: 繰り返し実行されます
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

次に、以下の2つのスケッチを見て、実行する前にArduinoに正しく認識されるかどうかを推測してみましょう。

スケッチA:

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // ここに初期化コードを書く: 一度だけ実行されます
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // ここにメインのコードを書く: 繰り返し実行されます
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

スケッチB:

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // ここに初期化コードを書く: 一度だけ実行されます
        pinMode(13,OUTPUT);
    }
    
    void loop() {
        // ここにメインのコードを書く: 繰り返し実行されます
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,
        
        LOW);
                delay(500)
        ;
    }

結果として、 **Sketch A** はエラーを報告し、 **Sketch B** は実行されます。

* **Sketch A** のエラーは、 ``;`` が欠落している点で、見た目は普通ですが、Arduinoはこれを読むことができません。
* **Sketch B** は、見た目は人間には不親切ですが、実際には、Arduinoプログラムではインデント、改行、ステートメントのスペースは存在しないので、Arduinoのコンパイラにとっては、例のように見えます。

しかし、 **Sketch B** のようにコードを書かないでください。通常、コードを書き、閲覧するのは自然な人々ですので、自分自身を困らせないようにしてください。


中括弧 ``{}``
------------------

``{}`` はArduinoプログラミング言語の主要なコンポーネントで、ペアで現れる必要があります。
より良いプログラムの慣習は、左の中括弧を入力した直後に右の中括弧を入力して、構造体を挿入し、カーソルを中括弧の間に移動してステートメントを挿入することです。



コメント ``//``
-------------------

コメントはコンパイラが無視するスケッチの部分です。通常、プログラムの動作方法を他者に伝えるために使用されます。

コードの行に隣接する2つのスラッシュを書くと、コンパイラはその行の最後まで何も無視します。

新しいスケッチを作成すると、2つのコメントが含まれています。これらのコメントを削除しても、スケッチに影響はありません。

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // ここに初期化コードを書く: 一度だけ実行されます
    }

    void loop() {
        // ここにメインのコードを書く: 繰り返し実行されます
    }

プログラミングでのコメントは非常に役立ちます。以下にいくつかの一般的な使用例を示します。

* 使用方法A: このコードのセクションが何をするのか、自分自身や他者に伝える。

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); // ピン13を出力モードに設定、ボード上のLEDを制御します
    }

    void loop() {
        digitalWrite(13,HIGH); // ピン13をハイに設定して、ボード上のLEDを活性化
        delay(500); // 500 ms のまま
        digitalWrite(13,LOW); // ボード上のLEDをオフにする
        delay(500); // 500 ms のまま
    }


* 使用B: 一時的にいくつかの文を無効にする（削除せずに）そして、それらを使用する必要があるときにコメントを外すことで、それらを再度書き直す必要がない。これは、コードのデバッグを行い、プログラムのエラーの場所を特定するときに非常に便利です。

.. code-block:: C
    :emphasize-lines: 3,4,5,6

    void setup() {
        pinMode(13,OUTPUT);
        // digitalWrite(13,HIGH);
        // delay(1000);
        // digitalWrite(13,LOW);
        // delay(1000);
    }

    void loop() {
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

.. note:: 
    コードを迅速にコメントまたはコメント解除するのに役立つショートカット ``Ctrl+/`` を使用してください。

コメント ``/**/``
------------------

``//`` と同様のコメントです。このコメントは複数の行にわたることができ、コンパイラが ``/*`` を読むと、 ``*/`` が現れるまで後続の内容を無視します。

例1:

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* 点滅 */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        以下のコードはボード上のLEDを点滅させます。
        delay()内の数値を変更して、点滅の頻度を変更することができます。
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }


``#define``
--------------

これは便利なC++のツールです。

.. code-block:: C

    #define identifier token-string

コンパイラは、それを読むときに自動的に ``identifier`` を ``token-string`` で置き換えます。これは、通常、定数定義に使用されます。

例として、defineを使用してコードの可読性を向上させるスケッチを以下に示します。

.. code-block:: C
    :emphasize-lines: 1,2

    #define ONBOARD_LED 13
    #define DELAY_TIME 500

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
        delay(DELAY_TIME); 
        digitalWrite(ONBOARD_LED,LOW); 
        delay(DELAY_TIME);
    }

コンパイラにとって、実際には以下のように見えます。

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

``identifier`` が置き換えられ、プログラム内に存在しないことがわかります。
したがって、使用する際のいくつかの注意点があります。

1. ``token-string`` は手動でのみ変更でき、プログラムの算術で他の値に変換することはできません。

2. ``;`` のようなシンボルの使用を避ける。例えば。

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
    }

コンパイラはそれを以下のように認識し、エラーとして報告されます。

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;,OUTPUT); 
    }

    void loop() {
        digitalWrite(13;,HIGH); 
    }

.. note:: 
    ``#define`` の命名規則は、変数との混同を避けるために ``identifier`` を大文字にすることです。
