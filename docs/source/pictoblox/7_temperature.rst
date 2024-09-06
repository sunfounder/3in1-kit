.. note::

    Ciao, benvenuto nella Community SunFounder di appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_low_temperature:

2.7 Allarme per Bassa Temperatura
=====================================

In questo progetto, realizzeremo un sistema di allarme per bassa temperatura. Quando la temperatura scende sotto una soglia predefinita, lo sprite **Fiocco di Neve** apparirà sullo stage.

.. image:: img/9_tem.png

Cosa Imparerai
-----------------

- Principio di funzionamento del termistore
- Operazioni con variabili multiple e sottrattive

Componenti Necessari
------------------------

In questo progetto, abbiamo bisogno dei seguenti componenti.

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

Puoi anche acquistarli separatamente dai link seguenti.

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
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

Costruire il Circuito
-------------------------

Un termistore è un tipo di resistore la cui resistenza dipende fortemente dalla temperatura, molto più di quanto accade nei resistori standard. Esistono due tipi di termistori: PTC (la resistenza aumenta con l'aumentare della temperatura) e NTC (la resistenza diminuisce con l'aumentare della temperatura).

Costruisci il circuito seguendo il diagramma sottostante.

Un'estremità del termistore è collegata a GND, l'altra estremità è collegata ad A0, e una resistenza da 10K è collegata in serie a 5V.

In questo caso viene utilizzato un termistore NTC, quindi quando la temperatura aumenta, la resistenza del termistore diminuisce, il partitore di tensione su A0 diminuisce e il valore letto da A0 diminuisce, e viceversa aumenta.

.. image:: img/circuit/thermistor_circuit.png

Programmazione
------------------

**1. Seleziona uno sprite**

Elimina lo sprite predefinito, clicca sul pulsante **Scegli uno Sprite** nell'angolo in basso a destra dell'area degli sprite, inserisci **Fiocco di Neve** nella barra di ricerca e poi clicca per aggiungerlo.

.. image:: img/9_snow.png

**2. Crea 2 variabili**

Crea due variabili, **prima** e **corrente**, per memorizzare il valore di A0 in situazioni diverse.

.. image:: img/9_va.png

**3. Leggi il valore di A0**

Quando viene cliccata la bandierina verde, il valore di A0 viene letto e memorizzato nella variabile **prima**.

.. image:: img/9_before.png

**4. Leggi di nuovo il valore di A0**

All'interno del blocco [forever], leggi di nuovo il valore di A0 e memorizzalo nella variabile **corrente**.

.. image:: img/9_current.png

**5. Determina le variazioni di temperatura**

Utilizzando il blocco [se allora altrimenti], determina se il valore corrente di A0 è superiore di 50 rispetto al valore precedente, il che rappresenta un abbassamento della temperatura. In tal caso, fai apparire lo sprite **Fiocco di Neve**, altrimenti nascondilo.

* [-] & [>]: operatori di sottrazione e confronto dalla palette **Operatori**.

.. image:: img/9_show.png
