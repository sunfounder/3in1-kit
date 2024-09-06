.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri nuovi prodotti.
    - **Promozioni festive e omaggi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_shiftout:

5.9 ShiftOut(LED)
=======================

``shiftOut()`` consente al 74HC595 di emettere 8 segnali digitali. Esso invia l'ultimo bit del numero binario a Q0 e il primo bit a Q7. In altre parole, scrivendo il numero binario “00000001”, Q0 emetterà un livello alto e Q1~Q7 un livello basso.

In questo progetto imparerai come utilizzare il 74HC595, composto da un registro a scorrimento a 8 bit e un registro di memoria con uscite parallele a tre stati. Converte l'input seriale in output parallelo, consentendo di risparmiare le porte IO di un microcontrollore.

In particolare, il 74HC595 può sostituire 8 pin per l'uscita del segnale digitale scrivendo un numero binario a 8 bit.

* `Binary number - Wikipedia <https://en.wikipedia.org/wiki/Binary_number>`_

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
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Schema**

.. image:: img/circuit_6.4_74hc595.png

* Quando MR (pin10) è ad alto livello e OE (pin13) è a basso livello, i dati vengono immessi nel fronte di salita di SHcp e passano al registro di memoria attraverso il fronte di salita di SHcp.
* Se i due clock sono collegati insieme, il registro a scorrimento è sempre un impulso prima del registro di memoria.
* C'è un pin di ingresso seriale (Ds), un pin di uscita seriale (Q) e un pulsante di reset asincrono (livello basso) nel registro di memoria.
* Il registro di memoria fornisce un bus parallelo a 8 bit con tre stati.
* Quando OE è abilitato (livello basso), i dati nel registro di memoria vengono inviati al bus (Q0 ~ Q7).


**Collegamenti**

.. image:: img/74hc595_bb.jpg
    :width: 800
    :align: center

**Codice**

.. note::

    * Apri il file ``5.9.shiftout_led.ino`` nel percorso ``3in1-kit\basic_project\5.9.shiftout_led``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    
    * Oppure carica il codice tramite l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/4c208eb3-67f0-40f7-999a-0eeca8b6b466/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Una volta caricato correttamente il codice sulla scheda R3, vedrai i LED accendersi uno dopo l'altro.

**Come funziona?**

Dichiara un array, 
memorizza alcuni numeri binari a 8 bit utilizzati per cambiare lo stato di funzionamento degli otto LED controllati dal 74HC595. 

.. code-block:: arduino

    int datArray[] = {B00000000, B00000001, B00000011, B00000111, B00001111, B00011111, B00111111, B01111111, B11111111};

Imposta ``STcp`` su livello basso e poi su livello alto. 
Genererà un impulso di fronte di salita di STcp.

.. code-block:: arduino

    digitalWrite(STcp,LOW); 

``shiftOut()`` viene utilizzato per spostare un byte di dati un bit alla volta, 
ovvero spostare un byte di dati da ``datArray[num]`` nel registro di scorrimento 
tramite il pin ``DS``. **MSBFIRST** indica di spostare dai bit più alti.

.. code-block:: arduino

    shiftOut(DS,SHcp,MSBFIRST,datArray[num]);

Dopo che ``digitalWrite(STcp,HIGH)`` viene eseguito, ``STcp`` sarà nel fronte di salita. 
A questo punto, i dati nel registro di scorrimento verranno trasferiti nel registro di memoria.

.. code-block:: arduino

    digitalWrite(STcp,HIGH);

Un byte di dati sarà trasferito nel registro di memoria dopo 8 volte. 
Poi i dati del registro di memoria verranno inviati al bus (Q0-Q7). 
Ad esempio, ``B00000001`` accenderà il LED controllato da Q0 e spegnerà i LED controllati da Q1~Q7.

