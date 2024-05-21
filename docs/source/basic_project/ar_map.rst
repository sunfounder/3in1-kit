.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_map:

5.6 マップ
===================

もし注意深く観察すると、多くの値がプログラミング内で異なる範囲を持つことに気付くでしょう。
例えば、アナログ入力の値の範囲は(0~1023)です。
アナログ出力の値の範囲は(0~255)です。
サーボの出力角度は(0~180)です。

これは、ポテンショメータを使用してLEDの明るさやサーボの角度を制御したい場合、マッピング操作を行う必要があるということを意味しています。

それでは、どのようにこれを実現するか見てみましょう。

**必要な部品**

このプロジェクトで必要な部品は以下の通りです。

全体のキットを購入すると非常に便利です。以下はリンクです：

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**回路図**

.. image:: img/circuit_8.3_amp.png

**配線図**

.. image:: img/5.6_map_bb.png
    :width: 800
    :align: center

**コード**

.. note::

    * ``3in1-kit\learning_project\5.6.map`` のパスの下の ``5.6.map.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。

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
        * ``toLow``: 値の目的範囲の下限。
        * ``toHigh``: 値の目的範囲の上限。

ポテンショメータでLEDを制御する場合、マップを使用してタスクを完了することもできます。

.. code-block:: arduino

    int x = analogRead(knob);
    int y = map(x,0,1023,0,255);
    analogWrite(led,y);

**注意事項と警告**

* 両方の範囲の"下限"は"上限"より大きくまたは小さくなる場合があり、これは ``map()`` 関数を使用して数字の範囲を逆転させることができることを意味します。

  .. code-block:: arduino

    y = map(x,0,180,180,0);

* マッピングは負の数に対しても適切に動作します。

  .. code-block:: arduino

    y = map(x,0,1023,-90,90);

* マッピングは整数を使用し、浮動小数点の小数部は破棄されます。
