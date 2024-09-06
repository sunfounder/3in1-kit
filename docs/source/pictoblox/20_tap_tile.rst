.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a promozioni festive e concorsi con premi.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _sh_tap_tile:

2.20 GIOCO - Non toccare la piastrella bianca
=====================================================

Sono sicuro che molti di voi hanno giocato a questo gioco sui vostri telefoni. In questo gioco si devono toccare le piastrelle nere che appaiono casualmente per aggiungere punti; la velocità diventerà sempre più veloce. Se tocchi una piastrella bianca o perdi una nera, il gioco è finito.

Ora lo replichiamo con PictoBlox.

Inserisci due moduli di evitamento ostacoli a infrarossi verticalmente sulla breadboard. Quando la tua mano si trova sopra uno dei moduli IR, un punto lampeggiante apparirà sullo stage, rappresentando un tocco.

Se il tocco è su una piastrella nera, il punteggio aumenta di 1, se tocca una piastrella bianca, il punteggio diminuisce di 1.

Devi decidere se posizionare la mano sopra il modulo IR sinistro o destro, a seconda della posizione della piastrella nera sullo stage.

.. image:: img/21_tile.png

Componenti Necessari
-------------------------

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
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

Costruire il Circuito
------------------------

Il modulo di evitamento ostacoli è un sensore di prossimità a infrarossi regolabile 
in distanza il cui output è normalmente alto e diventa basso quando viene rilevato 
un ostacolo.

Ora costruisci il circuito secondo lo schema seguente.

.. image:: img/circuit/2avoid_circuit.png

Programmazione
------------------

Qui abbiamo bisogno di tre sprite: **Piastrella**, **IR Sinistro** e **IR Destro**.

* Lo sprite **Piastrella** serve per ottenere l'effetto delle piastrelle nere e bianche che scendono alternativamente. Nel gioco per cellulare di solito ci sono 4 colonne, ma qui ne faremo solo due.
* Lo sprite **IR Sinistro** serve per ottenere l'effetto del clic. Quando il modulo IR sinistro rileva la tua mano, invierà un messaggio - **sinistra** allo sprite **IR Sinistro**, che inizierà a funzionare. Se tocca la piastrella nera, il punteggio aumenta di 1, altrimenti diminuisce di 1.
* Lo sprite **IR Destro** ha la stessa funzione dell'**IR Sinistro**, ma riceve il messaggio **destra**.

**1. Disegnare uno sprite Piastrella**.

Elimina lo sprite predefinito, posiziona il mouse sull'icona **Aggiungi uno sprite**, seleziona **Disegna** e apparirà uno sprite vuoto da nominare **Piastrella**.

.. image:: img/21_tile1.png

Vai alla pagina **Costumi** e usa lo strumento **Rettangolo** per disegnare un rettangolo.

.. image:: img/21_tile2.png

Seleziona il rettangolo e clicca su **Copia** -> **Incolla** per creare un rettangolo identico, poi allinea i due rettangoli.

.. image:: img/21_tile01.png

Seleziona uno dei rettangoli e riempilo di nero.

.. image:: img/21_tile02.png

Ora seleziona entrambi i rettangoli e spostali in modo che il loro punto centrale corrisponda al centro della tela.

.. image:: img/21_tile0.png

Duplica il costume1 alternando i colori di riempimento dei due rettangoli. Ad esempio, nel costume1 il rettangolo a sinistra è bianco e quello a destra è nero, mentre nel costume2 il colore è invertito.

.. image:: img/21_tile3.png

**2. Programmare lo sprite Piastrella**

Ora torna alla pagina **Blocchi** e imposta la posizione iniziale dello sprite **Piastrella** in modo che sia in cima allo stage.

.. image:: img/21_tile4.png

Crea una variabile **blocchi** e assegnale un valore iniziale per determinare quante volte lo sprite **Piastrella** apparirà. Usa il blocco [ripeti fino a] per fare in modo che la variabile **blocchi** diminuisca gradualmente fino a 0. Durante questo tempo, lo sprite **Piastrella** cambierà costume casualmente.

Dopo aver cliccato sulla bandiera verde, vedrai lo sprite **Piastrella** cambiare costume rapidamente sul palco.

.. image:: img/21_tile5.png

Crea cloni dello sprite **Piastrella** mentre la variabile **blocchi** diminuisce, e ferma lo script quando **blocchi** è 0. Usa due blocchi [attendi () secondi]: il primo per limitare l'intervallo tra i cloni della **Piastrella** e il secondo per fare in modo che la variabile **blocchi** scenda a 0 senza fermare immediatamente il programma, dando all'ultimo sprite piastrella abbastanza tempo per muoversi.

.. image:: img/21_tile6.png

Ora fai in modo che il clone dello sprite **Piastrella** si muova lentamente verso il basso e lo elimini quando raggiunge il fondo dello stage. La variazione della coordinata y influisce sulla velocità di discesa: maggiore è il valore, più veloce è la discesa.

.. image:: img/21_tile7.png

Nascondi il corpo e mostra il clone.

.. image:: img/21_tile8.png

**3. Leggere i valori dei 2 moduli IR**

Nel fondale, leggi i valori dei 2 moduli IR e fai compiere le azioni corrispondenti.

* Se il modulo di evitamento ostacoli IR sinistro rileva la tua mano, trasmetti un messaggio - **sinistra**.
* Se il modulo di evitamento ostacoli IR destro rileva la tua mano, trasmetti un messaggio - **destra**.

.. image:: img/21_tile9.png

**4. Sprite IR Sinistro**

Posiziona di nuovo il mouse sull'icona **Aggiungi sprite** e seleziona **Disegna** per creare un nuovo sprite chiamato **IR Sinistro**.

.. image:: img/21_tile10.png

Vai alla pagina **Costumi** dello sprite **IR Sinistro**, seleziona un colore di riempimento (qualsiasi colore tranne bianco e nero) e disegna un cerchio.

.. image:: img/21_tile11.png

Ora inizia a programmare lo sprite **IR Sinistro**. Quando il messaggio **sinistra** viene ricevuto (il modulo ricevente IR sinistro rileva un ostacolo), verifica se la piastrella nera dello sprite **Piastrella** è toccata e, se lo è, fai aggiungere 1 alla variabile **conteggio**, altrimenti sottrai 1.

.. image:: img/21_tile12.png

.. note::

    Devi fare apparire lo sprite **Piastrella** sul palco e poi assorbire il colore del blocco nero nello sprite **Piastrella**.

    .. image:: img/21_tile13.png

Ora applichiamo l'effetto sensoriale (ingrandimento e riduzione) per **IR Sinistro**.

.. image:: img/21_tile14.png

Fai nascondere lo sprite **IR Sinistro** quando viene cliccata la bandiera verde, fallo apparire quando viene ricevuto il messaggio **sinistra** e infine nascondilo di nuovo.

.. image:: img/21_tile15.png

**5. Sprite IR Destro**

Copia lo sprite **IR Sinistro** e rinominalo in **IR Destro**.

.. image:: img/21_tile16.png

Poi cambia il messaggio ricevuto in **destra**.

.. image:: img/21_tile17.png

Ora la programmazione è completata e puoi cliccare sulla bandiera verde per eseguire lo script.
