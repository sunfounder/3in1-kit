.. _sh_balloon:

2.14 JUEGO - Inflando el Globo
=========================================

Aquí, jugaremos un juego de inflar globos.

Después de hacer clic en la bandera verde, el globo se hará más y más grande. Si el globo es demasiado grande, explotará; si es demasiado pequeño, caerá; debes juzgar cuándo presionar el botón para hacerlo ascender.

.. image:: img/13_balloon0.png

Aprenderás
---------------------

- Pintar un disfraz para el sprite

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

**1. Añadir un sprite y un fondo**

Elimina el sprite por defecto, haz clic en el botón **Choose a Sprite** en la esquina inferior derecha del área de sprites y selecciona el sprite **Balloon1**.

.. image:: img/13_balloon1.png

Añade un fondo **Boardwalk** a través del botón **Choose a backdrop**, o cualquier otro fondo que te guste.

.. image:: img/13_balloon2.png

**2. Pintar un disfraz para el sprite Balloon1**

Ahora vamos a dibujar un disfraz de efecto explosión para el sprite del globo.

Ve a la página **Costumes** para el sprite **Balloon1**, haz clic en el botón **Choose a Costume** en la esquina inferior izquierda y selecciona **Paint** para mostrar un **Costume** en blanco.

.. image:: img/13_balloon7.png

Selecciona un color y luego usa la herramienta **Brush** para dibujar un patrón.

.. image:: img/13_balloon3.png

Selecciona un color de nuevo, haz clic en la herramienta de Rellenar y mueve el ratón dentro del patrón para llenarlo de color.

.. image:: img/13_balloon4.png

Finalmente, escribe el texto BOOM, para que el disfraz de efecto explosión esté completo.

.. image:: img/13_balloon5.png

**3. Programar el sprite del Globo**

Establece la posición y tamaño iniciales del sprite **Balloon1**.

.. image:: img/13_balloon6.png

Luego, haz que el sprite **Balloon** se haga más grande lentamente.

.. image:: img/13_balloon8.png

Cuando se presiona el botón (valor es 1), el tamaño del sprite **Balloon1** deja de aumentar.

* Cuando el tamaño es menor de 90, caerá (la coordenada y disminuye).
* Cuando el tamaño es mayor de 90 y menor de 120, volará hacia el cielo (la coordenada y aumenta).

.. image:: img/13_balloon9.png

Si no se ha presionado el botón, el globo se hace más grande lentamente y cuando el tamaño supera los 120, explotará (cambia al disfraz de efecto de explosión).

.. image:: img/13_balloon10.png
