.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_threshold:

5.2 Umbral
=============

En muchos proyectos, te encontrarás con una necesidad como esta.
"Cuando xxx alcance cierto nivel, entonces..."

Por ejemplo, en una casa inteligente, cuando la intensidad de la luz sea menor a 50Lux, encender la luz;
Otro ejemplo es en la placa madre del ordenador, si la temperatura operativa de la CPU es superior a 65 grados Celsius, encender el ventilador, y así sucesivamente.

En estos requisitos, se refleja la palabra clave "umbral".

Podemos ajustar el valor del umbral para hacer que el circuito opere más en línea con las necesidades individuales.
Por ejemplo, si me gusta un ambiente más iluminado, puedo aumentar el umbral de las luces automáticas de la casa inteligente a 80Lux.
Otro ejemplo es que el ambiente de ventilación de mi estudio no es muy bueno y la demanda de disipación de calor es mayor, entonces el valor umbral de apertura automática del ventilador puede ajustarse a 50 grados Celsius.


Aquí usamos un sensor de humedad del suelo y 2 LEDs para hacer un monitor de maceta. Si el suelo está demasiado seco, se encenderá el LED rojo; si el suelo está suficientemente húmedo, se encenderá el LED verde. Necesitas ajustar manualmente los umbrales para determinar la sequedad y humedad del suelo.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Esquemático**

.. image:: img/circuit_8.2_threshold.png

**Cableado**

.. image:: img/threshold_bb.png
    :width: 600
    :align: center

**Código**

.. note::

    * Abre el archivo ``5.2.threshold.ino`` en la ruta ``3in1-kit\basic_project\5.2.threshold``.
    * O copia este código en **Arduino IDE**.
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/9936413a-6e6c-4e57-b0c6-5df58dd48a3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Después de cargar el código con éxito, si tu umbral está configurado correctamente, verás el LED rojo encenderse cuando el suelo esté seco para recordarte que necesitas regar; después de regar, se encenderá el LED verde.

**¿Cómo funciona?**

.. code-block:: Arduino

    ...

    void loop() {
        int sensorValue = analogRead(soilMoisture);
        Serial.println(sensorValue);
        if (sensorValue > threshold) {
            digitalWrite(redPin, HIGH); // Turn the red LED
            digitalWrite(greenPin, LOW); // green
        } else {
            digitalWrite(greenPin, HIGH); // Turn on the green LED
            digitalWrite(redPin, LOW); // red
        }
    }
    ...

Primero establece un valor ``threshold`` y luego lee el valor del módulo de humedad del suelo, su valor disminuye a medida que aumenta el nivel de humedad. Si el valor leído actualmente es mayor que el ``threshold`` establecido, entonces deja que el LED rojo se ilumine, de lo contrario, se encenderá el LED verde.

Este valor ``threshold`` necesita ser ajustado según la situación real, puedes cargar primero el código, luego abrir el monitor serial para verificar el valor, registrar el valor en condiciones húmedas y secas, y luego elegir un valor medio como el valor ``threshold``.
