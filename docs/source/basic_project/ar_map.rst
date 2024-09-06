.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Omaggi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_map:

5.6 Map
===================

Se osservi attentamente, noterai che molti valori hanno intervalli diversi in programmazione.
Ad esempio, l'intervallo di valori per gli ingressi analogici è (0~1023).
L'intervallo di valori per l'uscita analogica è (0~255).
L'angolo di uscita del servo è (0~180).

Questo significa che, se vogliamo utilizzare il potenziometro per controllare la luminosità del LED o l'angolo del servo, dobbiamo eseguire un'operazione di mappatura.

Ora vediamo come farlo.

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**Schema Elettrico**

.. image:: img/circuit_8.3_amp.png

**Collegamenti**

.. image:: img/map_bb.jpg
    :width: 800
    :align: center

**Codice**

.. note::

    * Apri il file ``5.6.map.ino`` nel percorso ``3in1-kit\basic_project\5.6.map``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    * Oppure carica il codice tramite il `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f00e4c4c-fb13-4445-9d89-eb2857b5fe87/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Dopo aver caricato correttamente il codice, puoi ruotare avanti e indietro il potenziometro, e l'albero di uscita del servo ruoterà avanti e indietro.

**Come funziona?**

``map(value, fromLow, fromHigh, toLow, toHigh)``: Mappa un numero da un intervallo a un altro.
Ovvero, un valore da fromLow viene mappato a toLow, e un valore da fromHigh viene mappato a toHigh.

    **Sintassi**
        map(value, fromLow, fromHigh, toLow, toHigh)

    **Parametri**
        * ``value``: il numero da mappare.
        * ``fromLow``: il limite inferiore dell'intervallo corrente.
        * ``fromHigh``: il limite superiore dell'intervallo corrente.
        * ``toLow``: il limite inferiore dell'intervallo di destinazione.
        * ``toHigh``: il limite superiore dell'intervallo di destinazione.

Se il potenziometro controlla il LED, puoi anche usare la mappatura per completare il compito.

.. code-block:: arduino

    int x = analogRead(knob);
    int y = map(x,0,1023,0,255);
    analogWrite(led,y);


**Note e Avvertenze**

* Il "limite inferiore" di entrambi gli intervalli può essere maggiore o minore del "limite superiore", il che significa che la funzione ``map()`` può essere utilizzata per invertire un intervallo di numeri.

  .. code-block:: arduino

    y = map(x,0,180,180,0);

* La mappatura funziona anche bene per i numeri negativi.

  .. code-block:: arduino

    y = map(x,0,1023,-90,90);

* La mappatura utilizza numeri interi e le cifre decimali dei numeri a virgola mobile vengono scartate.
