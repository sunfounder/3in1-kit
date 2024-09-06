.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_receiver:

5.11.2 Ricevitore IR
=========================

In questo progetto, imparerai a utilizzare il ricevitore IR.

Un ricevitore a infrarossi è un componente che riceve segnali a infrarossi e può ricevere raggi infrarossi in modo indipendente e fornire segnali compatibili con il livello TTL. Ha dimensioni simili a un normale transistor incapsulato in plastica ed è adatto a tutti i tipi di telecomandi a infrarossi e trasmissioni IR.

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
    *   - :ref:`cpn_receiver`
        - \-

**Schema Elettrico**

.. image:: img/circuit_7.2_receiver.png

**Collegamenti**

In questo esempio, colleghiamo il pin sinistro del ricevitore IR al pin 11,
il pin centrale a GND e il pin destro a 5V.

.. image:: img/ir_remote_control_bb.jpg


**Codice**

.. note::

    * Apri il file ``5.11.ir_receiver.ino`` nel percorso ``3in1-kit\basic_project\5.11.ir_receiver``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    * La libreria ``IRremote`` viene utilizzata qui, puoi installarla dal **Library Manager**.
  
        .. image:: ../img/lib_irremote.png


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1141d808-cc26-4589-ae5c-d1834033ac3d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Dopo aver caricato il codice sulla scheda R3, puoi vedere il valore corrente 
del pulsante premuto del telecomando IR visualizzato sul monitor seriale.

**Come funziona?**

Questo codice è progettato per funzionare con un telecomando a infrarossi (IR) utilizzando la libreria ``IRremote``. Ecco una descrizione del funzionamento:

#. Includi le librerie: Viene inclusa la libreria ``IRremote``, che fornisce funzioni per lavorare con i telecomandi IR.

    .. code-block:: arduino

        #include <IRremote.h>

#. Definisci il pin di Arduino a cui è collegato il pin del segnale del sensore IR.

    .. code-block:: arduino

        const int IR_RECEIVE_PIN = 11;  // Define the pin number for the IR Sensor

#. Inizializza la comunicazione seriale a un baud rate di 9600. Inizializza il ricevitore IR sul pin specificato (``IR_RECEIVE_PIN``) e abilita il feedback LED (se applicabile).

    .. code-block:: arduino

        void setup() {
            Serial.begin(9600);                                     // Start serial communication at 9600 baud rate
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver
        }

#. Il ciclo loop viene eseguito continuamente per elaborare i segnali in arrivo dal telecomando IR.

    .. code-block:: arduino

        void loop() {
            if (IrReceiver.decode()) {
                String decodedValue = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (decodedValue != "ERROR") {
                    Serial.println(decodedValue);
                    delay(100);
                }
                IrReceiver.resume();  // Enable receiving of the next value
            }
        }
    
    * Verifica se un segnale IR è stato ricevuto e decodificato correttamente.
    * Decodifica il comando IR e lo memorizza in ``decodedValue`` utilizzando una funzione personalizzata ``decodeKeyValue()``.
    * Verifica che il valore decodificato non sia un errore.
    * Stampa il valore decodificato IR sul monitor seriale.
    * Riprende la ricezione dei segnali IR per il prossimo segnale.
