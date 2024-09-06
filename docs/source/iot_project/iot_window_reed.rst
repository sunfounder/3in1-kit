
.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni e concorsi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _iot_window:

3. Inviare Dati a Blynk
=============================

Questo capitolo ti mostrerà come inviare dati a Blynk.

Qui creiamo un dispositivo di rilevamento porte e finestre. Il circuito con l'interruttore Reed è posizionato accanto alla porta e alla finestra, mentre il magnete è montato sul bordo della porta e della finestra.
Quando la porta o la finestra è chiusa, l'interruttore Reed verrà attivato dalla forza magnetica e il valore del pin corrispondente sulla scheda R3 cambierà.
Blynk.cloud riceverà questo valore, consentendoti di verificare se le porte e le finestre della tua casa sono chiuse anche quando sei lontano.

Ora utilizzeremo un widget LED in Blynk per indicare se le tue finestre e porte sono chiuse (cioè se l'interruttore Reed è acceso o spento).

**Componenti Necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un intero kit, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome
        - ARTICOLI IN QUESTO KIT
        - LINK
    *   - Starter Kit 3 in 1
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
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_reed`
        - \-

**1. Costruisci il Circuito**

.. note::

    Il modulo ESP8266 richiede un'elevata corrente per garantire un ambiente operativo stabile, quindi assicurati che la batteria da 9V sia collegata.


.. image:: img/wiring_reed.jpg

**2. Modifica la Dashboard**

#. Crea un **Datastream** di tipo **Pin Virtuale** nella pagina **Datastream** per ottenere il valore dell'interruttore Reed. Imposta il TIPO DI DATO su **Intero** e MIN e MAX rispettivamente su **0** e **1**.

    .. image:: img/sp220609_162548.png

#. Trascina un **widget LED** sulla pagina della **Dashboard Web**, a un valore di 1 si accenderà (con colore), altrimenti sarà bianco.

    .. image:: img/blynk_edit_drag_led_widget.png

#. Nella pagina delle impostazioni del **widget LED**, seleziona **Datastream** come **Reed(V1)** e salvalo.

    .. image:: img/sp220609_163502.png

**3. Esegui il Codice**

#. Apri il file ``3.push_data_to_blynk.ino`` nel percorso ``3in1-kit\iot_project\3.push_data_to_blynk``, oppure copia questo codice in **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/e81b0024-c11e-4507-8d43-aeb3b6656c2c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Sostituisci ``Template ID``, ``Nome Dispositivo`` e ``Auth Token`` con i tuoi. Devi anche inserire il ``ssid`` e la ``password`` della rete WiFi che stai utilizzando. Per tutorial dettagliati, fai riferimento a :ref:`connect_blynk`.
#. Dopo aver selezionato la scheda e la porta corrette, fai clic sul pulsante **Upload**.

#. Apri il monitor seriale (imposta la velocità a 115200) e attendi che venga visualizzato un messaggio di connessione avvenuta con successo.

    .. image:: img/2_ready.png

    .. note::

        Se viene visualizzato il messaggio ``ESP non risponde`` quando ti connetti, segui questi passaggi.

        * Assicurati che la batteria da 9V sia collegata.
        * Ripristina il modulo ESP8266 collegando il pin RST a GND per 1 secondo, quindi scollegalo.
        * Premi il pulsante di reset sulla scheda R3.

        A volte potrebbe essere necessario ripetere l'operazione 3-5 volte, sii paziente.

#. Ora, Blynk mostrerà lo stato delle tue porte e finestre. Se le porte e finestre sono chiuse, il widget LED sarà verde, altrimenti sarà grigio.

#. Se desideri utilizzare Blynk sui dispositivi mobili, fai riferimento a :ref:`blynk_mobile`.

**Come funziona?**

In questo esempio, dovresti concentrarti sulle seguenti righe. "Scrivere i dati ogni secondo nel Datastream V1 di Blynk Cloud" è definito da queste righe.

.. code-block:: arduino

    BlynkTimer timer;

    void myTimerEvent()
    {
        Blynk.virtualWrite(V1, pinValue);
    }

    void setup()
    {
        timer.setInterval(1000L, myTimerEvent);
    }

    void loop()
    {
        timer.run(); // Avvia BlynkTimer
    }

La libreria Blynk fornisce un timer integrato, prima creiamo un oggetto timer.

.. code-block:: arduino

    BlynkTimer timer;

Imposta l'intervallo del timer in ``setup()``, qui impostiamo l'esecuzione della funzione ``myTimerEvent()`` ogni 1000ms.

.. code-block:: arduino

    timer.setInterval(1000L, myTimerEvent);

Esegui BlynkTimer in ``loop()``.

.. code-block:: arduino

    timer.run();

Modifica la funzione personalizzata ``myTimerEvent()``, il codice ``Blynk.virtualWrite(V1, pinValue)`` viene utilizzato per scrivere il valore pinValue su V1.

.. code-block:: arduino

    void myTimerEvent()
    {
        Blynk.virtualWrite(V1, pinValue);
    }

