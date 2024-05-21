.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_joystick:

4.3 ジョイスティックのトグル
================================

ジョイスティックは、定期的にビデオゲームをプレイする人なら誰もが非常によく知っているはずです。
通常、キャラクターの移動や画面の回転に使用されます。

私たちの動きはジョイスティックによって読み取られ、非常にシンプルな原理で動作します。
これは、互いに直交する2つのポテンショメーターで構成されています。
これらの2つのポテンショメーターは、ジョイスティックの垂直および水平の両方の方向でのアナログ値を測定し、直交座標系での値（x,y）を生成します。

このキットには、デジタル入力を備えたジョイスティックも含まれています。ジョイスティックが押されると、それがアクティブになります。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入することは確かに便利です。リンクはこちら：

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_joystick`
        - \-

**回路図**

.. image:: img/circuit_5.3_joystick.png

.. note::
    SWピンは10Kのプルアップ抵抗器に接続されています。
    その理由は、ジョイスティックが押されていないときにSWピン（Z軸）で安定した高レベルを取得するためです。 
    そうでなければ、SWは一時停止状態となり、出力値は0/1の間で変動するかもしれません。

**配線図**

.. image:: img/toggle_the_joystick_bb.jpg
    :width: 800
    :align: center

**コード**

.. note::

    * ``3in1-kit\basic_project\4.3.toggle_the_joystick`` のパスの下で ``4.3.toggle_the_joystick.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f678a03f-546c-42ed-bfae-b8c7daa5eec9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードのアップロードが成功した後、シリアルモニタを開いてジョイスティックのx、y、zの値を確認してください。

* x軸とy軸の値は0から1023までのアナログ値です。
* Z軸は1または0のステータスを持つデジタル値です（押されると0になります）。
