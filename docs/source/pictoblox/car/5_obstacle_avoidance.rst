.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Immergiti più a fondo in Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue abilità.
    - **Anteprime esclusive**: Ottieni accesso anticipato a nuove comunicazioni di prodotto e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_avoid1:

3.5 Evitamento degli ostacoli
==================================

Due moduli di evitamento ostacoli a infrarossi sono montati sulla parte anteriore dell'auto e possono essere utilizzati per rilevare ostacoli vicini.

In questo progetto, l'auto può muoversi liberamente in avanti, e quando incontra un ostacolo, è in grado di evitarlo e continuare a muoversi in altre direzioni.

Componenti necessari
------------------------

In questo progetto, ci servono i seguenti componenti.

È sicuramente comodo acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - Starter Kit 3 in 1
        - 380+
        - |link_3IN1_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE COMPONENTI
        - LINK ACQUISTO

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110` 
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

Costruire il circuito
--------------------------

Il modulo di evitamento degli ostacoli è un sensore di prossimità a infrarossi con distanza regolabile, il cui output è normalmente alto e diventa basso quando viene rilevato un ostacolo.

Ora costruisci il circuito secondo il diagramma qui sotto.

.. list-table:: 

    * - Modulo IR sinistro
      - Scheda R3
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 

    * - Modulo IR destro
      - Scheda R3
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_5.png
    :width: 800

Regolare il modulo
-----------------------

Prima di iniziare il progetto, è necessario regolare la distanza di rilevamento del modulo.

Cablare secondo lo schema sopra, alimenta la scheda R3 (collegando direttamente il cavo USB o il cavo della batteria da 9V), senza caricare il codice.

Posiziona un quaderno o qualsiasi altro oggetto piatto a circa 5 cm davanti al modulo di evitamento ostacoli IR.

Quindi usa un cacciavite per ruotare il potenziometro sul modulo finché l'indicatore di segnale sul modulo si illumina appena, per regolare la distanza massima di rilevamento a 5 cm.

Segui lo stesso metodo per regolare un altro modulo a infrarossi.

.. image:: img/ir_obs_cali.jpg

Programmazione
------------------

L'effetto che vogliamo ottenere.

* Quando il modulo IR sinistro rileva un ostacolo, l'auto arretra a sinistra.
* Quando il modulo IR destro rileva un ostacolo, l'auto arretra a destra.
* Se entrambi i moduli IR rilevano l'ostacolo, l'auto arretra direttamente.
* Altrimenti, l'auto va avanti.

Ora crea i blocchi corrispondenti.

**1. L'auto arretra a sinistra**

Quando il motore destro gira in senso antiorario e il motore sinistro non gira, l'auto arretra a sinistra.

.. image:: img/5_avoid1.png

**2. L'auto arretra a destra**

Quando il motore sinistro gira in senso orario e il motore destro non gira, l'auto arretra a destra.

.. image:: img/5_avoid2.png

**3. L'auto va avanti, indietro e si ferma**

.. image:: img/5_avoid3.png

**4. Leggi i valori dei 2 moduli IR**

Fai clic su **Crea una variabile** nella palette **Variabili**.

.. image:: img/5_avoid4.png

Inserisci il nome della variabile e fai clic su **OK** per creare una nuova variabile.

.. image:: img/5_avoid5.png

Leggi i valori dei moduli di evitamento ostacoli IR sinistro e destro e memorizzali nelle 2 nuove variabili.

.. image:: img/5_avoid6.png

**5. Evitamento degli ostacoli**

* Quando il modulo IR sinistro è 0 (ostacolo rilevato) e il modulo IR destro è 1, fai arretrare l'auto a sinistra.
* Quando il modulo IR destro è 0 (ostacolo rilevato), fai arretrare l'auto a destra.
* Se 2 moduli IR rilevano l'ostacolo contemporaneamente, l'auto arretrerà.
* Altrimenti l'auto continuerà ad andare avanti.

.. image:: img/5_avoid7.png
