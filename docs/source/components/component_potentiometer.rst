.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_potentiometer:

Potenziometro
=================

.. image:: img/potentiometer.png
    :align: center
    :width: 150

Il potenziometro è un componente resistivo con 3 terminali, il cui valore di resistenza può essere regolato secondo una variazione prestabilita.

I potenziometri si presentano in varie forme, dimensioni e valori, ma hanno in comune le seguenti caratteristiche:

* Hanno tre terminali (o punti di connessione).
* Sono dotati di una manopola, una vite o un cursore che può essere spostato per variare la resistenza tra il terminale centrale e uno dei terminali esterni.
* La resistenza tra il terminale centrale e uno dei terminali esterni varia da 0 Ω alla resistenza massima del potenziometro quando la manopola, la vite o il cursore vengono spostati.

Ecco il simbolo circuitale del potenziometro.

.. image:: img/potentiometer_symbol.png
    :align: center
    :width: 400

Le funzioni del potenziometro nel circuito sono le seguenti:

#. Funzione di divisore di tensione

    Il potenziometro è una resistenza regolabile in modo continuo. Quando si regola l'albero o la maniglia scorrevole del potenziometro, il contatto mobile scorre sulla resistenza. A questo punto, è possibile ottenere una tensione in uscita che dipende dalla tensione applicata sul potenziometro e dall'angolo o dalla corsa del braccio mobile.

#. Funzione di reostato

    Quando il potenziometro viene utilizzato come reostato, si collega il pin centrale e uno degli altri 2 pin nel circuito. In questo modo, è possibile ottenere un valore di resistenza che varia in modo uniforme e continuo all'interno del percorso del contatto mobile.

#. Funzione di controllo della corrente

    Quando il potenziometro funziona come controllore di corrente, il terminale del contatto scorrevole deve essere collegato come uno dei terminali di uscita.

Se desideri saperne di più sul potenziometro, fai riferimento a: `Potentiometro - Wikipedia <https://en.wikipedia.org/wiki/Potentiometer>`_

**Esempio**

* :ref:`ar_potentiometer` (Basic Project)
* :ref:`sh_moving_mouse` (Scratch Project)
* :ref:`sh_breakout_clone` (Scratch Project)


