.. note::

    Ciao, benvenuto nella Community SunFounder di appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_colorful_ball:

2.3 Palline Colorate
=======================

In questo progetto, faremo sì che i LED RGB mostrino colori diversi.

Cliccando su diverse palline colorate nell'area del palco, il LED RGB si illuminerà nei colori corrispondenti.

.. image:: img/4_color.png

Cosa imparerai
-----------------

- Il principio del LED RGB
- Copiare sprite e selezionare costumi diversi
- Sovrapposizione dei tre colori primari

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

Costruire il circuito
-------------------------

Un LED RGB racchiude tre LED rosso, verde e blu in un involucro di plastica trasparente o semitrasparente. Può visualizzare vari colori modificando la tensione di ingresso dei tre pin e sovrapponendoli, il che, secondo le statistiche, può creare 16.777.216 colori diversi.

.. image:: img/4_rgb.png
    :width: 300

.. image:: img/circuit/rgb_circuit.png

Programmazione
-----------------

**1. Selezionare uno sprite**

Elimina lo sprite predefinito, poi scegli lo sprite **Palla**.

.. image:: img/4_ball.png

Duplicalo 5 volte.

.. image:: img/4_duplicate_ball.png

Scegli costumi diversi per questi 5 sprite **Palla** e posizionali nelle posizioni corrispondenti.

.. note::

    Il colore del costume dello sprite **Palla3** deve essere cambiato manualmente in rosso.

.. image:: img/4_rgb1.png
    :width: 800

**2. Fare in modo che i LED RGB si accendano nel colore appropriato**

Prima di comprendere il codice, dobbiamo capire il `RGB color model <https://en.wikipedia.org/wiki/RGB_color_model>`_.

Il modello di colore RGB è un modello additivo in cui la luce rossa, verde e blu viene aggiunta insieme in vari modi per riprodurre una vasta gamma di colori.

Miscelazione additiva dei colori: aggiungendo rosso al verde si ottiene il giallo; aggiungendo verde al blu si ottiene il ciano; aggiungendo blu al rosso si ottiene il magenta; aggiungendo insieme i tre colori primari si ottiene il bianco.

.. image:: img/4_rgb_addition.png
  :width: 400

Quindi, il codice per far accendere il LED RGB in giallo è il seguente.

.. image:: img/4_yellow.png


Quando lo sprite Palla (palla gialla) viene cliccato, impostiamo il pin 11 su HIGH (LED rosso acceso), il pin 10 su HIGH (LED verde acceso) e il pin 9 su LOW (LED blu spento), così il LED RGB si illuminerà di giallo.

Puoi scrivere i codici per gli altri sprite allo stesso modo per far accendere i LED RGB nei colori corrispondenti.

**3. Sprite Palla2 (azzurro)**

.. image:: img/4_blue.png

**4. Sprite Palla3 (rosso)**

.. image:: img/4_red.png

**5. Sprite Palla4 (verde)**

.. image:: img/4_green.png

**6. Sprite Palla5 (viola)**

.. image:: img/4_purple.png



