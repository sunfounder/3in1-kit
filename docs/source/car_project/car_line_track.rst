.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _follow_the_line:

4. ライン追従
======================

この車はライントラックモジュールを搭載しており、車が黒い線を追従するようにすることができます。

ライン追従モジュールが黒い線を検出すると、右のモーターが回転し、左のモーターは回転しないため、車は左前方に一歩進みます。
車が動くと、ラインモジュールは線から外れ、次に左のモーターが回転し、右のモーターは回転しないため、車は右に一歩進んで線に戻ります。
上記の2つのステップを繰り返すことで、車は黒い線に沿って動くことができます。

プロジェクトを開始する前に、黒い線テープで曲線マップを作成する必要があります。推奨される線の幅は0.8-1.5cmで、曲がる角度は90度未満であってはなりません。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

キット全体を購入すると非常に便利です。以下がリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクからそれぞれ別々に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネントの紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_track`
        - |link_track_buy|

**配線図**

これはデジタルライン追従モジュールです。黒い線が検出されると、出力は1となり、白い線が検出されると、出力は0となります。さらに、モジュール上のポテンショメータを調整することで、感知距離を調整することができます。

以下の図に従って回路を組み立ててください。

.. list-table:: 
    :header-rows: 1

    * - ライントラッキングモジュール
      - R4ボード
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

上記の図に従って配線し、R4ボードに電源を供給します（USBケーブルを直接挿入するか、9Vの電池ボタンケーブルを使用）。コードをアップロードすることなく。

黒い電気テープをテーブルに貼り、カートをその上に置きます。

モジュール上の信号LEDを観察して、白いテーブルの上で点灯し、黒いテープの上で消灯することを確認してください。

そうでない場合は、モジュール上のポテンショメータを調整して、上記の効果を実現できるようにします。

.. image:: img/line_track_cali.JPG


**コード**

.. note::

    * ``3in1-kit\car_project\4.follow_the_line`` のパスの下で ``4.follow_the_line.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    * あるいは、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/2779e9eb-b7b0-4d47-b8c0-78fed39828c3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
R4ボードにコードをアップロードした後、車の下のライン追跡モジュールを黒線に合わせると、車が線に沿って動くのを見ることができます。

**どのように動作するのか？**

このコードでは、ライントラックモジュールの値に従って2つのモータを微調整することで、車が黒線に沿って動くのを見ることができます。

#. ライントラッキングモジュールのピン定義を追加します。ここでは ``INPUT`` に設定されています。また、シリアルモニターを初期化し、ボーレートを9600bpsに設定します。

    .. code-block:: arduino

        ...
        const int lineTrack = 2;
        Serial.begin(9600);
        void setup() {
            ...
            pinMode(lineTrack, INPUT);
        }

#. ライントラッキングモジュールの値を読み取ります。それが1の場合、車を左に進めます。そうでなければ、右に進めます。また、USBケーブルを抜く前に、右上隅の虫眼鏡アイコンをクリックしてシリアルモニターを開き、黒と白の線上でのライントラッキングモジュール値の変化を見ることができます。

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

    プロジェクト :ref:`car_move_code` の左右回転機能とは異なり、ここでは小さな左右の回転のみが必要です。したがって、毎回 ``A_1A`` または ``B_1B`` の値を調整するだけで十分です。例えば、左前方に移動する場合(``moveLeft()``)、 ``A_1A`` の速度を設定し、他のすべてを0に設定するだけで、右のモータが時計回りに回転し、左のモータは動かないようになります。

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

    Arduinoボードとコンピュータや他のデバイスとの通信に使用されます。

    * ``Serial.begin()``: シリアルデータの送信のためのビットレート(baud)を設定します。
    * ``Serial.println()``: データを人間が読めるASCIIテキストとしてシリアルポートに出力し、キャリッジリターン文字(ASCII 13または'\r')と改行文字(ASCII 10または'\n')に続きます。

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    ``if else`` は基本的なif文よりもコードの流れをより細かく制御することができるように、複数のテストをグループ化することを可能にします。
