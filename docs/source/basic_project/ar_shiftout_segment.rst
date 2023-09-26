.. _ar_segment:

5.10 シフトアウト(セグメントディスプレイ)
===========================================

以前、私たちは ``shiftout()`` 関数を使用して8つのLEDを点灯させましたが、このセクションでは7セグメントディスプレイで0-9を表示させる方法を学びます。

7セグメントディスプレイは、実質的に8つのLEDで構成されており、そのうちの7つのストリップ形状のLEDが「8」の形を作り、小さめのドットのLEDが小数点として機能します。これらのLEDは、a、b、c、d、e、f、g、およびdpとしてマークされています。それぞれが独自のアノードピンを持ち、カソードを共有しています。ピンの位置関係は下図に示されています。

.. image:: img/segment_cathode.png
    :width: 600
    :align: center

**必要な部品**

このプロジェクトには、以下の部品が必要です。

一式をまとめて購入するのがおすすめです。リンクは以下になります：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

下記のリンクから個別に購入することも可能です。

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

.. image:: img/5.10_segment_bb.png
    :width: 600
    :align: center

**コード**

.. note::

    * ``3in1-kit\learning_project\5.10.shiftout_segment`` のパスの下にある ``5.10.shiftout_segment.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/23b9a3ea-c648-4f33-8622-e279d94ee507/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードのアップロードが成功した後、LEDセグメントディスプレイで0~9が順番に表示されることが確認できます。

**どのように動作するのか？**

``shiftOut()`` は74HC595に8つのデジタル信号を出力させます。
最後のビットのバイナリ数をQ0に、
最初のビットの出力をQ7に出力します。つまり、
バイナリ数「00000001」を書くと、Q0はハイレベルを出力し、Q1~Q7はローレベルを出力します。

7セグメントディスプレイで数字「2」を表示すると仮定します。
a, b, d, e, gにハイレベルを書き、c, f, dpにローレベルを書く必要があります。
つまり、バイナリ数「01011011」を書く必要があります。
可読性のため、16進数の表記「0x5b」を使用します。

.. image:: img/7_segment2.png

* `16進数 <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `BinaryHex 変換ツール <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

同様に、同じ方法で7セグメントディスプレイに他の数字を表示させることもできます。
以下のテーブルは、これらの数字に対応するコードを示しています。

.. list-table:: グリフコード
    :widths: 20 20 20
    :header-rows: 1

    *   - 数字	
        - バイナリコード
        - 16進数コード  
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

これらのコードを ``shiftOut()`` に入力すると、LEDセグメントディスプレイに対応する数字が表示されます。
