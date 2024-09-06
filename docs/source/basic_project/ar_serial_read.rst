.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri nuovi prodotti.
    - **Promozioni festive e omaggi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_serial_read:

5.12 Lettura seriale
=========================

Potresti aver notato l'uso della funzione ``Serial.print()``. Se esiste la stampa, esiste anche la lettura? A cosa serve la casella di testo nel Monitor Serial?
Esatto, ci sono modi per controllare programmi e circuiti inserendo informazioni nella casella di testo del Monitor Serial.

In questo progetto, utilizzeremo l'I2C LCD1602 per visualizzare il testo inserito nel Monitor Serial, sperimentando così l'uso di ``Serial.read()``.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|


**Schema**

.. image:: img/circuit_7.1_lcd1602.png

**Collegamenti**

.. image:: img/lcd_bb.jpg
    :width: 800
    :align: center

**Codice**

.. note::

    * Apri il file ``5.12.serial_read.ino`` nel percorso ``3in1-kit\basic_project\5.12.serial_read``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    * La libreria ``LiquidCrystal I2C`` è utilizzata qui, puoi installarla dal **Library Manager**.

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/a6197c53-6969-402e-8930-84a9165397b9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Dopo che il codice è stato caricato correttamente, puoi inserire del testo nella casella di testo del Monitor Serial e l'LCD visualizzerà le informazioni.

**Come funziona?**

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

* ``Serial.available()`` ottiene il numero di caratteri disponibili nello stream in entrata quando digiti qualcosa nella casella di testo. Poiché ci sono due terminatori nell'input, in realtà hai 3 caratteri quando digiti ``A``, e 4 caratteri quando digiti ``AB``.
* ``Serial.read()`` prende il primo carattere dallo stream in entrata. Ad esempio, se hai digitato ``AB``, chiamando ``Serial.read()`` una sola volta otterrai il carattere ``A``; alla seconda chiamata otterrai ``B``; alla terza e quarta chiamata otterrai i due simboli di fine; chiamando questa funzione quando non ci sono caratteri disponibili nello stream di input causerà un errore.

In sintesi, è comune combinare le due funzioni sopra utilizzando un ciclo ``while`` per leggere tutti i caratteri immessi ogni volta.

    .. code-block:: arduino

        while (Serial.available() > 0) {
            Serial.print(Serial.read());
        }

Inoltre, se non usi ``Serial.read()`` per ottenere i caratteri dallo stream in entrata, i caratteri verranno accumulati insieme.
Ad esempio, se digiti ``A`` seguito da ``AB``, lo stream in entrata accumulerà 7 caratteri.

