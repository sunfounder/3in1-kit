.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e concorsi**: Partecipa a concorsi e promozioni speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _car_remote_plus:

10. Avvio con un solo tocco
==================================

In questo progetto, abbiamo integrato i progetti precedenti - seguire linee, seguire oggetti, evitare ostacoli, guida autonoma, ecc. Queste modalità possono essere cambiate utilizzando i pulsanti del telecomando, permettendoti di avviare la macchina e sperimentare tutte le funzioni contemporaneamente.

**Collegamenti**

.. image:: img/car_10.png
    :width: 800

**Codice**

.. note::

    * Apri il file ``10.one_touch_start.ino`` nel percorso ``3in1-kit\car_project\10.one_touch_start``.
    * Oppure copia questo codice nell'**IDE di Arduino**.
    * Qui viene utilizzata la libreria ``IRremote``, puoi installarla dal **Library Manager**.
  
        .. image:: ../img/lib_irremote.png
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/d873724f-120e-4679-b4ec-8d72ad583c8c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Dopo che il codice è stato caricato con successo, il LED lampeggerà rapidamente 3 volte per ogni segnale ricevuto dal telecomando tramite il ricevitore IR. Puoi premere i seguenti tasti per controllare la macchina.

* **+**: Aumenta la velocità
* **-**: Diminuisci la velocità
* **1**: Spostati in avanti a sinistra
* **2**: Avanti
* **3**: Spostati a destra
* **4**: Gira a sinistra
* **6**: Gira a destra
* **7**: Indietro a sinistra
* **8**: Indietro
* **9**: Indietro a destra
* **CYCLE**: Segui la linea
* **U/SD**: Guida autonoma
* **▷▷|**: Evitamento ostacoli con modulo a ultrasuoni
* **|◁◁**: Evitamento ostacoli con modulo IR
* **EQ**: Segui la mano
* **0**: Ferma
