.. note::

    Ciao, benvenuto nella Community di appassionati SunFounder per Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni festive e concorsi con premi.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _sh_star_crossed:

2.15 GIOCO - Attraversare le Stelle
===========================================

Nei prossimi progetti, giocheremo a dei mini-giochi divertenti su PictoBlox.

In questo progetto, utilizziamo il modulo Joystick per giocare ad "Attraversare le Stelle".

Dopo aver avviato lo script, le stelle appariranno casualmente sullo stage e dovrai usare il Joystick per controllare l'Astronave, cercando di evitare le stelle. Se tocchi una stella, il gioco finisce.

.. image:: img/16_rocket.png

Cosa Imparerai
-----------------------

- Come funziona il modulo Joystick
- Impostare le coordinate x e y dello sprite

Componenti Necessari
------------------------

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
    *   - :ref:`cpn_joystick`
        - \-

Costruire il Circuito
-------------------------

Un joystick è un dispositivo di input costituito da una leva che ruota su una base e comunica l'angolo o la direzione al dispositivo che controlla. I joystick sono spesso usati per controllare videogiochi e robot.

Per trasmettere l'intera gamma di movimenti al computer, un joystick deve misurare la posizione della leva su due assi – l'asse X (da sinistra a destra) e l'asse Y (dal basso verso l'alto).

Le coordinate di movimento del joystick sono mostrate nella figura seguente.

.. note::

    * La coordinata x è da sinistra a destra, con un intervallo di 0-1023.
    * La coordinata y è dall'alto verso il basso, con un intervallo di 0-1023.

.. image:: img/16_joystick.png

Ora costruisci il circuito seguendo lo schema riportato di seguito.

.. image:: img/circuit/joystick_circuit.png

Programmazione
------------------
L'intero script ha lo scopo di far muovere lo sprite **Stelle** in una curva sullo stage quando viene cliccata la bandiera verde, e dovrai usare il joystick per muovere l'**Astronave**, in modo da evitare il contatto con lo sprite **Stelle**.

**1. Aggiungi gli sprite e gli sfondi**

Elimina lo sprite predefinito e utilizza il pulsante **Scegli uno Sprite** per aggiungere lo sprite **Astronave** e lo sprite **Stella**. Nota che la dimensione dello sprite **Rocket** è impostata al 50%.

.. image:: img/16_sprite.png

Ora aggiungi lo sfondo **Stars** tramite **Scegli uno Sfondo**.

.. image:: img/16_sprite1.png

**2. Script per l'Astronave**

Lo sprite **Astronave** deve apparire in una posizione casuale e poi essere controllato dal joystick per muoversi su, giù, a sinistra e a destra.

Il flusso di lavoro è il seguente.

* Quando viene cliccata la bandiera verde, fai sì che lo sprite vada in una posizione casuale e crea 2 variabili **x** e **y**, che memorizzano i valori letti da A0 (VRX del Joystick) e A1 (VRY del Joystick). Puoi eseguire lo script, muovendo il joystick su e giù, a sinistra e a destra, per vedere l'intervallo di valori per x e y.

.. image:: img/16_roc2.png

* Il valore di A0 è compreso tra 0 e 1023 (il centro è circa 512). Usa ``x-512>200`` per determinare se il Joystick è spostato a destra, e in tal caso fai in modo che la coordinata x dello sprite aumenti di 30 (per muovere lo sprite a destra).

.. image:: img/16_roc3.png

* Se il Joystick è spostato a sinistra (``x-512<-200``), la coordinata x dello sprite diminuisce di 30 (spostando lo sprite a sinistra).

.. image:: img/16_roc4.png

* Poiché la coordinata y del Joystick va da su (0) a giù (1023), e la coordinata y dello sprite va da giù a su. Quindi, per far muovere il Joystick verso l'alto e lo sprite verso l'alto, la coordinata y deve essere diminuita di 30 nello script.

.. image:: img/16_roc5.png

* Se il joystick viene spostato verso il basso, la coordinata y dello sprite aumenta di 30.

.. image:: img/16_roc6.png

**3. Script per la Stella**

L'effetto che si vuole ottenere con lo sprite **Stella** è che appaia in una posizione casuale, e se tocca l'**Astronave**, lo script si ferma e il gioco termina.

* Quando viene cliccata la bandiera verde e lo sprite va in una posizione casuale, il blocco [turn degrees] serve a far muovere lo sprite **Stella** in avanti con un po' di variazione nell'angolo, così che si possa vedere che si muove in una curva e rimbalza sui bordi dello stage.

.. image:: img/16_star1.png

* Se lo sprite tocca l'**Astronave** mentre si muove, ferma lo script.

.. image:: img/16_star2.png