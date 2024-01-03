.. _ar_segment:

5.10 ShiftOut(Display de Segmentos)
===================================

Anteriormente, usamos la función ``shiftout()`` para encender ocho LEDs; aquí la usamos para mostrar los números 0-9 en el Display de 7 segmentos.

El Display de 7 segmentos es esencialmente un dispositivo empaquetado con 8 LEDs, de los cuales 7 LEDs en forma de tira forman una figura "8", y hay un LED puntual ligeramente más pequeño que sirve como punto decimal. Estos LEDs se marcan como a, b, c, d, e, f, g y dp. Tienen sus propios pines de ánodo y comparten cátodos. La ubicación de sus pines se muestra en la figura a continuación.

.. image:: img/segment_cathode.png
    :width: 600
    :align: center

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
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Esquemático**

.. image:: img/circuit_6.5_segment.png

**Cableado**

.. list-table:: Conexión
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - Display de Segmentos LED
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

.. image:: img/segment_bb.jpg
    :width: 600
    :align: center


**Código**

.. note::

    * Abre el archivo ``5.10.shiftout_segment.ino`` en la ruta ``3in1-kit\basic_project\5.10.shiftout_segment``.
    * O copia este código en el **Arduino IDE**.
    
    * O sube el código a través del `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/23b9a3ea-c648-4f33-8622-e279d94ee507/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Una vez que el código se haya cargado con éxito, podrás ver el Display de Segmentos LED mostrando los números del 0 al 9 en secuencia.

**¿Cómo funciona?**

``shiftOut()`` hace que el 74HC595 emita 8 señales digitales.
Envía el último bit del número binario a Q0,
y la salida del primer bit a Q7. En otras palabras,
escribir el número binario "00000001" hará que Q0 emita un nivel alto y Q1~Q7 un nivel bajo.

Supongamos que el Display de 7 segmentos muestra el número "2", 
necesitamos escribir un nivel alto para a, b, d, e y g, y un nivel bajo para c, f y dp.
Es decir, se necesita escribir el número binario "01011011". 
Por legibilidad, usaremos la notación hexadecimal como "0x5b".

.. image:: img/7_segment2.png

* `Hexadecimal <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `Convertidor Binario a Hexadecimal <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

De manera similar, también podemos hacer que el Display de 7 Segmentos muestre otros números de la misma manera. 
La siguiente tabla muestra los códigos correspondientes a estos números.

.. list-table:: Código de Glifo
    :widths: 20 20 20
    :header-rows: 1

    *   - Números	
        - Código Binario
        - Código Hex  
    *   - 0	
        - 00111111	
        - 0x3f
    *   - 1	
        - 00000110	
        - 0x06
    *   - 2	
        - 01011011	
        - 0x5b
    *   - 3	
        - 01001111	
        - 0x4f
    *   - 4	
        - 01100110	
        - 0x66
    *   - 5	
        - 01101101	
        - 0x6d
    *   - 6	
        - 01111101	
        - 0x7d
    *   - 7	
        - 00000111	
        - 0x07
    *   - 8	
        - 01111111	
        - 0x7f
    *   - 9	
        - 01101111	
        - 0x6f

Escribe estos códigos en ``shiftOut()`` para que el Display de Segmentos LED muestre los números correspondientes.
