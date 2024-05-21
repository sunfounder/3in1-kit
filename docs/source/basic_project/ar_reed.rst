.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_reed:

3.2 磁気を感じる
===============================

最も一般的なリードスイッチには、スイッチが開いているときに小さなギャップによって端部が分離されている、磁気化可能な柔軟な金属のリードのペアが含まれています。

電磁石や永久磁石からの磁場は、リードが互いに引き付けるように作用し、電気回路を完成させます。
リードのバネ力は、磁場が停止すると、それらを分離させて回路を開きます。

リードスイッチの一般的な例は、セキュリティアラームのためのドアや窓の開放を検出することです。

**必要な部品**

このプロジェクトには、以下の部品が必要です。

キット全体を購入することは確かに便利です。こちらがリンクです:

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_reed`
        - \-

**回路図**

.. image:: img/circuit_3.2_reed.png

デフォルトでは、ピン2はローです。磁石がリードスイッチの近くにあると、ハイになります。

10Kの抵抗の目的は、磁石が近くにないときにピン2を安定したローレベルに保つことです。

**配線図**

.. image:: img/3.2_feel_the_magnetism_bb.png
    :width: 600
    :align: center

**コード**

.. note::

   * ``3in1-kit\learning_project\3.2.feel_the_magnetism`` のパスの下にある ``3.2.feel_the_magnetism.ino`` ファイルを開くことができます。
   * または、このコードを **Arduino IDE** にコピーしてください。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/d28c942e-5144-44a1-85d8-d5e6894fc5df/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードが正常にアップロードされた後、磁石がリードスイッチの近くにあると、シリアルモニターは1を印刷します。
