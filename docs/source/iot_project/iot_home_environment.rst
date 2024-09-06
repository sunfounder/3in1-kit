.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a promozioni e concorsi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _iot_home:


5. Monitoraggio dell'ambiente domestico
================================================

In questo capitolo utilizzeremo Blynk per creare un monitor per l'ambiente domestico.
Puoi misurare la temperatura, l'umidità e l'intensità della luce di una stanza utilizzando il DHT11 e la fotoresistenza.
Inviando questi valori a Blynk, sarai in grado di conoscere le condizioni ambientali della tua casa tramite internet.

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

**1. Costruisci il Circuito**

.. note::

    Il modulo ESP8266 richiede un'elevata corrente per garantire un ambiente di funzionamento stabile, quindi assicurati che la batteria da 9V sia collegata.

.. image:: img/wiring_dht11.jpg

**2. Modifica il Dashboard**


#. Per registrare i valori di umidità, crea un **Datastream** di tipo **Virtual Pin** nella pagina **Datastream**. Imposta il TIPO DI DATO su **Double** e MIN e MAX su **0** e **100**. Imposta anche le unità su **Percentuale, %**.

    .. image:: img/sp220610_145748.png

#. Successivamente, crea un **Datastream** di tipo **Virtual Pin** per registrare la temperatura. Imposta il TIPO DI DATO su ``Double``, MIN e MAX su ``-30`` e ``50``, e le unità su **Celsius, °C**.

    .. image:: img/sp220610_145811.png

#. Crea anche un **Datastream** di tipo **Virtual Pin** per registrare l'intensità della luce. Utilizza il tipo di dato predefinito - **Integer**, con MIN e MAX impostati su ``0`` e ``1024``.

    .. image:: img/sp220610_145834.png

#. Vai alla pagina **Wed Dashboard**, trascina due widget **Label** e imposta i loro flussi di dati rispettivamente su **V4** e **V5**, e trascina un widget **Gauge** impostando il flusso di dati su **V6**. Nelle impostazioni del widget, puoi anche abilitare **Cambia colore in base al valore** e selezionare i colori appropriati per rendere il widget più intuitivo e gradevole alla vista.

.. image:: img/sp220610_150400.png
    :align: center


**3. Esegui il Codice**

#. Apri il file ``5.home_environment_monitoring.ino`` nel percorso ``3in1-kit\iot_project\5.home_environment_monitoring``, o copia questo codice in **Arduino IDE**.

    .. note::

        * Qui viene utilizzata la libreria ``DHT sensor``, che puoi installare dal **Library Manager**.

            .. image:: ../img/lib_dht11.png

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/4f0ad85e-8aff-4df9-99dd-c6741aed8219/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

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

#. Ora vedrai la temperatura, l'umidità e l'intensità della luce dell'ambiente su Blynk.

    .. image:: img/sp220610_150400.png
        :align: center

#. Se desideri utilizzare Blynk sui dispositivi mobili, fai riferimento a :ref:`blynk_mobile`.

    .. image:: img/mobile_home.jpg

**Come funziona?**

Queste due funzioni vengono utilizzate per ottenere la temperatura, l'umidità e l'intensità della luce della stanza.


.. code-block:: arduino

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


Con il ``Timer`` di Blynk, la temperatura, l'umidità e l'intensità della luce dell'ambiente vengono ottenute ogni secondo e inviate al flusso di dati sul Cloud di Blynk, da cui i widget visualizzano i dati.

.. code-block:: arduino

    void myTimerEvent()
    {
        bool chk = readDHT();
        int light = readLight();
        if(chk){
            Blynk.virtualWrite(V4,humidity);
            Blynk.virtualWrite(V5,temperature);
        }
        Blynk.virtualWrite(V6,light);
    }