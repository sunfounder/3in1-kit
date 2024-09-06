.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_servo:

5.5 Utilizzare la Libreria Interna
=======================================

Nell'IDE di Arduino, puoi utilizzare molte librerie integrate aggiungendo direttamente il file corrispondente ``.h`` al tuo codice.

Questo progetto utilizza la libreria ``Servo`` per guidare il servo e farlo ruotare tra 0° e 180°.

**Componenti necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|


**Schema**


.. image:: img/circuit_6.2_servo.png

In questo progetto, utilizziamo il pin PWM 9 per controllare il servo. 
Colleghiamo il filo arancione del servo al pin PWM 9, quello rosso a 5V 
e quello marrone a GND.

**Collegamenti**

.. image:: img/swinging_servo_bb.jpg

**Codice**

.. note::

    * Apri il file ``5.5.use_internal_library.ino`` nel percorso ``3in1-kit\basic_project\5.5.use_internal_library``.
    * Oppure copia questo codice nell'**Arduino IDE**.
    
    * Oppure carica il codice tramite il `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fa27db71-b191-4eda-b5c7-bbbe5f2652ca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Una volta completato il caricamento del codice sulla scheda R3, vedrai il braccio del servo ruotare nell'intervallo 0°~180°.

**Come funziona?**

Chiamando la libreria ``Servo.h``, puoi controllare facilmente il servo.

.. code-block:: arduino

    #include <Servo.h> 

Funzioni della Libreria: 

.. code-block:: arduino

    Servo

Crea l'oggetto **Servo** per controllare un servo.

.. code-block:: arduino

    uint8_t attach(int pin); 

Chiama ``pinMode()`` per impostare un pin come driver per il servo e restituisce 0 in caso di fallimento.

.. code-block:: arduino

    void detach();

Rilascia un pin dal controllo del servo.

.. code-block:: arduino

    void write(int value); 

Imposta l'angolo del servo in gradi, da 0 a 180.

.. code-block:: arduino

    int read();

Restituisce il valore impostato con l'ultimo ``write()``.

.. code-block:: arduino

    bool attached(); 

Restituisce 1 se il servo è attualmente collegato.
