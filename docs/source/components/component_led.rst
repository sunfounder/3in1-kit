.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_led:

LED
==========

.. image:: img/LED.png
    :width: 400

Il diodo emettitore di luce a semiconduttore è un tipo di componente che può convertire l'energia elettrica in energia luminosa tramite giunzioni PN. In base alla lunghezza d'onda, può essere classificato in diodo laser, diodo emettitore di luce infrarossa e diodo emettitore di luce visibile, comunemente noto come LED (Light-Emitting Diode).

Il diodo ha una conduttività unidirezionale, quindi il flusso di corrente seguirà la direzione della freccia indicata nel simbolo del circuito. Si può applicare solo una tensione positiva sull'anodo e una negativa sul catodo, facendo così accendere il LED.

.. image:: img/led_symbol.png

Un LED ha due pin. Quello più lungo è l'anodo, mentre quello più corto è il catodo. Fai attenzione a non collegarli inversamente. Nel LED c'è una caduta di tensione fissa in direzione diretta, quindi non può essere collegato direttamente al circuito perché la tensione di alimentazione potrebbe superare questa caduta e bruciare il LED. La tensione diretta per i LED rossi, gialli e verdi è di 1,8 V, mentre per quelli bianchi è di 2,6 V. La maggior parte dei LED può sopportare una corrente massima di 20 mA, quindi è necessario collegare una resistenza limitatrice di corrente in serie.

La formula per il calcolo del valore della resistenza è la seguente:

    R = (Vsupply – VD)/I

**R** rappresenta il valore della resistenza limitatrice di corrente, **Vsupply** la tensione di alimentazione, **VD** la caduta di tensione e **I** la corrente di lavoro del LED.

Qui trovi una descrizione dettagliata del LED: `LED - Wikipedia <https://en.wikipedia.org/wiki/Light-emitting_diode>`_.

**Esempio**

* :ref:`ar_blink` (Basic Project)
* :ref:`ar_fading` (Basic Project)
* :ref:`iot_blink` (IoT Project)
* :ref:`sh_breathing_led` (Scratch Project)
* :ref:`sh_table_lamp` (Scratch Project)
