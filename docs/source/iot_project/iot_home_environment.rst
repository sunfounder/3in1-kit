.. _iot_home:


5. 住宅環境監視
=====================

この章では、Blynkを使用して住宅の環境モニターを作成します。
DHT11とフォトレジスタを使用して、部屋の温度、湿度、および光の強度を測定できます。
これらの値をBlynkに送信することで、インターネット経由で自宅の環境を知ることができます。

**必要な部品**

このプロジェクトには、以下の部品が必要です。

全体のキットを購入すると非常に便利です。以下のリンクを参照してください：

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

    ESP8266モジュールは安定した動作環境を提供するために高い電流が必要ですので、9Vのバッテリーが接続されていることを確認してください。

.. image:: img/wiring_dht11.jpg

**2. ダッシュボードを編集**

#. 湿度の値を記録するために、 **Datastream** ページで **Virtual Pin** タイプの **Datastream** を作成します。DATA TYPEを **Double** に設定し、MINとMAXを **0** と **100** に設定します。また、単位を **Percentage, %** に設定します。

    .. image:: img/sp220610_145748.png

#. 次に、温度を記録するための **Virtual Pin** タイプの **Datastream** を作成します。DATA TYPEを ``Double`` に設定し、MINとMAXを ``-30`` と ``50`` に設定し、単位を **Celsius, °C** にします。

    .. image:: img/sp220610_145811.png

#. また、光の強度を記録するための **Virtual Pin** タイプの **Datastream** を作成します。デフォルトのデータタイプである **Integer** を使用し、MINとMAXを ``0`` と ``1024`` に設定します。

    .. image:: img/sp220610_145834.png

#. **Wed Dashboard** ページに移動し、2つの **Label** ウィジェットをドラッグして、それぞれのデータストリームを **V4** および **V5** に設定し、 **Gauge** ウィジェットをドラッグしてデータストリームを **V6** に設定します。ウィジェットの設定でも、 **値に基づいて色を変更** を有効にし、適切な色を選択してウィジェットをより見やすく、直感的にすることができます。


.. image:: img/sp220610_150400.png
    :align: center


**3. コードの実行**

#. ``3in1-kit\iot_project\5.home_environment_monitoring`` のパスの下にある ``5.home_environment_monitoring.ino`` ファイルを開くか、このコードを **Arduino IDE** にコピーします。

    .. note::

        * ここでは ``DHT sensor library`` を使用しています。 **Library Manager** からインストールできます。

            .. image:: ../img/lib_dht11.png

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/4f0ad85e-8aff-4df9-99dd-c6741aed8219/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. ``Template ID``、 ``Device Name``、そして ``Auth Token`` を自分のものに置き換えてください。また、使用しているWiFiの ``ssid`` と ``password`` も入力する必要があります。詳しいチュートリアルは :ref:`connect_blynk` を参照してください。
#. 適切なボードとポートを選択した後、 **Upoad** ボタンをクリックします。

#. シリアルモニター（ボーレートを115200に設定）を開き、成功した接続のようなプロンプトが表示されるのを待ちます。

    .. image:: img/2_ready.png

    .. note::

        接続時に ``ESP is not responding`` というメッセージが表示された場合は、以下の手順に従ってください。

        * 9Vのバッテリーが接続されていることを確認してください。
        * RSTピンを1秒間GNDに接続してESP8266モジュールをリセットし、その後、プラグを抜いてください。
        * R3ボードのリセットボタンを押します。

        こうした操作を3〜5回繰り返すことが必要な場合もありますので、お待ちください。

#. 今、Blynk上に現在の室温、湿度、光の強度が表示されるようになります。

    .. image:: img/sp220610_150400.png
        :align: center

#. Blynkをモバイルデバイスで使用したい場合は、 :ref:`blynk_mobile` を参照してください。

    .. image:: img/mobile_home.jpg

**どのように動作するのか？**


以下の二つの関数は、部屋の温度、湿度、および光の強度を取得するために使用されます。

.. code-block:: arduino

    int readLight(){
        return analogRead(lightPin);
    }

    bool readDHT() {

        // Reading temperature or humidity takes about 250 milliseconds!
        // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
        humidity = dht.readHumidity();
        // Read temperature as Celsius (the default)
        temperature = dht.readTemperature();

        // Check if any reads failed and exit early (to try again).
        if (isnan(humidity) || isnan(temperature)) {
            Serial.println("Failed to read from DHT sensor!");
            return false;
        }
        return true;
    }


Blynkの ``Timer`` を使用して、毎秒、室内の温度、湿度、および光の強度が取得され、Blynk Cloudのデータストリームに送信されます。このデータはウィジェットによって表示されます。


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