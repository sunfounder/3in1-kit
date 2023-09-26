.. _ar_eeprom:

6.2 デジタルサイコロ
=============================

このプロジェクトでは、ボタン、7セグメント表示、および74hc595を使用して電子サイコロを作成します。
ボタンを押すたびに、1から6までのランダムな数字が生成され、7セグメント表示に表示されます。

**必要な部品**

このプロジェクトで必要な部品は以下のとおりです。

一式を購入するのは確かに便利です。リンクはこちら:

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|

**回路図**

.. image:: img/circuit_8.9_eeprom.png

**配線図**

.. image:: img/6.2_electronic_dice_bb.png
    :width: 800
    :align: center

**コード**

.. note::

    * ``3in1-kit\learning_project\6.2.electronic_dice`` のパスの下の ``6.2.electronic_dice.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーしてください。

    
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8d8ad340-b1de-4518-917b-caaf07e4baf4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、7セグメント表示は0-7を高速でスクロールして表示しますが、ボタンを押すとランダムな数字を表示し、スクロールが停止します。再びボタンを押すと、スクロール表示が再開されます。

**どのように動作するのか？**

このプロジェクトは、 :ref:`ar_segment` をベースに、ボタンを使用して7セグメント表示のスクロール表示を開始/一時停止します。

#. 各ピンを初期化し、ボタンの値を読み取ります。

    .. code-block:: arduino

        void setup ()
        {
            ...
            attachInterrupt(digitalPinToInterrupt(buttonPin), rollDice, FALLING);
        }

    * ここでは割り込みを使用してボタンの状態を読み取ります。 ``buttonPin`` のデフォルト値は低いですが、ボタンを押すと低から高に変わります。
    * ``rollDice`` は割り込みがトリガーされたときに呼び出される関数を表し、変数 ``state`` の値を切り替えるために使用されます。
    * ``FALLING`` は、 ``buttonPin`` が低から高になったときに割り込みがトリガーされることを意味します。

#. 変数 ``state`` が0の場合、関数 ``showNumber()`` が呼び出されて、7セグメント表示が1から7の間でランダムに数字を表示するようになります。

    .. code-block:: arduino

        void loop()
        {
            if (state == 0) {
                showNumber((int)random(1, 7));
                delay(50);
            }
        }

#. ``rollDice()`` 関数について。

    .. code-block:: arduino

        void rollDice() {
            state = !state;
        }
    
    この関数が呼び出されると、stateの値が切り替わります。前回が1で、今回が0の場合など。

#. ``showNumber()`` 関数について。

    .. code-block:: arduino

        void showNumber(int num) {
            digitalWrite(STcp, LOW); //ST_CPをGNDに接続し、送信中は常に低く保持
            shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
            // ラッチ ピンを High に戻してチップに信号を送ります
            // 情報を聞く必要がなくなりました
            digitalWrite(STcp, HIGH); //ST_CPST_CPを上げてデータを保存
        }
    
    これは、プロジェクト :ref:`ar_segment` の ``loop()`` 内のコードを関数 ``showNumber()`` に入れたものです。
