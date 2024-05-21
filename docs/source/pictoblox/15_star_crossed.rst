.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_star_crossed:

2.15 JUEGO - Estrellas Cruzadas
=================================

En los próximos proyectos, jugaremos algunos mini-juegos divertidos en PictoBlox.

Aquí utilizamos el módulo Joystick para jugar al juego Estrellas Cruzadas.

Una vez que se ejecute el script, las estrellas aparecerán aleatoriamente en el escenario, debes usar el Joystick para controlar la Nave Espacial y evitar las estrellas, si las tocas, el juego terminará.

.. image:: img/16_rocket.png

Aprenderás
---------------------

- Cómo funciona el módulo Joystick
- Establecer las coordenadas x e y del sprite

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - \-

Construir el Circuito
-----------------------

Un joystick es un dispositivo de entrada compuesto por una palanca que pivota en una base e informa su ángulo o dirección al dispositivo que está controlando. Los joysticks son a menudo utilizados para controlar videojuegos y robots.

Para comunicar un rango completo de movimiento al ordenador, un joystick necesita medir la posición de la palanca en dos ejes: el eje X (de izquierda a derecha) y el eje Y (de arriba abajo).

Las coordenadas de movimiento del joystick se muestran en la siguiente figura.

.. note::

    * La coordenada x es de izquierda a derecha, el rango es 0-1023.
    * La coordenada y es de arriba abajo, el rango es 0-1023.

.. image:: img/16_joystick.png


Ahora construye el circuito según el siguiente diagrama.

.. image:: img/circuit/joystick_circuit.png

Programación
------------------
El objetivo del script completo es lograr que, al hacer clic en la bandera verde, el sprite **Stars** se mueva en una curva en el escenario y necesitas usar el joystick para mover la **Rocketship**, de modo que no sea tocada por el sprite **Star**.

**1. Añadir sprites y fondos**

Elimina el sprite por defecto y usa el botón **Choose a Sprite** para añadir el sprite **Rocketship** y el sprite **Star**. Ten en cuenta que el tamaño del sprite **Rocket** se establece al 50%.

.. image:: img/16_sprite.png

Ahora añade el fondo **Stars** mediante **Choose a Backdrop**.

.. image:: img/16_sprite1.png

**2. Programación para la Nave Espacial**

El sprite **Rocketship** debe lograr el efecto de aparecer en una posición aleatoria y luego ser controlado por el joystick para moverlo arriba, abajo, izquierda y derecha.

El flujo de trabajo es el siguiente.

* Al hacer clic en la bandera verde, haz que el sprite vaya a una ubicación aleatoria y crea 2 variables **x** e **y**, que almacenan los valores leídos de A0 (VRX del Joystick) y A1 (VRY del Joystick), respectivamente. Puedes ejecutar el script, alternando el joystick hacia arriba y abajo, izquierda y derecha, para ver el rango de valores de x e y.

.. image:: img/16_roc2.png

* El valor de A0 está en el rango de 0-1023 (el medio es aproximadamente 512). Usa ``x-512>200`` para determinar si el Joystick se está moviendo hacia la derecha, y si es así, haz que la coordenada x del sprite sea +30 (para mover el sprite hacia la derecha).

.. image:: img/16_roc3.png

* Si el Joystick se mueve hacia la izquierda (``x-512<-200``), deja que la coordenada x del sprite sea -30 (para mover el sprite hacia la izquierda).

.. image:: img/16_roc4.png

* Dado que la coordenada y del Joystick va de arriba (0) a abajo (1023), y la coordenada y del sprite es de abajo a arriba. Entonces, para mover el Joystick hacia arriba y el sprite hacia arriba, la coordenada y debe ser -30 en el script.

.. image:: img/16_roc5.png

* Si el joystick se inclina hacia abajo, la coordenada y del sprite es +30.


.. image:: img/16_roc6.png

**3. Programación para la Estrella**

El efecto que se busca lograr con el sprite **Star** es aparecer en una ubicación aleatoria, y si golpea a la **Rocketship**, el script deja de ejecutarse y el juego termina.

* Al hacer clic en la bandera verde y que el sprite vaya a una ubicación aleatoria, el bloque [turn degrees] es para hacer que el sprite **Star** avance con un poco de cambio de ángulo para que puedas ver que se está moviendo en una curva y si toca un borde, rebota.

.. image:: img/16_star1.png

* Si el sprite toca el sprite **Rocketship** mientras se mueve, detiene la ejecución del script.

.. image:: img/16_star2.png
