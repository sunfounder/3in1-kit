.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_receiver:

Ricevitore IR
===========================

**Ricevitore IR**

.. image:: img/ir_receiver_sl838.png
    :width: 400
    :align: center

* **S**: Uscita segnale
* **-**: GND
* **+**: Alimentazione, 3.3V~5V

Il ricevitore a infrarossi SL838 è un componente che riceve segnali infrarossi e può ricevere indipendentemente i raggi infrarossi ed emettere segnali compatibili con il livello TTL. Ha dimensioni simili a quelle di un normale transistor in plastica ed è adatto per tutti i tipi di telecomandi a infrarossi e trasmissione a infrarossi.

La comunicazione a infrarossi, o IR, è una tecnologia di comunicazione wireless popolare, a basso costo e facile da usare. La luce a infrarossi ha una lunghezza d'onda leggermente superiore alla luce visibile, quindi è impercettibile all'occhio umano, rendendola ideale per la comunicazione wireless. Uno schema di modulazione comune per la comunicazione a infrarossi è la modulazione a 38KHz.

* Può essere utilizzato per il controllo remoto
* Ampia tensione operativa: 2.7~5V
* Filtro interno per la frequenza PCM
* Compatibilità con TTL e CMOS
* Forte capacità anti-interferenza
* Conforme alla RoHS


**Telecomando**

.. image:: img/image186.jpeg
    :width: 400

Questo è un mini telecomando wireless a infrarossi con 21 pulsanti funzionali e una distanza di trasmissione fino a 8 metri, ideale per comandare una vasta gamma di dispositivi in una stanza per bambini.

* Dimensioni: 85x39x6mm
* Portata del telecomando: 8-10m
* Batteria: Batteria al litio manganese da 3V tipo a bottone
* Frequenza portante a infrarossi: 38KHz
* Materiale superficiale: PET da 0.125mm
* Vita utile: oltre 20.000 utilizzi


**Esempio**

* :ref:`ar_receiver` (Basic Project)
* :ref:`car_remote` (Car Project)
* :ref:`car_remote_plus` (Car Project)
