.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_dht11:

Sensore di Temperatura e Umidità DHT11
==================================================

Il sensore digitale di temperatura e umidità DHT11 è un sensore composito che fornisce un'uscita digitale calibrata dei valori di temperatura e umidità. 
Utilizza la tecnologia di raccolta dei moduli digitali dedicati e la tecnologia di rilevamento di temperatura e umidità per garantire alta affidabilità e un'eccellente stabilità a lungo termine.

Il sensore comprende un componente resistivo per la misurazione dell'umidità e un dispositivo di misurazione della temperatura NTC, collegato a un microcontrollore ad alte prestazioni a 8 bit.

Sono disponibili solo tre pin per l'uso: VCC, GND e DATA.
Il processo di comunicazione inizia con il segnale di avvio inviato sulla linea DATA al DHT11, il quale riceve il segnale e restituisce un segnale di risposta. 
Successivamente, l'host riceve il segnale di risposta e inizia a ricevere i dati di umidità e temperatura a 40 bit (8 bit per l'umidità intera + 8 bit per la parte decimale dell'umidità + 8 bit per la temperatura intera + 8 bit per la parte decimale della temperatura + 8 bit per il checksum).

.. image:: img/dht11.png

**Caratteristiche**

    #. Intervallo di misurazione dell'umidità: 20 - 90%RH
    #. Intervallo di misurazione della temperatura: 0 - 60℃
    #. Uscita di segnali digitali per temperatura e umidità
    #. Tensione di lavoro: 5V DC; Dimensioni PCB: 2.0 x 2.0 cm
    #. Precisione nella misurazione dell'umidità: ±5%RH
    #. Precisione nella misurazione della temperatura: ±2℃

* `DHT11 Datasheet <http://wiki.sunfounder.cc/images/c/c7/DHT11_datasheet.pdf>`_

**Esempio**

* :ref:`ar_dht11` (Basic Project)
* :ref:`iot_home` (IoT Project)
* :ref:`iot_plant` (IoT Project)
