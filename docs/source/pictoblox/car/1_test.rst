.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_test:

3.1 Prueba el Coche
======================

Aquí, aprenderás cómo escribir scripts para hacer que el coche avance, pero necesitarás referirte a :ref:`car_projects` para ensamblar el coche y obtener una comprensión básica del mismo.

Pero antes de comenzar el proyecto, necesitas conocer los pasos para usar PictoBlox en :ref:`upload_mode`.

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
    *   - :ref:`cpn_l9110` 
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-

Construye el Circuito
-----------------------

El módulo controlador de motor L9110 es un módulo controlador de motor de alta potencia para conducir motores DC y motores paso a paso. El módulo L9110 puede controlar hasta 4 motores DC, o 2 motores DC con control de dirección y velocidad.


Conecta los cables entre el módulo L9110 y la placa R3 según el diagrama a continuación.


.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - Módulo L9110
      - Placa R3
      - Motor
    * - A-1B
      - 5
      - 
    * - A-1A
      - 6
      - 
    * - B-1B(B-2A)
      - 9
      - 
    * - B-1A
      - 10
      - 
    * - OB(B)
      - 
      - Cable negro del motor derecho
    * - OA(B)
      - 
      - Cable rojo del motor derecho
    * - OB(A)
      - 
      - Cable negro del motor izquierdo
    * - OA(A)
      - 
      - Cable rojo del motor izquierdo

.. image:: img/car_2.png
    :width: 800

Programación
-------------------

**1. Haz que el coche avance**

Basado en el cableado anterior, sabemos que los pines 5 y 6 se utilizan para controlar la rotación del motor derecho y los pines 9 y 10 para la rotación del motor izquierdo. Ahora escribamos un script para hacer que el coche avance.

Después de seleccionar la placa como Arduino Uno, cambia a :ref:`upload_mode` y escribe el script según el siguiente diagrama.

.. image:: img/1_test1.png

Haz clic en el botón **Upload Code** para subir el código a la placa R3. Cuando se complete, verás que los dos motores del coche se mueven hacia adelante (si pones el coche en el suelo, se moverá hacia adelante en línea recta, pero puede que el coche vaya en curva porque la velocidad de los dos motores es un poco diferente).

Si no ambos giran hacia adelante, pero ocurren las siguientes situaciones, necesitas reajustar el cableado de los dos motores.

* Si ambos motores giran hacia atrás al mismo tiempo (el motor izquierdo gira en el sentido de las agujas del reloj, el motor derecho gira en sentido contrario), intercambia el cableado de los motores izquierdo y derecho al mismo tiempo, OA(A) y OB(A) se intercambian, OA(B) y OB(B) se intercambian.
* Si el motor izquierdo gira hacia atrás (rotación en el sentido de las agujas del reloj), intercambia el cableado de OA(B) y OB(B) del motor izquierdo.
* Si el motor derecho gira hacia atrás (rotación en sentido contrario a las agujas del reloj), intercambia el cableado de OA(A) y OB(A) del motor derecho.

**2. Creación de bloque**

Para que el script sea más limpio y fácil de usar, aquí ponemos todos los bloques que controlan el movimiento hacia adelante en un bloque, y cuando se usa, simplemente llama a este bloque directamente.

Haz clic en **Make a Block** en la paleta **My Blocks**.

.. image:: img/1_test31.png

Introduce el nombre del bloque - **forward** y marca **Add an input**, establece el nombre de la entrada a **speed**.

.. image:: img/1_test32.png

Arrastra y suelta los bloques que controlan el avance de los coches en **forward**, ten en cuenta que necesitas añadir el parámetro - **speed** a los pines 6 y 9.

.. image:: img/1_test33.png

Llama al bloque creado en el bloque [Forward] - **forward**. En el modo de subida, el bloque [When Arduino Uno starts up] debe añadirse al principio.

* El rango de velocidad de rotación del motor es 100 ~ 255.

.. image:: img/1_test3.png
    
**3. Ajustando la velocidad de los motores**

Dado que puede haber una ligera diferencia en la velocidad de los 2 motores, lo que resulta en que el coche no pueda moverse en línea recta, podemos dar a los motores izquierdo y derecho diferentes velocidades para mantener el coche moviéndose en línea recta tanto como sea posible.

Dado que mi coche se mueve lentamente hacia el frente derecho, aquí reduzco la velocidad del motor izquierdo.

.. image:: img/1_test2.png
