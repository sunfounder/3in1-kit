.. _cpn_l298n:

Módulo L298N
==================================

Este Módulo Controlador de Motor L298N es un módulo controlador de motor de alta potencia para la conducción de motores de corriente continua (DC) y motores paso a paso. Este módulo consta de un circuito integrado controlador de motor L298 y un regulador de 5V 78M05. El Módulo L298N puede controlar hasta 4 motores de corriente continua o 2 motores de corriente continua con control direccional y de velocidad.

.. image:: img/l298n_pin.jpg
    :width: 400
    :align: center

* **IN1 & IN2**: Pines de entrada del Motor A. Utilizados para controlar la dirección de giro del Motor A.
* **IN3 & IN4**: Pines de entrada del Motor B. Utilizados para controlar la dirección de giro del Motor B.
* **ENA**: Habilita la señal PWM para el Motor A. Aquí se ha conectado a 5V con un jumper cap.
* **ENB**: Habilita la señal PWM para el Motor B. Aquí se ha conectado a 5V con un jumper cap.
* **OUT1 & OUT2**: Pines de salida del Motor A.
* **OUT3 & OUT4**: Pines de salida del Motor B.
* **12V**: Entrada de 12V desde una fuente de poder de corriente continua.
* **5V**: Suministra energía para el circuito lógico de conmutación dentro del circuito integrado L298N.
* **GND**: Pin de tierra.

**Características**

* Modelo del Controlador: L298N 2A
* Chip del Controlador: Doble Puente H L298N
* Voltaje Máximo de Suministro del Motor: 46V
* Corriente Máxima de Suministro del Motor: 2A
* Voltaje Lógico: 5V
* Voltaje del Controlador: 5-35V
* Corriente del Controlador: 2A
* Corriente Lógica: 0-36mA
* Potencia Máxima (W): 25W
* Detección de Corriente para cada motor
* Disipador de calor para un mejor rendimiento
* Indicador LED de encendido

**Principio de Funcionamiento**

El módulo controlador puede manejar dos motores. Los terminales habilitados ENA y ENB son efectivos a nivel alto.

La relación de trabajo entre ENA e IN1, IN2 es la siguiente:

.. list-table:: 
    :widths: 25 25 25 50
    :header-rows: 1

    * - ENA
      - IN1
      - IN2
      - Estado del Motor A
    * - 0
      - X
      - X
      - Detener
    * - 1
      - 0
      - 0
      - Frenar
    * - 1
      - 0
      - 1
      - Girar en sentido de las agujas del reloj
    * - 1
      - 1
      - 0
      - Girar en sentido contrario a las agujas del reloj
    * - 1
      - 1
      - 1
      - Frenar

La relación de trabajo entre ENB e IN3, IN4 es la siguiente.

.. list-table:: 
    :widths: 25 25 25 50
    :header-rows: 1

    * - ENB
      - IN3
      - IN4
      - Estado del Motor B
    * - 0
      - X
      - X
      - Detener
    * - 1
      - 0
      - 0
      - Frenar
    * - 1
      - 0
      - 1
      - Girar en sentido de las agujas del reloj
    * - 1
      - 1
      - 0
      - Girar en sentido contrario a las agujas del reloj
    * - 1
      - 1
      - 1
      - Frenar

**Acerca del Jumper de Habilitación de 5V**

El Módulo Controlador de Motor L298N consta de un Circuito Integrado Controlador de Motor L298, Regulador de Voltaje 78M05, resistencias, capacitor, LED de encendido, jumper de 5V en un circuito integrado.

El regulador de voltaje 78M05 solo se habilitará cuando el jumper esté colocado. Cuando la fuente de alimentación es igual o inferior a 12V, entonces la circuitería interna será alimentada por el regulador de voltaje y el pin de 5V puede ser utilizado como un pin de salida para alimentar el microcontrolador.

El jumper no debe colocarse cuando la fuente de alimentación es superior a 12V y se debe suministrar 5V separado a través del terminal de 5V para alimentar la circuitería interna.

* `Hoja de Datos del L298N <https://www.yerical.com/product/L298N?product/XXXXX?source=adg&gclid=CjwKCAjwkYGVBhArEiwA4sZLuKEC19ydceKs396z1JENqjcbJDEvedRkcsza1aH_swhuNPWzL-CYfRoCMTMQAvD_BwE#g-pd-res>`_

**Ejemplo**

* :ref:`ar_motor` (Proyecto Básico)
* :ref:`car_move` (Proyecto de Coche)
* :ref:`car_speed` (Proyecto de Coche)
* :ref:`iot_car` (Proyecto IoT)
* :ref:`sh_test` (Proyecto Scratch)
