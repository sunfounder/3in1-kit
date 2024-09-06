.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a promozioni e giveaway durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _iot_music:

4. Cloud Music Player
=====================================

L'obiettivo di questo progetto è creare un lettore musicale utilizzando Blynk.
La musica viene riprodotta allo stesso modo del progetto :ref:`ar_passive_buzzer`, scrivendo la canzone nel programma e riproducendola tramite un buzzer passivo.
Tuttavia, in questo esempio possiamo cliccare su un interruttore per riprodurre/pausare e far scorrere un cursore per modificare l'avanzamento della riproduzione.

**Componenti necessari**

In questo progetto, avremo bisogno dei seguenti componenti.

È decisamente comodo acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - OGGETTI NEL KIT
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
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|

**1. Costruisci il circuito**

.. note::

    Il modulo ESP8266 richiede un'elevata corrente per garantire un ambiente di funzionamento stabile, quindi assicurati che la batteria da 9V sia collegata.

.. image:: img/wiring_buzzer.jpg

**2. Modifica il Dashboard**

#. Crea un **Datastream** di tipo **Virtual Pin** sulla pagina **Datastream** come il valore modificato dal widget Slider aggiunto successivamente o dal codice. Imposta il DATA TYPE su **Integer** e MIN e MAX su **0** e **30**.

    .. image:: img/sp220610_104330.png

#. Crea anche un altro **Datastream** di tipo **Virtual Pin** per visualizzare il nome della canzone, e imposta il DATA TYPE su ``String``.

    .. image:: img/sp220610_105932.png

#. Vai alla pagina **Wed Dashboard**, trascina un widget **Switch** e imposta **Datastream** su V0 (V0 è già impostato in :ref:`iot_blink`); trascina un widget **Label** e impostalo su V3; trascina un widget **Slider** e impostalo su V2.

    .. image:: img/blynk_music_cloud.png

.. note::

    I tuoi Virtual Pin potrebbero essere diversi dai miei, dovrai quindi modificarli nel codice in base ai tuoi.



**3. Esegui il codice**

#. Apri il file ``4.cloud_music_player.ino`` nel percorso ``3in1-kit\iot_project\4.cloud_music_player``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/34a49c4b-9eb4-4d03-bd78-fe1daefc9f5c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Sostituisci il ``Template ID``, ``Device Name``, e ``Auth Token`` con i tuoi. Devi anche inserire il ``ssid`` e la ``password`` del WiFi che stai utilizzando. Per tutorial dettagliati, fai riferimento a :ref:`connect_blynk`.
#. Dopo aver selezionato la scheda e la porta corrette, clicca sul pulsante **Upload**.

#. Apri il Monitor seriale (imposta il baudrate su 115200) e attendi che appaia un messaggio che confermi la connessione avvenuta con successo.

    .. image:: img/2_ready.png

    .. note::

        Se appare il messaggio ``ESP is not responding`` quando ti connetti, segui questi passaggi.

        * Assicurati che la batteria da 9V sia collegata.
        * Resetta il modulo ESP8266 collegando il pin RST a GND per 1 secondo, quindi scollegalo.
        * Premi il pulsante di reset sulla scheda R3.

        A volte, potrebbe essere necessario ripetere l'operazione sopra 3-5 volte, abbi pazienza.

#. Ora puoi usare il widget Switch di Blynk per avviare/pausare la musica e lo Slider per regolare l'avanzamento della riproduzione. Vedrai anche il nome della musica.

    .. image:: img/blynk_music_cloud.png

#. Se desideri usare Blynk sui dispositivi mobili, fai riferimento a :ref:`blynk_mobile`.


**Come funziona?**

Il datastream **V0** viene utilizzato per ottenere lo stato del widget Switch e assegnarlo alla variabile **musicPlayFlag**, che controlla la pausa e la riproduzione della musica.

.. code-block:: arduino

    int musicPlayFlag=0;

    BLYNK_WRITE(V0)
    {
        musicPlayFlag = param.asInt(); // AVVIO/PAUSA MUSICA
    }

Il datastream **V2** viene utilizzato per ottenere il valore del widget Slider e assegnarlo alla variabile **scrubBar** quando il cursore viene mosso.

.. code-block:: arduino

    int scrubBar=0;

    BLYNK_WRITE(V2)
    {
        scrubBar=param.asInt();
    }

Quando il dispositivo è connesso al **Blynk Cloud**, viene scritto il nome della canzone per il datastream **V3** e poi visualizzato tramite il widget **Label**.

.. code-block:: arduino

    BLYNK_CONNECTED() {
        String songName = "Ode to Joy";
        Blynk.virtualWrite(V3, songName);
    }

Il **Blynk Timer** si esegue ogni secondo. La musica viene riprodotta se **musicPlayFlag** è diverso da 0, ovvero se il widget **Switch** è acceso.
Appena vengono riprodotte due note, la variabile della barra di avanzamento ``scrubBar`` viene incrementata di 2, e il valore viene scritto sul **Blynk Cloud**, che sincronizza il valore del widget **Slider**.

.. code-block:: arduino

    void myTimerEvent()
    {
        if(musicPlayFlag!=0)
        {
            tone(buzzerPin,melody[scrubBar],250);
            scrubBar=(scrubBar+1)%(sizeof(melody)/sizeof(int));
            delay(500);
            tone(buzzerPin,melody[scrubBar],250);
            scrubBar=(scrubBar+1)%(sizeof(melody)/sizeof(int));
            Serial.println(scrubBar);    
            Blynk.virtualWrite(V2, scrubBar);
        }
    }