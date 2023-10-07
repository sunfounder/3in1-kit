.. _ar_servo:

5.5 内蔵ライブラリの使用
=======================================

Arduino IDEには、対応する ``.h`` ファイルを直接コードに追加することで、多数の内蔵ライブラリを使用することができます。

このプロジェクトでは ``Servo`` ライブラリを使用してサーボモータを駆動し、0°から180°の間で回転させることができます。

**必要な部品**

このプロジェクトで必要な部品は以下の通りです。

全てのキットを購入するのは確かに便利です。リンクは以下の通りです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

また、以下のリンクから部品を個別に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネントの紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|


**回路図**

.. image:: img/circuit_6.2_servo.png

このプロジェクトでは、PWMピン9を使用してサーボを駆動します。サーボのオレンジワイヤーをPWMピン9に、赤ワイヤーを5Vに、ブラウンワイヤーをGNDに接続します。

**配線図**

.. image:: img/swinging_servo_bb.jpg

**コード**

.. note::

    * ``3in1-kit\basic_project\5.5.use_internal_library`` のパスの下の ``5.5.use_internal_library.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    * あるいは、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ でコードをアップロードします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fa27db71-b191-4eda-b5c7-bbbe5f2652ca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードをR3ボードにアップロードすると、サーボアームが0°〜180°の範囲で回転するのを確認できます。

**どのように動作するのか？**

ライブラリ ``Servo.h`` を呼び出すことで、簡単にサーボを駆動することができます。

.. code-block:: arduino

    #include <Servo.h> 

ライブラリの関数：

.. code-block:: arduino

    Servo

サーボを制御するための **Servo** オブジェクトを作成。

.. code-block:: arduino

    uint8_t attach(int pin); 

``pinMode()`` を呼び出してピンをサーボドライバに変換し、失敗時に0を返す。

.. code-block:: arduino

    void detach();

サーボ駆動からピンを解放。

.. code-block:: arduino

    void write(int value); 

サーボの角度を度数で設定、0から180。

.. code-block:: arduino

    int read();

最後の ``write()`` で設定した値を返す。

.. code-block:: arduino

    bool attached(); 

サーボが現在接続されている場合は1を返す。
