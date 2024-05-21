.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_fading:

2.1 フェーディング
=====================

このプロジェクトは :ref:`ar_blink` に似ていますが、違いは信号の種類です。
前者はデジタル信号（0&1）を出力してLEDを点灯または消灯させるのに対し、このプロジェクトはアナログ信号を出力してLEDの明るさを制御します。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入するのが便利です。こちらのリンクから購入できます：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクから、個別に購入することもできます。

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
    *   - :ref:`cpn_led`
        - |link_led_buy|

**回路図**

.. image:: img/circuit_1.1_led.png

**配線図**

.. image:: img/1.1_hello_led_bb.png
    :width: 600
    :align: center

**コード**

.. note::

   * ``3in1-kit\learning_project\2.analogWrite\2.1.fading`` のパスの下で ``2.1.fading.ino`` ファイルを開くことができます。
   * または、このコードを **Arduino IDE** にコピーしてください。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8a7e52a4-fcb3-4c3b-98ff-f3f657822d72/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされた後、LEDが呼吸するように点滅するのが見えます。
