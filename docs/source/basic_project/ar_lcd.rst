.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_lcd1602:

5.11.1 Display a Cristalli Liquidi
======================================

Un I2C LCD1602 è composto da un LCD1602 e da un modulo I2C. L'LCD1602 può essere utilizzato per visualizzare caratteri, numeri, ecc., ma necessita di molti pin della scheda di controllo. Dopo aver configurato un modulo I2C, bastano solo 2 pin I/O per pilotare questo LCD1602.

Ora vediamo come far funzionare questo I2C LCD1602.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|


**Schema Elettrico**


.. image:: img/circuit_7.1_lcd1602.png

**Collegamenti**

.. image:: img/lcd_bb.jpg
    :width: 800
    :align: center

.. note::
    SDA e SCL della scheda R3 corrispondono ai pin A4 e A5.

**Codice**

.. note::

    * Apri il file ``5.11.liquid_crystal_display.ino`` nel percorso ``3in1-kit\basic_project\5.11.liquid_crystal_display``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    * La libreria ``LiquidCrystal I2C`` viene utilizzata qui, puoi installarla tramite il **Library Manager**.

        .. image:: ../img/lib_liquidcrystal_i2c.png
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e49c4936-2530-4890-b86c-1017d11eae6e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Dopo aver caricato il codice correttamente, vedrai "SunFounder" e "Hello World" sull'I2C LCD1602.

.. note::
    Se il codice e i collegamenti sono corretti ma l'LCD non visualizza contenuti, puoi regolare il potenziometro sul retro.

**Come funziona?**

Chiamando la libreria ``LiquidCrystal_I2C.h``, puoi facilmente pilotare l'LCD. 

.. code-block:: arduino

    #include "LiquidCrystal_I2C.h"

Funzioni della Libreria: 

.. code-block:: arduino

    LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)

Crea una nuova istanza della classe ``LiquidCrystal_I2C`` che rappresenta un particolare LCD collegato alla tua scheda Arduino.

* ``lcd_AddR``: L'indirizzo dell'LCD è di default 0x27.
* ``lcd_cols``: L'LCD1602 ha 16 colonne.
* ``lcd_rows``: L'LCD1602 ha 2 righe.


.. code-block:: arduino

    void init()

Inizializza l'LCD.

.. code-block:: arduino

    void backlight()

Accende la retroilluminazione (opzionale).

.. code-block:: arduino

    void nobacklight()

Spegne la retroilluminazione (opzionale).

.. code-block:: arduino

    void display()

Accende il display LCD.

.. code-block:: arduino

    void nodisplay()

Spegne rapidamente il display LCD.

.. code-block:: arduino

    void clear()

Cancella il display e imposta la posizione del cursore a zero.

.. code-block:: arduino

    void setCursor(uint8_t col,uint8_t row)

Imposta la posizione del cursore su colonna e riga specificate.

.. code-block:: arduino

    void print(data,BASE)

Stampa testo sull'LCD.

* ``data``: I dati da stampare (char, byte, int, long o string).
* ``BASE (opzionale)``: La base con cui stampare i numeri: BIN per binario (base 2), DEC per decimale (base 10), OCT per ottale (base 8), HEX per esadecimale (base 16).

