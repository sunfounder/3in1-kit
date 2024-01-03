.. _ar_if_else:

5.1 If else
==============

Normalmente utilizamos juicios condicionales para completar los proyectos de interacción con la realidad más básicos.
Aquí, construimos un sistema de detección de puertas con un interruptor de lengüeta y un LED para mostrar esta lógica.

Fija el imán en un lado de la puerta y el interruptor de lengüeta (con circuito) en el otro lado de la puerta.
Cuando la puerta está cerrada, el imán está cerca del interruptor de lengüeta, lo que lo activará.

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
    *   - :ref:`cpn_reed`
        - \-

**Esquemático**

.. image:: img/circuit_8.1_ifelse.png

**Cableado**

.. image:: img/if_else_bb.jpg
    :width: 600
    :align: center

**Código**

.. note::

    * Abre el archivo ``5.1.if_else.ino`` en la ruta ``3in1-kit\basic_project\5.1.if_else``.
    * O copia este código en **Arduino IDE**.
    
    * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c7bf6236-1276-45a0-8d34-008d2d838476/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Después de cargar el código con éxito, si no cierras la puerta, el LED se iluminará, indicándote que cierres la puerta.

Por cierto, si necesitamos el efecto opuesto (iluminar el LED cuando la puerta está cerrada), solo necesitamos modificar la condición en el ``if``.

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    El ``if else`` permite un mayor control sobre el flujo del código que la declaración básica de if, al permitir agrupar varias pruebas.
