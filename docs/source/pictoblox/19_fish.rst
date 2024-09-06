.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni festive e concorsi con premi.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _sh_fishing:

2.19 GIOCO - Pesca
===========================

Qui giochiamo a un gioco di pesca utilizzando un pulsante.

Quando lo script è in esecuzione, i pesci nuotano da sinistra a destra sul palco; devi premere il pulsante quando il pesce è vicino all'amo (si consiglia di tenerlo premuto più a lungo) per catturare il pesce, e il numero di pesci catturati verrà registrato automaticamente.

.. image:: img/18_fish.png

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Costruire il Circuito
--------------------------

Il pulsante è un dispositivo a 4 pin, poiché il pin 1 è collegato al pin 2 e il pin 3 al pin 4; quando il pulsante viene premuto, i 4 pin sono collegati, chiudendo così il circuito.

.. image:: img/5_buttonc.png

Costruisci il circuito secondo lo schema seguente.

* Collega uno dei pin sul lato sinistro del pulsante al pin 12, collegato a una resistenza pull-down e a un condensatore da 0.1uF (104) per eliminare i disturbi e ottenere un livello stabile quando il pulsante è in funzione.
* Collega l'altro capo della resistenza e del condensatore a GND, e uno dei pin sul lato destro del pulsante a 5V.

.. image:: img/circuit/button_circuit.png

Programmazione
-------------------

Dobbiamo prima selezionare uno sfondo **Sottomarino**, poi aggiungere uno sprite **Pesce** e farlo nuotare avanti e indietro sul palco. Disegniamo quindi uno sprite **Amo da pesca** e lo controlliamo tramite un pulsante per iniziare la pesca. Quando lo sprite **Pesce** tocca lo sprite **Amo da pesca** nello stato di pesca (diventa rosso), sarà catturato.

**1. Aggiungere uno sfondo**

Usa il pulsante **Scegli uno sfondo** per aggiungere uno sfondo **Sottomarino**.

.. image:: img/18_under.png

**2. Sprite Amo da pesca**

Lo sprite **Amo da pesca** di solito rimane sott'acqua nello stato giallo; quando il pulsante viene premuto, entra nello stato di pesca (rosso) e si muove sopra il palco.

Non esiste uno sprite **Amo da pesca** in Pictoblox, possiamo modificare lo sprite **Glow-J** per farlo sembrare un amo da pesca.

* Aggiungi lo sprite **Glow-J** tramite **Scegli uno Sprite**.

.. image:: img/18_hook.png

* Ora vai alla pagina **Costumi** dello sprite **Glow-J**, seleziona il riempimento di colore ciano e rimuovilo. Cambia poi il colore della J in rosso e riduci anche la sua larghezza. Il punto più importante da notare è che la parte superiore deve essere posizionata esattamente al centro.

.. image:: img/18_hook1.png

* Usa lo **Strumento Linea** per disegnare una linea il più lunga possibile dal punto centrale verso l'alto (linea fuori dal palco). Ora che lo sprite è disegnato, imposta il nome dello sprite su **Amo da pesca** e spostalo nella posizione corretta.

.. image:: img/18_hook2.png

* Quando viene cliccata la bandiera verde, imposta l'effetto colore dello sprite su 30 (giallo) e imposta la posizione iniziale.

.. image:: img/18_hook3.png

* Se il pulsante viene premuto, imposta l'effetto colore su 0 (rosso, stato di pesca), attendi 0.1 secondi e poi sposta lo sprite **Amo da pesca** in cima al palco. Rilascia il pulsante e lascia che l'**Amo da pesca** ritorni nella sua posizione iniziale.

.. image:: img/18_hook4.png

**3. Sprite Pesce**

L'effetto da ottenere con lo sprite **Pesce** è che si muova da sinistra a destra sul palco e, quando incontra lo sprite **Amo da pesca** nello stato di pesca, si riduce e si sposta in una posizione specifica per poi scomparire, e un nuovo clone dello sprite **Pesce** viene creato.

* Ora aggiungi lo sprite **Pesce** e regola la sua dimensione e posizione.

.. image:: img/18_fish1.png

* Crea una variabile **punteggio** per memorizzare il numero di pesci catturati, nascondi questo sprite e clonalo.

.. image:: img/18_fish2.png

* Mostra il clone dello sprite **Pesce**, cambia il suo costume e infine imposta la posizione iniziale.

.. image:: img/18_fish3.png

* Fai muovere il clone dello sprite **Pesce** da sinistra a destra e fallo rimbalzare quando tocca il bordo.

.. image:: img/18_fish4.png


* Il clone dello sprite **Pesce** non reagirà quando passa vicino allo sprite **Amo da pesca**; quando lo tocca nello stato di pesca (diventa rosso), sarà catturato, a quel punto il punteggio (variabile punteggio) aumenta di 1 e mostrerà un'animazione del punteggio (si riduce del 40%, si sposta rapidamente verso la posizione del tabellone dei punteggi e scompare). Allo stesso tempo, viene creato un nuovo pesce (un nuovo clone dello sprite pesce) e il gioco continua.

.. note::
    
    Devi cliccare sull'area colore nel blocco [Touch color], poi selezionare lo strumento contagocce per prendere il colore rosso dello sprite **Amo da pesca** sul palco. Se scegli un colore a caso, questo blocco [Touch color] non funzionerà.

.. image:: img/18_fish5.png
