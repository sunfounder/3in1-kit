.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Unisciti agli appassionati per approfondire Raspberry Pi, Arduino ed ESP32 insieme a noi.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e affronta sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti riservati sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_eeprom:

6.2 Dado Digitale
=============================

Qui utilizziamo un pulsante, un display a 7 segmenti e un 74hc595 per creare un dado elettronico.
Ogni volta che si preme il pulsante, viene generato un numero casuale compreso tra 1 e 6 e visualizzato sul display a 7 segmenti.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|

**Schema**

.. image:: img/circuit_8.9_eeprom.png

**Collegamenti**

.. image:: img/wiring_electronic_dice.png
    :width: 800
    :align: center

**Codice**

.. note::

    * Apri il file ``6.2.electronic_dice.ino`` nel percorso ``3in1-kit\basic_project\6.2.electronic_dice``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    
    * Oppure carica il codice tramite `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8d8ad340-b1de-4518-917b-caaf07e4baf4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Quando il codice è caricato correttamente, il display a 7 segmenti mostrerà 0-7 in una rapida sequenza, e quando si preme il pulsante, visualizzerà un numero casuale e interromperà lo scorrimento. La sequenza di scorrimento ricomincia quando si preme nuovamente il pulsante.

**Come funziona?**

Questo progetto è basato su :ref:`ar_segment` con un pulsante per avviare/mettere in pausa la sequenza di scorrimento sul display a 7 segmenti.

#. Inizializza ciascun pin e leggi il valore del pulsante.

    .. code-block:: arduino

        void setup ()
        {

            ...
            attachInterrupt(digitalPinToInterrupt(buttonPin), rollDice, FALLING);
        }

    * Qui viene utilizzato un interrupt per leggere lo stato del pulsante. Il valore predefinito di ``buttonPin`` è basso, che passa da basso ad alto quando si preme il pulsante.
    * ``rollDice`` rappresenta la funzione da chiamare quando l'interrupt viene attivato, ed è utilizzata per alternare il valore della variabile ``state``.
    * ``FALLING`` significa che l'interrupt viene attivato quando ``buttonPin`` passa da alto a basso.

#. Quando la variabile ``state`` è 0, la funzione ``showNumber()`` viene chiamata per far sì che il display a 7 segmenti visualizzi casualmente un numero tra 1 e 7.

    .. code-block:: arduino

        void loop()
        {
            if (state == 0) {
                showNumber((int)random(1, 7));
                delay(50);
            }
        }

#. A proposito della funzione ``rollDice()``.

    .. code-block:: arduino

        void rollDice() {
            state = !state;
        }
    
    Quando questa funzione viene chiamata, alterna il valore di state, ad esempio da 1 a 0 e viceversa.

#. A proposito della funzione ``showNumber()``.

    .. code-block:: arduino

        void showNumber(int num) {
            digitalWrite(STcp, LOW); //ground ST_CP and hold low for as long as you are transmitting
            shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
            //return the latch pin high to signal chip that it
            //no longer needs to listen for information
            digitalWrite(STcp, HIGH); //pull the ST_CPST_CP to save the data
        }
    
    Questo è il codice dentro ``loop()`` nel progetto :ref:`ar_segment` nella funzione ``showNumber()``.

