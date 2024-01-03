.. _ar_motor:

1.3 Motor
============================

Un motor es un dispositivo típico de salida digital, y se utiliza de la misma manera que un LED.
Sin embargo, el motor necesita ser impulsado con una gran corriente, y la gran corriente puede dañar la placa de control principal, como la placa R3.
Por lo tanto, en esta ocasión se utiliza un módulo L9110, que es un gran aliado para que la placa R3 controle el motor de forma segura.

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
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

**Esquemático**


.. image:: img/circuit_1.3_wheel_l9110.png


**Cableado**


.. image:: img/1.3_motor_l9110_bb.png
    :width: 800
    :align: center

**Código**

.. note::

   * Puedes abrir el archivo ``1.3.turn_the_wheel.ino`` en la ruta ``3in1-kit\basic_project\1.3.turn_the_wheel``. 
   * O copia este código en **Arduino IDE**.
   
   * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/5f8e4f33-883b-4c06-9516-f1754ea2121d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

