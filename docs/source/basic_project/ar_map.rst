.. _ar_map:

5.6 マッピング
===================

よく観察してみると、多くの値がプログラミングの中で異なる範囲を持っていることに気がつくでしょう。
例えば、アナログ入力の値範囲は(0~1023)です。
アナログ出力の値範囲は(0~255)です。
サーボの出力角度は(0~180)です。

これは、ポテンショメーターを使用してLEDの明るさやサーボの角度を制御したい場合、マッピング操作を行う必要があることを意味します。

では、それをどのように実現するのか見てみましょう。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

全体のキットを購入する方が便利です。以下がリンクです：

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**回路図**

.. image:: img/circuit_8.3_amp.png

**配線図**

.. image:: img/map_bb.jpg
    :width: 800
    :align: center

**コード**

.. note::

    * ``3in1-kit\basic_project\5.6.map`` のパスの下で ``5.6.map.ino`` ファイルを開きます。
    * またはこのコードを **Arduino IDE** にコピーします。
    
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ でコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f00e4c4c-fb13-4445-9d89-eb2857b5fe87/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードが正常にアップロードされた後、ポテンショメータを前後に回転させると、サーボの出力軸も前後に回転します。

**どのように動作するのか？**

``map(value, fromLow, fromHigh, toLow, toHigh)``: ある範囲の数字を別の範囲にマッピングします。
すなわち、fromLowの値はtoLowに、fromHighの値はtoHighにマッピングされます。

    **構文**
        map(value, fromLow, fromHigh, toLow, toHigh)

    **パラメータ**
        * ``value``: マッピングする数字。
        * ``fromLow``: 値の現在の範囲の下限。
        * ``fromHigh``: 値の現在の範囲の上限。
        * ``toLow``: 値の目標範囲の下限。
        * ``toHigh``: 値の目標範囲の上限。

ポテンショメーターでLEDを制御する場合、マップを使用してタスクを完了することもできます。

.. code-block:: arduino

    int x = analogRead(knob);
    int y = map(x,0,1023,0,255);
    analogWrite(led,y);

**注意と警告**

* 両方の範囲の"下限"は"上限"より大きくまたは小さい場合があります。これは、 ``map()`` 関数が数の範囲を逆転させるために使用できることを意味します。

  .. code-block:: arduino

    y = map(x,0,180,180,0);

* マッピングは負の数にも適用されます。

  .. code-block:: arduino

    y = map(x,0,1023,-90,90);

* マッピングは整数を使用し、浮動小数点の小数部は破棄されます。
