.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Unisciti agli appassionati per approfondire Raspberry Pi, Arduino ed ESP32 insieme a noi.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e affronta sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti riservati sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_if_else:

5.1 If else
================

Di solito utilizziamo il giudizio condizionale per completare i progetti di interazione più basilari.
Qui, costruiamo un sistema di rilevamento porta con interruttore reed e LED per mostrare questa logica.

Fissa il magnete su un lato della porta e l'interruttore reed (con circuito) sull'altro lato.
Quando la porta è chiusa, il magnete è vicino all'interruttore reed, che lo attiverà.

**Componenti necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente comodo acquistare un intero kit, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - OGGETTI IN QUESTO KIT
        - LINK
    *   - Kit Starter 3 in 1
        - 380+
        - |link_3IN1_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE COMPONENTI
        - LINK DI ACQUISTO

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_reed`
        - \-

**Schema**

.. image:: img/circuit_8.1_ifelse.png

**Collegamenti**

.. image:: img/if_else_bb.jpg
    :width: 600
    :align: center

**Codice**

.. note::

    * Apri il file ``5.1.if_else.ino`` nel percorso ``3in1-kit\basic_project\5.1.if_else``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    
    * Oppure carica il codice tramite `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c7bf6236-1276-45a0-8d34-008d2d838476/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Dopo aver caricato correttamente il codice, se non chiudi la porta, il LED si accenderà, ricordandoti di chiudere la porta.

A proposito, se desideriamo l'effetto opposto (accendere il LED quando la porta è chiusa), basta modificare la condizione nell'``if``.

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    L'``if else`` permette un controllo maggiore sul flusso del codice rispetto alla semplice dichiarazione if, consentendo di raggruppare più test.
