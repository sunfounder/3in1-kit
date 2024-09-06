.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti esclusivi**: Goditi sconti esclusivi sui nostri nuovi prodotti.
    - **Promozioni festive e giveaway**: Partecipa a promozioni e concorsi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _iot_gate:

7. Cancello con limitazione corrente
========================================

Alcune situazioni, come nei parcheggi, richiedono una gestione quantitativa.

Qui creiamo un cancello intelligente: un servomotore funge da cancello, e un rilevatore di ostacoli a infrarossi è posizionato di fronte; se viene rilevato un oggetto (come un'auto), il cancello si aprirà e il numero sarà incrementato di 1.
Il conteggio viene visualizzato su un display a 7 segmenti e viene anche caricato sul Cloud di Blynk per essere visualizzato da remoto. Infine, Blynk ha un widget Switch per abilitare o disabilitare questo sistema di cancello intelligente.

**Componenti necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È decisamente comodo acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - COMPONENTI NEL KIT
        - LINK
    *   - Kit 3 in 1 Starter
        - 380+
        - |link_3IN1_kit|

Puoi anche acquistarli separatamente dai link seguenti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE COMPONENTI
        - LINK DI ACQUISTO

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|


**1. Costruisci il circuito**

.. note::

    Il modulo ESP8266 richiede un'elevata corrente per garantire un ambiente di funzionamento stabile, quindi assicurati che la batteria da 9V sia collegata.


.. image:: img/wiring_servo_segment.jpg
    :width: 800


**2. Modifica il Dashboard**

#. Per registrare il numero, crea un **Datastream** di tipo **Virtual Pin** sulla pagina **Datastream**. Imposta il DATA TYPE su ``Integer`` e MIN e MAX su ``0`` e ``10``.

    .. image:: img/sp220610_165328.png

#. Ora vai alla pagina **Wed Dashboard**, trascina un widget **Switch** per impostare il suo datastream su **V0** e un widget **Label** per impostare il suo datastream su **V8**.

    .. image:: img/sp220610_165548.png


**3. Esegui il codice**

#. Apri il file ``7.current_limiting_gate.ino`` nel percorso ``3in1-kit\iot_project\7.current_limiting_gate``, o copia questo codice in **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/bd829175-652f-4c3e-85b0-048c3fda4555/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Sostituisci il ``Template ID``, ``Device Name``, e ``Auth Token`` con i tuoi. Devi anche inserire il ``ssid`` e la ``password`` del WiFi che stai utilizzando. Per tutorial dettagliati, fai riferimento a :ref:`connect_blynk`.
#. Dopo aver selezionato la scheda e la porta corrette, clicca sul pulsante **Upload**.

#. Apri il Monitor seriale (imposta il baudrate su 115200) e attendi che appaia un messaggio che confermi la connessione avvenuta con successo.

    .. image:: img/2_ready.png

    .. note::

        Se appare il messaggio ``ESP non risponde`` quando ti connetti, segui questi passaggi.

        * Assicurati che la batteria da 9V sia collegata.
        * Resetta il modulo ESP8266 collegando il pin RST a GND per 1 secondo, quindi scollegalo.
        * Premi il pulsante di reset sulla scheda R3.

        A volte potrebbe essere necessario ripetere l'operazione sopra 3-5 volte, sii paziente.

#. Ora clicca sul widget di controllo Button su Blynk per abilitare il sistema di cancello intelligente. Se il modulo di rilevamento ostacoli a infrarossi rileva un ostacolo, il cancello si aprirà e il display a 7 segmenti e il widget Count su Blynk aggiungeranno 1.

    .. image:: img/sp220610_165548.png

#. Se desideri utilizzare Blynk sui dispositivi mobili, fai riferimento a :ref:`blynk_mobile`.

    .. image:: img/mobile_gate.jpg

**Come funziona?**

La funzione ``BLYNK_WRITE(V0)`` ottiene lo stato del widget **Switch** e lo assegna alla variabile ``doorFlag``, che verrà utilizzata per determinare se il sistema di cancello intelligente è abilitato o meno.

.. code-block:: arduino

    BLYNK_WRITE(V0)
    {
        doorFlag = param.asInt(); // Abilita Cancello
    }

Nel Blynk Timer, ``doorFlag`` viene valutato ogni secondo e, se è abilitato, viene eseguita la funzione principale del cancello.

.. code-block:: arduino

    void myTimerEvent()
    {
        if (doorFlag)
        {
            channelEntrance();
        }
    }

La funzione principale del cancello è ``channelEntrance()``.
Quando un oggetto si avvicina al cancello (il sensore rileva un ostacolo), il ``count`` viene incrementato di 1.
Il valore di ``count`` viene inviato al datastream ``V8`` del Blynk Cloud e al display a 7 segmenti sul circuito, e il cancello si apre.
Se l'oggetto passa da presente a assente, il che significa che l'oggetto è entrato, il cancello si chiude.

.. code-block:: arduino

    void channelEntrance()
    {
        int currentState = digitalRead(irPin); // 0:obstacle 1:no-obstacle
        if (currentState == 0 && lastState == 1) {
            count=(count+1)%10;
            Blynk.virtualWrite(V8, count);
            showNumber(count);
            operateGate(true);
        } else if ((currentState == 1 && lastState == 0)) {
            operateGate(false);
        }
        lastState = currentState;
    }

La funzione ``showNumber(int num)`` viene utilizzata per mostrare il valore sul display a 7 segmenti.

.. code-block:: arduino

    void showNumber(int num)
    {
        digitalWrite(STcp, LOW); //ground ST_CP and hold low for as long as you are transmitting
        shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
        digitalWrite(STcp, HIGH); //pull the ST_CPST_CP to save the data
    }

La funzione ``operateGate(bool openGate)`` apre lentamente il cancello quando il riferimento è ``True``, e lo chiude lentamente quando il riferimento è ``False``.

.. code-block:: arduino

    void operateGate(bool openGate) {
        if (openGate == true) 
        {
            // open gate
            while (angle <= 90) { 
            angle++;
            myservo.write(angle);
            delay(5);
            }
        } else {
            // close gate
            while (angle >= 0){ 
            angle--;
            myservo.write(angle);
            delay(5);
            }
        }
    }