.. _ar_moisture:

4.4 Medir la Humedad del Suelo
==================================

En la industria de la plantación, los cultivos por sí mismos no pueden obtener directamente los elementos inorgánicos del suelo,
El agua en el suelo actúa como un disolvente para disolver estos elementos inorgánicos.

Los cultivos absorben la humedad del suelo a través del sistema radicular, obtienen nutrientes y promueven el crecimiento.

En el proceso de crecimiento y desarrollo de los cultivos, los requisitos para la temperatura del suelo también son diferentes.
Por lo tanto, se requiere un sensor de humedad del suelo.

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
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Esquemático**

.. image:: img/circuit_5.4_soil.png

**Cableado**

.. image:: img/measure_the_moisture_bb.jpg
    :width: 800
    :align: center

**Código**

.. note::

    * Abre el archivo ``4.4.measure_soil_moisture.ino`` en la ruta ``3in1-kit\basic_project\4.4.measure_soil_moisture``.
    * O copia este código en **Arduino IDE**.
    
    * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b6f7e756-0f14-4117-9bb2-ee5083b6445f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Una vez cargado el código con éxito, el monitor serial imprimirá el valor de la humedad del suelo.

Al insertar el módulo en la tierra y regarla, el valor del sensor de humedad del suelo se volverá más pequeño.
