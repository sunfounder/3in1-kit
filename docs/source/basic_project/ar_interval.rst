.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e affronta sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_interval:

5.4 Intervallo
================

A volte è necessario fare due cose contemporaneamente. Ad esempio, potresti 
voler far lampeggiare un LED mentre leggi la pressione di un pulsante. In 
questo caso, non puoi usare ``delay()``, perché Arduino mette in pausa il 
tuo programma durante ``delay()``. Se il pulsante viene premuto mentre Arduino 
è in pausa, il programma perderà la pressione del pulsante.

Un'analogia sarebbe riscaldare una pizza nel forno a microonde e attendere 
anche una e-mail importante. Metti la pizza nel microonde e imposti il timer 
per 10 minuti. L'analogia con l'uso di ``delay()`` sarebbe quella di sedersi 
di fronte al microonde a guardare il timer che conta alla rovescia da 10 minuti 
fino a quando non raggiunge lo zero. Se l'e-mail importante arriva durante questo 
tempo, la perderai.

Quello che faresti nella vita reale sarebbe accendere il microonde, poi controllare 
la tua e-mail e magari fare qualcos'altro (che non richieda troppo tempo!) e 
di tanto in tanto tornare al microonde per vedere se il timer ha raggiunto lo 
zero, indicando che la tua pizza è pronta.

Questo sketch dimostra come far suonare un buzzer senza usare ``delay()``. 
Accende il buzzer e segna l'orario. Poi, ad ogni passaggio nel ``loop()``, 
controlla se è trascorso il tempo desiderato. Se lo è, suona il buzzer e 
aggiorna l'orario. In questo modo, il buzzer suona continuamente mentre 
l'esecuzione dello sketch non si blocca mai su una singola istruzione.

In base a questa condizione, possiamo aggiungere il codice del pulsante per 
controllare il LED, che non sarà disturbato dalla riproduzione della musica del buzzer.

**Componenti Necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un intero kit, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - 3 in 1 Starter Kit
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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|


**Schema Elettrico**

.. image:: img/circuit_8.5_interval.png


**Collegamenti**

.. image:: img/interval_bb.jpg
    :width: 600
    :align: center

**Codice**

.. note::

    * Apri il file ``5.4.interval.ino`` nel percorso ``3in1-kit\basic_project\5.4.interval``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    
    * Oppure carica il codice tramite l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0d430b04-ef2d-4e32-8d76-671a3a917cb1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Dopo aver caricato correttamente il codice, il buzzer suonerà; ogni volta che premi il pulsante, il LED si accenderà. Il funzionamento del LED e del buzzer non interferiscono tra loro.

**Come funziona?**

Inizializza una variabile chiamata ``previousMillis`` per memorizzare l'ora precedente del microcontrollore.

.. code-block:: arduino

    unsigned long previousMillis = 0;     

Segna quale nota viene suonata.

.. code-block:: arduino

    int thisNote=0; 

L'intervallo di tempo di ciascuna nota.

.. code-block:: arduino

    long interval = 1000; 

Nel ``loop()``, dichiara ``currentMillis`` per memorizzare l'ora attuale.

.. code-block:: arduino

    unsigned long currentMillis = millis();

Quando l'intervallo tra l'ora attuale e l'ultima ora aggiornata è maggiore di 1000ms, vengono attivate determinate funzioni. Nel frattempo, aggiorna ``previousMillis`` all'ora attuale per il prossimo attivarsi, che avverrà 1 secondo dopo.  

.. code-block:: arduino

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;// save the last time of the last tone
        //...
    }

Suona le note nella melodia una per una.

.. code-block:: arduino

    tone(buzzerPin,melody[thisNote],100);
    interval=1000/noteDurations[thisNote]; // interval at which to tone
    thisNote=(thisNote+1)%(sizeof(melody)/2); //iterate over the notes of the melody

Il pulsante controlla il LED.

.. code-block:: arduino

  // play button & led 
  digitalWrite(ledPin,digitalRead(buttonPin));