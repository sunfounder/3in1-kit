.. _ar_ultrasonic:

5.8 ユーザー定義関数
======================================

C言語では、関数として知られる基本的な構造ブロックに大きなプログラムを分割することができます。
関数には{}で囲まれた一連のプログラム文が含まれています。
関数は、Cプログラムに再利用性とモジュール性を提供するために、複数回呼び出すことができます。
言い換えれば、関数の集合がプログラムを作成すると言えます。
関数は、他のプログラミング言語では手続きやサブルーチンとしても知られています。

関数には以下のような利点があります。

* 関数を使用することで、プログラム内で同じロジック/コードを何度も書き直すことを避けることができます。
* Cの関数は、プログラム内の任意の場所から何度でも呼び出すことができます。
* 複数の関数に分割された大きなCプログラムは、追跡しやすくなります。
* 再利用性は、C関数の主な達成です。
* ただし、関数の呼び出しは、Cプログラムにおいて常にオーバーヘッドとなります。

Cプログラミングには2種類の関数があります：

* **ライブラリ関数**：Cのヘッダーファイルで宣言されている関数。
* **ユーザー定義関数**：Cプログラマによって作成され、何度も使用できるようにされた関数。これにより、大きなプログラムの複雑さが減少し、コードが最適化されます。

このプロジェクトでは、超音波モジュールの値を読み取る関数を定義します。

**必要な部品**

このプロジェクトでは、以下のコンポーネントが必要です。

キット全体を購入するのは非常に便利です、こちらがリンクです：

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|


**回路図**

.. image:: img/circuit_6.3_ultrasonic.png

**配線図**

.. image:: img/5.8_ultrasonic_bb.png
    :width: 600
    :align: center

**コード**

.. note::

    * ``3in1-kit\learning_project\5.8.user_function`` のパスの下にある ``5.8.user_function.ino`` ファイルを開いてください。
    * または、このコードを **Arduino IDE** にコピーしてください。
    
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/11717782-3ee6-4eca-bbb9-094385d9eb4b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

コードが正常にアップロードされた後、シリアルモニターは超音波センサと前方の障害物との距離を表示します。

**どのように動作するのか？**

超音波センサの利用については、サブファンクションを直接確認できます。

.. code-block:: arduino

    float readSensorData(){// ...}

超音波モジュールの ``trigPin`` は、2usごとに10usの正方波信号を送信します。

.. code-block:: arduino

    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); 


範囲内に障害物がある場合、 ``echoPin`` は高レベルの信号を受信し、 ``pulseIn()`` 関数を使用して送信から受信までの時間を記録します。

.. code-block:: arduino

    microsecond=pulseIn(echoPin, HIGH);

音の速度は、340 m/s または 1cmあたり29マイクロ秒です。

これにより、正方波が移動した距離、外向きと帰還、が得られるので、
障害物の距離を取得するために2で割ります。

.. code-block:: arduino

    float distance = microsecond / 29.00 / 2;  

超音波センサは動作しているときにプログラムを一時停止するため、複雑なプロジェクトを書いているときにラグが発生することがあります。

