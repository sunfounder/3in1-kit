.. _ar_pump:

1.4 ポンピング
===================

水ポンプもモーターの一つで、モーターや他の外部エネルギーの機械エネルギーを特別な構造を通じて液体を輸送するものです。

**必要な部品**

このプロジェクトには以下の部品が必要です。

キット全体を購入すると非常に便利です、リンクは以下です:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

下のリンクから個別に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネント紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_l298n`
        - |link_l298n_buy|
    *   - :ref:`cpn_pump`
        - \-

**回路図**

.. image:: img/circuit_1.3_wheel.png

IN1～IN4はL298Nモジュールの入力であり、OUT1～OUT4は出力です。

それらを使う簡単な方法は：INxに高レベルを入力すると、OUTxは高レベルを出力します。INxに低レベルを入力すると、OUTxは低レベルを出力します。
モーターの両端をOUT1とOUT2に接続し、IN1とIN2に逆のレベルの信号を入力するとモーターが回転します。OUT3とOUT4も同じように使用できます。

**配線図**

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L298N
      - R3 ボード
      - モーター
    * - 12V
      - 5V
      - 
    * - GND
      - GND
      - 
    * - IN3
      - 9
      -
    * - IN4
      - 10
      - 
    * - OUT3
      - 
      - モーターのワイヤーの一方
    * - OUT4
      - 
      - モーターのワイヤーの一方

.. image:: img/pumping_bb.jpg
    :width: 800
    :align: center

**コード**

.. note::

   * ファイル ``1.4.pumping.ino`` を ``3in1-kit\basic_project\1.4.pumping`` のパスから開くことができます。
   * また、このコードを **Arduino IDE** にコピーしてください。
   
   * あるいは、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を使ってコードをアップロードしてください。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f829508f-2475-4de6-bc2f-ab0a68d707b1/preview?F=undefined?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
ポンプにチューブを追加して、それをベースンに置きます。コードが正常にアップロードされた後、しばらくするとベースンの水が排水されるのを確認できます。
この実験を行う際は、短絡を避けるため回路を水から離してください！
