.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_segment:

5.10 ShiftOut(7セグメント表示)
===================================

以前は、 ``shiftout()`` 関数を使用して8つのLEDを点灯させましたが、ここではそれを使用して7セグメントディスプレイに0-9を表示します。

7セグメントディスプレイは、基本的に8つのLEDで構成されたデバイスであり、7つのストリップ形状のLEDが「8」の形を作り、小さな点LEDが小数点としてあります。これらのLEDはa, b, c, d, e, f, g, dpとしてマークされています。それぞれが独自のアノードピンを持ち、カソードを共有しています。ピンの位置は下の図に示されています。

.. image:: img/segment_cathode.png
    :width: 600
    :align: center

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

キット全体を購入するのは確かに便利です。リンクは以下の通りです：

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
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**回路図**

.. image:: img/circuit_6.5_segment.png

**配線図**

.. list-table:: 配線
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - LEDセグメントディスプレイ
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

.. image:: img/segment_bb.jpg
    :width: 600
    :align: center

**コード**

.. note::

    * ``3in1-kit\basic_project\5.10.shiftout_segment`` のパスの下にある ``5.10.shiftout_segment.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/23b9a3ea-c648-4f33-8622-e279d94ee507/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードが正常にアップロードされた後、LEDセグメントディスプレイが0〜9を順番に表示するのを見ることができます。

**どのように動作するのか？**

``shiftOut()`` は74HC595に8つのデジタル信号を出力させます。
それは、二進数の最後のビットをQ0に、
最初のビットの出力をQ7にします。つまり、
二進数"00000001"を書くと、Q0はハイレベルを出力し、Q1〜Q7はローレベルを出力します。

7セグメントディスプレイで数字の「2」を表示すると仮定すると、
a, b, d, e, gにハイレベルを書き、c, f, dpにローレベルを書く必要があります。
つまり、二進数 "01011011"を書く必要があります。
可読性のために、16進表記として"0x5b"を使用します。

.. image:: img/7_segment2.png

* `16進数 <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `BinaryHexコンバータ <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

同様に、7セグメントディスプレイで他の数字も同じ方法で表示させることができます。
以下の表は、これらの数字に対応するコードを示しています。

.. list-table:: グリフコード
    :widths: 20 20 20
    :header-rows: 1

    *   - Numbers	
        - Binary Code
        - Hex Code  
    *   - 0	
        - 00111111	
        - 0x3f
    *   - 1	
        - 00000110	
        - 0x06
    *   - 2	
        - 01011011	
        - 0x5b
    *   - 3	
        - 01001111	
        - 0x4f
    *   - 4	
        - 01100110	
        - 0x66
    *   - 5	
        - 01101101	
        - 0x6d
    *   - 6	
        - 01111101	
        - 0x7d
    *   - 7	
        - 00000111	
        - 0x07
    *   - 8	
        - 01111111	
        - 0x7f
    *   - 9	
        - 01101111	
        - 0x6f

これらのコードを ``shiftOut()`` に書き込むと、LEDセグメントディスプレイが対応する数字を表示します。