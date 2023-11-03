.. _ar_pump:

1.4 ポンピング
===================

水ポンプもモーターの一種であり、特別な構造を通じてモーターや他の外部エネルギーの機械的エネルギーを変換し、液体を輸送するものです。

.. **回路図**

.. .. image:: img/circuit_1.3_wheel.png

.. IN1〜IN4はL298Nモジュールの入力であり、OUT1〜OUT4は出力です。

.. それらを使用する簡単な方法は次のとおりです：INxに高レベルを入力すると、OUTxは高レベルを出力します；INxに低レベルを入力すると、OUTxは低レベルを出力します。
.. モーターの両端をOUT1とOUT2に接続し、IN1とIN2に逆のレベル信号を入力すると、モーターが回転します。OUT3とOUT4も同様に使用できます。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

キット全体を購入すると確かに便利です、リンクはこちら：

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
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_pump`
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
    * - B-1B(B-2A)
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
.. image:: img/1.4_pumping_bb.png
    :width: 800
    :align: center

**コード**

.. note::

   * ファイル ``1.4.pumping.ino`` を ``3in1-kit\learning_project\1.4.pumping`` のパスの下で開くことができます。
   * または、このコードを **Arduino IDE** にコピーしてください。
   
   

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f829508f-2475-4de6-bc2f-ab0a68d707b1/preview?F=undefined?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
ポンプにチューブを追加し、ベースンに置きます。コードが正常にアップロードされた後、しばらくするとベースンの水が排出されることが確認できます。
この実験を行うときは、回路が水から離れているようにして、短絡を避けてください！
