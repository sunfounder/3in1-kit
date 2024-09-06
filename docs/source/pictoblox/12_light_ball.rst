.. note::

    Ciao, benvenuto nella Community di appassionati SunFounder per Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni festive e concorsi con premi.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _sh_light_ball:

2.12 Palla Sensibile alla Luce
=================================

In questo progetto, utilizziamo un fotoresistore per far volare la palla sul palco verso l'alto. Posiziona la mano sopra il fotoresistore per controllare l'intensità della luce che riceve. Più la mano è vicina al fotoresistore, minore sarà il suo valore e più in alto volerà la palla sul palco; altrimenti, cadrà. Quando la palla tocca la corda, emette un suono melodioso e delle scintille di luce stellare.

.. image:: img/18_ball.png

Cosa Imparerai
-----------------------

- Riempire uno sprite con colori
- Rilevare il contatto tra gli sprite

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_photoresistor` 
        - |link_photoresistor_buy|

Costruire il Circuito
-------------------------

Un fotoresistore, o cellula fotovoltaica, è un resistore variabile controllato dalla luce. La resistenza di un fotoresistore diminuisce con l'aumentare dell'intensità della luce incidente.

Costruisci il circuito secondo lo schema seguente.

Collega un'estremità del fotoresistore al pin 5V, l'altra estremità al pin A0 e collega una resistenza da 10K in serie con il pin GND a quest'ultima estremità.

Quando l'intensità della luce aumenta, la resistenza del fotoresistore diminuisce, la tensione sul resistore da 10K aumenta e il valore ottenuto da A0 aumenta.

.. image:: img/circuit/photoresistor_circuit.png

Programmazione
-------------------

L'effetto che vogliamo ottenere è che più la mano è vicina al fotoresistore, più lo sprite della palla sul palco continua a salire; altrimenti cadrà sullo sprite **Bowl**. Se tocca lo sprite **Line** mentre sale o cade, emetterà un suono musicale e genererà sprite a forma di stella in tutte le direzioni.


**1. Seleziona sprite e sfondo**

Elimina lo sprite predefinito, seleziona lo sprite **Ball**, **Bowl** e **Star**.

.. image:: img/18_ball1.png


Sposta lo sprite **Bowl** al centro inferiore del palco e ingrandisci la sua dimensione.

.. image:: img/18_ball3.png

Poiché dobbiamo farlo muovere verso l'alto, imposta la direzione dello sprite **Ball** a 0.

.. image:: img/18_ball4.png

Imposta la dimensione e la direzione dello sprite **Star** a 180 perché deve cadere, oppure puoi cambiarla a un altro angolo.

.. image:: img/18_ball12.png

Ora aggiungi lo sfondo **Stars**.

.. image:: img/18_ball2.png

**2. Disegna uno sprite Line**

Aggiungi uno sprite Line.

.. image:: img/18_ball7.png

Vai alla pagina **Costumi** dello sprite **Line**, riduci leggermente la larghezza della linea rossa sulla tela, quindi copiala 5 volte e allinea le linee.

.. image:: img/18_ball8.png

Ora riempi le linee con colori diversi. Scegli prima un colore che ti piace, poi clicca sullo strumento **Riempi** e muovi il mouse sulla linea per riempirla di colore.

.. image:: img/18_ball9.png

Segui lo stesso metodo per cambiare il colore delle altre linee.

.. image:: img/18_ball10.png


**3. Script per lo sprite Ball**

Imposta la posizione iniziale dello sprite **Ball**, poi, quando il valore della luce è inferiore a 800 (può essere qualsiasi altro valore, a seconda dell'ambiente in cui ti trovi), fai muovere la palla verso l'alto.

Puoi rendere visibile la variabile light_value sul palco per osservare il cambiamento dell'intensità della luce in ogni momento.

.. image:: img/18_ball5.png

Altrimenti, lo sprite **Ball** cadrà e il suo coordinato Y sarà limitato a un minimo di -100. Questo può essere modificato per far sembrare che stia cadendo sullo sprite **Bowl**.

.. image:: img/18_ball6.png

Quando lo sprite **Line** viene colpito, la coordinata Y corrente viene salvata nella variabile **ball_coor** e viene trasmesso un messaggio **Bling**.

.. image:: img/18_ball11.png

**4. Script per lo sprite Star**

Quando lo script inizia, nascondi lo sprite **Star**. Quando riceve il messaggio **Bling**, clona lo sprite **Star**.

.. image:: img/18_ball13.png

Quando lo sprite **Star** appare come clone, riproduci l'effetto sonoro e imposta le sue coordinate in sincronia con lo sprite **Ball**.

.. image:: img/18_ball14.png

Crea l'effetto di apparizione dello sprite **Star** e aggiustalo come necessario.

.. image:: img/18_ball15.png