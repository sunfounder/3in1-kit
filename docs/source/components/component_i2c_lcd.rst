.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_i2c_lcd1602:

I2C LCD1602
==============

.. image:: img/i2c_lcd1602.png
    :width: 800

* **GND**: Massa
* **VCC**: Alimentazione, 5V.
* **SDA**: Linea di dati seriali. Collegare a VCC tramite una resistenza pull-up.
* **SCL**: Linea di clock seriale. Collegare a VCC tramite una resistenza pull-up.

Come sappiamo, sebbene i display LCD e altri schermi arricchiscano notevolmente l'interazione uomo-macchina, condividono una debolezza comune. Quando vengono collegati a un controller, occupano molte porte IO del controller, che spesso non ha sufficienti porte esterne. Questo limita anche altre funzionalità del controller.

Per risolvere questo problema, è stato sviluppato l'LCD1602 con un modulo I2C. Il modulo I2C integra un chip I2C PCF8574 che converte i dati seriali I2C in dati paralleli per il display LCD.

* `PCF8574 Datasheet <https://www.ti.com/lit/ds/symlink/pcf8574.pdf?ts=1627006546204&ref_url=https%253A%252F%252Fwww.google.com%252F>`_

**Indirizzo I2C**

L'indirizzo predefinito è generalmente 0x27, in alcuni casi potrebbe essere 0x3F.

Prendendo come esempio l'indirizzo predefinito di 0x27, l'indirizzo del dispositivo può essere modificato cortocircuitando i pad A0/A1/A2; nello stato predefinito, A0/A1/A2 è 1, e se il pad viene cortocircuitato, A0/A1/A2 diventa 0.

.. image:: img/i2c_address.jpg
    :width: 600

**Retroilluminazione/Contrasto**

La retroilluminazione può essere abilitata tramite un jumper, scollegando il jumper per disabilitarla. Il potenziometro blu sul retro viene utilizzato per regolare il contrasto (il rapporto di luminosità tra il bianco più chiaro e il nero più scuro).

.. image:: img/back_lcd1602.jpg

* **Jumper**: La retroilluminazione può essere attivata con questo jumper, scollegare il jumper per disabilitarla.
* **Potenziometro**: Viene utilizzato per regolare il contrasto (la nitidezza del testo visualizzato), che aumenta in senso orario e diminuisce in senso antiorario.

**Esempio**

* :ref:`ar_lcd1602` (Basic Project)
* :ref:`ar_serial_read` (Basic Project)
