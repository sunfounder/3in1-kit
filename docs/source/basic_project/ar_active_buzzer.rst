.. _ar_beep:

1.2 Pitido
==================
¡El zumbador activo es un dispositivo típico de salida digital tan fácil de usar como encender un LED!

El kit incluye dos tipos de zumbadores.
Necesitamos usar el zumbador activo. Gíralos, la parte sellada (no la PCB expuesta) es la que queremos.

.. image:: img/buzzer.png

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
    *   - :ref:`cpn_buzzer`
        - \-


**Esquemático**

.. image:: img/circuit_1.2_beep.png


**Cableado**

.. image:: img/wiring_active_buzzer.png
    :width: 400
    :align: center

**Código**


.. note::

   * Puedes abrir el archivo ``1.2.beep.ino`` en la ruta ``3in1-kit\basic_project\1.2.beep``. 
   * O copia este código en **Arduino IDE**.
   
   * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/95570ca2-11c6-404c-a23f-bf03094d8085/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de cargar el código con éxito, escucharás un pitido cada segundo.
