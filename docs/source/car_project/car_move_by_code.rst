.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _car_move_code:

2. Movimiento por Código
==========================

En el proyecto anterior, intentamos controlar el funcionamiento del motor utilizando diferentes señales de nivel para la entrada del módulo L9110.

Si modificamos las señales de nivel a través del programa, entonces podremos controlar el movimiento del coche de manera flexible.

**Componentes Necesarios**

Para este proyecto, necesitaremos los siguientes componentes.

Definitivamente es conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS DE ESTE KIT
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


**Cableado**

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/Dpxpb4wSq5k?si=ep6p_jzhm-DPU9w4" title="Reproductor de video de YouTube" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Conecta los cables entre el módulo L9110 y la placa R3 de acuerdo con el diagrama a continuación.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - Módulo L9110
      - Placa R3
      - Motor
    * - A-1B
      - 5
      - 
    * - A-1A
      - 6
      - 
    * - B-1B(B-2A)
      - 9
      - 
    * - B-1A
      - 10
      - 
    * - OB(B)
      - 
      - Cable negro del motor derecho
    * - OA(B)
      - 
      - Cable rojo del motor derecho
    * - OB(A)
      - 
      - Cable negro del motor izquierdo
    * - OA(A)
      - 
      - Cable rojo del motor izquierdo

.. image:: img/car_2.png
    :width: 800


**Código**

.. note::

    * Abre el archivo ``2.move.ino`` bajo la ruta de ``3in1-kit\car_project\2.move``.
    * O copia este código en **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6ff67dfb-a1c1-474b-a106-6acbb3a39e6f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Después de subir el código, el coche se moverá hacia adelante, hacia atrás, a la izquierda y a la derecha durante dos segundos respectivamente.

**¿Cómo funciona?**

Este proyecto es esencialmente el mismo que el anterior, implica hacer que el coche se mueva hacia adelante, hacia atrás, a la izquierda y a la derecha, así como detenerse proporcionando diferentes niveles de señal a los pines de entrada del módulo L9110.

#. Inicializar los pines del módulo L9110.

    .. code-block:: arduino

        const int A_1B = 5;
        const int A_1A = 6;
        const int B_1B = 9;
        const int B_1A = 10;

        void setup() {
            pinMode(A_1B, OUTPUT);
            pinMode(A_1A, OUTPUT);
            pinMode(B_1B, OUTPUT);
            pinMode(B_1A, OUTPUT);
        }

#. Establecer los pines de entrada en diferentes niveles alto o bajo para controlar la rotación de los motores izquierdo y derecho, y luego encapsularlos en funciones individuales.

    .. code-block:: arduino

        void moveForward() {
            digitalWrite(A_1B, LOW);
            digitalWrite(A_1A, HIGH);
            digitalWrite(B_1B, HIGH);
            digitalWrite(B_1A, LOW);
        }

        void moveBackward() {
            digitalWrite(A_1B, HIGH);
            digitalWrite(A_1A, LOW);
            digitalWrite(B_1B, LOW);
            digitalWrite(B_1A, HIGH);
        }
        ...
#. Llamar a estas funciones en ``loop()``.

    .. code-block:: arduino

        void loop() {
            moveForward();
            delay(2000);
            stopMove();
            delay(500);

            moveBackward();
            delay(2000);
            stopMove();
            delay(500);
        ...

* `digitalWrite(pin, valor) <https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/>`_

    * ``pin``: el número de pin de Arduino.
    * ``valor``: HIGH o LOW.
    
    Escribe un valor HIGH o LOW en un pin digital. Si el pin ha sido configurado como ``OUTPUT`` con ``pinMode()``, su voltaje se establecerá en el valor correspondiente: 5V (o 3.3V en placas de 3.3V) para HIGH, 0V (tierra) para LOW.


* `pinMode(pin, modo) <https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/>`_

    * ``pin``: el número de pin de Arduino para establecer el modo.
    * ``modo``: INPUT, OUTPUT, o INPUT_PULLUP.
    
    Configura el pin especificado para comportarse ya sea como una entrada o una salida.

* `delay(ms) <https://www.arduino.cc/reference/en/language/functions/time/delay/>`_

    * ``ms``: la cantidad de milisegundos a pausar. Tipos de datos permitidos: unsigned long.

    Pausa el programa durante la cantidad de tiempo (en milisegundos) especificada como parámetro. (Hay 1000 milisegundos en un segundo.)

