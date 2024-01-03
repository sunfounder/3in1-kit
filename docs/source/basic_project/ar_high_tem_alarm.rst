.. _ar_high_tem_alarm:

6.3 Alarma de Alta Temperatura
====================================

A continuación, crearemos un dispositivo de alarma de alta temperatura utilizando un termistor, botón, potenciómetro y LCD. 
El LCD1602 muestra la temperatura detectada por el termistor y el valor del umbral de alta temperatura, 
que puede ajustarse utilizando un potenciómetro. 
El valor del umbral se almacena en la EEPROM al mismo tiempo, así que si la temperatura actual supera el valor del umbral, 
el zumbador sonará.

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
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**Esquemático**

.. image:: img/wiring_high_tem.png
   :align: center

**Cableado**

.. image:: img/tem_alarm.png
    :width: 800
    :align: center

**Código**

.. note::

    * Puedes abrir directamente el archivo ``6.3.high_tem_alarm.ino`` en la ruta ``3in1-kit\basic_project\6.3.high_tem_alarm``.
    * O copia este código en Arduino IDE.
    * Aquí se utiliza la biblioteca ``LiquidCrystal I2C``, puedes instalarla desde el **Library Manager**.

        .. image:: ../img/lib_liquidcrystal_i2c.png
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1341b79d-c87e-4cea-ad90-189c2ebf40ee/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de que el código se haya cargado con éxito, el LCD1602 muestra la temperatura detectada por el termistor y el valor del umbral de alta temperatura, que puede ajustarse utilizando un potenciómetro. El valor del umbral se almacena en la EEPROM al mismo tiempo, así que si la temperatura actual supera el valor del umbral, el zumbador sonará.

.. note::
    Si el código y la conexión están bien, pero el LCD todavía no muestra contenido, puedes girar el potenciómetro en la parte trasera.

**¿Cómo funciona?**

#. Inicializa el botón, el zumbador y el LCD1602 I2C, y lee los valores de la EEPROM. Aquí también se utiliza una interrupción para leer el estado del botón.

    .. code-block:: arduino

        void setup()
        {
            pinMode(buzzerPin, OUTPUT);
            pinMode(buttonPin, INPUT);
            lcd.init();
            lcd.backlight();
            upperTem = EEPROM.read(0);
            delay(1000);
            attachInterrupt(digitalPinToInterrupt(buttonPin), buttonState, FALLING);
        }
    
    * Aquí se utiliza una interrupción para leer el estado del botón. Cuando se presiona el botón, ``buttonPin`` cambia de bajo a alto.
    * La función buttonState se llama cuando se activa la interrupción, y cambia el valor de la variable state.
    * ``FALLING`` significa que la interrupción ocurre cuando ``buttonPin`` pasa de bajo a alto.

#. Para establecer el umbral de alta temperatura, se llama a la función ``upperTemSetting()`` cuando state es 1 (state cambia entre 0 y 1 con la presión del botón) en el programa principal, de lo contrario se llama a ``monitoringTemp()`` para mostrar la temperatura actual y el umbral establecido.

    .. code-block:: arduino

        void loop()
        {
            if (state == 1)
            {
                upperTemSetting();
            }
            else {
                monitoringTemp();
            }
        }

#. Acerca de la función ``upperTemSetting()``.

    .. code-block:: arduino

        void upperTemSetting()
        {
            int setTem = 0;

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Adjusting...");
            lcd.setCursor(0, 1);
            lcd.print("Upper Tem: ");

            while (1) {
                lcd.setCursor(11, 1);
                setTem = map(analogRead(potPin), 0, 1023, 0, 100);
                lcd.print(setTem);
                if (state == 0)
                {
                    EEPROM.write(0, setTem);
                    upperTem = setTem;
                    lcd.clear();
                    return;
                }
            }
        }

    * Con esta función se puede establecer un umbral. Al entrar en esta función, el LCD1602 muestra el valor actual del umbral, que puede modificarse con el potenciómetro. Este valor del umbral se almacenará en la EEPROM y se saldrá cuando se vuelva a presionar el botón.

#. Acerca de la función ``monitoringTemp()``.

    .. code-block:: arduino

        void monitoringTemp()
        {
            long a = analogRead(temPin);
            float tempC = beta / (log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;
            float tempF = 1.8 * tempC + 32.0;
            lcd.setCursor(0, 0);
            lcd.print("Temp: ");
            lcd.print(tempC);
            lcd.print(char(223));
            lcd.print("C   ");
            lcd.setCursor(0, 1);
            lcd.print("Upper: ");
            lcd.print(upperTem);
            lcd.print(char(223));
            lcd.print("C   ");
            delay(300);
            if (tempC >= upperTem)
            {
                digitalWrite(buzzerPin, HIGH);
                delay(50);
                digitalWrite(buzzerPin, LOW);
                delay(10);
            }
            else
            {
                digitalWrite(buzzerPin, LOW);
            }
        }

    * Utilizando esta función, puedes mostrar la temperatura y configurar una alarma.
    * Se lee el valor del termistor y luego se convierte a temperatura en Celsius mediante la fórmula y se muestra en el LCD1602.
    * El umbral establecido también se muestra en el LCD.
    * Si la temperatura actual es mayor que el umbral, el zumbador sonará una alarma.
