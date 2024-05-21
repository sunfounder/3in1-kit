.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_rgb:

2.2 カラフルな光
==============================================

光は重ね合わせることができることは周知の通りです。例えば、青い光と緑の光を混ぜるとシアン色の光が得られ、赤い光と緑の光を混ぜると黄色の光が得られます。
これは「加色混色の方法」と呼ばれます。

* `加色混色 - Wikipedia <https://en.wikipedia.org/wiki/Additive_color>`_

この方法に基づいて、三原色を使用して、異なる比重に従って任意の色の可視光を混合することができます。例えば、赤色を多く、緑色を少なくすることでオレンジ色が得られます。

この章では、RGB LEDを使用して、加色混色のミステリーを探求します！

RGB LEDは、一つのランプキャップの下に赤、緑、青のLEDを一つずつカプセル化したものと同等であり、これら三つのLEDは共通のカソードピンを共有しています。
各アノードピンに電気信号が供給されるので、対応する色の光が表示されます。
各アノードの電気信号の強度を変更することで、さまざまな色を出力することができます。

**必要な部品**

このプロジェクトには、以下のコンポーネントが必要です。

キット全体を購入することは非常に便利です。以下はリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名前	
        - このキットのアイテム
        - リンク
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

以下のリンクから、個別にも購入可能です。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネント紹介
        - 購入リンク

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

**回路図**

.. image:: img/circuit_2.2_rgb.png

PWMピンの11、10、9は、それぞれRGB LEDの赤、緑、青のピンを制御し、共通のカソードピンをGNDに接続します。
これにより、異なるPWM値でこれらのピンの光を重ね合わせることで、RGB LEDが特定の色を表示することができます。

**配線図**

.. image:: img/rgb_led_sch.png

RGB LEDには4つのピンがあります：最も長いピンは共通のカソードピンで、通常はGNDに接続されます。
最も長いピンの隣の左側のピンは赤で、右側の2つのピンは緑と青です。

.. image:: img/colorful_light_bb.jpg
    :width: 500
    :align: center

**コード**

ここでは、お気に入りの色を描画ソフトウェア（例：ペイント）で選択し、RGB LEDで表示することができます。

.. note::

   * ``3in1-kit\basic_project\2.analogWrite\2.2.colorful_light`` のパスの下の ``2.2.colorful_light.ino`` ファイルを開くことができます。
   * または、このコードを **Arduino IDE** にコピーしてください。
   
   * あるいは、 `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ を通じてコードをアップロードします。

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/5d70e864-4f34-4090-b65d-904350091936/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. image:: img/edit_colors.png

``color_set()`` にRGB値を書き込むと、希望する色でRGBが点灯します。

**どのように動作するのか？**

この例では、RGBの三つのピンに値を割り当てるために使用される関数は、独立したサブ関数 ``color()`` にパッケージされています。

.. code-block:: arduino

    void color (unsigned char red, unsigned char green, unsigned char blue)
    {
        analogWrite(redPin, red);
        analogWrite(greenPin, green);
        analogWrite(bluePin, blue);
    }

``loop()`` 内で、RGB値は ``color()`` 関数を呼び出して、RGBが異なる色を発することを実現する入力引数として動作します。

.. code-block:: arduino

    void loop() 
    {    
        color(255, 0, 0); //  赤 
        delay(1000); 
        color(0,255, 0); //  緑  
        delay(1000);  
        color(0, 0, 255); //  青  
        delay(1000);
    }

