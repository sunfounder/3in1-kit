.. _ar_eeprom:

6.2 電子サイコロ
=============================

このプロジェクトでは、ボタン、7セグメント、および74hc595を使用して電子サイコロを作成します。
ボタンが押されるたびに、1から6までのランダムな数字が生成され、7セグメントディスプレイに表示されます。

**必要な部品**

このプロジェクトには以下の部品が必要です。

一式を購入するのは確かに便利です、リンクはこちら：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクから部品を個別に購入することもできます。

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|

**回路図**

.. image:: img/circuit_8.9_eeprom.png

**配線図**

.. image:: img/wiring_electronic_dice.png
    :width: 800
    :align: center

**コード**

.. note::

    * ``3in1-kit\basic_project\6.2.electronic_dice`` のパスの下にある ``6.2.electronic_dice.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8d8ad340-b1de-4518-917b-caaf07e4baf4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、7セグメントディスプレイは0-7を高速でスクロールして表示し、ボタンを押すとランダムな数字が表示されてスクロールが停止します。ボタンを再度押すと、スクロール表示が再開されます。

**どのように動作するのか？**

このプロジェクトは :ref:`ar_segment` を基にしており、7セグメントディスプレイ上のスクロール表示を開始/一時停止するボタンが付いています。

1. 各ピンを初期化し、ボタンの値を読み取ります。

    .. code-block:: arduino

        void setup ()
        {

            ...
            attachInterrupt(digitalPinToInterrupt(buttonPin), rollDice, FALLING);
        }

    * ここで割り込みは、ボタンの状態を読むために使用されます。 ``buttonPin`` のデフォルト値は低く、ボタンが押されると低から高に変わります。
    * ``rollDice`` は割り込みがトリガされたときに呼び出される関数を表しており、変数 ``state`` の値をトグルするために使用されます。
    * ``FALLING`` は、 ``buttonPin`` が低から高に移行するときに割り込みがトリガされることを意味します。

2. 変数 ``state`` が0の場合、関数 ``showNumber()`` が呼び出され、7セグメントディスプレイが1から7までのランダムな数字を表示します。

    .. code-block:: arduino

        void loop()
        {
            if (state == 0) {
                showNumber((int)random(1, 7));
                delay(50);
            }
        }

3. ``rollDice()`` 関数について。

    .. code-block:: arduino

        void rollDice() {
            state = !state;
        }
    
    この関数が呼び出されると、stateの値をトグルします。例えば、前回が1で、今回が0です。

4. ``showNumber()`` 関数について。

    .. code-block:: arduino

        void showNumber(int num) {
            digitalWrite(STcp, LOW); //ST_CPを接地し、送信している間だけLowを保持する
            shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
            //ラッチ・ピンをハイ・レベルに戻し、チップにそれを知らせる
            //もはや情報をリッスンする必要はない
            digitalWrite(STcp, HIGH); //ST_CPST_CPをプルしてデータを保存する。
        }
    
    これはプロジェクト :ref:`ar_segment` の ``loop()`` 内のコードを関数 ``showNumber()`` に移したものです。
