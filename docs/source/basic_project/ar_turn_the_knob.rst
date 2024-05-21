.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_potentiometer:

4.1 Girar el Potenciómetro
============================

El potenciómetro es un componente resistivo con 3 terminales y su valor de resistencia puede ser
ajustado según alguna variación regular.

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
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|


**Esquemático**

.. image:: img/circuit_5.1_potentiometer.png

En este ejemplo, usamos el pin analógico (A0) para leer el valor
del potenciómetro. Al girar el eje del potenciómetro, puedes
cambiar la distribución de resistencia entre estos tres pines, cambiando
el voltaje en el pin medio. Cuando la resistencia entre el medio
y un pin exterior conectado a 5V está cerca de cero (y la resistencia
entre el medio y el otro pin exterior está cerca de 10kΩ), el
voltaje en el pin medio está cerca de 5V. La operación inversa (la
resistencia entre el medio y un pin exterior conectado a 5V está cerca
de 10kΩ) hará que el voltaje en el pin medio esté cerca de 0V.


**Cableado**

.. image:: img/turn_thek_knob_bb.jpg
    :width: 600
    :align: center

**Código**


.. note::

   * Puedes abrir el archivo ``4.1.turn_the_knob.ino`` en la ruta ``3in1-kit\basic_project\4.1.turn_the_knob``. 
   * O copia este código en **Arduino IDE**.
   
   * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d931f2c9-74bc-4a53-8531-39a21a07dbaf/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
    
Después de subir los códigos a la placa, puedes abrir el monitor
serial para ver el valor de lectura del pin. Al girar el eje del
potenciómetro, el monitor serial imprimirá el valor
「0」~「1023」. 
