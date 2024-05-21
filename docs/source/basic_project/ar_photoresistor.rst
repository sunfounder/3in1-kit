.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_photoresistor:

4.2 光を感じる
===========================

光抵抗はアナログ入力のための代表的なデバイスで、ポテンショメータと非常に似た方法で使用されます。その抵抗値は光の強度に依存しており、照射される光が強いほど抵抗値は小さくなりますが、その逆の場合、抵抗値は増加します。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

一式を購入すると確かに便利です。以下がリンクです：

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**回路図**

.. image:: img/circuit_5.2_light.png

この回路では、10Kの抵抗と光抵抗が直列に接続されており、両方を通る電流は同じです。10Kの抵抗は保護として機能し、ピンA0は光抵抗の電圧変換後の値を読み取ります。

光が強くなると、フォト・レジスタの抵抗が減少し、電圧が下がるので、ピンA0からの値は増加する；
光が十分に強ければ、フォト抵抗の抵抗値は0に近くなり、A0ピンの値は1023に近くなる。
この時、10K抵抗が保護的な役割を果たし、5VとGNDが接続され、短絡にならないようにしている。

光抵抗を暗い状況に置くと、ピンA0の値は減少します。十分に暗い状況では、光抵抗の抵抗は無限大となり、その電圧は5V（10K抵抗は無視できる）に近く、ピンA0の値は0に近くなります。

**配線図**

.. image:: img/4.2_feel_the_light_bb.png
    :width: 600
    :align: center

**コード**

.. note::

    * ``3in1-kit\learning_project\4.2.feel_the_light`` のパス下の ``4.2.feel_the_light.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e1bc4c8b-788e-4bfe-a0a1-532d4fdc7753/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、シリアルモニタは光抵抗の値を表示します。現在の周囲の明るさが強いほど、シリアルモニタに表示される値は大きくなります。
