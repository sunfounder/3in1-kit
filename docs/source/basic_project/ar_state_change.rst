.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi tecnici e post-vendita con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_state_change:

5.3 Rilevamento del Cambio di Stato
=========================================

Quando il pulsante controlla altri dispositivi, non solo può attivarli quando viene premuto, ma anche fermarli quando viene rilasciato.
È inoltre possibile commutare lo stato operativo ogni volta che il pulsante viene premuto.

Per ottenere questo effetto, è necessario sapere come alternare lo stato di funzionamento tra acceso e spento quando il pulsante viene premuto, 
ovvero il "rilevamento del cambio di stato".

In questo progetto, utilizzeremo il pulsante per controllare il motore.

**Componenti necessari**

In questo progetto, ci servono i seguenti componenti. 

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

**Schema**

.. image:: img/circuit_8.3_statechange.png

**Collegamenti**

.. image:: img/5.3_state_change_l9110_bb.png
    :width: 800
    :align: center

**Codice**

.. note::

    * Apri il file ``5.3.state_change_detection.ino`` nel percorso ``3in1-kit\basic_project\5.3.state_change_detection``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    
    * Oppure carica il codice tramite l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/67a62a3d-46d3-4f5f-889c-364cbdf9b66f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Dopo aver caricato correttamente il codice, premi il pulsante e il motore si avvierà; fino a quando non premi nuovamente il pulsante, il motore si fermerà.


**Come funziona?**

#. Crea variabili e definisci i pin per il motore e il pulsante.

    .. code-block:: arduino

        ...
        int detectionState = 0;   
        int buttonState = 0;         
        int lastButtonState = 0;    

    * ``detectionState`` è una variabile che cambia il suo valore ogni volta che viene premuto il pulsante, ad esempio, 0 questa volta, 1 la prossima e così via alternativamente.
    * ``buttonState`` e ``lastButtonState`` vengono utilizzati per registrare lo stato del pulsante questa volta e l'ultima volta, per confrontare se il pulsante è stato premuto o rilasciato.

#. Inizializza ogni pin e imposta la velocità di trasmissione del monitor seriale.

    .. code-block:: arduino

        void setup() {
            pinMode(buttonPin, INPUT);
            Serial.begin(9600);
            pinMode(B_1A, OUTPUT);
            pinMode(B_1B, OUTPUT);
        }


#. Leggi lo stato del pulsante e, se premuto, la variabile ``detectionState`` cambierà il suo valore da 0 a 1 o da 1 a 0. Quando ``detectionState`` è 1, il motore si avvierà. L'effetto sarà che questa volta il pulsante viene premuto, il motore gira, la prossima volta che viene premuto, il motore si fermerà, e così via alternativamente.

    .. code-block:: arduino

        void loop() {
        // Toggle the detectionState each time the button is pressed
        buttonState = digitalRead(buttonPin);
        if (buttonState != lastButtonState) {
            if (buttonState == HIGH) {
            detectionState=(detectionState+1)%2;
            Serial.print("The detection state is: ");
            Serial.println(detectionState);
            } 
            delay(50);
        }
        lastButtonState = buttonState;
        
        // According to the detectionState, start the motor
        if(detectionState==1){
            digitalWrite(B_1A,HIGH);
            digitalWrite(B_1B,LOW);
        }else{
            digitalWrite(B_1A,LOW);
            digitalWrite(B_1B,LOW);
        }
        }

    Il flusso di lavoro completo è il seguente.

    * Leggi il valore del pulsante.

    .. code-block:: arduino

        buttonState = digitalRead(buttonPin);

    * Se ``buttonState`` e ``lastButtonState`` non sono uguali, significa che lo stato del pulsante è cambiato, procedi con il successivo controllo, e memorizza lo stato del pulsante attuale nella variabile ``lastButtonState``. ``delay(50)`` viene utilizzato per eliminare il rimbalzo.

    .. code-block:: arduino

        if (buttonState != lastButtonState) {
        ...
            delay(50);
        }
        lastButtonState = buttonState;

    * Quando il pulsante è premuto, il suo valore è HIGH. Qui, quando il pulsante è premuto, il valore della variabile ``detectionState`` cambia, ad esempio, da 0 a 1 dopo un'operazione.

    .. code-block:: arduino

        if (buttonState == HIGH) {
            detectionState=(detectionState+1)%2;
            Serial.print("The detection state is: ");
            Serial.println(detectionState);
            }

    * Quando la variabile ``detectionState`` è 1, fai ruotare il motore, altrimenti fermalo.

    .. code-block:: arduino

        if(detectionState==1){
            digitalWrite(B_1A,HIGH);
            digitalWrite(B_1B,LOW);
        }else{
            digitalWrite(B_1A,LOW);
            digitalWrite(B_1B,LOW);
        }

