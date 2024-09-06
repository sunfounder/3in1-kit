.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e concorsi**: Partecipa a concorsi e promozioni speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _car_ir_obstacle:

5. Gioca con il Modulo di Evitamento degli Ostacoli
==========================================================

Due moduli di evitamento ostacoli a infrarossi sono montati sulla parte anteriore dell'auto, che possono essere utilizzati per rilevare ostacoli ravvicinati.

In questo progetto, l'auto si muove liberamente in avanti e, quando incontra un ostacolo, lo evita e continua a muoversi in altre direzioni.

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
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

**Collegamenti**

Il modulo di evitamento ostacoli è un sensore di prossimità a infrarossi con distanza regolabile, il cui output è normalmente alto e diventa basso quando rileva un ostacolo.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/vadNtXwITFc?si=gY4Ww31zmcs8AObP" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Ora costruisci il circuito seguendo lo schema qui sotto.

.. list-table:: 
    :header-rows: 1

    * - Modulo IR Sinistro
      - Scheda R3
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - Modulo IR Destro
      - Scheda R3
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_5.png
    :width: 800


**Regolazione del Modulo**

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/calibrate_ir.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>

Prima di iniziare il progetto, devi regolare la distanza di rilevamento del modulo.

Collega i cavi come mostrato nello schema sopra, alimenta la scheda R3 (collegando direttamente il cavo USB o utilizzando il cavo della batteria da 9V), senza caricare il codice.

Posiziona un quaderno o un altro oggetto piatto a circa 5 cm di fronte al modulo di evitamento ostacoli IR.

Poi, utilizza un cacciavite per ruotare il potenziometro sul modulo fino a quando l'indicatore di segnale non si accende, così da regolare la distanza massima di rilevamento a 5 cm.

Ripeti lo stesso metodo per regolare l'altro modulo a infrarossi.

.. image:: img/ir_obs_cali.jpg



**Codice**

.. note::

    * Apri il file ``5.obstacle_avoidance_module.ino`` nel percorso ``3in1-kit\car_project\5.obstacle_avoidance_module``.
    * Oppure copia questo codice nell'**IDE di Arduino**.
    
    * O carica il codice tramite l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/289ca80d-009f-4f60-b36d-1da6c5e10233/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

L'auto si muoverà in avanti una volta che il codice sarà stato caricato correttamente. Quando il modulo a infrarossi sinistro rileva un ostacolo, l'auto andrà indietro verso sinistra; quando il modulo a infrarossi destro rileva un ostacolo, andrà indietro verso destra; se entrambi i lati rilevano un ostacolo, andrà indietro in linea retta.

**Come funziona?**

Questo progetto si basa sui valori dei moduli di evitamento ostacoli a infrarossi sinistro e destro per far compiere all'auto l'azione appropriata.

#. Aggiungi la definizione del pin per i 2 moduli di evitamento ostacoli, impostati qui come ``INPUT``.

    .. code-block:: arduino

        ...
        const int rightIR = 7;
        const int leftIR = 8;

        void setup() {
        ...

        // IR ostacoli
            pinMode(leftIR, INPUT);
            pinMode(rightIR, INPUT);
        }

#. Leggi i valori dei moduli a infrarossi sinistro e destro e fai compiere all'auto l'azione corrispondente.

    .. code-block:: arduino

        void loop() {

            int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
            int right = digitalRead(rightIR);
            int speed = 150;

            if (!left && right) {
                backLeft(speed);
            } else if (left && !right) {
                backRight(speed);
            } else if (!left && !right) {
                moveBackward(speed);
            } else {
                moveForward(speed);
            }
        }

    * Se il modulo IR sinistro è 0 (ostacolo rilevato) e quello destro è 1, l'auto andrà indietro a sinistra.
    * Se il modulo IR destro è 0 (ostacolo rilevato), l'auto andrà indietro a destra.
    * Se entrambi i moduli IR rilevano l'ostacolo contemporaneamente, l'auto andrà indietro.
    * Altrimenti, l'auto continuerà ad andare avanti.

#. Informazioni sulla funzione ``backLeft()``.

    Quando il motore destro gira in senso antiorario e il motore sinistro è fermo, l'auto andrà indietro a sinistra.

    .. code-block:: arduino

        void backLeft(int speed) {
            analogWrite(A_1B, speed);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, 0);
        }

#. Informazioni sulla funzione ``backRight()``.

    Quando il motore sinistro gira in senso orario e il motore destro è fermo, l'auto andrà indietro a destra.

    .. code-block:: arduino

        void backRight(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, speed);
        }

* `&& <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicaland/>`_: Logical AND results in true only if both operands are true.

* `! <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicalnot/>`_: Logical NOT results in a true if the operand is false and vice versa.
