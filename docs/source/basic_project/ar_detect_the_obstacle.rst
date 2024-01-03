.. _ar_ir_obstacle:

3.3 Detectar el Obstáculo
===================================

Este módulo se instala comúnmente en automóviles y robots para juzgar la
existencia de obstáculos por delante. También se utiliza ampliamente en dispositivos portátiles, grifos de agua y otros.

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
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

**Esquemático**

.. image:: img/circuit_3.3_obstacle.png

El pin digital 2 se usa para leer la
señal del Módulo de Evitación de Obstáculos IR. Conectamos el VCC del
Módulo Sensor IR a 5V, GND a GND, OUT al pin digital 2.

**Cableado**

.. image:: img/detect_the_obstacle_bb.jpg
    :width: 800
    :align: center

**Código**

.. note::

   * Puedes abrir el archivo ``3.3.detect_the_obstacle.ino`` en la ruta ``3in1-kit\basic_project\3.3.detect_the_obstacle``. 
   * O copia este código en **Arduino IDE**.
   
   * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/535a0304-684e-481d-b85d-403911b3a4e2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Cuando el módulo de evitación de obstáculos IR detecta algo bloqueando su frente, aparecerá [0] en el monitor serial, de lo contrario, se mostrará [1].
