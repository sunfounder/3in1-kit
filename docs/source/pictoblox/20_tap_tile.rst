.. _sh_tap_tile:

2.20 JUEGO - No Toques la Baldosa Blanca
==========================================

Estoy seguro de que muchos de vosotros habéis jugado a este juego en vuestros teléfonos móviles. Se juega tocando baldosas negras que aparecen aleatoriamente para sumar puntos, la velocidad se incrementa progresivamente. Si tocas una baldosa blanca o te pierdes una negra, el juego termina.

Ahora usaremos PictoBlox para replicarlo.

Inserta dos módulos de evitación de obstáculos IR verticalmente en el protoboard. Cuando pongas tu mano sobre uno de los módulos IR, aparecerá un punto parpadeante en el escenario, representando que se ha realizado un toque.

Si tocas la baldosa negra, la puntuación aumenta en 1, si tocas la blanca, disminuye en 1.

Necesitas decidir si colocar tu mano sobre el módulo IR de la izquierda o sobre el de la derecha, dependiendo de la posición de la baldosa negra en el escenario.


.. image:: img/21_tile.png

Componentes Necesarios
-------------------------

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|


Construye el Circuito
-----------------------

El módulo de evitación de obstáculos es un sensor de proximidad infrarrojo ajustable en distancia cuya salida es normalmente alta y baja cuando detecta un obstáculo.

Ahora construye el circuito según el diagrama a continuación.

.. image:: img/circuit/2avoid_circuit.png

Programación
------------------

Aquí necesitamos tener 3 sprites: **Tile**, **Left IR** y **Right IR**.

* Sprite **Tile**: se utiliza para lograr el efecto de alternar baldosas negras y blancas hacia abajo. En el móvil, este juego generalmente tiene 4 columnas, aquí solo haremos dos columnas.
* Sprite **Left IR**: se utiliza para lograr el efecto de clic. Cuando el módulo IR izquierdo detecta tu mano, enviará un mensaje - **Left** al sprite **Left IR**, permitiéndole empezar a funcionar. Si toca la baldosa negra en el escenario, la puntuación aumentará en 1, de lo contrario, disminuirá en 1.
* Sprite **Right IR**: Su función es básicamente la misma que **Left IR**, excepto que recibe la información **Right**.

**1. Pintar un sprite Baldosa**.

Elimina el sprite por defecto, pasa el ratón sobre el icono **Add Sprite**, selecciona **Paint** y aparecerá un sprite en blanco y nómbralo **Tile**.

.. image:: img/21_tile1.png

Ve a la página **Costumes** y usa la herramienta **Rectangle** para dibujar un rectángulo.

.. image:: img/21_tile2.png

Selecciona el rectángulo y haz clic en **Copy** -> **Paste** para hacer un rectángulo idéntico, luego mueve los dos rectángulos a una posición alineada.

.. image:: img/21_tile01.png

Selecciona uno de los rectángulos y elige un color de relleno negro.

.. image:: img/21_tile02.png

Ahora selecciona ambos rectángulos y muévelos para que sus puntos centrales coincidan con el centro del lienzo.

.. image:: img/21_tile0.png

Duplica el disfraz1, alternando los colores de relleno de los dos rectángulos. Por ejemplo, el color de relleno del disfraz1 es blanco a la izquierda y negro a la derecha, y el color de relleno del disfraz2 es negro a la izquierda y blanco a la derecha.

.. image:: img/21_tile3.png

**2. Programación del sprite Baldosa**

Ahora regresa a la página **Blocks** y establece la posición inicial del sprite **Tile** para que esté en la parte superior del escenario.

.. image:: img/21_tile4.png

Crea una variable - **blocks** y dale un valor inicial para determinar el número de veces que aparecerá el sprite **Tile**. Usa el bloque [repeat until] para hacer que la variable **blocks** disminuya gradualmente hasta que **blocks** sea 0. Durante este tiempo, haz que el sprite **Tile** cambie aleatoriamente de disfraz.

Tras hacer clic en la bandera verde, verás el sprite **Tile** en el escenario cambiando rápidamente de disfraces.

.. image:: img/21_tile5.png

Crea clones del sprite **Tile** mientras la variable **blocks** disminuye, y detén la ejecución del script cuando bloques sea 0. Aquí se usan dos bloques [wait () seconds], el primero para limitar el intervalo entre los clones de **Tile's** y el segundo para permitir que la variable bloques disminuya a 0 sin detener el programa inmediatamente, dándole al último sprite baldosa tiempo suficiente para moverse.

.. image:: img/21_tile6.png

Ahora programa el clon del sprite **Tile** para que se mueva lentamente hacia abajo y lo elimine cuando alcance la parte inferior del escenario. El cambio en la coordenada y afecta la velocidad de caída, cuanto mayor sea el valor, más rápida será la velocidad de caída.

.. image:: img/21_tile7.png

Oculta el cuerpo y muestra el clon.

.. image:: img/21_tile8.png

**3. Leer los valores de los 2 módulos IR**

En el fondo, lee los valores de los 2 módulos IR y realiza las acciones correspondientes.

* Si el módulo IR de evitación de obstáculos izquierdo detecta tu mano, emite un mensaje - **left**.
* Si el módulo IR de evitación de obstáculos derecho detecta tu mano, emite un mensaje - **right**.

.. image:: img/21_tile9.png

**4. Sprite IR Izquierdo**

De nuevo, pasa el ratón sobre el icono **Add sprite** y selecciona **Paint** para crear un nuevo sprite llamado **Left IR**.

.. image:: img/21_tile10.png

Ve a la página **Costumes** del sprite **Left IR**, selecciona un color de relleno (cualquier color fuera de negro y blanco) y dibuja un círculo.

.. image:: img/21_tile11.png

Ahora comienza a programar el sprite **Left IR**. Cuando se reciba el mensaje - **left** (el módulo receptor IR de la izquierda detecta un obstáculo), determina si se ha tocado el bloque negro del sprite **Tile**, y si es así, haz que la variable **count** aumente en 1, de lo contrario disminúyela en 1.

.. image:: img/21_tile12.png

.. note::

    Necesitas hacer que el sprite **Tile** aparezca en el escenario y luego absorber el color del bloque negro en el sprite **Tile**.

    .. image:: img/21_tile13.png

Ahora hagamos el efecto de detección (aumento y disminución) para **Left IR**.

.. image:: img/21_tile14.png

Haz que el sprite **Left IR** se oculte cuando se haga clic en la bandera verde, se muestre cuando se reciba el mensaje - **left**, y finalmente se oculte de nuevo.

.. image:: img/21_tile15.png

**5. Sprite IR Derecho**

Copia el sprite **Left IR** y renómbralo a **Right IR**.

.. image:: img/21_tile16.png

Luego cambia el mensaje recibido a - **right**.

.. image:: img/21_tile17.png

Ahora toda la programación está completa y puedes hacer clic en la bandera verde para ejecutar el script.
