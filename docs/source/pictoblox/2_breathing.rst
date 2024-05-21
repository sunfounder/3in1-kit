.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _sh_breathing_led:

2.2 LED Respirando
========================

Ahora utiliza otro método para controlar el brillo del LED. A diferencia del proyecto anterior, aquí se hace que el brillo del LED disminuya lentamente hasta que desaparece.

Cuando se hace clic en el sprite en el escenario, el brillo del LED aumenta lentamente y luego se apaga instantáneamente.

.. image:: img/3_ap.png

Aprenderás
---------------------

- Establecer el valor de salida del pin PWM
- Crear variables
- Cambiar el brillo del sprite

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
    *   - :ref:`cpn_led`
        - |link_led_buy|

Construir el Circuito
-----------------------

Este proyecto utiliza el mismo circuito que el proyecto anterior :ref:`sh_table_lamp`, pero en lugar de usar ALTO/BAJO para encender o apagar los LEDs, este proyecto utiliza la señal `PWM - Wikipedia <https://en.wikipedia.org/wiki/Pulse-width_modulation>`_ para iluminar o atenuar lentamente el LED.

El rango de la señal PWM es de 0-255, en la placa Arduno Uno, los pines 3, 5, 6, 9, 10, 11 pueden emitir señal PWM; en la Mega2560, los pines 2 - 13, 44 - 46 pueden emitir señal PWM.

.. image:: img/circuit/led_circuit.png

Programación
------------------

**1. Seleccionar un sprite**

Elimina el sprite predeterminado, haz clic en el botón **Choose a Sprite** en la esquina inferior derecha del área de sprites, introduce **button3** en la caja de búsqueda y luego haz clic para añadirlo.

.. image:: img/3_sprite.png

**2. Crear una variable**.

Crea una variable llamada **pwm** para almacenar el valor del cambio de pwm.

Haz clic en la paleta **Variables** y selecciona **Make a Variable**.

.. image:: img/3_ap_va.png

Introduce el nombre de la variable, puede ser cualquier nombre, pero se recomienda que describa su función. El tipo de dato es número y Para todos los sprites.

.. image:: img/3_ap_pwm.png

Una vez creada, verás **pwm** dentro de la paleta **Variables** y en estado marcado, lo que significa que esta variable aparecerá en el escenario. Puedes probar desmarcándola para ver si pwm sigue presente en el escenario.

.. image:: img/3_ap_0.png

**3. Establecer el estado inicial**

Cuando se hace clic en el sprite **button3**, cambia el disfraz a **button-b** (estado clickeado), y establece el valor inicial de la variable **pwm** en 0.

* [set pwm to 0]: de la paleta **Variables**, se utiliza para establecer el valor de la variable.

.. image:: img/3_ap_brightness.png

**4. Hacer que el LED brille cada vez más**

Dado que el rango de pwm es 255, así que por el bloque [repeat], la variable **pwm** se acumula hasta 255 en incrementos de 5, y luego se pone en el bloque [set PWM pin], para que puedas ver el LED iluminarse lentamente.

* [change pwm by 5]: de la paleta **Variables**, permite que la variable cambie un número específico cada vez. Puede ser un número positivo o negativo, positivo es aumentar cada vez, negativo es disminuir cada vez, por ejemplo, aquí la variable pwm aumenta en 5 cada vez.
* [set PWM pin]: de la paleta **Arduino Uno**, se utiliza para establecer el valor de salida del pin pwm.

.. image:: img/3_ap_1.png

Finalmente, cambia el disfraz de button3 de nuevo a **button-a** y establece el valor del pin PWM en 0, para que el LED se ilumine lentamente y luego se apague de nuevo.

.. image:: img/3_ap_2.png

