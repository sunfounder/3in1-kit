.. note::

    Ciao, benvenuto nella community SunFounder di appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotto e anteprime.
    - **Sconti esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a promozioni festive e omaggi.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _burn_firmware:

Come ri-scrivere il firmware per il modulo ESP8266?
=======================================================

Ri-scrivere il Firmware con R3
---------------------------------------

**1. Costruire il circuito**

Collega ESP8266 e la scheda SunFounder R3.

    .. image:: img/connect_esp8266.png
        :width: 800

**2. Scrittura del firmware**

* Segui i passaggi seguenti per scrivere il firmware se stai utilizzando **Windows**.

    #. Scarica il firmware e lo strumento di masterizzazione.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Dopo l'estrazione, vedrai 4 file.

        .. .. image:: img/bat_firmware.png
    
        * ``BAT_AT_V1.7.1.0_1M.bin``: Il firmware da scrivere sul modulo ESP8266.
        * ``esptool.exe``: Un'utility a riga di comando per Windows.
        * ``install_r3.bat``: Questo è il pacchetto di comandi per Windows, facendo doppio clic su questo file eseguirai tutti i comandi all'interno del file.
        * ``install_r4.bat``: Uguale a ``install_r3.bat``, ma dedicato alla scheda UNO R4.

    #. Fai doppio clic su ``install_r3.bat`` per avviare la masterizzazione del firmware. Se vedi il seguente messaggio, il firmware è stato installato correttamente.

        .. image:: img/install_firmware.png

        .. note::
            Se la masterizzazione fallisce, controlla i seguenti punti.

            * Resetta il modulo ESP8266 collegando il RST sull'adattatore ESP8266 a GND e poi scollegandolo.
            * Controlla se il cablaggio è corretto.
            * Verifica se il computer ha riconosciuto correttamente la tua scheda e assicurati che la porta non sia occupata.
            * Riapri il file install.bat.

* Segui questi passaggi per scrivere il firmware se stai utilizzando un sistema **Mac OS**.

    #. Utilizza i seguenti comandi per installare Esptool. Esptool è un'utility open-source, basata su Python e indipendente dalla piattaforma, per comunicare con il bootloader ROM nei chip Espressif.

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. Se esptool è installato correttamente, uscirà un messaggio come [usage: esptool] se esegui ``python3 -m esptool``.

    #. Scarica il firmware.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Dopo l'estrazione, vedrai 3 file.

        .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: Il firmware da scrivere sul modulo ESP8266.
        * ``esptool.exe``: Un'utility a riga di comando per Windows.
        * ``install_r3.bat``: Pacchetto di comandi per Windows.
        * ``install_r4.bat``: Uguale a ``install_r3.bat``, ma dedicato alla scheda UNO R4.


    #. Apri un terminale e utilizza il comando ``cd`` per accedere alla cartella del firmware appena scaricata, quindi esegui il seguente comando per cancellare il firmware esistente e scrivere il nuovo firmware.

        .. code-block::

            python3 -m esptool --chip esp8266 --before default_reset erase_flash
            python3 -m esptool --chip esp8266 --before default_reset write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. Se vedi il seguente messaggio, il firmware è stato installato correttamente.

        .. image:: img/install_firmware_macos.png

        .. note::
            Se la masterizzazione fallisce, controlla i seguenti punti.

            * Resetta il modulo ESP8266 collegando il RST sull'adattatore ESP8266 a GND e poi scollegandolo.
            * Controlla se il cablaggio è corretto.
            * Verifica se il computer ha riconosciuto correttamente la tua scheda e assicurati che la porta non sia occupata.
            * Riapri il file install.bat.

**3. Test**

#. Basandoti sul cablaggio originale, collega IO1 a 3V3.

    .. image:: img/connect_esp826612.png
        :width: 800

#. Potrai visualizzare le informazioni sul modulo ESP8266 cliccando sull'icona della lente d'ingrandimento (Monitor Seriale) in alto a destra e impostando la velocità baud a **115200**.

    .. image:: img/sp20220524113020.png

    .. note::

        * Se non appare ``ready``, puoi provare a resettare il modulo ESP8266 (collega RST a GND) e riaprire il Monitor Seriale.

#. Clicca su **NEWLINE DROPDOWN BOX**, seleziona ``both NL & CR`` nell'opzione a discesa, inserisci ``AT``, se restituisce OK, significa che ESP8266 ha stabilito con successo la connessione con la scheda R3.

    .. image:: img/sp20220524113702.png

.. Now you can continue to follow :ref:`config_esp8266` to set the working mode and baud rate of the ESP8266 module.

Ri-scrivere il Firmware con R4
---------------------------------------



**1. Costruire il circuito**

Collega ESP8266 e la scheda Arduino UNO R4.

    .. image:: img/faq_at_burn_bb.jpg
        :width: 800

**2. Caricare il seguente codice su R4**

.. code-block:: Arduino

    void setup() {
        Serial.begin(115200);
        Serial1.begin(115200);
    }

    void loop() {
        if (Serial.available()) {      // If anything comes in Serial (USB),
            Serial1.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
        }
            if (Serial1.available()) {     // If anything comes in Serial1 (pins 0 & 1)
            Serial.write(Serial1.read());   // read it and send it out Serial (USB)
        }
    }

**3. Masterizzare il firmware**

* Segui i passaggi seguenti per masterizzare il firmware se stai utilizzando **Windows**.

    #. Scarica il firmware e lo strumento di masterizzazione.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Dopo aver scompattato, vedrai 4 file.

        .. .. image:: img/bat_firmware.png
    
        * ``BAT_AT_V1.7.1.0_1M.bin``: Il firmware da scrivere sul modulo ESP8266.
        * ``esptool.exe``: Utility a riga di comando per Windows.
        * ``install_r3.bat``: Pacchetto di comandi per sistema Windows, facendo doppio clic verranno eseguiti tutti i comandi contenuti.
        * ``install_r4.bat``: Uguale a ``install_r3.bat``, ma dedicato alla scheda UNO R4.

    #. Fai doppio clic su ``install_r4.bat`` per avviare la masterizzazione del firmware. Se visualizzi il seguente messaggio, il firmware è stato installato correttamente.

        .. image:: img/install_firmware.png

        .. note::
            Se la masterizzazione fallisce, controlla i seguenti punti:

            * Resetta il modulo ESP8266 collegando il pin RST sull'adattatore ESP8266 a GND e scollegandolo successivamente.
            * Verifica se il cablaggio è corretto.
            * Controlla se il computer ha riconosciuto correttamente la scheda e assicurati che la porta non sia occupata.
            * Riapri il file install.bat.

* Segui questi passaggi per masterizzare il firmware se utilizzi un sistema **Mac OS**.

    #. Usa i seguenti comandi per installare Esptool. Esptool è un'utility open-source basata su Python e indipendente dalla piattaforma per comunicare con il bootloader ROM nei chip Espressif.

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. Se Esptool è installato correttamente, vedrai un messaggio tipo [usage: esptool] quando esegui ``python3 -m esptool``.

    #. Scarica il firmware.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Dopo aver scompattato, vedrai 4 file.

        .. .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: Il firmware da scrivere sul modulo ESP8266.
        * ``esptool.exe``: Utility a riga di comando per Windows.
        * ``install_r3.bat``: Pacchetto di comandi per sistema Windows.
        * ``install_r4.bat``: Uguale a ``install_r3.bat``, ma dedicato alla scheda UNO R4.


    #. Apri un terminale e usa il comando ``cd`` per entrare nella cartella del firmware che hai appena scaricato, poi esegui il seguente comando per cancellare il firmware esistente e scrivere il nuovo firmware.

        .. code-block::

            python3 -m esptool --chip esp8266 --before no_reset_no_sync erase_flash
            python3 -m esptool --chip esp8266 --before no_reset_no_sync write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. Se visualizzi il seguente messaggio, il firmware è stato installato correttamente.

        .. image:: img/install_firmware_macos.png

        .. note::
            Se la masterizzazione fallisce, controlla i seguenti punti:

            * Resetta il modulo ESP8266 collegando il pin RST sull'adattatore ESP8266 a GND e scollegandolo successivamente.
            * Verifica se il cablaggio è corretto.
            * Controlla se il computer ha riconosciuto correttamente la scheda e assicurati che la porta non sia occupata.
            * Riapri il file install.bat.

.. **4. Test**

.. #. 

.. #. On the basis of the original wiring, connect IO1 to 3V3.

..     .. image:: img/faq_at_burn_check_bb.jpg
..         :width: 800

.. #. You will be able to see information about the ESP8266 module if you click the magnifying glass icon(Serial Monitor) in the upper right corner and set the baud rate to **115200**.

..     .. image:: img/sp20220524113020.png

..     .. note::

..         * If ``ready`` doesn't appear, you can try to reset the ESP8266 module(connect RST to GND) and re-open the Serial Monitor.

.. #. Click on **NEWLINE DROPDOWN BOX**, select ``both NL & CR`` in the drop down option, enter ``AT``, if it returns OK, it means ESP8266 has successfully established connection with your board.

..     .. image:: img/sp20220524113702.png

.. Now you can continue to follow :ref:`config_esp8266` to set the working mode and baud rate of the ESP8266 module.


