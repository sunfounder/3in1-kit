.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Unisciti agli appassionati per approfondire Raspberry Pi, Arduino ed ESP32 insieme a noi.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche grazie all'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti riservati sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_button:

3.1 Lettura del valore del pulsante
==============================================

Nei progetti precedenti, abbiamo utilizzato la funzione di output, in questo capitolo utilizzeremo la funzione di input per leggere il valore del pulsante.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Schema**

.. image:: img/circuit_3.1_button.png

Un lato del pin del pulsante è collegato a 5V, 
mentre l'altro lato è collegato al pin 2, 
quindi quando si preme il pulsante, 
il pin 2 sarà alto. Tuttavia, 
quando il pulsante non è premuto, 
il pin 2 è in uno stato sospeso e può essere alto o basso. 
Per ottenere un livello basso stabile quando il pulsante non è premuto, 
il pin 2 deve essere collegato a GND tramite una resistenza di pull-down da 10K.

**Collegamenti**

.. image:: img/read_the_button_value_bb.jpg
    :width: 600
    :align: center

**Codice**

.. note::

   * Puoi aprire il file ``3.1.read_button_value.ino`` nel percorso ``3in1-kit\basic_project\3.1.read_button_value``. 
   * Oppure copia questo codice nell'**Arduino IDE**.
   
   * Oppure carica il codice tramite `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/b456ff57-4dfb-4231-9d91-f1e9a5777de2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo che il codice è stato caricato con successo, clicca sull'icona della lente di ingrandimento nell'angolo in alto a destra dell'Arduino IDE (Serial Monitor).

.. image:: img/sp220614_152922.png

Quando premi il pulsante, il Serial Monitor stamperà "1".
