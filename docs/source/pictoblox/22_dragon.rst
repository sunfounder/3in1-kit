.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a promozioni festive e concorsi con premi.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _sh_dragon:

2.22 GIOCO - Uccidi il Drago
================================

Qui utilizziamo il joystick per giocare a un gioco di uccisione del drago.

Quando si clicca sul verde, il drago fluttuerà su e giù sulla destra e soffierà fuoco a intermittenza. Devi usare il joystick per controllare il movimento della bacchetta magica e lanciare attacchi di stelle contro il drago, evitando al contempo le fiamme che sputa, e infine sconfiggerlo.

.. image:: img/19_dragon.png

Componenti Necessari
------------------------

In questo progetto, abbiamo bisogno dei seguenti componenti. 

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - \-

Costruire il Circuito
-------------------------

Un joystick è un dispositivo di input costituito da una leva che ruota su una base e segnala il suo angolo o direzione al dispositivo che controlla. I joystick sono spesso utilizzati per controllare videogiochi e robot.

Per comunicare un'intera gamma di movimenti al computer, un joystick deve misurare la posizione della leva su due assi: l'asse X (da sinistra a destra) e l'asse Y (dall'alto verso il basso).

Le coordinate del movimento del joystick sono mostrate nella figura seguente.

.. note::

    * La coordinata x va da sinistra a destra, con un intervallo di 0-1023.
    * La coordinata y va dall'alto verso il basso, con un intervallo di 0-1023.

.. image:: img/16_joystick.png


Ora costruisci il circuito secondo lo schema seguente.

.. image:: img/circuit/joystick_circuit.png

Programmazione
-------------------

**1. Drago**

Aggiungi lo sfondo **Bosco** tramite il pulsante **Scegli uno Sfondo**.

.. image:: img/19_dragon01.png

* Elimina lo sprite predefinito e aggiungi lo sprite **Drago**.

.. image:: img/19_dragon0.png

* Vai alla pagina **Costumi** e capovolgi orizzontalmente i costumi dragon-b e dragon-c.

.. image:: img/19_dragon1.png

* Imposta la dimensione al 50%.

.. image:: img/19_dragon3.png

* Ora crea una variabile - **drago** per registrare i punti vita del drago e imposta il valore iniziale a 50.

.. image:: img/19_dragon2.png

* Successivamente, cambia il costume dello sprite in **dragon-b** e fai in modo che lo sprite **Drago** si muova su e giù entro un intervallo.

.. image:: img/19_dragon4.png

* Aggiungi uno sprite **Fulmine** come il fuoco soffocato dal drago. È necessario ruotarlo di 90° in senso orario nella pagina dei Costumi, in modo che lo sprite **Fulmine** si muova nella giusta direzione.

.. note::
    Quando regoli il costume del fulmine, potresti spostarlo dal centro, il che deve essere evitato! Il punto centrale deve essere esattamente al centro dello sprite!

.. image:: img/19_lightning1.png

* Poi regola il costume **dragon-c** dello sprite **Drago** in modo che il suo punto centrale sia alla coda del fuoco. Questo farà sì che le posizioni dello sprite **Drago** e dello sprite **Fulmine** siano corrette e impedirà al **Fulmine** di essere lanciato dai piedi del drago.

.. image:: img/19_dragon5.png

* Di conseguenza, **dragon-b** deve far coincidere la testa del drago con il punto centrale.

.. image:: img/19_dragon5.png

* Regola la dimensione e l'orientamento dello sprite **Fulmine** per rendere l'immagine più armoniosa.

.. image:: img/19_lightning3.png

* Ora scrivi lo script per lo sprite **Fulmine**. Questo è semplice: fagli seguire sempre lo sprite **Drago**. A questo punto, clicca sulla bandiera verde e vedrai il **Drago** che si muove con il fulmine in bocca.

.. image:: img/19_lightning4.png

* Torna allo sprite **Drago** e fagli soffiare fuoco, facendo attenzione a non lasciare che il fuoco spari direttamente dalla bocca, ma a creare un clone per lo sprite **Fulmine**.

.. image:: img/19_dragon6.png

* Clicca sullo sprite **Fulmine** e fai in modo che il clone del fulmine spari in un angolo casuale, rimbalzi contro il muro e scompaia dopo un certo periodo di tempo.

.. image:: img/19_lightning5.png

* Nello sprite **Fulmine**, nascondi il corpo e mostra il clone.

.. image:: img/19_lightning6.png

Ora il drago può muoversi su e giù e soffiare fuoco.


**2. Bacchetta**

* Crea uno sprite **Bacchetta** e ruota la sua direzione a 180 per puntare a destra.

.. image:: img/19_wand1.png

* Ora crea una variabile **hp** per registrare i suoi punti vita, inizialmente impostata a 3. Poi leggi il valore del joystick, che verrà utilizzato per controllare il movimento della bacchetta.

.. image:: img/19_wand2.png

* Il drago ha il fulmine, e la bacchetta che lo distrugge ha il suo "proiettile magico"! Crea uno sprite **Stella**, ridimensiona e scrivilo in modo che segua sempre lo sprite **Bacchetta**, limitando il numero di stelle a tre.

.. image:: img/19_star2.png

* Fai in modo che lo sprite **Bacchetta** spari stelle automaticamente. Lo sprite **Bacchetta** spara stelle nello stesso modo in cui il drago soffia fuoco, creando cloni.

.. image:: img/19_wand3.png

* Torna allo sprite **Stella** e scrivi lo script per il suo clone affinché ruoti e spari verso destra, scompaia dopo aver superato lo stage e ripristini il numero di stelle. Come per lo sprite **Fulmine**, nascondi il corpo e mostra il clone.

.. image:: img/19_star3.png

Ora abbiamo una bacchetta che spara proiettili a forma di stella.

**3. Battaglia!**

La bacchetta e il drago sono attualmente nemici in lotta e faremo in modo che combattano. Il drago è forte, e la bacchetta è il coraggioso che lo sfida. L'interazione tra di loro consiste nelle seguenti parti.


1. Se la bacchetta tocca il drago, verrà respinta e perderà punti vita.
2. Se il fulmine colpisce la bacchetta, questa perderà punti vita.
3. Se il proiettile a forma di stella colpisce il drago, quest'ultimo perderà punti vita.

Una volta che questo è sistemato, passiamo a modificare gli script per ciascuno sprite.

* Se la **Bacchetta** colpisce il **Drago**, verrà respinta e perderà punti vita.

.. image:: img/19_wand4.png

* Se un clone di **Fulmine** colpisce lo sprite **Bacchetta**, emetterà un suono di scoppio e scomparirà, e la **Bacchetta** perderà punti vita.

.. image:: img/19_lightning7.png

* Se un clone della **Stella** colpisce il **Drago**, emetterà un suono di raccolta e scomparirà, mentre il conteggio delle **Stelle** verrà ripristinato e il **Drago** perderà punti vita.

.. image:: img/19_star4.png


**4. Stage**

La battaglia tra la **Bacchetta** e il **Drago** avrà infine un vincitore e un perdente, che rappresenteremo con lo stage.

* Aggiungi lo sfondo **Cielo Blu** e scrivi la parola "WIN!" per rappresentare che il drago è stato sconfitto e che l'alba è arrivata.

.. image:: img/19_sky0.png

* E modifica lo sfondo vuoto come segue, per rappresentare che il gioco è fallito e tutto sarà nell'oscurità.

.. image:: img/19_night.png

* Ora scrivi uno script per cambiare questi sfondi: quando si clicca sulla bandiera verde, passa allo sfondo **Bosco**; se i punti vita del drago scendono sotto 1, allora il gioco avrà successo e lo sfondo cambierà in **Cielo Blu**; se i punti vita della **Bacchetta** scendono sotto 1, allora lo sfondo cambierà in **Notte** e il gioco fallirà.

.. image:: img/19_sky1.png
