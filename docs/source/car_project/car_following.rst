.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _follow_your_hand:

7. Segui la tua mano
=========================

Pensa a quest'auto come al tuo animale domestico, quando le farai un cenno con la mano, verrà da te.

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

**Cablaggio**

Collega il modulo a ultrasuoni e i due moduli di evitamento ostacoli IR contemporaneamente.

Collega l'ultrasuono alla scheda R3 come segue.

.. list-table:: 
    :header-rows: 1

    * - Modulo a ultrasuoni
      - Scheda R3
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

Il cablaggio dei due moduli IR di evitamento ostacoli alla scheda R3 è il seguente.

.. list-table:: 
    :header-rows: 1

    * - Modulo IR sinistro
      - Scheda R3
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - Modulo IR destro
      - Scheda R3
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_7_8.png
    :width: 800

**Codice**

.. note::

    * Apri il file ``7.follow_your_hand.ino`` nel percorso ``3in1-kit\car_project\7.follow_your_hand``.
    * Oppure copia questo codice nell'IDE Arduino.
    
    * Oppure carica il codice tramite l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/584e42c8-8842-4db0-93b5-f6f949b6ffca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Posiziona l'auto a terra dopo che il codice è stato caricato correttamente. Metti la mano a 5-10 cm davanti all'auto e questa seguirà la tua mano in avanti. Se metti la mano vicino al modulo IR di evitamento ostacoli su entrambi i lati, l'auto si girerà nella direzione corrispondente.

**Come funziona?**

Questo progetto è una combinazione dei due precedenti :ref:`car_ultrasonic` e :ref:`car_ir_obstacle`, ma l'effetto implementato è diverso. Nei due progetti precedenti l'ostacolo veniva rilevato all'indietro, qui la tua mano viene rilevata per seguire la direzione in avanti o girare.
Il flusso di lavoro di questo progetto è il seguente.

* Leggi la distanza rilevata dal modulo a ultrasuoni e il valore di entrambi i moduli a infrarossi.
* Se la distanza è di 5-10 cm, fai muovere l'auto con la tua mano.
* Se il modulo IR sinistro rileva la tua mano, gira a sinistra.
* Se il modulo IR destro rileva la tua mano, gira a destra.
* Se né il modulo a infrarossi né quello a ultrasuoni rilevano la tua mano, ferma l'auto.

.. code-block:: arduino

    void loop() {

        float distance = readSensorData();

        int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
        int right = digitalRead(rightIR);
        int speed = 150;

        if (distance>5 && distance<10){
            moveForward(speed);
        }
        if(!left&&right){
            turnLeft(speed);
        }else if(left&&!right){
            turnRight(speed);
        }else{
            stopMove();
        }
    }