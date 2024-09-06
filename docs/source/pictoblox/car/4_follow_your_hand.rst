.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni e concorsi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_follow1:

3.4 Segui la tua mano
============================

Pensa a questa macchina come se fosse il tuo animale domestico: quando gli fai un cenno con la mano, verrà correndo verso di te.

Componenti Necessari
------------------------

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

Costruisci il Circuito
---------------------------

Un modulo sensore a ultrasuoni è uno strumento che misura la distanza da un oggetto utilizzando onde sonore ultrasoniche.
Ha due sonde: una invia le onde ultrasoniche, l'altra le riceve e trasforma il tempo di invio e ricezione in una distanza, rilevando così la distanza tra il dispositivo e un ostacolo.

Ora costruisci il circuito seguendo lo schema seguente.

.. list-table:: 

    * - Modulo Ultrasonico
      - Scheda R3
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

.. image:: img/car_6.png
    :width: 800

Programmazione
-----------------

Crea blocchi per far avanzare la macchina e fermarla.

.. image:: img/4_hand1.png

Metti la mano davanti alla macchina, poi leggi il valore del modulo ultrasonico: se la distanza rilevata della tua mano è tra 5 e 10 cm, fai avanzare la macchina, altrimenti fermala.

.. image:: img/4_hand2.png