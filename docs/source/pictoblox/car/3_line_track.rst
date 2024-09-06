.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni e concorsi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_line:

3.3 Segui la linea
======================

L'auto è dotata di un modulo di tracciamento della linea, che può essere utilizzato per far seguire all'auto una linea nera.

Prima di iniziare il progetto, è necessario creare un percorso curvo con del nastro nero, la larghezza consigliata della linea è compresa tra 0,8 e 1,5 cm e l'angolo della curva non deve essere inferiore a 90 gradi.

Componenti Necessari
-----------------------

In questo progetto, abbiamo bisogno dei seguenti componenti.

È decisamente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ARTICOLI IN QUESTO KIT
        - LINK
    *   - Kit 3 in 1 Starter
        - 380+
        - |link_3IN1_kit|

Puoi anche acquistarli separatamente dai link seguenti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK DI ACQUISTO

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110` 
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_track`
        - |link_track_buy|

Costruisci il Circuito
--------------------------

Questo è un modulo digitale di tracciamento della linea, quando rileva una linea nera emette 1; quando rileva una linea bianca emette un valore di 0. Inoltre, è possibile regolare la distanza di rilevamento tramite il potenziometro sul modulo.

Costruisci il circuito seguendo lo schema seguente.

.. list-table:: 

    * - Modulo di Tracciamento della Linea
      - Scheda R3
    * - S
      - 2
    * - V+
      - 5V
    * - G
      - GND

.. image:: img/car_4.png
    :width: 800

Regola il Modulo
-----------------------

Prima di iniziare il progetto, è necessario regolare la sensibilità del modulo.

Collega i fili secondo lo schema sopra, quindi alimenta la scheda R3 (collegando il cavo USB o la batteria a 9V), senza caricare il codice.

Attacca un nastro nero isolante sul tavolo e posiziona il carrello su di esso.

Osserva il LED del segnale sul modulo per assicurarti che si accenda sul tavolo bianco e si spenga sul nastro nero.

Se ciò non accade, è necessario regolare il potenziometro sul modulo affinché produca questo effetto.

.. image:: img/line_track_cali.JPG


Programmazione
----------------

Ora crea 2 blocchi che permettano all'auto di muoversi leggermente verso il fronte sinistro o verso il fronte destro.

**1. Muoversi verso il fronte sinistro**

Quando il motore destro gira in senso orario e il motore sinistro rimane fermo, l'auto si sposta leggermente verso il fronte sinistro.

.. image:: img/3_forward_left.png

**2. Muoversi verso il fronte destro**

Allo stesso modo, quando il motore sinistro gira in senso antiorario e il motore destro non si muove, l'auto si sposta leggermente verso destra.

.. image:: img/3_forward_left.png

**3. Tracciamento della linea**

Leggi il valore del modulo di tracciamento della linea, se è 1 significa che è stata rilevata la linea nera, quindi fai muovere l'auto verso il fronte sinistro, altrimenti falla muovere verso destra.

.. image:: img/3_follow.png

Dopo aver caricato il codice sulla scheda R3, allinea il modulo di tracciamento della linea sotto l'auto con la linea nera e vedrai l'auto seguire la linea.
