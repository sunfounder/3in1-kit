.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Immergiti più a fondo in Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato alle nuove comunicazioni sui prodotti e alle anteprime.
    - **Sconti esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_avoid2:

3.7 Evitamento ostacoli 2
==================================

Nel progetto :ref:`sh_avoid1`, sono stati utilizzati solo 2 moduli IR di evitamento ostacoli per l'evitamento, ma la distanza di rilevamento dei moduli IR è breve, il che potrebbe far sì che l'auto non riesca a evitare gli ostacoli in tempo.

In questo progetto, aggiungiamo anche un modulo a ultrasuoni per eseguire un rilevamento a lunga distanza, in modo che l'auto possa percepire ostacoli a una distanza maggiore e prendere decisioni tempestive.

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

Costruire il circuito
--------------------------

Collega il modulo a ultrasuoni e i 2 moduli IR di evitamento ostacoli contemporaneamente.

Collega il modulo a ultrasuoni alla scheda R3 come segue.

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

**1. Crea una funzione**

Fai avanzare e indietreggiare l'auto.

.. image:: img/7_avoid2_1.png

Fai indietreggiare l'auto a sinistra e a destra.

.. image:: img/7_avoid2_2.png

Ferma l'auto.

.. image:: img/7_avoid2_3.png

**2. Evitamento ostacoli di emergenza**

I 2 moduli IR di evitamento ostacoli sull'auto vengono utilizzati per l'evitamento di emergenza, rilevando ostacoli a breve distanza, angoli o ostacoli relativamente piccoli.

* Se il modulo IR sinistro rileva un ostacolo, l'auto indietreggia a sinistra.
* Se il modulo IR destro rileva un ostacolo, l'auto indietreggia a destra.
* Se entrambi i moduli rilevano l'ostacolo contemporaneamente, l'auto arretra direttamente.

.. image:: img/7_avoid2_4.png

**3. Evitamento ostacoli a lungo raggio**

Leggi il valore del modulo a ultrasuoni, quando il valore rilevato è inferiore a 10, l'auto arretra; altrimenti continua ad avanzare.

.. image:: img/7_avoid2_5.png
