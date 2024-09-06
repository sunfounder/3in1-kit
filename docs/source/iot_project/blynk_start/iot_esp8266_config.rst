.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a promozioni speciali e giveaway durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _config_esp8266:

1.0 Configurare l'ESP8266
===============================

Il modulo ESP8266 fornito con il kit è già pre-configurato con firmware AT.
Se desideri modificarne la configurazione, segui i passaggi qui sotto.
Se usi UNO R4, non sarà possibile configurare l'ESP8266 in questo modo.

1. Costruisci il circuito.

    .. image:: img/iot_1_at_set_bb.jpg
        :width: 800

2. Apri il file ``1.set_software_serial.ino`` sotto il percorso ``3in1-kit\iot_project\1.set_software_serial``. Oppure copia questo codice nell'**Arduino IDE**.

    .. code-block:: Arduino

        #include <SoftwareSerial.h>
        SoftwareSerial espSerial(2, 3); //Rx,Tx

        void setup() {
            // put your setup code here, to run once:
            Serial.begin(115200);
            espSerial.begin(115200);
        }

        void loop() {
            if (espSerial.available()) {
                Serial.write(espSerial.read());
            }
            if (Serial.available()) {
                espSerial.write(Serial.read());
            }
        }


3. Clicca sull'icona della lente d'ingrandimento (Monitor Seriale) in alto a destra e imposta il baud rate su **115200**. (Potresti vedere alcune informazioni stampate come me, oppure no, non importa, passa al passaggio successivo.)

    .. image:: img/sp20220524113020.png

    .. warning::

        * Se non appare ``ready``, puoi provare a resettare il modulo ESP8266 (collega RST a GND) e riapri il Monitor Seriale.

        * Inoltre, se il risultato è ``OK``, potrebbe essere necessario ri-masterizzare il firmware. Per favore fai riferimento a :ref:`burn_firmware` per maggiori dettagli. Se non riesci ancora a risolvere, fai uno screenshot del monitor seriale e invialo a service@sunfounder.com, ti aiuteremo a risolvere il problema il prima possibile.

4. Clicca su **NEWLINE DROPDOWN BOX**, seleziona ``both NL & CR`` nell'opzione a tendina, inserisci ``AT``, se ritorna OK, significa che l'ESP8266 ha stabilito con successo la connessione con la scheda R3.

    .. image:: img/sp20220524113702.png

5. Inserisci ``AT+CWMODE=3`` e la modalità sarà cambiata a **coesistenza di Station e AP**.

    .. image:: img/sp20220524114032.png

.. 6. In order to use the software serial later, you must input ``AT+UART=9600,8,1,0,0`` to modify the ESP8266's baud rate to 9600.

..     .. image:: img/PIC4_sp220615_150321.png

.. 7. Now change the serial monitor baud rate to 9600, try to enter ``AT``, if it returns OK, it means the setting is successful.


..     .. image:: img/PIC5_sp220615_150431.png

