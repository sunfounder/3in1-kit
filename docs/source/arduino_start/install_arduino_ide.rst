.. _install_arduino:

Arduino IDE 2.0のダウンロードとインストール
=============================================

Arduino IDE（Arduino統合開発環境としても知られています）は、Arduinoプロジェクトを完成させるために必要なソフトウェアサポートを全て提供します。これはArduinoのために特別に設計されたプログラミングソフトウェアで、Arduinoチームによって提供されており、プログラムを書き、それをArduinoボードにアップロードすることができます。

Arduino IDE 2.0はオープンソースプロジェクトです。これは頑丈な前身であるArduino IDE 1.xからの大きなステップであり、一新されたUI、改良されたボード&ライブラリマネージャ、デバッガ、オートコンプリート機能などが搭載されています。

このチュートリアルでは、Windows、Mac、LinuxコンピュータにArduino IDE 2.0をダウンロードしてインストールする方法を紹介します。

必要システム条件
-------------------

* Windows - Win 10以降、64ビット
* Linux - 64ビット
* Mac OS X - バージョン10.14 "Mojave"以降、64ビット

Arduino IDE 2.0のダウンロード
-------------------------------

#. |link_download_arduino| にアクセスしてください。

#. お使いのOSバージョンのIDEをダウンロードしてください。

    .. image:: img/sp_001.png

インストール方法
------------------------------

Windows
^^^^^^^^^^^^^

#. ダウンロードした ``arduino-ide_xxxx.exe`` ファイルをダブルクリックします。

#. ライセンス契約を読み、同意してください。

    .. image:: img/sp_002.png

#. インストールオプションを選択します。

    .. image:: img/sp_003.png

#. インストール場所を選択します。ソフトウェアはシステムドライブ以外のドライブにインストールすることを推奨します。

    .. image:: img/sp_004.png

#. 完了をクリックします。

    .. image:: img/sp_005.png

macOS
^^^^^^^^^^^^^^^^

ダウンロードした ``arduino_ide_xxxx.dmg`` ファイルをダブルクリックし、指示に従って **Arduino IDE.app** を **Applications** フォルダにコピーします。数秒後、Arduino IDEが正常にインストールされたことが確認できます。

.. image:: img/macos_install_ide.png
    :width: 800

Linux
^^^^^^^^^^^^

LinuxシステムでのArduino IDE 2.0のインストールチュートリアルについては、以下のリンクを参照してください：https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing#linux

IDEの起動
--------------

#. Arduino IDE 2.0を初めて開くと、Arduino AVRボード、ビルトインライブラリ、その他の必要なファイルが自動的にインストールされます。

    .. image:: img/sp_901.png

#. また、ファイアウォールやセキュリティセンターがデバイスドライバのインストールを求めるポップアップを表示することがあります。すべてのドライバをインストールしてください。

    .. image:: img/sp_104.png

#. これで、Arduino IDEの準備が完了しました！

    .. note::
        ネットワークの問題やその他の理由で一部のインストールが完了しなかった場合、Arduino IDEを再度開いて残りのインストールを完了することができます。すべてのインストールが完了した後、VerifyまたはUploadをクリックしない限り、Outputウィンドウは自動的には開きません。
