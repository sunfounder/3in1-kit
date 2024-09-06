.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

Struttura di un Programma Arduino
=======================================

Diamo un'occhiata al nuovo file sketch. Anche se ha poche righe di codice, è in realtà uno sketch "vuoto". 
Caricare questo sketch sulla scheda di sviluppo non farà accadere nulla.

.. code-block:: C

    void setup() {
    // inserisci qui il tuo codice di configurazione, per eseguirlo una sola volta:

    }

    void loop() {
    // inserisci qui il tuo codice principale, per eseguirlo ripetutamente:

    }

Se rimuoviamo ``setup()`` e ``loop()`` e rendiamo lo sketch un vero ``blank`` file, scoprirai che non passa la verifica. 
Sono l'equivalente dello scheletro umano e sono indispensabili.

Durante la scrittura dello sketch, ``setup()`` viene eseguito per primo, e il codice all'interno (tra le parentesi ``{}``) viene eseguito dopo l'accensione della scheda o il reset e solo una volta. 
``loop()`` viene utilizzato per scrivere la funzione principale, e il codice al suo interno verrà eseguito in un ciclo dopo che ``setup()`` è stato eseguito.

Per comprendere meglio setup() e loop(), utilizziamo quattro sketch. Il loro scopo è far lampeggiare il LED integrato di Arduino. Esegui ciascun esperimento a turno e registra gli effetti specifici.

* Sketch 1: Far lampeggiare continuamente il LED integrato.

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

* Sketch 2: Far lampeggiare il LED integrato una sola volta. 

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // put your main code here, to run repeatedly:
    }

* Sketch 3: Far lampeggiare lentamente il LED integrato una volta e poi farlo lampeggiare rapidamente. 

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* Sketch 4: Generare un errore.

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // put your main code here, to run repeatedly:
    }    

Con l'aiuto di questi sketch, possiamo riassumere diverse caratteristiche di ``setup-loop``.

* ``loop()`` verrà eseguito ripetutamente dopo l'accensione della scheda. 
* ``setup()`` verrà eseguito una sola volta dopo l'accensione della scheda. 
* Dopo l'accensione della scheda, verrà eseguito prima ``setup()`` e poi ``loop()``. 
* Il codice deve essere scritto all'interno del campo delle parentesi ``{}`` di ``setup()`` o ``loop()``, al di fuori del framework sarà un errore.

.. note::  
    I comandi come ``digitalWrite(13,HIGH)`` vengono utilizzati per controllare il LED integrato, e parleremo del loro utilizzo in dettaglio nei capitoli successivi.

