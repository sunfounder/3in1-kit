.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e concorsi**: Partecipa a concorsi e promozioni speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _speed_calibration:

11. Calibrazione della velocità
===================================

Quando fai muovere l'auto in avanti, potresti notare che non procede in linea retta. 
Questo accade perché i due motori potrebbero non avere la stessa velocità dalla fabbrica. 
Tuttavia, possiamo scrivere un offset per i due motori in modo che le loro velocità di rotazione si avvicinino.

In questo progetto, 
impareremo a memorizzare l'offset nella `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_, con l'obiettivo di permettere a tutti i progetti futuri di leggere direttamente il valore dell'offset dalla EEPROM, 
così l'auto potrà procedere in modo lineare senza deviazioni.

**Collegamenti**

Questo progetto utilizza gli stessi collegamenti descritti in :ref:`car_move_code`.


**Come funziona?**

1. Apri il file ``11.speed_calibration.ino`` nel percorso ``3in1-kit\car_project\11.speed_calibration``. Oppure copia questo codice nell'**IDE di Arduino**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/66dc7ee5-31a5-418e-9aa2-43e7820cf5e6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


2. Dopo aver caricato con successo il codice, collega l'auto alla batteria da 9V, mettila a terra e falla avanzare per osservare verso quale lato devia.

* Se l'auto devia verso sinistra, significa che il motore destro è troppo veloce e deve essere ridotto.

    .. code-block:: arduino

        EEPROM.write(1, 100) // 1 significa il motore destro, 100 indica la velocità al 100%, che può essere impostata a 90, 95, ecc., a seconda della situazione reale.

* Se l'auto devia verso destra, significa che il motore sinistro è troppo veloce e deve essere ridotto.

    .. code-block:: arduino

        EEPROM.write(0, 100) // 0 significa il motore sinistro, 100 indica la velocità al 100%, che può essere impostata a 90, 95, ecc., a seconda della situazione reale.

3. Dopo aver modificato il codice, caricalo di nuovo sulla scheda R3 e osserva l'effetto. Ripeti i passaggi sopra fino a quando l'auto procede quasi in linea retta.

4. Questo offset sarà registrato nella `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_, quindi potrai leggerlo direttamente quando lo utilizzi in altri progetti, come ad esempio in :ref:`car_ir_obstacle`.


.. code-block:: arduino
    :emphasize-lines: 1,3,4,27,28,50,51

    #include <EEPROM.h>

    float leftOffset = 1.0;
    float rightOffset = 1.0;

    const int A_1B = 5;
    const int A_1A = 6;
    const int B_1B = 9;
    const int B_1A = 10;

    const int rightIR = 7;
    const int leftIR = 8;

    void setup() {
        Serial.begin(9600);

        //motor
        pinMode(A_1B, OUTPUT);
        pinMode(A_1A, OUTPUT);
        pinMode(B_1B, OUTPUT);
        pinMode(B_1A, OUTPUT);

        //IR obstacle
        pinMode(leftIR, INPUT);
        pinMode(rightIR, INPUT);

        leftOffset = EEPROM.read(0) * 0.01;//read the offset of the left motor
        rightOffset = EEPROM.read(1) * 0.01;//read the offset of the right motor
    }

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

    void moveForward(int speed) {
        analogWrite(A_1B, 0);
        analogWrite(A_1A, int(speed * leftOffset));
        analogWrite(B_1B, int(speed * rightOffset));
        analogWrite(B_1A, 0);
    }

    void moveBackward(int speed) {
        analogWrite(A_1B, speed);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, speed);
    }

    void backLeft(int speed) {
        analogWrite(A_1B, speed);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, 0);
    }

    void backRight(int speed) {
        analogWrite(A_1B, 0);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, speed);
    }

