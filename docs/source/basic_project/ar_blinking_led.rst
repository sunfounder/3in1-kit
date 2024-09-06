.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Unisciti agli appassionati per approfondire Raspberry Pi, Arduino ed ESP32 insieme a noi.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche grazie all'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti esclusivi**: Approfitta di sconti riservati sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_blink:

1.1 Ciao, LED! 
=======================================

Proprio come stampare "Hello, world!" è il primo passo nell'apprendimento della programmazione, usare un programma per accendere un LED è la tradizionale introduzione alla programmazione fisica.

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

**Schema**

.. image:: img/circuit_1.1_led.png

Il principio di questo circuito è semplice e la direzione della corrente è mostrata nella figura. Quando il pin 9 emette un livello alto (5V), il LED si accenderà grazie alla resistenza di limitazione da 220 ohm. Quando il pin 9 emette un livello basso (0V), il LED si spegnerà.

**Collegamenti**

.. image:: img/wiring_led.png
    :width: 400
    :align: center

**Codice**

.. note::

   * Puoi aprire il file ``1.1.hello_led.ino`` nel percorso ``3in1-kit\basic_project\1.1.hello_led``. 
   * Oppure copia questo codice nell'**Arduino IDE**.
   
   * Oppure carica il codice tramite `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.



.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/0497f915-5bf8-41a2-8e0f-b013130a57f5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo che il codice è stato caricato con successo, vedrai il LED lampeggiare.

**Come funziona?**

Qui, colleghiamo il LED al pin digitale 9, quindi dobbiamo dichiarare una variabile int chiamata ledpin all'inizio del programma e assegnarle il valore 9.

.. code-block:: arduino

    const int ledPin = 9;


Ora, inizializza il pin nella funzione ``setup()``, dove è necessario impostarlo in modalità ``OUTPUT``.

.. code-block:: arduino

    void setup() {
        pinMode(ledPin, OUTPUT);
    }

Nel ciclo ``loop()``, il comando ``digitalWrite()`` fornisce un segnale ad alto livello di 5V al ledpin, creando una differenza di tensione tra i pin del LED e facendolo accendere.

.. code-block:: arduino

    digitalWrite(ledPin, HIGH);

Se il segnale viene cambiato a LOW, il segnale del ledPin tornerà a 0V e il LED si spegnerà.

.. code-block:: arduino

    digitalWrite(ledPin, LOW);

È necessario un intervallo tra accensione e spegnimento per permettere alle 
persone di vedere il cambiamento, quindi usiamo il comando ``delay(1000)`` 
per far sì che il controller resti inattivo per 1000 ms.

.. code-block:: arduino

    delay(1000);   