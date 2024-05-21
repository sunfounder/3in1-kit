.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_button:

3.1 ボタンの値の読取り
==============================================

前回のプロジェクトでは出力関数を使用しましたが、この章では入力関数を使用してボタンの値を読み取ります。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入すると非常に便利です。こちらがリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクからそれぞれ別々に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネントの紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

**回路図**

.. image:: img/circuit_3.1_button.png

ボタンの片側のピンは5Vに接続され、
もう一方のピンはピン2に接続されているため、
ボタンが押されると、
ピン2はハイになります。しかし、
ボタンが押されていない場合、
ピン2は浮遊状態であり、ハイまたはローのどちらかになる可能性があります。
ボタンが押されていないときに安定したローレベルを得るために、
ピン2は10Kのプルダウン抵抗を通してGNDに再接続する必要があります。

**配線図**

.. image:: img/3.1_reading_button_value_bb.png
    :width: 600
    :align: center

**コード**

.. note::

   * ``3in1-kit\learning_project\3.1.read_button_value`` のパスの下で ``3.1.read_button_value.ino`` ファイルを開くことができます。
   * または、このコードを **Arduino IDE** にコピーしてください。
   

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/b456ff57-4dfb-4231-9d91-f1e9a5777de2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされた後、Arduino IDEの右上隅にある虫眼鏡のアイコン（シリアルモニタ）をクリックします。

.. image:: img/sp220614_152922.png

ボタンを押すと、シリアルモニタに「1」と表示されます。

