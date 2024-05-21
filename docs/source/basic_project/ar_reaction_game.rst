.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_reaction_game:

6.5 Juego de Reacción
==========================

Nuestro cuerpo tiene varios tiempos de reacción, como el tiempo de reacción auditivo, visual, táctil, etc.

Los tiempos de reacción tienen muchos efectos en nuestra vida diaria, por ejemplo, un tiempo de reacción más lento de lo normal al conducir puede llevar a consecuencias graves.

En este proyecto, usamos 3 botones y 2 LEDs para medir nuestro tiempo de reacción visual.

El monitor serial de Arduino muestra el mensaje "esperando..."
Después de presionar el botón Listo, uno de los dos LEDs debe encenderse aleatoriamente después de un intervalo de tiempo aleatorio. Es importante que el examinado presione el botón correspondiente lo más rápido posible.
Arduino registra la diferencia de tiempo entre cuando se enciende el LED y cuando la persona presiona el botón correspondiente, e imprime el tiempo de respuesta medido en el monitor serial de Arduino.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Esquemático**

.. image:: img/wiring_reaction_game.png
    :align: center

**Cableado**

.. image:: img/reaction_game.png
    :align: center

**Código**

.. note::

    * Puedes abrir directamente el archivo ``6.5_reaction_time.ino`` en la ruta ``3in1-kit\basic_project\6.5_reversingAid``.
    * O copia este código en Arduino IDE.
    
    * Por favor, asegúrate de haber añadido la biblioteca ``LiquidCrystal_I2C``, para tutoriales detallados consulta :ref:`install_libraries_ar`.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/4313dd1c-e1d2-4939-ae20-0a5b82a12390/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**¿Cómo funciona?**

#. Inicializa los botones y LEDs, se utilizan 2 interrupciones aquí para leer el estado de los botones.

    .. code-block:: arduino

        void setup()
        {
            ...
            attachInterrupt(digitalPinToInterrupt(buttonPin1), pressed1, FALLING);
            attachInterrupt(digitalPinToInterrupt(buttonPin2), pressed2, FALLING);
            ...
        }

#. Si se presiona el botón ``rstBtn``, el juego comienza de nuevo. En un tiempo aleatorio entre 2 y 5ms, haz que uno de los LEDs se ilumine.

    .. code-block:: arduino

        void loop()
        {
            if (flag == -1 && digitalRead(rstBtn) == LOW) {
                digitalWrite(ledPin1, LOW);
                digitalWrite(ledPin2, LOW);
                Serial.println("Waiting...");
                int randomTime = random(2000, 5000);
                delay(randomTime);

                timer = millis();
                flag = randomTime % 2;
                Serial.println("Light!");

                if (flag == 0) {
                    digitalWrite(ledPin1, HIGH);
                } else if (flag == 1) {
                    digitalWrite(ledPin2, HIGH);
                }
            }
            delay(200);
        }

    * Cuando la bandera es -1 y se presiona el botón ``rstBtn``, usa la función ``random()`` para generar un tiempo aleatorio de 2-5s.
    * Este tiempo se utiliza luego para controlar el encendido de los LEDs.
    * Además, el encendido de los 2 LEDs se genera aleatoriamente con ``randomTime % 2`` con 0 y 1. Si la bandera es 0, se enciende el LED1; si es 1, se enciende el LED2.

#. Acerca de la función ``pressed1()``

    .. code-block:: arduino

        void pressed1() {
            if (flag == -1) {
                return;
            }
            if (flag == 0) {
                int currentTime = millis();
                Serial.print("Correct! You reaction time is : ");
                Serial.print(currentTime - timer);
                Serial.println(" ms");
            } else if (flag == 1) {
                Serial.println("Wrong Click!");
            }
            flag = -1;
        }

    Esta es la función que se activará cuando se presione el botón 1. Cuando se presiona el botón 1, si la bandera es 0 en ese momento, se imprimirá el tiempo de respuesta, de lo contrario se indicará el error de presión.

#. Acerca de la función ``pressed2()``

    .. code-block:: arduino

        void pressed2() {
            if (flag == -1) {
                return;
            }
            if (flag == 1) {
                int currentTime =millis();
                Serial.print("Correct! You reaction time is : ");
                Serial.print(currentTime - timer);
                Serial.println(" ms");
            } else if (flag == 0) {
                Serial.println("Wrong Click!");
            }
            flag = -1;
        }

    Esta es la función que se activará cuando se presione el botón 2. Cuando se presiona el botón 2, si la bandera es 1 en ese momento, se imprimirá el tiempo de respuesta, de lo contrario se indicará el error de presión.

