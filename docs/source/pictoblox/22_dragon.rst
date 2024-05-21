.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_dragon:

2.22 JUEGO - Matar al Dragón
============================

Aquí, usamos el joystick para jugar a un juego de matar dragones.

Al hacer clic en verde, el dragón flotará arriba y abajo en el lado derecho y soplará fuego intermitentemente. Necesitas usar el joystick para controlar el movimiento de la varita mágica y lanzar ataques estelares al dragón, mientras evitas las llamas que dispara, y finalmente derrotarlo.

.. image:: img/19_dragon.png

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - \-

Construye el Circuito
-----------------------

Un joystick es un dispositivo de entrada que consiste en un palo que pivota sobre una base e informa su ángulo o dirección al dispositivo que está controlando. Los joysticks se utilizan a menudo para controlar videojuegos y robots.

Para comunicar un rango completo de movimiento al ordenador, un joystick necesita medir la posición del palo en dos ejes: el eje X (de izquierda a derecha) y el eje Y (de arriba abajo).

Las coordenadas de movimiento del joystick se muestran en la siguiente figura.

.. note::

    * La coordenada x es de izquierda a derecha, el rango es 0-1023.
    * La coordenada y es de arriba abajo, el rango es 0-1023.

.. image:: img/16_joystick.png


Ahora construye el circuito según el siguiente diagrama.

.. image:: img/circuit/joystick_circuit.png

Programación
------------------

**1. Dragón**

Se añadió el fondo **Woods** a través del botón **Choose a Backdrop**.

.. image:: img/19_dragon01.png

* Elimina el sprite por defecto y añade el sprite **Dragon**.

.. image:: img/19_dragon0.png

* Ve a la página **Costumes** y gira horizontalmente los disfraces dragon-b y dragon-c.

.. image:: img/19_dragon1.png

* Ajusta el tamaño al 50%.

.. image:: img/19_dragon3.png

* Ahora crea una variable - **dragon** para registrar los puntos de vida del dragón, y establece el valor inicial en 50.

.. image:: img/19_dragon2.png

* A continuación, cambia el disfraz del sprite a **dragon-b** y haz que el sprite **Dragon** se mueva hacia arriba y abajo en un rango.

.. image:: img/19_dragon4.png


* Añade un sprite **Lightning** como el fuego soplado por el sprite **Dragon**. Necesitas rotarlo 90° en sentido horario en la página Disfraces, esto es para hacer que el sprite **Lightning** se mueva en la dirección correcta.

.. note::
    Al ajustar el disfraz del sprite **Lightning**, puedes moverlo fuera de centro, ¡lo cual debe evitarse! ¡El punto central debe estar justo en medio del sprite!

.. image:: img/19_lightning1.png



* Luego ajusta el disfraz **dragon-c** del sprite **Dragon** para que su punto central esté en la cola del fuego. Esto hará que las posiciones del sprite **Dragon** y del sprite **Lightning** sean correctas y evitará que el **Lightning** se lance desde los pies del dragón. 

.. image:: img/19_dragon5.png

* Correspondientemente, **dragon-b** necesita hacer que la cabeza del dragón coincida con el punto central.

.. image:: img/19_dragon5.png

* Ajusta el tamaño y la orientación del sprite **Lightning** para que la imagen se vea más armoniosa.

.. image:: img/19_lightning3.png

* Ahora programa el sprite **Lightning**. Esto es fácil, solo haz que siga al sprite **Dragon** todo el tiempo. En este punto, haz clic en la bandera verde y verás al **Dragon** moviéndose con un rayo en la boca.

.. image:: img/19_lightning4.png

* De vuelta al sprite **Dragon**, ahora haz que sople fuego, teniendo cuidado de no dejar que el fuego en su boca salga disparado, sino de crear un clon para el sprite **Lightning**.

.. image:: img/19_dragon6.png

* Haz clic en el sprite **Lightning** y deja que el clon del **Lightning** salga disparado en un ángulo aleatorio, rebotará en la pared y desaparecerá después de cierto tiempo.

.. image:: img/19_lightning5.png

* En el sprite **Lightning**, oculta su cuerpo y muestra el clon.

.. image:: img/19_lightning6.png

Ahora el dragón puede moverse hacia arriba y abajo y soplar fuego.


**2. Varita**

* Crea un sprite **Wand** y rota su dirección a 180 para que apunte a la derecha.

.. image:: img/19_wand1.png

* Ahora crea una variable **hp** para registrar su valor de vida, inicialmente establecida en 3. Luego lee el valor del Joystick, que se usa para controlar el movimiento de la varita.

.. image:: img/19_wand2.png

* ¡El dragón tiene rayos, y la varita que lo aplasta tiene su "bala mágica"! Crea un sprite **Star**, redimensiónalo y prográmalo para que siempre siga al sprite **Wand**, y limita el número de estrellas a tres.

.. image:: img/19_star2.png

* Haz que el sprite **Wand** dispare estrellas automáticamente. El sprite **Wand** dispara estrellas de la misma manera que el dragón sopla fuego -- creando clones.

.. image:: img/19_wand3.png


* Vuelve al sprite **Star** y programa su clon para que gire y dispare hacia la derecha, desaparezca después de ir más allá del escenario y restaure el número de estrellas. Igual que el sprite **Lightning**, oculta el cuerpo y muestra el clon.

.. image:: img/19_star3.png

Ahora tenemos una varita que dispara balas de estrella.

**3. ¡Pelea!**

La varita y el dragón están actualmente en desacuerdo entre sí, y vamos a hacer que luchen. El dragón es fuerte, y la varita es el valiente que se enfrenta al dragón. La interacción entre ellos consta de las siguientes partes.


1. Si la varita toca al dragón, será rechazada y perderá puntos de vida.
2. Si un rayo golpea la varita, esta perderá puntos de vida.
3. Si una bala de estrella golpea al dragón, este perderá puntos de vida.


Una vez aclarado esto, avancemos a cambiar los scripts para cada sprite.

* Si la **Wand** golpea al **Dragon**, será rechazada y perderá puntos de vida.

.. image:: img/19_wand4.png

* Si **Lightning** (un clon del sprite **Lightning**) golpea al sprite **Wand**, emitirá un sonido de estallido y desaparecerá, y la **Wand** perderá puntos de vida.

.. image:: img/19_lightning7.png

* Si una **Star** (clon del sprite **Star**) golpea al **Dragon**, emitirá un sonido de recogida y desaparecerá, restaurando el conteo de **Star**, y el **Dragon** perderá puntos de vida.

.. image:: img/19_star4.png


**4. Escenario**

La batalla entre la **Wand** y el **Dragon** eventualmente se dividirá en ganadores y perdedores, lo que representamos con el escenario.

* Añade el fondo **Blue Sky**, y escribe el personaje "WIN!" en él para representar que el dragón ha sido derrotado y ha llegado el amanecer.


.. image:: img/19_sky0.png

* Y modifica el fondo en blanco de la siguiente manera, para representar que el juego ha fracasado y todo estará en oscuridad.

.. image:: img/19_night.png

* Ahora escribe un script para cambiar estos fondos, cuando se haga clic en la bandera verde, cambia al fondo **Woods**; si el punto de vida del dragón es menor de 1, entonces el juego tiene éxito y cambia el fondo a **Blue Sky**; si el valor de vida de la **Wand** es menor de 1, entonces cambia al fondo **Night** y el juego fracasa.


.. image:: img/19_sky1.png

