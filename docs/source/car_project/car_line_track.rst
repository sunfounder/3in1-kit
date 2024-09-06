.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _follow_the_line:

4. Segui la linea
======================

L'auto è dotata di un modulo Line Track, che può essere utilizzato per far seguire all'auto la linea nera.

Quando il modulo di rilevamento della linea rileva la linea nera, il motore destro ruota mentre il motore sinistro no, facendo così avanzare l'auto di un passo verso sinistra. Man mano che l'auto si muove, il modulo della linea si sposta fuori dalla linea, quindi il motore sinistro si accende e quello destro si spegne, facendo avanzare l'auto di un passo verso destra per tornare sulla linea.
Ripetendo questi due passaggi, l'auto può seguire la linea nera.

Prima di iniziare il progetto, è necessario creare una mappa curvilinea con del nastro nero. La larghezza della linea consigliata è compresa tra 0,8 e 1,5 cm, e l'angolo della curva non deve essere inferiore a 90 gradi.

**Componenti necessari**

In questo progetto, avremo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome
        - ELEMENTI NEL KIT
        - LINK
    *   - Kit 3 in 1
        - 380+
        - |link_3IN1_kit|

Puoi anche acquistarli separatamente dai link sottostanti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK D'ACQUISTO

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_track`
        - |link_track_buy|

**Cablaggio**

Questo è un modulo di tracciamento della linea digitale, quando rileva una linea nera, emette 1; quando rileva una linea bianca, emette un valore di 0. Inoltre, è possibile regolare la distanza di rilevamento tramite il potenziometro sul modulo.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/mlCQgAq4elo?si=ZFmHeA6bVsDCPG0p" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Costruisci il circuito secondo il diagramma seguente.

.. list-table:: 
    :header-rows: 1

    * - Modulo di tracciamento della linea
      - Scheda R3
    * - S
      - 2
    * - V+
      - 5V
    * - G
      - GND

.. image:: img/car_4.png
    :width: 800

**Regolazione del modulo**

Prima di iniziare il progetto, è necessario regolare la sensibilità del modulo.

Collega i fili secondo il diagramma precedente, quindi alimenta la scheda R3 (collegandola direttamente con il cavo USB o il cavo della batteria da 9V), senza caricare il codice.

Applica un nastro adesivo nero sul tavolo e posiziona il carrello sopra di esso.

Osserva il LED del segnale sul modulo per assicurarti che si accenda sul tavolo bianco e si spenga sul nastro nero.

Se ciò non accade, dovrai regolare il potenziometro sul modulo affinché funzioni correttamente.

.. image:: img/line_track_cali.JPG

**Codice**

.. note::

    * Apri il file ``4.follow_the_line.ino`` nel percorso ``3in1-kit\car_project\4.follow_the_line``.
    * Oppure copia questo codice nell'IDE Arduino.
    
    * Oppure carica il codice tramite l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/2779e9eb-b7b0-4d47-b8c0-78fed39828c3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Dopo aver caricato il codice sulla scheda R3, allinea il modulo di tracciamento della linea sotto l'auto con la linea nera e vedrai l'auto seguire la linea.


**Come funziona?**

In questo codice, si fa ruotare i due motori a sinistra e a destra in base al valore del modulo di tracciamento della linea, in modo che l'auto possa seguire la linea nera.

#. Aggiungi la definizione del pin per il modulo di tracciamento della linea, qui è impostato su ``INPUT``. Qui viene anche inizializzato il monitor seriale e impostata la velocità di trasmissione a 9600bps.

    .. code-block:: arduino

        ...
        const int lineTrack = 2;
        Serial.begin(9600);
        void setup() {
            ...
            pinMode(lineTrack, INPUT);
        }

#. Leggi il valore del modulo di tracciamento della linea, se è 1, l'auto si sposta in avanti a sinistra; altrimenti, si sposta in avanti a destra. Puoi anche aprire il monitor seriale cliccando sull'icona della lente d'ingrandimento nell'angolo in alto a destra per vedere il cambiamento del valore del modulo di tracciamento della linea sulla linea bianca e nera prima di scollegare il cavo USB.

    .. code-block:: arduino
    
        void loop() {

            int speed = 150;

            int lineColor = digitalRead(lineTrack); // 0:white    1:black
            Serial.println(lineColor); 
            if (lineColor) {
                moveLeft(speed);
            } else {
                moveRight(speed);
            }
        }

#. Sulle funzioni ``moveLeft()`` e ``moveRight()``.

    A differenza della funzione di svolta a sinistra e a destra nel progetto :ref:`car_move_code`, qui sono necessarie solo piccole svolte a sinistra e a destra, quindi è sufficiente regolare il valore di ``A_1A`` o ``B_1B`` ogni volta. Ad esempio, se ti sposti a sinistra in avanti (``moveLeft()``), devi solo impostare la velocità su ``A_1A`` e impostare gli altri valori a 0; in questo modo, il motore destro ruoterà in senso orario e il motore sinistro non si muoverà.

    .. code-block:: arduino
    

        void moveLeft(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, speed);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, 0);
        }

        void moveRight(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, speed);
            analogWrite(B_1A, 0);
        }

* `Serial <https://www.arduino.cc/reference/en/language/functions/communication/serial/>`_

    Utilizzato per la comunicazione tra la scheda Arduino e un computer o altri dispositivi.

    * ``Serial.begin()``: Imposta la velocità di trasmissione dati in bit al secondo (baud) per la trasmissione dei dati seriali.
    * ``Serial.println()``: Stampa i dati sulla porta seriale come testo ASCII leggibile dall'uomo, seguito da un carattere di ritorno a capo (ASCII 13, o '\r') e un carattere di nuova riga (ASCII 10, o '\n').

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    ``if else`` consente un maggiore controllo sul flusso delle operazioni.
