.. _ar_reversing_aid:

6.4 Ayuda para Reversa
=========================

Con el desarrollo de la ciencia y la tecnología, se han instalado muchos productos de alta tecnología en los automóviles, entre los cuales el sistema de asistencia para la reversa es uno de ellos. Aquí utilizamos un módulo ultrasónico, LCD, LED y zumbador para hacer un sistema simple de asistencia ultrasónica para la reversa.

**Componentes Necesarios**

Para este proyecto, necesitamos los siguientes componentes.

Comprar un kit completo es definitivamente conveniente, aquí está el enlace:

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Esquemático**

.. image:: img/image265.png
    :width: 800
    :align: center

**Cableado**

.. image:: img/backcar.png
    :width: 800
    :align: center

**Código**

.. note::

    * Puedes abrir directamente el archivo ``6.4_reversingAid.ino`` en la ruta ``3in1-kit\basic_project\6.4_reversingAid``.
    * O copia este código en Arduino IDE.
    * Aquí se utiliza la biblioteca ``LiquidCrystal I2C``, puedes instalarla desde el **Library Manager**.

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d6848669-fe79-42e9-afd7-0f083f96a6d6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de que el código se haya cargado con éxito, la distancia detectada actual se mostrará en el LCD. Luego, el zumbador cambiará la frecuencia de sonido según las diferentes distancias.

.. note::
    Si el código y la conexión están bien, pero el LCD todavía no muestra contenido, puedes girar el potenciómetro en la parte trasera.

**¿Cómo funciona?**

Este código nos ayuda a crear un dispositivo sencillo de medición de distancia que puede medir la distancia entre objetos y proporcionar retroalimentación a través de una pantalla LCD y un zumbador.

La función ``loop()`` contiene la lógica principal del programa y se ejecuta continuamente. Vamos a echar un vistazo más de cerca a la función ``loop()``.

#. Bucle para leer la distancia y actualizar parámetros

    En el ``loop``, el código primero lee la distancia medida por el módulo ultrasónico y actualiza el parámetro de intervalo basado en la distancia.

    .. code-block:: arduino

        // Update the distance
        distance = readDistance();

        // Update intervals based on distance
        if (distance <= 10) {
            intervals = 300;
        } else if (distance <= 20) {
            intervals = 500;
        } else if (distance <= 50) {
            intervals = 1000;
        } else {
            intervals = 2000;
        }

#. Verificar si es momento de pitar

    El código calcula la diferencia entre el tiempo actual y el último pitido, y si la diferencia es mayor o igual al tiempo del intervalo, activa el zumbador y actualiza el tiempo del último pitido.

    .. code-block:: arduino

        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= intervals) {
            Serial.println("Beeping!");
            beep();
            previousMillis = currentMillis;
        }

#. Actualizar pantalla LCD

    El código limpia la pantalla LCD y luego muestra "Dis:" y la distancia actual en centímetros en la primera línea.

    .. code-block:: arduino

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dis: ");
        lcd.print(distance);
        lcd.print(" cm");

        delay(100);