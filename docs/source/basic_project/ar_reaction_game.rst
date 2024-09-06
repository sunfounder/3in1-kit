.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri nuovi prodotti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_reaction_game:

6.5 Gioco di Reazione
==========================

Il nostro corpo ha diversi tempi di reazione, come quello uditivo, visivo, tattile, ecc.

I tempi di reazione influenzano molte attività della nostra vita quotidiana; ad esempio, tempi di reazione più lenti alla guida possono avere conseguenze gravi.

In questo progetto, utilizziamo 3 pulsanti e 2 LED per misurare il tempo di reazione visiva.

Il monitor seriale di Arduino visualizza il messaggio "waiting..."
Dopo aver premuto il pulsante Ready, uno dei due LED si accenderà casualmente dopo un intervallo di tempo casuale. È importante che il partecipante preme il pulsante corrispondente il più velocemente possibile.
Arduino registra il tempo che intercorre tra l'accensione del LED e la pressione del pulsante e stampa il tempo di reazione misurato sul monitor seriale di Arduino.

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

**Schema Elettrico**

.. image:: img/wiring_reaction_game.png
    :align: center

**Collegamenti**

.. image:: img/reaction_game.png
    :align: center

**Codice**

.. note::

    * Puoi aprire il file ``6.5_reaction_time.ino`` nel percorso ``3in1-kit\basic_project\6.5_reversingAid`` direttamente.
    * Oppure copia questo codice nell'**Arduino IDE**.
    
    * Assicurati di aver aggiunto la libreria ``LiquidCrystal_I2C``, fai riferimento al tutorial dettagliato: :ref:`install_libraries_ar`.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/4313dd1c-e1d2-4939-ae20-0a5b82a12390/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Come funziona?**

#. Inizializza i pulsanti e i LED, qui vengono utilizzati 2 interrupt per leggere lo stato dei pulsanti.

    .. code-block:: arduino

        void setup()
        {

            ...

            attachInterrupt(digitalPinToInterrupt(buttonPin1), pressed1, FALLING);
            attachInterrupt(digitalPinToInterrupt(buttonPin2), pressed2, FALLING);
            ...
        }

#. Se il pulsante ``rstBtn`` viene premuto, il gioco ricomincia. Dopo un intervallo di tempo casuale compreso tra 2 e 5ms, uno dei LED si accende.

    .. code-block:: arduino

        void loop()
        {
            if (flag == -1 && digitalRead(rstBtn) == LOW) {
                digitalWrite(ledPin1, LOW);
                digitalWrite(ledPin2, LOW);
                Serial.println("Waiting...");
                int randomTime = random(2000, 5000);
                delay(randomTime);

                timer = millis();
                flag = randomTime % 2;
                Serial.println("Light!");

                if (flag == 0) {
                    digitalWrite(ledPin1, HIGH);
                } else if (flag == 1) {
                    digitalWrite(ledPin2, HIGH);
                }
            }
            delay(200);
        }

    * Quando il flag è -1 e il pulsante ``rstBtn`` viene premuto, utilizza la funzione ``random()`` per generare un tempo casuale tra 2 e 5 secondi.
    * Questo tempo viene poi utilizzato per controllare l'accensione dei LED.
    * L'accensione dei 2 LED viene generata casualmente tramite ``randomTime % 2`` con 0 e 1. Se il flag è 0, si accende il LED1; se 1, si accende il LED2.

#. Funzione ``pressed1()``

    .. code-block:: arduino

        void pressed1() {
            if (flag == -1) {
                return;
            }
            if (flag == 0) {
                int currentTime = millis();
                Serial.print("Correct! You reaction time is : ");
                Serial.print(currentTime - timer);
                Serial.println(" ms");
            } else if (flag == 1) {
                Serial.println("Wrong Click!");
            }
            flag = -1;
        }

    Questa è la funzione che viene attivata quando viene premuto il pulsante 1. Se il flag è 0, viene stampato il tempo di reazione; altrimenti viene segnalato l'errore di pressione.

#. Funzione ``pressed2()``

    .. code-block:: arduino

        void pressed2() {
            if (flag == -1) {
                return;
            }
            if (flag == 1) {
                int currentTime =millis();
                Serial.print("Correct! You reaction time is : ");
                Serial.print(currentTime - timer);
                Serial.println(" ms");
            } else if (flag == 0) {
                Serial.println("Wrong Click!");
            }
            flag = -1;
        }

    Questa è la funzione che viene attivata quando viene premuto il pulsante 2. Se il flag è 1, viene stampato il tempo di reazione; altrimenti viene segnalato l'errore di pressione.
