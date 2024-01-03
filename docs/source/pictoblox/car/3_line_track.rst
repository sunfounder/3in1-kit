.. _sh_line:

3.3 Seguir la línea
======================

El coche está equipado con un módulo de Seguimiento de Línea, que se puede utilizar para hacer que el coche siga la línea negra.

Antes de comenzar el proyecto, necesitas construir un mapa curvo con cinta de línea negra, el ancho de línea recomendado es entre 0.8-1.5cm y el ángulo de la curva no debe ser menor de 90 grados.

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
    *   - :ref:`cpn_l9110` 
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_track`
        - |link_track_buy|

Construye el Circuito
-----------------------

Este es un módulo digital de Seguimiento de Línea, cuando detecta una línea negra, emite 1; cuando detecta una línea blanca, emite un valor de 0. Además, puedes ajustar su distancia de detección a través del potenciómetro en el módulo.

Construye el circuito según el siguiente diagrama.

.. list-table:: 

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

Ajusta el Módulo
-----------------------

Antes de comenzar el proyecto, necesitas ajustar la sensibilidad del módulo.

Conecta el cableado según el diagrama anterior, luego enciende la placa R3 (ya sea directamente en el cable USB o el cable de botón de batería de 9V), sin subir el código.

Pega una cinta eléctrica negra en la mesa y coloca el carrito sobre ella.

Observa el LED de señal en el módulo para asegurarte de que se ilumine en la mesa blanca y se apague en la cinta negra.

Si no, necesitas ajustar el potenciómetro en el módulo, para que pueda hacer el efecto anterior.

.. image:: img/line_track_cali.JPG


Programación
--------------

Ahora crea 2 bloques que permitan al coche moverse ya sea hacia el frente izquierdo o hacia el frente derecho.

**1. Mover hacia el frente izquierdo**

Cuando el motor derecho se gira en sentido horario y el motor izquierdo se deja sin mover, el coche se mueve ligeramente hacia el frente izquierdo.

.. image:: img/3_forward_left.png

**2. Mover hacia el frente derecho**

De manera similar, cuando el motor izquierdo se gira en sentido antihorario y el motor derecho no se mueve, el coche se mueve ligeramente hacia la derecha.

.. image:: img/3_forward_left.png

**3. Seguimiento de línea**

Lee el valor del módulo de Seguimiento de Línea, si es 1, significa que se ha detectado una línea negra, deja que el coche se mueva hacia adelante a la izquierda, de lo contrario se mueve hacia adelante a la derecha.

.. image:: img/3_follow.png

Después de subir el código a la placa R3, alinea el módulo de Seguimiento de Línea bajo el coche con la línea negra, y verás que el coche sigue la línea.
