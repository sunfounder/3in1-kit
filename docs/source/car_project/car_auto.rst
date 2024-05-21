.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _self_driving:

8. Coche Autónomo
=========================

Este proyecto es una combinación de los dos proyectos :ref:`car_ultrasonic` y :ref:`car_ir_obstacle`. 
2 módulos de evitación de obstáculos infrarrojos realizan detección de corta distancia o de bordes, 
y los módulos ultrasónicos hacen detección de larga distancia para confirmar que el coche no golpee un obstáculo durante el proceso de conducción libre.

**Componentes Necesarios**

Para este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí tienes el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS DE ESTE KIT
        - ENLACE
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

También puedes comprarlos por separado en los siguientes enlaces.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

**Cableado**

Conecta el módulo ultrasónico y los 2 módulos de evitación de obstáculos IR al mismo tiempo.

Conecta el ultrasónico a la placa R3 de la siguiente manera.

.. list-table:: 
    :header-rows: 1

    * - Módulo Ultrasónico
      - Placa R3
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

El cableado de los 2 módulos de evitación de obstáculos IR a la placa R3 es como sigue.

.. list-table:: 
    :header-rows: 1

    * - Módulo IR Izquierdo
      - Placa R3
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - Módulo IR Derecho
      - Placa R3
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_7_8.png
    :width: 800

**Código**

.. note::

    * Abre el archivo ``8.self_driving_car.ino`` en la ruta ``3in1-kit\car_project\8.self_driving_car``.
    * O copia este código en el **Arduino IDE**.
    
    * O sube el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0a74a7b1-ead6-4bea-ab5a-4da71f27f82f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

El coche se moverá libremente una vez que el código haya sido cargado con éxito. Cuando el módulo de obstrucción IR en ambos lados detecte un obstáculo, se moverá en la dirección opuesta para una evasión de emergencia; si hay un obstáculo a 2~10cm directamente frente al coche, retrocederá hacia la izquierda, ajustará su dirección y luego avanzará.

**¿Cómo funciona?**

El flujo de trabajo de este proyecto es el siguiente.

* Prioridad para leer el valor del módulo de evitación de obstáculos IR izquierdo y derecho.
* Si el módulo IR izquierdo es 0 (obstáculo detectado), y el módulo IR derecho es 1, deja que el coche retroceda hacia la izquierda.
* Si el módulo IR derecho es 0 (obstáculo detectado), deja que el coche retroceda hacia la derecha.
* Si los 2 módulos IR detectan el obstáculo al mismo tiempo, el coche retrocederá.
* De lo contrario, lee la distancia detectada por el módulo ultrasónico.
* Si la distancia es mayor a 50cm, deja que el coche avance.
* Si la distancia está entre 2-10cm, deja que el coche retroceda antes de girar.
* Si la distancia está entre 10-50cm, deja que el coche avance a baja velocidad.

.. code-block:: arduino

    void loop() {

        int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
        int right = digitalRead(rightIR);

        if (!left && right) {
            backLeft(150);
        } else if (left && !right) {
            backRight(150);
        } else if (!left && !right) {
            moveBackward(150);
        } else {
            float distance = readSensorData();
            Serial.println(distance);
            if (distance > 50) { // Safe
                moveForward(200);
            } else if (distance < 10 && distance > 2) { // Attention
                moveBackward(200);
                delay(1000);
                backLeft(150);
                delay(500);
            } else {
                moveForward(150);
            }
        }
    }

