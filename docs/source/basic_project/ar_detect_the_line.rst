.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_line_track:

3.4 Detectar la Línea
===================================

El módulo de seguimiento de línea se utiliza para detectar si hay áreas negras en el suelo, como líneas negras pegadas con cinta eléctrica.

Uno de sus LED emite luz infrarroja adecuada hacia el suelo, y la superficie negra tiene una capacidad relativamente fuerte para absorber la luz y una capacidad de reflexión más débil. Las superficies blancas son lo contrario.
Si detecta luz reflejada, significa que el suelo es actualmente blanco. Si no se detecta, significa que es negro.

Así es como funciona.

**Componentes Necesarios**

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
    *   - :ref:`cpn_track`
        - |link_track_buy|

**Esquemático**

.. image:: img/circuit_3.4_line.png

El pin digital 2 se utiliza para leer la
señal del módulo de seguimiento de línea. Conectamos el VCC del módulo a 5V, 
GND a GND, OUT al pin digital 2.

**Cableado**

.. image:: img/detect_the_line_bb.jpg
    :width: 500
    :align: center

**Código**

.. note::

   * Puedes abrir el archivo ``3.4.detect_the_line.ino`` en la ruta ``3in1-kit\basic_project\3.4.detect_the_line``. 
   * O copia este código en **Arduino IDE**.
   
   * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9795add6-c838-4a66-b484-0c39f252a7b4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Cuando el módulo de seguimiento de línea detecta que hay una línea negra, aparece [1] en el Monitor Serial; de lo contrario, se muestra [0].

