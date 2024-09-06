.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e concorsi**: Partecipa a concorsi e promozioni speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _car_move_code:

2. Movimento tramite codice
==============================

Nel progetto precedente, abbiamo controllato il funzionamento del motore utilizzando diversi segnali di livello per l'input del modulo L9110.

Se modifichiamo i segnali di livello attraverso il programma, possiamo controllare il movimento dell'auto in modo più flessibile.

**Componenti necessari**

Per questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un intero kit, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
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
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-

**Collegamenti**

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/Dpxpb4wSq5k?si=ep6p_jzhm-DPU9w4" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Collega i fili tra il modulo L9110 e la scheda R3 seguendo lo schema qui sotto.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - Modulo L9110
      - Scheda R3
      - Motore
    * - A-1B
      - 5
      - 
    * - A-1A
      - 6
      - 
    * - B-1B(B-2A)
      - 9
      - 
    * - B-1A
      - 10
      - 
    * - OB(B)
      - 
      - Filo nero del motore destro
    * - OA(B)
      - 
      - Filo rosso del motore destro
    * - OB(A)
      - 
      - Filo nero del motore sinistro
    * - OA(A)
      - 
      - Filo rosso del motore sinistro

.. image:: img/car_2.png
    :width: 800


**Codice**

.. note::

    * Apri il file ``2.move.ino`` nel percorso ``3in1-kit\car_project\2.move``.
    * Oppure copia questo codice nell'**IDE di Arduino**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6ff67dfb-a1c1-474b-a106-6acbb3a39e6f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Dopo il caricamento del codice, l'auto si muoverà avanti, indietro, a sinistra e a destra per due secondi rispettivamente.


**Come funziona?**

Questo progetto è essenzialmente lo stesso del precedente, e consiste nel far muovere l'auto in avanti, indietro, a sinistra e a destra, nonché fermarsi, fornendo diversi segnali di livello ai pin di input del modulo L9110.

#. Inizializza i pin del modulo L9110.

    .. code-block:: arduino

        const int A_1B = 5;
        const int A_1A = 6;
        const int B_1B = 9;
        const int B_1A = 10;

        void setup() {
            pinMode(A_1B, OUTPUT);
            pinMode(A_1A, OUTPUT);
            pinMode(B_1B, OUTPUT);
            pinMode(B_1A, OUTPUT);
        }

#. Imposta i pin di input su diversi livelli alti o bassi per controllare la rotazione dei motori sinistro e destro, quindi incapsulali in singole funzioni.

    .. code-block:: arduino

        void moveForward() {
            digitalWrite(A_1B, LOW);
            digitalWrite(A_1A, HIGH);
            digitalWrite(B_1B, HIGH);
            digitalWrite(B_1A, LOW);
        }

        void moveBackward() {
            digitalWrite(A_1B, HIGH);
            digitalWrite(A_1A, LOW);
            digitalWrite(B_1B, LOW);
            digitalWrite(B_1A, HIGH);
        }
        ...
#. Chiama queste funzioni in ``loop()``.

    .. code-block:: arduino

        void loop() {
            moveForward();
            delay(2000);
            stopMove();
            delay(500);

            moveBackward();
            delay(2000);
            stopMove();
            delay(500);
        ...

* `digitalWrite(pin, value) <https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/>`_

    * ``pin``: il numero del pin di Arduino.
    * ``value``: HIGH o LOW.
    
    Scrive un valore HIGH o LOW su un pin digitale. Se il pin è stato configurato come ``OUTPUT`` con ``pinMode()``, la sua tensione verrà impostata sul valore corrispondente: 5V (o 3.3V su schede a 3.3V) per HIGH, 0V (massa) per LOW.

* `pinMode(pin, mode) <https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/>`_

    * ``pin``: il numero del pin di Arduino da impostare.
    * ``mode``: INPUT, OUTPUT o INPUT_PULLUP.
    
    Configura il pin specificato per comportarsi come input o output.

* `delay(ms) <https://www.arduino.cc/reference/en/language/functions/time/delay/>`_

    * ``ms``: il numero di millisecondi di pausa. Tipi di dati consentiti: unsigned long.

    Mette in pausa il programma per il tempo specificato (in millisecondi) come parametro. (Ci sono 1000 millisecondi in un secondo.)

