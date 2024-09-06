.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Immergiti più a fondo in Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue abilità.
    - **Anteprime esclusive**: Ottieni accesso anticipato alle nuove comunicazioni sui prodotti e anteprime.
    - **Sconti esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_follow2:

3.6 Segui la tua mano 2
===============================

Nel progetto :ref:`sh_follow1`, è stato utilizzato solo il modulo a ultrasuoni, che permette all'auto di seguire la tua mano solo in avanti.

In questo progetto, utilizziamo contemporaneamente 2 moduli IR di evitamento ostacoli, in modo che l'auto possa seguire la tua mano a sinistra o a destra.

Componenti necessari
-----------------------

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

Costruire il circuito
------------------------

Collega contemporaneamente il modulo a ultrasuoni e i due moduli IR di evitamento ostacoli.

I collegamenti tra il modulo a ultrasuoni e la scheda R3 sono i seguenti.

.. list-table:: 

    * - Modulo Ultrasuoni
      - Scheda R3
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

Il cablaggio dei 2 moduli IR di evitamento ostacoli alla scheda R3 è il seguente.

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

.. image:: img/car_7_8.png
    :width: 800

Programmazione
------------------

L'effetto che si desidera ottenere con questo progetto è il seguente:

* Il modulo a ultrasuoni rileva la tua mano a circa 5-10 cm di distanza e l'auto la segue.
* Il modulo IR sinistro rileva la tua mano e l'auto si sposta a sinistra.
* Il modulo IR destro rileva la tua mano e l'auto si sposta a destra.

**1. Crea un blocco**

Crea blocchi che permettano all'auto di avanzare, girare a sinistra, girare a destra e fermarsi.

.. image:: img/6_follow2_1.png

**2. Segui per avanzare**

Leggi il valore dell'ultrasuono e se la tua mano viene rilevata a una distanza di 5-10 cm, lascia che l'auto la segua.

.. image:: img/6_follow2_2.png

**3. Segui per girare a sinistra e a destra**

Leggi i valori dei moduli IR sinistro e destro.

* Se il modulo IR sinistro rileva la tua mano, gira a sinistra.
* Se il modulo IR destro rileva la tua mano, gira a destra.
* Se nessuno dei moduli IR e il modulo a ultrasuoni rilevano la tua mano, fai fermare l'auto.

.. image:: img/6_follow2_3.png