.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_digital_write:

1. Scrittura Digitale
==============================

La **Scrittura Digitale** serve per inviare o scrivere un segnale digitale su un pin digitale. Il segnale digitale ha solo due stati: 0 o 1, 0V o 5V, quindi consente ad alcuni componenti, come il LED e il cicalino, di essere accesi o spenti.

Sulla scheda Arduino R3, ci sono 14 pin digitali I/O numerati da 0 a 13. Ora utilizzeremo le funzioni ``pinMode()`` e ``digitalWrite()`` per inviare un livello alto o basso a questi pin digitali.



* ``pinMode(pin, mode)``: Configura un pin specifico come ``INPUT`` o ``OUTPUT``, in questo caso deve essere impostato su ``OUTPUT``.



   **Sintassi**
      pinMode(pin, mode)

   **Parametri**
    * ``pin``: il numero del pin di Arduino da configurare.
    * ``mode``: ``INPUT``, ``OUTPUT`` o ``INPUT_PULLUP``.

* ``digitalWrite(pin, value)``: Scrive un livello alto (5V) o basso (0V) su un pin digitale per modificare lo stato operativo del componente. Se il pin è stato configurato come OUTPUT con pinMode(), la tensione verrà impostata sul valore corrispondente: 5V (o 3.3V per le schede a 3.3V) per HIGH, 0V (massa) per LOW.

   **Sintassi**
      digitalWrite(pin, value)

   **Parametri**
    * ``pin``: il numero del pin di Arduino.
    * ``value``: ``HIGH`` o ``LOW``.

**Esempio di Scrittura Digitale:**

.. code-block:: arduino

   const int pin = 13;

   void setup() {
      pinMode(pin, OUTPUT);    // sets the digital pin as output
   }

   void loop() {
      digitalWrite(pin, HIGH); // sets the digital pin on
      delay(1000);            // waits for a second
      digitalWrite(pin, LOW);  // sets the digital pin off
      delay(1000);            // waits for a second
   }

.. image:: img/1_led.jpg


**Note e Avvertenze**

* I pin da 0 a 13 sono tutti pin digitali.
* Non utilizzare i pin 0 e 1, poiché sono usati per la comunicazione con il computer. Collegare qualsiasi cosa a questi pin interferisce con la comunicazione e può causare il fallimento del caricamento del programma.
* Se i pin digitali sono esauriti, i pin analogici (A0-A5) possono essere usati anche come pin digitali.

**Componenti Correlati**

Di seguito sono elencati i componenti correlati, puoi cliccare per imparare come utilizzarli.

.. toctree::
   :maxdepth: 2

   ar_blinking_led
   ar_active_buzzer
   ar_turn_the_wheel
   ar_pumping


