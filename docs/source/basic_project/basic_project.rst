.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_projects:

Progetti di base
========================

Questo capitolo serve per imparare a controllare i circuiti elettronici utilizzando Arduino.

A seconda dei componenti, i metodi di controllo di base di Arduino possono essere suddivisi in quattro categorie:

* :ref:`ar_digital_write`: Imposta l'uscita della tensione del pin su alta o bassa, che può essere utilizzata per accendere o spegnere la luce.
* :ref:`ar_analog_write`: Scrivi un valore analogico (`PWM wave <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_) sul pin, utile per regolare la luminosità della luce.
* :ref:`ar_digital_read`: Leggi il segnale di livello del pin digitale, utile per verificare lo stato di funzionamento di un interruttore.
* :ref:`ar_analog_read`: Leggi la tensione del pin analogico, utile per leggere lo stato di funzionamento di un potenziometro.

Ci sono anche alcuni componenti che richiedono librerie aggiuntive per l'uso, e questi sono raggruppati nella sezione :ref:`install_libraries_ar`.

Infine, il kit offre anche alcuni :ref:`ar_funny_project`, che includono molti esempi semplici e utili.
Prova questa sezione di codice e capirai come funzionano la maggior parte dei progetti semplici.


.. toctree::
    :maxdepth: 2

    ard_digital_write
    ard_analog_write
    ard_digital_read
    ard_analog_read
    ard_more_syntax
    ard_funny_project


