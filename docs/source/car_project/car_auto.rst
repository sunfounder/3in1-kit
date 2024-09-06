.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _self_driving:

Auto a guida autonoma
=========================

Questo progetto è una combinazione dei due progetti :ref:`car_ultrasonic` e :ref:`car_ir_obstacle`. 
Due moduli a infrarossi evitano ostacoli a breve distanza o ai bordi, mentre i moduli a ultrasuoni rilevano ostacoli a lunga distanza per garantire che l'auto non colpisca ostacoli durante il processo di guida autonoma.

**Componenti necessari**

In questo progetto, avremo bisogno dei seguenti componenti. 

È sicuramente conveniente acquistare un kit completo, ecco il link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - OGGETTI NEL KIT
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

    * Apri il file ``8.self_driving_car.ino`` nel percorso ``3in1-kit\car_project\8.self_driving_car``.
    * Oppure copia questo codice nell'IDE Arduino.
    
    * Oppure carica il codice tramite l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0a74a7b1-ead6-4bea-ab5a-4da71f27f82f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

L'auto guiderà liberamente una volta che il codice sarà stato caricato correttamente. Quando i moduli IR su entrambi i lati rilevano un ostacolo, l'auto si muoverà nella direzione opposta per evitare emergenze; se c'è un ostacolo entro 2~10 cm davanti all'auto, farà retromarcia a sinistra, regolerà la direzione e poi procederà in avanti.

**Come funziona?**

Il flusso di lavoro di questo progetto è il seguente.

* Leggi prioritariamente il valore dei moduli IR sinistro e destro per l'evitamento ostacoli.
* Se il modulo IR sinistro restituisce 0 (ostacolo rilevato) e il modulo IR destro restituisce 1, fai retromarcia a sinistra.
* Se il modulo IR destro restituisce 0 (ostacolo rilevato), fai retromarcia a destra.
* Se entrambi i moduli IR rilevano un ostacolo contemporaneamente, l'auto farà retromarcia.
* Altrimenti, leggi la distanza rilevata dal modulo a ultrasuoni.
* Se la distanza è maggiore di 50 cm, l'auto avanzerà.
* Se la distanza è tra 2 e 10 cm, l'auto farà retromarcia prima di girare.
* Se la distanza è tra 10 e 50 cm, l'auto avanzerà a bassa velocità.


.. code-block:: arduino

    void loop() {

        int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
        int right = digitalRead(rightIR);

        if (!left && right) {
            backLeft(150);
        } else if (left && !right) {
            backRight(150);
        } else if (!left && !right) {
            moveBackward(150);
        } else {
            float distance = readSensorData();
            Serial.println(distance);
            if (distance > 50) { // Safe
                moveForward(200);
            } else if (distance < 10 && distance > 2) { // Attention
                moveBackward(200);
                delay(1000);
                backLeft(150);
                delay(500);
            } else {
                moveForward(150);
            }
        }
    }

