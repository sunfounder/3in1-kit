.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

Variabile
===========

La variabile è uno degli strumenti più potenti e cruciali in un programma. Ci aiuta a memorizzare e richiamare dati nei nostri programmi.

Il seguente sketch utilizza delle variabili. Memorizza il numero di pin del LED integrato nella variabile ``ledPin`` e il numero "500" nella variabile ``delayTime``.

.. code-block:: C
    :emphasize-lines: 1,2

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
    }

Aspetta, è un duplicato di quello che fa ``#define``? La risposta è NO.

* Il ruolo di ``#define`` è semplicemente sostituire direttamente il testo, non è considerato dal compilatore come parte del programma.
* Una ``variabile``, invece, esiste all'interno del programma e viene utilizzata per memorizzare e richiamare valori. Una variabile può anche modificare il suo valore all'interno del programma, cosa che un define non può fare.

Il file sketch qui sotto auto-incrementa la variabile, e farà sì che il LED integrato lampeggi più a lungo dopo ogni lampeggio.

.. code-block:: C

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
        delayTime = delayTime+200; //Ogni esecuzione incrementa il valore di 200
    }

Dichiarare una variabile
----------------------------

Dichiarare una variabile significa creare una variabile.

Per dichiarare una variabile, hai bisogno di due cose: il tipo di dato e il nome della variabile. Il tipo di dato deve essere separato dal nome della variabile da uno spazio, e la dichiarazione della variabile deve essere terminata da un ``;``.

Usiamo questa variabile come esempio.

.. code-block:: C

    int delayTime;

**Tipo di Dato**

Qui ``int`` è un tipo di dato chiamato tipo intero, che può essere utilizzato per memorizzare numeri interi da -32768 a 32766. Non può essere utilizzato per memorizzare numeri decimali.

Le variabili possono contenere tipi di dati diversi dagli interi. Il linguaggio Arduino (che, ricordiamo, è C++) ha il supporto integrato per alcuni di essi (qui sono elencati solo i più usati e utili):

* ``float``: Memorizza un numero decimale, ad esempio 3.1415926.
* ``byte``: Può contenere numeri da 0 a 255.
* ``boolean``: Contiene solo due valori possibili, ``True`` o ``False``, anche se occupa un byte in memoria.
* ``char``: Contiene un numero da -127 a 127. Poiché è contrassegnato come ``char``, il compilatore cercherà di associarlo a un carattere dall'|link_ascii|.
* ``string``: Può memorizzare una stringa di caratteri, ad esempio ``Halloween``.

**Nome della Variabile**

Puoi impostare il nome della variabile come desideri, ad esempio ``i``, ``apple``, ``Bruce``, ``R2D2``, ``Sectumsempra``, ma ci sono alcune regole di base da seguire.

1. Descrivi a cosa serve. Qui, ho chiamato la variabile delayTime, così puoi capire facilmente cosa fa. Funzionerebbe bene se chiamassi la variabile ``barryAllen``, ma confonderebbe chi guarda il codice.

2. Usa una nomenclatura regolare. Puoi usare il CamelCase come ho fatto io, con la T maiuscola in ``delayTime`` per rendere chiaro che la variabile è composta da due parole. Inoltre, puoi usare l'UnderScoreCase per scrivere la variabile come ``delay_time``. Non influisce sul funzionamento del programma, ma aiuterebbe il programmatore a leggere il codice se usi la nomenclatura che preferisci.

3. Non usare parole chiave. Simile a ciò che accade quando scriviamo "int", l'Arduino IDE lo colorerà per ricordarti che è una parola con uno scopo speciale e non può essere usata come nome di variabile. Cambia il nome della variabile se viene colorato.

4. I simboli speciali non sono ammessi. Ad esempio, spazio, #, $, /, +, %, ecc. La combinazione di lettere inglesi (case sensitive), underscore e numeri (ma i numeri non possono essere usati come primo carattere di un nome di variabile) è abbastanza ricca.

**Assegnare un valore a una variabile**

Una volta dichiarata la variabile, è il momento di memorizzare i dati. Usiamo l'operatore di assegnazione (cioè ``=``) per inserire un valore nella variabile.

Possiamo assegnare valori alla variabile non appena la dichiariamo.

.. code-block:: C

    int delayTime = 500;

È anche possibile assegnare un nuovo valore in un secondo momento.

.. code-block:: C

    int delayTime; // no value
    delayTime = 500; // value is 500
    delayTime = delayTime +200; // value is 700