.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e concorsi**: Partecipa a concorsi e promozioni speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _car_ultrasonic:

6. Gioca con il Modulo Ultrasonico
=====================================

Nel progetto :ref:`car_ir_obstacle`, i 2 moduli a infrarossi vengono utilizzati per l'evitamento degli ostacoli, ma la distanza di rilevamento del modulo IR è corta, il che potrebbe far sì che l'auto reagisca troppo tardi agli ostacoli.

In questo progetto, utilizziamo il modulo ultrasonico per eseguire un rilevamento a lunga distanza, in modo che l'auto possa percepire gli ostacoli da una distanza maggiore e prendere decisioni di conseguenza.

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Collegamenti**

Un modulo sensore ultrasonico è uno strumento che misura la distanza di un oggetto utilizzando onde sonore ultrasoniche.
Ha due sonde. Una invia onde ultrasoniche e l'altra riceve le onde, trasformando il tempo di invio e ricezione in una distanza, rilevando così la distanza tra il dispositivo e un ostacolo.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/qx9ZH-YnAkg?si=wfrsDrmGCPa2nYPD" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Ora costruisci il circuito secondo il seguente schema.

.. list-table:: 
    :header-rows: 1

    * - Modulo Ultrasonico
      - Scheda R3
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

.. image:: img/car_6.png
    :width: 800

**Codice**

.. note::

    * Apri il file ``6.ultrasonic_module.ino`` nel percorso ``3in1-kit\car_project\6.ultrasonic_module``.
    * Oppure copia questo codice nell'**IDE di Arduino**.
    
    * Oppure carica il codice tramite `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/ae97f966-9d72-40e6-aa9f-e0767ddf5bd5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Dopo che il codice sarà caricato con successo, gira l'auto verso il muro. Se la distanza è troppo grande, l'auto avanzerà; se è troppo vicina, arretrerà; se si trova a una distanza di sicurezza, si fermerà.


**Come funziona?**

Questo progetto si basa sulla distanza letta dal modulo ultrasonico per far muovere l'auto di conseguenza.

#. Aggiungi la definizione dei pin per il modulo ultrasonico, ``trigPin`` viene utilizzato per trasmettere l'onda ultrasonica, quindi impostalo su ``OUTPUT``; ``echoPin`` è impostato su ``INPUT`` per ricevere l'onda ultrasonica.

    .. code-block:: arduino

        ...
        const int trigPin = 3;
        const int echoPin = 4;

        void setup() {
        ...

        //ultrasonic
            pinMode(echoPin, INPUT);
            pinMode(trigPin, OUTPUT);
        }

#. Leggi il valore della distanza ottenuto dal modulo ultrasonico: se la distanza è maggiore di 25, fai avanzare l'auto; se la distanza è compresa tra 2 e 10 cm, fai arretrare l'auto; altrimenti (tra 10 e 25) fermati.

    .. code-block:: arduino

        void loop() {
            float distance = readSensorData();
            if (distance > 25) {
                moveForward(200);
            }
            else if (distance < 10 && distance > 2) {
                moveBackward(200);
            } else {
                stopMove();
            }
        }

#. A proposito della funzione ``readSensorData()``.

    Il trasmettitore del modulo ultrasonico trasmette un segnale a onda quadra da 10us ogni 2us, e il ricevitore riceve un segnale di livello alto se c'è un ostacolo entro il raggio di rilevamento. Utilizza la funzione ``pulseIn()`` per registrare il tempo dall'invio alla ricezione, dividi per la velocità del suono 340m/s, e poi dividi per 2; il risultato è la distanza tra il modulo e l'ostacolo in cm.

    .. code-block:: arduino

        float readSensorData() {
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);
            float distance = pulseIn(echoPin, HIGH) / 58.00; //Equivalent to (340m/s*1us)/2
            return distance;
        }

* `pulseIn(pin, value) <https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/>`_

    * ``pin``: il numero del pin di Arduino da cui vuoi leggere l'impulso. Tipi di dati ammessi: int.
    * ``value``: tipo di impulso da leggere: HIGH o LOW. Tipi di dati ammessi: int.

    Legge un impulso (HIGH o LOW) su un pin. Ad esempio, se il valore è HIGH, ``pulseIn()`` attende che il pin passi da LOW a HIGH, avvia il conteggio del tempo, poi attende che il pin torni a LOW e ferma il conteggio.
