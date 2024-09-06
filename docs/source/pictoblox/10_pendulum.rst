.. note::

    Ciao, benvenuto nella Community di appassionati SunFounder per Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni festive e concorsi con premi.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _sh_pendulum:

2.10 Pendolo
=====================

In questo progetto, creeremo un pendolo con una freccia mentre il servo seguirà la rotazione.

.. image:: img/12_pun.png

Cosa Imparerai
----------------------

- Come funziona il servo e il range degli angoli
- Disegnare uno sprite e posizionare il punto centrale sulla coda.

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
    *   - :ref:`cpn_servo` 
        - |link_servo_buy|

Costruire il Circuito
------------------------

Un servo è un motore con ingranaggi che può ruotare solo di 180 gradi. È 
controllato inviando impulsi elettrici dalla tua scheda, che indicano al 
servo quale posizione raggiungere.

Il servo ha tre fili: il filo marrone è GND, quello rosso è VCC (collegare a 3.3V) e quello arancione è il filo di segnale. Il range di angolazione è 0-180 gradi.

Ora costruisci il circuito seguendo il diagramma qui sotto.

.. image:: img/circuit/servo_circuit.png

Programmazione
------------------

**1. Disegna uno sprite**

Elimina lo sprite predefinito, seleziona il pulsante Sprite e clicca su **Disegna**, apparirà uno sprite vuoto chiamato **Sprite1**.

.. image:: img/12_paint1.png

Nella pagina **Costumi**, utilizza lo strumento **Linea** per disegnare una freccia.

.. note::

    * Assicurati di iniziare a disegnare la freccia dal centro del canvas verso l'esterno, in modo che la freccia ruoti con il punto centrale come origine.
    * Tieni premuto Shift per mantenere l'angolo della linea dritto o a 45 gradi.

.. image:: img/12_paint2.png

Dopo aver disegnato, lo sprite **freccia** apparirà sul palco. Nominalo **freccia**. Poi clicca sul numero dopo **Direzione**, apparirà un quadrante circolare. Trascina questa freccia e verifica se lo sprite **freccia** ruota sul palco con la coda come origine.

.. image:: img/12_paint3.png

Per far oscillare lo sprite **freccia** da sinistra a destra, il range di angolazione è -90 a -180, e da 180 a 90.

.. image:: img/12_paint4.png

.. image:: img/12_paint5.png

**2. Creazione di una variabile**

Crea una variabile chiamata **servo**, che memorizza il valore dell'angolo e imposta il valore iniziale a 270.

.. image:: img/12_servo.png

**3. Oscillazione da sinistra a destra**

Ora fai oscillare lo sprite **freccia** dalla posizione di -90 gradi a sinistra fino alla posizione di 90 gradi a destra.

Con il blocco [ripeti], aggiungi -10 alla variabile ogni volta, e raggiungerai i 90 gradi in 18 passaggi. Usa poi il blocco [puntare in direzione] per far ruotare lo sprite freccia verso questi angoli.

Poiché l'angolo di rotazione dello sprite va da -180 a 180, gli angoli al di fuori di questo range vengono convertiti secondo le seguenti condizioni.

* Se l'angolo > 180, allora angolo -360.

.. image:: img/12_servo1.png

**4. Ruotare il Servo**

Quando clicchi sulla bandiera verde, vedrai la freccia ruotare rapidamente verso destra e poi tornare a sinistra. Usa quindi un blocco [aspetta secondi] per rallentare la rotazione. Usa anche il blocco [imposta servo su angolo] per fare in modo che il servo collegato alla scheda Arduino ruoti a un angolo specifico.

.. image:: img/12_servo2.png

**5. Oscillazione da destra a sinistra**

Con lo stesso metodo, fai ruotare lentamente il servo e lo sprite **freccia** da destra a sinistra.

* Se l'angolo > 180, allora angolo -360.

.. image:: img/12_servo3.png
