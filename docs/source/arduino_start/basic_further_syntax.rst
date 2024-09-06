.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

Regole di Scrittura degli Sketch
=====================================

Se chiedi a un amico di accendere le luci per te, puoi dire "Accendi le luci." oppure "Luci accese, amico.", e puoi usare qualsiasi tono di voce tu voglia.

Tuttavia, se vuoi che la scheda Arduino faccia qualcosa per te, devi seguire le regole di scrittura dei programmi Arduino per digitare i comandi.

Questo capitolo contiene le regole di base del linguaggio Arduino e ti aiuterà a capire come tradurre il linguaggio naturale in codice.

Ovviamente, questo è un processo che richiede tempo per essere assimilato, ed è anche la parte più soggetta a errori per i principianti, quindi se fai errori spesso, va bene, basta riprovare più volte.


Punto e virgola ``;``
------------------------

Proprio come quando scrivi una lettera e metti un punto alla fine di ogni frase per indicarne la conclusione, il linguaggio Arduino richiede di usare ``;`` per indicare alla scheda la fine del comando.

Prendiamo l'esempio familiare del "lampeggio del LED a bordo". Un sketch corretto dovrebbe apparire così.

Esempio:

.. code-block:: C

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

Ora, diamo un'occhiata ai due sketch seguenti e cerchiamo di indovinare se possono essere correttamente riconosciuti da Arduino prima di eseguirli.

Sketch A:

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

Sketch B:

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // inserisci qui il tuo codice di configurazione, da eseguire una sola volta:
        pinMode(13,OUTPUT);
    }
    
    void loop() {
        // inserisci qui il tuo codice principale, da eseguire ripetutamente:
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,
        
        LOW);
                delay(500)
        ;
    }

Il risultato è che **Sketch A** riporta un errore mentre **Sketch B** funziona.

* Gli errori in **Sketch A** sono dovuti alla mancanza di ``;``, e anche se sembra normale, Arduino non può leggerlo.
* **Sketch B**, pur sembrando poco comprensibile per un essere umano, funziona correttamente poiché l'indentazione, le interruzioni di riga e gli spazi all'interno delle istruzioni non vengono considerati nei programmi Arduino, quindi per il compilatore Arduino appare esattamente come nell'esempio precedente.

Tuttavia, per favore, non scrivere il tuo codice come **Sketch B**, perché generalmente sono le persone a scrivere e leggere il codice, quindi non crearti problemi inutili.


Parentesi graffe ``{}``
-------------------------

Le parentesi graffe ``{}`` sono una componente essenziale del linguaggio di programmazione Arduino e devono sempre apparire in coppia. 
Una buona convenzione di programmazione è inserire una struttura che richiede parentesi graffe digitando subito la parentesi graffa destra dopo aver digitato quella sinistra, per poi spostare il cursore tra le parentesi graffe per inserire le istruzioni.



Commento ``//``
-----------------

Il commento è la parte dello sketch che il compilatore ignora. Di solito viene utilizzato per spiegare agli altri come funziona il programma.

Se scriviamo due barre oblique consecutive in una riga di codice, il compilatore ignorerà tutto ciò che segue fino alla fine della riga.

Se creiamo un nuovo sketch, viene fornito con due commenti, e se rimuoviamo questi due commenti, lo sketch non subirà alcuna modifica nel suo funzionamento.

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // put your setup code here, to run once:

    }

    void loop() {
        // put your main code here, to run repeatedly:

    }

I commenti sono molto utili nella programmazione, e qui sotto trovi alcuni usi comuni.

* Uso A: Spiega a te stesso o agli altri cosa fa questa sezione di codice.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); //Set pin 13 to output mode, it controls the onboard LED
    }

    void loop() {
        digitalWrite(13,HIGH); // Activate the onboard LED by setting pin 13 high
        delay(500); // Status quo for 500 ms
        digitalWrite(13,LOW); // Turn off the onboard LED
        delay(500);// Status quo for 500 ms
    }

* Uso B: Invalida temporaneamente alcune istruzioni (senza eliminarle) e rimuovi il commento quando è necessario utilizzarle, evitando così di doverle riscrivere. Questo è molto utile quando si esegue il debug del codice e si cercano di individuare gli errori nel programma.

.. code-block:: C
    :emphasize-lines: 3,4,5,6

    void setup() {
        pinMode(13,OUTPUT);
        // digitalWrite(13,HIGH);
        // delay(1000);
        // digitalWrite(13,LOW);
        // delay(1000);
    }

    void loop() {
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

.. note:: 
    Usa la scorciatoia ``Ctrl+/`` per commentare o rimuovere rapidamente i commenti dal codice.

Commento ``/**/``
------------------

Funziona come ``//`` per i commenti. Questo tipo di commento può estendersi su più righe e una volta che il compilatore legge ``/*``, ignora tutto ciò che segue fino a quando non trova ``*/``.

Esempio 1:

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Blink */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        The following code will blink the onboard LED
        You can modify the number in delay() to change the blinking frequency
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

``#define``
---------------

Questo è uno strumento utile del C++.

.. code-block:: C

    #define identifier token-string

Il compilatore sostituisce automaticamente ``identificatore`` con ``token-string`` quando lo legge, ed è solitamente utilizzato per definire costanti.

Ad esempio, ecco uno sketch che utilizza define, il che migliora la leggibilità del codice.

.. code-block:: C
    :emphasize-lines: 1,2

    #define ONBOARD_LED 13
    #define DELAY_TIME 500

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
        delay(DELAY_TIME); 
        digitalWrite(ONBOARD_LED,LOW); 
        delay(DELAY_TIME);
    }

Per il compilatore, in realtà appare così.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

Possiamo vedere che ``identificatore`` viene sostituito e non esiste all'interno del programma.
Pertanto, ci sono alcuni avvertimenti da tenere in considerazione quando si utilizza ``#define``.

1. Un ``token-string`` può essere modificato solo manualmente e non può essere trasformato in altri valori tramite operazioni aritmetiche nel programma.

2. Evita di usare simboli come ``;``. Per esempio:

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
    }

Il compilatore lo riconoscerà così, il che genererà un errore.

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;,OUTPUT); 
    }

    void loop() {
        digitalWrite(13;,HIGH); 
    }

.. note:: 
    Una convenzione per ``#define`` è quella di scrivere ``identificatore`` in maiuscolo per evitare confusione con le variabili.
