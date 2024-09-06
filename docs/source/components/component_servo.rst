.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_servo:

Servo
===========

.. image:: img/servo.png
    :align: center

Un servo è generalmente composto dalle seguenti parti: custodia, albero, sistema di ingranaggi, potenziometro, motore DC e scheda integrata.

Funziona così: il microcontrollore invia segnali PWM al servo, la scheda integrata nel servo riceve i segnali tramite il pin di segnale e controlla il motore interno per farlo girare. Di conseguenza, il motore aziona il sistema di ingranaggi che, dopo una riduzione di velocità, fa muovere l'albero. L'albero e il potenziometro del servo sono collegati insieme. Quando l'albero ruota, muove il potenziometro, che invia un segnale di tensione alla scheda integrata. La scheda determina la direzione e la velocità di rotazione in base alla posizione attuale, così da fermarsi esattamente nella posizione definita e mantenerla.

.. image:: img/servo_internal.png
    :align: center

L'angolo è determinato dalla durata di un impulso applicato al filo di controllo. Questo è chiamato Pulse Width Modulation. Il servo si aspetta di ricevere un impulso ogni 20 ms. La lunghezza dell'impulso determinerà quanto il motore ruoterà. Ad esempio, un impulso di 1,5 ms farà ruotare il motore fino alla posizione di 90 gradi (posizione neutra).
Quando un impulso inviato a un servo è inferiore a 1,5 ms, il servo ruota in una posizione e mantiene il suo albero di uscita a un certo numero di gradi in senso antiorario rispetto al punto neutro. Quando l'impulso è più lungo di 1,5 ms avviene il contrario. La larghezza minima e massima dell'impulso che comanderà il servo a ruotare in una posizione valida è una funzione di ogni servo. Generalmente, l'impulso minimo sarà di circa 0,5 ms e l'impulso massimo sarà di 2,5 ms.

.. image:: img/servo_duty.png
    :width: 600
    :align: center

**Esempio**

* :ref:`ar_servo` (Basic Project)
* :ref:`iot_gate` (IoT Project)
* :ref:`sh_pendulum` (Scratch Project)



