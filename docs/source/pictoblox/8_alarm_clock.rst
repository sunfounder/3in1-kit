.. note::

    Ciao, benvenuto nella Community SunFounder di appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotto e anteprime esclusive.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _sh_light_alarm:

2.8 Sveglia a Luce
======================

Nella vita quotidiana ci sono vari tipi di sveglie. Ora realizziamo una sveglia controllata dalla luce. Quando arriva il mattino e la luminosità della luce aumenta, questa sveglia ti ricorderà che è ora di alzarsi.

.. image:: img/10_clock.png

Cosa Imparerai
-----------------

- Principio di funzionamento della fotoresistenza
- Interrompere la riproduzione del suono e fermare l'esecuzione degli script

Componenti Necessari
-------------------------

In questo progetto, avremo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un intero kit, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - COMPONENTI IN QUESTO KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Puoi anche acquistarli separatamente dai link sottostanti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

Costruire il Circuito
-------------------------

Un fotoresistore, o cellula fotoelettrica, è un resistore variabile controllato dalla luce. La resistenza di un fotoresistore diminuisce all'aumentare dell'intensità della luce incidente.

Costruisci il circuito seguendo il diagramma sottostante.

Collega un'estremità del fotoresistore a 5V, l'altra estremità ad A0, e collega una resistenza da 10K in serie con GND a questa estremità.

Così, quando l'intensità della luce aumenta, la resistenza del fotoresistore diminuisce, il partitore di tensione sulla resistenza da 10K aumenta, e il valore ottenuto da A0 diventa più grande.

.. image:: img/circuit/photoresistor_circuit.png

Programmazione
------------------

**1. Seleziona uno sprite**

Elimina lo sprite predefinito, clicca sul pulsante **Scegli uno Sprite** nell'angolo in basso a destra dell'area degli sprite, inserisci **campanello** nella barra di ricerca, e poi clicca per aggiungerlo.

.. image:: img/10_sprite.png

**2. Leggi il valore di A0**

Crea due variabili **prima** e **corrente**. Quando viene cliccata la bandierina verde, leggi il valore di A0 e memorizzalo nella variabile **prima** come valore di riferimento. Nel blocco [forever], leggi di nuovo il valore di A0 e memorizzalo nella variabile **corrente**.

.. image:: img/10_reada0.png

**3. Emetti un suono**

Quando il valore di A0 corrente è maggiore di 50 rispetto al valore precedente, il che rappresenta un aumento dell'intensità della luce sopra la soglia, fai emettere un suono allo sprite.

.. image:: img/10_sound.png

**4. Ruota lo sprite**

Utilizza il blocco [gira] per far ruotare lo sprite **campanello** a sinistra e a destra per ottenere l'effetto sveglia.

.. image:: img/10_turn.png

**5. Ferma tutto**

Interrompi l'allarme dopo che ha suonato per un po'.

.. image:: img/10_stop.png

