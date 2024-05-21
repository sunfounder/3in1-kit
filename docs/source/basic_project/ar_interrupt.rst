.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_interrupt:

5.13 Interrupt
=======================

Si utilizas algún ``delay()`` en un proyecto que usa sensores, podrías notar que cuando activas estos sensores, el programa puede no tener efecto.
Esto se debe a que la instrucción de retraso hará que el programa se suspenda, y el programa no podrá obtener la señal enviada por el sensor a la placa de control principal.

En este caso, se puede utilizar una interrupción. La interrupción permite que el programa no se pierda un pulso.

En este capítulo, usamos el zumbador activo y botones para experimentar el proceso de uso de interrupciones.

En la función ``loop()``, se utiliza ``delay(1000)`` para contar segundos.
Pon el botón para controlar el zumbador en la ISR, para que no sea perturbado por el retraso y complete la tarea sin problemas.

.. note::
    Las ISR son tipos especiales de funciones que tienen algunas limitaciones únicas que la mayoría de las otras funciones no tienen. Una ISR no puede tener parámetros, y no debería devolver nada.
    Generalmente, una ISR debe ser lo más corta y rápida posible. Si tu sketch usa múltiples ISR, solo una puede ejecutarse a la vez, otras interrupciones se ejecutarán después de que termine la actual en un orden que depende de la prioridad que tengan.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_buzzer`
        - \-

**Esquemático**

.. image:: img/circuit_8.6_interval.png

**Cableado**

.. image:: img/interrupt_bb.jpg
    :width: 600
    :align: center

**Código**

.. note::

    * Abre el archivo ``5.13.interrupt.ino`` en la ruta ``3in1-kit\basic_project\5.13.interrupt``.
    * O copia este código en el **Arduino IDE**.
    
    * O carga el código a través del `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/6111757d-dd63-4c4c-95b5-9d96fb0843f0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Una vez que el código se haya cargado con éxito, enciende el Monitor Serial y verás un número autoincrementado impreso cada segundo. Si presionas el botón, el zumbador sonará.
La función del zumbador controlado por botón y la función de temporización no entran en conflicto entre sí.

**¿Cómo funciona?**

* ``attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)``: Añade una interrupción.

    **Sintaxis**
        attachInterrupt(digitalPinToInterrupt(pin), ISR, mode) 

    **Parámetros**
        * ``pin``: el número de pin de Arduino. Debes usar ``digitalPinToInterrupt(pin)`` para convertir el pin digital real en un número de interrupción específico. Por ejemplo, si te conectas al pin 3, usa su ``digitalPinToInterrupt(3)`` como primer parámetro.
        * ``ISR``: la ISR a llamar cuando ocurra la interrupción; esta función no debe tomar parámetros y no debe devolver nada. Esta función a veces se conoce como una rutina de servicio de interrupción.
        * ``mode``: define cuándo se debe activar la interrupción. Cuatro constantes están predefinidas como valores válidos:

          * ``LOW`` para activar la interrupción siempre que el pin esté bajo,
          * ``CHANGE`` para activar la interrupción siempre que el pin cambie de valor.
          * ``RISING`` para activar cuando el pin pasa de bajo a alto.
          * ``FALLING`` para cuando el pin pasa de alto a bajo.

.. note:: 
    Diferentes placas de control principal pueden usar pines de interrupción de manera diferente. En la placa R3, solo el pin 2 y el pin 3 pueden usar interrupción.
