.. _sh_protect_heart:

2.21 JUEGO - Protege tu Corazón
=====================================

En este proyecto, hagamos un juego que ponga a prueba la velocidad de reacción.

En el escenario, hay un corazón protegido en una caja rectangular, y hay flechas volando hacia este corazón desde cualquier posición en el escenario. El color de la flecha alternará entre negro y blanco al azar y la flecha volará más y más rápido.

Si el color de la caja rectangular y el color de la flecha son iguales, la flecha es bloqueada afuera y se añade 1 nivel; si el color de ambos no es el mismo, la flecha atravesará el corazón y el juego terminará.

Aquí el color de la caja rectangular es controlado por el módulo de Seguimiento de Línea. Cuando el módulo se coloca sobre una superficie negra (una superficie que refleja), el color de la caja rectangular es negro, de lo contrario es blanco.

Así que necesitas decidir si colocar el módulo de Seguimiento de Línea sobre una superficie blanca o negra según el color de la flecha.

.. image:: img/22_heart.png

Componentes Necesarios
------------------------

Para este proyecto, necesitamos los siguientes componentes.

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
    *   - :ref:`cpn_track` 
        - |link_track_buy|


Construye el Circuito
-----------------------

Este es un módulo digital de Seguimiento de Línea, cuando detecta una línea negra, emite 1; cuando detecta una línea blanca, emite un valor de 0. Además, puedes ajustar su distancia de detección a través del potenciómetro en el módulo.

Ahora construye el circuito según el diagrama a continuación.

.. image:: img/circuit/linetrack_circuit.png

.. note::

    Antes de empezar el proyecto, necesitas ajustar la sensibilidad del módulo.

    Conecta el cableado según el diagrama anterior, luego enciende la placa R3 (ya sea directamente en el cable USB o el cable de botón de batería de 9V), sin subir el código.

    Ahora pega una cinta eléctrica negra en el escritorio, coloca el módulo de Seguimiento de Línea a una altura de 2 cm del escritorio.

    Con el sensor mirando hacia abajo, observa el LED de señal en el módulo para asegurarte de que se ilumine en la mesa blanca y se apague en la cinta negra.

    Si no es así, necesitas ajustar el potenciómetro en el módulo, para que pueda hacer el efecto anterior.

Programación
------------------

Aquí necesitamos crear 3 sprites: **Heart**, **Square Box** y **Arrow1**.

* **Heart**: se detiene en el medio del escenario, si es tocado por el sprite **Arrow1**, el juego termina.
* **Square Box**: Hay dos tipos de disfraces, negro y blanco, y cambiará de disfraz según el valor del módulo de Seguimiento de Línea.
* **Arrow**: vuela hacia el medio del escenario desde cualquier posición en negro/blanco; si su color coincide con el color del sprite **Square Box**, es bloqueada y vuelve a volar hacia el centro del escenario desde una posición aleatoria; si su color no coincide con el color del sprite **Square Box**, pasa a través del sprite **Heart** y el juego termina.

**1. Añadir sprite Caja Cuadrada**

Dado que el sprite Flecha1 y Caja Cuadrada tienen disfraces blancos, para que se muestren en el escenario, ahora rellena el fondo con un color que puede ser cualquier color excepto negro, blanco y rojo.

* Haz clic en **Backdrop1** para ir a su página **Backdrops**.
* Selecciona el color que quieras para rellenar.
* Usa la herramienta **Rectangle** para dibujar un rectángulo del mismo tamaño que el tablero de dibujo.

.. image:: img/22_heart0.png

Elimina el sprite por defecto, usa el botón **Choose a Sprite** para añadir el sprite **Square Box**, y ajusta sus coordenadas x e y a (0, 0).

.. image:: img/22_heart1.png

Ve a la página **Costumes** del sprite **Square Box** y establece los disfraces en negro y blanco.

* Haz clic en la herramienta de selección
* Selecciona el rectángulo en el lienzo
* Selecciona el color de relleno como negro
* y nombra el disfraz **Black**

.. image:: img/22_heart2.png

Selecciona el segundo disfraz, establece el color de relleno en blanco, nómbralo Blanco y elimina el resto del disfraz.

.. image:: img/22_heart3.png

**2. Añadir sprite Corazón**

También añade un sprite **Heart**, ajusta su posición a (0, 0) y reduce su tamaño para que parezca estar ubicado dentro de la Caja Cuadrada.

.. image:: img/22_heart5.png

En la página **Costumes**, ajusta el disfraz de corazón morado para que parezca estar roto.

.. image:: img/22_heart6.png

**3. Añadir sprite Flecha1**

Añade un sprite **Arrow1**.

.. image:: img/22_heart7.png

En la página **Costumes**, mantén y copia el disfraz que mira hacia la derecha y establece su color en negro y blanco.

.. image:: img/22_heart8.png

**4. Programación para el sprite Caja Cuadrada**

Regresa a la página **Blocks** y programa el sprite **Square Box**.

* Así que cuando el valor del pin digital 2 (módulo de Seguimiento de Línea) sea 1 (línea negra detectada), cambia el disfraz a **Black**.
* De lo contrario, cambia el disfraz a **White**.

.. image:: img/22_heart4.png


**5. Programación para el sprite Corazón**

El sprite **Heart** está protegido dentro de **Square Box**, y por defecto tiene un disfraz rojo. Cuando el sprite Flecha1 lo toca, el juego termina.

.. image:: img/22_heart9.png

**6. Programación para el sprite Flecha1**

Haz que el sprite **Arrow1** se oculte y cree un clon cuando se haga clic en la bandera verde.

.. image:: img/22_heart10.png

Crea un bloque [init] para inicializar la posición, orientación y color del sprite **Arrow1**.

Aparece en una ubicación aleatoria, y si la distancia entre él y el sprite **Heart** es menor de 200, se mueve hacia afuera hasta que la distancia sea mayor de 200.

.. image:: img/22_heart11.png

Establece su dirección hacia el sprite **Heart**.

.. image:: img/22_heart12.png

Haz que su color alterne aleatoriamente entre negro/blanco.

* Si la variable color es 0, cambia el disfraz a **White**.
* Si la variable color es 1, cambia el disfraz a **Black**.

.. image:: img/22_heart14.png

Ahora haz que empiece a moverse, se moverá más rápido a medida que el valor de la variable **level** aumente.

.. image:: img/22_heart13.png

Ahora establece su efecto de colisión con el sprite **Square Box**.

* Si el sprite **Arrow1** y el sprite **Square Box** tienen el mismo color (que se modificará según el valor del módulo de Seguimiento de Línea), ya sea negro o blanco, se crea un nuevo clon y el juego continúa.
* Si sus colores no coinciden, el sprite **Arrow1** continúa moviéndose y el juego termina cuando golpea al sprite **Heart**.

.. image:: img/22_heart15.png

.. note::
    Los dos bloques [touch color()] necesitan recoger los disfraces negro/blanco de Caja Cuadrada por separado.

    .. image:: img/22_heart16.png

