.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a promozioni festive e concorsi con premi.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _sh_protect_heart:

2.21 GIOCO - Proteggi il tuo Cuore
=======================================

In questo progetto, creeremo un gioco che testa la velocità di reazione.

Sul palco c'è un cuore protetto in una scatola rettangolare, e delle frecce volano verso il cuore da qualsiasi posizione sullo stage. Il colore della freccia cambierà casualmente tra bianco e nero e volerà sempre più veloce.

Se il colore della scatola rettangolare e quello della freccia sono uguali, la freccia verrà bloccata all'esterno e il livello aumenterà di 1; se i colori non corrispondono, la freccia passerà attraverso il cuore e il gioco terminerà.

Qui il colore della scatola rettangolare è controllato dal modulo di tracciamento della linea. Quando il modulo è posizionato su una superficie nera (riflettente), il colore della scatola sarà nero, altrimenti sarà bianco.

Devi quindi decidere se posizionare il modulo di tracciamento su una superficie bianca o nera a seconda del colore della freccia.

.. image:: img/22_heart.png

Componenti Necessari
-------------------------

In questo progetto, abbiamo bisogno dei seguenti componenti. 

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - COMPONENTI NEL KIT
        - LINK
    *   - Kit Starter 3 in 1
        - 380+
        - |link_3IN1_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_track` 
        - |link_track_buy|

Costruire il Circuito
-------------------------

Questo è un modulo di tracciamento della linea digitale. Quando viene rilevata 
una linea nera, il modulo restituisce 1; quando rileva una linea bianca, 
restituisce un valore di 0. Inoltre, puoi regolare la distanza di rilevamento 
tramite il potenziometro sul modulo.

Costruisci ora il circuito secondo lo schema seguente.

.. image:: img/circuit/linetrack_circuit.png

.. note::

    Prima di iniziare il progetto, devi regolare la sensibilità del modulo.

    Collega i fili seguendo lo schema sopra, poi alimenta la scheda R3 (collegando direttamente il cavo USB o il cavo della batteria da 9V), senza caricare il codice.

    Ora attacca un nastro adesivo nero sul piano di lavoro e posiziona il modulo di tracciamento a un'altezza di 2 cm dal tavolo.

    Con il sensore rivolto verso il basso, osserva il LED del modulo per assicurarti che si accenda sul tavolo bianco e si spenga sul nastro nero.

    In caso contrario, devi regolare il potenziometro sul modulo per ottenere l'effetto desiderato.

Programmazione
------------------

Qui dobbiamo creare 3 sprite: **Cuore**, **Scatola Rettangolare** e **Freccia1**.

* **Cuore**: si trova al centro del palco e, se toccato dallo sprite **Freccia1**, il gioco finisce.
* **Scatola Rettangolare**: ha due costumi, uno nero e uno bianco, e cambierà costume in base al valore del modulo di tracciamento della linea.
* **Freccia**: vola verso il centro del palco da qualsiasi posizione, alternandosi tra i colori bianco e nero. Se il suo colore corrisponde a quello della **Scatola Rettangolare**, viene bloccata e vola di nuovo da una posizione casuale; se i colori non corrispondono, passa attraverso il **Cuore** e il gioco termina.

**1. Aggiungere lo sprite Scatola Rettangolare**

Poiché lo sprite Freccia1 e la Scatola Rettangolare hanno entrambi costumi bianchi, per visualizzarli sul palco riempiamo lo sfondo con un colore diverso da nero, bianco e rosso.

* Clicca su **Sfondo1** per andare alla pagina **Sfondo**.
* Seleziona il colore che desideri.
* Usa lo strumento **Rettangolo** per disegnare un rettangolo della stessa dimensione del canvas.

.. image:: img/22_heart0.png

Elimina lo sprite predefinito, usa il pulsante **Scegli uno Sprite** per aggiungere lo sprite **Scatola Rettangolare**, e imposta le sue coordinate x e y su (0, 0).

.. image:: img/22_heart1.png

Vai alla pagina **Costumi** dello sprite **Scatola Rettangolare** e imposta i costumi bianco e nero.

* Clicca sullo strumento di selezione.
* Seleziona il rettangolo sul canvas.
* Seleziona il colore di riempimento nero.
* Nomina il costume **Nero**.

.. image:: img/22_heart2.png

Seleziona il secondo costume, imposta il colore di riempimento su bianco, nominato **Bianco**, ed elimina il resto dei costumi.

.. image:: img/22_heart3.png

**2. Aggiungere lo sprite Cuore**

Aggiungi anche lo sprite **Cuore**, impostando la sua posizione su (0, 0) e ridimensionandolo affinché sembri all'interno della Scatola Rettangolare.

.. image:: img/22_heart5.png

Nella pagina **Costumi**, modifica il costume viola del cuore per farlo sembrare spezzato.

.. image:: img/22_heart6.png

**3. Aggiungere lo sprite Freccia1**

Aggiungi lo sprite **Freccia1**.

.. image:: img/22_heart7.png

Nella pagina **Costumi**, mantieni e duplica il costume della freccia che guarda verso destra e imposta il colore su bianco e nero.

.. image:: img/22_heart8.png

**4. Script per lo sprite Scatola Rettangolare**

Torna alla pagina **Blocchi** e crea lo script per lo sprite **Scatola Rettangolare**.

* Quando il valore del pin digitale 2 (modulo di tracciamento della linea) è 1 (linea nera rilevata), cambia il costume in **Nero**.
* Altrimenti, cambia il costume in **Bianco**.

.. image:: img/22_heart4.png


**5. Script per lo sprite Cuore**

Lo sprite **Cuore** è protetto all'interno della **Scatola Rettangolare** e di default è di colore rosso. Quando lo sprite Freccia1 lo tocca, il gioco finisce.

.. image:: img/22_heart9.png

**6. Script per lo sprite Freccia1**

Fai nascondere lo sprite **Freccia1** e crea un clone quando si clicca sulla bandiera verde.

.. image:: img/22_heart10.png

Crea un blocco [init] per inizializzare la posizione, l'orientamento e il colore dello sprite **Freccia1**.

Lo sprite appare in una posizione casuale e, se la distanza tra esso e il **Cuore** è inferiore a 200, si muove verso l'esterno finché la distanza non supera i 200.

.. image:: img/22_heart11.png

Imposta la direzione in modo che lo sprite **Freccia1** sia rivolto verso il **Cuore**.

.. image:: img/22_heart12.png

Fai alternare casualmente il colore della freccia tra bianco e nero.

* Se la variabile colore è 0, cambia il costume in **Bianco**.
* Se la variabile colore è 1, cambia il costume in **Nero**.

.. image:: img/22_heart14.png

Ora fai muovere lo sprite **Freccia1**, aumentandone la velocità man mano che aumenta il valore della variabile **livello**.

.. image:: img/22_heart13.png

Infine, imposta l'effetto di collisione con lo sprite **Scatola Rettangolare**.

* Se lo sprite **Freccia1** e lo sprite **Scatola Rettangolare** hanno lo stesso colore (che verrà modificato in base al valore del modulo di tracciamento della linea), cioè nero o bianco, verrà creato un nuovo clone e il gioco continuerà.
* Se i loro colori non corrispondono, lo sprite **Freccia1** continuerà a muoversi e il gioco terminerà quando colpirà lo sprite **Cuore**.

.. image:: img/22_heart15.png

.. note::
    I due blocchi [touch color()] devono rilevare i costumi nero/bianco della Scatola Rettangolare separatamente.

    .. image:: img/22_heart16.png
