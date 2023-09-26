.. _cpn_avoid:

障害物回避モジュール
===========================================

.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC**: 電源供給、3.3 ~ 5V DC。
* **GND**: グラウンド
* **OUT**: 信号ピン、通常は高レベルで、障害物を検出すると低レベルになります。

IR障害物回避モジュールは、環境光に対する適応性が高く、赤外線の送受信管のペアを持っています。

送信管は赤外線の周波数を放出し、検出方向に障害物が存在すると、赤外線の放射が受信管によって受け取られ、コンパレータ回路の処理を経て、インジケータが点灯し、低レベルの信号を出力します。

検出距離はポテンショメータで調整可能で、有効距離の範囲は2-30cmです。

.. image:: img/IR_module.png
    :width: 600
    :align: center

**例**

* :ref:`ar_ir_obstacle` (基本プロジェクト)
* :ref:`car_ir_obstacle` (車プロジェクト)
* :ref:`self_driving` (車プロジェクト)
* :ref:`iot_gate` (IoTプロジェクト)

.. * :ref:`sh_shooting` (Scratchプロジェクト)
.. * :ref:`sh_tap_tile` (Scratchプロジェクト)

