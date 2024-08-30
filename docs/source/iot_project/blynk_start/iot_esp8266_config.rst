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

1.0 ESP8266の設定
===============================

キットに含まれるESP8266モジュールはすでにATファームウェアで事前に書き込まれていますが、以下の手順に従ってその設定を変更する必要があります。

1. 回路を組む。

    .. image:: img/iot_1.1_at_set_bb.png
        :width: 600
        :align: center

2. ``3in1-kit\iot_project\1.set_software_serial`` のパスの下の ``1.set_software_serial.ino`` ファイルを開く。または、このコードを **Arduino IDE** にコピーします。

    .. code-block:: Arduino

        #include <SoftwareSerial.h>
        SoftwareSerial espSerial(2, 3); //Rx,Tx

        void setup() {
            // セットアップ コードをここに配置して、1 回実行します。
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

3. 右上隅の虫眼鏡のアイコン（シリアルモニター）をクリックして、ボーレートを **115200** に設定します。（私のように何か情報が表示されるかもしれませんし、表示されないかもしれませんが、問題ありません。次の手順に進んでください。）

    .. image:: img/sp20220524113020.png

    .. warning::
        
        * ``ready`` が表示されない場合、ESP8266モジュールをリセットして（RSTをGNDに接続）シリアルモニターを再度開くことができます。

        * さらに、結果が ``OK`` の場合、ファームウェアを再度書き込む必要があるかもしれません。詳細については :ref:`burn_firmware` を参照してください。それでも解決できない場合は、シリアルモニターのスクリーンショットを sevice@sunfounder.com に送信してください。できるだけ早く問題を解決するお手伝いをいたします。

4. **NEWLINE DROPDOWN BOX** をクリックして、ドロップダウンオプションで ``both NL & CR`` を選択し、 ``AT`` を入力します。OKと返されると、ESP8266がボードとの接続に成功したことを意味します。

    .. image:: img/sp20220524113702.png

5. ``AT+CWMODE=3`` を入力すると、管理モードが **Station and AP** の共存に変更されます。

    .. image:: img/sp20220524114032.png

6. 後でソフトウェアシリアルを使用するために、 ``AT+UART=9600,8,1,0,0`` を入力して、ESP8266のボーレートを9600に変更する必要があります。

    .. image:: img/PIC4_sp220615_150321.png

.. 7. 今、シリアルモニターのボーレートを9600に変更し、``AT`` を入力してみてください。OKが返されると、設定が成功したことを意味します。

..     .. image:: img/PIC5_sp220615_150431.png

