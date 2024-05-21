.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_light_ball:

2.12 Bola Sensible a la Luz
==============================

En este proyecto, usamos un fotoresistor para hacer que la bola en el escenario vuele hacia arriba. Coloca tu mano sobre el fotoresistor para controlar la intensidad de luz que recibe. Cuanto más cerca esté tu mano del fotoresistor, menor será su valor y más alta volará la bola en el escenario; de lo contrario, caerá. Cuando la bola toca la cuerda, produce un sonido agradable y una luz de estrella parpadeante.

.. image:: img/18_ball.png

Aprenderás
---------------------

- Rellenar el sprite con colores
- Tocar entre los sprites

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

Un fotoresistor o célula fotoeléctrica es un resistor variable controlado por la luz. La resistencia de un fotoresistor disminuye con el aumento de la intensidad de luz incidente.

Construye el circuito según el siguiente diagrama.

Conecta un extremo del fotoresistor a 5V, el otro extremo a A0, y conecta una resistencia de 10K en serie con GND en este extremo.

Por lo tanto, cuando la intensidad de la luz aumenta, la resistencia del fotoresistor disminuye, la división de voltaje de la resistencia de 10K aumenta y el valor obtenido por A0 se hace mayor.

.. image:: img/circuit/photoresistor_circuit.png

Programación
------------------

El efecto que queremos obtener es que cuanto más cerca esté tu mano del fotoresistor, el sprite de la bola en el escenario seguirá subiendo, de lo contrario caerá sobre el sprite del tazón. Si toca el sprite de la Línea mientras sube o cae, emitirá un sonido musical y lanzará sprites de estrellas en todas direcciones.


**1. Seleccionar sprite y fondo**

Elimina el sprite predeterminado, selecciona los sprites **Ball**, **Bowl** y **Star**.

.. image:: img/18_ball1.png

Mueve el sprite **Bowl** al centro inferior del escenario y aumenta su tamaño.

.. image:: img/18_ball3.png

Como necesitamos moverlo hacia arriba, establece la dirección del sprite **Ball** a 0.

.. image:: img/18_ball4.png

Establece el tamaño y la dirección del sprite **Star** a 180 porque necesitamos que caiga, o puedes cambiarlo a otro ángulo.

.. image:: img/18_ball12.png

Ahora añade el fondo **Stars**.

.. image:: img/18_ball2.png

**2. Dibujar un sprite de Línea**

Añade un sprite de Línea.

.. image:: img/18_ball7.png

Ve a la página **Costumes** del sprite **Line**, reduce ligeramente el ancho de la línea roja en el lienzo, luego cópiala 5 veces y alinea las líneas.

.. image:: img/18_ball8.png

Ahora rellena las líneas con diferentes colores. Primero elige un color que te guste, luego haz clic en la herramienta **Fill** y mueve el ratón sobre la línea para rellenarla con color.

.. image:: img/18_ball9.png

Sigue el mismo método para cambiar el color de las otras líneas.

.. image:: img/18_ball10.png

**3. Programar el sprite Bola**

Establece la posición inicial del sprite **Ball**, luego, cuando el valor de luz sea menor a 800 (puede ser cualquier otro valor, dependiendo de tu entorno actual), deja que la Bola se mueva hacia arriba.

Puedes hacer que la variable light_value aparezca en el escenario para observar el cambio de intensidad de luz en todo momento.

.. image:: img/18_ball5.png

De lo contrario, el sprite **Ball** caerá y limitará su coordenada Y a un mínimo de -100. Esto se puede modificar para que parezca que está cayendo sobre el sprite **Bowl**.

.. image:: img/18_ball6.png

Cuando el sprite **Line** es golpeado, la coordenada Y actual se guarda en la variable **ball_coor** y se transmite un mensaje **Bling**.

.. image:: img/18_ball11.png

**4. Programar el sprite Estrella**

Cuando comience el script, primero oculta el sprite **Star**. Cuando se recibe el mensaje **Bling**, clona el sprite **Star**.

.. image:: img/18_ball13.png

Cuando el sprite **Star** aparezca como un clon, reproduce el efecto de sonido y establece sus coordenadas sincronizadas con el sprite **Ball**.

.. image:: img/18_ball14.png

Crea el efecto de aparición del sprite **Star** y ajústalo según sea necesario.

.. image:: img/18_ball15.png
