.. note::

    Ciao, benvenuto nella Community SunFounder di appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_doorbell:

2.6 Campanello
=================

In questo progetto, utilizzeremo il pulsante e la campanella sullo stage per creare un campanello.

Dopo aver cliccato sulla bandierina verde, puoi premere il pulsante e la campanella sullo stage emetterà un suono.

.. image:: img/7_doorbell.png

Cosa imparerai
-----------------

- Come funziona un pulsante
- Leggere i valori da un pin digitale
- Creare un ciclo condizionale
- Aggiungere uno sfondo
- Riprodurre suoni

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|

Costruire il circuito
-------------------------

Il pulsante è un dispositivo a 4 pin. Poiché il pin 1 è collegato al pin 2 e il pin 3 al pin 4, quando il pulsante viene premuto, i 4 pin sono collegati, chiudendo il circuito.

.. image:: img/5_buttonc.png

Costruisci il circuito seguendo il diagramma sottostante.

* Collega uno dei pin sul lato sinistro del pulsante al pin 12, che è collegato a una resistenza pull-down e a un condensatore da 0,1uF (104) (per eliminare i disturbi e fornire un livello stabile quando il pulsante è attivo).
* Collega l'altra estremità della resistenza e del condensatore a GND e uno dei pin sul lato destro del pulsante a 5V.

.. image:: img/circuit/button_circuit.png

Programmazione
-----------------

**1. Aggiungi uno sfondo**

Clicca sul pulsante **Scegli uno Sfondo** nell'angolo in basso a destra.

.. image:: img/7_backdrop.png

Scegli **Bedroom 1**.

.. image:: img/7_bedroom2.png

**2. Seleziona lo sprite**

Elimina lo sprite predefinito, clicca sul pulsante **Scegli uno Sprite** nell'angolo in basso a destra dell'area sprite, inserisci **campanella** nella barra di ricerca e poi clicca per aggiungerla.

.. image:: img/7_sprite.png

Quindi seleziona lo sprite **campanella** sullo stage e spostalo nella posizione corretta.

.. image:: img/7_doorbell.png

**3. Premi il pulsante e la campanella emette un suono**

Usa [se allora] per creare una condizione che, quando il valore del pin 12 letto è uguale a 1 (il pulsante è premuto), il suono **xylo1** verrà riprodotto.

* [leggi stato del pin digitale]: Questo blocco proviene dalla palette **Arduino Uno** e viene utilizzato per leggere il valore di un pin digitale, il risultato sarà 0 o 1.
* [`if then <https://en.scratch-wiki.info/wiki/If_()_Then_(block)>`_]: Questo blocco è un blocco di controllo della palette **Controllo**. Se la sua condizione booleana è vera, i blocchi all'interno verranno eseguiti, altrimenti verranno ignorati.
* [riproduci suono fino al termine]: dalla palette Suoni, utilizzato per riprodurre suoni specifici.

.. image:: img/7_bell.png
