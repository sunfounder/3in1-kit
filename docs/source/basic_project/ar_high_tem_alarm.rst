.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Unisciti agli appassionati per approfondire Raspberry Pi, Arduino ed ESP32 insieme a noi.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e affronta sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti riservati sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_high_tem_alarm:

6.3 Allarme ad Alta Temperatura
====================================

Ora realizzeremo un dispositivo di allarme ad alta temperatura utilizzando un termistore, un pulsante, un potenziometro e un LCD. 
Il display LCD1602 mostra la temperatura rilevata dal termistore e il valore soglia di alta temperatura, 
che può essere regolato utilizzando un potenziometro. 
Il valore soglia viene memorizzato su EEPROM, quindi se la temperatura corrente supera la soglia, 
il buzzer emetterà un segnale acustico.

**Componenti necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente comodo acquistare un intero kit, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - OGGETTI IN QUESTO KIT
        - LINK
    *   - Kit Starter 3 in 1
        - 380+
        - |link_3IN1_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE COMPONENTI
        - LINK DI ACQUISTO

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

**Schema**

.. image:: img/wiring_high_tem.png
   :align: center

**Collegamenti**

.. image:: img/tem_alarm.png
    :width: 800
    :align: center

**Codice**

.. note::

    * Puoi aprire il file ``6.3.high_tem_alarm.ino`` nel percorso ``3in1-kit\basic_project\6.3.high_tem_alarm`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.
    * La libreria ``LiquidCrystal I2C`` viene utilizzata qui, puoi installarla dal **Library Manager**.

        .. image:: ../img/lib_liquidcrystal_i2c.png
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1341b79d-c87e-4cea-ad90-189c2ebf40ee/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo aver caricato correttamente il codice, l'LCD1602 mostrerà la temperatura rilevata dal termistore e il valore soglia di alta temperatura, che può essere regolato utilizzando un potenziometro. Il valore soglia viene memorizzato su EEPROM, quindi se la temperatura corrente supera la soglia, il buzzer emetterà un segnale acustico.

.. note::
    Se il codice e i collegamenti sono corretti, ma l'LCD non visualizza nulla, puoi regolare il potenziometro sul retro.

**Come funziona?**

#. Inizializza il pulsante, il buzzer e l'LCD I2C1602, e leggi i valori dall'EEPROM. Viene utilizzato anche un interrupt per leggere lo stato del pulsante.

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
    
    * L'interrupt viene utilizzato per leggere lo stato del pulsante. Quando il pulsante viene premuto, ``buttonPin`` passa da basso ad alto.
    * La funzione buttonState viene chiamata quando l'interrupt viene attivato, e cambia il valore della variabile state.
    * ``FALLING`` significa che l'interrupt si verifica quando ``buttonPin`` passa da basso ad alto.

#. Per impostare la soglia di alta temperatura, la funzione ``upperTemSetting()`` viene chiamata quando state è 1 (state passa tra 0 e 1 con la pressione del pulsante) nel programma principale, altrimenti viene chiamata ``monitoringTemp()`` per visualizzare la temperatura corrente e la soglia impostata.

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

#. Riguardo alla funzione ``upperTemSetting()``.

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

    * Una soglia può essere impostata con questa funzione. Quando si entra in questa funzione, l'LCD1602 visualizza il valore soglia corrente, che può essere modificato utilizzando il potenziometro. Questo valore soglia verrà memorizzato su EEPROM e uscito quando il pulsante viene premuto di nuovo.

#. Riguardo alla funzione ``monitoringTemp()``.

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

    * Con questa funzione, puoi visualizzare la temperatura e impostare un allarme.
    * Il valore del termistore viene letto e quindi convertito in temperatura Celsius tramite la formula e visualizzato su LCD1602.
    * La soglia impostata viene anch'essa visualizzata sull'LCD.
    * Se la temperatura corrente è maggiore della soglia, il buzzer emetterà un segnale acustico.
