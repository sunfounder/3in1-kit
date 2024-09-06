.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Unisciti agli appassionati per approfondire Raspberry Pi, Arduino ed ESP32 insieme a noi.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e affronta sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti riservati sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_dht11:


5.11.3 Temperatura - Umidità
=======================================

Temperatura e umidità sono strettamente correlate, sia come grandezze fisiche che nella vita quotidiana delle persone.
La temperatura e l'umidità dell'ambiente umano influiscono direttamente sulla funzione di termoregolazione e sull'effetto di trasferimento del calore del corpo umano.
Questo influisce ulteriormente sull'attività mentale e sullo stato psicologico, e di conseguenza sull'efficienza del nostro studio e lavoro.

La temperatura è una delle sette grandezze fisiche fondamentali nel Sistema Internazionale di Unità, utilizzata per misurare il grado di calore o freddo di un oggetto.
Il Celsius è una delle scale di temperatura più utilizzate al mondo, rappresentata dal simbolo "℃".

L'umidità è la concentrazione di vapore acqueo presente nell'aria.
Nella vita quotidiana si utilizza comunemente l'umidità relativa dell'aria, espressa in %RH. L'umidità relativa è strettamente legata alla temperatura.
Per un certo volume di gas sigillato, maggiore è la temperatura, minore è l'umidità relativa, e minore è la temperatura, maggiore è l'umidità relativa.

.. image:: img/Dht11.png

Il dht11, un sensore digitale di temperatura e umidità, è incluso in questo kit. Utilizza un sensore capacitivo di umidità e un termistore per misurare l'aria circostante ed emette un segnale digitale sul pin dei dati.

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
    *   - :ref:`cpn_dht11`
        - \-


**Schema**

.. image:: img/circuit_7.3_dht11.png

**Collegamenti**

.. image:: img/dht11_bb.jpg

**Codice**

.. note::

    * Apri il file ``5.11.temperature_humidity.ino`` nel percorso ``3in1-kit\basic_project\5.11.temperature_humidity``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    * Qui viene utilizzata la ``DHT sensor library``, che puoi installare dal **Library Manager**.

        .. image:: ../img/lib_dht11.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c5b4c902-f39d-45a6-9a17-1308056041a8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo aver caricato correttamente il codice, vedrai il Monitor Seriale stampare continuamente la temperatura e l'umidità, e man mano che il programma si stabilizza, questi due valori diventeranno sempre più accurati.

**Come funziona?**

#.  Includi la libreria ``DHT.h``, che fornisce funzioni per interagire con i sensori DHT. Successivamente, imposta il pin e il tipo per il sensore DHT.

    .. code-block:: arduino

        #include "DHT.h"

        #define DHTPIN 11  // Set the pin connected to the DHT11 data pin
        #define DHTTYPE DHT11 // DHT 11 

        DHT dht(DHTPIN, DHTTYPE);

#. Inizializza la comunicazione seriale a una velocità di trasmissione di 115200 e inizializza il sensore DHT.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            Serial.println("DHT11 test!");
            dht.begin();
        }

#. Nella funzione ``loop()``, leggi i valori di temperatura e umidità dal sensore DHT11 e stampali sul monitor seriale.

    .. code-block:: arduino

        void loop() {
            // Wait a few seconds between measurements.
            delay(2000);

            // Reading temperature or humidity takes about 250 milliseconds!
            // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
            float humidity = dht.readHumidity();
            // Read temperature as Celsius (the default)
            float temperture = dht.readTemperature();

            // Check if any reads failed and exit early (to try again).
            if (isnan(humidity) || isnan(temperture)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
            // Print the humidity and temperature
            Serial.print("Humidity: "); 
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("Temperature: "); 
            Serial.print(temperture);
            Serial.println(" *C");
        }

    * La funzione ``dht.readHumidity()`` viene chiamata per leggere il valore dell'umidità dal sensore DHT.
    * La funzione ``dht.readTemperature()`` viene chiamata per leggere il valore della temperatura dal sensore DHT.
    * La funzione ``isnan()`` viene utilizzata per verificare se le letture sono valide. Se il valore dell'umidità o della temperatura è NaN (not a number), indica una lettura fallita dal sensore, e viene stampato un messaggio di errore.

