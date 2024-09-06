.. note::

    Ciao, benvenuto nella Community SunFounder di appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_breathing_led:

2.2 LED a Respirazione
==========================

Ora utilizzeremo un altro metodo per controllare la luminosità del LED. A differenza del progetto precedente, qui la luminosità del LED diminuirà lentamente fino a scomparire.

Quando lo sprite sul palco viene cliccato, la luminosità del LED aumenterà lentamente per poi spegnersi istantaneamente.

.. image:: img/3_ap.png

Cosa imparerai
-----------------

- Impostare il valore di uscita del pin PWM
- Creare variabili
- Modificare la luminosità dello sprite

Componenti necessari
-----------------------

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
    *   - :ref:`cpn_led`
        - |link_led_buy|

Costruire il circuito
-------------------------

Questo progetto utilizza lo stesso circuito del progetto precedente :ref:`sh_table_lamp`, ma invece di utilizzare HIGH/LOW per accendere o spegnere i LED, questo progetto utilizza il segnale `PWM - Wikipedia <https://en.wikipedia.org/wiki/Pulse-width_modulation>`_ per accendere lentamente o spegnere il LED.

Il range del segnale PWM è 0-255, sulla scheda Arduino Uno i pin 3, 5, 6, 9, 10, 11 possono emettere segnali PWM; sulla Mega2560, i pin 2 - 13 e 44 - 46 possono emettere segnali PWM.

.. image:: img/circuit/led_circuit.png

Programmazione
------------------

**1. Selezionare uno sprite**

Elimina lo sprite predefinito, clicca sul pulsante **Scegli uno Sprite** nell'angolo in basso a destra dell'area degli sprite, inserisci **button3** nella barra di ricerca e quindi clicca per aggiungerlo.

.. image:: img/3_sprite.png

**2. Creare una variabile**

Crea una variabile chiamata **pwm** per memorizzare il valore della variazione del pwm.

Clicca sulla paletta **Variabili** e seleziona **Crea una Variabile**.

.. image:: img/3_ap_va.png

Inserisci il nome della variabile, può essere qualsiasi nome, ma si consiglia di descrivere la sua funzione. Il tipo di dato è numero e vale per tutti gli sprite.

.. image:: img/3_ap_pwm.png

Una volta creata, vedrai **pwm** all'interno della paletta **Variabili** in stato selezionato, il che significa che questa variabile apparirà sul palco. Puoi provare a deselezionarla per vedere se pwm è ancora presente sul palco.

.. image:: img/3_ap_0.png

**3. Impostare lo stato iniziale**

Quando lo sprite **button3** viene cliccato, cambia il costume in **button-b** (stato premuto) e imposta il valore iniziale della variabile **pwm** a 0.

* [imposta pwm a 0]: dalla paletta **Variabili**, usata per impostare il valore della variabile.

.. image:: img/3_ap_brightness.png

**4. Far diventare il LED sempre più luminoso**

Poiché il range del pwm è 255, tramite il blocco [ripeti], la variabile **pwm** viene accumulata fino a 255 di 5 in 5, e poi inserita nel blocco [imposta pin PWM], così puoi vedere il LED accendersi lentamente.

* [cambia pwm di 5]: dalla paletta **Variabili**, permette alla variabile di cambiare un numero specifico ogni volta. Può essere un numero positivo o negativo, positivo per aumentare ogni volta, negativo per diminuire ogni volta. Qui, ad esempio, la variabile pwm aumenta di 5 ogni volta.
* [imposta pin PWM]: dalla paletta **Arduino Uno**, usata per impostare il valore di uscita del pin pwm.

.. image:: img/3_ap_1.png

Infine, cambia il costume di button3 di nuovo in **button-a** e imposta il valore del pin PWM a 0, così il LED si accenderà lentamente e poi si spegnerà di nuovo.

.. image:: img/3_ap_2.png
