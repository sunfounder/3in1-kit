.. _sh_light_alarm:

2.8 Reloj Despertador Luminoso
=================================

En la vida, hay varios tipos de relojes despertadores. Ahora hagamos un reloj despertador controlado por la luz. Cuando llega la mañana, el brillo de la luz aumenta y este reloj despertador controlado por la luz te recordará que es hora de levantarse.

.. image:: img/10_clock.png

Aprenderás
---------------------

- Principio de funcionamiento del fotorresistor
- Detener la reproducción de sonido y detener la ejecución de scripts

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_photoresistor` 
        - |link_photoresistor_buy|

Construir el Circuito
-----------------------

Un fotorresistor o célula fotoeléctrica es una resistencia variable controlada por la luz. La resistencia de un fotorresistor disminuye con el aumento de la intensidad de luz incidente.

Construye el circuito según el siguiente diagrama.

Conecta un extremo del fotorresistor a 5V, el otro extremo a A0, y conecta una resistencia de 10K en serie con GND en este extremo.

Así que cuando la intensidad de la luz aumenta, la resistencia del fotorresistor disminuye, la división de voltaje de la resistencia de 10K aumenta, y el valor obtenido por A0 se hace más grande.

.. image:: img/circuit/photoresistor_circuit.png

Programación
------------------

**1. Seleccionar un sprite**

Elimina el sprite predeterminado, haz clic en el botón **Choose a Sprite** en la esquina inferior derecha del área de sprites, introduce **bell** en la caja de búsqueda y luego haz clic para añadirla.

.. image:: img/10_sprite.png

**2. Leer el valor de A0**

Crea dos variables **before** y **current**. Cuando se hace clic en la bandera verde, lee el valor de A0 y guárdalo en la variable **before** como valor de referencia. En [forever], lee nuevamente el valor de A0, guárdalo en la variable **current**.

.. image:: img/10_reada0.png

**3. Hacer un sonido**

Cuando el valor actual de A0 sea mayor que el anterior en 50, lo que representa que la intensidad de la luz actual es mayor que el umbral, entonces haz que el sprite haga un sonido.

.. image:: img/10_sound.png

**4. Girar el sprite**

Usa [turn block] para hacer que el sprite **bell** gire a la izquierda y a la derecha para lograr el efecto de alarma.

.. image:: img/10_turn.png

**5. detener todo**

Detiene la alarma cuando ha estado sonando durante un tiempo.

.. image:: img/10_stop.png
