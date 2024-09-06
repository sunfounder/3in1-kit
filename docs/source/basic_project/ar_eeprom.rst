.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Unisciti agli appassionati per approfondire Raspberry Pi, Arduino ed ESP32 insieme a noi.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e affronta sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti riservati sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_74hc_7seg:

5.15 EEPROM
==============

L'`EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ è una memoria che non viene cancellata quando la scheda di controllo principale viene spenta. Puoi usarla per registrare alcuni dati e leggerli la prossima volta che la accendi.

Ad esempio, puoi creare un contatore sportivo che tiene traccia di quante volte salti la corda ogni giorno.

Puoi anche scrivere dati su di essa in un programma e leggerli in un altro. Ad esempio, quando lavori su un progetto di auto, le velocità dei due motori potrebbero essere diverse. Puoi scrivere un programma di calibrazione per registrare il valore di compensazione della velocità del motore.

**Componenti necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente comodo acquistare un intero kit, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - OGGETTI IN QUESTO KIT
        - LINK
    *   - Kit Starter 3 in 1
        - 380+
        - |link_3IN1_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE COMPONENTI
        - LINK DI ACQUISTO

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**Schema**

.. image:: img/circuit_515_eeprom.png

**Collegamenti**

.. image:: img/eeprom_servo.png

**Codice**


.. note::

    * Apri il file ``5.15.eeproom.ino`` nel percorso ``3in1-kit\basic_project\5.15.eeproom``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    
    * Oppure carica il codice tramite `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7378341f-9c1a-4171-814f-c76c109e1e67/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Per utilizzare questo circuito, basta premere il pulsante per iniziare la registrazione e inserire le informazioni desiderate tramite un potenziometro. Ora, la scheda ripeterà le tue azioni all'infinito (e farà lampeggiare un LED ad ogni iterazione) fino a quando non premerai nuovamente il pulsante per registrare nuove azioni. Puoi anche variare il tempo registrato cambiando i valori di ``resolution`` e ``recordTime``.

**Come funziona?**

#. Importa la libreria ``EEPROM.h`` e inizializza la memoria EEPROM. 

    .. code-block:: arduino

        ...
        #include <EEPROM.h>//usata per memorizzare i valori registrati

        ...
        float resolution = 1000;//DEVE essere inferiore a EEPROM.length()
        float recordTime = 5; //tempo di ritardo
        bool recording = false;
        ...
    
    Nota che ``/DEVE essere inferiore a EEPROM.length()``, in ``setup()`` verrà stampata la memoria della EEPROM della tua scheda, che dovrebbe essere 1024 per la scheda SunFounder R3. Se utilizzi una scheda diversa, puoi modificare il valore della variabile ``resolution``.

#. Stampa la memoria EEPROM della tua scheda.

    .. code-block:: arduino

        void setup() {
            ...
            Serial.begin(9600);
            //Serial.println(EEPROM.length());
        }

    Per trovare la dimensione della memoria EEPROM della tua scheda, decommenta la linea ``Serial.println(EEPROM.read(i))``. Questo stamperà la dimensione della EEPROM nel monitor seriale, e potrai cambiare di conseguenza il valore della variabile ``resolution``.

#. Non appena viene rilevata una pressione del pulsante, inizia la registrazione e le informazioni richieste vengono inserite tramite un potenziometro. Ora la scheda ripeterà la tua azione all'infinito (e farà lampeggiare un LED per ogni ripetizione) fino a quando non premerai nuovamente il pulsante, registrando una nuova azione.

    .. code-block:: arduino

        void loop() {
            if (recording == true) {//record
                for (int i = 1; i <= resolution; i++) {
                    digitalWrite(ledPin, HIGH); //light status led
                    int val = map(analogRead(A0), 0, 1023, 0, 180);
                    EEPROM.write(i, val);
                    //Serial.println(EEPROM.read(i));
                    myServo.write(val);
                    delay(recordTime);
                }
                digitalWrite(ledPin, LOW); //turn off status led
                delay(1000);//give time for person
                recording = false;
            }
            else {
                for (int i = 1; i <= resolution; i++) {//playback
                    if (digitalRead(buttonPin) == 0) {//stop playback and record new values
                        recording = true;
                        break;
                    }
                    int readval = EEPROM.read(i);
                    myServo.write(readval);
                    //Serial.println(readval);
                    delay(recordTime);
                }
                digitalWrite(ledPin, HIGH); //show a new repeat
                delay(100);
                digitalWrite(ledPin, LOW);
            }
        }

    * Imposta la variabile ``recording`` su true quando viene premuto il pulsante.
    * Quando la variabile ``recording`` è true, inizia a registrare l'azione nell'intervallo di memoria.
    * Leggi il valore del potenziometro e mappalo su 0-180 per memorizzarlo nell'EEPROM e controllare la rotazione del servo.
    * Il LED si accende all'inizio della registrazione e si spegne alla fine.
    * Ripeti l'azione registrata con un rapido lampeggio del LED per ricordarti di una nuova ripetizione.

#. Informazioni sulla libreria ``EEPROM``.

    Ecco alcune delle sue funzioni.
        
    * ``write(address,value)``: Scrive un byte nella EEPROM.

        * ``address``: la posizione in cui scrivere, a partire da 0 (int)
        * ``value``: il valore da scrivere, da 0 a 255 (byte)
        * Una scrittura EEPROM richiede 3,3 ms per essere completata. La memoria EEPROM ha una durata specificata di 100.000 cicli di scrittura/cancellazione, quindi potrebbe essere necessario fare attenzione a quanto spesso la scrivi.

    * ``Read(address)``: Legge un byte dalla EEPROM. Le posizioni che non sono mai state scritte hanno il valore di 255.

    * ``update(address,value)``: Scrive un byte nella EEPROM. Il valore viene scritto solo se differisce da quello già salvato nello stesso indirizzo.

        * Una scrittura EEPROM richiede 3,3 ms per essere completata. La memoria EEPROM ha una durata specificata di 100.000 cicli di scrittura/cancellazione, quindi utilizzare questa funzione al posto di write() può risparmiare cicli se i dati scritti non cambiano spesso.

    * ``EEPROM.put(address, data)``: Scrive qualsiasi tipo di dato o oggetto nella EEPROM.

        * ``address``: la posizione da cui leggere, a partire da 0 (int).
        * ``data``: i dati da leggere, possono essere un tipo primitivo (es. float) o una struttura personalizzata.
        * Questa funzione utilizza EEPROM.update() per eseguire la scrittura, quindi non riscrive il valore se non è cambiato.

    * ``EEPROM.get(address, data)``: Legge qualsiasi tipo di dato o oggetto dalla EEPROM.

        * ``address``: la posizione da cui leggere, a partire da 0 (int).
        * ``data``: i dati da leggere, possono essere un tipo primitivo (es. float) o una struttura personalizzata.

