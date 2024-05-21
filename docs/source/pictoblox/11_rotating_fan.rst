.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_rotating_fan:

2.11 Ventilador Rotativo
========================

En este proyecto, haremos un sprite de estrella giratoria y un ventilador.

Al hacer clic en los sprites de flecha izquierda y derecha en el escenario, controlarás la rotación en sentido horario y antihorario del motor y del sprite de estrella. Haz clic en el sprite de estrella para detener la rotación.

.. image:: img/13_fan.png

Aprenderás
---------------------

- Principio de funcionamiento del motor
- Función de transmisión (broadcast)
- Detener otro script en bloque de sprite

Componentes Necesarios
-------------------------

En este proyecto, necesitamos los siguientes componentes.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110` 
        - \-

Construir el Circuito
-----------------------

.. image:: img/circuit/motor_circuit.png

Programación
------------------

El efecto que queremos lograr es usar 2 sprites de flecha para controlar respectivamente la rotación en sentido horario y antihorario del motor y del sprite de estrella, haciendo clic en el sprite de estrella detendrá la rotación del motor.

**1. Añadir sprites**

Elimina el sprite predeterminado, luego selecciona el sprite **Star** y el sprite **Arrow1**, y copia **Arrow1** una vez.

.. image:: img/13_star.png

En la opción **Costumes**, cambia el sprite **Arrow1** a un disfraz de dirección diferente.

.. image:: img/13_star1.png

Ajusta el tamaño y la posición del sprite adecuadamente.

.. image:: img/13_star2.png

**2. Sprite de flecha izquierda**

Cuando se hace clic en este sprite, transmite un mensaje - gira, luego establece el pin digital 9 en bajo y el pin 10 en alto, y establece la variable **flag** en 1. Si haces clic en el sprite de flecha izquierda, encontrarás que el motor gira en sentido antihorario, si tu giro es en sentido horario, entonces intercambias las posiciones del pin 9 y el pin 10.

Hay 2 puntos a tener en cuenta aquí.

* `[broadcast <https://en.scratch-wiki.info/wiki/Broadcast>`_]: de la paleta **Events**, se utiliza para transmitir un mensaje a los otros sprites, cuando los otros sprites reciben este mensaje, realizarán un evento específico. Por ejemplo, aquí es **turn**, cuando el sprite **star** recibe este mensaje, ejecuta el script de rotación.
* variable bandera: La dirección de rotación del sprite estrella está determinada por el valor de bandera. Entonces, cuando creas la variable **flag**, necesitas hacer que se aplique a todos los sprites.

.. image:: img/13_left.png

**3. Sprite de flecha derecha**

Cuando se hace clic en este sprite, transmite un mensaje gira, luego establece el pin digital 9 en alto y el pin 10 en bajo para hacer que el motor gire en sentido horario y establece la variable **flag** en 0.

.. image:: img/13_right.png

**4. Sprite de estrella**

Aquí se incluyen 2 eventos.

* Cuando el sprite **star** recibe el mensaje transmitido gira, determina el valor de bandera; si bandera es 1, gira 10 grados a la izquierda, de lo contrario, al revés. Como está en [FOREVER], seguirá girando.
* Cuando se hace clic en este sprite, establece ambos pines del motor en alto para hacer que deje de girar y detener los otros scripts en este sprite.

.. image:: img/13_broadcast.png
