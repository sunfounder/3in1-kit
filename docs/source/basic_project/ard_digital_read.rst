.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_digital_read:

3. Lettura Digitale
========================

I sensori catturano informazioni dal mondo reale e le comunicano alla scheda principale tramite pin (alcuni digitali, altri analogici) affinché il computer possa comprendere la situazione attuale.

Di conseguenza, la scheda Arduino può conoscere lo stato di funzionamento dei sensori digitali leggendo il valore dei pin digitali, come i pulsanti o il modulo di evitamento ostacoli a infrarossi.


Ecco le funzioni necessarie.

* ``pinMode(pin, mode)``: Configura il pin specifico come ``INPUT`` o ``OUTPUT``. Qui deve essere impostato come ``INPUT``.

   **Sintassi**
      pinMode(pin, mode)

   **Parametri**
    * ``pin``: il numero del pin di Arduino di cui impostare la modalità.
    * ``mode``: INPUT, OUTPUT o INPUT_PULLUP.



* ``digitalRead(pin)``: Legge il valore (stato del livello) dal pin digitale specificato.

   **Sintassi**
      digitalRead(pin)

   **Parametri**
    * ``pin``: il numero del pin di Arduino che desideri leggere.

   **Ritorna**
      HIGH o LOW.


**Esempio di Lettura Digitale**

.. code-block:: arduino

   int ledPin = 13;  // LED connected to digital pin 13
   int inPin = 7;    // pushbutton connected to digital pin 7
   int val = 0;      // variable to store the read value

   void setup() {
      pinMode(ledPin, OUTPUT);  // sets the digital pin 13 as output
      pinMode(inPin, INPUT);    // sets the digital pin 7 as input
   }

   void loop() {
      val = digitalRead(inPin);   // read the input pin
      digitalWrite(ledPin, val);  // sets the LED to the button's value
   }


**Note e Avvertenze**

1. Pull Up & Pull Down.

    ``digitalRead()`` può produrre valori casuali e indeterminati se il pin non riceve un segnale di livello. Pertanto, indirizzare i pin di ingresso a uno stato noto può rendere il progetto più affidabile.
    Quando si utilizza un componente di ingresso, come un pulsante, è solitamente necessario collegare una resistenza pull-up o pull-down in parallelo al pin di ingresso digitale.

    Oltre a collegare una resistenza pull-up, puoi anche impostare la modalità del pin su ``INPUT_PULLUP`` nel codice, ad esempio ``pinMode(pin, INPUT_PULLUP)``. In questo caso, il pin accederà alla resistenza pull-up integrata dell'Atmega tramite software, con lo stesso effetto del collegamento di una resistenza pull-up.

2. Riguardo al Pin 13.

    Tutti i pin digitali (1-13) sulla scheda R3 possono essere utilizzati come ``digitalRead()``.
    Tuttavia, il pin digitale 13 è più difficile da usare come ingresso rispetto agli altri pin digitali. Questo perché è collegato a un LED e una resistenza, saldati sulla maggior parte delle schede.
    Se abiliti la resistenza pull-up interna da 20k, rimarrà intorno a 1.7V invece dei 5V previsti, poiché il LED integrato e la resistenza in serie abbassano il livello di tensione, il che significa che restituirà sempre LOW. Se devi utilizzare il pin 13 come ingresso digitale, imposta la sua ``pinMode()`` su INPUT e usa una resistenza pull-down esterna.

3. Pin analogici.

    Se i pin digitali non sono sufficienti, i pin analogici (A0-A5) possono essere utilizzati anche come pin digitali.
    Devono essere impostati su INPUT con ``pinMode(pin,mode)``.


**Componenti Correlati**

Di seguito sono elencati i componenti correlati, puoi cliccare per imparare come utilizzarli.

.. toctree::
    :maxdepth: 2

    ar_serial_monitor
    ar_button
    ar_reed
    ar_detect_the_obstacle
    ar_detect_the_line


