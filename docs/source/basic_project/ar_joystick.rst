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

4.3 ジョイスティックの操作
================================

ジョイスティックは、定期的にビデオゲームを楽しむ人々にとっては非常に馴染み深いものです。
通常、キャラクターの移動や画面の回転に使用されます。

我々の動きは、ジョイスティックによって読み取ることができ、これは非常に単純な原理で動作します。
それは、互いに垂直な二つのポテンショメーターから成っています。
これらのポテンショメーターはジョイスティックの垂直と水平の両方の方向でのアナログ値を測定し、平面直角座標系での値(x,y)を生成します。

このキットには、デジタル入力を持つジョイスティックも含まれています。ジョイスティックが押されたときに作動します。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

一式を購入するのは確かに便利です。リンクは以下のとおりです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクから別々に購入することも可能です。

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
    *   - :ref:`cpn_joystick`
        - \-

**回路図**

.. image:: img/circuit_5.3_joystick.png

.. note::
    SWピンは10Kのプルアップ抵抗に接続されています。
    これは、ジョイスティックが押されていないときにSWピン(Z軸)で安定した高レベルを得るためです。
    それ以外の場合、SWはサスペンド状態となり、出力値は0/1の間で変動する可能性があります。

**配線図**

.. image:: img/4.3_toggle_the_joystick_bb.png
    :width: 800
    :align: center

**コード**

.. note::

    * ``3in1-kit\learning_project\4.3.toggle_the_joystick`` のパスの下の ``4.3.toggle_the_joystick.ino`` ファイルを開きます。
    * あるいは、このコードを **Arduino IDE** にコピーします。
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f678a03f-546c-42ed-bfae-b8c7daa5eec9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされた後、シリアルモニターを開くと、ジョイスティックのx,y,zの値が表示されます。

* x軸とy軸の値は0から1023までのアナログ値です。
* Z軸は1または0の状態のデジタル値です(押された場合は0)。
