.. _follow_the_line:

4. Seguir la línea
======================

El coche está equipado con un módulo de Seguimiento de Línea, que se puede utilizar para hacer que el coche siga la línea negra.

Cuando el módulo de seguimiento detecta la línea negra, el motor derecho rota mientras que el motor izquierdo no, de modo que el coche se mueve un paso hacia la izquierda frontal.
A medida que el coche se mueve, el módulo de línea se desplaza fuera de la línea, entonces el motor izquierdo gira y el motor derecho no, el coche se moverá un paso hacia la derecha para volver a la línea.
Repetir los dos pasos anteriores permite que el coche se mueva a lo largo de la línea negra.

Antes de comenzar el proyecto, necesitas construir un mapa curvo con cinta de línea negra, el ancho de línea recomendado está entre 0.8-1.5cm y el ángulo de giro no debe ser menor a 90 grados.

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
    *   - :ref:`cpn_track`
        - |link_track_buy|

**Conexión**


Este es un módulo digital de Seguimiento de Línea, cuando detecta una línea negra, emite 1; cuando detecta una línea blanca, emite un valor de 0. Además, puedes ajustar su distancia de detección a través del potenciómetro en el módulo.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/mlCQgAq4elo?si=ZFmHeA6bVsDCPG0p" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Construye el circuito según el siguiente diagrama.

.. list-table:: 
    :header-rows: 1

    * - Módulo de Seguimiento de Línea
      - Placa R3
    * - S
      - 2
    * - V+
      - 5V
    * - G
      - GND

.. image:: img/car_4.png
    :width: 800


**Ajustar el Módulo**


Antes de comenzar el proyecto, necesitas ajustar la sensibilidad del módulo.

Conecta el cableado según el diagrama anterior, luego enciende la placa R3 (ya sea directamente en el cable USB o el cable del botón de la batería de 9V), sin subir el código.

Pega una cinta eléctrica negra en la mesa y coloca el carro sobre ella.

Observa el LED de señal en el módulo para asegurarte de que se ilumina en la mesa blanca y se apaga en la cinta negra.

Si no, necesitas ajustar el potenciómetro en el módulo, para que pueda hacer el efecto anterior.

.. image:: img/line_track_cali.JPG

**Código**

.. note::

    * Abre el archivo ``4.follow_the_line.ino`` en la ruta ``3in1-kit\car_project\4.follow_the_line``.
    * O copia este código en el **Arduino IDE**.
    
    * O sube el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/2779e9eb-b7b0-4d47-b8c0-78fed39828c3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Después de subir el código a la placa R3, alinea el módulo de Seguimiento de Línea bajo el coche con la línea negra, y verás al coche siguiendo la línea.


**¿Cómo funciona?**

En este código, se hace que los dos motores giren microscópicamente a izquierda y derecha según el valor del módulo de Seguimiento de Línea para que puedas ver al coche siguiendo la línea negra.


#. Añade la definición de pin para el módulo de Seguimiento de Línea, aquí está configurado como ``INPUT``. Aquí también inicializa el monitor serial y establece la tasa de baudios a 9600bps.

    .. code-block:: arduino

        ...
        const int lineTrack = 2;
        Serial.begin(9600);
        void setup() {
            ...
            pinMode(lineTrack, INPUT);
        }

#. Lee el valor del módulo de Seguimiento de Línea, si es 1, entonces haz que el coche avance hacia la izquierda; de lo contrario, avanza hacia la derecha. También puedes abrir el monitor serial haciendo clic en el icono de la lupa en la esquina superior derecha para ver el cambio del valor del módulo de Seguimiento de Línea en la línea negra y blanca antes de desconectar el cable USB.

    .. code-block:: arduino
    
        void loop() {

            int speed = 150;

            int lineColor = digitalRead(lineTrack); // 0:white    1:black
            Serial.println(lineColor); 
            if (lineColor) {
                moveLeft(speed);
            } else {
                moveRight(speed);
            }
        }

#. Acerca de las funciones ``moveLeft()`` y ``moveRight()``.

    A diferencia de la función de giro izquierda-derecha en el proyecto :ref:`car_move_code`, aquí solo se necesitan pequeños giros a izquierda y derecha, por lo que solo necesitas ajustar el valor de ``A_1A`` o ``B_1B`` cada vez. Por ejemplo, si te mueves hacia la izquierda frontal (``moveLeft()``), solo necesitas configurar la velocidad a ``A_1A`` y todos los demás a 0, hará que el motor derecho gire en el sentido de las agujas del reloj y el motor izquierdo no se mueva.

    .. code-block:: arduino
    

        void moveLeft(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, speed);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, 0);
        }

        void moveRight(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, speed);
            analogWrite(B_1A, 0);
        }

* `Serial <https://www.arduino.cc/reference/en/language/functions/communication/serial/>`_

    Usado para la comunicación entre la placa Arduino y un ordenador u otros dispositivos.

    * ``Serial.begin()``: Establece la tasa de datos en bits por segundo (baudios) para la transmisión de datos seriales.
    * ``Serial.println()``: Imprime datos al puerto serial como texto ASCII legible seguido de un carácter de retorno de carro (ASCII 13, o '\r') y un carácter de nueva línea (ASCII 10, o '\n'). 

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    La estructura ``if else`` permite un mayor control sobre el flujo del código que la simple declaración if, permitiendo agrupar varias pruebas.
