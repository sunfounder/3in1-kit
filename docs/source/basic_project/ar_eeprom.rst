.. _ar_74hc_7seg:

5.15 EEPROM
==============

`EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ はメモリであり、メインコントロールボードをオフにしてもそのデータは消去されません。これを使用してデータを記録し、次回電源を入れたときにそれを読み取ることができます。

例として、毎日のロープスキップの回数を追跡するスポーツカウンターを作成することができます。

また、あるプログラムでデータを書き込み、別のプログラムでそれを読み取ることもできます。例えば、車のプロジェクトで作業しているとき、2つのモーターの速度が一致しない場合、モーター速度の補正値を記録するキャリブレーションプログラムを書くことができます。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

全てを含むキットを購入すると非常に便利です、こちらのリンクから購入できます：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

下記のリンクから別々に購入することも可能です。

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**回路図**

.. image:: img/circuit_515_eeprom.png

**配線図**

.. image:: img/eeprom_servo.png

**コード**


.. note::

    * ``3in1-kit\basic_project\5.15.eeproom`` のパスの下で ``5.15.eeproom.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    
    * あるいは、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7378341f-9c1a-4171-814f-c76c109e1e67/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

この回路を使用するには、ボタンを押して記録を開始し、ポテンショメータを通じて所望の情報を入力するだけです。現在、ボードはあなたの操作を無限に繰り返します（そして、各反復ごとにLEDが点滅します）。新しい操作を記録するためにボタンを再度押すまでです。resolutionとrecordTimeの値を変更することで、記録される時間を変更することもできます。



**どのように動作しますか？**

#. ``EEPROM.h`` ライブラリをインポートし、EEPROMメモリを初期化します。

    .. code-block:: arduino

        ...
        #include <EEPROM.h>//記録した値を保存するために使用

        ...
        float resolution = 1000;//EEPROM.length() より小さくなければならない
        float recordTime = 5; //遅延時間
        bool recording = false;
        ...
    
    ``/EEPROM.length() より小さくなければならない`` に注意してください。 ``setup()`` で、ボードのEEPROMのメモリがSunFounder R3ボードの場合は1024と表示されます。別のボードを使用している場合は、変数 ``resolution`` の値を変更できます。

#. ボードのEEPROMメモリを印刷します。

    .. code-block:: arduino

        void setup() {
            ...
            Serial.begin(9600);
            //Serial.println(EEPROM.length());
        }

    ボードのEEPROMメモリのサイズを知るには、 ``Serial.println(EEPROM.read(i))`` の行のコメントを解除してください。これにより、シリアルモニタにEEPROMのサイズが表示され、変数 ``resolution`` の値をそれに応じて変更できます。

#. ボタンが押されたことを検出すると、すぐに記録が開始され、ポテンショメータを使用して必要な情報が入力されます。その後、ボードはあなたのアクションを無限に繰り返します（各反復でLEDが点滅します）。新しいアクションを記録するために再度ボタンを押すまでです。

    .. code-block:: arduino

        void loop() {
            if (recording == true) {//記録
                for (int i = 1; i <= resolution; i++) {
                    digitalWrite(ledPin, HIGH); //状態LEDの点灯
                    int val = map(analogRead(A0), 0, 1023, 0, 180);
                    EEPROM.write(i, val);
                    //Serial.println(EEPROM.read(i));
                    myServo.write(val);
                    delay(recordTime);
                }
                digitalWrite(ledPin, LOW); //状態LEDをオフ
                delay(1000);//人のための時間を与える
                recording = false;
            }
            else {
                for (int i = 1; i <= resolution; i++) {//再生
                    if (digitalRead(buttonPin) == 0) {//再生を停止し、新しい値を記録
                        recording = true;
                        break;
                    }
                    int readval = EEPROM.read(i);
                    myServo.write(readval);
                    //Serial.println(readval);
                    delay(recordTime);
                }
                digitalWrite(ledPin, HIGH); //新しい繰り返しを示す
                delay(100);
                digitalWrite(ledPin, LOW);
            }
        }

    * ボタンが押されたときに変数 ``recording`` をtrueにします。
    * 変数 ``recording`` がtrueの場合、メモリ範囲にアクションの記録を開始します。
    * ポテンショメータの値を読み取り、0-180にマッピングしてEEPROMに保存し、サーボの回転を制御します。
    * LEDは、記録の開始時に点灯し、終了時に消灯します。
    * LEDの速い点滅で記録されたアクションを繰り返し、新しい繰り返しのリマインダとして機能します。

#. ``EEPROM`` ライブラリについて。

    以下は、その関数の一部です。
        
    * ``write(address,value)``: EEPROMにバイトを書き込みます。

        * ``address``: 書き込む場所、0から始まる (int)
        * ``value``: 書き込む値、0から255まで (byte)
        * EEPROMへの書き込みは3.3msで完了します。EEPROMメモリは、100,000回の書き込み/消去サイクルの寿命が指定されているため、頻繁に書き込む場合は注意が必要です。

    * ``Read(address)``: EEPROMからバイトを読み取ります。書き込まれていない場所の値は255です。

    * ``update(address,value)``: EEPROMにバイトを書き込みます。値は、同じアドレスにすでに保存されているものと異なる場合のみ書き込まれます。

        * EEPROMへの書き込みは3.3msで完了します。EEPROMメモリは、100,000回の書き込み/消去サイクルの寿命が指定されているため、書き込むデータが頻繁に変更されない場合は、write()の代わりにこの関数を使用してサイクルを節約できます。

    * ``EEPROM.put(address, data)``: 任意のデータタイプやオブジェクトをEEPROMに書き込みます。

        * ``address``: 読み取る場所、0から始まる (int)。
        * ``data``: 読み取るデータ、プリミティブタイプ（例：float）やカスタム構造体。
        * この関数はEEPROM.update()を使用して書き込みを実行するため、値が変更されていない場合は再書き込みしません。

    * ``EEPROM.get(address, data)``: EEPROMから任意のデータタイプやオブジェクトを読み取ります。

        * ``address``: 読み取る場所、0から始まる (int)。
        * ``data``: 読み取るデータ、プリミティブタイプ（例：float）やカスタム構造体。



