.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _speed_calibration:

11. Calibración de Velocidad
==============================

Al hacer que el coche avance, puedes notar que no se desplaza en línea recta.
Esto se debe a que los dos motores pueden no tener la misma velocidad en fábrica. 
Pero podemos escribir un desfase a los dos motores para hacer converger sus velocidades de rotación.

En este proyecto, 
aprenderemos a almacenar el desfase en `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_. La idea es que después de cada calibración, 
todos los proyectos puedan obtener directamente el valor del desfase de la EEPROM, 
para que el coche pueda avanzar de manera recta y suave.

**Cableado**

Este proyecto tiene el mismo cableado que :ref:`car_move_code`.

**¿Cómo jugar?**

1. Abre el archivo ``11.speed_calibration.ino`` en la ruta ``3in1-kit\car_project\11.speed_calibration``. O copia este código en el **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/66dc7ee5-31a5-418e-9aa2-43e7820cf5e6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

2. Una vez subido el código con éxito, conecta el coche con una batería de 9V, colócalo en el suelo y déjalo avanzar para ver hacia qué lado se desvía.

* Si el coche se mueve hacia el frente izquierdo, significa que la velocidad del motor derecho es demasiado rápida y necesita ser reducida.

    .. code-block:: arduino

        EEPROM.write(1, 100) // 1 means the right motor, 100 means 100% speed, can be set to 90, 95, etc., depending on the actual situation.

* Si el coche se mueve hacia la derecha, significa que la velocidad del motor izquierdo es demasiado rápida y necesita ser reducida.

    .. code-block:: arduino

        EEPROM.write(0, 100) // 0 means the right motor, 100 means the speed is 100%, can be set to 90, 95, etc., depending on the actual situation. 3.

3. Después de modificar el código, sube el código a la placa R3 para ver el efecto. Repite los pasos anteriores hasta que el coche vaya casi recto.

4. Este desfase se registrará en `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_, solo necesitas leer este desfase cuando lo uses en otros proyectos, toma como ejemplo :ref:`car_ir_obstacle`.

.. code-block:: arduino
    :emphasize-lines: 1,3,4,27,28,50,51

    #include <EEPROM.h>

    float leftOffset = 1.0;
    float rightOffset = 1.0;

    const int A_1B = 5;
    const int A_1A = 6;
    const int B_1B = 9;
    const int B_1A = 10;

    const int rightIR = 7;
    const int leftIR = 8;

    void setup() {
        Serial.begin(9600);

        //motor
        pinMode(A_1B, OUTPUT);
        pinMode(A_1A, OUTPUT);
        pinMode(B_1B, OUTPUT);
        pinMode(B_1A, OUTPUT);

        //IR obstacle
        pinMode(leftIR, INPUT);
        pinMode(rightIR, INPUT);

        leftOffset = EEPROM.read(0) * 0.01;//read the offset of the left motor
        rightOffset = EEPROM.read(1) * 0.01;//read the offset of the right motor
    }

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

    void moveForward(int speed) {
        analogWrite(A_1B, 0);
        analogWrite(A_1A, int(speed * leftOffset));
        analogWrite(B_1B, int(speed * rightOffset));
        analogWrite(B_1A, 0);
    }

    void moveBackward(int speed) {
        analogWrite(A_1B, speed);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, speed);
    }

    void backLeft(int speed) {
        analogWrite(A_1B, speed);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, 0);
    }

    void backRight(int speed) {
        analogWrite(A_1B, 0);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, speed);
    }

