.. _cpn_servo:

Servo
===========

.. image:: img/servo.png
    :align: center

Un servo generalmente está compuesto por las siguientes partes: carcasa, eje, sistema de engranajes, potenciómetro, motor de corriente continua (DC) y placa integrada.

Funciona de la siguiente manera: El microcontrolador envía señales PWM al servo, y luego la placa integrada en el servo recibe las señales a través del pin de señal y controla el motor interno para que gire. Como resultado, el motor acciona el sistema de engranajes y luego motiva el eje después de la desaceleración. El eje y el potenciómetro del servo están conectados entre sí. Cuando el eje gira, acciona el potenciómetro, por lo que el potenciómetro emite una señal de voltaje a la placa integrada. Luego, la placa determina la dirección y velocidad de rotación según la posición actual, para poder detenerse exactamente en la posición definida y mantenerse allí.

.. image:: img/servo_internal.png
    :align: center

El ángulo está determinado por la duración de un pulso que se aplica al cable de control. Esto se llama Modulación por Ancho de Pulso (PWM). El servo espera ver un pulso cada 20 ms. La longitud del pulso determinará cuánto gira el motor. Por ejemplo, un pulso de 1.5 ms hará que el motor gire a la posición de 90 grados (posición neutral).
Cuando se envía un pulso a un servo que es menor a 1.5 ms, el servo gira a una posición y mantiene su eje de salida algunos grados en sentido antihorario desde el punto neutral. Cuando el pulso es más ancho que 1.5 ms ocurre lo opuesto. El ancho mínimo y máximo de pulso que comandará al servo para girar a una posición válida son funciones de cada servo. Generalmente, el pulso mínimo será de aproximadamente 0.5 ms de ancho y el máximo de 2.5 ms de ancho.

.. image:: img/servo_duty.png
    :width: 600
    :align: center

**Ejemplo**

* :ref:`ar_servo` (Proyecto Básico)
* :ref:`iot_gate` (Proyecto IoT)
* :ref:`sh_pendulum` (Proyecto Scratch)
