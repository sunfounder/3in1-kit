.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Unisciti agli appassionati per approfondire Raspberry Pi, Arduino ed ESP32 insieme a noi.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e affronta sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti riservati sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_guess_number:

6.6 Indovina il Numero
=============================

"Indovina il Numero" è un divertente gioco di società in cui tu e i 
tuoi amici vi alternate a inserire un numero (0~99). L'intervallo si 
riduce con ogni numero inserito fino a quando un giocatore indovina 
correttamente il numero fortunato. A quel punto, il giocatore viene 
sconfitto e punito. Ad esempio, se il numero fortunato è 51, che i 
giocatori non possono vedere, e il giocatore 1 inserisce 50, l'intervallo 
numerico cambia da 50~99; se il giocatore 2 inserisce 70, l'intervallo 
diventa 50~70; se il giocatore 3 inserisce 51, lui o lei è lo sfortunato. 
Qui utilizziamo un telecomando a infrarossi per inserire i numeri e un 
display LCD per mostrare i risultati.

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_receiver`
        - \-


**Schema**

.. image:: img/circuit_guess_number.png
    :align: center

**Collegamenti**

In questo esempio, i collegamenti dell'LCD1602 e del modulo di ricezione a infrarossi sono i seguenti.

.. image:: img/wiring_guess_number.png
    :align: center


**Codice**


.. note::

    * Puoi aprire il file ``6.6.guess_number.ino`` nel percorso ``3in1-kit\basic_project\6.6.guess_number`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.
    * Vengono utilizzate le librerie ``LiquidCrystal I2C`` e ``IRremote``, che puoi installare dal **Library Manager**.


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/6bafb36d-6763-460c-98b7-aba48120e718/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Dopo aver caricato correttamente il codice, i caratteri di benvenuto appariranno sull'LCD1602. Ora premi i numeri secondo l'intervallo visualizzato sullo schermo, l'intervallo si ridurrà sempre di più fino a quando non indovini il numero fortunato.

.. note::
    Se il codice e i collegamenti sono corretti, ma l'LCD non visualizza ancora nulla, puoi regolare il contrasto ruotando il potenziometro sul retro.


**Come funziona?**

Per rendere il gioco dell'indovina numero più vivace e divertente, dobbiamo 
raggiungere le seguenti funzioni:

1. Il numero fortunato verrà visualizzato all'avvio e al reset del gioco, 
e l'intervallo numerico sarà ripristinato a 0 ~ 99.

2. L'LCD visualizzerà il numero inserito e l'intervallo numerico.

3. Dopo aver inserito due cifre, verrà effettuata automaticamente la verifica 
   del risultato.

4. Se inserisci una singola cifra, puoi premere il tasto CYCLE (il tasto al 
   centro del telecomando) per avviare la verifica del risultato.

5. Se il numero non viene indovinato, verrà visualizzato un nuovo intervallo 
   numerico (se il numero fortunato è 51 e inserisci 50, l'intervallo cambierà in 50~99).

6. Il gioco verrà automaticamente resettato dopo che il numero fortunato è stato 
   indovinato, così da poter iniziare un nuovo round.

7. Il gioco può essere resettato direttamente premendo il pulsante POWER 
   (il pulsante nell'angolo in alto a sinistra).

In conclusione, il flusso di lavoro del progetto è mostrato nel diagramma di flusso.

.. image:: img/Part_three_4_Example_Explanation.png
    :align: center

