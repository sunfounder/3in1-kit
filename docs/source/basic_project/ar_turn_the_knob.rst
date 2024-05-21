.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_potentiometer:

4.1 ノブを回す
===================

ポテンショメータは3端子の抵抗成分であり、その抵抗値は一定の変化に応じて調整することができます。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

一式を購入するのは非常に便利です。購入リンクはこちら：

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
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|


**回路図**

.. image:: img/circuit_5.1_potentiometer.png

この例では、アナログピン（A0）を使用してポテンショメータの値を読み取ります。ポテンショメータの軸を回転させることで、これら3つのピンの間での抵抗の分配を変更し、中央のピンの電圧を変更することができます。中央と5Vに接続された外側のピンとの間の抵抗がゼロに近い（そして中央と他の外側のピンとの間の抵抗が10kΩに近い）場合、中央のピンの電圧は5Vに近くなります。逆の操作（中央と5Vに接続された外側のピンとの間の抵抗が10kΩに近い場合）は、中央のピンの電圧が0Vに近くなるようにします。

**配線図**

.. image:: img/turn_thek_knob_bb.jpg
    :width: 600
    :align: center

**コード**

.. note::

   * ``3in1-kit\basic_project\4.1.turn_the_knob`` のパスの下にある ``4.1.turn_the_knob.ino`` ファイルを開くことができます。
   * または、このコードを **Arduino IDE** にコピーします。
   
   * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d931f2c9-74bc-4a53-8531-39a21a07dbaf/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
ボードにコードをアップロードした後、シリアルモニターを開いてピンの読み取り値を確認することができます。ポテンショメータの軸を回転させると、シリアルモニターは「0」~「1023」の値を表示します。
