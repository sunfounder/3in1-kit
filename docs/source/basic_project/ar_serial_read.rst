.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_serial_read:

5.12 Lectura Serial
======================

Puede que lo hayas notado al usar la función ``Serial.print()``.
Si hay impresión, ¿hay lectura? ¿Para qué se utiliza el cuadro de texto en el Monitor Serial?
Sí, lo has adivinado, existen formas de controlar programas y circuitos ingresando información a través del cuadro de texto en el Monitor Serial.

En este proyecto, usaremos el I2C LCD1602 para mostrar el texto ingresado en el Monitor Serial con el fin de experimentar el uso de ``Serial.read()``.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|


**Esquemático**

.. image:: img/circuit_7.1_lcd1602.png

**Cableado**

.. image:: img/lcd_bb.jpg
    :width: 800
    :align: center

**Código**

.. note::

    * Abre el archivo ``5.12.serial_read.ino`` en la ruta ``3in1-kit\basic_project\5.12.serial_read``.
    * O copia este código en el **Arduino IDE**.
    * Aquí se utiliza la biblioteca ``LiquidCrystal I2C``, puedes instalarla desde el **Library Manager**.

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/a6197c53-6969-402e-8930-84a9165397b9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Después de cargar el código con éxito, puedes introducir texto en el cuadro de texto del monitor serial y el LCD mostrará la información.

**¿Cómo funciona?**

    .. code-block:: arduino

        void loop()
        {
        // when characters arrive over the serial port...
            if (Serial.available()) {
                // wait a bit for the entire message to arrive
                delay(100);
                // clear the screen
                lcd.clear();
                // read all the available characters
                while (Serial.available() > 0) {
                    // display each character to the LCD
                    lcd.write(Serial.read());
                }
            }
        }

* ``Serial.available()`` puede obtener el número de caracteres disponibles en el flujo entrante cuando escribes algo en el cuadro de texto. Dado que hay dos terminadores en la entrada, en realidad tienes 3 caracteres cuando escribes ``A``, y 4 caracteres cuando escribes ``AB``.
* ``Serial.read()`` tomará el primer carácter del flujo entrante. Por ejemplo, si escribes ``AB``, al llamar ``Serial.read()`` una sola vez, obtendrás el carácter ``A``; en la segunda llamada, obtendrás ``B``; en la tercera y cuarta llamada, obtendrás dos símbolos de fin; llamar a esta función cuando el flujo de entrada no tiene caracteres disponibles resultará en un error.

En resumen, es común combinar los dos anteriores, utilizando un bucle ``while`` para leer todos los caracteres introducidos cada vez.

    .. code-block:: arduino

        while (Serial.available() > 0) {
            Serial.print(Serial.read());
        }

Por cierto, si no usas ``Serial.read()`` para obtener caracteres del flujo entrante, los caracteres de este flujo se acumularán juntos.
Por ejemplo, si escribes ``A`` seguido de ``AB``, el flujo entrante acumulará 7 caracteres.
