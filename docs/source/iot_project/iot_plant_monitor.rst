.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni e concorsi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _iot_plant:

6. Monitoraggio delle Piante
================================

Lo scopo di questo progetto è creare un sistema intelligente di irrigazione che rileva la temperatura attuale, l'umidità, l'intensità della luce e l'umidità del suolo, visualizzandoli su Blynk.

Non appena accendi l'interruttore a levetta su Blynk Cloud, la pompa inizierà a funzionare e le piante saranno idratate.

**Componenti necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti. 

È sicuramente comodo acquistare un kit completo, ecco il link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - Kit 3 in 1 Starter
        - 380+
        - |link_3IN1_kit|

Puoi anche acquistarli separatamente dai link seguenti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_dht11`
        - \-
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_pump`
        - \-

**1. Costruisci il Circuito**

.. note::

    Il modulo ESP8266 richiede un'elevata corrente per garantire un ambiente di funzionamento stabile, quindi assicurati che la batteria da 9V sia collegata.

.. image:: img/wiring_6_plant_monitor_bb.png
    :width: 800

**2. Modifica il Dashboard**

#. I flussi di dati creati nei progetti precedenti devono essere salvati, in quanto verranno utilizzati anche in questo progetto.

#. Per registrare l'umidità del suolo, crea un altro **Datastream** di tipo **Virtual Pin** nella pagina **Datastream**. Imposta il TIPO DI DATO su ``Integer`` e MIN e MAX su ``0`` e ``1024``.

    .. image:: img/sp220610_155221.png

#. Ora vai alla pagina **Wed Dashboard**, trascina 2 widget **Label** e imposta i loro flussi di dati rispettivamente su **V4** e **V5**; trascina 2 widget **Gauge** e imposta i loro flussi di dati per visualizzare **V6** e **V7** rispettivamente; e infine trascina un widget **Switch** e imposta il suo flusso di dati su **V0**.

    .. image:: img/sp220610_155350.png


**3. Esegui il Codice**

Apri il file ``6.plant_monitoring.ino`` nel percorso ``3in1-kit\iot_project\6.plant_monitoring``, o copia questo codice in **Arduino IDE**.

    .. note::

        * Qui viene utilizzata la libreria ``DHT sensor``, che puoi installare dal **Library Manager**.

            .. image:: ../img/lib_dht11.png

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/f738bcb5-4ee2-475b-b683-759e6b2041b0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Sostituisci il ``Template ID``, ``Device Name``, e ``Auth Token`` con i tuoi. Devi anche inserire il ``ssid`` e la ``password`` del WiFi che stai utilizzando. Per tutorial dettagliati, fai riferimento a :ref:`connect_blynk`.
#. Dopo aver selezionato la scheda e la porta corrette, clicca sul pulsante **Upload**.

#. Apri il Monitor seriale (imposta il baudrate su 115200) e attendi che appaia un messaggio che confermi la connessione avvenuta con successo.

    .. image:: img/2_ready.png

    .. note::

        Se appare il messaggio ``ESP is not responding`` quando ti connetti, segui questi passaggi.

        * Assicurati che la batteria da 9V sia collegata.
        * Resetta il modulo ESP8266 collegando il pin RST a GND per 1 secondo, quindi scollegalo.
        * Premi il pulsante di reset sulla scheda R3.

        A volte potrebbe essere necessario ripetere l'operazione sopra 3-5 volte, sii paziente.

#. Tornando su Blynk, vedrai la temperatura attuale, l'umidità, l'intensità della luce e l'umidità del suolo. Puoi far innaffiare le piante alla pompa, se necessario, cliccando sul widget di controllo del pulsante.

    .. image:: img/sp220610_155350.png

#. Se desideri utilizzare Blynk sui dispositivi mobili, fai riferimento a :ref:`blynk_mobile`.

    .. image:: img/mobile_plant.jpg

**Come funziona?**

Questo ``BLYNK_WRITE`` fa sì che il widget **Switch** di Blynk avvii la pompa quando è acceso e la spenga quando è spento.

.. code-block:: arduino

    BLYNK_WRITE(V0)
    {
        if(param.asInt()==1){
            digitalWrite(pumpA,HIGH);
        }else{
            digitalWrite(pumpA,LOW); 
        }
    }


Queste tre funzioni vengono utilizzate per ottenere la temperatura, l'umidità, l'intensità della luce e l'umidità del suolo attuali.

.. code-block:: arduino

    int readMoisture(){
        return analogRead(moisturePin);
    }

    int readLight(){
        return analogRead(lightPin);
    }

    bool readDHT() {

        // Reading temperature or humidity takes about 250 milliseconds!
        // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
        humidity = dht.readHumidity();
        // Read temperature as Celsius (the default)
        temperature = dht.readTemperature();

        // Check if any reads failed and exit early (to try again).
        if (isnan(humidity) || isnan(temperature)) {
            Serial.println("Failed to read from DHT sensor!");
            return false;
        }
        return true;
    }

Con il ``Timer`` di Blynk, la temperatura, l'umidità, l'intensità della luce e l'umidità del suolo dell'ambiente vengono ottenute ogni secondo e inviate al flusso di dati sul **Blynk Cloud**, da cui i widget visualizzano i dati.

.. code-block:: arduino

    void myTimerEvent()
    {
        bool chk = readDHT();
        int light = readLight();
        int moisture = readMoisture();
        if(chk){
            Blynk.virtualWrite(V4,humidity);
            Blynk.virtualWrite(V5,temperature);
        }
        Blynk.virtualWrite(V6,light);
        Blynk.virtualWrite(V7,moisture);
    }
