.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _iot_blink:

2. Blynkからデータを取得
=================================

この章では、Blynkを使って回路を制御する方法を学びます。インターネットを介してLEDを点灯させましょう！

**必要な部品**

このプロジェクトには、以下の部品が必要です。

一式を購入することは非常に便利です。以下がリンクです：

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
    *   - :ref:`cpn_led`
        - |link_led_buy|

**1. 回路を組む**

.. note::

    ESP8266モジュールは、安定した動作環境を提供するために高い電流が必要です。9Vのバッテリーが接続されていることを確認してください。

.. image:: img/wiring_led.jpg

**2. ダッシュボードを編集**

#. 以前に作成した **Quickstart Device** にアクセスし、右上のメニューアイコンをクリックして **edit dashboard** を選択します。

    .. image:: img/sp220609_112825.png

#. Datastreamsは、BlynkのウィジェットとR3ボードのコードが相互に認識するための機能です。完全な設定プロセスを体験するために、DatastreamsページからすべてのDatastreamsを削除してください。

    .. image:: img/sp220609_114723.png

#. Datastreamsを削除する前に、警告を注意深く読んで正しいことを確認してください。

    .. image:: img/sp220609_114929.png

#. Blynkのスイッチを使用してLEDを制御するための **Virtual Pin** タイプのDatastreamを作成します。

    .. image:: img/sp220609_115124.png

#. **Virtual Pin** を設定します。ボタンとLEDはONとOFFのみが必要なので、DATA TYPEを ``Integer`` に設定し、MINとMAXを ``0`` と ``1`` に設定します。

    .. image:: img/sp220609_115520.png

#. **Web Dashboard** ページに移動し、既存のウィジェットを削除します。

    .. image:: img/sp220609_133707.png

#. 左の **Widget Box** から **switch** ウィジェットをドラッグアンドドロップします。

    .. image:: img/sp220609_114508.png

#. これで設定します。

    .. image:: img/sp20220615180127.png

#. 以前に設定した **Datastream** を選択します。

    .. image:: img/sp220609_133741.png

#. Datastreamを選択すると、いくつかのカスタム設定が表示されます。それらを設定した後、保存をクリックします。

    .. image:: img/sp220609_133950.png

#. 最後に、 **Save And Apply** をクリックします。

    .. image:: img/sp220609_141733.png


**3. コードの実行**

#. ``3in1-kit\iot_project\2.get_data_from_blynk`` のパスの下の ``2.get_data_from_blynk.ino`` ファイルを開くか、このコードを **Arduino IDE** にコピーします。

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b187a8-dabf-4866-b38c-742e0446cc3f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. ``Template ID`` 、 ``Device Name`` 、 ``Auth Token`` をあなた自身のものに置き換えます。使用中のWiFiの ``ssid`` と ``password`` も入力する必要があります。詳しいチュートリアルは、 :ref:`connect_blynk` を参照してください。

#. 正しいボードとポートを選択したら、 **Upoad** ボタンをクリックします。

    .. image:: img/2_upload.png

#. シリアルモニター（ボーレートを115200に設定）を開き、成功した接続のようなプロンプトが表示されるのを待ちます。

    .. image:: img/2_ready.png

    .. note::

        接続時に ``ESP is not responding`` のメッセージが表示される場合、次の手順に従ってください。

        * 9Vのバッテリーが接続されていることを確認します。
        * RSTピンを1秒間GNDに接続してESP8266モジュールをリセットし、その後、それを取り外します。
        * R3ボードのリセットボタンを押します。

        ときどき、上記の操作を3〜5回繰り返す必要があるかもしれませんので、お待ちください。

#. Blynkに戻ると、ステータスがオンラインに変わっているのがわかります。これで、blynkのスイッチウィジェットを使用してR3ボードに接続されているLEDを制御することができます。

    .. image:: img/2_blynk_button.png

#. モバイルデバイスでBlynkを使用したい場合は、 :ref:`blynk_mobile` を参照してください。

**どのように動作するのか？**

このプロジェクトのコードと前章の :ref:`connect_blynk` のコードとの違いは、以下の行になります。

.. code-block:: arduino

    const int ledPin=6;

    BLYNK_WRITE(V0)
    {
        int pinValue = param.asInt(); // V0からの入力値を変数に割り当てる
        // 以下も使用可能:
        // String i = param.asStr();
        // double d = param.asDouble();
        digitalWrite(ledPin,pinValue);
    }

    void setup()
    {
        pinMode(ledPin,OUTPUT);
    }

ledPinの ``pinMode`` と ``digitalWrite`` については、すでにお馴染みだと思いますので、再度説明しません。注目すべきは、``BLYNK_WRITE(V0)`` 関数です。

この関数が行うのは、Blynkの ``V0`` の値が変更されると、Blynk.Cloudがあなたのデバイスに「 **Virtual Pin** V0に書き込みをしています」と通知し、この情報を受け取ったデバイスが何かの動作をすることができることです。

前のステップでV0 Datastreamを作成し、スイッチウィジェットに適用しました。
これは、スイッチウィジェットを操作するたびに、 ``BLYNK_WRITE(V0)`` がトリガされることを意味します。

この関数には2つの命令を書き込んでいます。

.. code-block:: arduino

    int pinValue = param.asInt();

V0の値を取得し、変数 ``pinValue`` に割り当てます。

.. code-block:: arduino

    digitalWrite(ledPin,pinValue);

取得したV0の値をledPinに書き込むことで、BlynkのスイッチウィジェットでLEDを制御することができます。



