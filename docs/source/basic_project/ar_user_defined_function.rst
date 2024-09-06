.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_ultrasonic:

5.8 Funzione Definita dall'Utente
======================================

In C, possiamo dividere un programma grande in blocchi di base noti come funzioni. 
Una funzione contiene un insieme di istruzioni di programmazione racchiuse da {}. 
Una funzione può essere chiamata più volte per fornire riutilizzabilità e modularità al programma C. 
In altre parole, possiamo dire che l'insieme delle funzioni crea un programma. 
La funzione è nota anche come procedura o sottoprogramma in altri linguaggi di programmazione.

Ecco alcuni vantaggi delle funzioni.

* Usando le funzioni, possiamo evitare di riscrivere la stessa logica/codice ripetutamente in un programma.
* Possiamo chiamare funzioni C un numero qualsiasi di volte in un programma e da qualsiasi punto.
* Possiamo tracciare un programma C grande più facilmente quando è diviso in più funzioni.
* Il riutilizzo è il principale vantaggio delle funzioni in C.
* Tuttavia, la chiamata a una funzione è sempre un sovraccarico in un programma C.

Ci sono due tipi di funzioni nella programmazione C:

* **Funzioni di libreria**: le funzioni dichiarate nei file di intestazione C.
* **Funzioni definite dall'utente**: le funzioni create dal programmatore C, che possono essere utilizzate più volte. Questo riduce la complessità di un programma grande e ottimizza il codice.

In questo progetto, definiamo una funzione per leggere il valore del modulo ultrasonico.

**Componenti necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti. 

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Puoi anche acquistarli separatamente dai link sottostanti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Schema**

.. image:: img/circuit_6.3_ultrasonic.png

**Collegamenti**

.. image:: img/ultrasonic_bb.jpg
    :width: 600
    :align: center

**Codice**

.. note::

    * Apri il file ``5.8.user_function.ino`` nel percorso ``3in1-kit\basic_project\5.8.user_function``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    
    * Oppure carica il codice tramite il `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/11717782-3ee6-4eca-bbb9-094385d9eb4b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Dopo che il codice è stato caricato con successo, il monitor seriale stamperà la distanza tra il sensore ultrasonico e l'ostacolo davanti.

**Come funziona?**

Per l'applicazione del sensore ultrasonico, possiamo controllare direttamente la sottoprogramma.

.. code-block:: arduino

    float readSensorData(){// ...}

Il ``trigPin`` del modulo ultrasonico trasmette un segnale d'onda quadra di 10us ogni 2us.

.. code-block:: arduino

    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); 


Il ``echoPin`` riceve un segnale di livello alto se c'è un ostacolo entro il raggio e usa la funzione ``pulseIn()`` per registrare il tempo dal segnale inviato a quello ricevuto.

.. code-block:: arduino

    microsecond=pulseIn(echoPin, HIGH);

La velocità del suono è 340 m/s o 29 microsecondi per centimetro.

Questo dà la distanza percorsa dall'onda quadra, andata e ritorno, quindi
dividiamo per 2 per ottenere la distanza dell'ostacolo.

.. code-block:: arduino

    float distance = microsecond / 29.00 / 2;  


Nota che il sensore ultrasonico sospenderà il programma mentre sta funzionando, il che può causare ritardi durante la scrittura di progetti complessi.
