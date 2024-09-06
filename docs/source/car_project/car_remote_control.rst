.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e concorsi**: Partecipa a concorsi e promozioni speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _car_remote:

9. Telecomando
==================

Questo kit include un ricevitore IR che ti permette di utilizzare un telecomando a infrarossi per controllare il movimento dell'auto.

**Componenti necessari**

Per questo progetto, avremo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - Kit Starter 3 in 1
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
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_receiver`
        - \-

**Collegamenti**

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/M8buGWCkYcI?si=spLK2KP363rkN6sl" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Ora costruisci il circuito seguendo lo schema qui sotto.

.. list-table:: 
    :header-rows: 1

    * - Ricevitore IR
      - Scheda R3
    * - OUT
      - 12
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_9.png
    :width: 800

**Codice**

.. note::

    * Apri il file ``9.remote_control.ino`` nel percorso ``3in1-kit\car_project\9.remote_control``.
    * Oppure copia questo codice nell'**IDE di Arduino**.
    * Qui viene utilizzata la libreria ``IRremote``, puoi installarla dal **Library Manager**.
  
        .. image:: ../img/lib_irremote.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/7c78450d-fcd2-4288-a00d-499c71ad2d52/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Dopo che il codice è stato caricato con successo, premi il pulsante sul telecomando e il LED lampeggerà una volta per indicare che il segnale è stato ricevuto, e l'auto si muoverà in base al pulsante premuto. Puoi premere i seguenti tasti per controllare l'auto.

* **+**: Aumenta la velocità
* **-**: Riduci la velocità
* **1**: Avanti a sinistra
* **2**: Avanti
* **3**: Avanti a destra
* **4**: Gira a sinistra
* **6**: Gira a destra
* **7**: Indietro a sinistra
* **8**: Indietro
* **9**: Indietro a destra


**Come funziona?**

L'effetto di questo progetto è far muovere l'auto leggendo il valore del tasto del telecomando a infrarossi. Inoltre, il LED sul pin 13 lampeggerà per indicare la ricezione corretta del segnale IR.

#. Importa la libreria ``IRremote``, che puoi installare dal **Library Manager**.


    .. code-block:: arduino

        #include <IRremote.h>

        const int IR_RECEIVE_PIN = 12;  // Definisce il numero di pin per il sensore IR

#. Inizializza la comunicazione seriale a un baud rate di 9600. Inizializza il ricevitore IR sul pin specificato (``IR_RECEIVE_PIN``) e abilita il feedback LED (se applicabile).

    .. code-block:: arduino

        ...

        void setup() {

            ...
            // Telecomando IR
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Avvia il ricevitore
            Serial.println("TELECOMANDO AVVIATO");

        }


#. Quando premi i tasti sul telecomando, il ricevitore infrarossi rileverà quale tasto è stato premuto, e l'auto si muoverà secondo il valore corrispondente.


    .. code-block:: arduino

        void loop() {

            if (IrReceiver.decode()) {
                //    Serial.println(results.value,HEX);
                String key = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (key != "ERROR") {
                    Serial.println(key);

                    if (key == "+") {
                        speed += 50;
                    } else if (key == "-") {
                        speed -= 50;
                    } else if (key == "2") {
                        moveForward(speed);
                        delay(1000);
                    ...
                    }
                    IrReceiver.resume();  // Abilita la ricezione del prossimo segnale

            }
        }

    * Verifica se un segnale IR è stato ricevuto e decodificato correttamente.
    * Decodifica il comando IR e lo memorizza in ``key`` utilizzando una funzione personalizzata ``decodeKeyValue()``.
    * Verifica se il valore decodificato non è un errore.
    * Stampa il valore IR decodificato nel monitor seriale.
    * Riprende la ricezione del segnale IR per il prossimo segnale.
