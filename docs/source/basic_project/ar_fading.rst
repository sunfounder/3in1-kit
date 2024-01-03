.. _ar_fading:

2.1 Atenuación
=================

Este proyecto es similar a :ref:`ar_blink`, la diferencia está en el tipo de señal.
El anterior consiste en hacer que el LED se encienda o apague emitiendo una señal digital (0&1), este proyecto controla el brillo del LED emitiendo una señal analógica.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|

**Esquemático**

.. image:: img/circuit_1.1_led.png

**Cableado**

.. image:: img/wiring_led.png
    :width: 500
    :align: center

**Código**

.. note::

   * Puedes abrir el archivo ``2.1.fading.ino`` en la ruta ``3in1-kit\basic_project\2.analogWrite\2.1.fading``. 
   * O copia este código en **Arduino IDE**.
   
   * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8a7e52a4-fcb3-4c3b-98ff-f3f657822d72/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Después de cargar el código con éxito, podrás ver el LED "respirar".
