.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_reed:

Interruttore Reed
======================

.. image:: img/reed.png

L'interruttore Reed è un interruttore elettrico che funziona grazie a un campo magnetico applicato. Fu inventato da Walter B. Ellwood dei Bell Telephone Laboratories nel 1936 e brevettato negli Stati Uniti il 27 giugno 1940 con il numero di brevetto 2264746.

Il principio di funzionamento di un interruttore Reed è molto semplice. Due lamelle (solitamente fatte di ferro e nichel, due metalli) che si sovrappongono alle estremità sono sigillate in un tubo di vetro, con una piccola distanza (di pochi micron) tra di esse. Il tubo di vetro è riempito con un gas inerte di elevata purezza (come l'azoto), e alcuni interruttori Reed sono progettati per avere il vuoto all'interno, per migliorare le prestazioni in alta tensione.

Le lamelle agiscono come conduttori di flusso magnetico. Le due lamelle non sono a contatto in condizioni di riposo; quando vengono attraversate da un campo magnetico generato da un magnete permanente o da una bobina elettromagnetica, il campo magnetico applicato fa sì che le due lamelle abbiano polarità diverse alle estremità. Quando la forza magnetica supera la forza elastica delle lamelle stesse, le due lamelle vengono attratte l'una verso l'altra, chiudendo il circuito; quando il campo magnetico si indebolisce o scompare, le lamelle, grazie alla loro elasticità, si separano nuovamente aprendo il circuito.

.. image:: img/reed_sche.png

* `Reed Switch - Wikipedia <https://en.wikipedia.org/wiki/Reed_switch>`_

**Esempio**

* :ref:`ar_reed` (Basic Project)
* :ref:`iot_gate` (IoT Project)