.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e concorsi**: Partecipa a concorsi e promozioni speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_7_segment:

Display a 7 Segmenti
=======================

.. image:: img/7_segment.png
    :width: 200
    :align: center

Un display a 7 segmenti è un componente a forma di 8 che racchiude 7 LED. Ogni LED è chiamato segmento - quando è alimentato, un segmento forma parte di una cifra da visualizzare.

Esistono due tipi di connessione dei pin: Catodo Comune (CC) e Anodo Comune (CA). Come suggerisce il nome, un display CC ha tutti i catodi dei 7 LED collegati, mentre un display CA ha tutti gli anodi dei 7 segmenti collegati.

In questo kit, utilizziamo un display a 7 segmenti con catodo comune, qui trovi il simbolo elettronico.

.. image:: img/segment_cathode.png
    :width: 800

Ciascuno dei LED nel display è associato a un segmento posizionale, con uno dei suoi pin di connessione che sporge dal pacchetto plastico rettangolare. Questi pin dei LED sono etichettati da "a" a "g", rappresentando ciascun LED. Gli altri pin dei LED sono collegati insieme, formando un pin comune. Alimentando i pin appropriati dei segmenti LED in un ordine particolare, alcuni segmenti si illumineranno e altri rimarranno spenti, mostrando così il carattere corrispondente sul display.

**Codici di visualizzazione** 

Per aiutarti a comprendere come i display a 7 segmenti (Catodo Comune) visualizzano i numeri, abbiamo disegnato la seguente tabella. I numeri rappresentano lo 0-F visualizzato sul display a 7 segmenti; (DP) GFEDCBA si riferisce al set di LED corrispondente impostato su 0 o 1. Ad esempio, 00111111 significa che DP e G sono impostati su 0, mentre gli altri sono impostati su 1. Pertanto, lo 0 viene visualizzato sul display a 7 segmenti, mentre il codice HEX corrisponde al numero esadecimale.

.. image:: img/segment_code.png

**Esempio**

* :ref:`ar_segment` (Basic Project)
* :ref:`iot_gate` (IoT Project)

