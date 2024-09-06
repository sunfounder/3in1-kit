.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri nuovi prodotti.
    - **Promozioni festive e omaggi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_reversing_aid:

6.4 Sistema di Assistenza al Parcheggio
===========================================

Con lo sviluppo della scienza e della tecnologia, molti prodotti high-tech 
sono stati installati nelle auto, tra cui il sistema di assistenza al parcheggio. 
In questo progetto, utilizzeremo un modulo a ultrasuoni, un display LCD, LED e un 
buzzer per creare un semplice sistema di assistenza al parcheggio.

**Componenti necessari**

Per questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente comodo acquistare un intero kit, ecco il link:

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Schema elettrico**

.. image:: img/image265.png
    :width: 800
    :align: center

**Collegamenti**

.. image:: img/backcar.png
    :width: 800
    :align: center

**Codice**

.. note::

    * Puoi aprire il file ``6.4_reversingAid.ino`` nel percorso ``3in1-kit\basic_project\6.4_reversingAid`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.
    * La libreria ``LiquidCrystal I2C`` è utilizzata qui, puoi installarla dal **Library Manager**.

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d6848669-fe79-42e9-afd7-0f083f96a6d6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo aver caricato correttamente il codice, la distanza rilevata verrà visualizzata sull'LCD. Successivamente, il buzzer cambierà la frequenza del suono in base alle diverse distanze.

.. note::
    Se il codice e i collegamenti sono corretti, ma l'LCD non mostra nulla, puoi regolare il potenziometro sul retro.


**Come funziona?**

Questo codice ci aiuta a creare un semplice dispositivo di misurazione della distanza che può rilevare la distanza tra oggetti e fornire un feedback tramite un display LCD e un buzzer.

La funzione ``loop()`` contiene la logica principale del programma e viene eseguita continuamente. Vediamo più da vicino la funzione ``loop()``.

#. Ciclo per leggere la distanza e aggiornare i parametri

    Nel ciclo ``loop``, il codice legge prima la distanza misurata dal modulo a ultrasuoni e aggiorna il parametro dell'intervallo in base alla distanza.

    .. code-block:: arduino

        // Update the distance
        distance = readDistance();

        // Update intervals based on distance
        if (distance <= 10) {
            intervals = 300;
        } else if (distance <= 20) {
            intervals = 500;
        } else if (distance <= 50) {
            intervals = 1000;
        } else {
            intervals = 2000;
        }

#. Verifica se è il momento di emettere un beep

    Il codice calcola la differenza tra il tempo attuale e il tempo del beep precedente, e se la differenza è maggiore o uguale al tempo dell'intervallo, attiva il buzzer e aggiorna il tempo del beep precedente.

    .. code-block:: arduino

        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= intervals) {
            Serial.println("Beeping!");
            beep();
            previousMillis = currentMillis;
        }

#. Aggiornamento del display LCD

    Il codice pulisce il display LCD e visualizza "Dis:" e la distanza attuale in centimetri sulla prima linea.

    .. code-block:: arduino

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dis: ");
        lcd.print(distance);
        lcd.print(" cm");

        delay(100);