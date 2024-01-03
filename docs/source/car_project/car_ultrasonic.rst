.. _car_ultrasonic:

6. Jugar con el Módulo Ultrasónico
=====================================

En el proyecto :ref:`car_ir_obstacle`, se utilizan 2 módulos infrarrojos de evitación de obstáculos, pero la distancia de detección del módulo IR es corta, lo que puede hacer que el coche reaccione tarde para evitar los obstáculos.

En este proyecto, usamos un módulo ultrasónico para hacer detecciones a larga distancia, permitiendo que el coche sienta obstáculos desde una distancia mayor y así tomar una decisión.

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Cableado**

Un módulo sensor ultrasónico es un instrumento que mide la distancia a un objeto usando ondas sonoras ultrasónicas. 
Tiene dos sondas. Una para enviar las ondas ultrasónicas y la otra para recibir las ondas y transformar el tiempo de envío y recepción en una distancia, detectando así la distancia entre el dispositivo y un obstáculo.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/qx9ZH-YnAkg?si=wfrsDrmGCPa2nYPD" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Ahora construye el circuito según el siguiente diagrama.

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

.. image:: img/car_6.png
    :width: 800


**Código**

.. note::

    * Abre el archivo ``6.ultrasonic_module.ino`` en la ruta ``3in1-kit\car_project\6.ultrasonic_module``.
    * O copia este código en el **Arduino IDE**.
    
    * O sube el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/ae97f966-9d72-40e6-aa9f-e0767ddf5bd5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Después de que el código se haya cargado con éxito, dirige el coche hacia la pared. Si la distancia es demasiado grande, avanzará; si es demasiado corta, retrocederá; si está a una distancia segura, se detendrá.

**¿Cómo funciona?**

Este proyecto se basa en la distancia leída por el módulo ultrasónico para mover el coche en consecuencia.

#. Añade la definición de pin para el módulo ultrasónico, ``trigPin`` se utiliza para transmitir la onda ultrasónica, por lo tanto, se configura como ``OUTPUT``; ``echoPin`` se configura como ``INPUT`` para recibir la onda ultrasónica.

    .. code-block:: arduino

        ...
        const int trigPin = 3;
        const int echoPin = 4;

        void setup() {
        ...

        //ultrasonic
            pinMode(echoPin, INPUT);
            pinMode(trigPin, OUTPUT);
        }

#. Primero lee el valor de distancia obtenido del módulo ultrasónico, si la distancia es mayor a 25cm, haz que el coche avance; si la distancia está entre 2-10cm, haz que retroceda, de lo contrario (entre 10~25cm) detente.

    .. code-block:: arduino

        void loop() {
            float distance = readSensorData();
            if (distance > 25) {
                moveForward(200);
            }
            else if (distance < 10 && distance > 2) {
                moveBackward(200);
            } else {
                stopMove();
            }
        }

#. Acerca de la función ``readSensorData()``.

    El transmisor del módulo ultrasónico transmite una señal de onda cuadrada de 10us cada 2us, y el receptor recibe una señal de nivel alto si hay un obstáculo dentro del alcance. Usa la función ``pulseIn()`` para registrar el tiempo desde el envío hasta la recepción, divídelo por la velocidad del sonido 340m/s, y luego divídelo por 2, el resultado es la distancia entre este módulo y el obstáculo en unidades: cm.

    .. code-block:: arduino

        float readSensorData() {
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);
            float distance = pulseIn(echoPin, HIGH) / 58.00; //Equivalent to (340m/s*1us)/2
            return distance;
        }

* `pulseIn(pin, value) <https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/>`_

    * ``pin``: el número del pin de Arduino en el que quieres leer el pulso. Tipos de datos permitidos: int.
    * ``value``: tipo de pulso a leer: ya sea ALTO o BAJO. Tipos de datos permitidos: int.

    Lee un pulso (ya sea ALTO o BAJO) en un pin. Por ejemplo, si el valor es ALTO, ``pulseIn()`` espera a que el pin pase de BAJO a ALTO, comienza a medir el tiempo, luego espera a que el pin pase a BAJO y detiene el tiempo.

