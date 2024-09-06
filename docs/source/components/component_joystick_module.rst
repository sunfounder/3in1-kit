.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_joystick:

Modulo Joystick
=======================

.. image:: img/joystick_pic.png
    :align: center
    :width: 600

Il concetto base di un joystick è quello di tradurre il movimento della leva in informazioni elettroniche che un computer può elaborare.

Per comunicare all'intero spettro di movimento, il joystick deve misurare la posizione della leva su due assi: l'asse X (sinistra-destra) e l'asse Y (su-giù). Proprio come nella geometria di base, le coordinate X-Y identificano esattamente la posizione della leva.

Per determinare la posizione della leva, il sistema di controllo del joystick monitora semplicemente la posizione di ciascun asse. Il design convenzionale del joystick analogico lo fa utilizzando due potenziometri, o resistori variabili.

Il joystick ha anche un ingresso digitale che si attiva quando la leva viene premuta verso il basso.

.. image:: img/joystick318.png
    :align: center
    :width: 600
	
**Esempio**

* :ref:`ar_joystick` (Basic Project)
* :ref:`sh_star_crossed` (Scratch Project)
* :ref:`sh_dragon` (Scratch Project)