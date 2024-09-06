.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a promozioni e giveaway durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _iot_car:

8. Auto IoT
====================

Abbiamo utilizzato l'APP Blynk sul cellulare per controllare l'auto in questo progetto. Ma è necessario fare riferimento a :ref:`car_projects` per assemblare l'auto e avere una comprensione di base del suo funzionamento.
Nell'era della diffusione della rete 5G, questa modalità potrebbe diventare uno dei principali metodi di produzione in molte industrie, quindi sperimentiamo questo approccio in anticipo.

**1. Costruisci il circuito**

.. image:: img/wiring_iot_car.png
    :width: 800


**2. Modifica del Dashboard**

Blynk su cellulare non può modificare i Datastream, quindi dobbiamo eseguire questi passaggi sul lato web.

#. Crea un **Datastream** di tipo **Virtual Pin** sulla pagina **Datastream**, per registrare il valore dell'asse X del joystick. Imposta NAME su ``Xvalue``, DATA TYPE su ``Integer``, e MIN e MAX su ``-10`` e ``10``.

    .. image:: img/sp220613_164507.png

#. Crea un **Datastream** di tipo **Virtual Pin** per registrare il valore dell'asse Y del joystick. Imposta NAME su ``Yvalue``, DATA TYPE su ``Integer``, MIN e MAX su ``-10`` e ``10``.

    .. image:: img/sp220613_164717.png

Successivamente, è necessario fare quanto segue sul telefono.

1. Cerca "Blynk IoT" (non Blynk(legacy)) in GOOGLE Play o APP Store per scaricarlo.
2. Dopo aver aperto l'APP, effettua l'accesso, utilizzando lo stesso account del client web.
3. Vai su Dashboard (se non ne hai uno, creane uno) e vedrai che i Dashboard per cellulare e web sono indipendenti tra loro.

.. image:: img/APP_1.jpg

4. Clicca sull'icona Modifica.
5. Clicca sull'area vuota.
6. Seleziona un widget Joystick.

.. image:: img/APP_2.jpg

7. Ora vedrai un widget Joystick apparire nell'area vuota, cliccaci sopra.
8. Nelle Impostazioni del Joystick, seleziona i valori ``Xvalue`` e ``Yvalue`` che hai appena impostato nei datastream.
9. Torna alla pagina Dashboard e potrai utilizzare il Joystick quando desideri.

.. image:: img/APP_3.jpg


**3. Esegui il codice**

#. Apri il file ``8.iot_car.ino`` nel percorso ``3in1-kit\iot_project\8.iot_car``, oppure copia questo codice nell'**Arduino IDE**.

    .. raw:: html 
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/a1db6c35-2f26-425c-8636-53d2df7936d7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Sostituisci il ``Template ID``, ``Device Name``, e ``Auth Token`` con i tuoi. Devi anche inserire il ``ssid`` e la ``password`` del WiFi che stai utilizzando. Per tutorial dettagliati, fai riferimento a :ref:`connect_blynk`.
#. Dopo aver selezionato la scheda e la porta corrette, clicca sul pulsante **Upload**.

#. Apri il Monitor seriale (imposta il baudrate su 115200) e attendi un messaggio che confermi la connessione avvenuta con successo.

    .. image:: img/2_ready.png

    .. note::

        Se appare il messaggio ``ESP non risponde`` quando ti connetti, segui questi passaggi.

        * Assicurati che la batteria da 9V sia collegata.
        * Resetta il modulo ESP8266 collegando il pin RST a GND per 1 secondo, quindi scollegalo.
        * Premi il pulsante di reset sulla scheda R3.

        A volte, potrebbe essere necessario ripetere l'operazione sopra 3-5 volte, abbi pazienza.

#. Ora scollega il cavo USB e alimenta il carrello solo con una batteria da 9V, quindi attendi che il LED si accenda, il che significa che l'auto è connessa a Blynk.
#. Apri Blynk sul telefono e puoi usare il widget Joystick per controllare il movimento dell'auto.

    .. image:: img/iot_car.jpg



**Come funziona?**

Queste funzioni vengono utilizzate per controllare il movimento dell'auto.

.. code-block:: arduino

    void moveForward(int speed) {...}
    void moveBackward(int speed) {...}
    void turnRight(int speed) {...}
    void turnLeft(int speed) {...}
    void stopMove() {...}

La sezione IoT legge i valori del widget Joystick e li assegna alle variabili ``Xvalue`` e ``Yvalue``.

.. code-block:: arduino

    int Xvalue = 0;
    int Yvalue = 0;

    BLYNK_WRITE(V9)
    {
        Xvalue = param.asInt();
    }

    BLYNK_WRITE(V10)
    {
        Yvalue = param.asInt();
    }

Nel ``loop()``, l'auto esegue azioni diverse in base ai valori di ``Xvalue`` e ``Yvalue``.

.. code-block:: arduino

    if (Yvalue >= 5) {
        moveForward(255);
    } else if (Yvalue <= -5) {
        moveBackward(255);
    } else if (Xvalue >= 5) {
        turnRight(150);
    } else if (Xvalue <= -5) {
        turnLeft(150);
    } else {
        stopMove();
    }

Inoltre, aggiungi una determinazione dello stato della rete nel ``loop()`` per accendere un LED se è connesso a Blynk Cloud.

.. code-block:: arduino

    if (!Blynk.connected()) {
        digitalWrite(ledPin, LOW);
        Serial.print("offline!");
        bool result = Blynk.connect();
        Serial.println(result);
    } else {
        digitalWrite(ledPin, HIGH);
    }