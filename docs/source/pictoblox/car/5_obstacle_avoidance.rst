.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_avoid1:

3.5 Evitación de obstáculos
==================================

Dos módulos infrarrojos de evitación de obstáculos están montados en la parte frontal del coche, los cuales pueden ser utilizados para detectar algunos obstáculos cercanos.

En este proyecto, se permite que el coche se mueva libremente hacia adelante, y cuando encuentra un obstáculo, puede evitarlo y continuar moviéndose en otras direcciones.

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
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

Construye el Circuito
-----------------------

El módulo de evitación de obstáculos es un sensor de proximidad infrarrojo ajustable en distancia cuya salida es normalmente alta y baja cuando detecta un obstáculo.

Ahora construye el circuito según el diagrama a continuación.

.. list-table:: 

    * - Módulo IR Izquierdo
      - Placa R3
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 

    * - Módulo IR Derecho
      - Placa R3
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_5.png
    :width: 800

Ajuste del Módulo
-----------------------

Antes de comenzar el proyecto, necesitas ajustar la distancia de detección del módulo.

Conecta el cableado según el diagrama anterior, enciende la placa R3 (ya sea conectando directamente el cable USB o enganchando el cable de la batería de 9V), sin subir el código.

Coloca un cuaderno u otro objeto plano a unos 5 cm delante del módulo de evitación de obstáculos IR.

Luego usa un destornillador para girar el potenciómetro en el módulo hasta que el indicador de señal en el módulo se ilumine, ajustando así su distancia máxima de detección a 5 cm.

Sigue el mismo método para ajustar otro módulo infrarrojo.

.. image:: img/ir_obs_cali.jpg

Programación
---------------

El efecto que queremos lograr.

* Cuando el módulo IR izquierdo detecta un obstáculo, el coche retrocede hacia la izquierda
* Cuando el módulo IR derecho detecta un obstáculo, el coche retrocede hacia la derecha.
* Si ambos módulos IR detectan el obstáculo, el coche retrocederá directamente.
* De lo contrario, el coche avanzará.

Ahora crea los bloques correspondientes.

**1. El coche retrocede hacia la izquierda**

Cuando el motor derecho está girando en sentido antihorario y el motor izquierdo no está girando, el coche retrocederá hacia la izquierda.

.. image:: img/5_avoid1.png

**2. El coche retrocede hacia la derecha**

Cuando el motor izquierdo está girando en sentido horario y el motor derecho no está girando, el coche retrocederá hacia la derecha.

.. image:: img/5_avoid2.png

**3. El coche se mueve hacia adelante, hacia atrás y se detiene**

.. image:: img/5_avoid3.png

**4. Leer los valores de los 2 módulos IR**

Haz clic en **Make a variable** en la paleta **Variables**.

.. image:: img/5_avoid4.png

Introduce el nombre de la variable y haz clic en **OK** para crear una nueva variable.

.. image:: img/5_avoid5.png

Lee los valores de los módulos de evitación de obstáculos IR izquierdo y derecho y guárdalos en las 2 nuevas variables.

.. image:: img/5_avoid6.png

**5. Evitación de obstáculos**

* Cuando el módulo IR izquierdo es 0 (obstáculo detectado) y el módulo IR derecho es 1, haz que el coche retroceda hacia la izquierda.
* Cuando el módulo IR derecho es 0 (obstáculo detectado), haz que el coche retroceda hacia la derecha.
* Si los 2 módulos IR detectan el obstáculo al mismo tiempo, el coche retrocederá.
* De lo contrario, el coche seguirá avanzando.

.. image:: img/5_avoid7.png
