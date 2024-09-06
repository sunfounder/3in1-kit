.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Unisciti agli altri appassionati per approfondire insieme Raspberry Pi, Arduino ed ESP32.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e affronta le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_interrupt:

5.13 Interrupt
=======================

Se utilizzi alcune funzioni ``delay()`` in un progetto che impiega sensori, potresti 
notare che quando attivi questi sensori, il programma potrebbe non rispondere. Questo 
perché l'istruzione delay provoca una sospensione del programma, impedendogli di 
ricevere i segnali inviati dal sensore alla scheda di controllo.

In questi casi, è possibile utilizzare gli interrupt. Gli interrupt consentono al 
programma di non perdere nessun impulso.

In questo capitolo, utilizziamo un buzzer attivo e dei pulsanti per sperimentare il 
processo di utilizzo degli interrupt.

Nella funzione ``loop()``, utilizziamo ``delay(1000)`` per contare i secondi. 
Inserisci il pulsante per controllare il buzzer all'interno dell'ISR, in modo che non venga disturbato dal delay e completi il compito senza problemi.

.. note::
    Le ISR sono un tipo particolare di funzioni che hanno alcune limitazioni uniche che la maggior parte delle altre funzioni non ha. Un'ISR non può avere parametri e non deve restituire nulla.
    Generalmente, un'ISR dovrebbe essere il più breve e veloce possibile. Se il tuo sketch utilizza più ISR, solo una può essere eseguita alla volta; gli altri interrupt verranno eseguiti dopo che quello attuale è terminato, seguendo un ordine che dipende dalla priorità di ciascuno.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_buzzer`
        - \-

**Schema Elettrico**

.. image:: img/circuit_8.6_interval.png

**Collegamenti**

.. image:: img/interrupt_bb.jpg
    :width: 600
    :align: center

**Codice**

.. note::

    * Apri il file ``5.13.interrupt.ino`` nel percorso ``3in1-kit\basic_project\5.13.interrupt``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    
    * Oppure carica il codice tramite l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/6111757d-dd63-4c4c-95b5-9d96fb0843f0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo aver caricato correttamente il codice, accendi il Serial Monitor e vedrai stampato un numero incrementale automaticamente ogni secondo. Se premi il pulsante, il buzzer emetterà un suono.
La funzione del buzzer controllata dal pulsante e la funzione di conteggio temporale non entreranno in conflitto tra loro.

**Come funziona?**

* ``attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)``: Aggiungi un interrupt.

    **Sintassi**
        attachInterrupt(digitalPinToInterrupt(pin), ISR, mode) 

    **Parametri**
        * ``pin``: il numero di pin di Arduino. Dovresti usare ``digitalPinToInterrupt(pin)`` per convertire il pin digitale effettivo in un numero di interrupt specifico. Ad esempio, se connetti al pin 3, usa il suo ``digitalPinToInterrupt(3)`` come primo parametro.
        * ``ISR``: l'ISR da chiamare quando si verifica l'interrupt; questa funzione non deve prendere parametri e non deve restituire nulla. Questa funzione è talvolta chiamata routine di servizio di interrupt.
        * ``mode``: definisce quando l'interrupt dovrebbe essere attivato. Quattro costanti sono predefinite come valori validi:

          * ``LOW`` per attivare l'interrupt ogni volta che il pin è basso,
          * ``CHANGE`` per attivare l'interrupt ogni volta che il pin cambia valore.
          * ``RISING`` per attivare quando il pin passa da basso ad alto.
          * ``FALLING`` per quando il pin passa da alto a basso.

.. note:: 
    Diversi modelli di schede possono utilizzare i pin di interrupt in modo diverso. Sulla scheda R3, solo il pin 2 e il pin 3 possono utilizzare gli interrupt.
