.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_lcd1602:

5.11.1 液晶ディスプレイ
===============================

I2C LCD1602は、LCD1602とI2Cモジュールで構成されています。LCD1602は文字、数字などを表示するために使用できますが、多くのピンをメインコントロールに使用する必要があります。I2Cモジュールを設定すると、このLCD1602を駆動するのに2つのI/0ピンのみが必要になります。

このI2C CDL1602がどのように動作するかを見てみましょう。

**必要な部品**

このプロジェクトでは、以下の部品が必要です。

キット全体を購入するのは非常に便利です。リンクは以下のとおりです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクからそれぞれ別々に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネントの紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

**回路図**

.. image:: img/circuit_7.1_lcd1602.png

**配線図**

.. image:: img/lcd_bb.jpg
    :width: 800
    :align: center

.. note::
    R3ボードのSDAとSCLは、ピンA4とA5です。

**コード**

.. note::

    * ``3in1-kit\basic_project\5.11.liquid_crystal_display`` のパスの下にある ``5.11.liquid_crystal_display.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーします。
    * ここでは ``LiquidCrystal I2C`` ライブラリが使用されています。 **Library Manager** からインストールできます。

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e49c4936-2530-4890-b86c-1017d11eae6e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードが正常にアップロードされると、I2C LCD1602に"SunFounder"、"Hello World"が表示されます。

.. note::
    コードと配線が正しいのにLCDが内容を表示しない場合、背面のポテンショメータを回してみてください。

**どのように動作するのか？**

``LiquidCrystal_I2C.h`` ライブラリを呼び出すことで、LCDを簡単に駆動することができます。

.. code-block:: arduino

    #include "LiquidCrystal_I2C.h"

ライブラリの機能：

.. code-block:: arduino

    LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)

Arduinoボードに接続された特定のLCDを表す ``LiquidCrystal_I2C`` クラスの新しいインスタンスを作成します。

* ``lcd_AddR``: LCDのアドレスはデフォルトで0x27。
* ``lcd_cols``: LCD1602には16の列があります。
* ``lcd_rows``: LCD1602には2行あります。

.. code-block:: arduino

    void init()

lcdを初期化します。

.. code-block:: arduino

    void backlight()

(オプションの)バックライトをオンにします。

.. code-block:: arduino

    void nobacklight()

(オプションの)バックライトをオフにします。

.. code-block:: arduino

    void display()

LCDディスプレイをオンにします。

.. code-block:: arduino

    void nodisplay()

LCDディスプレイをすぐにオフにします。

.. code-block:: arduino

    void clear()

表示をクリアし、カーソルの位置をゼロに設定します。

.. code-block:: arduino

    void setCursor(uint8_t col,uint8_t row)

カーソルの位置をcol,rowに設定します。

.. code-block:: arduino

    void print(data,BASE)

テキストをLCDに表示します。

* ``data``: 表示するデータ（char、byte、int、long、または文字列）。
* ``BASE (オプション)``: 数字を印刷する基数：BIN(2進数)、DEC(10進数)、OCT(8進数)、HEX(16進数)。
