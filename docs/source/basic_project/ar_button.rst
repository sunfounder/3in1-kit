.. _ar_button:

3.1 Leyendo el Valor del Botón
=================================

En los proyectos anteriores, utilizamos la función de salida, en este capítulo usaremos la función de entrada para leer el valor del botón.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Esquemático**

.. image:: img/circuit_3.1_button.png

Un lado del pin del botón está conectado a 5V, 
y el otro lado del pin está conectado al pin 2, 
así que cuando se presiona el botón, 
el pin 2 será alto. Sin embargo, 
cuando el botón no está presionado, 
el pin 2 está en un estado suspendido y puede estar alto o bajo. 
Para obtener un nivel bajo estable cuando el botón no está presionado, 
el pin 2 necesita ser reconectado a GND a través de una resistencia de pull-down de 10K.

**Cableado**

.. image:: img/read_the_button_value_bb.jpg
    :width: 600
    :align: center

**Código**

.. note::

   * Puedes abrir el archivo ``3.1.read_button_value.ino`` en la ruta ``3in1-kit\basic_project\3.1.read_button_value``. 
   * O copia este código en **Arduino IDE**.
   
   * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/b456ff57-4dfb-4231-9d91-f1e9a5777de2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de cargar el código con éxito, haz clic en el icono de la lupa en la esquina superior derecha del IDE de Arduino (Monitor Serial).

.. image:: img/sp220614_152922.png

Cuando presiones el botón, el Monitor Serial imprimirá "1".

