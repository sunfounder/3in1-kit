.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri nuovi prodotti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_photoresistor:

4.2 Rileva la Luce
===========================

Il fotoresistore è un dispositivo tipico per gli ingressi analogici ed è utilizzato in modo molto simile a un potenziometro. Il suo valore di resistenza dipende dall'intensità della luce: più forte è la luce irradiata, minore sarà la sua resistenza; viceversa, aumenterà.

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Schema Elettrico**

.. image:: img/circuit_5.2_light.png

In questo circuito, il resistore da 10K e il fotoresistore sono collegati in serie, e la corrente che li attraversa è la stessa. Il resistore da 10K funge da protezione, e il pin A0 legge il valore dopo la conversione della tensione del fotoresistore.

Quando la luce aumenta, la resistenza del fotoresistore diminuisce, quindi la sua tensione si riduce, e il valore del pin A0 aumenterà; 
se la luce è abbastanza forte, la resistenza del fotoresistore sarà prossima a 0, e il valore del pin A0 sarà vicino a 1023. 
In questo caso, il resistore da 10K svolge un ruolo protettivo, evitando che i 5V e il GND siano collegati insieme, causando un cortocircuito.

Se metti il fotoresistore in una situazione di oscurità, il valore del pin A0 diminuirà. 
In una situazione abbastanza buia, la resistenza del fotoresistore sarà infinita, e la sua tensione sarà vicina a 5V (il resistore da 10K è trascurabile), e il valore del pin A0 sarà vicino a 0.


**Collegamenti**

.. image:: img/feel_the_light_bb.jpg
    :width: 600
    :align: center


**Codice**

.. note::

    * Apri il file ``4.2.feel_the_light.ino`` nel percorso ``3in1-kit\basic_project\4.2.feel_the_light``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    
    * Oppure carica il codice tramite il `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e1bc4c8b-788e-4bfe-a0a1-532d4fdc7753/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Dopo che il codice è stato caricato correttamente, il monitor seriale stamperà i valori del fotoresistore. 
Più forte è la luminosità ambientale corrente, maggiore sarà il valore visualizzato sul monitor seriale.
