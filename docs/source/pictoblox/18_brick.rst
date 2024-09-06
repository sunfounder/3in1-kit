.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni festive e concorsi con premi.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _sh_breakout_clone:

2.18 GIOCO - Breakout Clone
===============================

Qui utilizziamo un potenziometro per giocare a un gioco clone di Breakout.

Dopo aver cliccato sulla bandiera verde, dovrai usare il potenziometro per controllare la paletta sul palco e catturare la pallina, così da farla rimbalzare verso l'alto e colpire i mattoni. Quando tutti i mattoni spariscono, il gioco è vinto, se non catturi la pallina, il gioco è perso.

.. image:: img/17_brick.png

Componenti Necessari
------------------------

In questo progetto, ci servono i seguenti componenti. 

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - COMPONENTI NEL KIT
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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

Costruire il Circuito
-------------------------

Il potenziometro è un elemento resistivo con 3 terminali, i due pin laterali sono collegati a 5V e GND, mentre il pin centrale è collegato ad A0. Dopo la conversione tramite il convertitore ADC della scheda Arduino, l'intervallo di valori è 0-1023.

.. image:: img/circuit/potentiometer_circuit.png

Programmazione
--------------------

Ci sono 3 sprite sul palco.

**1. Sprite Paddle**

L'effetto da ottenere con lo sprite **Paddle** è che la sua posizione iniziale si trovi al centro della parte inferiore del palco e sia controllata da un potenziometro per spostarla a sinistra o a destra.

* Elimina lo sprite predefinito, utilizza il pulsante **Scegli uno Sprite** per aggiungere lo sprite **Paddle** e imposta la sua x e y a (0, -140).

.. image:: img/17_padd1.png

* Vai alla pagina **Costumi**, rimuovi il contorno e cambia il colore in grigio scuro.

.. image:: img/17_padd3.png

* Ora scrivi lo script per lo sprite **Paddle** impostando la sua posizione iniziale a (0, -140) quando viene cliccata la bandiera verde, e leggi il valore di A0 (potenziometro) nella variabile **a0**. Poiché lo sprite **Paddle** si muove da sinistra a destra con coordinate x comprese tra -195 e 195, devi usare il blocco [mappa] per mappare l'intervallo della variabile **a0** da 0-1023 a -195-195.

.. image:: img/17_padd2.png

* Ora puoi ruotare il potenziometro per vedere se lo sprite **Paddle** si muove a sinistra e a destra sul palco.

**2. Sprite Ball**

L'effetto da ottenere con lo sprite **Ball** è che si muova intorno al palco rimbalzando quando tocca il bordo; rimbalza verso il basso se colpisce il blocco sopra il palco; rimbalza verso l'alto se tocca lo sprite Paddle durante la sua caduta; se non lo tocca, lo script si ferma e il gioco termina.

* Aggiungi lo sprite **Ball**.

.. image:: img/17_ball1.png

* Quando viene cliccata la bandiera verde, imposta l'angolo dello sprite **Ball** a 45° e imposta la posizione iniziale a (0, -120).

.. image:: img/17_ball2.png

* Ora fai muovere lo sprite **Ball** intorno al palco e fallo rimbalzare quando tocca il bordo; puoi cliccare sulla bandiera verde per vedere l'effetto.

.. image:: img/17_ball3.png

* Quando lo sprite **Ball** tocca lo sprite **Paddle**, effettua un riflesso. Il modo semplice per farlo è invertire direttamente l'angolo, ma poi noterai che il percorso della pallina è completamente fisso, il che è noioso. Pertanto, utilizziamo il centro dei due sprite per calcolare e far rimbalzare la pallina nella direzione opposta al centro della paletta.

.. image:: img/17_ball4.png

.. image:: img/17_ball6.png

* Quando lo sprite **Ball** cade al bordo del palco, lo script si interrompe e il gioco termina.

.. image:: img/17_ball5.png


**3. Sprite Block1**


L'effetto da ottenere con lo sprite **Block1** è di clonarsi 4x8 sopra il palco con un colore casuale, e cancellare un clone se viene toccato dallo sprite **Ball**.


Lo sprite **Block1** non è disponibile nella libreria **PictoBlox**, devi disegnarlo da solo o modificarne uno esistente. Qui modificheremo lo sprite **Button3**.

* Dopo aver aggiunto lo sprite **Button3**, vai alla pagina **Costumi**. Ora elimina prima **button-a**, quindi riduci sia la larghezza che l'altezza di **button-b** e rinomina lo sprite in **Block1**, come mostrato nell'immagine seguente.

.. note::

    * Per la larghezza di **Block1**, puoi simulare lo spazio sullo schermo per verificare se riesci a posizionare 8 blocchi in fila, se non ci riesci, riduci la larghezza di conseguenza.
    * Durante il processo di riduzione dello sprite **Block1**, devi mantenere il punto centrale al centro dello sprite.

.. image:: img/17_bri2.png

* Ora crea prima 2 variabili, **block** per memorizzare il numero di blocchi e **roll** per memorizzare il numero di righe.

.. image:: img/17_bri3.png

* Dobbiamo clonare lo sprite **Block1**, in modo che venga visualizzato da sinistra a destra, dall'alto verso il basso, uno per uno, 4x8 in totale, con colori casuali.

.. image:: img/17_bri4.png

* Dopo aver scritto lo script, clicca sulla bandiera verde e guarda la visualizzazione sul palco, se è troppo compatto o troppo piccolo, puoi modificare la dimensione.

.. image:: img/17_bri5.png

* Ora scrivi l'evento di attivazione. Se il clone dello sprite **Block1** tocca lo sprite **Ball**, elimina il clone e trasmetti il messaggio **crush**.

.. image:: img/17_bri6.png

* Torna allo sprite **Ball**, quando viene ricevuto il messaggio di trasmissione **crush** (lo sprite **Ball** tocca il clone dello sprite **Block1**), la pallina rimbalza nella direzione opposta.

.. image:: img/17_ball7.png
