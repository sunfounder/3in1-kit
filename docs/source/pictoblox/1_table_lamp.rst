.. note::

    Ciao, benvenuto nella Community SunFounder di appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_table_lamp:

2.1 Lampada da tavolo
=========================

In questo progetto, collegheremo un LED sulla breadboard e faremo in modo che lo sprite controlli il lampeggiamento di questo LED.

Quando il pulsante sprite sul palco viene cliccato, il LED lampeggerà 5 volte e poi si fermerà.

.. image:: img/2_button.png

Cosa imparerai
-----------------

- Breadboard, LED e resistori
- Costruire un circuito su una breadboard
- Eliminare e selezionare sprite
- Cambiare costumi
- Impostare un numero limitato di cicli di ripetizione

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
    *   - :ref:`cpn_led`
        - |link_led_buy|

Costruire il circuito
-------------------------

Segui il diagramma qui sotto per costruire il circuito sulla breadboard.

Poiché l'anodo del LED (il piedino più lungo) è collegato al pin 9 tramite una resistenza da 220Ω, e il catodo del LED è collegato a GND, puoi accendere il LED fornendo un livello alto al pin 9.

.. image:: img/circuit/led_circuit.png

Programmazione
-----------------

L'intera programmazione è suddivisa in 3 parti: la prima parte riguarda la selezione dello sprite desiderato, la seconda parte il cambio del costume dello sprite per renderlo cliccabile, e la terza parte per far lampeggiare il LED.

**1. Selezionare lo sprite Button3**

Elimina lo sprite Tobi esistente utilizzando il pulsante Elimina nell'angolo in alto a destra e seleziona nuovamente uno sprite.

.. image:: img/2_tobi.png

Qui, selezioniamo lo sprite **Button3**.

.. image:: img/2_button3.png

Clicca su Costumi nell'angolo in alto a destra e vedrai che lo sprite Button3 ha 2 costumi, imposta **button3-a** come rilasciato e **button3-b** come premuto.

.. image:: img/2_button3_2.png

**2. Cambio dei costumi**

Quando lo sprite viene cliccato (paletta **Eventi**), cambia il costume in **button3-b** (paletta **Aspetto**).

.. image:: img/2_switch.png

**3. Far lampeggiare il LED 5 volte**

Utilizza il blocco [Ripeti] per far lampeggiare il LED 5 volte (ciclo High-> Low), ricordati di cambiare il pin 13 con il pin 9, e infine torna al costume **button3-a**.

* [Ripeti 10]: ciclo di ripetizione limitato, puoi impostare tu stesso il numero di ripetizioni, dalla paletta **Controllo**.

.. image:: img/2_led_on_off.png




