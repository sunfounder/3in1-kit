.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_eat_apple:

2.16 JUEGO - Comer Manzana
==============================

En este proyecto, jugamos un juego que usa un botón para controlar a un Escarabajo para que coma una manzana.

Cuando se hace clic en la bandera verde, presiona el botón y el Escarabajo girará; presiona el botón de nuevo y el Escarabajo se detendrá, avanzando en ese ángulo. Debes controlar el ángulo del Escarabajo para que avance sin tocar la línea negra en el mapa hasta que coma la manzana. Si toca la línea negra, el juego termina.

.. image:: img/14_apple.png

Componentes Necesarios
------------------------

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

Construir el Circuito
-----------------------

El botón es un dispositivo de 4 pines, ya que el pin 1 está conectado al pin 2, y el pin 3 al pin 4, cuando se presiona el botón, los 4 pines se conectan, cerrando así el circuito.

.. image:: img/5_buttonc.png

Construye el circuito según el siguiente diagrama.

* Conecta uno de los pines del lado izquierdo del botón al pin 12, que está conectado a una resistencia de pull-down y un condensador de 0.1uF (104) (para eliminar el jitter y emitir un nivel estable cuando el botón esté en funcionamiento).
* Conecta el otro extremo de la resistencia y el condensador a GND, y uno de los pines del lado derecho del botón a 5V.

.. image:: img/circuit/button_circuit.png

Programación
------------------

El efecto que queremos lograr es usar el botón para controlar la dirección del sprite **Beetle** para avanzar y comer la manzana sin tocar la línea negra en el fondo **Maze**, lo que cambiará el fondo cuando se coma la manzana.

Ahora añade los fondos y sprites relevantes.

**1. Añadir fondos y sprites**

Añade un fondo **Maze** a través del botón **Choose a backdrop**.

.. image:: img/14_backdrop.png

Elimina el sprite por defecto, luego selecciona el sprite **Beetle**.

.. image:: img/14_sprite.png

Coloca el sprite **Beetle** en la entrada del fondo **Maze**, recordando los valores de las coordenadas x, y en este punto, y redimensiona el sprite al 40%.

.. image:: img/14_sprite1.png

**2. Dibujar un fondo**

Ahora es el momento de dibujar simplemente un fondo con el personaje ¡GANAR! apareciendo en él.

Primero haz clic en la miniatura del fondo para ir a la página **Backdrops** y haz clic en el fondo en blanco1.

.. image:: img/14_paint_back.png
    :width: 800

Ahora comienza a dibujar, puedes referirte a la imagen de abajo para dibujar, o puedes dibujar un fondo propio, siempre y cuando la expresión sea de victoria.

* Utilizando la herramienta **Circle**, dibuja una elipse con el color establecido en rojo y sin contorno.
* Luego usa la herramienta **Text**, escribe el personaje \"WIN!\", establece el color del personaje en negro, y ajusta el tamaño y la posición del personaje.
* Nombra el fondo como **Win**.

.. image:: img/14_win.png

**3. Programación para el fondo**

El fondo debe cambiarse a **Maze** cada vez que comienza el juego.

.. image:: img/14_switchback.png

**4. Escribir scripts para el sprite Escarabajo**

Ahora escribe un script para el sprite **Beetle** para poder avanzar y cambiar de dirección bajo el control de un botón. El flujo de trabajo es el siguiente.

* Cuando se hace clic en la bandera verde, establece el ángulo del **Beetle** en 90, y la posición en (-134, -134), o reemplázalo con el valor de coordenada de tu propia posición colocada. Crea la variable **flag** y establece el valor inicial en -1.

.. image:: img/14_bee1.png

A continuación, en el bloque [forever], se utilizan cuatro bloques [if] para determinar varios escenarios posibles.

* Si la clave es 1 (presionada), usa el bloque [`mod <https://en.scratch-wiki.info/wiki/Boolean_Block>`_] para alternar el valor de la variable **flag** entre 0 y 1 (alternando entre 0 para esta pulsación y 1 para la siguiente).

.. image:: img/14_bee2.png

* Si bandera=0 (esta pulsación de tecla), deja que el sprite **Beetle** gire en el sentido de las agujas del reloj. Luego determina si bandera es igual a 1 (tecla presionada de nuevo), el sprite **Beetle** se mueve hacia adelante. De lo contrario, sigue girando en el sentido de las agujas del reloj.

.. image:: img/14_bee3.png

* Si el sprite Escarabajo toca negro (la línea negra en el fondo **Maze**), el juego termina y el script deja de ejecutarse.

.. note::
    
    Necesitas hacer clic en el área de color en el bloque [Touch color], y luego seleccionar la herramienta gotero para recoger el color de la línea negra en el escenario. Si eliges un negro arbitrariamente, este bloque [Touch color] no funcionará.


.. image:: img/14_bee5.png

* Si el Escarabajo toca rojo (También usa la herramienta pajita para recoger el color rojo de la manzana), el fondo cambiará a **Win**, lo que significa que el juego tiene éxito y detiene la ejecución del script.


.. image:: img/14_bee4.png

