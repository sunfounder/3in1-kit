.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni festive e concorsi con premi.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _sh_parrot:

2.17 GIOCO - Flappy Parrot
===============================

Qui utilizziamo il modulo a ultrasuoni per giocare a un gioco con il pappagallo flappy.

Dopo l'avvio dello script, il bambù verde si sposterà lentamente da destra a sinistra a un'altezza casuale. Ora posiziona la tua mano sopra il modulo a ultrasuoni, se la distanza tra la tua mano e il modulo è inferiore a 10, il pappagallo volerà verso l'alto, altrimenti cadrà verso il basso.
Devi controllare la distanza tra la tua mano e il modulo a ultrasuoni affinché il pappagallo possa evitare il bambù verde (Paddle), se lo tocca, il gioco termina.

.. image:: img/15_parrot.png

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

Costruire il Circuito
--------------------------

Un modulo sensore a ultrasuoni è uno strumento che misura la distanza da un oggetto utilizzando onde sonore a ultrasuoni. 
Ha due sonde: una invia onde ultrasoniche e l'altra le riceve, trasformando il tempo di invio e ricezione in una distanza, rilevando così la distanza tra il dispositivo e un ostacolo.

Ora costruisci il circuito secondo il diagramma seguente.

.. image:: img/circuit/ultrasonic_circuit.png

Programmazione
-------------------

L'effetto che vogliamo ottenere è utilizzare il modulo a ultrasuoni per controllare l'altezza di volo dello sprite **Parrot**, evitando lo sprite **Paddle**.


**1. Aggiungere uno sprite**

Elimina lo sprite predefinito e utilizza il pulsante **Scegli uno Sprite** per aggiungere lo sprite **Parrot**. Imposta la sua dimensione al 50% e sposta la sua posizione al centro sinistro.

.. image:: img/15_sprite.png

Ora aggiungi lo sprite **Paddle**, imposta la sua dimensione al 150%, imposta l'angolazione a 180 e sposta la sua posizione iniziale nell'angolo in alto a destra.

.. image:: img/15_sprite1.png

Vai alla pagina **Costumi** dello sprite **Paddle** e rimuovi il contorno.

.. image:: img/15_sprite2.png

**2. Script per lo sprite Parrot**

Ora scrivi lo script per lo sprite **Parrot**, che sarà in volo e la sua altitudine di volo sarà determinata dalla distanza rilevata dal modulo a ultrasuoni.

* Quando viene cliccata la bandiera verde, cambia costume ogni 0,2 secondi in modo che sembri sempre in volo.

.. image:: img/15_parr1.png

* Leggi il valore del modulo a ultrasuoni e memorizzalo nella variabile **distanza** dopo averlo arrotondato con il blocco [round].

.. image:: img/15_parr2.png

* Se la distanza rilevata è inferiore a 10 cm, fai aumentare la coordinata y di 50, lo sprite **Parrot** volerà verso l'alto. Altrimenti, la coordinata y diminuirà di 40 e **Parrot** cadrà.

.. image:: img/15_parr3.png

* Se lo sprite **Parrot** tocca lo sprite **Paddle**, il gioco termina e lo script si interrompe.

.. image:: img/15_parr4.png


**3. Script per lo sprite Paddle**

Ora scrivi lo script per lo sprite **Paddle**, che deve apparire casualmente sul palco.

* Nascondi lo sprite **Paddle** quando viene cliccata la bandiera verde e clona se stesso contemporaneamente. Il blocco [`create clone of <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_] è un blocco di controllo e uno stack block. Crea un clone dello sprite nell'argomento. Può anche clonare lo sprite in cui si sta eseguendo, creando cloni di cloni, ricorsivamente.

.. image:: img/15_padd.png

* Quando **Paddle** appare come clone, la sua posizione è 220 (massima a destra) per la coordinata x e la sua coordinata y è casuale tra -125 e 125 (altezza casuale).

.. image:: img/15_padd1.png

* Utilizza il blocco [repeat] per far diminuire lentamente la coordinata x, così vedrai il clone dello sprite **Paddle** muoversi lentamente da destra a sinistra fino a scomparire.

.. image:: img/15_padd2.png

* Riclona un nuovo sprite **Paddle** ed elimina il clone precedente.

.. image:: img/15_padd3.png