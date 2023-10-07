.. _ar_dht11:


5.11.3 温度 - 湿度
=======================================

湿度と温度は、物理量自体から実際の人々の生活まで、密接に関連しています。
人間の生活環境の温度と湿度は、人体の体温調節機能と熱伝達効果に直接影響を与えます。
これはさらに思考活動と精神状態に影響を与え、私たちの学習と仕事の効率に影響を与えます。

温度は、国際単位系における7つの基本物理量の一つで、物体の熱さや冷たさを測定するために使用されます。
摂氏は、世界で広く使用されている温度尺度の一つで、"℃"という記号で表されます。

湿度は、空気中に存在する水蒸気の濃度を示します。
相対湿度は日常生活でよく使用され、%RHで表されます。相対湿度は温度と密接に関連しています。
一定の容積の密閉ガスに対して、温度が高ければ相対湿度は低く、温度が低ければ相対湿度は高くなります。

.. image:: img/Dht11.png

このキットには、デジタル温湿度センサであるdht11が付属しています。周囲の空気を測定するための静電容量式湿度センサとサーミスタを使用し、データピンにデジタル信号を出力します。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

キットを一式で購入するのは非常に便利です、リンクは以下の通りです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクから別々に購入することもできます。

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
    *   - :ref:`cpn_dht11`
        - \-

**回路図**

.. image:: img/circuit_7.3_dht11.png

**配線図**

.. image:: img/5.11_dht11_bb.png

**コード**

.. note::

    * ``3in1-kit\learning_project\5.11.temperature_humidity`` のパスの下で ``5.11.temperature_humidity.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    * ここでは ``DHT sensor library`` を使用しています。 **Library Manager** からインストールできます。

        .. image:: ../img/lib_dht11.png


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c5b4c902-f39d-45a6-9a17-1308056041a8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされた後、シリアルモニターが連続して温度と湿度を表示するのを見ることができます。プログラムが安定して実行されると、これらの2つの値はますます正確になります。

**どのように動作するのか？**

#.  ``DHT.h`` ライブラリを含めることで、DHTセンサと対話するための関数を提供します。次に、DHTセンサのピンとタイプを設定します。

    .. code-block:: arduino

        #include "DHT.h"

        #define DHTPIN 11  // DHT11データピンに接続されたピンを設定
        #define DHTTYPE DHT11 // DHT 11 

        DHT dht(DHTPIN, DHTTYPE);

#. 115200のボーレートでシリアル通信を初期化し、DHTセンサを初期化します。

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            Serial.println("DHT11 test!");
            dht.begin();
        }

#. ``loop()`` 関数で、DHT11センサから温度と湿度の値を読み取り、それらをシリアルモニターに表示します。

    .. code-block:: arduino

        void loop() {
            // 測定の間に数秒待機します。
            delay(2000);

            // 温度または湿度の読み取りには約250ミリ秒かかります！
            // センサーの読み取りは最大2秒「古い」ものになることがあります（非常に遅いセンサーです）
            float humidity = dht.readHumidity();
            // 温度を摂氏で読み取る（デフォルト）
            float temperture = dht.readTemperature();

            // 読み取りが失敗したかどうかを確認して、早期に終了します（再試行するため）。
            if (isnan(humidity) || isnan(temperture)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
            // 湿度と温度を表示
            Serial.print("Humidity: "); 
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("Temperature: "); 
            Serial.print(temperture);
            Serial.println(" *C");
        }

    * ``dht.readHumidity()`` 関数は、DHTセンサから湿度値を読み取るために呼び出されます。
    * ``dht.readTemperature()`` 関数は、DHTセンサから温度値を読み取るために呼び出されます。
    * ``isnan()`` 関数は、読み取りが有効であるかどうかを確認するために使用されます。湿度または温度の値がNaN（数値でない）の場合、センサーからの読み取りに失敗したことを示し、エラーメッセージが表示されます。

