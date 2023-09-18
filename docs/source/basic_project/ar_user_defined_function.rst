.. _ar_ultrasonic:

5.8 ユーザー定義関数
======================================

C言語では、大きなプログラムを関数として知られる基本的な構築ブロックに分割することができます。
関数には、{}で囲まれた一連のプログラム文が含まれます。
関数は、Cプログラムに再利用性とモジュール性を提供するために、複数回呼び出すことができます。
言い換えれば、関数の集合がプログラムを構築すると言えます。
関数は、他のプログラミング言語で手続きやサブルーチンとしても知られています。

関数の以下のような利点があります。

* 関数を使用することで、同じロジック/コードをプログラム内で何度も書く必要がなくなります。
* Cの関数は、プログラム内の任意の場所から、任意の回数呼び出すことができます。
* 多数の関数に分割された大きなCプログラムは、追跡が容易です。
* 再利用性は、C関数の主要な成果です。
* ただし、関数の呼び出しは、Cプログラム内で常にオーバーヘッドとなります。

Cプログラミングには2種類の関数があります：

* **ライブラリ関数**：Cのヘッダーファイルで宣言されている関数。
* **ユーザー定義関数**：Cプログラマーが作成した関数で、何度も使用することができます。これにより、大きなプログラムの複雑さが軽減され、コードが最適化されます。

このプロジェクトでは、超音波モジュールの値を読む関数を定義します。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

一式を購入するのが便利です。購入リンクは以下の通りです：

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**回路図**

.. image:: img/circuit_6.3_ultrasonic.png

**配線図**

.. image:: img/ultrasonic_bb.jpg
    :width: 600
    :align: center

**コード**

.. note::

    * ``3in1-kit\basic_project\5.8.user_function`` のパスの下で ``5.8.user_function.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    * あるいは、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/11717782-3ee6-4eca-bbb9-094385d9eb4b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードが正常にアップロードされると、シリアルモニタは超音波センサと前方の障害物との間の距離を表示します。

**どのように動作するのか？**

超音波センサの使用方法については、サブ関数を直接確認できます。

.. code-block:: arduino

    float readSensorData(){// ...}

超音波モジュールの ``trigPin`` は、2usごとに10usの方形波信号を送信します。

.. code-block:: arduino

    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); 

``echoPin`` は、範囲内に障害物が存在する場合に高レベルの信号を受信し、 ``pulseIn()`` 関数を使用して送信から受信までの時間を記録します。

.. code-block:: arduino

    microsecond=pulseIn(echoPin, HIGH);

音の速度は、340 m/sまたは29マイクロ秒/センチメートルです。

これにより、方形波が往復する距離が得られるので、障害物の距離を得るために2で割ります。

.. code-block:: arduino

    float distance = microsecond / 29.00 / 2;  

超音波センサは動作中にプログラムを一時停止するので、複雑なプロジェクトを書いているときに若干の遅延が発生することがあります。

