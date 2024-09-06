.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Immergiti più a fondo nel mondo di Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_guide:

1.3 Guida rapida su PictoBlox
=====================================

Ora impariamo a utilizzare PictoBlox in due modalità.

Inoltre, c'è un LED integrato collegato al Pin 13 sulla scheda R3. Impareremo a far lampeggiare questo LED in 2 modalità diverse.

.. image:: img/1_led.jpg
    :width: 500
    :align: center

.. _stage_mode:

Modalità Stage
------------------

**1. Connessione alla scheda Arduino**

Collega la tua scheda Arduino al computer tramite un cavo USB. Di solito il computer riconoscerà automaticamente la scheda e assegnerà una porta COM.

Apri PictoBlox, l'interfaccia di programmazione Python si aprirà per impostazione predefinita. Dobbiamo passare all'interfaccia a blocchi.

.. image:: img/0_choose_blocks.png

Poi vedrai l'angolo in alto a destra per il cambio di modalità. La modalità predefinita è la Modalità Stage, dove Tobi è in piedi sul palcoscenico.

.. image:: img/1_stage_upload.png

Clicca su **Board** nella barra di navigazione in alto a destra per selezionare la scheda.

.. image:: img/1_board.png

Ad esempio, scegli **Arduino Uno**.

.. image:: img/1_choose_uno.png

Apparirà quindi una finestra di connessione per selezionare la porta a cui connettersi e tornerai alla home page una volta completata la connessione. Se la connessione si interrompe durante l'uso, puoi anche cliccare su **Connect** per riconnetterti.

.. image:: img/1_connect.png

Nel frattempo, le palette dei blocchi relative ad Arduino Uno, come Arduino Uno e Attuatori, appariranno nella **Block Palette**.

.. image:: img/1_arduino_uno.png

**2. Carica il Firmware**

Poiché lavoreremo in Modalità Stage, dobbiamo caricare il firmware sulla scheda. Assicurerà una comunicazione in tempo reale tra la scheda e il computer. Il caricamento del firmware è un processo unico. Per farlo, clicca sul pulsante Carica Firmware.

Dopo qualche attesa, apparirà il messaggio di successo del caricamento.

.. note::

    Se utilizzi questa scheda Arduino in PictoBlox per la prima volta, o se questo Arduino è stato precedentemente caricato con l'IDE di Arduino, devi cliccare su **Carica Firmware** prima di poterla usare.

.. image:: img/1_firmware.png


**3. Programmazione**

* Apri ed esegui direttamente lo script

Ovviamente puoi aprire gli script direttamente per eseguirli, ma prima scaricali da `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_.

Puoi cliccare su **File** nell'angolo in alto a destra e poi scegliere **Apri**.

.. image:: img/0_open.png

Scegli **Apri dal computer**.

.. image:: img/0_dic.png

Poi vai al percorso ``3in1-kit\scratch_project\code``, e apri **1. Stage Mode.sb3**. Assicurati di aver scaricato il codice richiesto da `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_.

.. image:: img/0_stage.png

Clicca direttamente sullo script per eseguirlo, in alcuni progetti basta cliccare sulla bandiera verde o sullo sprite.

.. image:: img/1_more.png

* Programma passo dopo passo

Puoi anche scrivere lo script passo dopo passo seguendo questi passaggi.

Clicca sulla palette **Arduino Uno**.

.. image:: img/1_arduino_uno.png

Il LED sulla scheda Arduino è controllato dal pin digitale 13 (solo 2 stati, HIGH o LOW), quindi trascina il blocco [set digital pin out as] nell'area script.

Poiché lo stato predefinito del LED è acceso, ora imposta il pin 13 su LOW e clicca su questo blocco e vedrai il LED spegnersi.

* [set digital pin out as]: Imposta i pin digitali (2~13) su livello (HIGH/LOW).

.. image:: img/1_digital.png

Per vedere l'effetto del LED lampeggiante in modo continuo, devi utilizzare i blocchi [Aspetta 1 secondo] e [sempre] nella palette **Control**. Clicca su questi blocchi dopo averli scritti, ci sarà un alone giallo che significa che è in esecuzione.

* [Aspetta 1 secondo]: dalla palette **Control**, usato per impostare l'intervallo di tempo tra 2 blocchi.
* [sempre]: dalla palette **Control**, consente allo script di continuare a funzionare finché non viene manualmente interrotto.

.. image:: img/1_more.png

.. _upload_mode:

Modalità Upload
-------------------

**1. Connessione alla scheda Arduino**

Collega la tua scheda Arduino al computer tramite un cavo USB. Di solito il computer riconoscerà automaticamente la scheda e assegnerà una porta COM.

Apri PictoBlox e clicca su **Board** nella barra di navigazione in alto a destra per selezionare la scheda.

.. image:: img/1_board.png

Ad esempio, scegli **Arduino Uno**.

.. image:: img/1_choose_uno.png

Apparirà quindi una finestra di connessione per selezionare la porta a cui connettersi e tornerai alla home page una volta completata la connessione. Se la connessione si interrompe durante l'uso, puoi anche cliccare su **Connect** per riconnetterti.

.. image:: img/1_connect.png

Nel frattempo, le palette dei blocchi relative ad Arduino Uno, come Arduino Uno e Attuatori, appariranno nella **Block Palette**.

.. image:: img/1_upload_uno.png

Dopo aver selezionato la modalità Upload, il palco si sposterà nell'area del codice originale di Arduino.

.. image:: img/1_upload.png

**2. Programmazione**

* Apri ed esegui direttamente lo script

Puoi cliccare su **File** nell'angolo in alto a destra.

.. image:: img/0_open.png

Scegli **Apri dal computer**.

.. image:: img/0_dic.png

Poi vai al percorso ``3in1-kit\scratch_project\code``, e apri **1. Upload Mode.sb3**. Assicurati di aver scaricato il codice richiesto da `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_.

.. image:: img/0_upload.png

Infine, clicca sul pulsante **Carica Codice**.

.. image:: img/1_upload_code.png


* Programma passo dopo passo

Puoi anche scrivere lo script passo dopo passo seguendo questi passaggi.

Clicca sulla palette **Arduino Uno**.

.. image:: img/1_upload_uno.png

Trascina [quando Arduino Uno si avvia] nell'area script, che è necessario per ogni script.

.. image:: img/1_uno_starts.png

Il LED sulla scheda Arduino è controllato dal pin digitale 13 (solo 2 stati HIGH o LOW), quindi trascina il blocco [set digital pin out as] nell'area script.

Poiché lo stato predefinito del LED è acceso, ora imposta il pin 13 su LOW e clicca su questo blocco e vedrai il LED spegnersi.

* [set digital pin out as]: Imposta il pin digitale (2~13) su livello (HIGH/LOW).

.. image:: img/1_upload_digital.png

A questo punto vedrai il codice Arduino apparire sul lato destro. Se desideri modificare questo codice, puoi attivare la modalità di modifica.

.. image:: img/1_upload1.png

Per vedere l'effetto del LED lampeggiante in modo continuo, devi utilizzare i blocchi [Aspetta 1 secondo] e [sempre] nella palette **Control**. Clicca su questi blocchi dopo averli scritti, ci sarà un alone giallo che significa che è in esecuzione.

* [Aspetta 1 secondo]: dalla palette **Control**, usato per impostare l'intervallo di tempo tra 2 blocchi.
* [sempre]: dalla palette **Control**, consente allo script di continuare a funzionare finché non viene interrotto.

.. image:: img/1_upload_more.png

Infine, clicca sul pulsante **Carica Codice**.

.. image:: img/1_upload_code.png