.. _follow_the_line:

4. ラインを追う
======================

この車にはライン追跡モジュールが装備されており、黒いラインに沿って車を動かすことができます。

ライン追跡モジュールが黒いラインを検出すると、右のモーターは回転し、左のモーターは回転しないため、車は左前方に一歩進みます。
車が移動すると、ラインモジュールはラインから移動し、左のモーターが回転し、右のモーターが回転しなくなり、車はラインに戻るために右に一歩移動します。
上記の2つの手順を繰り返すことで、車は黒いラインに沿って移動することができます。

プロジェクトを開始する前に、黒いラインテープで曲線マップを作成する必要があります。推奨されるラインの幅は0.8-1.5cmで、曲がる角度は90度未満であってはなりません。

**必要なコンポーネント**

このプロジェクトには、以下のコンポーネントが必要です。

一式を購入するのは非常に便利です、以下のリンクを参照してください:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム数
        - リンク
    *   - 3 in 1 スターターキット
        - 380+
        - |link_3IN1_kit|

以下のリンクからそれぞれ購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネント紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_track`
        - |link_track_buy|

**配線**

これはデジタルライン追跡モジュールで、黒いラインが検出されると1を出力し、白いラインが検出されると0の値を出力します。さらに、モジュールのポテンショメーターを通じて、感知距離を調整することができます。

以下の図に従って回路を組み立ててください。

.. list-table:: 
    :header-rows: 1

    * - ライン追跡モジュール
      - R3 ボード
    * - S
      - 2
    * - V+
      - 5V
    * - G
      - GND

.. image:: img/car_4.png
    :width: 800

**モジュールの調整**

プロジェクトを開始する前に、モジュールの感度を調整する必要があります。

上記の図に従って配線を行い、R3ボードに電源を供給します（USBケーブルを直接挿入するか、9Vのバッテリーケーブルを押して供給する）。コードをアップロードすることなく。

テーブルに黒い電気テープを貼り、カートを上に置いてください。

モジュール上の信号LEDを観察して、白いテーブル上で点灯し、黒いテープ上で消灯することを確認してください。

そうでない場合は、上記の効果を実現するためにモジュールのポテンショメーターを調整する必要があります。

.. image:: img/line_track_cali.JPG

**コード**

.. note::

    * ``3in1-kit\car_project\4.follow_the_line`` のパスの下で ``4.follow_the_line.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を使用してコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/2779e9eb-b7b0-4d47-b8c0-78fed39828c3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

R3ボードにコードをアップロードした後、車の下のライン追跡モジュールを黒いラインに合わせると、車がラインを追っているのがわかります。

**どのように動作するか？**

このコードでは、ライン追跡モジュールの値に従って、2つのモーターを微細に左右に回転させることで、車が黒いラインに沿って動く様子を見ることができます。

#. ライン追跡モジュールのピン定義を追加します。ここでは ``INPUT`` に設定されています。ここでもシリアルモニターを初期化し、ボーレートを9600bpsに設定します。

    .. code-block:: arduino

        ...
        const int lineTrack = 2;
        Serial.begin(9600);
        void setup() {
            ...
            pinMode(lineTrack, INPUT);
        }

#. ライン追跡モジュールの値を読み取り、1の場合は車を左に前進させ、それ以外の場合は右に前進させます。また、USBケーブルを抜く前に、右上の角にある虫眼鏡アイコンをクリックしてシリアルモニターを開くことで、黒と白のライン上でのライン追跡モジュール値の変化を見ることができます。

    .. code-block:: arduino
    
        void loop() {

            int speed = 150;

            int lineColor = digitalRead(lineTrack); // 0:white    1:black
            Serial.println(lineColor); 
            if (lineColor) {
                moveLeft(speed);
            } else {
                moveRight(speed);
            }
        }

#. ``moveLeft()`` および ``moveRight()`` 関数について。

    プロジェクト :ref:`car_move_code` の左右の回転関数とは異なり、ここでは小さな左右の回転のみが必要ですので、毎回 ``A_1A`` または ``B_1B`` の値を調整するだけで済みます。たとえば、左前方に移動する場合（ ``moveLeft()`` ）、右モーターが時計回りに回転し、左モーターが動かないように、速度を ``A_1A`` に設定し、他すべてを0に設定するだけで済みます。

    .. code-block:: arduino
    

        void moveLeft(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, speed);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, 0);
        }

        void moveRight(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, speed);
            analogWrite(B_1A, 0);
        }

* `Serial <https://www.arduino.cc/reference/en/language/functions/communication/serial/>`_

    Arduinoボードとコンピュータや他のデバイスとの通信に使用される

    * ``Serial.begin()``: シリアルデータの伝送における秒単位のデータレート（ボード）を設定します。
    * ``Serial.println()``: データを人間が読めるASCIIテキストとしてシリアルポートに印刷し、続けてキャリッジリターン文字（ASCII 13、または '\r'）と改行文字（ASCII 10、または '\n'）を送信します。 

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    ``if else`` は基本的なif文よりもコードのフローをよりコントロールすることができ、複数のテストをグループ化することができます。
