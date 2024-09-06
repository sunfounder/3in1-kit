.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Omaggi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

6.1 Array Sensibile alla Luce
=====================================

Un fotoresistore o fotocellula è una resistenza variabile controllata dalla luce. La resistenza di un fotoresistore diminuisce all'aumentare dell'intensità della luce incidente; in altre parole, esso esibisce fotoconduttività. Un fotoresistore può essere utilizzato in circuiti di rilevamento della luce e in circuiti di attivazione tramite luce o buio.

La resistenza di un fotoresistore varia con l'intensità della luce incidente. Se l'intensità luminosa aumenta, la resistenza diminuisce; se l'intensità diminuisce, la resistenza aumenta.
In questo esperimento, useremo otto LED per mostrare l'intensità luminosa. Più alta è l'intensità della luce, più LED si accenderanno. Quando l'intensità luminosa sarà sufficiente, tutti i LED saranno accesi. Quando non ci sarà luce, tutti i LED si spegneranno.

**Componenti Necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un intero kit, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK PER L'ACQUISTO

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Schema Elettrico**

.. image:: img/circuit_6.1_light_led.png

**Collegamenti**

.. image:: img/light_control_led.png
    :width: 800
    :align: center

**Codice**

.. note::

    * Apri il file ``6.1.light_control_led.ino`` nel percorso ``3in1-kit\basic_project\6.1.light_control_led``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    * Oppure carica il codice tramite il `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/859e1688-5801-400e-9409-f844ca9b7da7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Ora, punta una luce sul fotoresistore e vedrai accendersi alcuni LED. Più intensa è la luce, più LED si accenderanno. Quando lo metti in un ambiente buio, tutti i LED si spegneranno.

**Come funziona?**

.. code-block:: arduino

    void loop() 
    {
        sensorValue = analogRead(photocellPin); //read the value of A0
        ledLevel = map(sensorValue, 300, 1023, 0, NbrLEDs); // map to the number of LEDs
        for (int led = 0; led < NbrLEDs; led++)//
        {
            if (led < ledLevel ) //When led is smaller than ledLevel, run the following code. 
            {
                digitalWrite(ledPins[led], HIGH); // turn on pins less than the level
            }
            else 
            {
                digitalWrite(ledPins[led],LOW); // turn off pins higher than 
            }
        }
    }

Utilizzando la funzione ``map()``, puoi mappare il valore del fotoresistore sui 8 LED, ad esempio, se sensorValue è 560, allora ledLevel è 4, quindi a questo punto, i ledPins[0] fino a ledPins[4] dovrebbero essere accesi, e i ledPins[5] fino a ledPins[7] dovrebbero essere spenti.

