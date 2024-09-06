.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_resistor:

Resistore
============

.. image:: img/resistor.png
    :width: 300

Il resistore è un elemento elettronico che può limitare la corrente in un ramo del circuito. 
Un resistore fisso è un tipo di resistore il cui valore di resistenza non può essere modificato, mentre quello di un potenziometro o di un resistore variabile può essere regolato.

Due simboli circuitali generalmente usati per il resistore. Normalmente, la resistenza è indicata su di esso. Quindi, se vedi questi simboli in un circuito, indicano un resistore.

.. image:: img/resistor_symbol.png
    :width: 400

**Ω** è l'unità di resistenza e le unità più grandi includono KΩ, MΩ, ecc. 
Il loro rapporto può essere mostrato come segue: 1 MΩ=1000 KΩ, 1 KΩ = 1000 Ω. Normalmente, il valore della resistenza è indicato su di esso.

Quando si utilizza un resistore, è necessario conoscerne prima la resistenza. Ecco due metodi: puoi osservare le bande sul resistore o utilizzare un multimetro per misurare la resistenza. Si consiglia di utilizzare il primo metodo poiché è più conveniente e veloce.

.. image:: img/resistance_card.jpg

Come mostrato nella tabella, ogni colore rappresenta un numero.

.. list-table::

   * - Nero
     - Marrone
     - Rosso
     - Arancione
     - Giallo
     - Verde
     - Blu
     - Viola
     - Grigio
     - Bianco
     - Oro
     - Argento
   * - 0
     - 1
     - 2
     - 3
     - 4
     - 5
     - 6
     - 7
     - 8
     - 9
     - 0.1
     - 0.01

I resistori a 4 e 5 bande sono comunemente utilizzati, su cui sono presenti rispettivamente 4 e 5 bande cromatiche.

Di solito, quando ricevi un resistore, potresti trovare difficile decidere da quale estremità iniziare a leggere i colori. 
Il trucco è che lo spazio tra la quarta e la quinta banda sarà relativamente più grande.

Pertanto, puoi osservare lo spazio tra le due bande cromatiche a un'estremità del resistore; 
se è più grande rispetto agli altri spazi tra le bande, puoi iniziare a leggere dal lato opposto.

Vediamo come leggere il valore di resistenza di un resistore a 5 bande come mostrato di seguito.

.. image:: img/220ohm.jpg
    :width: 500

Per questo resistore, la resistenza deve essere letta da sinistra a destra. 
Il valore dovrebbe essere in questo formato: 1ª Banda 2ª Banda 3ª Banda x 10^Moltiplicatore (Ω) e l'errore consentito è ±Tolleranza%. 
Quindi il valore di resistenza di questo resistore è 2(rosso) 2(rosso) 0(nero) x 10^0(nero) Ω = 220 Ω, 
e l'errore consentito è ± 1% (marrone).

.. list-table::Common resistor color band
    :header-rows: 1

    * - Resistore 
      - Bande colorate  
    * - 10Ω   
      - marrone nero nero argento marrone
    * - 100Ω   
      - marrone nero nero nero marrone
    * - 220Ω 
      - rosso rosso nero nero marrone
    * - 330Ω 
      - arancione arancione nero nero marrone
    * - 1kΩ 
      - marrone nero nero marrone marrone
    * - 2kΩ 
      - rosso nero nero marrone marrone
    * - 5.1kΩ 
      - verde marrone nero marrone marrone
    * - 10kΩ 
      - marrone nero nero rosso marrone 
    * - 100kΩ 
      - marrone nero nero arancione marrone 
    * - 1MΩ 
      - marrone nero nero verde marrone


Puoi saperne di più sui resistori da Wiki: `Resistore - Wikipedia <https://en.wikipedia.org/wiki/Resistor>`_.

