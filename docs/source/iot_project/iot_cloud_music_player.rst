.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _iot_music:

4. クラウド音楽プレイヤー
=====================================

このプロジェクトの目標はBlynkを使った音楽プレイヤーを作ることです。
音楽の再生は :ref:`ar_passive_buzzer` と同じように、プログラムに曲を書いてパッシブ・ブザーで再生する。
しかし、この例では、スイッチをクリックすると再生/一時停止ができ、スライダーをスライドさせると再生の進行状況を変えることができます。


**必要な部品**

このプロジェクトでは、以下の部品が必要です。

一式をまとめて購入するのは便利です。リンクは以下の通りです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクから、部品を個別に購入することもできます。

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
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|

**1. 回路を組む**

.. note::

    ESP8266モジュールは、安定した動作環境を確保するために高電流が必要です。9Vのバッテリーが接続されていることを確認してください。

.. image:: img/wiring_buzzer.jpg

**2. ダッシュボードを編集**

#. **Datastream** ページで、後で追加されるスライダーウィジェットまたはコードで変更する値として **Virtual Pin** タイプの **Datastream** を作成します。データタイプは **Integer** にし、MINとMAXを **0** と **30** に設定します。

    .. image:: img/sp220610_104330.png

#. 音楽の名前を表示するための **Virtual Pin** タイプの **Datastream** も作成します。データタイプは ``String`` に設定してください。

    .. image:: img/sp220610_105932.png

#. **Wed Dashboard** ページに移動して、 **Switch** ウィジェットをドラッグし、 **Datastream** をV0に設定します( :ref:`iot_blink` で既に設定済み); **Label** ウィジェットをドラッグしてV3に設定; **Slider** ウィジェットをドラッグしてV2に設定します。

    .. image:: img/sp220610_110105.png

.. note::

    あなたの仮想ピンの番号は私のものと異なるかもしれません。あなたの設定が優先されますので、コード内の対応するピン番号を修正してください。



**3. コードの実行**

#. パス ``3in1-kit\iot_project\4.cloud_music_player`` の下にある ``4.cloud_music_player.ino`` ファイルを開きます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/34a49c4b-9eb4-4d03-bd78-fe1daefc9f5c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. ``Template ID`` 、 ``Device Name`` 、および ``Auth Token`` を自分のものに置き換えます。使用しているWiFiの ``ssid`` と ``password`` も入力する必要があります。詳しいチュートリアルについては、 :ref:`connect_blynk` を参照してください。
#. 正しいボードとポートを選択した後、 **Upoad** ボタンをクリックします。

#. シリアルモニタを開き（ボーレートを115200に設定）、成功した接続のようなプロンプトが表示されるのを待ちます。

    .. image:: img/2_ready.png

    .. note::

        接続時に ``ESP is not responding`` メッセージが表示される場合は、以下の手順に従ってください。

        * 9Vのバッテリーが接続されていることを確認してください。
        * RSTピンを1秒間GNDに接続してESP8266モジュールをリセットし、その後プラグを抜きます。
        * R3ボードのリセットボタンを押します。

        ときどき、上記の操作を3〜5回繰り返す必要がある場合があります。お待ちください。

#. これで、Blynkのボタンコントロールウィジェットを使用して音楽の再生/一時停止を切り替えたり、スライダーで再生の進行状況を調整したりできます。また、音楽の名前も表示されます。

    .. image:: img/sp220610_110105.png

#. Blynkをモバイルデバイスで使用したい場合は、 :ref:`blynk_mobile` を参照してください。

**どのように動作するのか？**

データストリーム **V0** は、Switchウィジェットのステータスを取得し、変数 **musicPlayFlag** に割り当てるために使用されます。これは音楽の再生と一時停止を制御します。

.. code-block:: arduino

    int musicPlayFlag=0;

    BLYNK_WRITE(V0)
    {
        musicPlayFlag = param.asInt(); // 音楽の開始/一時停止
    }

データストリーム **V2** は、スライダーウィジェットの値を取得し、スライダーが移動したときに変数 **scrubBar** に割り当てるために使用されます。

.. code-block:: arduino

    int scrubBar=0;

    BLYNK_WRITE(V2)
    {
        scrubBar=param.asInt();
    }

デバイスが **Blynk Cloud** に接続されているとき、 **V3** データストリームの音楽の名前を書き込み、それを **Label** ウィジェットで表示します。

.. code-block:: arduino

    BLYNK_CONNECTED() {
        String songName = "Ode to Joy";
        Blynk.virtualWrite(V3, songName);
    }

**Blynk Timer** は毎秒実行されます。 **musicPlayFlag** が0でない場合、つまり **Switch** ウィジェットがONの場合、音楽が再生されます。
2つのノートが再生されると、進行バー変数 ``scrubBar`` が2増加し、その値は次に **Blynk Cloud** に書き込まれ、 **Slider** ウィジェットの値が同期されます。


.. code-block:: arduino

    void myTimerEvent()
    {
        if(musicPlayFlag!=0)
        {
            tone(buzzerPin,melody[scrubBar],250);
            scrubBar=(scrubBar+1)%(sizeof(melody)/sizeof(int));
            delay(500);
            tone(buzzerPin,melody[scrubBar],250);
            scrubBar=(scrubBar+1)%(sizeof(melody)/sizeof(int));
            Serial.println(scrubBar);    
            Blynk.virtualWrite(V2, scrubBar);
        }
    }