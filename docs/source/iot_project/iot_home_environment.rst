.. _iot_home:

5. 家の環境モニタリング
================================

この章では、Blynkを使用して家の環境モニタを作成します。
DHT11とフォトレジスタを使用することで、部屋の温度、湿度、および光の強度を測定できます。
これらのデータをBlynkに送信することで、インターネットを通じてあなたの家の環境を把握することができます。

**必要な部品**

このプロジェクトには、以下の部品が必要です。

一式として購入するのがおすすめです。以下はそのリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

また、以下のリンクから個別に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネントの紹介
        - 購入リンク
    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_dht11`
        - \-

**1. 回路を組む**

.. note::

    ESP8266モジュールは安定した動作のために高い電流が必要なので、9Vのバッテリーが接続されていることを確認してください。

.. image:: img/iot_5_bb.png

**2. ダッシュボードを編集**

#. 湿度のデータを記録するため、 **Datastream** ページで **Virtual Pin** タイプの **Datastream** を作成します。DATA TYPEを **Double** に設定し、MINとMAXを **0** と **100** にします。また、単位は **Percentage, %** に設定します。

    .. image:: img/sp220610_145748.png

#. 温度のデータを記録するための **Virtual Pin** タイプの **Datastream** を作成します。DATA TYPEを ``Double`` に、MINとMAXを ``-30`` と ``50`` に設定し、単位を **Celsius, °C** にします。

    .. image:: img/sp220610_145811.png

#. 光の強度のデータを記録するための **Virtual Pin** タイプの **Datastream** を作成します。デフォルトのデータタイプ、すなわち **Integer** を使用し、MINとMAXを ``0`` と ``1024`` に設定します。

    .. image:: img/sp220610_145834.png

#. **Wed Dashboard** ページに移動し、 **V4** および **V5** にデータストリームを設定した2つの **Label** ウィジェットを配置し、 **V6** にデータストリームを設定した **Gauge** ウィジェットを配置します。ウィジェットの設定で、 **値に応じて色を変更する** オプションを有効にし、見やすく直感的な表示のために適切な色を選択できます。

.. image:: img/sp220610_150400.png
    :align: center



**3. コードの実行**

#. ``3in1-kit\iot_project\5.home_environment_monitoring`` のパスの下で ``5.home_environment_monitoring.ino`` ファイルを開く、またはこのコードを **Arduino IDE** にコピーします。

    .. note::

            * ここでは ``DHT sensor library`` が使用されています。 **Library Manager** からインストールできます。

                .. image:: ../img/lib_dht11.png

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4f0ad85e-8aff-4df9-99dd-c6741aed8219/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. ``Template ID``、 ``Device Name``、および ``Auth Token`` を自分のものに置き換えます。使用しているWiFiの ``ssid`` と ``password`` も入力する必要があります。詳細なチュートリアルは、 :ref:`connect_blynk` を参照してください。
#. 正しいボードとポートを選択した後、 **Upoad** ボタンをクリックします。

#. シリアルモニターを開いて（ボーレートを115200に設定）、成功した接続などのプロンプトが表示されるのを待ちます。

    .. image:: img/2_ready.png

    .. note::

        接続時に ``ESP is not responding`` というメッセージが表示された場合は、以下の手順を実行してください。

        * 9Vのバッテリーが接続されていることを確認します。
        * RSTピンを1秒間GNDに接続してESP8266モジュールをリセットし、その後、抜きます。
        * R4ボードのリセットボタンを押します。

        こうした操作を3〜5回繰り返す必要があることもありますので、お待ちください。

#. これで、Blynk上で現在の周囲の温度、湿度、光の強度を見ることができます。

    .. image:: img/sp220610_150400.png
        :align: center

#. Blynkをモバイルデバイスで使用したい場合は、 :ref:`blynk_mobile` を参照してください。

    .. image:: img/mobile_home.jpg

**どのように動作するのか？**

これらの二つの関数は、部屋の温度、湿度、光の強度を取得するために使用されます。

.. code-block:: arduino

    int readLight(){
        return analogRead(lightPin);
    }

    bool readDHT() {

        // 温度または湿度の読み取りには約250ミリ秒かかります！
        // センサーの読み取りは、最大2秒「古い」場合があります（非常に遅いセンサーです）
        humidity = dht.readHumidity();
        // 温度を摂氏で読み取る（デフォルト）
        temperature = dht.readTemperature();

        // いずれかの読み取りに失敗した場合は確認し、早期に終了します（再試行のため）。
        if (isnan(humidity) || isnan(temperature)) {
            Serial.println("DHTセンサーからの読み取りに失敗しました！");
            return false;
        }
        return true;
    }

Blynkの ``Timer`` を使用して、周囲の温度、湿度、光の強度は毎秒取得され、Blynk Cloud上のデータストリームに送信されます。そして、ウィジェットがデータを表示します。


.. code-block:: arduino

    void myTimerEvent()
    {
        bool chk = readDHT();
        int light = readLight();
        if(chk){
            Blynk.virtualWrite(V4,humidity);
            Blynk.virtualWrite(V5,temperature);
        }
        Blynk.virtualWrite(V6,light);
    }