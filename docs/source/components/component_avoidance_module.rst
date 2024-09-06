.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e concorsi**: Partecipa a concorsi e promozioni speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_avoid:

Modulo di Evitamento Ostacoli
===========================================


.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC**: Alimentazione, 3.3 ~ 5V DC.
* **GND**: Massa
* **OUT**: Pin di segnale, solitamente a livello alto, e livello basso quando viene rilevato un ostacolo.


Il modulo di evitamento ostacoli a infrarossi ha una forte adattabilità alla luce ambientale, è dotato di una coppia di tubi di trasmissione e ricezione a infrarossi.

Il tubo trasmittente emette una frequenza a infrarossi; quando la direzione di rilevamento incontra un ostacolo, la radiazione infrarossa viene ricevuta dal tubo ricevente,
dopo l'elaborazione del circuito comparatore, l'indicatore si accende e viene emesso un segnale a livello basso.

La distanza di rilevamento può essere regolata tramite un potenziometro, con un intervallo di distanza efficace compreso tra 2 e 30 cm.

.. image:: img/IR_module.png
    :width: 600
    :align: center

**Esempio**

* :ref:`ar_ir_obstacle` (Basic Project)
* :ref:`car_ir_obstacle` (Car Project)
* :ref:`self_driving` (Car Project)
* :ref:`iot_gate` (IoT Project)
* :ref:`sh_shooting` (Scratch Project)
* :ref:`sh_tap_tile` (Scratch Project)






