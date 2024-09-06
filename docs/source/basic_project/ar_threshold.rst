.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi tecnici e post-vendita con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_threshold:

5.2 Soglia
=======================

In molti progetti ti capiterà di avere questa necessità:
"Quando xxx raggiunge un certo livello, allora..."

Ad esempio, in una casa intelligente, quando l'intensità luminosa scende sotto i 50Lux, accendere la luce;
Un altro esempio è sulla scheda madre di un computer: se la temperatura operativa della CPU supera i 65 gradi Celsius, accendere la ventola, e così via.

In questi casi, la parola chiave è "soglia".

Possiamo regolare il valore della soglia per far funzionare il circuito in modo più adeguato alle esigenze personali.
Ad esempio, se preferisco un ambiente più luminoso, posso aumentare la soglia delle luci automatiche della casa intelligente a 80Lux.
Un altro esempio è che la ventilazione del mio studio non è delle migliori e ho una maggiore necessità di dissipazione del calore, quindi posso regolare la soglia di accensione automatica della ventola a 50 gradi Celsius.

In questo progetto utilizziamo un sensore di umidità del suolo e 2 LED per creare un monitor per piante. Se il terreno è troppo secco, si accenderà il LED rosso; se il terreno è abbastanza umido, si accenderà il LED verde. È necessario regolare manualmente le soglie per determinare la secchezza e l'umidità del terreno.

**Componenti necessari**

In questo progetto ci servono i seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Puoi anche acquistarli separatamente dai link sottostanti.

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
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schema**

.. image:: img/circuit_8.2_threshold.png

**Collegamenti**

.. image:: img/threshold_bb.png
    :width: 600
    :align: center

**Codice**

.. note::

    * Apri il file ``5.2.threshold.ino`` nel percorso ``3in1-kit\basic_project\5.2.threshold``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/9936413a-6e6c-4e57-b0c6-5df58dd48a3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Dopo che il codice è stato caricato correttamente, se la soglia è impostata correttamente, vedrai il LED rosso accendersi quando il terreno è secco per ricordarti di annaffiare; dopo l'annaffiatura si accenderà il LED verde.

**Come funziona**

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

Imposta prima un valore di ``threshold`` e poi leggi il valore del modulo di umidità del suolo; il suo valore diminuisce all'aumentare dell'umidità. Se il valore attualmente letto è maggiore della ``threshold`` impostata, si accenderà il LED rosso, altrimenti si accenderà il LED verde.

Questo valore di ``threshold`` deve essere regolato in base alla situazione reale: puoi caricare prima il codice, aprire il monitor seriale per controllare il valore, registrare il valore in condizioni di umidità e di secchezza e poi scegliere un valore intermedio come soglia.
