.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_fishing:

2.19 JUEGO - Pesca
===========================

Aquí, jugamos un juego de pesca con un botón.

Cuando el script está en ejecución, los peces nadan de izquierda a derecha en el escenario. Debes presionar el botón cuando el pez esté casi cerca del anzuelo (se recomienda presionarlo por más tiempo) para atrapar al pez, y el número de peces capturados se registrará automáticamente.

.. image:: img/18_fish.png

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Construye el Circuito
-----------------------

El botón es un dispositivo de 4 pines, ya que el pin 1 está conectado al pin 2 y el pin 3 al pin 4. Cuando se presiona el botón, los 4 pines se conectan, cerrando así el circuito.

.. image:: img/5_buttonc.png

Construye el circuito según el siguiente diagrama.

* Conecta uno de los pines en el lado izquierdo del botón al pin 12, que está conectado a un resistor pull-down y un condensador de 0.1uF (104) (para eliminar el jitter y emitir un nivel estable cuando el botón esté en funcionamiento).
* Conecta el otro extremo del resistor y del condensador a GND, y uno de los pines del lado derecho del botón a 5V.

.. image:: img/circuit/button_circuit.png

Programación
------------------

Primero necesitamos seleccionar un fondo **Underwater**, luego añadir un sprite **Fish** y hacer que nade de un lado a otro en el escenario. Luego dibuja un sprite **Fishhook** y contrólalo con un botón para comenzar a pescar. Cuando el sprite **Fish** toca el sprite **Fishhook** en estado de anzuelo (se vuelve rojo), será atrapado.

**1. Añadir un fondo**

Usa el botón **Choose a Backdrop** para añadir un fondo **Underwater**.

.. image:: img/18_under.png

**2. Sprite Anzuelo**

El sprite **Fishhook** normalmente permanece bajo el agua en estado amarillo; cuando se presiona el botón, está en estado de pesca (rojo) y se mueve sobre el escenario.

No hay un sprite **Fishhook** en Pictoblox, podemos modificar el sprite **Glow-J** para que parezca un anzuelo.

* Añade el sprite **Glow-J** a través de **Choose a Sprite**.

.. image:: img/18_hook.png

* Ahora ve a la página **Costumes** del sprite **Glow-J**, selecciona el relleno Cyan en la pantalla y elimínalo. Luego cambia el color de la J a rojo y también reduce su ancho. El punto más importante a tener en cuenta es que necesitas tener la parte superior justo en el punto central.

.. image:: img/18_hook1.png

* Usa la **Line tool** para dibujar una línea tan larga como sea posible desde el punto central hacia arriba (línea fuera del escenario). Ahora que el sprite está dibujado, establece el nombre del sprite a **Fishhook** y muévelo a la posición correcta.

.. image:: img/18_hook2.png

* Cuando se hace clic en la bandera verde, establece el efecto de color del sprite a 30 (amarillo), y establece su posición inicial.

.. image:: img/18_hook3.png


* Si se presiona el botón, establece el efecto de color a 0 (rojo, comienza el estado de pesca), espera 0.1 y luego mueve el sprite **Fishhook** a la parte superior del escenario. Suelta el botón y deja que el **Fishhook** regrese a su posición inicial.

.. image:: img/18_hook4.png

**3. Sprite Pez**

El efecto que se busca lograr con el sprite **fish** es moverse de izquierda a derecha en el escenario, y cuando se encuentra con un sprite **Fishhook** en estado de pesca, se encoge y se mueve a una posición específica y luego desaparece, y luego clona un nuevo sprite **fish** de nuevo.

* Ahora añade el sprite **fish** y ajusta su tamaño y posición.

.. image:: img/18_fish1.png

* Crea una variable **score** para almacenar el número de peces capturados, oculta este sprite y clónalo.

.. image:: img/18_fish2.png


* Muestra el clon del sprite **fish**, cambia su disfraz y finalmente establece la posición inicial.


.. image:: img/18_fish3.png


* Haz que el clon del sprite **fish** se mueva de izquierda a derecha y rebote cuando toque el borde.


.. image:: img/18_fish4.png


* El sprite **fish** (del clon) no reaccionará cuando pase por el sprite **Fishhook**; cuando toque el sprite **Fishhook** en estado de pesca (se vuelve rojo), será capturado, en cuyo punto la puntuación (variable puntuación) +1, y también mostrará una animación de puntuación (encoge un 40%, se mueve rápidamente a la posición del marcador y desaparece). Al mismo tiempo, se crea un nuevo pez (un nuevo clon del sprite pez) y el juego continúa.

.. note::
    
    Necesitas hacer clic en el área de color en el bloque [Touch color], y luego seleccionar la herramienta cuentagotas para recoger el color rojo del sprite **Fishhook** en el escenario. Si eliges un color arbitrariamente, este bloque [Touch color] no funcionará.

.. image:: img/18_fish5.png
