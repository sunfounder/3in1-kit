.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_tt_motor:

Motore TT
==============

.. image:: img/tt_motor.jpg
    :width: 400
    :align: center

Questo è un motore con riduttore TT DC con un rapporto di riduzione di 1:48. È dotato di 2 fili da 200 mm con connettori maschio da 0,1" che si inseriscono in una breadboard. Perfetto per essere collegato a una breadboard o a un blocco terminale.

Puoi alimentare questi motori con una tensione da 3 a 6V DC, ma naturalmente andranno un po' più veloci a tensioni più alte.

Nota che questi sono motori molto basici, senza encoder integrato, controllo della velocità o feedback di posizione. Inserisci la tensione e il motore gira. Ci sarà una variazione da motore a motore, quindi se hai bisogno di movimenti precisi, avrai bisogno di un sistema di feedback separato.

**Dettagli tecnici**

* Tensione nominale: 3~6V
* Corrente senza carico continua: 150mA +/- 10%
* Velocità minima di funzionamento (3V): 90+/- 10% RPM
* Velocità minima di funzionamento (6V): 200+/- 10% RPM
* Coppia di stallo (3V): 0,4kg.cm
* Coppia di stallo (6V): 0,8kg.cm
* Rapporto di riduzione: 1:48
* Dimensioni del corpo: 70 x 22 x 18mm
* Lunghezza fili: 200mm & 28 AWG
* Peso: 30,6g

**Disegno dimensionale**

.. image:: img/motor_size.jpg

**Esempio**

* :ref:`ar_motor` (Basic Project)
* :ref:`car_move` (Car Project)
* :ref:`car_speed` (Car Project)
* :ref:`iot_car` (IoT Project)
* :ref:`sh_test` (Scratch Project)