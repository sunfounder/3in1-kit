.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

Come caricare uno Sketch sulla Scheda?
===============================================

In questa sezione, imparerai come caricare lo sketch creato in precedenza sulla scheda Arduino, oltre ad alcune considerazioni.

**1. Scegliere la scheda e la porta**

Le schede di sviluppo Arduino sono generalmente fornite con un cavo USB. Puoi usarlo per collegare la scheda al tuo computer.

Seleziona la **Scheda** e la **Porta** corrette nell'Arduino IDE. Normalmente, le schede Arduino vengono riconosciute automaticamente dal computer e assegnate a una porta, quindi puoi selezionarla qui.

    .. image:: img/board_port.png


Se la tua scheda è già collegata, ma non viene riconosciuta, verifica se il logo **INSTALLED** appare nella sezione **Arduino AVR Boards** del **Boards Manager**; in caso contrario, scorri un po' verso il basso e clicca su **INSTALL**.

    .. image:: img/upload1.png

La riapertura dell'Arduino IDE e il ricollegamento della scheda Arduino risolveranno la maggior parte dei problemi. Puoi anche cliccare su **Strumenti** -> **Scheda** o **Porta** per selezionarli.


**2. Verificare lo Sketch**

Dopo aver cliccato sul pulsante Verifica, lo sketch verrà compilato per vedere se ci sono errori.

    .. image:: img/sp221014_174532.png

Puoi utilizzarlo per trovare errori se elimini alcuni caratteri o digiti alcune lettere per errore. Dalla barra dei messaggi, puoi vedere dove e che tipo di errori sono occorsi.

    .. image:: img/sp221014_175307.png

Se non ci sono errori, vedrai un messaggio simile a quello qui sotto.

    .. image:: img/sp221014_175512.png


**3. Caricare lo sketch**

Dopo aver completato i passaggi precedenti, clicca sul pulsante **Upload** per caricare questo sketch sulla scheda.

    .. image:: img/sp221014_175614.png

Se l'operazione ha successo, vedrai il seguente messaggio.

    .. image:: img/sp221014_175654.png

Allo stesso tempo, il LED a bordo lampeggerà.

    .. image:: img/1_led.jpg

La scheda Arduino eseguirà automaticamente lo sketch dopo l'applicazione dell'alimentazione una volta caricato lo sketch. Il programma in esecuzione può essere sovrascritto caricando un nuovo sketch.
