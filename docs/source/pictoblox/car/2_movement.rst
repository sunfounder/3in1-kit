.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni e concorsi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_move:

3.2 Movimento
==================

Questo progetto si basa su :ref:`sh_test` per far muovere l'auto in tutte le direzioni.

Prima di iniziare la programmazione, rivediamo il principio di funzionamento del modulo L9110.

Ecco la tabella della verità del Motore B:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - Stato del Motore B
    * - 1
      - 0
      - Ruota in senso orario
    * - 0
      - 1
      - Ruota in senso antiorario
    * - 0
      - 0
      - Freno
    * - 1
      - 1
      - Stop

Ecco la tabella della verità del Motore A:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - Stato del Motore A
    * - 1
      - 0
      - Ruota in senso orario
    * - 0
      - 1
      - Ruota in senso antiorario
    * - 0
      - 0
      - Freno
    * - 1
      - 1
      - Stop

Programmazione
-------------------

Ora crea dei blocchi per far muovere l'auto in avanti, indietro, girare a sinistra, a destra e fermarsi rispettivamente.


**1. Avanzare**

Il motore destro ruota in senso orario e il motore sinistro in senso antiorario per far avanzare l'auto.

.. image:: img/2_forward.png

**2. Andare all'indietro**

Per andare indietro, è l'opposto: il motore destro deve ruotare in senso antiorario e il motore sinistro in senso orario.

.. image:: img/2_backward.png

**3. Girare a sinistra**

Entrambi i motori, sinistro e destro, ruotano in senso orario per far girare l'auto a sinistra.

.. image:: img/2_turn_left.png

**4. Girare a destra**

Allo stesso modo, per girare a destra, entrambi i motori ruotano in senso antiorario.

.. image:: img/2_turn_right.png

**5. Fermare**

Ferma l'auto impostando tutti i motori a 0.

.. image:: img/2_stop.png

**6. Far muovere l'auto**

Fai muovere l'auto in avanti, indietro, a sinistra e a destra per 1 secondo, poi fermala. Poiché tutti i blocchi sono posizionati nel blocco [Per sempre], vedrai l'auto ripetere le azioni descritte.

.. image:: img/2_move.png