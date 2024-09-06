.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_soil_moisture:

Modulo Sensore di Umidità del Suolo
=======================================

.. image:: img/soil_mositure.png

* GND: Massa
* VCC: Alimentazione, 3.3V~5V
* AOUT: Uscita del valore di umidità del suolo, più il terreno è umido, minore sarà il valore.

Questo sensore capacitivo di umidità del suolo è diverso dalla maggior parte dei sensori resistivi sul mercato, utilizzando il principio dell'induzione capacitiva per rilevare l'umidità del suolo. Evita il problema della corrosione a cui i sensori resistivi sono soggetti, prolungandone notevolmente la durata operativa.

È realizzato con materiali resistenti alla corrosione e ha un'eccellente durata. Inseriscilo nel terreno intorno alle piante e monitora in tempo reale i dati sull'umidità del suolo. Il modulo include un regolatore di tensione integrato che gli consente di operare su un intervallo di tensione di 3.3 ~ 5.5 V. È ideale per microcontrollori a bassa tensione con alimentazioni di 3.3 V e 5 V.

Lo schema hardware del sensore capacitivo di umidità del suolo è mostrato di seguito.

.. image:: img/solid_schematic.png

È presente un oscillatore a frequenza fissa, costruito con un timer IC 555. L'onda quadra generata viene quindi alimentata al sensore come un condensatore. Tuttavia, per il segnale dell'onda quadra, il condensatore ha una certa reattanza o, per semplificare, una resistenza con un puro resistore ohmico (resistenza da 10k sul pin 3) per formare un partitore di tensione.

Maggiore è l'umidità del suolo, maggiore è la capacità del sensore. Di conseguenza, l'onda quadra ha meno reattanza, il che riduce la tensione sulla linea di segnale, e minore sarà il valore dell'ingresso analogico attraverso il microcontrollore.

**Specifiche**

* Tensione di funzionamento: 3.3 ~ 5.5 VDC
* Tensione di uscita: 0 ~ 3.0VDC
* Corrente operativa: 5mA
* Interfaccia: PH2.0-3P
* Dimensioni: 3.86 x 0.905 pollici (L x W)
* Peso: 15g

**Esempio**

* :ref:`ar_moisture` (Basic Project)
* :ref:`iot_plant` (IoT Project)



