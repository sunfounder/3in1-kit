.. _cpn_avoid:

障害物回避モジュール
===========================================

.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC**: 電源供給、3.3 ~ 5V DC。
* **GND**: 接地
* **OUT**: シグナルピン、通常は高レベルで、障害物が検出されると低レベルになります。

IR障害物回避モジュールは、環境光への適応性が強く、赤外線の送受信チューブのペアを持っています。

送信チューブは赤外線周波数を放射し、検出方向に障害物がある場合、赤外線放射は受信チューブによって受信され、コンパレータ回路処理後、インジケータが点灯し、低レベル信号が出力されます。

検出距離はポテンショメータで調整可能であり、有効距離範囲は2-30cmです。

.. image:: img/IR_module.png
    :width: 600
    :align: center

**例**

* :ref:`ar_ir_obstacle` (基本プロジェクト)
* :ref:`car_ir_obstacle` (カープロジェクト)
* :ref:`self_driving` (カープロジェクト)
* :ref:`iot_gate` (IoTプロジェクト)
* :ref:`sh_shooting` (Scratchプロジェクト)
* :ref:`sh_tap_tile` (Scratchプロジェクト)