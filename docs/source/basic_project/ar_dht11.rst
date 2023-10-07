.. _ar_dht11:

5.11.3 温度・湿度
=======================================

湿度と温度は物理的な数量自体から実際の人々の生活まで密接に関連しています。
人間の環境の温度と湿度は、人体の体温調節機能と熱伝達効果に直接影響します。
さらに、思考活動と精神状態に影響を与え、私たちの学習や仕事の効率に影響を与えます。

温度は国際単位系における7つの基本的な物理量の1つで、物体の熱さや寒さの度合いを測定するために使用されます。
摂氏は、世界でよく使われる温度の尺度の一つで、"℃"の記号で表されます。

湿度は、空気中に存在する水蒸気の濃度です。
日常生活では空気の相対湿度が一般的に使用され、%RHで表されます。相対湿度は温度と密接に関連しています。
一定の体積の密封されたガスの場合、温度が高いほど相対湿度が低く、温度が低いほど相対湿度が高くなります。

.. image:: img/Dht11.png

このキットには、デジタル温度・湿度センサーであるdht11が含まれています。このセンサーは、周囲の空気を測定するための容量性湿度センサーとサーミスターを使用し、データピンにデジタル信号を出力します。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

キット全体を購入するのは非常に便利です。こちらがリンクです：

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

    *   - コンポーネント紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_dht11`
        - \-

**回路図**

.. image:: img/circuit_7.3_dht11.png

**配線図**

.. image:: img/dht11_bb.jpg

**コード**

.. note::

    * ``3in1-kit\basic_project\5.11.temperature_humidity`` のパスの下で ``5.11.temperature_humidity.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    * ここでは ``DHT sensor library`` が使用されています。 **Library Manager** からインストールできます。

        .. image:: ../img/lib_dht11.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c5b4c902-f39d-45a6-9a17-1308056041a8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、シリアルモニタに継続的に温度と湿度が出力されます。プログラムが安定して動作すると、これらの2つの値はますます正確になります。

**どのように動作するのか？**

#. ``DHT.h`` ライブラリをインクルードします。これはDHTセンサーと対話するための関数を提供します。次に、DHTセンサーのピンとタイプを設定します。

    .. code-block:: arduino

        #include "DHT.h"

        #define DHTPIN 11   // Set the pin connected to the DHT11 data pin
        #define DHTTYPE DHT11 // DHT 11 

        DHT dht(DHTPIN, DHTTYPE);

#. 115200のボーレートでシリアル通信を初期化し、DHTセンサーを初期化します。

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            Serial.println("DHT11 test!");
            dht.begin();
        }

#. ``loop()`` 関数で、DHT11センサから温度と湿度の値を読み取り、シリアルモニタに出力します。

    .. code-block:: arduino

        void loop() {
            // Wait a few seconds between measurements.
            delay(2000);

            // Reading temperature or humidity takes about 250 milliseconds!
            // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
            float humidity = dht.readHumidity();
            // Read temperature as Celsius (the default)
            float temperture = dht.readTemperature();

            // Check if any reads failed and exit early (to try again).
            if (isnan(humidity) || isnan(temperture)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
            // Print the humidity and temperature
            Serial.print("Humidity: ");
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("Temperature: ");
            Serial.print(temperture);
            Serial.println(" *C");
        }

    * ``dht.readHumidity()`` 関数は、DHTセンサから湿度の値を読むために呼び出されます。
    * ``dht.readTemperature()`` 関数は、DHTセンサから温度の値を読むために呼び出されます。
    * ``isnan()`` 関数は、読み取りが有効かどうかを確認するために使用されます。湿度または温度の値がNaN（数値でない）の場合、センサーからの読み取りが失敗したことを示し、エラーメッセージが出力されます。

