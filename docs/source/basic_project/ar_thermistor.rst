.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi tecnici e post-vendita con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_temp:

4.5 Termometro
===========================

Un termometro è un dispositivo che misura la temperatura o un gradiente di temperatura (il grado di caldo o freddo di un oggetto).
Un termometro ha due elementi importanti: (1) un sensore di temperatura (ad es. il bulbo di un termometro a mercurio o il sensore pirometrico di un termometro a infrarossi) in cui avviene una variazione in base alla temperatura; 
e (2) un mezzo per convertire questa variazione in un valore numerico (ad es. la scala visibile su un termometro a mercurio o il display digitale su un modello a infrarossi).
I termometri sono ampiamente utilizzati in tecnologia e nell'industria per monitorare i processi, in meteorologia, in medicina e nella ricerca scientifica.

Un termistore è un tipo di sensore di temperatura la cui resistenza dipende fortemente dalla temperatura, ed esistono due tipi:
Coefficiente di Temperatura Negativo (NTC) e Coefficiente di Temperatura Positivo (PTC),
noti anche come NTC e PTC. La resistenza del termistore PTC aumenta con l'aumentare della temperatura, mentre per l'NTC accade l'opposto.

In questo esperimento utilizziamo un **termistore NTC** per realizzare un termometro.

**Componenti necessari**

In questo progetto, ci servono i seguenti componenti.

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
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

**Schema**

.. image:: img/circuit_5.5_thermistor.png

Ogni termistore ha una resistenza nominale. In questo caso è di 10k ohm, misurata a 25 gradi Celsius.

Quando la temperatura aumenta, la resistenza del termistore diminuisce. Poi i dati di tensione vengono convertiti in quantità digitali dall'adattatore A/D.

La temperatura in Celsius o Fahrenheit viene visualizzata tramite programmazione.

Ecco la relazione tra la resistenza e la temperatura:

    **RT =RN expB(1/TK – 1/TN)**

    * **RT** è la resistenza del termistore NTC alla temperatura **TK**.
    * **RN** è la resistenza del termistore NTC alla temperatura nominale TN. Qui il valore numerico di RN è 10k.
    * **TK** è una temperatura Kelvin e l'unità è K. Qui, il valore numerico di **TK** è ``273,15 + gradi Celsius``.
    * **TN** è una temperatura nominale in Kelvin; anche l'unità è K. Qui, il valore numerico di TN è ``273,15+25``.
    * E **B(beta)**, la costante di materiale del termistore NTC, è chiamata indice di sensibilità termica con un valore numerico ``3950``.
    * **exp** è l'abbreviazione di esponenziale, e il numero base ``e`` è un numero naturale ed è approssimativamente uguale a 2,7.

    Converti questa formula ``TK=1/(ln(RT/RN)/B+1/TN)`` per ottenere la temperatura in Kelvin, che sottraendo 273,15 dà i gradi Celsius.

    Questa relazione è una formula empirica. È accurata solo quando la temperatura e la resistenza sono all'interno del range effettivo.

**Collegamenti**

.. note::
    * Il termistore è nero o verde e contrassegnato con 103.

.. image:: img/thermistor_bb.png
    :width: 600
    :align: center

**Codice**

.. note::

   * Apri il file ``4.5_thermometer.ino`` nel percorso ``euler-kit/arduino/4.5_thermometer``.
   * Oppure copia questo codice nell'**Arduino IDE**.
   
   * Oppure carica il codice tramite l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

    Non dimenticare di selezionare la scheda Raspberry Pi Pico e la porta corretta prima di cliccare sul pulsante di caricamento.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1ceb0ea2-a330-4052-824d-bd6762c6f0e0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Dopo che il codice è stato caricato con successo, il Monitor Seriale stamperà le temperature in Celsius e Fahrenheit.

