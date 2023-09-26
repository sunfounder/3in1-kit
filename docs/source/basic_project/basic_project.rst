.. _basic_projects:

基本プロジェクト
========================

この章では、Arduinoを使用して電子回路を制御する方法を学びます。

コンポーネントに応じて、Arduinoの基本的な制御方法は4つのタイプに分けられます：

* :ref:`ar_digital_write`: ピンの出力電圧を高または低に設定し、これを使用して光をオンまたはオフにすることができます。
* :ref:`ar_analog_write`: アナログ値 (`PWM波 <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_) をピンに書き込み、これを使用して光の明るさを調整することができます。
* :ref:`ar_digital_read`: デジタルピンのレベル信号を読み取り、これを使用してスイッチの動作状態を読み取ることができます。
* :ref:`ar_analog_read`: アナログピンの電圧を読み取り、これを使用してノブの動作状態を読み取ることができます。

また、使用するには追加のライブラリが必要なコンポーネントもあり、これらはセクション :ref:`install_libraries_ar` の下にまとめられています。

最後に、キットにはいくつかの :ref:`ar_funny_project` も提供されており、これには多くのシンプルで有用な操作が含まれています。
このセクションのコードを試してみれば、ほとんどのシンプルなプロジェクトがどのように動作するかを理解することができます。

.. toctree::
    :maxdepth: 2

    ard_digital_write
    ard_analog_write
    ard_digital_read
    ard_analog_read
    ard_more_syntax
    ard_funny_project


