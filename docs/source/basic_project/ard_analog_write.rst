.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_analog_write:

2. Scrittura Analogica
=========================

6 dei 14 pin digitali di Arduino supportano anche la funzione PWM. Oltre a scrivere segnali digitali su questi 6 pin, è possibile inviare segnali analogici (segnali d'onda PWM). In questo modo puoi far sì che i LED mostrino diverse luminosità o far ruotare il motore a velocità differenti.

La modulazione a larghezza di impulso, o `PWM <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_, è una tecnica che consente di ottenere risultati analogici con mezzi digitali. Poiché il significato letterale può essere difficile da comprendere, ecco un esempio di controllo dell'intensità di un LED per aiutarti a capire meglio.

Un segnale digitale composto da livelli alti e bassi è chiamato impulso. La larghezza dell'impulso di questi pin può essere regolata cambiando la velocità di accensione/spegnimento.
In parole povere, quando accendiamo e spegniamo un LED ripetutamente per un breve periodo di tempo (ad esempio 20ms, il tempo di persistenza visiva per la maggior parte delle persone), non vedremo che si è spento, ma la luminosità della luce sarà leggermente inferiore. In questo periodo, più a lungo il LED rimane acceso, più sarà luminoso.
Detto ciò, più ampio è l'impulso all'interno di un intervallo di tempo, maggiore sarà la "forza del segnale elettrico" emessa dal microcontrollore.

Questa è la funzione necessaria per scrivere l'onda PWM.

* ``analogWrite(pin, value)``

    Scrive un valore analogico (onda PWM) su un pin. Generando un segnale a impulsi specificato, è possibile simulare tensioni di uscita diverse (0-5V). Il pin manterrà questo segnale fino a quando non verrà richiamato da un'altra istruzione di lettura o scrittura.

   **Sintassi**
      analogWrite(pin, value)

   **Parametri**
    * ``pin``: il pin Arduino su cui scrivere. Tipi di dati consentiti: int.
    * ``value``: il ciclo di lavoro: tra 0 (sempre spento) e 255 (sempre acceso). Tipi di dati consentiti: int.


**Esempio di Scrittura Analogica**

.. code-block:: arduino

   int pin = 9;      //collega al pin pwm

   void setup() {
      pinMode(pin, OUTPUT);  // imposta il pin come uscita
   }

   void loop() {
      for (int i = 0; i < 255; i++){
         analogWrite(pin, i); //analogWrite valori da 0 a 255
         delay(30);
      }
   }

**Note e Avvertenze**

* Guardando da vicino la scheda R3, i pin contrassegnati con il simbolo "~" hanno la funzione di uscita analogica.
* Gli output PWM generati sui pin 5 e 6 avranno cicli di lavoro più alti del previsto. Ciò è dovuto alle interazioni con le funzioni ``millis()`` e ``delay()``, che condividono lo stesso timer interno utilizzato per generare quegli output PWM. Questo sarà evidente soprattutto su impostazioni di ciclo di lavoro basso (ad esempio 0-10) e potrebbe far sì che un valore di 0 non spenga completamente l'uscita sui pin 5 e 6.


**Componenti Correlati**

Di seguito sono elencati i componenti correlati, puoi cliccare per imparare come utilizzarli.

.. toctree::
   :maxdepth: 2

   ar_fading
   ar_colorful_light
