.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_doorbell:

2.6 Timbre
======================

Aquí, usaremos el botón y la campana en el escenario para hacer un timbre.


Después de hacer clic en la bandera verde, puedes presionar el botón y la campana en el escenario hará un sonido.

.. image:: img/7_doorbell.png

Aprenderás
---------------------

- Cómo funciona el botón
- Lectura del pin digital y rangos
- Creación de un bucle condicional
- Añadir un fondo
- Reproducir sonido

Componentes Necesarios
--------------------------

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|

Construir el Circuito
-----------------------

El botón es un dispositivo de 4 pines, dado que el pin 1 está conectado al pin 2, y el pin 3 al pin 4, cuando se presiona el botón, los 4 pines se conectan, cerrando así el circuito.

.. image:: img/5_buttonc.png

Construye el circuito según el siguiente diagrama.

* Conecta uno de los pines del lado izquierdo del botón al pin 12, que está conectado a una resistencia de pull-down y un capacitor de 0.1uF (104) (para eliminar la oscilación y emitir un nivel estable cuando el botón está funcionando).
* Conecta el otro extremo de la resistencia y el capacitor a GND, y uno de los pines del lado derecho del botón a 5V.

.. image:: img/circuit/button_circuit.png

Programación
------------------

**1. Añadir un Fondo**

Haz clic en el botón **Choose a Backdrop** en la esquina inferior derecha.

.. image:: img/7_backdrop.png

Elige **Bedroom 1**.

.. image:: img/7_bedroom2.png

**2. Seleccionar el sprite**

Elimina el sprite predeterminado, haz clic en el botón **Choose a Sprite** en la esquina inferior derecha del área de sprites, introduce **bell** en la caja de búsqueda y luego haz clic para añadirla.

.. image:: img/7_sprite.png

Luego selecciona el sprite **bell** en el escenario y muévelo a la posición correcta.

.. image:: img/7_doorbell.png

**3. Presionar el botón y la campana hace un sonido**


Usa [if then] para hacer una declaración condicional que cuando el valor del pin12 leído sea igual a 1 (se presiona el botón), se reproduzca el sonido **xylo1**.

* [read status of digital pin]: Este bloque es de la paleta **Arduino Uno** y se utiliza para leer el valor de un pin digital, el resultado es 0 o 1.
* [`if then <https://en.scratch-wiki.info/wiki/If_()_Then_(block)>`_]: Este bloque es un bloque de control y de la paleta **Control**. Si su condición booleana es verdadera, los bloques que contiene se ejecutarán y luego el script involucrado continuará. Si la condición es falsa, se ignorarán los scripts dentro del bloque. La condición solo se verifica una vez; si la condición se vuelve falsa mientras el script dentro del bloque se está ejecutando, seguirá ejecutándose hasta que haya terminado.
* [play sound until done]: de la paleta de Sonido, se utiliza para reproducir sonidos específicos.

.. image:: img/7_bell.png
