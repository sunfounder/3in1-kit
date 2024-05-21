.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_passive_buzzer:

5.7 ``Tone()`` または ``noTone()``
====================================

``Tone()`` は指定された周波数の正方形の波（および50％のデューティサイクル）をピンで生成するために使用されます。継続時間を指定することもできますが、 ``noTone()`` が呼び出されるまで波は続きます。

このプロジェクトでは、この二つの関数を使用して、受動ブザーを振動させて音を鳴らします。
アクティブブザーと同様に、受動ブザーも電磁誘導の現象を利用して動作します。
違いは、受動ブザーには振動源がないため、直流信号が使用されるとビープ音がしないことです。
しかし、これにより受動ブザーは自分の振動周波数を調整でき、"ド、レ、ミ、ファ、ソ、ラ、シ"などの異なる音符を発することができます。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

全体のキットを購入するのは確かに便利です、リンクはこちら：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクから別々に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネントの紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|

**回路図**

.. image:: img/circuit_6.1_passive.png

ブザーのカソードをGNDに、アノードをデジタルピン9に接続します。

**配線図**

.. image:: img/5.7_tone_bb.png
    :width: 600
    :align: center

**コード**

.. note::

    * ``3in1-kit\learning_project\5.7.tone_notone`` のパスの下で ``5.7.tone_notone.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9212e985-1f31-4bd9-bee6-f29357035aae/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードをR4ボードにアップロードしたとき、7つの音符を含むメロディーが聞こえます。


**どのように動作するのか？**

以下、2つの点に注意が必要です：

1. ``tone()`` & ``noTone()``: この関数は、受動ブザーの音を直接制御するために使用され、そのプロトタイプは以下のとおりです：


**文法**
    void tone(int pin, unsigned int frequency)

    void tone(int pin, unsigned int frequency, unsigned long duration)

**パラメータ**
    * ``pin``: トーンを生成するArduinoのピン。
    * ``frequency``: ヘルツ単位のトーンの周波数。
    * ``duration``: ミリ秒単位のトーンの持続時間（オプショナル）


指定された周波数の正方形の波（および50％のデューティサイクル）をピンで生成します（これにより受動ブザーが振動して音を発する）。持続時間を指定でき、指定しない場合は ``noTone()`` が呼び出されるまで波は続きます。 
ピンは、ピエゾブザーまたは他のスピーカーに接続して、音を再生することができます。

同時に1つのトーンのみを生成することができます。異なるピンですでにトーンが再生されている場合、 ``tone()`` の呼び出しは効果がありません。同じピンでトーンが再生されている場合、呼び出しはその周波数を設定します。

``tone()`` 関数の使用は、ピン3および11のPWM出力に干渉します。

31Hzより低いトーンを生成することはできません。


**文法**
    void noTone(int pin)

**パラメータ**
    ``pin``: トーンを生成するArduinoのピン。

``tone()`` によってトリガされる正方形の波の生成を停止します。トーンが生成されていない場合、効果はありません。

これら2つの関数を知ったら、コードの理解が深まります―配列 ``melody[]`` と配列 ``noteDurations[]`` のインストールは、後続の複数回の ``tone()`` 関数の呼び出しや、音楽の再生の効果を高めるためのループ内でのトーンと持続時間の変更の準備です。

2. ``pitches.h``: このコードは追加のファイル、 ``pitches.h`` を使用しています。このファイルには、典型的なノートのためのすべてのピッチ値が含まれています。たとえば、NOTE_C4は中央のCです。NOTE_FS4はFシャープです、などです。このノートテーブルは、 ``tone()`` コマンドがベースになっているBrett Hagmanによって元々書かれました。音楽のノートを作りたいときに役立つでしょう。

.. code-block:: arduino

    #include "pitches.h"

.. note::
    このサンプルプログラムには既に ``pitches.h`` ファイルがあります。メインコードと同じフォルダにまとめると、 ``pitches.h`` のインストールの続きのステップは省略できます。

.. image:: img/image123.png

コードファイルを開いた後、 ``pitches.h`` コードを開くことができない場合は、手動で1つ作成することができます。手順は以下の通りです：

``pitches.h`` ファイルを作成するには、シリアルモニターアイコンのすぐ下のボタンをクリックして **New Tab** を選択するか、 **Ctrl+Shift+N** を使用します。

.. image:: img/image124.png

次に、以下のコードをペーストして、それを ``pitches.h`` として保存します：

.. code-block:: arduino

    /*****************
    公開定数
    *****************/
    #define NOTE_B0  31
    #define NOTE_C1  33
    #define NOTE_CS1 35
    #define NOTE_D1  37
    #define NOTE_DS1 39
    #define NOTE_E1  41
    #define NOTE_F1  44
    #define NOTE_FS1 46
    #define NOTE_G1  49
    #define NOTE_GS1 52
    #define NOTE_A1  55
    #define NOTE_AS1 58
    #define NOTE_B1  62
    #define NOTE_C2  65
    #define NOTE_CS2 69
    #define NOTE_D2  73
    #define NOTE_DS2 78
    #define NOTE_E2  82
    #define NOTE_F2  87
    #define NOTE_FS2 93
    #define NOTE_G2  98
    #define NOTE_GS2 104
    #define NOTE_A2  110
    #define NOTE_AS2 117
    #define NOTE_B2  123
    #define NOTE_C3  131
    #define NOTE_CS3 139
    #define NOTE_D3  147
    #define NOTE_DS3 156
    #define NOTE_E3  165
    #define NOTE_F3  175
    #define NOTE_FS3 185
    #define NOTE_G3  196
    #define NOTE_GS3 208
    #define NOTE_A3  220
    #define NOTE_AS3 233
    #define NOTE_B3  247
    #define NOTE_C4  262
    #define NOTE_CS4 277
    #define NOTE_D4  294
    #define NOTE_DS4 311
    #define NOTE_E4  330
    #define NOTE_F4  349
    #define NOTE_FS4 370
    #define NOTE_G4  392
    #define NOTE_GS4 415
    #define NOTE_A4  440
    #define NOTE_AS4 466
    #define NOTE_B4  494
    #define NOTE_C5  523
    #define NOTE_CS5 554
    #define NOTE_D5  587
    #define NOTE_DS5 622
    #define NOTE_E5  659
    #define NOTE_F5  698
    #define NOTE_FS5 740
    #define NOTE_G5  784
    #define NOTE_GS5 831
    #define NOTE_A5  880
    #define NOTE_AS5 932
    #define NOTE_B5  988
    #define NOTE_C6  1047
    #define NOTE_CS6 1109
    #define NOTE_D6  1175
    #define NOTE_DS6 1245
    #define NOTE_E6  1319
    #define NOTE_F6  1397
    #define NOTE_FS6 1480
    #define NOTE_G6  1568
    #define NOTE_GS6 1661
    #define NOTE_A6  1760
    #define NOTE_AS6 1865
    #define NOTE_B6  1976
    #define NOTE_C7  2093
    #define NOTE_CS7 2217
    #define NOTE_D7  2349
    #define NOTE_DS7 2489
    #define NOTE_E7  2637
    #define NOTE_F7  2794
    #define NOTE_FS7 2960
    #define NOTE_G7  3136
    #define NOTE_GS7 3322
    #define NOTE_A7  3520
    #define NOTE_AS7 3729
    #define NOTE_B7  3951
    #define NOTE_C8  4186
    #define NOTE_CS8 4435
    #define NOTE_D8  4699
    #define NOTE_DS8 49
