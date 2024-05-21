.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_if_else:

5.1 If else
==============

通常、私たちは条件判断を使って、最も基本的な現実のインタラクションプロジェクトを完成させます。
ここでは、リードスイッチとLEDを使用して、このロジックを示すドア検出システムを構築します。

ドアの片側に磁石を取り付け、ドアの反対側にリードスイッチ（回路付き）を取り付けます。
ドアが閉まっていると、磁石がリードスイッチに近づき、それをオンにします。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

キット全体を購入するのは間違いなく便利です。リンクはこちら：

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

    *   - コンポーネント紹介
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
    *   - :ref:`cpn_reed`
        - \-

**回路図**

.. image:: img/circuit_8.1_ifelse.png

**配線図**

.. image:: img/if_else_bb.jpg
    :width: 600
    :align: center

**コード**

.. note::

    * ``3in1-kit\basic_project\5.1.if_else`` のパスの下で ``5.1.if_else.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c7bf6236-1276-45a0-8d34-008d2d838476/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードが正常にアップロードされた後、ドアを閉めないと、LEDが点灯して、ドアを閉めるように促します。

ちなみに、ドアが閉まっているときにLEDを点灯させる逆の効果が必要な場合、 ``if`` の条件を変更するだけです。

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    ``if else`` は、複数のテストをグループ化できることで、基本的なif文よりもコードの流れをより大きく制御することができます。
