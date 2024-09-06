.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e concorsi**: Partecipa a concorsi e promozioni speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_buzzer:

Cicalino
===========

.. image:: img/buzzer.png
    :width: 600

Come tipo di cicalino elettronico con una struttura integrata, i cicalini, alimentati da corrente continua (DC), sono ampiamente utilizzati in computer, stampanti, fotocopiatrici, allarmi, giocattoli elettronici, dispositivi elettronici per auto, telefoni, timer e altri prodotti elettronici o dispositivi sonori. 

I cicalini possono essere classificati in attivi e passivi (vedi immagine seguente). Ruota il cicalino con i pin rivolti verso l'alto: quello con una scheda verde è un cicalino passivo, mentre quello avvolto con del nastro nero è un cicalino attivo.

La differenza tra un cicalino attivo e uno passivo:

Un cicalino attivo ha una fonte di oscillazione integrata, quindi emette suoni quando viene alimentato. Un cicalino passivo, invece, non ha una tale fonte, quindi non emetterà suoni con segnali DC; per funzionare ha bisogno di onde quadre con frequenze comprese tra 2K e 5K. Il cicalino attivo è spesso più costoso di quello passivo per via dei molteplici circuiti oscillanti integrati.

Di seguito è riportato il simbolo elettrico di un cicalino. Ha due pin con poli positivi e negativi. Il simbolo + sulla superficie rappresenta l'anodo, mentre l'altro è il catodo. 

.. image:: img/buzzer_symbol.png
    :width: 150

Puoi controllare i pin del cicalino: quello più lungo è l'anodo e quello più corto è il catodo. Assicurati di non confonderli quando lo colleghi, altrimenti il cicalino non emetterà suoni. 

`Cicalino - Wikipedia <https://en.wikipedia.org/wiki/Buzzer>`_

**Esempio**

* :ref:`ar_beep` (Basic Project)
* :ref:`ar_passive_buzzer` (Basic Project)
* :ref:`iot_music` (IoT Project)



