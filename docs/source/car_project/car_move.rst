.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _car_move:

1. 移動
===============

.. image:: ../components/img/l9110_module.jpg
    :width: 500
    :align: center

プログラミングを始める前に、L9110モジュールの動作原理を再確認しましょう。

こちらはモーターBの真理表です：

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - モーターBの状態
    * - 1
      - 0
      - 時計回りに回転
    * - 0
      - 1
      - 反時計回りに回転
    * - 0
      - 0
      - ブレーキ
    * - 1
      - 1
      - 停止

こちらはモーターAの真理表です：

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - モーターAの状態
    * - 1
      - 0
      - 時計回りに回転
    * - 0
      - 1
      - 反時計回りに回転
    * - 0
      - 0
      - ブレーキ
    * - 1
      - 1
      - 停止

* :ref:`cpn_l9110`

**前進**

L9110モジュールの入力を12VおよびGNDに直接接続して、車を動かしてみましょう。

.. raw:: html
    
  <iframe width="600" height="400" src="https://www.youtube.com/embed/ulD40OtsL7c?si=hJ9nyf8ePAWNp0-8" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>


1. R3ボード、L9110モジュール、および2つのモーターを接続します。

.. image:: img/car_1.png
    :width: 800

2. B-1B(B-2A)とA-1AをVCCに、B-1AとA-1BをGNDに接続すると、車が前進するのを見ることができます。

.. image:: img/1.move_4.png 
    :align: center

両方のモーターが同時に前進しない場合、以下の状況が発生した場合は、2つのモーターの配線を再調整する必要があります。

* 両方のモーターが同時に後退する場合（左モーターが時計回り、右モーターが反時計回りに回転する場合）、左右のモーターの配線を同時に交換します。OA(A)とOB(A)、OA(B)とOB(B)を交換します。
* 左モーターが後退する場合（時計回りに回転）、左モーターのOA(B)とOB(B)の配線を交換します。
* 右モーターが後退する場合（反時計回りに回転）、右モーターのOA(A)とOB(A)の配線を交換します。

**後退**

B-1B(B-2A)およびA-1AをGNDに、B-1AおよびA-1BをVCCに接続すると、車が後退するのを見ることができます。

.. image:: img/1.move_back.png 
    :width: 800

**左折**

車を左に曲げたい場合、つまり、両方のモーターを時計回りに回転させたい場合は、B-1AおよびA-1AをGNDに、B-1B(B-2A)およびA-1BをVCCに接続する必要があります。

.. image:: img/1.move_left.png 
    :width: 800

**右折**

逆に、車を右に曲げたい場合、つまり、両方のモーターを反時計回りに回転させたい場合は、B-1AおよびA-1AをVCCに、B-1B(B-2A)およびA-1BをGNDに接続する必要があります。

.. image:: img/1.move_right.png 
    :width: 800

**停止**

モーターを停止するには、同じ側の入力を同時に12VまたはGNDに接続します。たとえば、B-1AおよびB-1B(B-2A)を同時に12Vまたは5Vに接続し、A-1AとA-1Bも同様にします。

これはもちろん理論的であり、コードで制御するときに後で必要となります。ここでは、車の電源を取り外して停止させることができます。
