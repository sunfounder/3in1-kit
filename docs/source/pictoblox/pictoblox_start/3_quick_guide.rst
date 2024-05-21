.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _sh_guide:

1.3 PictoBloxのクイックガイド
====================================

PictoBloxの2つのモードでの使い方を学びましょう。

また、R3ボードのPin 13に接続されたオンボードLEDがありますので、2つの異なるモードでこのLEDを点滅させる方法を学びます。

.. image:: img/1_led.jpg
    :width: 500
    :align: center

.. _stage_mode:

ステージモード
---------------

**1. Arduinoボードを接続**

USBケーブルでArduinoボードをコンピュータに接続します。通常、コンピュータは自動的にボードを認識し、最終的にCOMポートを割り当てます。

PictoBloxを開くと、Pythonのプログラミングインターフェースがデフォルトで開きます。ブロックインターフェースに切り替える必要があります。

.. image:: img/0_choose_blocks.png

次に、モード切替のための右上隅が表示されます。デフォルトはステージモードで、Tobiがステージに立っています。

.. image:: img/1_stage_upload.png

上部のナビゲーションバーで **Board** をクリックしてボードを選択します。

.. image:: img/1_board.png

例として、 **Arduino Uno** を選びます。

.. image:: img/1_choose_uno.png

次に、接続するポートを選択するための接続ウィンドウが表示されます。接続が完了するとホームページに戻ります。使用中に接続が切れた場合は、 **Connect** をクリックして再接続することもできます。

.. image:: img/1_connect.png

同時に、 **Block Palette** にArduino Uno関連のパレット、例えばArduino UnoやActuatorsなどが表示されます。

.. image:: img/1_arduino_uno.png

**2. ファームウェアのアップロード**

ステージモードで作業を行うためには、ボードにファームウェアをアップロードする必要があります。これによりボードとコンピュータ間のリアルタイム通信が可能となります。ファームウェアのアップロードは一度だけのプロセスです。Upload Firmwareボタンをクリックして行います。

少し待つと、アップロード成功のメッセージが表示されます。

.. note::

    このArduinoボードをPictoBloxで初めて使用する場合、またはこのArduinoが以前Arduino IDEでアップロードされていた場合は、使用する前に **Upload Firmware** をタップする必要があります。

.. image:: img/1_firmware.png

**3. プログラミング**

* スクリプトを直接開くと実行

もちろん、スクリプトを直接開いて実行することもできますが、まず `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_ からダウンロードしてください。

右上隅の **File** をクリックし、 **Open** を選択します。

.. image:: img/0_open.png

**Open from Computer** を選択します。

.. image:: img/0_dic.png

``3in1-kit\scratch_project\code`` のパスに移動して、 **1. Stage Mode.sb3** を開きます。必要なコードを `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_ からダウンロードしたことを確認してください。

.. image:: img/0_stage.png

スクリプトを直接クリックして実行します。いくつかのプロジェクトは緑の旗をクリックするか、スプライトをクリックします。

.. image:: img/1_more.png

* ステップバイステップのプログラム

これらの手順に従って、スクリプトをステップバイステップで書くこともできます。

**Arduino Uno** のパレットをクリックします。

.. image:: img/1_arduino_uno.png

Arduinoボード上のLEDは、デジタルピン13で制御されます（2つの状態、HIGHまたはLOWのみ）。そのため、[set digital pin out as]ブロックをスクリプトエリアにドラッグします。

LEDのデフォルトの状態は点灯しているため、ピン13をLOWに設定して、このブロックをクリックするとLEDが消灯するのを確認できます。

* [set digital pin out as]: デジタルピン(2〜13)を(HIGH/LOW)レベルに設定する。

.. image:: img/1_digital.png

連続してLEDを点滅させる効果を確認するには、 **Control** パレット内の[Wait 1 seconds]ブロックと[forever]ブロックを使用する必要があります。これらのブロックを書いた後にクリックすると、黄色のハロが表示されていることを意味します。

* [Wait 1 seconds]: **Control** パレットから、2つのブロックの間の時間間隔を設定するために使用されます。
* [forever]: **Control** パレットから、手動で一時停止しない限りスクリプトを継続的に実行するために使用されます。

.. image:: img/1_more.png


.. _upload_mode:

アップロードモード
------------------

**1. Arduinoボードに接続する**

ArduinoボードをUSBケーブルでコンピュータに接続します。通常、コンピュータはボードを自動的に認識し、最終的にCOMポートを割り当てます。

PictoBloxを開き、右上のナビゲーションバーで **Board** をクリックしてボードを選択します。

.. image:: img/1_board.png

例として、 **Arduino Uno** を選択します。

.. image:: img/1_choose_uno.png

接続ウィンドウが表示され、接続するポートを選択します。接続が完了するとホームページに戻ります。使用中に接続が切れた場合は、 **Connect** をクリックして再接続できます。

.. image:: img/1_connect.png

同時に、 **Block Palette** にArduino Uno関連のパレット、例えばArduino Unoやアクチュエータなどが表示されます。

.. image:: img/1_upload_uno.png

アップロードモードを選択すると、ステージは元のArduinoコードエリアに切り替わります。

.. image:: img/1_upload.png

**2. プログラミング**

* スクリプトを直接開く・実行する

右上のコーナーの **File** をクリックします。

.. image:: img/0_open.png

**Open from Computer** を選択します。

.. image:: img/0_dic.png

``3in1-kit\scratch_project\code`` のパスに移動して、 **1. Upload Mode.sb3** を開きます。必要なコードは `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_ からダウンロードしたことを確認してください。

.. image:: img/0_upload.png

最後に、 **Upload Code** ボタンをクリックします。

.. image:: img/1_upload_code.png

* ステップバイステップでプログラムする

これらの手順に従って、スクリプトをステップバイステップで記述することもできます。

**Arduino Uno** パレットをクリックします。

.. image:: img/1_upload_uno.png

スクリプトエリアに[when Arduino Uno starts up]をドラッグします。これはすべてのスクリプトに必要です。

.. image:: img/1_uno_starts.png

ArduinoボードのLEDはデジタルpin13（2つの状態のみHIGHまたはLOW）によって制御されるため、[set digital pin out as]ブロックをスクリプトエリアにドラッグします。

LEDのデフォルトの状態は点灯しているので、pin 13をLOWに設定し、このブロックをクリックするとLEDが消えます。

* [set digital pin out as]: デジタルピン（2〜13）を(HIGH/LOW)レベルに設定します。

.. image:: img/1_upload_digital.png

この時点で、右側にArduinoコードが表示されます。このコードを編集したい場合は、編集モードをオンにできます。

.. image:: img/1_upload1.png

連続して点滅するLEDの効果を見るために、 **Control** パレットの[Wait 1 seconds]と[forever]ブロックを使用する必要があります。これらのブロックを書き込んだ後、クリックすると黄色いハローが表示されていることを確認してください。これは、それが実行中であることを意味します。

* [Wait 1 seconds]: **Control** パレットから、2つのブロック間の時間間隔を設定するために使用します。
* [forever]: **Control** パレットから、スクリプトを手動で一時停止するまで実行し続けることができます。

.. image:: img/1_upload_more.png

最後に、 **Upload Code** ボタンをクリックします。

.. image:: img/1_upload_code.png
