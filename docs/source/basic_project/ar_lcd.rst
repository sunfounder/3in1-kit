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
=============================

I2C接続のLCD1602は、LCD1602本体とI2Cモジュールで構成されています。LCD1602は文字や数字などを表示するために使用できますが、多くの主制御のピンを使用する必要があります。I2Cモジュールを構成することで、このLCD1602を駆動するのに必要なI/0ピンは2つだけになります。

さて、このI2C接続のLCD1602をどのように動作させるか見てみましょう。

**必要な部品**

このプロジェクトには、以下の部品が必要です。

一式のキットとして購入すると非常に便利です。購入リンクは以下の通りです。

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクから個別に購入することも可能です。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネントの紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

**回路図**

.. image:: img/circuit_7.1_lcd1602.png

**配線図**

.. image:: img/5.11_lcd_bb.png
    :width: 800
    :align: center

.. note::
    R4ボードのSDAとSCLは、A4ピンとA5ピンです。

**コード**

.. note::

    * ``3in1-kit\learning_project\5.11.liquid_crystal_display`` のパス下の ``5.11.liquid_crystal_display.ino`` ファイルを開きます。
    * または、このコードを **Arduino IDE** にコピーしてください。
    * ここでは ``LiquidCrystal I2C`` ライブラリが使用されています。 **Library Manager** からインストールできます。

        .. image:: ../img/lib_liquidcrystal_i2c.png
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e49c4936-2530-4890-b86c-1017d11eae6e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードが正常にアップロードされると、I2C接続のLCD1602に「SunFounder」と「Hello World」が表示されます。

.. note::
    コードと配線が問題ない場合でも、LCDに内容が表示されない場合は、背面のポテンショメータを回してみてください。


**どのように動作するのか？**

``LiquidCrystal_I2C.h`` ライブラリを呼び出すことで、LCDを簡単に駆動できます。

.. code-block:: arduino

    #include "LiquidCrystal_I2C.h"

ライブラリ関数:

.. code-block:: arduino

    LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)

Arduinoボードに接続された特定のLCDを表す ``LiquidCrystal_I2C`` クラスの新しいインスタンスを作成します。

* ``lcd_AddR``: LCDのアドレスはデフォルトで0x27です。
* ``lcd_cols``: LCD1602は16列を持っています。
* ``lcd_rows``: LCD1602は2行を持っています。

.. code-block:: arduino

    void init()

LCDを初期化します。

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

LCDディスプレイをすばやくオフにします。

.. code-block:: arduino

    void clear()

ディスプレイをクリアし、カーソル位置をゼロに設定します。

.. code-block:: arduino

    void setCursor(uint8_t col,uint8_t row)

カーソル位置をcol,rowに設定します。

.. code-block:: arduino

    void print(data,BASE)

テキストをLCDに出力します。

* ``data``: 出力するデータ（char、byte、int、long、またはstring）。
* ``BASE (オプショナル)``: 数値を出力するベース：BINはバイナリ(基数2)、DECは10進数(基数10)、OCTは8進数(基数8)、HEXは16進数(基数16)。
