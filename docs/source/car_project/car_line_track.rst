
.. _follow_the_line:

4. ラインフォロー
======================

この車にはライントラックモジュールが装備されており、黒いラインに沿って車を走らせることができます。

ラインフォローモジュールが黒いラインを検出すると、右のモーターが回転し、左のモーターは回転しないため、車は左前方に一歩移動します。
車が移動すると、ラインモジュールはラインから外れ、次に左のモーターが回転し、右のモーターは回転しないため、車は右に一歩移動してラインに戻ります。
上記の2つのステップを繰り返すことで、車は黒いラインに沿って移動します。

プロジェクトを開始する前に、黒いラインテープでカーブマップを作成する必要があります。推奨されるラインの幅は0.8-1.5cmで、曲がり角の角度は90度未満であってはなりません。

**必要な部品**

このプロジェクトには以下の部品が必要です。

全セットを購入するのは確かに便利です、リンクはこちら：

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
    *   - :ref:`cpn_l298n`
        - |link_l298n_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_track`
        - |link_track_buy|

**配線図**

これはデジタルライントラッキングモジュールで、黒いラインが検出されると1を出力し、白いラインが検出されると0の値を出力します。さらに、モジュール上のポテンショメータを通じて感知距離を調整することができます。

以下の図に従って回路を組み立ててください。

.. list-table:: 
    :header-rows: 1

    * - ライントラッキングモジュール
      - R3ボード
    * - S
      - 2
    * - V+
      - 5V
    * - G
      - GND

.. image:: img/car_track.jpg
    :width: 800

**モジュールの調整**

プロジェクトを開始する前に、モジュールの感度を調整する必要があります。

上記の図に従って配線を行い、R3ボードに電源を供給します（USBケーブルを直接接続するか、9Vのバッテリーボタンケーブルを使用）。コードをアップロードしないでください。

テーブルに黒い電気テープを貼り、その上にカートを置きます。

モジュールの信号LEDを観察して、白いテーブル上で点灯し、黒いテープ上で消灯することを確認します。

もしそうでない場合、モジュール上のポテンショメータを調整して、上記の効果を得るようにします。

.. image:: img/line_track_cali.JPG


**コード**

.. note::

    * ``3in1-kit\car_project\4.follow_the_line`` のパスの下で ``4.follow_the_line.ino`` ファイルを開きます。
    * あるいは、このコードを **Arduino IDE** にコピーします。
    
    * また、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードすることもできます。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/2779e9eb-b7b0-4d47-b8c0-78fed39828c3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

R3ボードにコードをアップロードした後、車の下のライントラッキングモジュールを黒いラインに合わせると、車がラインを追従するのを見ることができます。

**どのように動作するのか？**

このコードでは、ライントラックモジュールの値に応じて、2つのモーターを微調整して左右に回転させることで、車が黒いラインを追従するのを見ることができます。

#. ライントラッキングモジュールのピン定義を追加し、 ``INPUT`` として設定します。ここではシリアルモニタも初期化し、ボーレートを9600bpsに設定します。

    .. code-block:: arduino

        ...
        const int lineTrack = 2;
        Serial.begin(9600);
        void setup() {
            ...
            pinMode(lineTrack, INPUT);
        }

#. ライントラッキングモジュールの値を読み取ります。もし値が1ならば、車を左に前進させます。それ以外の場合は、右に前進させます。また、右上の虫眼鏡アイコンをクリックしてシリアルモニタを開くことで、USBケーブルを抜く前に黒と白のライン上でのライントラッキングモジュールの値の変化を見ることができます。

    .. code-block:: arduino
    
        void loop() {

            int speed = 150;

            int lineColor = digitalRead(lineTrack); // 0:白 1:黒
            Serial.println(lineColor); 
            if (lineColor) {
                moveLeft(speed);
            } else {
                moveRight(speed);
            }
        }

#. ``moveLeft()`` および ``moveRight()`` 関数について。

    プロジェクト :ref:`car_move_code` の左右のターン機能とは異なり、ここでは小さな左右のターンだけが必要です。したがって、IN2またはIN3の値を毎回調整するだけでよいです。例えば、左前に移動する場合（ ``moveLeft()`` ）、IN2のスピードを設定して、他のすべてを0に設定するだけで、右のモーターは時計回りに回転し、左のモーターは動かないようになります。

    .. code-block:: arduino
    

        void moveLeft(int speed) {
            analogWrite(in1, 0);
            analogWrite(in2, speed);
            analogWrite(in3, 0);
            analogWrite(in4, 0);
        }

        void moveRight(int speed) {
            analogWrite(in1, 0);
            analogWrite(in2, 0);
            analogWrite(in3, speed);
            analogWrite(in4, 0);
        }

* `Serial <https://www.arduino.cc/reference/en/language/functions/communication/serial/>`_

    Arduinoボードとコンピュータや他のデバイスとの通信に使用されます。

    * ``Serial.begin()``: シリアルデータ伝送のビットレート（ボーレート）を設定します。
    * ``Serial.println()``: データをシリアルポートに人間が読めるASCIIテキストとして印刷し、次にキャリッジリターン文字（ASCII 13、または '\r'）および改行文字（ASCII 10、または '\n'）が続きます。

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    ``if else`` ステートメントは、基本的なifステートメントよりもコードの流れをより制御することができます。複数のテストをグループ化できます。
