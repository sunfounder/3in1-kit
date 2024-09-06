.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

Come creare, aprire o salvare uno sketch?
=============================================

#. Quando apri l'Arduino IDE per la prima volta o crei un nuovo sketch, vedrai una pagina come questa, dove l'Arduino IDE crea un nuovo file per te, chiamato "sketch".

    .. image:: img/sp221014_173458.png

    Questi file sketch hanno un nome temporaneo regolare, dal quale puoi capire la data in cui il file è stato creato. ``sketch_oct14a.ino`` significa primo sketch del 14 ottobre, ``.ino`` è il formato di file di questo sketch.

#. Ora proviamo a creare un nuovo sketch. Copia il seguente codice nell'Arduino IDE per sostituire il codice originale.

        .. image:: img/create1.png

    .. code-block:: C

        void setup() {
            // put your setup code here, to run once:
            pinMode(13,OUTPUT); 
        }

        void loop() {
            // put your main code here, to run repeatedly:
            digitalWrite(13,HIGH);
            delay(500);
            digitalWrite(13,LOW);
            delay(500);
        }

#. Premi ``Ctrl+S`` o clicca su **File** -> **Salva**. Lo sketch viene salvato in: ``C:\Users\{your_user}\Documents\Arduino`` per impostazione predefinita, puoi rinominarlo o scegliere un nuovo percorso per salvarlo.

    .. image:: img/create2.png

#. Dopo aver salvato con successo, vedrai che il nome nell'Arduino IDE è stato aggiornato.

    .. image:: img/create3.png

Continua con la sezione successiva per imparare come caricare questo sketch creato sulla tua scheda Arduino.
