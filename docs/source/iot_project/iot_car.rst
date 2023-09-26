.. _iot_car:

8. IoT カー
====================

このプロジェクトでは、携帯電話のBlynkアプリを使用して車を制御しました。しかし、車の組み立てや基本的な理解については、 :ref:`car_projects` を参照してください。
5Gネットワークの普及時代に、このモードは多くの産業で主要な生産方法の一つとなるかもしれませんので、先取りしてこのプレイを体験してみましょう。

**1. 回路を組む**

.. image:: img/iot_car.png
    :width: 800

**2. ダッシュボードを編集**

モバイルのBlynkではDatastreamを編集することができないので、これらのステップはウェブサイドで行う必要があります。

#. **Datastream** ページで、ジョイスティックのX軸の値を記録するための **Virtual Pin** タイプの **Datastream** を作成します。NAMEを ``Xvalue``、DATA TYPEを ``Integer``、MINとMAXを ``-10`` と ``10`` に設定します。

    .. image:: img/sp220613_164507.png

#. ジョイスティックのY軸の値を記録するための **Virtual Pin** タイプの **Datastream** を作成します。NAMEを ``Yvalue``、DATA TYPEを ``Integer``、MINとMAXを ``-10`` と ``10`` に設定します。

    .. image:: img/sp220613_164717.png

次に、以下の手順を携帯電話で行ってください。

1. GOOGLE PlayまたはAPP Storeで "Blynk IoT" (Blynk(legacy)ではありません)を検索してダウンロードします。
2. アプリを開いてログインします。このアカウントは、ウェブクライアントで使用したアカウントと同じである必要があります。
3. 次にダッシュボードに移動します（持っていない場合は作成します）。モバイルとウェブのダッシュボードは互いに独立していることがわかります。

.. image:: img/APP_1.jpg

4. 編集アイコンをクリックします。
5. 空白のエリアをクリックします。
6. ジョイスティックウィジェットを選択します。

.. image:: img/APP_2.jpg

7. 空白のエリアにジョイスティックウィジェットが表示されますので、それをクリックします。
8. ジョイスティックの設定が表示されますので、先ほどdatastreamsで設定したXvalueとYvalueを選択します。
9. ダッシュボードページに戻って、ジョイスティックを操作したいときに操作します。

.. image:: img/APP_3.jpg

**3. コードの実行**

#. ``3in1-kit\iot_project\8.iot_car`` のパス下で ``8.iot_car.ino`` ファイルを開くか、このコードを **Arduino IDE** にコピーします。

    .. raw:: html 
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/a1db6c35-2f26-425c-8636-53d2df7936d7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. 自分の ``Template ID``、 ``Device Name``、および ``Auth Token`` に置き換えます。使用しているWiFiの ``ssid`` および ``password`` も入力する必要があります。詳しいチュートリアルは、 :ref:`connect_blynk` を参照してください。
#. 適切なボードとポートを選択した後、 **Upoad** ボタンをクリックします。

#. シリアルモニター（ボーレートを115200に設定）を開き、成功した接続などのプロンプトが表示されるのを待ちます。

    .. image:: img/2_ready.png

    .. note::

        接続時に ``ESP is not responding`` というメッセージが表示された場合、以下の手順に従ってください。

        * 9Vのバッテリーが接続されていることを確認してください。
        * RSTピンを1秒間GNDに接続してESP8266モジュールをリセットし、その後、それを取り外します。
        * R4ボード上のリセットボタンを押します。

        これらの操作を3〜5回繰り返す必要があることがあります。忍耐強く行ってください。


#. 今、USBケーブルを抜いて、9Vのバッテリーだけでカートを起動します。LEDが点灯するのを待ちます。これは、車がBlynkに接続されていることを示しています。
#. 携帯電話でBlynkを開き、ジョイスティックウィジェットを使用して車の動きを制御できます。

    .. image:: img/iot_car.jpg

**どのように動作するのか？**

これらの関数は、車の動きを制御するために使用されます。

.. code-block:: arduino

    void moveForward(int speed) {...}
    void moveBackward(int speed) {...}
    void turnRight(int speed) {...}
    void turnLeft(int speed) {...}
    void stopMove() {...}

IoTセクションは、ジョイスティックウィジェットの値を読み取り、それらを変数 ``Xvalue`` および ``Yvalue`` に割り当てます。

.. code-block:: arduino

    int Xvalue = 0;
    int Yvalue = 0;

    BLYNK_WRITE(V9)
    {
        Xvalue = param.asInt();
    }

    BLYNK_WRITE(V10)
    {
        Yvalue = param.asInt();
    }

``loop()`` で、 ``Xvalue`` および ``Yvalue`` に基づいて車にさまざまなアクションを実行させます。

.. code-block:: arduino

    if (Yvalue >= 5) {
        moveForward(255);
    } else if (Yvalue <= -5) {
        moveBackward(255);
    } else if (Xvalue >= 5) {
        turnRight(150);
    } else if (Xvalue <= -5) {
        turnLeft(150);
    } else {
        stopMove();
    }

また、Blynk Cloudに接続されている場合にLEDを点灯させるために、 ``loop()`` にネットワークステータスの判定を追加します。


.. code-block:: arduino

    if (!Blynk.connected()) {
        digitalWrite(ledPin, LOW);
        Serial.print("offline!");
        bool result = Blynk.connect();
        Serial.println(result);
    } else {
        digitalWrite(ledPin, HIGH);
    }