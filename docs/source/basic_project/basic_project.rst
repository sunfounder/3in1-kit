.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _basic_projects:

基本的なプロジェクト
========================

この章では、Arduinoを使用して電子回路を制御する方法を学びます。

コンポーネントに応じて、Arduinoの基本的な制御方法は4つのタイプに分けることができます。

* :ref:`ar_digital_write`: ピンの出力電圧を高または低に設定し、ライトのオン/オフを制御できます。
* :ref:`ar_analog_write`: アナログ値（ `PWM波 <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_ ）をピンに書き込み、ライトの明るさを調整できます。
* :ref:`ar_digital_read`: デジタルピンのレベル信号を読み取り、スイッチの動作状態を読み取ることができます。
* :ref:`ar_analog_read`: アナログピンの電圧を読み取り、ノブの動作状態を読み取ることができます。

また、追加のライブラリが必要なコンポーネントもあり、それらはセクション :ref:`install_libraries_ar` でまとめられています。

最後に、このキットには :ref:`ar_funny_project` も提供されており、多くのシンプルで役立つ操作が含まれています。
このコードのセクションを試して、多くのシンプルなプロジェクトがどのように動作するかを理解してください。


.. toctree::
    :maxdepth: 2

    ard_digital_write
    ard_analog_write
    ard_digital_read
    ard_analog_read
    ard_more_syntax
    ard_funny_project


