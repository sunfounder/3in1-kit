.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_interval:

5.4 インターバル
================

時折、同時に2つの作業を行う必要があります。たとえば、LEDを点滅させながらボタンの押下を読み取りたい場合などです。この場合、 ``delay()`` を使用することはできません。なぜなら、Arduinoは ``delay()`` の間、プログラムを一時停止します。 ``delay()`` を待っている間にボタンが押されると、プログラムはボタンの押下を検出しません。

例えるならば、電子レンジでピザを温めるときに、重要なメールを待っている状況と似ています。ピザを電子レンジに入れて10分間セットします。 ``delay()`` を使うことに例えると、10分間カウントダウンするタイマーを見つめ続け、0になるのを待つことになります。この時間内に重要なメールが届いても、気づくことはできません。

実際の生活では、ピザを焼き、メールをチェックし、何か他のことをし（あまり時間がかからない！）、時々電子レンジに戻ってタイマーがゼロになったかどうかを確認する。

このスケッチでは、 ``delay()`` を使用せずにブザーを鳴らす方法を示しています。
ブザーをオンにし、時刻を記録します。その後、 ``loop()`` の中で所望のインターバル時間が経過したかどうかを確認します。
経過していれば、ブザーを鳴らし、新しい時間を記録します。
この方法で、スケッチの実行は一つの指示に遅延することなく、ブザーは継続して音を鳴らします。

この条件に基づいて、LEDを制御するボタンのコードを追加することができます。これにより、ブザーが音楽を再生しても邪魔されることはありません。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

全てのキットを購入するのは確かに便利です、以下がリンクです：

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
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|


**回路図**

.. image:: img/circuit_8.5_interval.png

**配線図**

.. image:: img/interval_bb.jpg
    :width: 600
    :align: center

**コード**

.. note::

    * ``3in1-kit\basic_project\5.4.interval`` のパスの下の ``5.4.interval.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ でコードをアップロードします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/0d430b04-ef2d-4e32-8d76-671a3a917cb1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードが正常にアップロードされると、ブザーは音楽を再生し、ボタンを押すたびにLEDが点灯します。LEDとブザーの動作は互いに干渉しません。

**どのように動作するのか？**

マイクロコントローラの前回の操作時間を保存する変数 ``previousMillis`` を初期化します。

.. code-block:: arduino

    unsigned long previousMillis = 0;     

どのノートが再生されるかをマークします。

.. code-block:: arduino

    int thisNote=0; 

各ノートの間隔時間。

.. code-block:: arduino

    long interval = 1000; 

``loop()`` 内で、現在の時刻を保存するために ``currentMillis`` を宣言します。

.. code-block:: arduino

    unsigned long currentMillis = millis();

現在の動作時間と最後の更新時間の間隔が1000msより大きい場合、特定の機能がトリガーされます。その間、次のトリガーが1秒後に発生するため、previousMillisを現在の時間に更新します。

.. code-block:: arduino

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;// 最後の音の最後の時間を保存
        //...
    }

メロディのノートを順番に再生します。

.. code-block:: arduino

    tone(buzzerPin,melody[thisNote],100);
    interval=1000/noteDurations[thisNote]; // 音を出す間隔
    thisNote=(thisNote+1)%(sizeof(melody)/2); //メロディのノートを順番に

ボタンはLEDを制御します。

.. code-block:: arduino

  // ボタンとLEDの再生
  digitalWrite(ledPin,digitalRead(buttonPin));
