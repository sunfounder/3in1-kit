.. _ar_photoresistor:

4.2 Siente la Luz
===========================

El fotorresistor es un dispositivo típico para entradas analógicas y se usa de manera muy similar a un potenciómetro. Su valor de resistencia depende de la intensidad de la luz, cuanto más fuerte sea la luz irradiada, menor será su valor de resistencia; por el contrario, aumenta.

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Esquemático**

.. image:: img/circuit_5.2_light.png

En este circuito, la resistencia de 10K y el fotorresistor están conectados en serie, y la corriente que pasa a través de ellos es la misma. La resistencia de 10K actúa como protección, y el pin A0 lee el valor después de la conversión de voltaje del fotorresistor.

Cuando la luz se intensifica, la resistencia del fotorresistor disminuye, luego su voltaje disminuye, por lo que el valor del pin A0 aumentará; 
si la luz es lo suficientemente fuerte, la resistencia del fotorresistor estará cerca de 0, y el valor del pin A0 estará cerca de 1023. 
En este momento, la resistencia de 10K juega un papel protector, de modo que 5V y GND no se conectan juntos, resultando en un cortocircuito.

Si colocas el fotorresistor en una situación oscura, el valor del pin A0 disminuirá. 
En una situación lo suficientemente oscura, la resistencia del fotorresistor será infinita, y su voltaje estará cerca de 5V (la resistencia de 10K es despreciable), y el valor del pin A0 estará cerca de 0.


**Cableado**

.. image:: img/feel_the_light_bb.jpg
    :width: 600
    :align: center


**Código**

.. note::

    * Abre el archivo ``4.2.feel_the_light.ino`` en la ruta ``3in1-kit\basic_project\4.2.feel_the_light``.
    * O copia este código en **Arduino IDE**.
    
    * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e1bc4c8b-788e-4bfe-a0a1-532d4fdc7753/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Después de cargar el código con éxito, el monitor serial imprime los valores del fotorresistor. 
Cuanto más fuerte sea la luminosidad ambiental actual, mayor será el valor mostrado en el monitor serial.
