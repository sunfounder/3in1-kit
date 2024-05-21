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

ESP8266モジュールのファームウェアを再書き込みする方法は?
========================================================

R3でのファームウェアの再書き込み
---------------------------------------

**1. 回路の作成**

ESP8266とSunFounder R3ボードを接続します。

    .. image:: img/connect_esp8266.png
        :width: 800

**2. ファームウェアの書き込み**

* **Windows** を使用している場合、以下の手順でファームウェアを書き込んでください。

    #. ファームウェアと書き込みツールをダウンロードします。

        * :download:`ESP8266 ファームウェア <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. 展開すると、4つのファイルが表示されます。

        .. .. image:: img/bat_firmware.png
    
        * ``BAT_AT_V1.7.1.0_1M.bin``: ESP8266モジュールに書き込むファームウェア。
        * ``esptool.exe``: Windows用のコマンドラインユーティリティ。
        * ``install_r3.bat``: Windowsシステム用のコマンドパッケージ。このファイルをダブルクリックすると、ファイル内のすべてのコマンドが実行されます。
        * ``install_r4.bat``: ``install_r3.bat`` と同じですが、UNO R4ボード専用です。

    #. ``install_r3.bat`` をダブルクリックしてファームウェアの書き込みを開始します。以下のプロンプトが表示されたら、ファームウェアが正常にインストールされたことを示します。

        .. image:: img/install_firmware.png

        .. note::
            書き込みに失敗した場合は、以下の点を確認してください。

            * ESP8266アダプターのRSTをGNDに挿入してから抜き、ESP8266モジュールをリセットします。
            * 配線が正しいか確認してください。
            * コンピュータがボードを正しく認識しているか、またポートが占有されていないことを確認してください。
            * install.batファイルを再度開いてください。

* **Mac OS** を使用している場合、以下の手順でファームウェアを書き込んでください。

    #. Esptoolをインストールするには、以下のコマンドを使用します。EsptoolはEspressifチップのROMブートローダーと通信するためのPythonベースのオープンソース、プラットフォーム独立のユーティリティです。

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. esptoolが正しくインストールされていれば、 ``python3 -m esptool`` を実行すると[usage: esptool]のようなメッセージが出力されます。

    #. ファームウェアをダウンロードします。

        * :download:`ESP8266 ファームウェア <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. 展開すると、3つのファイルが表示されます。

        .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: ESP8266モジュールに書き込むファームウェア。
        * ``esptool.exe``: Windows用のコマンドラインユーティリティ。
        * ``install_r3.bat``: Windowsシステム用のコマンドパッケージ。
        * ``install_r4.bat``: ``install_r3.bat`` と同じですが、UNO R4ボード専用です。

    #. ターミナルを開き、 ``cd`` コマンドを使用してダウンロードしたファームウェアのフォルダに移動し、次のコマンドを実行して既存のファームウェアを消去し、新しいファームウェアを再書き込みします。

        .. code-block::

            python3 -m esptool --chip esp8266 --before default_reset erase_flash
            python3 -m esptool --chip esp8266 --before default_reset write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. 以下のプロンプトが表示されたら、ファームウェアが正常にインストールされたことを示します。

        .. image:: img/install_firmware_macos.png

        .. note::
            書き込みに失敗した場合は、以下の点を確認してください。

            * ESP8266アダプターのRSTをGNDに挿入してから抜き、ESP8266モジュールをリセットします。
            * 配線が正しいか確認してください。
            * コンピュータがボードを正しく認識しているか、またポートが占有されていないことを確認してください。
            * install.batファイルを再度開いてください。

**3. テスト**

#. 元の配線の基盤上で、IO1を3V3に接続します。

    .. image:: img/connect_esp826612.png
        :width: 800

#. 右上の虫眼鏡アイコン（シリアルモニタ）をクリックし、ボーレートを **115200** に設定すると、ESP8266モジュールに関する情報が表示されます。

    .. image:: img/sp20220524113020.png

    .. note::

        * ``ready`` が表示されない場合は、ESP8266モジュールをリセットして（RSTをGNDに接続）、シリアルモニタを再度開いてみてください。

#. **NEWLINE DROPDOWN BOX** をクリックし、ドロップダウンオプションで ``both NL & CR`` を選択し、 ``AT`` を入力します。OKが返された場合、ESP8266がR3ボードと正常に接続されていることを示します。

    .. image:: img/sp20220524113702.png

次に、 :ref:`config_esp8266` に従って、ESP8266モジュールの動作モードとボーレートを設定することができます。




R4でファームウェアを再書き込み
---------------------------------------

**1. 回路を作成する**

ESP8266とArduino UNO R4ボードを接続します。

    .. image:: img/faq_at_burn_bb.jpg
        :width: 800

**2. R4に以下のコードをアップロードする**

.. code-block:: Arduino

    void setup() {
        Serial.begin(115200);
        Serial1.begin(115200);
    }

    void loop() {
        if (Serial.available()) {      // シリアル（USB）から何かが入力された場合
            Serial1.write(Serial.read());   // それを読み取り、Serial1（ピン0 & 1）で送信する
        }
        if (Serial1.available()) {     // Serial1（ピン0 & 1）から何かが入力された場合
            Serial.write(Serial1.read());   // それを読み取り、シリアル（USB）で送信する
        }
    }

**3. ファームウェアの書き込み**

* **Windows** を使用している場合は、以下の手順でファームウェアを書き込む方法に従ってください。

    #. ファームウェアと書き込みツールをダウンロードします。

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. 解凍すると、4つのファイルが表示されます。

        .. .. image:: img/bat_firmware.png
    
        * ``BAT_AT_V1.7.1.0_1M.bin``: ESP8266モジュールに書き込むファームウェア。
        * ``esptool.exe``: Windows用のコマンドラインユーティリティ。
        * ``install_r3.bat``: Windowsシステム用のコマンドパッケージ。このファイルをダブルクリックすると、ファイル内のすべてのコマンドが実行されます。
        * ``install_r4.bat``: ``install_r3.bat`` と同じですが、UNO R4ボード専用です。

    #. ``install_r4.bat`` をダブルクリックしてファームウェアの書き込みを開始します。以下のプロンプトが表示されたら、ファームウェアが正常にインストールされました。

        .. image:: img/install_firmware.png

        .. note::
            書き込みに失敗した場合は、以下の点を確認してください。

            * ESP8266 AdapterのRSTをGNDに挿入してから取り外すことで、ESP8266モジュールをリセットします。
            * 配線が正しいか確認してください。
            * コンピュータがボードを正しく認識しているか、およびポートが占有されていないか確認してください。
            * install.batファイルを再度開きます。


* **Mac OS** システムを使用している場合、以下の手順に従ってファームウェアを書き込む方法に従ってください。

    #. Esptoolをインストールするには、以下のコマンドを使用します。EsptoolはPythonベースのオープンソース、プラットフォームに依存しないユーティリティで、EspressifチップのROMブートローダーと通信します。

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. esptoolが正しくインストールされている場合、 ``python3 -m esptool`` を実行すると[usage: esptool]というメッセージが出力されます。

    #. ファームウェアをダウンロードします。

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. 解凍すると、4つのファイルが表示されます。

        .. .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: ESP8266モジュールに書き込むファームウェア。
        * ``esptool.exe``: Windows用のコマンドラインユーティリティ。
        * ``install_r3.bat``: Windowsシステム用のコマンドパッケージ。
        * ``install_r4.bat``: ``install_r3.bat`` と同じですが、UNO R4ボード専用です。

    #. ターミナルを開き、ダウンロードしたファームウェアのフォルダに移動するために ``cd`` コマンドを使用します。その後、以下のコマンドを実行して既存のファームウェアを消去し、新しいファームウェアを再書き込みします。

        .. code-block::

            python3 -m esptool --chip esp8266 --before no_reset_no_sync erase_flash
            python3 -m esptool --chip esp8266 --before no_reset_no_sync write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. 以下のプロンプトが表示されたら、ファームウェアが正常にインストールされました。

        .. image:: img/install_firmware_macos.png

        .. note::
            書き込みに失敗した場合は、以下の点を確認してください。

            * ESP8266 AdapterのRSTをGNDに挿入してから取り外すことで、ESP8266モジュールをリセットします。
            * 配線が正しいか確認してください。
            * コンピュータがボードを正しく認識しているか、およびポートが占有されていないか確認してください。
            * install.batファイルを再度開きます。

**4. テスト**

#. 元の配線に基づいて、IO1を3V3に接続します。

    .. image:: img/faq_at_burn_check_bb.jpg
        :width: 800

#. 右上隅の虫眼鏡アイコン（シリアルモニタ）をクリックし、ボーレートを **115200** に設定すると、ESP8266モジュールに関する情報が表示されます。

    .. image:: img/sp20220524113020.png

    .. note::

        * ``ready`` が表示されない場合、ESP8266モジュールをリセット（RSTをGNDに接続）し、シリアルモニタを再度開くことができます。

#. **NEWLINE DROPDOWN BOX** をクリックし、ドロップダウンオプションで ``both NL & CR`` を選択し、 ``AT`` を入力します。OKが返されると、ESP8266がボードとの接続を正常に確立したことを意味します。

    .. image:: img/sp20220524113702.png

次に、 :ref:`config_esp8266` を参照して、ESP8266モジュールの動作モードとボーレートを設定できます。



