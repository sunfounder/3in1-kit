.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _iot_window:

3. Blynkへのデータ送信
=============================

本章では、Blynkへのデータ送信方法をご紹介します。

ここでは、ドアおよび窓の検出デバイスを作成します。リードスイッチを使用した回路は、ドアや窓の隣に配置され、磁石はドアや窓の端に取り付けられます。
ドアや窓が閉じられると、リードスイッチは磁力でオンになり、R4ボード上の対応するピンの値が変化します。
Blynk.cloudはこの値を受け取るので、家を離れていても家のドアや窓が閉じているかどうかを確認できます。

現在、BlynkのLEDウィジェットを使用して、窓とドアが閉じているかどうか（すなわち、リードスイッチがオンまたはオフか）を示すことになります。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

キットをまとめて購入すると確実に便利です、以下がそのリンクです：

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
    *   - :ref:`cpn_reed`
        - \-

**1. 回路を組む**

.. note::

    ESP8266モジュールは安定した動作環境を提供するために高い電流を必要とするため、9Vのバッテリーが接続されていることを確認してください。

.. image:: img/iot_3_bb.png

**2. ダッシュボードを編集**

#. **Datastream** ページで **Virtual Pin** タイプの **Datastream** を作成し、リードスイッチの値を取得します。DATA TYPEを **Integer** に設定し、MINとMAXを **0** と **1** にします。

    .. image:: img/sp220609_162548.png

#. **Wed Dashboard** ページで **LED widget** をドラッグアンドドロップし、値が1の場合、それは（色と共に）点灯し、それ以外の場合は白くなります。

    .. image:: img/blynk_edit_drag_led_widget.png

#. **LED widget** の設定ページで、 **Datastream** を **Reed(V1)** として選択し、保存します。

    .. image:: img/sp220609_163502.png


**3. コードの実行**

#. ``3in1-kit\iot_project\3.push_data_to_blynk`` のパスの下の ``3.push_data_to_blynk.ino`` ファイルを開く、またはこのコードを **Arduino IDE** にコピーします。

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/e81b0024-c11e-4507-8d43-aeb3b6656c2c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. ``Template ID``、 ``Device Name``、および ``Auth Token`` を自分のものに置き換えます。また、使用しているWiFiの ``ssid`` および ``password`` を入力する必要があります。詳しいチュートリアルは、 :ref:`connect_blynk` を参照してください。
#. 正しいボードとポートを選択した後、 **Upoad** ボタンをクリックします。

#. シリアルモニターを開いて（ボーレートを115200に設定し）、接続が成功したようなプロンプトが表示されるのを待ちます。

    .. image:: img/2_ready.png

    .. note::

        接続するときに ``ESP is not responding`` というメッセージが表示される場合は、次の手順に従ってください。

        * 9Vのバッテリーが接続されていることを確認してください。
        * ピンRSTを1秒間GNDに接続して、ESP8266モジュールをリセットし、その後、それを抜きます。
        * R4ボードのリセットボタンを押します。

        まれに、上記の操作を3-5回繰り返す必要がある場合があります。しばらくお待ちください。

#. これで、Blynkはあなたのドアや窓の状態を表示します。ドアや窓が閉じている場合、LEDウィジェットは緑色になり、そうでない場合は灰色になります。

#. Blynkをモバイルデバイスで使用したい場合は、 :ref:`blynk_mobile` を参照してください。



**どのように動作するのか？**


この例では、次の行に注目してください。"Blynk CloudのV1 Datastreamに毎秒データを書き込む"は、これらの行で定義されています。

.. code-block:: arduino

    BlynkTimer timer;

    void myTimerEvent()
    {
        Blynk.virtualWrite(V1, pinValue);
    }

    void setup()
    {
        timer.setInterval(1000L, myTimerEvent);
    }

    void loop()
    {
        timer.run(); // BlynkTimerを開始
    }

Blynkライブラリは組み込みのタイマーを提供しています。まず、タイマーオブジェクトを作成します。

.. code-block:: arduino

    BlynkTimer timer;

``setup()`` でタイマー間隔を設定します。ここでは、 ``myTimerEvent()`` 関数を毎秒1000msで実行するように設定します。

.. code-block:: arduino

    timer.setInterval(1000L, myTimerEvent);

``loop()`` でBlynkTimerを実行します。

.. code-block:: arduino

    timer.run();

カスタム関数 ``myTimerEvent()`` を編集します。コード ``Blynk.virtualWrite(V1, pinValue)`` は、V1のデータpinValueを書き込むために使用されます。

.. code-block:: arduino

    void myTimerEvent()
    {
        Blynk.virtualWrite(V1, pinValue);
    }


