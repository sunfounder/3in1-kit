.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _config_esp8266:

1.1 ESP8266の設定
===============================

このキットに同梱されているESP8266モジュールはすでにATファームウェアで書き込み済みですが、以下の手順に従って設定を変更する必要があります。


1. 回路を組み立てる。

    .. image:: img/iot_1_at_set_bb.jpg
        :width: 800

2. ``3in1-kit\iot_project\1.set_software_serial`` のパスの下にある ``1.set_software_serial.ino`` ファイルを開くか、このコードを **Arduino IDE** にコピーします。

    .. code-block:: Arduino

        #include <SoftwareSerial.h>
        SoftwareSerial espSerial(2, 3); //Rx,Tx

        void setup() {
            // セットアップコードをここに書いて、一度だけ実行する：
            Serial.begin(115200);
            espSerial.begin(115200);
        }

        void loop() {
            if (espSerial.available()) {
                Serial.write(espSerial.read());
            }
            if (Serial.available()) {
                espSerial.write(Serial.read());
            }
        }


3. 右上の虫眼鏡アイコン（シリアルモニタ）をクリックし、ボーレートを **115200** に設定します。(私のようにいくつかの情報が表示されるか、表示されない場合もありますが、問題ありません。次のステップに進んでください。)

    .. image:: img/sp20220524113020.png

    .. warning::
        
        * ``ready`` が表示されない場合は、ESP8266モジュールをリセットして（RSTをGNDに接続）シリアルモニタを再度開いてみてください。

        * さらに、結果が ``OK`` の場合、ファームウェアを再書き込みする必要があるかもしれません。詳しくは :ref:`burn_firmware` を参照してください。それでも解決しない場合は、シリアルモニタのスクリーンショットを sevice@sunfounder.com に送信してください。可能な限り早く問題を解決するお手伝いをします。

4. **NEWLINE DROPDOWN BOX** をクリックし、ドロップダウンオプションで ``both NL & CR`` を選択し、 ``AT`` を入力します。OKが返ってくれば、ESP8266がR3ボードと正常に接続されていることを意味します。

    .. image:: img/sp20220524113702.png

5. ``AT+CWMODE=3`` を入力すると、管理モードが **Station and AP** 共存に変更されます。

    .. image:: img/sp20220524114032.png

6. 後でソフトウェアシリアルを使用するために、ESP8266のボーレートを9600に変更するため ``AT+UART=9600,8,1,0,0`` を入力する必要があります。

    .. image:: img/PIC4_sp220615_150321.png

.. 7. Now change the serial monitor baud rate to 9600, try to enter ``AT``, if it returns OK, it means the setting is successful.


..     .. image:: img/PIC5_sp220615_150431.png

