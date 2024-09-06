.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_esp8266:

Modulo ESP8266
=================

.. image:: img/esp8266.jpg
    :align: center

L'ESP8266 è un microchip Wi-Fi a basso costo, 
con software di rete TCP/IP integrato e capacità di microcontrollore, prodotto da Espressif Systems a Shanghai, Cina.

Il chip ha attirato l'attenzione dei maker occidentali nell'agosto 2014 con il modulo ESP-01, 
realizzato da un produttore terzo, Ai-Thinker. 
Questo piccolo modulo permette ai microcontrollori di connettersi a una rete Wi-Fi e di stabilire connessioni TCP/IP semplici utilizzando comandi in stile Hayes. 
Tuttavia, inizialmente, non c'era quasi nessuna documentazione in inglese sul chip e sui comandi accettati. 
Il prezzo estremamente basso e il fatto che ci fossero pochissimi componenti esterni sul modulo, 
suggerendo che potesse diventare molto economico su larga scala, 
ha attratto molti hacker a esplorare il modulo, il chip e il software su di esso, oltre a tradurre la documentazione cinese.

Pin dell'ESP8266 e loro funzioni:

.. image:: img/ESP8266_pinout.png


.. list-table:: ESP8266-01 Pins
   :widths: 25 25 100
   :header-rows: 1

   * - Pin	
     - Nome	
     - Descrizione
   * - 1	
     - TXD	
     - UART_TXD, trasmissione; Input/Output Generale: GPIO1; Non è consentito il pull-down all'avvio.
   * - 2	
     - GND
     - GND
   * - 3	
     - CU_PD	
     - Funziona ad alto livello; si spegne quando viene fornito un livello basso.
   * - 4		
     - GPIO2
     - Deve essere ad alto livello all'accensione, non è consentito il pull-down hardware; Pull-up di default;
   * - 5	
     - RST	
     - Segnale di Reset esterno, si resetta con livello basso; funziona con livello alto (alto di default);
   * - 6	
     - GPIO0	
     - Indicatore di stato Wi-Fi; Selezione modalità operativa: Pull-up: Flash Boot, modalità operativa; Pull-down: UART Download, modalità download
   * - 7	
     - VCC	
     - Alimentazione (3.3V)
   * - 8	
     - RXD	
     - UART_RXD，Ricezione; Input/Output Generale: GPIO3;


* `ESP8266 - Espressif <https://www.espressif.com/en/products/socs/esp8266>`_
* `ESP8266 AT Instruction Set <https://github.com/sunfounder/3in1-kit/blob/main/iot_project/esp8266_at_instruction_set_en.pdf>`_

Adattatore ESP8266
------------------------

.. image:: img/esp8266_adapter.png
    :width: 300
    :align: center

L'adattatore ESP8266 è una scheda di espansione che consente l'utilizzo del modulo ESP8266 su una breadboard.

Si adatta perfettamente ai pin dell'ESP8266 stesso e aggiunge un pin a 5V per ricevere la tensione dalla scheda Arduino. Il chip AMS1117 integrato viene utilizzato per alimentare il modulo ESP8266 dopo aver ridotto la tensione a 3.3V.

Lo schema elettrico è il seguente:

.. image:: img/sch_esp8266adapter.png


**Esempio**


* :ref:`iot_projects` (IoT Project)