.. _ar_reed:

3.2 Siente el Magnetismo
===============================

El tipo más común de interruptor de lengüeta contiene un par de lengüetas de metal magnetizables y flexibles, cuyas partes finales están separadas por un pequeño espacio cuando el interruptor está abierto.

Un campo magnético de un electroimán o un imán permanente hará que las lengüetas se atraigan entre sí, completando así un circuito eléctrico.
La fuerza de resorte de las lengüetas las hace separarse y abrir el circuito cuando cesa el campo magnético.

Un ejemplo común de aplicación de un interruptor de lengüeta es detectar la apertura de una puerta o ventana para una alarma de seguridad.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_reed`
        - \-

**Esquemático**

.. image:: img/circuit_3.2_reed.png

Por defecto, el pin 2 es bajo; y se pondrá alto cuando el imán esté cerca del interruptor de lengüeta.

El propósito de la resistencia de 10K es mantener el pin 2 en un nivel bajo estable cuando no hay un imán cerca.

**Cableado**

.. image:: img/feel_the_magnetism_bb.jpg
    :width: 600
    :align: center

**Código**

.. note::

   * Puedes abrir el archivo ``3.2.feel_the_magnetism.ino`` en la ruta ``3in1-kit\basic_project\3.2.feel_the_magnetism``. 
   * O copia este código en **Arduino IDE**.
   
   * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/d28c942e-5144-44a1-85d8-d5e6894fc5df/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Después de cargar el código con éxito, cuando un imán está cerca del interruptor de lengüeta, el monitor serial imprimirá 1.


