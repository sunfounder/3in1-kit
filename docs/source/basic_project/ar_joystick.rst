.. _ar_joystick:

4.3 Mover el Joystick
================================

El joystick debería ser muy familiar para cualquiera que juegue videojuegos con regularidad.
Normalmente se utiliza para mover personajes o rotar la pantalla.

Nuestros movimientos pueden ser leídos por el Joystick, que funciona bajo un principio muy simple.
Consiste en dos potenciómetros que están perpendiculares entre sí.
Estos dos potenciómetros miden el valor analógico del joystick en direcciones vertical y horizontal, produciendo un valor (x,y) en un sistema de coordenadas plano y rectangular.


Este kit también incluye un joystick con una entrada digital. Se activa cuando se presiona el joystick.


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
    *   - :ref:`cpn_joystick`
        - \-

**Esquemático**

.. image:: img/circuit_5.3_joystick.png

.. note::
    El pin SW está conectado a una resistencia de pull-up de 10K, 
    la razón es poder obtener un nivel alto estable en el pin SW (eje Z) cuando el joystick no está presionado; 
    de lo contrario, el SW está en un estado suspendido y el valor de salida puede variar entre 0/1.

**Cableado**

.. image:: img/toggle_the_joystick_bb.jpg
    :width: 800
    :align: center

**Código**

.. note::

    * Abre el archivo ``4.3.toggle_the_joystick.ino`` en la ruta ``3in1-kit\basic_project\4.3.toggle_the_joystick``.
    * O copia este código en **Arduino IDE**.
    
    * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f678a03f-546c-42ed-bfae-b8c7daa5eec9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Abre el monitor serial después de haber cargado el código con éxito para ver los valores x, y, z del joystick.

* Los valores de los ejes x e y son valores analógicos que varían de 0 a 1023.
* El eje Z es un valor digital con un estado de 1 o 0 (cuando se presiona, es 0).
