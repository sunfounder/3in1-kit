.. _car_speed:

3. Acelerar
===================

Además de la señal digital (ALTA/BAJA), la entrada del módulo L9110 también puede recibir una señal PWM para controlar la velocidad de salida.

En otras palabras, podemos usar ``AnalogWrite()`` para controlar la velocidad de movimiento del coche.

En este proyecto, hacemos que el coche cambie gradualmente su velocidad hacia adelante, primero acelerando y luego desacelerando.

**Cableado**

El cableado de este proyecto es el mismo que en :ref:`car_move_code`.

**Código**

.. note::

    * Abre el archivo ``3.speed_up.ino`` en la ruta ``3in1-kit\car_project\3.speed_up``.
    * O copia este código en el **Arduino IDE**.
    
    * O sube el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c15276c1-2359-4de6-ac82-a14a72e041c6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de ejecutar el programa, el coche acelerará gradualmente y luego desacelerará de la misma manera.

**¿Cómo funciona?**

El objetivo de este proyecto es escribir diferentes valores de PWM en los pines de entrada del módulo L9110 para controlar la velocidad hacia adelante del coche.

#. Utiliza la declaración ``for()`` para dar ``speed`` en pasos de 5, escribiendo valores de 0 a 255 para que puedas ver el cambio en la velocidad hacia adelante del coche.

    .. code-block:: arduino

        void loop() {
            for(int i=0;i<=255;i+=5){
                moveForward(i);
                delay(500);
            }
            for(int i=255;i>=0;i-=5){
                moveForward(i);
                delay(500);
            }
        }

#. Acerca de la función ``moveForward()``.

    A diferencia de :ref:`car_move_code`, que da niveles altos/bajos directamente a los pines de entrada del módulo L9110, aquí pasamos un parámetro ``speed`` a donde necesitamos dar niveles altos.

    .. code-block:: arduino

        void moveForward(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, speed);
            analogWrite(B_1B, speed);
            analogWrite(B_1A, 0);
        }

* `for <https://www.arduino.cc/reference/en/language/structure/control-structure/for/>`_

La declaración ``for`` se utiliza para repetir un bloque de declaraciones encerradas entre llaves. Generalmente se usa un contador de incremento para incrementar y terminar el bucle.

    .. code-block:: arduino

        for (initialization; condition; increment) {
        // statement(s);
        }

    * ``initialization``: ocurre primero y solo una vez.
    * ``condition``: cada vez que se pasa por el bucle, se prueba la condición; si es verdadera, se ejecuta el bloque de declaración y el incremento, luego se prueba nuevamente la condición. Cuando la condición se vuelve falsa, el bucle termina.
    * ``increment``: se ejecuta cada vez que se pasa por el bucle cuando la condición es verdadera.
