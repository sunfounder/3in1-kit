.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni festive e concorsi con premi.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _sh_eat_apple:

2.16 GIOCO - Mangia la Mela
================================

In questo progetto, giochiamo a un gioco che utilizza un pulsante per controllare lo Scarabeo nel mangiare una mela.

Quando viene cliccata la bandiera verde, premi il pulsante e lo Scarabeo inizierà a ruotare; premi nuovamente il pulsante e lo Scarabeo smetterà di girare e si muoverà in avanti con l'angolazione stabilita. Devi controllare l'angolazione dello Scarabeo in modo che avanzi senza toccare la linea nera sulla mappa fino a mangiare la mela. Se tocca la linea nera, il gioco finisce.

.. image:: img/14_apple.png

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Costruire il Circuito
-----------------------

Il pulsante è un dispositivo a 4 pin, poiché il pin 1 è collegato al pin 2 e il pin 3 al pin 4; quando il pulsante viene premuto, i 4 pin sono connessi, chiudendo così il circuito.

.. image:: img/5_buttonc.png

Costruisci il circuito seguendo lo schema riportato di seguito.

* Collega uno dei pin sul lato sinistro del pulsante al pin 12, che è connesso a una resistenza pull-down e a un condensatore da 0.1uF (104) (per eliminare il jitter e fornire un livello stabile quando il pulsante funziona).
* Collega l'altra estremità della resistenza e del condensatore a GND e uno dei pin sul lato destro del pulsante a 5V.

.. image:: img/circuit/button_circuit.png

Programmazione
------------------
L'effetto che vogliamo ottenere è usare il pulsante per controllare la direzione dello sprite **Scarabeo** in modo che avanzi e mangi la mela senza toccare la linea nera dello sfondo **Labirinto**, cambiando sfondo una volta mangiata la mela.

Ora aggiungi gli sfondi e gli sprite rilevanti.

**1. Aggiungere sfondi e sprite**

Aggiungi uno sfondo **Labirinto** tramite il pulsante **Scegli uno sfondo**.

.. image:: img/14_backdrop.png

Elimina lo sprite predefinito e seleziona lo sprite **Scarabeo**.

.. image:: img/14_sprite.png

Posiziona lo sprite **Scarabeo** all'entrata dello sfondo **Labirinto**, ricordando i valori delle coordinate x,y in questo punto, e ridimensiona lo sprite al 40%.

.. image:: img/14_sprite1.png

**2. Disegnare uno sfondo**

Ora è il momento di disegnare semplicemente uno sfondo con la scritta WIN! che appare sopra.

Per prima cosa, fai clic sulla miniatura dello sfondo per andare alla pagina **Sfondi** e fai clic sullo sfondo vuoto backdrop1.

.. image:: img/14_paint_back.png
    :width: 800

Ora inizia a disegnare, puoi fare riferimento all'immagine sotto o disegnare uno sfondo a tuo piacimento, purché esprima la vittoria.

* Utilizzando lo strumento **Cerchio**, disegna un'ellisse con il colore impostato su rosso e senza contorno.
* Poi usa lo strumento **Testo** per scrivere il testo \"WIN!\", imposta il colore del carattere su nero e regola la dimensione e la posizione del testo.
* Assegna il nome **Win** allo sfondo.

.. image:: img/14_win.png

**3. Script per lo sfondo**

Lo sfondo deve essere impostato su **Labirinto** ogni volta che il gioco inizia.

.. image:: img/14_switchback.png

**4. Scrivere script per lo sprite Scarabeo**

Ora scrivi uno script per lo sprite **Scarabeo** in modo che possa muoversi in avanti e cambiare direzione sotto il controllo di un pulsante. Il flusso di lavoro è il seguente.

* Quando viene cliccata la bandiera verde, imposta l'angolazione dello **Scarabeo** a 90 e la posizione a (-134, -134), o sostituisci questi valori con le tue coordinate. Crea la variabile **flag** e imposta il valore iniziale a -1.

.. image:: img/14_bee1.png

Successivamente, nel blocco [forever], utilizza quattro blocchi [if] per determinare vari scenari possibili.

* Se il valore del pulsante è 1 (premuto), utilizza il blocco [`mod <https://en.scratch-wiki.info/wiki/Boolean_Block>`_] per alternare il valore della variabile **flag** tra 0 e 1 (alternando tra 0 per questo click e 1 per il click successivo).

.. image:: img/14_bee2.png

* Se flag=0 (questo click), fai ruotare lo sprite **Scarabeo** in senso orario. Poi, se flag è uguale a 1 (premuto nuovamente), lo sprite **Scarabeo** si muove in avanti. Altrimenti, continua a ruotare in senso orario.

.. image:: img/14_bee3.png

* Se lo sprite Scarabeo tocca il nero (la linea nera dello sfondo **Labirinto**), il gioco finisce e lo script si interrompe.

.. note::
    
    Devi fare clic sull'area del colore nel blocco [Tocca colore] e poi selezionare lo strumento contagocce per prelevare il colore della linea nera sul palco. Se scegli un nero a caso, questo blocco [Tocca colore] non funzionerà.

.. image:: img/14_bee5.png

* Se lo Scarabeo tocca il rosso (utilizzando nuovamente lo strumento contagocce per prelevare il colore rosso della mela), lo sfondo verrà cambiato su **Win**, il che significa che il gioco è vinto e lo script si interrompe.

.. image:: img/14_bee4.png
