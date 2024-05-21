.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_temp:

4.5 Termómetro
================

Un termómetro es un dispositivo que mide la temperatura o un gradiente de temperatura (el grado de calor o frío de un objeto).
Un termómetro tiene dos elementos importantes: (1) un sensor de temperatura (por ejemplo, el bulbo de un termómetro de mercurio en vidrio o el sensor piroeléctrico en un termómetro infrarrojo) en el que se produce algún cambio con un cambio en la temperatura; 
y (2) algún medio para convertir este cambio en un valor numérico (por ejemplo, la escala visible que está marcada en un termómetro de mercurio en vidrio o la lectura digital en un modelo infrarrojo).
Los termómetros se utilizan ampliamente en tecnología e industria para monitorear procesos, en meteorología, en medicina y en investigación científica.

Un termistor es un tipo de sensor de temperatura cuya resistencia depende fuertemente de la temperatura, y tiene dos tipos:
Coeficiente de Temperatura Negativo (NTC) y Coeficiente de Temperatura Positivo (PTC),
también conocidos como NTC y PTC. La resistencia del termistor PTC aumenta con la temperatura, mientras que la condición del NTC es opuesta a la anterior.

En este experimento usamos un **termistor NTC** para hacer un termómetro.

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
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

**Esquemático**

.. image:: img/circuit_5.5_thermistor.png

Cada termistor tiene una resistencia normal. Aquí es de 10k ohm, que se mide bajo 25 grados Celsius.

Cuando la temperatura aumenta, la resistencia del termistor disminuye. Luego, los datos de voltaje se convierten a cantidades digitales por el adaptador A/D.

La temperatura en Celsius o Fahrenheit se muestra a través de la programación.

Aquí está la relación entre la resistencia y la temperatura:

    **RT = RN expB(1/TK – 1/TN)**

    * **RT** es la resistencia del termistor NTC cuando la temperatura es **TK**.
    * **RN** es la resistencia del termistor NTC bajo la temperatura nominal TN. Aquí, el valor numérico de RN es 10k.
    * **TK** es una temperatura Kelvin y la unidad es K. Aquí, el valor numérico de **TK** es ``273.15 + grados Celsius``.
    * **TN** es una temperatura Kelvin nominal; la unidad también es K. Aquí, el valor numérico de TN es ``273.15+25``.
    * Y **B(beta)**, la constante de material del termistor NTC, también se llama índice de sensibilidad térmica con un valor numérico ``3950``.
    * **exp** es la abreviatura de exponencial, y el número base ``e`` es un número natural que equivale aproximadamente a 2.7.

    Convierte esta fórmula ``TK=1/(ln(RT/RN)/B+1/TN)`` para obtener la temperatura Kelvin que menos 273.15 equivale a grados Celsius.

    Esta relación es una fórmula empírica. Solo es precisa cuando la temperatura y la resistencia están dentro del rango efectivo.


**Cableado**

.. note::
    * El termistor es negro o verde y está marcado 103.

.. image:: img/thermistor_bb.png
    :width: 600
    :align: center

**Código**

.. note::

   * Puedes abrir el archivo ``4.5_thermometer.ino`` en la ruta ``euler-kit/arduino/4.5_thermometer``.
   * O copia este código en **Arduino IDE**.
   
   * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

    No olvides seleccionar la placa Raspberry Pi Pico y el puerto correcto antes de hacer clic en el botón de Subir.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1ceb0ea2-a330-4052-824d-bd6762c6f0e0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Después de cargar el código con éxito, el Monitor Serial mostrará las temperaturas en Celsius y Fahrenheit.



