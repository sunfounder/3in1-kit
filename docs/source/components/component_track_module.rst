.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_track:

Modulo di Tracciamento Linee
================================

.. image:: img/line_track.png
    :width: 400
    :align: center

* S: Generalmente basso livello, diventa alto livello quando viene rilevata la linea nera.
* V+: Alimentazione, 3.3V~5V
* G: Terra

Questo è un modulo di tracciamento a 1 canale che, come suggerisce il nome, segue le linee nere su sfondo bianco o le linee bianche su sfondo nero.

.. image:: img/tcrt5000.jpg
    :width: 200
    :align: center

Il modulo utilizza un sensore a infrarossi TCRT500, composto da un LED a infrarossi (blu) e un fototransistor (nero).

* Il LED a infrarossi blu, quando alimentato, emette luce a infrarossi invisibile all'occhio umano.
* Il fototransistor nero, utilizzato per ricevere la luce a infrarossi, ha una resistenza interna che varia in base alla luce a infrarossi ricevuta; maggiore è la luce ricevuta, minore è la sua resistenza e viceversa.

Sul modulo è presente un comparatore LM393, utilizzato per confrontare la tensione del fototransistor con la tensione impostata (regolata dal potenziometro); se è maggiore della tensione impostata, l'uscita è 1, altrimenti l'uscita è 0.

Pertanto, quando il tubo emettitore a infrarossi brilla su una superficie nera, poiché il nero assorbe la luce, il fototransistor riceve meno luce a infrarossi, la sua resistenza aumenta (aumenta la tensione), e dopo il comparatore LM393, l'uscita è di alto livello.

Allo stesso modo, quando brilla su una superficie bianca, la luce riflessa aumenta e la resistenza del fototransistor diminuisce (diminuisce la tensione); pertanto, il comparatore emette un livello basso e il LED indicatore si accende.

* `TCRT5000 <https://www.vishay.com/docs/83760/tcrt5000.pdf>`_

**Caratteristiche**

* Utilizza il sensore a infrarossi TCRT5000
* Distanza di rilevamento: 1-8mm, lunghezza focale di 2.5mm
* Segnale di uscita del comparatore pulito, buon segnale d'onda, capacità di pilotaggio maggiore di 15mA
* Regolazione della sensibilità tramite potenziometro
* Tensione di funzionamento: 3.3V-5V
* Uscita digitale: 0 (bianco) e 1 (nero)
* Utilizza il comparatore LM393 a larga tensione.
* Dimensioni: 42mmx10mm

**Esempio**

* :ref:`ar_line_track` (Basic Project)
* :ref:`follow_the_line` (Car Project)
* :ref:`sh_protect_heart` (Scratch Project)
