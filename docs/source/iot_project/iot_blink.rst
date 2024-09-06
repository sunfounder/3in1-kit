.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a promozioni speciali e giveaway durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _iot_blink:

2. Ottenere dati da Blynk
=================================

In questo capitolo imparerai come controllare il circuito con Blynk. Accendiamo i LED tramite Internet!

**Componenti necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti. 

È sicuramente conveniente acquistare un kit completo, ecco il link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ARTICOLI IN QUESTO KIT
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
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

**1. Costruisci il circuito**

.. note::

    Il modulo ESP8266 richiede una corrente elevata per fornire un ambiente operativo stabile, quindi assicurati che la batteria da 9V sia collegata.

.. image:: img/wiring_led.jpg

**2. Modifica del Dashboard**

#. Vai al dispositivo **Quickstart Device** che hai creato in precedenza, fai clic sull'icona **edit dashboard**.

    .. image:: img/blynk_edit_dashboard.png

#. I Datastream consentono ai widget su Blynk e al codice sulla scheda R3 di riconoscersi reciprocamente.

    .. image:: img/blynk_edit_datastream.png

#. Per completare la configurazione, rimuovi tutti i Datastream dalla pagina dei Datastream.

    .. image:: img/blynk_edit_datastream_delete.png

#. Crea un Datastream di tipo **Virtual Pin**, che verrà utilizzato per controllare il LED con l'interruttore di Blynk.

    .. image:: img/blynk_edit_virtualpin.png

#. Configura il **Virtual Pin**. Poiché il pulsante e il LED devono solo essere accesi e spenti, imposta il TIPO DI DATO su ``Integer`` e MIN e MAX su ``0`` e ``1``.

    .. image:: img/sp220609_115520.png

#. Vai alla pagina **Web Dashboard**.

    .. image:: img/blynk_edit_web_dashboard.png

#. Elimina i widget esistenti.

    .. image:: img/blynk_edit_delete_dashboard.png

#. Trascina e rilascia un widget **switch** dalla **Widget Box** a sinistra.

    .. image:: img/blynk_edit_drag_switch_widget.png

#. Ora configuralo.

    .. image:: img/blynk_edit_edit_widget.png

#. Seleziona **Datastream** come quello che hai configurato in precedenza.

    .. image:: img/sp220609_133741.png

#. Dopo aver selezionato il Datastream, vedrai alcune impostazioni personalizzabili, quindi premi Salva.

    .. image:: img/sp220609_133950.png

#. Infine, clicca su **Save And Apply**.

    .. image:: img/sp220609_141733.png

**3. Esegui il codice**

#. Apri il file ``2.get_data_from_blynk.ino`` nel percorso ``3in1-kit\iot_project\2.get_data_from_blynk``, oppure copia questo codice nell'**Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b187a8-dabf-4866-b38c-742e0446cc3f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Sostituisci il ``Template ID``, ``Device Name`` e ``Auth Token`` con i tuoi. Devi anche inserire il ``ssid`` e la ``password`` del WiFi che stai utilizzando. Per tutorial dettagliati, fai riferimento a :ref:`connect_blynk`.

#. Dopo aver selezionato la scheda e la porta corrette, fai clic sul pulsante **Upload**.

    .. image:: img/2_upload.png

#. Apri il Monitor seriale (imposta il baudrate su 115200) e attendi la comparsa di un messaggio che confermi la connessione avvenuta con successo.

    .. image:: img/2_ready.png

    .. note::

        Se il messaggio ``ESP non risponde`` appare durante la connessione, segui questi passaggi.

        * Assicurati che la batteria da 9V sia collegata.
        * Resetta il modulo ESP8266 collegando il pin RST a GND per 1 secondo, quindi scollegalo.
        * Premi il pulsante di reset sulla scheda R3.

        A volte, potrebbe essere necessario ripetere l'operazione sopra 3-5 volte, abbi pazienza.

#. Tornando su Blynk, potrai vedere che lo stato è cambiato da **offline** a **online** e ora puoi usare il widget switch su Blynk per controllare il LED collegato alla scheda R3.

    .. image:: img/blynk_button_on.png

#. Se vuoi utilizzare Blynk su dispositivi mobili, fai riferimento a :ref:`blynk_mobile`.


**Come funziona?**


La differenza tra il codice in questo progetto e il codice nel capitolo precedente :ref:`connect_blynk` è costituita dalle seguenti righe.

.. code-block:: arduino

    const int ledPin=6;

    BLYNK_WRITE(V0)
    {
        int pinValue = param.asInt(); // assigning incoming value from pin V0 to a variable
        // You can also use:
        // String i = param.asStr();
        // double d = param.asDouble();
        digitalWrite(ledPin,pinValue);
    }

    void setup()
    {
        pinMode(ledPin,OUTPUT);
    }


Riguardo ``pinMode`` e ``digitalWrite`` del ledPin, sono sicuro che tu sia già familiare, quindi non li spiegherò di nuovo. Ciò su cui devi concentrarti è la funzione ``BLYNK_WRITE(V0)``.

Questa funzione viene eseguita quando il valore di ``V0`` su Blynk cambia, e Blynk.Cloud invierà al tuo dispositivo l'informazione "Sto scrivendo sul **Virtual Pin** V0", permettendo al tuo dispositivo di eseguire azioni una volta ricevuta questa informazione.

Abbiamo creato il Datastream V0 nel passaggio precedente e lo abbiamo applicato al widget Switch.
Questo significa che ogni volta che operiamo il widget Switch, la funzione ``BLYNK_WRITE(V0)`` verrà attivata.

Scriviamo due istruzioni in questa funzione.

.. code-block:: arduino

    int pinValue = param.asInt();

Otteniamo il valore di V0 e lo assegniamo alla variabile ``pinValue``.

.. code-block:: arduino

    digitalWrite(ledPin,pinValue);

Scriviamo il valore ottenuto da V0 sul ledPin, in modo che il widget Switch su Blynk possa controllare il LED.
