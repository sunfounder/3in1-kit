.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_blink:

1.1 こんにちは、LED！ 
=======================================

“Hello, world!”を表示することがプログラミング学習の第一歩のように、プログラムを使用してLEDを駆動することは、物理的なプログラミング学習の伝統的な導入です。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入するのが便利です、リンクはこちら： 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名称	
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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

**回路図**

.. image:: img/circuit_1.1_led.png

この回路の原理は単純で、電流の方向は図に示されています。ピン9がハイレベル（5V）を出力すると、1kΩの電流制限抵抗を通ってLEDが点灯します。ピン9がローレベル（0V）を出力すると、LEDは消灯します。

**配線図**

.. image:: img/1.1_hello_led_bb.png
    :width: 600
    :align: center

**コード**

.. note::

   * ファイル ``1.1.hello_led.ino`` をパス ``3in1-kit\learning_project\1.1.hello_led`` で開くことができます。 
   * または、このコードを **Arduino IDE** にコピーしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/0497f915-5bf8-41a2-8e0f-b013130a57f5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、LEDが点滅するのが見えるでしょう。

**どのように動作するのか？**

ここでは、LEDをデジタルピン9に接続しているため、プログラムの始めにint変数ledpinを宣言し、9の値を割り当てる必要があります。

.. code-block:: arduino

    const int ledPin = 9;

次に、 ``setup()`` 関数内でピンを初期化します。ここでピンを ``OUTPUT`` モードに初期化する必要があります。

.. code-block:: arduino

    void setup() {
        pinMode(ledPin, OUTPUT);
    }

``loop()`` の中で、 ``digitalWrite()`` を使用してledpinに5Vの高レベル信号を供給し、LEDピン間に電圧差を生じさせてLEDを点灯させます。

.. code-block:: arduino

    digitalWrite(ledPin, HIGH);

レベル信号をLOWに変更すると、ledPinの信号が0 Vに戻り、LEDが消灯します。

.. code-block:: arduino

    digitalWrite(ledPin, LOW);

オンとオフの間隔が必要です。変化を見るために人々に時間を与えるため、 ``delay(1000)`` コードを使用して、コントローラーが1000 ms何もしないようにします。

.. code-block:: arduino

    delay(1000);   
