.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_shooting:

2.13 JUEGO - Disparos
========================

¿Has visto esos juegos de disparos en la televisión? Cuanto más cerca un concursante dispare una bala al blanco cerca del centro, mayor será su puntuación.

Hoy también estamos haciendo un juego de disparos en Scratch. En el juego, permite que la Mira dispare lo más cerca posible del centro para obtener una puntuación más alta.

Haz clic en la bandera verde para empezar. Utiliza el módulo de Evitación de Obstáculos para disparar una bala.

.. image:: img/14_shooting.png

Aprenderás
---------------------

- Cómo funciona el módulo de Evitación de Obstáculos y su rango de ángulo
- Pintar diferentes sprites
- Tocar colores

Componentes Necesarios
-------------------------

En este proyecto, necesitamos los siguientes componentes.

Definitivamente es conveniente comprar un kit completo, aquí está el enlace:

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
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

Construir el Circuito
-----------------------

El módulo de evitación de obstáculos es un sensor de proximidad infrarrojo ajustable en distancia cuya salida es normalmente alta y baja cuando se detecta un obstáculo.

Ahora construye el circuito según el diagrama a continuación.

.. image:: img/circuit/avoid_circuit.png

Programación
------------------

**1. Pintar el sprite de la Mira**

Elimina el sprite predeterminado, selecciona el botón **Sprite** y haz clic en **Paint**. Aparecerá un sprite en blanco **Sprite1** y nómbralo **Crosshair**.

.. image:: img/14_shooting0.png

Ve a la página de **Crosshair** del sprite **Costumes**. Haz clic en la herramienta **Circle**, elimina el color de relleno y establece el color y el ancho del contorno.

.. image:: img/14_shooting02.png

Ahora dibuja un círculo con la herramienta **Circle**. Después de dibujar, puedes hacer clic en la herramienta **Select** y mover el círculo para que el punto original se alinee con el centro del lienzo.

.. image:: img/14_shooting03.png

Utilizando la herramienta **Line**, dibuja una cruz dentro del círculo.

.. image:: img/14_shooting033.png

**Pintar el sprite de la Diana**

Crea un nuevo sprite llamado **Target**.

.. image:: img/14_shooting01.png

Ve a la página de Disfraces del sprite **Target**, haz clic en la herramienta **Circle**, selecciona un color de relleno y elimina el contorno y pinta un círculo grande.

.. image:: img/14_shooting05.png

Utiliza el mismo método para dibujar círculos adicionales, cada uno con un color diferente, y puedes usar las herramientas **Forward** o **Backbard** para cambiar la posición de los círculos superpuestos. Ten en cuenta que también necesitas seleccionar la herramienta para mover los círculos, de modo que el origen de todos los círculos y el centro del lienzo estén alineados.

.. image:: img/14_shooting04.png

**3. Añadir un fondo**

Añade un fondo adecuado que preferiblemente no tenga demasiados colores y no coincida con los colores en el sprite **Target**. Aquí he elegido el fondo **Wall1**.

.. image:: img/14_shooting06.png

**4. Programar el sprite de la Mira**

Establece la posición y el tamaño aleatorios del sprite **Crosshair**, y haz que se mueva al azar.

.. image:: img/14_shooting4.png

Cuando se coloca una mano frente al módulo de evitación de obstáculos, este emitirá un nivel bajo como señal de transmisión.

.. image:: img/14_shooting5.png

Cuando se recibe el mensaje de **shooting**, el sprite deja de moverse y se encoge lentamente, simulando así el efecto de un disparo.

.. image:: img/14_shooting6.png

Utiliza el bloque [Touch color ()] para determinar la posición del disparo.

.. image:: img/14_shooting7.png

Cuando el disparo esté dentro del círculo amarillo, se reportará 10.

.. image:: img/14_shooting8.png

Utiliza el mismo método para determinar la posición del disparo, si no se coloca en el sprite **Target**, significa que está fuera del círculo.

.. image:: img/14_shooting9.png
