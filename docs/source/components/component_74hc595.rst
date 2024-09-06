.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e concorsi**: Partecipa a concorsi e promozioni speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_74hc595:

74HC595
===========

.. image:: img/74HC595.png

Il 74HC595 consiste in un registro a scorrimento a 8 bit e un registro di memoria con uscite parallele a tre stati. Converte l'ingresso seriale in uscita parallela, permettendo di risparmiare porte IO di un MCU.
Quando MR (pin10) è a livello alto e OE (pin13) è a livello basso, i dati vengono inseriti nel fronte di salita di SHcp e vanno al registro di memoria attraverso il fronte di salita di SHcp. Se i due clock sono collegati insieme, il registro a scorrimento è sempre un impulso avanti rispetto al registro di memoria. C'è un pin di ingresso seriale (Ds), un pin di uscita seriale (Q) e un pulsante di reset asincrono (a livello basso) nel registro di memoria. Il registro di memoria emette un bus parallelo a 8 bit in tre stati. Quando OE è abilitato (a livello basso), i dati nel registro di memoria vengono inviati al bus.

* `74HC595 Datasheet <https://www.ti.com/lit/ds/symlink/cd74hc595.pdf?ts=1617341564801>`_

.. image:: img/74hc595_pin.png
    :width: 600

Pin del 74HC595 e le loro funzioni:

* **Q0-Q7**: Pin di uscita dati paralleli a 8 bit, in grado di controllare direttamente 8 LED o 8 pin di un display a 7 segmenti.
* **Q7'**: Pin di uscita in serie, collegato a DS di un altro 74HC595 per collegare più 74HC595 in serie.
* **MR**: Pin di reset, attivo a livello basso.
* **SHcp**: Ingresso di sequenza temporale del registro a scorrimento. Sul fronte di salita, i dati nel registro a scorrimento si spostano progressivamente di un bit, cioè i dati in Q1 si spostano in Q2, e così via. Sul fronte di discesa, i dati nel registro a scorrimento rimangono invariati.
* **STcp**: Ingresso di sequenza temporale del registro di memoria. Sul fronte di salita, i dati nel registro a scorrimento si spostano nel registro di memoria.
* **CE**: Pin di abilitazione dell'uscita, attivo a livello basso.
* **DS**: Pin di ingresso dati seriali.
* **VCC**: Tensione di alimentazione positiva.
* **GND**: Massa.

**Esempio**

* :ref:`ar_shiftout` (Basic Project)
* :ref:`ar_segment` (Basic Project)
* :ref:`iot_gate` (IoT Project)




