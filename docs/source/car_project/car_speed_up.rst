
.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e concorsi**: Partecipa a concorsi e promozioni speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _car_speed:

3. Aumentare la velocità
============================

Oltre al segnale digitale (HIGH/LOW), l'ingresso del modulo L9110 può anche ricevere segnali PWM per controllare la velocità di uscita.

In altre parole, possiamo usare ``AnalogWrite()`` per controllare la velocità di movimento dell'auto.

In questo progetto, facciamo accelerare gradualmente l'auto e poi decelerare.


**Collegamenti**

I collegamenti di questo progetto sono gli stessi descritti in :ref:`car_move_code`.

**Codice**

.. note::

    * Apri il file ``3.speed_up.ino`` nel percorso ``3in1-kit\car_project\3.speed_up``.
    * Oppure copia questo codice nell'**IDE di Arduino**.
    
    * Oppure carica il codice tramite `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c15276c1-2359-4de6-ac82-a14a72e041c6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Dopo che il programma sarà eseguito, l'auto accelererà gradualmente per poi rallentare altrettanto gradualmente.

**Come funziona?**

Lo scopo di questo progetto è scrivere diversi valori PWM sui pin di ingresso del modulo L9110 per controllare la velocità di avanzamento dell'auto.

#. Usa l'istruzione ``for()`` per incrementare ``speed`` di 5 alla volta, scrivendo valori da 0 a 255 in modo da vedere il cambiamento della velocità dell'auto.

    .. code-block:: arduino

        void loop() {
            for(int i=0;i<=255;i+=5){
                moveForward(i);
                delay(500);
            }
            for(int i=255;i>=0;i-=5){
                moveForward(i);
                delay(500);
            }
        }

#. A proposito della funzione ``moveForward()``.

    A differenza di :ref:`car_move_code` dove i livelli alto/basso vengono dati direttamente ai pin di ingresso del modulo L9110, qui passiamo un parametro ``speed`` dove dobbiamo dare i livelli alti.

    .. code-block:: arduino

        void moveForward(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, speed);
            analogWrite(B_1B, speed);
            analogWrite(B_1A, 0);
        }


* `for <https://www.arduino.cc/reference/en/language/structure/control-structure/for/>`_

L'istruzione ``for`` viene utilizzata per ripetere un blocco di istruzioni racchiuse tra parentesi graffe. Un contatore di incremento viene solitamente utilizzato per incrementare e terminare il ciclo.

    .. code-block:: arduino

        for (initialization; condition; increment) {
        // istruzione(i);
        }

    * ``initialization``: avviene per primo e solo una volta.
    * ``condition``: ad ogni passaggio del ciclo, la condizione viene verificata; se è vera, viene eseguito il blocco di istruzioni e l'incremento, poi la condizione viene verificata nuovamente. Quando la condizione diventa falsa, il ciclo termina.
    * ``increment``: eseguito ad ogni passaggio del ciclo quando la condizione è vera.
