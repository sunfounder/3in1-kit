.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _burn_firmware:

ESP8266モジュールのファームウェアの再書き込み方法は？
=====================================================

R4でファームウェアを再書き込む
---------------------------------------

**1. 回路を組む**

ESP8266とArduino UNO R4ボードを接続します。

    .. image:: img/faq_at_burn_bb.jpg
        :width: 800

**2. R4に次のコードをアップロード**

.. code-block:: Arduino

    void setup() {
        Serial.begin(115200);       
        Serial1.begin(115200);      
    }

    void loop() {
        if (Serial.available()) {           // シリアル (USB) に何かが入った場合、
            Serial1.write(Serial.read());   // それを読み取って送信します Serial1 (ピン 0 と 1)
        }
        if (Serial1.available()) {          // Serial1 (ピン 0 と 1) に何かが入った場合
            Serial.write(Serial1.read());   // 読み取って送信 シリアル (USB)
        }
    }

**3. ファームウェアの書き込み**

* **Windows** を使用している場合、以下の手順でファームウェアを書き込んでください。

    #. ファームウェアと書き込みツールをダウンロードする。

        * :download:`ESP8266 ファームウェア <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. 解凍すると、4つのファイルが表示されます。

        .. .. image:: img/bat_firmware.png
    
        * ``BAT_AT_V1.7.1.0_1M.bin``: ESP8266モジュールに書き込むファームウェア。
        * ``esptool.exe``: Windows用のコマンドラインユーティリティです。
        * ``install_r3.bat``: Windowsシステム用のコマンドパッケージ、このファイルをダブルクリックすると、ファイル内のすべてのコマンドが実行されます。
        * ``install_r4.bat``: ``install_r3.bat`` と同様ですが、UNO R4ボード専用です。

    #. ``install_r4.bat`` をダブルクリックして、ファームウェアの書き込みを開始します。以下のプロンプトが表示される場合、ファームウェアは正常にインストールされました。

        .. image:: img/install_firmware.png

        .. note::
            書き込みに失敗した場合、以下の点を確認してください。

            * ESP8266モジュールをリセットします（ESP8266アダプタのRSTをGNDに差し込み、それを抜く）。
            * 配線が正しいか確認してください。
            * コンピュータがボードを正しく認識しているか、ポートが占有されていないことを確認してください。
            * install.batファイルを再度開きます。

* **Mac OS** を使用している場合、以下の手順でファームウェアを書き込んでください。

    #. Esptoolをインストールするための以下のコマンドを使用します。EsptoolはPythonベースで、オープンソースの、Espressifチップ内のROMブートローダと通信するためのプラットフォーム非依存のユーティリティです。

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. esptoolが正しくインストールされていれば、 ``python3 -m esptool`` を実行すると[usage: esptool]というメッセージが出力されます。

    #. ファームウェアをダウンロードします。

        * :download:`ESP8266 ファームウェア <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. 解凍すると、4つのファイルが表示されます。

        .. .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: ESP8266モジュールに書き込むファームウェア。
        * ``esptool.exe``: Windows用のコマンドラインユーティリティです。
        * ``install_r3.bat``: Windowsシステム用のコマンドパッケージ。
        * ``install_r4.bat``: ``install_r3.bat`` と同様ですが、UNO R4ボード専用です。

    #. ターミナルを開き、 ``cd`` コマンドを使ってダウンロードしたファームウェア・フォルダーに入り、以下のコマンドを実行して既存のファームウェアを消去し、新しいファームウェアを焼き直す。

        .. code-block::

            python3 -m esptool --chip esp8266 --before no_reset_no_sync erase_flash
            python3 -m esptool --chip esp8266 --before no_reset_no_sync write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. 以下のプロンプトが表示される場合、ファームウェアは正常にインストールされました。

        .. image:: img/install_firmware_macos.png

        .. note::
            書き込みに失敗した場合、以下の点を確認してください。

            * ESP8266モジュールをリセットします（ESP8266アダプタのRSTをGNDに差し込み、それを抜く）。
            * 配線が正しいか確認してください。
            * コンピュータがボードを正しく認識しているか、ポートが占有されていないことを確認してください。
            * install.batファイルを再度開きます。

**4. テスト**

#. 元の配線のまま、IO1を3V3に接続します。

    .. image:: img/faq_at_burn_check_bb.jpg
        :width: 800

#. 右上の虫眼鏡アイコン（シリアルモニタ）をクリックし、ボーレートを **115200** に設定すると、ESP8266モジュールの情報が表示されます。

    .. image:: img/sp20220524113020.png

    .. note::

        * ``ready`` が表示されない場合、ESP8266モジュールをリセットして（RSTをGNDに接続）シリアルモニタを再度開くと良いでしょう。

#. **NEWLINE DROPDOWN BOX** をクリックし、ドロップダウンオプションで ``both NL & CR`` を選択し、 ``AT`` を入力します。OKが返される場合、ESP8266がボードと正常に接続されたことを意味します。

    .. image:: img/sp20220524113702.png

これで、 :ref:`config_esp8266` に従って、ESP8266モジュールの動作モードやボーレートを設定することができます。




R3でファームウェアを再書き込む
---------------------------------------

**1. 回路を作成する**

ESP8266とSunFounder R3ボードを接続します。

    .. image:: img/connect_esp8266.png
        :width: 800

**2. ファームウェアの書き込み**

* **Windows** を使用している場合、以下の手順に従ってファームウェアを書き込んでください。

    #. ファームウェアと書き込みツールをダウンロードします。

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. 解凍すると、4つのファイルが表示されます。

        .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: ESP8266モジュールに書き込むファームウェアです。
        * ``esptool.exe``: Windows用のコマンドラインユーティリティです。
        * ``install_r3.bat``: Windowsシステム用のコマンドパッケージで、このファイルをダブルクリックすると、ファイル内のすべてのコマンドが実行されます。
        * ``install_r4.bat``: ``install_r3.bat`` と同じですが、UNO R4ボード専用です。

    #. ``install_r3.bat`` をダブルクリックしてファームウェアの書き込みを開始します。次のプロンプトが表示されれば、ファームウェアが正常にインストールされました。

        .. image:: img/install_firmware.png

        .. note::
            書き込みが失敗した場合は、以下の点を確認してください。

            * ESP8266アダプタのRSTをGNDに挿入し、それを抜くことでESP8266モジュールをリセットします。
            * 配線が正しいか確認します。
            * コンピュータがボードを正しく認識しているか、そしてポートが占有されていないことを確認します。
            * install.batファイルを再度開きます。

* **Mac OS** システムを使用している場合、以下の手順に従ってファームウェアを書き込んでください。

    #. Esptoolをインストールするための次のコマンドを使用します。Esptoolは、EspressifチップのROMブートローダーと通信するためのPythonベースのオープンソースのプラットフォームに依存しないユーティリティです。

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. esptoolが正しくインストールされていれば、 ``python3 -m esptool`` を実行すると[usage: esptool]というメッセージが出力されます。

    #. ファームウェアをダウンロードします。

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. 解凍すると、3つのファイルが表示されます。

        .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: ESP8266モジュールに書き込むファームウェアです。
        * ``esptool.exe``: Windows用のコマンドラインユーティリティです。
        * ``install_r3.bat``: Windowsシステム用のコマンドパッケージです。
        * ``install_r4.bat``: ``install_r3.bat`` と同じですが、UNO R4ボード専用です。

    #. ターミナルを開き、先ほどダウンロードしたファームウェアのフォルダに ``cd`` コマンドを使用して移動します。次に、既存のファームウェアを消去し、新しいファームウェアを再書き込むための次のコマンドを実行します。

        .. code-block::

            python3 -m esptool --chip esp8266 --before default_reset erase_flash
            python3 -m esptool --chip esp8266 --before default_reset write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. 次のプロンプトが表示されれば、ファームウェアが正常にインストールされました。

        .. image:: img/install_firmware_macos.png

        .. note::
            書き込みが失敗した場合は、以下の点を確認してください。

            * ESP8266アダプタのRSTをGNDに挿入し、それを抜くことでESP8266モジュールをリセットします。
            * 配線が正しいか確認します。
            * コンピュータがボードを正しく認識しているか、そしてポートが占有されていないことを確認します。
            * install.batファイルを再度開きます。

**3. テスト**

#. 元の配線の基礎の上で、IO1を3V3に接続します。

    .. image:: img/connect_esp826612.png
        :width: 800

#. 右上隅の虫眼鏡アイコン（シリアルモニタ）をクリックし、ボーレートを **115200** に設定すると、ESP8266モジュールに関する情報が表示されます。

    .. image:: img/sp20220524113020.png

    .. note::

        * ``ready`` が表示されない場合は、ESP8266モジュールをリセット（RSTをGNDに接続）して、シリアルモニタを再度開きます。

#. **NEWLINE DROPDOWN BOX** をクリックし、ドロップダウンオプションで ``both NL & CR`` を選択し、 ``AT`` と入力します。OKが返されれば、ESP8266がR3ボードと正常に接続されていることを意味します。

    .. image:: img/sp20220524113702.png

次に、 :ref:`config_esp8266` に従って、ESP8266モジュールの動作モードとボーレートを設定できます。
