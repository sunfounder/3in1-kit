.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_segment:


5.10 ShiftOut(Display a Segmenti)
=======================================

In precedenza, abbiamo utilizzato la funzione ``shiftout()`` per accendere otto LED; qui la usiamo per visualizzare i numeri da 0 a 9 sul Display a 7 segmenti.

Il Display a 7 segmenti è essenzialmente un dispositivo composto da 8 LED, di cui 7 LED a forma di striscia formano un "8", e c'è un piccolo LED puntiforme come punto decimale. Questi LED sono etichettati come a, b, c, d, e, f, g e dp. Hanno i propri pin di anodo e condividono i catodi. Le loro posizioni sono mostrate nella figura sottostante.

.. image:: img/segment_cathode.png
    :width: 600
    :align: center

**Componenti necessari**

In questo progetto, ci servono i seguenti componenti. 

È sicuramente conveniente acquistare un kit completo, ecco il link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
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
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Schema**

.. image:: img/circuit_6.5_segment.png

**Collegamenti**

.. list-table:: Wiring
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - Display a Segmenti LED
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

.. image:: img/segment_bb.jpg
    :width: 600
    :align: center

**Codice**


.. note::

    * Apri il file ``5.10.shiftout_segment.ino`` nel percorso ``3in1-kit\basic_project\5.10.shiftout_segment``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    
    * Oppure carica il codice tramite l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/23b9a3ea-c648-4f33-8622-e279d94ee507/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Dopo aver caricato con successo il codice, sarai in grado di vedere il Display a 7 segmenti visualizzare i numeri da 0 a 9 in sequenza.

**Come funziona?**


``shiftOut()`` consente al 74HC595 di emettere 8 segnali digitali.
Emette l'ultimo bit del numero binario a Q0, 
e il primo bit a Q7. In altre parole, 
scrivendo il numero binario "00000001", Q0 emetterà un livello alto e Q1~Q7 emetteranno un livello basso.

Supponiamo che il Display a 7 segmenti visualizzi il numero "2". 
Dobbiamo scrivere un livello alto per a, b, d, e e g, e un livello basso per c, f e dp.
Cioè, è necessario scrivere il numero binario "01011011". 
Per leggibilità, useremo la notazione esadecimale "0x5b".

.. image:: img/7_segment2.png


* `Hexadecimal <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `BinaryHex Converter <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

Allo stesso modo, possiamo far visualizzare altri numeri al Display a 7 segmenti nello stesso modo. 
La tabella seguente mostra i codici corrispondenti a questi numeri.

.. list-table:: Codice dei Glifi
    :widths: 20 20 20
    :header-rows: 1

    *   - Numeri	
        - Codice Binario
        - Codice Esadecimale
    *   - 0	
        - 00111111	
        - 0x3f
    *   - 1	
        - 00000110	
        - 0x06
    *   - 2	
        - 01011011	
        - 0x5b
    *   - 3	
        - 01001111	
        - 0x4f
    *   - 4	
        - 01100110	
        - 0x66
    *   - 5	
        - 01101101	
        - 0x6d
    *   - 6	
        - 01111101	
        - 0x7d
    *   - 7	
        - 00000111	
        - 0x07
    *   - 8	
        - 01111111	
        - 0x7f
    *   - 9	
        - 01101111	
        - 0x6f

Scrivi questi codici in ``shiftOut()`` per far visualizzare i numeri corrispondenti sul Display a 7 segmenti.
