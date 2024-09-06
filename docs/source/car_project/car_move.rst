.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e concorsi**: Partecipa a concorsi e promozioni speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _car_move:

1. Movimento
=================

.. image:: ../components/img/l9110_module.jpg
    :width: 500
    :align: center

Prima di iniziare a programmare, rivediamo il principio di funzionamento del modulo L9110.

Ecco la tabella della verità per il Motore B:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - Stato del Motore B
    * - 1
      - 0
      - Rotazione in senso orario
    * - 0
      - 1
      - Rotazione in senso antiorario
    * - 0
      - 0
      - Freno
    * - 1
      - 1
      - Stop

Ecco la tabella della verità per il Motore A:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - Stato del Motore A
    * - 1
      - 0
      - Rotazione in senso orario
    * - 0
      - 1
      - Rotazione in senso antiorario
    * - 0
      - 0
      - Freno
    * - 1
      - 1
      - Stop


* :ref:`cpn_l9110`

**Avanti**

Ora colleghiamo l'ingresso del modulo L9110 rispettivamente a 12V e GND per far muovere l'auto.

.. raw:: html
    
  <iframe width="600" height="400" src="https://www.youtube.com/embed/ulD40OtsL7c?si=hJ9nyf8ePAWNp0-8" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

1. Collega la scheda R3, il modulo L9110 e 2 motori.


.. image:: img/car_1.png
    :width: 800

2. Collega B-1B(B-2A) e A-1A a VCC, e B-1A e A-1B a GND, quindi vedrai l'auto muoversi in avanti.


.. image:: img/1.move_4.png 
    :align: center

Se i motori non si muovono entrambi in avanti ma si verificano le seguenti situazioni, 
è necessario regolare nuovamente il cablaggio dei due motori.

* Se entrambi i motori girano all'indietro contemporaneamente (il motore sinistro gira in senso orario, il motore destro in senso antiorario), scambia il cablaggio dei motori sinistro e destro contemporaneamente, OA(A) e OB(A) si scambiano, OA(B) e OB(B) si scambiano.
* Se il motore sinistro gira all'indietro (rotazione oraria), scambia il cablaggio di OA(B) e OB(B) del motore sinistro.
* Se il motore destro gira all'indietro (rotazione antioraria), scambia il cablaggio di OA(A) e OB(A) del motore destro.


**Indietro**

Collega B-1B(B-2A) e A-1A a GND, e B-1A e A-1B a VCC, quindi vedrai l'auto muoversi all'indietro.


.. image:: img/1.move_back.png 
    :width: 800



**Gira a sinistra**

Se vuoi far girare l'auto a sinistra, cioè far girare entrambi i motori in senso orario, 
devi collegare B-1A e A-1A a GND, e B-1B(B-2A) e A-1B a VCC.


.. image:: img/1.move_left.png 
    :width: 800


**Gira a destra**

Al contrario, se vuoi girare l'auto a destra, cioè far girare entrambi i motori in senso antiorario, 
devi collegare B-1A e A-1A a VCC e B-1B(B-2A) e A-1B a GND.


.. image:: img/1.move_right.png 
    :width: 800



**Stop**

Per fermare il motore, collega gli ingressi dello stesso lato contemporaneamente a 12V o GND, ad esempio collega B-1A e B-1B(B-2A) contemporaneamente a 12V o 5V, e lo stesso per A-1A e A-1B.



Questo ovviamente è teorico e sarà necessario più avanti per il controllo tramite codice. Qui rimuovi l'alimentazione dell'auto per fermarla.
