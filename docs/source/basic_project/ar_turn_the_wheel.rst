.. _ar_motor:

1.3 車輪を回す
============================

モーターは典型的なデジタル出力デバイスであり、LEDと同じ方法で使用されます。
ただし、モーターは大電流で駆動する必要があり、
その大電流はR4ボードなどのメインコントロールボードを損傷させる可能性があります。
したがって、このような場合にはモータードライバーモジュールが使用され、
これはR4ボードがモーターを安全に制御するのに役立ちます。

.. **回路図**

.. .. image:: img/circuit_1.3_wheel.png

.. IN1〜IN4はL298Nモジュールの入力であり、OUT1〜OUT4は出力です。

.. それらを使用する簡単な方法は次のとおりです: INxに高レベルを入力すると、OUTxは高レベルを出力します。INxに低レベルを入力すると、OUTxは低レベルを出力します。
.. モーターの両端をOUT1とOUT2に接続し、IN1とIN2に対して逆のレベル信号を入力すると、モーターが回転します。OUT3とOUT4も同じ方法で使用できます。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入するのが便利です、リンクはこちら： 

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

**回路図**

.. image:: img/circuit_1.3_wheel_l9110.png

**配線図**

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L9110S
      - R4ボード
      - モーター
    * - VCC
      - 5V
      - 
    * - GND
      - GND
      - 
    * - B-1B
      - 9
      -
    * - B-1A
      - 10
      - 
    * - OA
      - 
      - モーターのワイヤー
    * - OB
      - 
      - モーターのワイヤー

.. image:: img/1.3_turn_the_wheel_bb.png
    :width: 800
    :align: center

**コード**

.. note::

   * ファイル ``1.3.turn_the_wheel.ino`` をパス ``3in1-kit\learning_project\1.3.turn_the_wheel`` で開くことができます。
   * または、このコードを **Arduino IDE** にコピーしてください。
   
   

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/5f8e4f33-883b-4c06-9516-f1754ea2121d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

