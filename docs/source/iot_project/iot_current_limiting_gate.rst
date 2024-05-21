.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _iot_gate:

7. 数量制限ゲート
==================================

駐車場などの状況では、数量の管理が必要とされます。

ここでは、スマートゲートを作成します。サーボはゲートとして使用され、その前にIR障害物検知器が配置されます。オブジェクト（車など）が検出されると、ゲートが開き、数字が1増加します。
カウントは7セグメントディスプレイで表示され、Blynk Cloudにもアップロードされ、遠隔地での閲覧が可能です。最後に、Blynkにはこのスマートゲートシステムを有効/無効にするSwitchウィジェットがあります。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

全体のキットを購入するのが確かに便利です、以下がリンクです：

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**1. 回路を組む**

.. note::

    ESP8266モジュールは、安定した動作環境を提供するために高電流が必要ですので、9Vのバッテリーが接続されていることを確認してください。

.. image:: img/iot_7_bb.png
    :width: 800
    :align: center

**2. ダッシュボードを編集**

#. 数字を記録するには、 **Datastream** ページで **Virtual Pin** タイプの **Datastream** を作成します。DATA TYPEを ``Integer`` に設定し、MINとMAXを ``0`` と ``10`` に設定します。

    .. image:: img/sp220610_165328.png

#. 今度は **Wed Dashboard** ページに移動し、 **Switch** ウィジェットをドラッグしてデータストリームを **V0** に、 **Label** ウィジェットをドラッグしてデータストリームを **V8** に設定します。

    .. image:: img/sp220610_165548.png


**3. コードの実行**

#. ``3in1-kit\iot_project\7.current_limiting_gate`` のパスの下で ``7.current_limiting_gate.ino`` ファイルを開くか、このコードを **Arduino IDE** にコピーします。

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/bd829175-652f-4c3e-85b0-048c3fda4555/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. ``Template ID``、 ``Device Name``、および ``Auth Token`` を自分のものに置き換えます。使用しているWiFiの ``ssid`` および ``password`` も入力する必要があります。詳しいチュートリアルは、 :ref:`connect_blynk` を参照してください。
#. 適切なボードとポートを選択した後、 **Upoad** ボタンをクリックします。

#. シリアルモニター（ボーレートを115200に設定）を開き、成功した接続などのプロンプトが表示されるのを待ちます。

    .. image:: img/2_ready.png

    .. note::

        接続時に ``ESP is not responding`` というメッセージが表示された場合は、以下の手順に従ってください。

        * 9Vのバッテリーが接続されていることを確認してください。
        * RSTピンを1秒間GNDに接続してESP8266モジュールをリセットし、その後、それを取り外します。
        * R4ボード上のリセットボタンを押します。

        これらの操作を3〜5回繰り返す必要があることがあります。忍耐強く行ってください。

#. Blynk上のButton Controlウィジェットをクリックしてスマートドアシステムを有効にします。IR障害物回避モジュールが障害物を検出すると、ゲートが開き、7セグメントディスプレイとBlynk上のCountウィジェットに1が加算されます。

    .. image:: img/sp220610_165548.png

#. モバイルデバイスでBlynkを使用したい場合は、 :ref:`blynk_mobile` を参照してください。

    .. image:: img/mobile_gate.jpg

**どのように動作するのか？**

関数 ``BLYNK_WRITE(V0)`` は **Switch** ウィジェットのステータスを取得し、それを変数 ``doorFlag`` に割り当てます。これはスマートゲートシステムが有効かどうかを判断するために使用されます。

.. code-block:: arduino

    BLYNK_WRITE(V0)
    {
        doorFlag = param.asInt(); // ゲートを有効にする
    }

Blynkタイマーでは、 ``doorFlag`` は毎秒判断され、有効な場合、ゲートの主要な関数が実行されます。

.. code-block:: arduino

    void myTimerEvent()
    {
        if (doorFlag)
        {
            channelEntrance();
        }
    }

ゲートの主要な関数は ``channelEntrance()`` です。
オブジェクトがゲートに近づくと（センサーが障害物があることを検出すると）、 ``count`` は1増加します。
``count`` をBlynk Cloudのデータストリーム ``V8`` と回路上の7セグメントディスプレイに書き込み、ドアを開きます。
オブジェクトが現在から欠如する場合、つまりオブジェクトがドアに入った場合、ドアを閉じます。

.. code-block:: arduino

    void channelEntrance()
    {
        int currentState = digitalRead(irPin); // 0:障害物 1:障害物なし
        if (currentState == 0 && lastState == 1) {
            count=(count+1)%10;
            Blynk.virtualWrite(V8, count);
            showNumber(count);
            operateGate(true);
        } else if ((currentState == 1 && lastState == 0)) {
            operateGate(false);
        }
        lastState = currentState;
    }

関数 ``showNumber(int num)`` は、7セグメントディスプレイに値を表示するために使用されます。

.. code-block:: arduino

    void showNumber(int num)
    {
        digitalWrite(STcp, LOW); //ST_CPをグラウンドにし、データを送信している間、ローに保持します
        shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
        digitalWrite(STcp, HIGH); //データを保存するためにST_CPをプルアップします
    }

関数 ``operateGate(bool openGate)`` は、参照が ``True`` の場合、ゆっくりとドアを開き、参照が ``False`` の場合、ゆっくりとドアを閉じます。


.. code-block:: arduino

    void operateGate(bool openGate) {
        if (openGate == true) 
        {
            // open gate
            while (angle <= 90) { 
            angle++;
            myservo.write(angle);
            delay(5);
            }
        } else {
            // close gate
            while (angle >= 0){ 
            angle--;
            myservo.write(angle);
            delay(5);
            }
        }
    }