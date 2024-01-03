.. _sh_parrot:

2.17 JUEGO - Loro Saltarín
==============================

Aquí utilizamos el módulo ultrasónico para jugar al juego del loro saltarín.

Después de ejecutar el script, el bambú verde se moverá lentamente de derecha a izquierda a una altura aleatoria. Ahora coloca tu mano sobre el módulo ultrasónico, si la distancia entre tu mano y el módulo es menor de 10, el loro volará hacia arriba, de lo contrario caerá hacia abajo.
Debes controlar la distancia entre tu mano y el módulo ultrasónico para que el Loro pueda evitar el bambú verde (Paddle). Si lo toca, el juego termina.

.. image:: img/15_parrot.png

Componentes Necesarios
------------------------

Para este proyecto, necesitaremos los siguientes componentes.

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

También puedes comprarlos por separado en los siguientes enlaces.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

Construye el Circuito
-----------------------

Un módulo sensor ultrasónico es un instrumento que mide la distancia a un objeto utilizando ondas de sonido ultrasónicas.
Tiene dos sondas. Una para enviar las ondas ultrasónicas y la otra para recibir las ondas y transformar el tiempo de envío y recepción en una distancia, detectando así la distancia entre el dispositivo y un obstáculo.

Ahora construye el circuito según el siguiente diagrama.

.. image:: img/circuit/ultrasonic_circuit.png

Programación
------------------

El efecto que queremos lograr es utilizar el módulo ultrasónico para controlar la altura de vuelo del sprite **Parrot**, mientras evita el sprite **Paddle**.

**1. Añadir un sprite**

Elimina el sprite por defecto y utiliza el botón **Choose a Sprite** para añadir el sprite **Parrot**. Ajusta su tamaño al 50% y colócalo en el centro izquierdo.

.. image:: img/15_sprite.png

Ahora añade el sprite **Paddle**, configura su tamaño al 150%, su ángulo a 180, y mueve su posición inicial a la esquina superior derecha.

.. image:: img/15_sprite1.png

Ve a la página **Costumes** del sprite **Paddle** y elimina el Contorno.

.. image:: img/15_sprite2.png

**2. Programación para el Sprite Loro**

Ahora programa el sprite **Parrot**, que está en vuelo y la altitud del vuelo es determinada por la distancia de detección del módulo ultrasónico.

* Cuando se hace clic en la bandera verde, cambia el disfraz cada 0.2s para que siempre esté en vuelo.

.. image:: img/15_parr1.png

* Lee el valor del módulo ultrasónico y almacénalo en la variable **distancia** después de redondearlo con el bloque [round].

.. image:: img/15_parr2.png

* Si la distancia de detección ultrasónica es menor a 10cm, aumenta la coordenada y en 50, el sprite **Parrot** volará hacia arriba. De lo contrario, el valor de la coordenada y disminuye en 40, **Parrot** caerá.

.. image:: img/15_parr3.png

* Si el sprite **Parrot** toca el sprite **Paddle**, el juego termina y el script deja de ejecutarse.

.. image:: img/15_parr4.png


**3. Programación para el Sprite Paleta**

Ahora escribe el script para el sprite **Paddle**, que necesita aparecer aleatoriamente en el escenario.

* Oculta el sprite **Paddle** cuando se hace clic en la bandera verde y clónalo al mismo tiempo. El bloque [`create clone of <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_] es un bloque de control y de pila. Crea un clon del sprite en el argumento. También puede clonar el sprite en el que se ejecuta, creando clones de clones, de manera recursiva.

.. image:: img/15_padd.png

* Cuando **Paddle** se presenta como un clon, su posición es 220 (extremo derecho) para la coordenada x y su coordenada y entre (-125 y 125) aleatoria (altura aleatoria).

.. image:: img/15_padd1.png

* Utiliza el bloque [repeat] para hacer que su valor de coordenada x disminuya lentamente, para que puedas ver el clon del sprite **Paddle** moverse lentamente de derecha a izquierda hasta que desaparezca.

.. image:: img/15_padd2.png

* Vuelve a clonar un nuevo sprite **Paddle** y elimina el clon anterior.

.. image:: img/15_padd3.png
