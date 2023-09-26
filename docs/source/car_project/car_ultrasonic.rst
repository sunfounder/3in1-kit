.. _car_ultrasonic:

6. 超音波モジュールで遊ぼう
=====================================

:ref:`car_ir_obstacle` のプロジェクトでは、2つの赤外線障害物回避モジュールを使用して障害物を避けていますが、赤外線障害物回避モジュールの検出距離は短いため、車が障害物を避けるのが遅くなる可能性があります。

このプロジェクトでは、車が遠くの障害物を感知して判断を下すために、超音波モジュールを使用して長距離の検出を行います。

**必要な部品**

このプロジェクトには、以下の部品が必要です。

一式を購入すると非常に便利です。リンクはこちら：

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
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**配線図**

超音波センサーモジュールは、超音波を使用してオブジェクトまでの距離を測定する器具です。
2つのプローブがあります。一つは超音波を送信するためのもの、もう一つは送受信の時間を距離に変換し、装置と障害物との距離を検出するためのものです。

以下の図に従って回路を組み立ててください。

.. list-table:: 
    :header-rows: 1

    * - 超音波モジュール
      - R4ボード
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

.. image:: img/car_6.png
    :width: 800

**コード**

.. note::

    * ``3in1-kit\car_project\6.ultrasonic_module`` のパス下で ``6.ultrasonic_module.ino`` ファイルを開いてください。
    * または、このコードを **Arduino IDE** にコピーしてください。
    
    * あるいは、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を使用してコードをアップロードしてください。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/ae97f966-9d72-40e6-aa9f-e0767ddf5bd5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされたら、車を壁の方向に向けてください。距離が遠すぎる場合は前進し、近すぎる場合は後退し、安全な距離であれば停止します。


**どのように動作するのか？**

このプロジェクトは、超音波モジュールから読み取った距離に基づいて車を動かすものです。

#. 超音波モジュールのピン定義を追加します。 ``trigPin`` は超音波を送信するために使用されるため、 ``OUTPUT`` に設定します。 ``echoPin`` は超音波を受信するために ``INPUT`` に設定されます。

    .. code-block:: arduino

        ...
        const int trigPin = 3;
        const int echoPin = 4;

        void setup() {
        ...

        //超音波
            pinMode(echoPin, INPUT);
            pinMode(trigPin, OUTPUT);
        }

#. 超音波モジュールから得られた距離の値をまず読み取ります。距離が25より大きい場合、車を前進させます。距離が2-10cmの間であれば、車を後退させます。それ以外（10~25の間）の場合は、停止します。

    .. code-block:: arduino

        void loop() {
            float distance = readSensorData();
            if (distance > 25) {
                moveForward(200);
            }
            else if (distance < 10 && distance > 2) {
                moveBackward(200);
            } else {
                stopMove();
            }
        }

#. ``readSensorData()`` 関数について。

    超音波モジュールの送信機は、2usごとに10usの矩形波信号を送信し、受信機は範囲内に障害物がある場合に高レベルの信号を受信します。 ``pulseIn()`` 関数を使用して送信から受信までの時間を記録し、音速340m/sで割った後、2で割ります。その結果、このモジュールと障害物との間の距離（単位：cm）が得られます。

    .. code-block:: arduino

        float readSensorData() {
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);
            float distance = pulseIn(echoPin, HIGH) / 58.00; // (340m/s*1us)/2と同等
            return distance;
        }

* `pulseIn(pin, value) <https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/>`_

    * ``pin``: パルスを読み取りたいArduinoのピンの番号。許可されているデータ型：int。
    * ``value``: 読み取りたいパルスのタイプ：HIGHまたはLOW。許可されているデータ型：int。

    ピン上のパルス（HIGHまたはLOW）を読み取ります。たとえば、valueがHIGHの場合、 ``pulseIn()`` はピンがLOWからHIGHに変わるのを待ち、タイミングを開始し、ピンがLOWになるのを待ってタイミングを停止します。

