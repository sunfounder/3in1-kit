.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _iot_plant:

6. 植物モニター
==========================

このプロジェクトの目的は、現在の温度、湿度、光の強度、土壌の湿度を検出し、それらをBlynkに表示するスマートな水やりシステムを作成することです。

Blynk Cloudでスイッチをオンにすると、ポンプが動作を開始し、植物に水分が供給されます。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

全体のキットを購入するのは非常に便利です。リンクは以下のとおりです:

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
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_l9110` 
        - \-
    *   - :ref:`cpn_pump`
        - \-

**1. 回路を組む**

.. note::

    ESP8266モジュールは、安定した動作環境を提供するために高電流が必要ですので、9Vのバッテリーが接続されていることを確認してください。

.. image:: img/iot_6_bb.png
    :width: 800
    :align: center

**2. ダッシュボードを編集**

#. 前のプロジェクトで作成されたデータストリームは保存される必要があり、このプロジェクトでも使用されます。

#. 土壌の湿度を記録するために、 **Datastream** ページで **Virtual Pin** タイプの別の **Datastream** を作成します。DATA TYPEを ``Integer`` に設定し、MINとMAXをそれぞれ ``0`` と ``1024`` に設定します。

    .. image:: img/sp220610_155221.png

#. 次に **Wed Dashboard** ページに移動し、2つの **Label** ウィジェットをドラッグし、それらのデータストリームをそれぞれ **V4** と **V5** に設定します。2つの **Gauge** ウィジェットをドラッグし、そのデータストリームをそれぞれ **V6** と **V7** に設定します。最後に、 **Switch** ウィジェットをドラッグし、そのデータストリームを **V0** に設定します。

    .. image:: img/sp220610_155350.png



**3. コードの実行**

``3in1-kit\iot_project\6.plant_monitoring`` のパスの下で ``6.plant_monitoring.ino`` ファイルを開く、もしくはこのコードを **Arduino IDE** にコピーします。

    .. note::

            * ここでは ``DHT sensor library`` が使用されています。 **Library Manager** からインストールすることができます。

                .. image:: ../img/lib_dht11.png

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/f738bcb5-4ee2-475b-b683-759e6b2041b0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. ``Template ID``、 ``Device Name``、および ``Auth Token`` を自分のものに置き換えます。使用しているWiFiの ``ssid`` および ``password`` も入力する必要があります。詳しいチュートリアルは :ref:`connect_blynk` を参照してください。
#. 適切なボードとポートを選択した後、 **Upoad** ボタンをクリックします。

#. シリアルモニター（ボーレートを115200に設定）を開き、成功した接続などのプロンプトが表示されるのを待ちます。

    .. image:: img/2_ready.png

    .. note::

        接続時に ``ESP is not responding`` というメッセージが表示される場合、以下の手順に従ってください。

        * 9Vのバッテリーが接続されていることを確認します。
        * ピンRSTを1秒間GNDに接続して、ESP8266モジュールをリセットします。その後、それを取り外します。
        * R4ボード上のリセットボタンを押します。

        この操作を3〜5回繰り返す必要があることもあります。しばらくお待ちください。

#. Blynkに戻ると、現在の温度、湿度、光の強度、土壌の湿度が表示されます。必要に応じて、ボタンコントロールウィジェットをクリックして植物に水をやることができます。

    .. image:: img/sp220610_155350.png

#. モバイルデバイスでBlynkを使用したい場合は、 :ref:`blynk_mobile` を参照してください。

    .. image:: img/mobile_plant.jpg

**どのように動作するのか？**

この ``BLYNK_WRITE`` は、Blynkの **Switch** ウィジェットがONのときにポンプを起動し、OFFのときに停止するようにします。

.. code-block:: arduino

    BLYNK_WRITE(V0)
    {
        if(param.asInt()==1){
            digitalWrite(pumpA,HIGH);
        }else{
            digitalWrite(pumpA,LOW); 
        }
    }

これらの三つの関数は、現在の環境温度、湿度、光の強度、および土壌の湿度を取得するために使用されます。

.. code-block:: arduino

    int readMoisture(){
        return analogRead(moisturePin);
    }

    int readLight(){
        return analogRead(lightPin);
    }

    bool readDHT() {

        // 温度または湿度の読み取りには約 250 ミリ秒かかります。
         // センサーの読み取り値は最大 2 秒ほど「古い」場合もあります (非常に遅いセンサーです)
        humidity = dht.readHumidity();
        // 温度を摂氏として読み取ります (デフォルト)
        temperature = dht.readTemperature();

        // 失敗した読み取りがあるかどうかを確認し、早めに終了します (再試行するため)。
        if (isnan(humidity) || isnan(temperature)) {
            Serial.println("Failed to read from DHT sensor!");
            return false;
        }
        return true;
    }

Blynkの ``Timer`` を使用すると、周囲の温度、湿度、光の強度、土壌の湿度が毎秒取得され、それらが **Blynk Cloud** 上のデータストリームに送信されます。その結果、ウィジェットがデータを表示します。



.. code-block:: arduino

    void myTimerEvent()
    {
        bool chk = readDHT();
        int light = readLight();
        int moisture = readMoisture();
        if(chk){
            Blynk.virtualWrite(V4,humidity);
            Blynk.virtualWrite(V5,temperature);
        }
        Blynk.virtualWrite(V6,light);
        Blynk.virtualWrite(V7,moisture);
    }
