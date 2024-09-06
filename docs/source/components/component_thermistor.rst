.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_thermistor:

Termistore
===============

.. image:: img/thermistor.png
    :width: 150
    :align: center

Un termistore è un tipo di resistore la cui resistenza dipende fortemente dalla temperatura, più di quanto non avvenga nei resistori standard. Il termine è una combinazione di "termico" e "resistore". I termistori sono ampiamente utilizzati come limitatori di corrente di spunto, sensori di temperatura (tipicamente del tipo a coefficiente di temperatura negativo o NTC), protettori autoripristinanti da sovracorrente e elementi riscaldanti autoregolanti (tipicamente del tipo a coefficiente di temperatura positivo o PTC).

* `Thermistor - Wikipedia <https://en.wikipedia.org/wiki/Thermistor>`_

Ecco il simbolo elettronico del termistore.

.. image:: img/thermistor_symbol.png
    :width: 300
    :align: center

I termistori si dividono in due tipologie fondamentali opposte:

* Con i termistori NTC, la resistenza diminuisce con l'aumento della temperatura, di solito a causa di un aumento degli elettroni di conduzione attivati dall'agitazione termica della banda di valenza. Un NTC è comunemente usato come sensore di temperatura o in serie con un circuito come limitatore di corrente di spunto.
* Con i termistori PTC, la resistenza aumenta con l'aumentare della temperatura, di solito a causa di maggiori agitazioni reticolari termiche, in particolare quelle di impurità e imperfezioni. I termistori PTC sono comunemente installati in serie con un circuito e utilizzati per proteggere da condizioni di sovracorrente, come fusibili autoripristinanti.

In questo kit utilizziamo un NTC. Ogni termistore ha una resistenza normale. Qui è di 10k ohm, misurata a 25 gradi Celsius.

Ecco la relazione tra resistenza e temperatura:

    RT = RN * expB(1/TK – 1/TN)   

* **RT** è la resistenza del termistore NTC quando la temperatura è TK. 
* **RN** è la resistenza del termistore NTC alla temperatura nominale TN. Qui, il valore di RN è 10k.
* **TK** è la temperatura in Kelvin e l'unità è K. Qui, il valore di TK è 273,15 + gradi Celsius.
* **TN** è la temperatura nominale in Kelvin; anche l'unità è K. Qui, il valore di TN è 273,15+25.
* **B(beta)**, la costante del materiale del termistore NTC, è chiamata anche indice di sensibilità termica con un valore numerico di 3950.      
* **exp** è l'abbreviazione di esponenziale, e il numero di base e è un numero naturale e vale circa 2,7.  

Converti questa formula TK=1/(ln(RT/RN)/B+1/TN) per ottenere la temperatura in Kelvin, da cui sottrai 273,15 per ottenere i gradi Celsius.

Questa relazione è una formula empirica. È accurata solo quando la temperatura e la resistenza rientrano nell'intervallo effettivo.

**Esempio**

* :ref:`ar_high_tem_alarm` (Basic Project)
* :ref:`ar_temp` (Basic Project)

* :ref:`sh_low_temperature` (Scratch Project)
