.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Unisciti agli appassionati per approfondire Raspberry Pi, Arduino ed ESP32 insieme a noi.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e affronta sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti riservati sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_line_track:

3.4 Rileva la linea
===================================

Il modulo di tracciamento della linea viene utilizzato per rilevare la presenza di aree nere sul terreno, come le linee nere applicate con nastro isolante.

Uno dei suoi LED emette una luce infrarossa appropriata verso il suolo, e la superficie nera ha una capacità relativamente forte di assorbire la luce e una capacità di riflessione più debole. Le superfici bianche, invece, sono l'opposto.
Se rileva luce riflessa, significa che il terreno è attualmente bianco. Se non viene rilevata, significa che è nero.

Questo è il suo funzionamento.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_track`
        - |link_track_buy|

**Schema**

.. image:: img/circuit_3.4_line.png

Il pin digitale 2 viene utilizzato per leggere il
segnale del modulo di tracciamento della linea. Colleghiamo il VCC del modulo a 5V, 
il GND al GND e l'OUT al pin digitale 2.

**Collegamenti**

.. image:: img/detect_the_line_bb.jpg
    :width: 500
    :align: center

**Codice**

.. note::

   * Puoi aprire il file ``3.4.detect_the_line.ino`` nel percorso ``3in1-kit\basic_project\3.4.detect_the_line``. 
   * Oppure copia questo codice nell'**Arduino IDE**.
   
   * Oppure carica il codice tramite `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9795add6-c838-4a66-b484-0c39f252a7b4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Quando il modulo di tracciamento della linea rileva una linea nera, appare [1] sul Monitor Seriale; altrimenti, viene visualizzato [0].

