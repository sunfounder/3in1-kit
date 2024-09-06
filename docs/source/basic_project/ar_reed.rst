.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri nuovi prodotti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_reed:

3.2 Senti il Magnetismo
===============================

Il tipo più comune di interruttore reed contiene una coppia di lamelle magnetizzabili e flessibili, i cui terminali sono separati da un piccolo spazio quando l'interruttore è aperto.

Un campo magnetico, proveniente da un elettromagnete o da un magnete permanente, farà sì che le lamelle si attraggano, completando così un circuito elettrico.
La forza elastica delle lamelle le separa e apre il circuito quando il campo magnetico cessa.

Un esempio comune di applicazione dell'interruttore reed è rilevare l'apertura di una porta o di una finestra per un sistema di allarme di sicurezza.

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
    *   - :ref:`cpn_reed`
        - \-

**Schema Elettrico**

.. image:: img/circuit_3.2_reed.png

Per impostazione predefinita, il pin 2 è basso; e diventerà alto quando il magnete sarà vicino all'interruttore reed.

Lo scopo del resistore da 10K è mantenere il pin 2 a un livello basso stabile quando nessun magnete è vicino.

**Collegamenti**

.. image:: img/feel_the_magnetism_bb.jpg
    :width: 600
    :align: center

**Codice**

.. note::

   * Puoi aprire il file ``3.2.feel_the_magnetism.ino`` nel percorso ``3in1-kit\basic_project\3.2.feel_the_magnetism``. 
   * Oppure copia questo codice nell'**Arduino IDE**.
   
   * Oppure carica il codice tramite il `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/d28c942e-5144-44a1-85d8-d5e6894fc5df/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Dopo aver caricato correttamente il codice, quando un magnete sarà vicino all'interruttore reed, il monitor seriale stamperà 1.
