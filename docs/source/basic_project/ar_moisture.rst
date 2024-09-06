.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri nuovi prodotti.
    - **Promozioni e Omaggi Festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_moisture:

4.4 Misurare l'Umidità del Suolo
======================================

Nell'industria agricola, le colture non possono ottenere direttamente gli elementi inorganici presenti nel suolo.
L'acqua nel suolo agisce come un solvente che dissolve questi elementi inorganici.

Le colture assorbono l'umidità del suolo attraverso il sistema radicale, ottengono nutrienti e promuovono la crescita.

Durante la crescita e lo sviluppo delle colture, le esigenze di temperatura del suolo variano.
Per questo motivo, è necessario un sensore di umidità del suolo.

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
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schema Elettrico**

.. image:: img/circuit_5.4_soil.png

**Collegamenti**

.. image:: img/measure_the_moisture_bb.jpg
    :width: 800
    :align: center

**Codice**

.. note::

    * Apri il file ``4.4.measure_soil_moisture.ino`` nel percorso ``3in1-kit\basic_project\4.4.measure_soil_moisture``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    
    * Oppure carica il codice tramite il `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b6f7e756-0f14-4117-9bb2-ee5083b6445f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Una volta caricato correttamente il codice, il monitor seriale stamperà il valore dell'umidità del suolo.

Inserendo il modulo nel suolo e annaffiandolo, il valore del sensore di umidità del suolo diminuirà.
