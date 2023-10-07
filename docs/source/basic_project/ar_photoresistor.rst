.. _ar_photoresistor:

4.2 光を感じる
===========================

フォトレジスタはアナログ入力の典型的なデバイスであり、ポテンショメータと非常に似た方法で使用されます。その抵抗値は光の強度に依存しており、照射される光が強ければ強いほど、その抵抗値は小さくなります。逆に、光が弱ければ抵抗値は増加します。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

キット全体を購入すると非常に便利です。リンクは以下です：

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**回路図**

.. image:: img/circuit_5.2_light.png

この回路では、10Kの抵抗器とフォトレジスタが直列に接続されており、通過する電流は同じです。10Kの抵抗器は保護として機能し、ピンA0はフォトレジスタの電圧変換後の値を読み取ります。

光が増加すると、フォトレジスタの抵抗が減少し、その電圧が減少するため、ピンA0からの値が増加します。
光が十分強い場合、フォトレジスタの抵抗が0に近づき、ピンA0の値が1023に近づくでしょう。この時、10Kの抵抗器は保護役として機能し、5VとGNDが短絡するのを防ぎます。

フォトレジスタを暗い場所に置くと、ピンA0の値が減少します。十分に暗い場所では、フォトレジスタの抵抗は無限大となり、その電圧は5V（10Kの抵抗器は無視できる）に近づき、ピンA0の値は0に近づくでしょう。


**配線図**

.. image:: img/feel_the_light_bb.jpg
    :width: 600
    :align: center

**コード**

.. note::

    * ``3in1-kit\basic_project\4.2.feel_the_light`` のパスの下にある ``4.2.feel_the_light.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * あるいは、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e1bc4c8b-788e-4bfe-a0a1-532d4fdc7753/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードが正常にアップロードされると、シリアルモニタにフォトレジスタの値が表示されます。
周囲の明るさが強いほど、シリアルモニタに表示される値が大きくなります。
