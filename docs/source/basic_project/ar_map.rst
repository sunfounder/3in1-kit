.. _ar_map:

5.6 Mapeo
============

Si observas detenidamente, notarás que muchos valores tienen diferentes rangos en la programación.
Por ejemplo, el rango de valores para entradas analógicas es (0~1023).
El rango de valores para la salida analógica es (0~255).
El ángulo de salida del servo es (0~180).

Esto significa que si queremos usar el potenciómetro para controlar el brillo del LED o el ángulo del servo, necesitamos realizar una operación de mapeo.

Ahora veamos cómo lograrlo.

**Componentes Necesarios**

En este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar todo un kit, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS DE ESTE KIT
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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**Esquemático**

.. image:: img/circuit_8.3_amp.png

**Cableado**

.. image:: img/map_bb.jpg
    :width: 800
    :align: center

**Código**

.. note::

    * Abre el archivo ``5.6.map.ino`` en la ruta ``3in1-kit\basic_project\5.6.map``.
    * O copia este código en el **Arduino IDE**.
    
    * O sube el código a través del `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f00e4c4c-fb13-4445-9d89-eb2857b5fe87/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Una vez que el código se haya cargado con éxito, puedes girar el potenciómetro hacia adelante y hacia atrás, y el eje de salida del servo rotará de la misma manera.

**¿Cómo funciona?**

``map(value, fromLow, fromHigh, toLow, toHigh)``: Mapea un número de un rango a otro.
Es decir, un valor fromLow se mapea a toLow, y un valor fromHigh se mapea a toHigh.

    **Sintaxis**
        map(value, fromLow, fromHigh, toLow, toHigh)

    **Parámetros**
        * ``value``: el número a mapear.
        * ``fromLow``: el límite inferior del rango actual del valor.
        * ``fromHigh``: el límite superior del rango actual del valor.
        * ``toLow``: el límite inferior del rango objetivo del valor.
        * ``toHigh``: el límite superior del rango objetivo del valor.

Si el potenciómetro controla el LED, también puedes usar el mapeo para completar la tarea.

.. code-block:: arduino

    int x = analogRead(knob);
    int y = map(x,0,1023,0,255);
    analogWrite(led,y);


**Notas y Advertencias**

* El "límite inferior" de ambos rangos puede ser mayor o menor que el "límite superior", lo que significa que la función ``map()`` se puede usar para invertir un rango de números.

  .. code-block:: arduino

    y = map(x,0,180,180,0);

* El mapeo también funciona bien para números negativos.

  .. code-block:: arduino

    y = map(x,0,1023,-90,90);

* El mapeo utiliza enteros, y se descartan los decimales de los números flotantes.
