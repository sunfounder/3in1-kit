.. _cpn_avoid:

Módulo de Evitación de Obstáculos
===========================================

.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC**: Fuente de alimentación, 3.3 ~ 5V DC.
* **GND**: Tierra
* **OUT**: Pin de señal, normalmente a nivel alto, y a nivel bajo cuando se detecta un obstáculo.

El módulo de evitación de obstáculos IR tiene una fuerte adaptabilidad a la luz ambiental, cuenta con un par de tubos de transmisión y recepción infrarrojos.

El tubo transmisor emite frecuencia infrarroja, cuando la dirección de detección encuentra un obstáculo, la radiación infrarroja es recibida por el tubo receptor, 
tras el procesamiento del circuito comparador, el indicador se encenderá y emitirá una señal de nivel bajo.

La distancia de detección puede ser ajustada mediante un potenciómetro, el rango efectivo de distancia es de 2-30cm.

.. image:: img/IR_module.png
    :width: 600
    :align: center

**Ejemplo**

* :ref:`ar_ir_obstacle` (Proyecto Básico)
* :ref:`car_ir_obstacle` (Proyecto de Coche)
* :ref:`self_driving` (Proyecto de Coche)
* :ref:`iot_gate` (Proyecto IoT)
* :ref:`sh_shooting` (Proyecto Scratch)
* :ref:`sh_tap_tile` (Proyecto Scratch)

