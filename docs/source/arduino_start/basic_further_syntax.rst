.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

スケッチの書き方のルール
================================

友達に照明をつけてもらう場合、「照明をつけてください」とか「ライトをつけて、兄弟！」など、好きな口調で言うことができます。

しかし、Arduinoボードに何かをしてもらいたい場合、Arduinoプログラムの書き方のルールに従ってコマンドを入力する必要があります。

この章では、Arduino言語の基本的なルールを紹介し、自然言語をコードに翻訳する方法を理解するのに役立ちます。

もちろん、これは慣れるまで時間がかかるプロセスであり、初心者にとっては最もエラーが発生しやすい部分でもあるので、頻繁に間違えることがあっても大丈夫です。何度も試してみてください。

セミコロン ``;``
--------------------

手紙を書く時、各文の最後にピリオドを書くように、Arduino言語では、コマンドの終了をボードに伝えるために ``;`` を使用する必要があります。

「オンボードLEDの点滅」の例を取り上げてみましょう。正常なスケッチは以下のようになります。

例:

.. code-block:: C

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

次に、以下の2つのスケッチを見て、実行する前にArduinoで正しく認識できるかを推測してみましょう。

スケッチA:

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

スケッチB:

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }
    
    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,
        
        LOW);
                delay(500)
        ;
    }

結果としては、 **スケッチA** はエラーを報告し、 **スケッチB** は実行されます。

* **スケッチA** のエラーは、 ``;`` が欠落していることで、見た目は正常に見えますが、Arduinoは読み取ることができません。
* **スケッチB** は、人間にとっては反対に見えますが、実際には、インデント、改行、ステートメント内のスペースなど、Arduinoのプログラムには存在しないものですので、Arduinoのコンパイラにとっては、例と同じに見えます。

しかし、 **スケッチB** のようにコードを書かないでください。コードを書き、表示するのは通常、人間ですので、自分自身を困らせないでください。

中括弧 ``{}``
------------------

``{}`` はArduinoプログラミング言語の主要な構成要素で、ペアで表示される必要があります。
良いプログラムの慣習として、左の中括弧を入力した直後に右の中括弧を入力し、中括弧の間にカーソルを移動してステートメントを挿入するのが良いでしょう。




コメント ``//``
---------------

コメントはコンパイラが無視するスケッチの部分です。プログラムの動作方法を他者に伝えるために通常使用されます。

コードの行に2つの連続したスラッシュを書くと、コンパイラはその行の終わりまでの内容を全て無視します。

新しいスケッチを作成すると、2つのコメントが付属してきます。これら2つのコメントを削除しても、スケッチには何の影響もありません。

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // put your setup code here, to run once:

    }

    void loop() {
        // put your main code here, to run repeatedly:

    }

プログラミングにおいてコメントは非常に便利で、以下にいくつかの一般的な使用例を示します。

* 使用法A：このコードのセクションが何をするのかを自分自身や他者に伝える。

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); //ピン13を出力モードに設定、オンボードLEDを制御
    }

    void loop() {
        digitalWrite(13,HIGH); // ピン13をHIGHにしてオンボードLEDを点灯
        delay(500); // 500msの状態維持
        digitalWrite(13,LOW); // オンボードLEDを消灯
        delay(500); // 500msの状態維持
    }

* 使用法B：一時的にいくつかの文を無効にし（削除せずに）、使用する必要があるときにコメントを外す。これはコードのデバッグやプログラムエラーの特定を試みる際に非常に便利です。

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
    コードを迅速にコメントする、またはコメントを解除するのに、ショートカット ``Ctrl+/`` を使用してください。

コメント ``/**/``
------------------

``//`` によるコメントと同様です。このタイプのコメントは複数行にわたることができ、コンパイラが ``/*`` を読み取ると、 ``*/`` に遭遇するまでの続く内容をすべて無視します。

例1:

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Blink */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        以下のコードはオンボードLEDを点滅させます
        delay()内の数字を変更することで点滅の頻度を変えることができます
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }



``#define``
--------------

これは役立つC++のツールです。

.. code-block:: C

    #define identifier token-string

コンパイラは ``identifier`` を読み取ったときに自動的に ``token-string`` に置き換えます。これは通常、定数の定義に使用されます。

例として、defineを使用するスケッチを以下に示します。これによりコードの可読性が向上します。

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

コンパイラにとって、実際には次のように見えます。

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

``identifier`` が置き換えられ、プログラム内には存在しないことがわかります。
そのため、使用する際にいくつか注意点があります。

1. ``token-string`` は手動でのみ変更でき、プログラム内の算術によって他の値に変換することはできません。

2. ``;`` のような記号の使用を避けてください。例えば、以下のように。

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
    }

コンパイラはそれを次のように認識します。これがエラーとして報告されるものです。

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;,OUTPUT); 
    }

    void loop() {
        digitalWrite(13;,HIGH); 
    }

.. note:: 
    ``#define`` の命名規則として、変数との混同を避けるために ``identifier`` を大文字にすることが推奨されています。
