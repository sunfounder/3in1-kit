.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _car_ir_obstacle:

5. Jugar con el Módulo de Evitación de Obstáculos
===================================================

Dos módulos de evitación de obstáculos infrarrojos están montados en la parte delantera del coche, que se pueden usar para detectar algunos obstáculos cercanos.

En este proyecto, se permite que el coche se mueva libremente hacia adelante, y cuando encuentra un obstáculo, es capaz de evitarlo y continuar moviéndose en otras direcciones.

**Componentes Necesarios**

En este proyecto, necesitaremos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS EN ESTE KIT
        - ENLACE
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

También puedes comprarlos por separado en los enlaces a continuación.

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
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

**Cableado**

El módulo de evitación de obstáculos es un sensor de proximidad infrarrojo ajustable en distancia cuya salida es normalmente alta y baja cuando se detecta un obstáculo.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/vadNtXwITFc?si=gY4Ww31zmcs8AObP" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Ahora construye el circuito según el siguiente diagrama.

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

.. image:: img/car_5.png
    :width: 800


**Ajustar el Módulo**

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/calibrate_ir.mp4" type="video/mp4">
        Su navegador no soporta la etiqueta de video.
    </video>
    
Antes de comenzar el proyecto, necesitas ajustar la distancia de detección del módulo.

Conecta el cableado según el diagrama anterior, enciende la placa R3 (ya sea conectando directamente el cable USB o enchufando el cable de la batería de 9V), sin subir el código.

Coloca un cuaderno u otro objeto plano a unos 5cm frente al módulo IR de evitación de obstáculos.

Luego usa un destornillador para girar el potenciómetro en el módulo hasta que el indicador de señal en el módulo apenas se ilumine, de esta manera ajustarás su máxima distancia de detección a 5cm.

Sigue el mismo método para ajustar otro módulo infrarrojo.

.. image:: img/ir_obs_cali.jpg

**Código**

.. note::

    * Abre el archivo ``5.obstacle_avoidance_module.ino`` en la ruta ``3in1-kit\car_project\5.obstacle_avoidance_module``.
    * O copia este código en el **Arduino IDE**.
    
    * O sube el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/289ca80d-009f-4f60-b36d-1da6c5e10233/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

El coche se moverá hacia adelante una vez que el código haya sido cargado con éxito. Cuando el módulo infrarrojo izquierdo detecta un obstáculo, retrocederá hacia la izquierda; cuando el módulo infrarrojo derecho detecta un obstáculo, retrocederá hacia la derecha; si ambos lados detectan un obstáculo, retrocederá rectamente.

**¿Cómo funciona?**

Este proyecto se basa en el valor de los módulos infrarrojos de evitación de obstáculos izquierdo y derecho para hacer que el coche realice la acción adecuada.

#. Añade la definición de pin para los 2 módulos de evitación de obstáculos, aquí están configurados como ``INPUT``.

    .. code-block:: arduino

        ...
        const int rightIR = 7;
        const int leftIR = 8;

        void setup() {
        ...

        //IR obstacle
            pinMode(leftIR, INPUT);
            pinMode(rightIR, INPUT);
        }


#. Lee los valores de los módulos infrarrojos izquierdo y derecho y haz que el coche realice la acción correspondiente.

    .. code-block:: arduino

        void loop() {

            int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
            int right = digitalRead(rightIR);
            int speed = 150;

            if (!left && right) {
                backLeft(speed);
            } else if (left && !right) {
                backRight(speed);
            } else if (!left && !right) {
                moveBackward(speed);
            } else {
                moveForward(speed);
            }
        }

    * Si el módulo IR izquierdo es 0 (obstáculo detectado) y el módulo IR derecho es 1, haz que el coche retroceda hacia la izquierda.
    * Si el módulo IR derecho es 0 (obstáculo detectado), haz que el coche retroceda hacia la derecha.
    * Si los 2 módulos IR detectan el obstáculo al mismo tiempo, el coche retrocederá.
    * De lo contrario, el coche seguirá avanzando.


#. Acerca de la función ``backLeft()``.

    Cuando el motor derecho gira en sentido antihorario y el motor izquierdo no gira, el coche retrocederá hacia la izquierda. 

    .. code-block:: arduino

        void backLeft(int speed) {
            analogWrite(A_1B, speed);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, 0);
        }

#. Acerca de la función ``backLeft()``.

    Cuando el motor izquierdo gira en sentido horario y el motor derecho no gira, el coche retrocederá hacia la derecha.

    .. code-block:: arduino

        void backRight(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, speed);
        }

* `&& <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicaland/>`_: El AND lógico resulta en verdadero solo si ambos operandos son verdaderos.

* `! <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicalnot/>`_: El NOT lógico resulta en verdadero si el operando es falso y viceversa.

