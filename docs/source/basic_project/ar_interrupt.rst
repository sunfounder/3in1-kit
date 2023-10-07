.. _ar_interrupt:

5.13 割り込み
=======================

``delay()`` をセンサーを使用するプロジェクトで使用すると、これらのセンサーをトリガーするときに、プログラムが何の効果も持たない可能性があります。
これは、delay文がプログラムの一時停止を引き起こし、プログラムがセンサーからメイン制御ボードに送信される信号を取得できないためです。

この場合、割り込みを使用できます。割り込みを使用すると、プログラムがパルスを逃さないようになります。

この章では、アクティブブザーとボタンを使用して、割り込みの使用過程を体験します。

``loop()`` 関数では、 ``delay(1000)`` を使用して秒をカウントします。
ボタンを使ってブザーを制御する部分をISRに入れることで、delayの影響を受けずにタスクをスムーズに完了させることができます。

.. note::
    ISRは、他の関数にはない一部のユニークな制限を持つ特別な関数です。 ISRにはパラメータを持つことができず、何も返すべきではありません。
    一般的に、ISRはできるだけ短く、高速であるべきです。複数のISRを使用するスケッチの場合、一度に1つだけ実行でき、他の割り込みは、それらが持っている優先順位に基づいて、現在のものが終了した後に実行されます。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

キット全体を購入すると非常に便利です、リンクはこちら:

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_buzzer`
        - \-

**回路図**

.. image:: img/circuit_8.6_interval.png

**配線図**

.. image:: img/interrupt_bb.jpg
    :width: 600
    :align: center

**コード**

.. note::

    * ``3in1-kit\basic_project\5.13.interrupt`` のパスの下で ``5.13.interrupt.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    * または、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/6111757d-dd63-4c4c-95b5-9d96fb0843f0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、シリアルモニタをオンにして、毎秒自動でインクリメントされる数字が表示されます。ボタンを押すと、ブザーが鳴ります。
ボタンで制御されるブザー機能とタイミング機能は互いに競合しません。

**どのように動作するのか？**

* ``attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)``: 割り込みを追加します。

    **文法**
        attachInterrupt(digitalPinToInterrupt(pin), ISR, mode) 

    **パラメータ**
        * ``pin``: Arduinoのピン番号。実際のデジタルピンを特定の割り込み番号に変換するために、 ``digitalPinToInterrupt(pin)`` を使用する必要があります。例えば、ピン3に接続する場合、第一パラメータとしてその ``digitalPinToInterrupt(3)`` を使用します。
        * ``ISR``: 割り込みが発生したときに呼び出すISR。この関数はパラメータを取らず、何も返さない必要があります。この関数は、割り込みサービスルーチンとしても参照されることがあります。
        * ``mode``: 割り込みがトリガされるタイミングを定義します。有効な値として4つの定数が事前に定義されています：

          * ``LOW`` は、ピンが低い場合に割り込みをトリガします。
          * ``CHANGE`` は、ピンの値が変わるたびに割り込みをトリガします。
          * ``RISING`` は、ピンが低から高になったときにトリガします。
          * ``FALLING`` は、ピンが高から低になったときにトリガします。

.. note:: 
    異なるメイン制御ボードは割り込みピンを異なる方法で使用することができます。R3ボードでは、ピン2とピン3だけが割り込みを使用することができます。
