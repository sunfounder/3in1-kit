.. _ar_moisture:

4.4 土壌の湿度を測定する
==========================

農業の世界では、作物自体が土壌中の無機元素を直接取得することはできません。
土壌の水は、これらの無機元素を溶解するための溶媒として作用します。

作物は根系を通じて土壌の湿度を吸収し、栄養を取得し、成長を促進します。

作物の成長と発展の過程で、土壌温度に対する要求も異なります。
したがって、土壌湿度センサーが必要となります。

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**回路図**

.. image:: img/circuit_5.4_soil.png

**配線図**

.. image:: img/measure_the_moisture_bb.jpg
    :width: 800
    :align: center

**コード**

.. note::

    * ``3in1-kit\basic_project\4.4.measure_soil_moisture`` のパスの下で ``4.4.measure_soil_moisture.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b6f7e756-0f14-4117-9bb2-ee5083b6445f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードのアップロードが成功したら、シリアルモニタは土壌の湿度値を表示します。

モジュールを土壌に挿入し、水をやると、土壌湿度センサの値は小さくなります。
