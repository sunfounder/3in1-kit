.. note::

    Ciao, benvenuto nella Community SunFounder di appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_moving_mouse:

2.5 Topolino in Movimento
=============================

Oggi realizzeremo un giocattolo a forma di topo controllato da un potenziometro.

Quando clicchi sulla bandierina verde, il topolino sul palco si muoverà in avanti, e ruotando il potenziometro, il topolino cambierà direzione.

.. image:: img/6_mouse.png

Cosa imparerai
-----------------

- Principio del potenziometro
- Leggere pin analogici e intervalli
- Mappare un intervallo su un altro
- Muovere e cambiare la direzione di uno sprite

Componenti necessari
------------------------

In questo progetto, abbiamo bisogno dei seguenti componenti. 

È sicuramente conveniente acquistare un intero kit, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - COMPONENTI IN QUESTO KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Puoi anche acquistarli separatamente dai link seguenti.

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
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

Costruire il circuito
-------------------------

Il potenziometro è un elemento resistivo con 3 terminali. I due pin laterali sono collegati a 5V e GND, mentre il pin centrale è collegato a A0. Dopo la conversione tramite il convertitore ADC della scheda Arduino, l'intervallo di valori sarà compreso tra 0 e 1023.

.. image:: img/circuit/potentiometer_circuit.png

Programmazione
------------------

**1. Scegli uno sprite**

Elimina lo sprite predefinito, clicca sul pulsante **Scegli uno Sprite** nell'angolo inferiore destro dell'area degli sprite, inserisci **mouse** nella barra di ricerca, quindi clicca per aggiungerlo.

.. image:: img/6_sprite.png

**2. Creare una variabile**

Crea una variabile chiamata **valore** per memorizzare il valore letto dal potenziometro.

Una volta creata, vedrai **valore** apparire nella palette **Variabili** e in stato selezionato, il che significa che questa variabile apparirà sul palco.

.. image:: img/6_value.png

**3. Leggere il valore di A0**

Memorizza il valore letto da A0 nella variabile **valore**.

* [set my variable to 0]: Imposta il valore della variabile.
* [read analog pin A0]: Legge il valore di A0~A5 nell'intervallo 0-1023.

.. image:: img/6_read_a0.png

Per continuare la lettura in modo continuo, devi utilizzare il blocco [per sempre]. Clicca su questo script per eseguirlo, ruota il potenziometro in entrambe le direzioni e vedrai che l'intervallo dei valori è compreso tra 0 e 1023.

.. image:: img/6_1023.png

**4. Muovere lo sprite**

Usa il blocco [muovi passi] per muovere lo sprite. Esegui lo script e vedrai lo sprite muoversi dal centro verso destra.

.. image:: img/6_move.png

**5. Cambiare la direzione dello sprite**

Ora cambia la direzione del movimento dello sprite in base al valore di A0. Poiché il valore di A0 varia da 0 a 1023, ma la direzione di rotazione dello sprite va da -180 a 180, è necessario utilizzare un blocco [mappa].

Aggiungi anche [quando si clicca sulla bandiera verde] all'inizio per avviare lo script.

* [`point in direction <https://en.scratch-wiki.info/wiki/Point_in_Direction_()_(block)>`_]: Imposta l'angolo di sterzata dello sprite, dalla palette **Movimento**.
* [mappa da a]: Mappa un intervallo su un altro intervallo.

.. image:: img/6_direction.png
