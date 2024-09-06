.. note::

    Ciao, benvenuto nella Community di appassionati SunFounder per Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni festive e concorsi con premi.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _sh_rotating_fan:

2.11 Ventola Rotante
========================

In questo progetto, creeremo uno sprite a forma di stella che ruota insieme a una ventola.

Cliccando sulle frecce sinistra e destra presenti sul palco, sarà possibile controllare la rotazione oraria e antioraria del motore e dello sprite a stella. Cliccando sulla stella, si fermerà la rotazione.

.. image:: img/13_fan.png

Cosa Imparerai
----------------------

- Principio di funzionamento del motore
- Funzione di broadcast
- Bloccare altri script all'interno dello sprite

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110` 
        - \-

Costruire il Circuito
-------------------------

.. image:: img/circuit/motor_circuit.png

Programmazione
--------------------
L'effetto che vogliamo ottenere è di utilizzare due sprite a forma di freccia per controllare rispettivamente la rotazione oraria e antioraria del motore e dello sprite a stella. Cliccando sulla stella, il motore si fermerà.

**1. Aggiungi sprite**

Elimina lo sprite predefinito, poi seleziona lo sprite **Stella** e lo sprite **Freccia1**, quindi duplica **Freccia1**.

.. image:: img/13_star.png

Nell'opzione **Costumi**, cambia la direzione dello sprite **Freccia1** per ottenere un costume con direzione diversa.

.. image:: img/13_star1.png

Regola la dimensione e la posizione dello sprite in modo appropriato.

.. image:: img/13_star2.png

**2. Sprite freccia sinistra**

Quando questo sprite viene cliccato, trasmette un messaggio - turn, poi imposta il pin digitale 9 su low e il pin 10 su high, e imposta la variabile **flag** su 1. Se clicchi sulla freccia sinistra, noterai che il motore gira in senso antiorario; se invece il tuo motore gira in senso orario, scambia le posizioni del pin 9 e del pin 10.

Ci sono due punti da notare qui.

* `[broadcast <https://en.scratch-wiki.info/wiki/Broadcast>`_]: dal pannello **Eventi**, usato per trasmettere un messaggio agli altri sprite; quando gli altri sprite ricevono questo messaggio, eseguiranno un evento specifico. Ad esempio, qui viene usato **turn**: quando lo sprite **stella** riceve questo messaggio, esegue lo script di rotazione.
* Variabile flag: la direzione di rotazione dello sprite stella è determinata dal valore della variabile flag. Quindi, quando crei la variabile **flag**, devi assicurarti che si applichi a tutti gli sprite.

.. image:: img/13_left.png

**3. Sprite freccia destra**

Quando questo sprite viene cliccato, trasmette un messaggio turn, poi imposta il pin digitale 9 su high e il pin 10 su low per far ruotare il motore in senso orario e imposta la variabile **flag** su 0.

.. image:: img/13_right.png

**4. Sprite stella**

Qui sono inclusi due eventi.

* Quando lo sprite **stella** riceve il messaggio broadcast turn, determina il valore di flag; se flag è 1, ruota di 10 gradi a sinistra, altrimenti ruota al contrario. Poiché è impostato su [PER SEMPRE], continuerà a ruotare.
* Quando questo sprite viene cliccato, imposta entrambi i pin del motore su high per fermarlo e blocca gli altri script di questo sprite.

.. image:: img/13_broadcast.png
