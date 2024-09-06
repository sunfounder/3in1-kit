.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_analog_read:

4. Lettura Analogica
=========================

L'Arduino può leggere i sensori analogici collegati tramite i pin analogici.

La scheda R3 contiene un convertitore analogico-digitale multicanale a 10 bit. Ciò significa che mappa la tensione di ingresso tra 0 e la tensione di funzionamento (5V o 3.3V) in un valore intero compreso tra 0 e 1023.

È necessario utilizzare la funzione ``analogRead(pin)`` per leggere il valore del pin analogico.

* ``analogRead(pin)``: Legge il valore dal pin analogico specificato.

   **Sintassi**
      analogRead(pin)

   **Parametri**
        * ``pin``: il nome del pin di ingresso analogico da cui leggere (da A0 a A5).

   **Ritorno**
      0-1023. Tipo di dato: int.


**Esempio di Lettura Analogica**

.. code-block:: arduino

   int analogPin = A0; // device connected to analog pin A0
                     // outside leads to ground and +5V
   int val = 0;  // variable to store the value read

   void setup() {
      Serial.begin(9600);           //  setup serial
   }

   void loop() {
      val = analogRead(analogPin);  // read the input pin
      Serial.println(val);          // debug value
   }


**Note e Avvertenze**

* I pin analogici sono A0-A5.
* Non è necessario chiamare ``pinMode()`` prima di utilizzare il pin analogico, ma se il pin è stato precedentemente impostato su ``OUTPUT``, la funzione ``analogRead()`` non funzionerà correttamente, in tal caso sarà necessario chiamare ``pinMode()`` per reimpostarlo su ``INPUT``.

**Componenti Correlati**

Di seguito sono elencati i componenti correlati, puoi cliccare per imparare come utilizzarli.

.. toctree::
    :maxdepth: 2

    ar_turn_the_knob
    ar_photoresistor
    ar_joystick
    ar_moisture
    ar_thermistor