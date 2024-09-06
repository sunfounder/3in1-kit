.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a promozioni speciali e giveaway durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _connect_blynk:

1.3 Collegare la scheda R3 a Blynk
=======================================

#. Ricollega il modulo ESP8266 e la scheda R3, qui viene utilizzata la seriale software, quindi TX e RX sono collegati rispettivamente ai pin 2 e 3 della scheda R3.

    .. note::

        Il modulo ESP8266 richiede un'elevata corrente per fornire un ambiente operativo stabile, quindi assicurati che la batteria da 9V sia collegata.

    .. image:: img/wiring_23.jpg


#. Clicca sulla pagina **dispositivi** e vedrai il nuovo dispositivo che hai appena creato. Quindi, fai clic su strumenti per sviluppatori.

    .. image:: img/blynk_copy_developer.png

#. Vedrai ``TEMPLATE_ID``, ``DEVICE_NAME`` e ``AUTH_TOKEN`` nelle **Firmware info**, e dovrai copiarli successivamente.

    .. image:: img/blynk_copy_firmwareinfo.png

#. Apri il file ``1.connect.ino`` sotto il percorso ``3in1-kit\iot_project\1.connect``. Oppure copia questo codice nell'**Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/1c0c1a8f-2551-484f-9f4f-d5d4117cc864/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Sostituisci le seguenti tre righe di codice che puoi copiare dalle **Firmware info** del tuo account. Queste tre righe di codice permetteranno alla tua scheda R3 di trovare il tuo account Blynk.

    .. code-block:: arduino

        #define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
        #define BLYNK_DEVICE_NAME "Device"
        #define BLYNK_AUTH_TOKEN "YourAuthToken"

#. Inserisci ``ssid`` e ``password`` del WiFi che stai utilizzando.

    .. code-block:: arduino

        char ssid[] = "ssid";
        char pass[] = "password";

#. Carica il codice sulla scheda R3, quindi apri il monitor seriale e imposta il baud rate su 115200. Quando la scheda R3 comunica correttamente con Blynk, il monitor seriale mostrerà il carattere ``ready``.

    .. image:: img/blynk_connect_network.png

    .. note::
    
        Se compare il messaggio ``ESP non risponde`` quando ti connetti, segui questi passaggi.

        * Assicurati che la batteria da 9V sia collegata.
        * Resetta il modulo ESP8266 collegando il pin RST a GND per 1 secondo, quindi scollegalo.
        * Premi il pulsante di reset sulla scheda R3.

        A volte, potrebbe essere necessario ripetere l'operazione sopra 3-5 volte, sii paziente.

#. Lo stato di Blynk passerà da **offline** a **online**.

    .. image:: img/sp220607_170326.png
