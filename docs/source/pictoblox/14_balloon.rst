.. note::

    Ciao, benvenuto nella Community di appassionati SunFounder per Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni festive e concorsi con premi.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _sh_balloon:

2.14 GIOCO - Gonfiare il Palloncino
=========================================

In questo progetto giocheremo a un gioco di gonfiaggio dei palloncini.

Dopo aver cliccato sulla bandiera verde, il palloncino diventerà sempre più grande. Se diventa troppo grande, scoppierà; se è troppo piccolo, cadrà. Dovrai capire quando premere il pulsante per farlo volare verso l'alto.

.. image:: img/13_balloon0.png

Cosa Imparerai
----------------------

- Disegnare un costume per lo sprite

Componenti Necessari
-----------------------

In questo progetto, ci servono i seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - COMPONENTI IN QUESTO KIT
        - LINK
    *   - Kit Starter 3 in 1
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
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Costruire il Circuito
------------------------

Il pulsante è un dispositivo a 4 pin, poiché il pin 1 è collegato al pin 2 e il pin 3 al pin 4, quando viene premuto, i 4 pin sono collegati, chiudendo così il circuito.

.. image:: img/5_buttonc.png

Costruisci il circuito seguendo lo schema sottostante.

* Collega uno dei pin sul lato sinistro del pulsante al pin 12, collegato a una resistenza di pull-down e a un condensatore da 0,1uF (104) per eliminare il jitter e ottenere un livello stabile quando il pulsante è in funzione.
* Collega l'altra estremità della resistenza e del condensatore a GND, e uno dei pin sul lato destro del pulsante a 5V.

.. image:: img/circuit/button_circuit.png

Programmazione
------------------

**1. Aggiungi uno sprite e uno sfondo**

Elimina lo sprite predefinito, clicca sul pulsante **Scegli uno Sprite** nell'angolo in basso a destra dell'area sprite, poi seleziona lo sprite **Balloon1**.

.. image:: img/13_balloon1.png

Aggiungi uno sfondo **Boardwalk** tramite il pulsante **Scegli uno sfondo** o altri sfondi che preferisci.

.. image:: img/13_balloon2.png

**2. Disegna un costume per lo sprite Balloon1**

Ora disegniamo un costume effetto esplosione per lo sprite del palloncino.

Vai alla pagina **Costumi** dello sprite **Balloon1**, clicca sul pulsante **Scegli un Costume** nell'angolo in basso a sinistra e seleziona **Disegna** per aprire un **Costume** vuoto.

.. image:: img/13_balloon7.png

Seleziona un colore e poi usa lo strumento **Pennello** per disegnare un motivo.

.. image:: img/13_balloon3.png

Seleziona nuovamente un colore, clicca sullo strumento **Riempi** e muovi il mouse all'interno del motivo per riempirlo di colore.

.. image:: img/13_balloon4.png

Infine, scrivi la parola BOOM per completare il costume con effetto esplosione.

.. image:: img/13_balloon5.png

**3. Script dello sprite Palloncino**

Imposta la posizione iniziale e la dimensione dello sprite **Balloon1**.

.. image:: img/13_balloon6.png

Poi fai in modo che lo sprite **Balloon** cresca lentamente.

.. image:: img/13_balloon8.png

Quando il pulsante viene premuto (valore è 1), la dimensione dello sprite **Balloon1** smetterà di crescere.

* Quando la dimensione è inferiore a 90, il palloncino cadrà (la coordinata y diminuisce).
* Quando la dimensione è maggiore di 90 e inferiore a 120, volerà verso l'alto (la coordinata y aumenta).

.. image:: img/13_balloon9.png

Se il pulsante non è stato premuto, il palloncino continuerà a crescere e quando la dimensione supererà 120, esploderà (passando al costume effetto esplosione).

.. image:: img/13_balloon10.png
