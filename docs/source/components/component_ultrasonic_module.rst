.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_ultrasonic:

Modulo Ultrasonico
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

Il modulo di misurazione a ultrasuoni fornisce una funzione di misurazione senza contatto da 2 cm a 400 cm, con una precisione di misurazione che può arrivare fino a 3 mm.
Può garantire che il segnale sia stabile entro 5 metri e il segnale si indebolisca gradualmente dopo i 5 metri, fino a scomparire alla distanza di 7 metri.

Il modulo include trasmettitori ultrasonici, un ricevitore e un circuito di controllo. I principi di base sono i seguenti:

#. Utilizzare un flip-flop IO per elaborare un segnale ad alto livello di almeno 10us.

#. Il modulo invia automaticamente otto impulsi a 40kHz e rileva se vi è un segnale di ritorno del impulso.

#. Se il segnale ritorna, il passaggio a livello alto, la durata dell'uscita IO alto è il tempo impiegato dall'onda ultrasonica per tornare. La distanza di misurazione = (tempo alto \* velocità del suono (340 m/s) / 2).

Il diagramma temporale è mostrato qui sotto.

.. image:: img/ultrasonic228.png

È sufficiente fornire un impulso breve di 10us all'ingresso di trigger per avviare 
la misurazione, e il modulo invierà una raffica di 8 cicli di ultrasuoni a 40 kHz e 
solleverà il suo eco. Puoi calcolare la distanza attraverso l'intervallo di tempo 
tra l'invio del segnale di trigger e la ricezione del segnale di eco.

Formula: us / 58 = centimetri o us / 148 = pollici; oppure: distanza = 
tempo alto \* velocità (340 m/s) / 2. Si consiglia di utilizzare un ciclo di 
misurazione superiore a 60 ms per prevenire collisioni tra il segnale di trigger e il segnale di eco.

**Esempio**

* :ref:`ar_ultrasonic` (Basic Project)
* :ref:`follow_your_hand` (Car Project)
* :ref:`car_ultrasonic` (Car Project)
* :ref:`sh_parrot` (Scratch Project)
