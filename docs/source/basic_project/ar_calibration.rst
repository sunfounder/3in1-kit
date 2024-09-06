.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Unisciti agli appassionati per approfondire Raspberry Pi, Arduino ed ESP32 insieme a noi.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche grazie all'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti esclusivi**: Approfitta di sconti riservati sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_calibration:

5.14 Calibrazione
==========================

Quando si utilizzano componenti con ingresso analogico, come fotoresistenze, sensori di umidità del terreno, ecc., si può notare che il loro intervallo di lettura non è 0-1023, ma piuttosto un intervallo come 0-800 o 600-1000, poiché è impossibile raggiungere i limiti di questi dispositivi con un uso normale.

In questo caso, è possibile utilizzare una tecnica di calibrazione degli ingressi dei sensori. Durante l'avvio, la scheda di controllo misura i valori dei sensori per cinque secondi e registra le letture massime e minime. Questo intervallo di cinque secondi definisce i valori minimi e massimi previsti per le letture che verranno effettuate durante il ciclo.

In questo progetto, utilizziamo una fotoresistenza e un buzzer passivo per realizzare un gioco simile a un `theremin <https://en.wikipedia.org/wiki/Theremin>`_, sfruttando la tecnica di calibrazione descritta sopra.

.. note::
    Il `theremin <https://en.wikipedia.org/wiki/Theremin>`_ è uno strumento musicale elettronico che non richiede contatto fisico. Genera diversi toni rilevando la posizione delle mani del musicista.

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
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Schema**

.. image:: img/circuit_8.8_calibration.png

**Collegamenti**

.. image:: img/calibration_bb.jpg
    :width: 600
    :align: center

**Codice**

.. note::

    * Apri il file ``5.14.calibration.ino`` nel percorso ``3in1-kit\basic_project\5.14.calibration``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    
    * Oppure carica il codice tramite `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/9cbcaae0-3c9d-4e33-9957-548f92a9aab7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Dopo che il codice è stato caricato con successo, il LED si accenderà e avremo 5 secondi per calibrare l'intervallo di rilevamento della fotoresistenza. Questo perché ogni volta che lo usiamo, potremmo trovarci in un ambiente con illuminazione diversa (ad esempio, la luce può variare tra mezzogiorno e il crepuscolo).

In questo momento, dobbiamo muovere le mani sopra la fotoresistenza, e il movimento della mano verrà calibrato per determinare l'intervallo di gioco di questo strumento.

Dopo 5 secondi, il LED si spegnerà e potremo muovere le mani sopra la fotoresistenza per suonare.




**Come funziona?**

#. Imposta i valori iniziali e i pin di tutti i componenti.

    .. code-block:: arduino

        const int buzzerPin = 9;
        const int ledPin = 8;
        const int photocellPin = A0;  //photoresistor attach to A2
    
        int lightLow = 1023;
        int lightHigh = 0;
    
        int sensorValue = 0;        // value read from the sensor
        int pitch = 0;           // sensor value converted into LED 'bars'
    
        unsigned long previousMillis = 0;
        const long interval = 5000;

#. Imposta un processo di calibrazione nel ``setup()``.

    .. code-block:: arduino

        void setup()
        {
            pinMode(buzzerPin, OUTPUT); // make buzzer output
            pinMode(ledPin, OUTPUT); // make the LED pin output

            /* calibrate the photoresistor max & min values */
            previousMillis = millis();
            digitalWrite(ledPin, HIGH);
            while (millis() - previousMillis <= interval) {
                sensorValue = analogRead(photocellPin);
                if (sensorValue > lightHigh) {
                    lightHigh = sensorValue;
                }
                if (sensorValue < lightLow) {
                    lightLow = sensorValue;
                }
            }
            digitalWrite(ledPin, LOW);
        }

    Il flusso di lavoro è il seguente.

    * Usare ``millis()`` per il temporizzatore con un intervallo di 5000ms.

    .. code-block:: arduino

        previousMillis = millis();
        ...
        while (millis() - previousMillis <= interval) {
        ...
        }

    * Durante questi cinque secondi, muovi la mano attorno alla fotoresistenza; i valori massimi e minimi rilevati vengono registrati e assegnati rispettivamente a ``lightHigh`` e ``lightLow``.

    .. code-block:: arduino
        
        sensorValue = analogRead(photocellPin);
        if (sensorValue > lightHigh) {
            lightHigh = sensorValue;
        }
        if (sensorValue < lightLow) {
            lightLow = sensorValue;
        }

#. Ora puoi iniziare a suonare questo Thermin. Leggi il valore della fotoresistenza in ``sensorValue`` e mappalo da un intervallo piccolo a uno grande, utilizzandolo come frequenza per il buzzer.

    .. code-block:: arduino

        void loop()
        {
        /* play*/
        sensorValue = analogRead(photocellPin); //read the value of A0
        pitch = map(sensorValue, lightLow, lightHigh, 50, 6000);  // map to the buzzer frequency
        if (pitch > 50) {
            tone(buzzerPin, pitch, 20);
        }
        delay(10);
        }