.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato a nuovi annunci di prodotti e anteprime esclusive.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

Come Costruire il Circuito
=============================

Molti degli oggetti che usi quotidianamente sono alimentati dall'elettricità, come le luci di casa tua e il computer su cui stai leggendo.

Per utilizzare l'elettricità, è necessario costruire un circuito elettrico. Fondamentalmente, un circuito è un percorso attraverso cui scorre l'elettricità, costituito da dispositivi e componenti elettrici (apparecchi) collegati in un certo modo, come resistori, condensatori, alimentatori e interruttori.

.. image:: img/circuit.png

Un circuito è un percorso chiuso in cui gli elettroni si muovono per creare una corrente elettrica. Per far scorrere la corrente, deve esserci un percorso conduttivo tra il terminale positivo dell'alimentatore e il terminale negativo, che viene chiamato circuito chiuso (se interrotto, viene chiamato circuito aperto).

La scheda Arduino dispone di alcuni pin di uscita di potenza (positivo) e di alcuni pin di massa (negativo).
Puoi utilizzare questi pin come lati positivo e negativo dell'alimentatore collegando la fonte di alimentazione alla scheda.

.. image:: img/arduinoPN.jpg

Con l'elettricità, puoi creare opere con luce, suono e movimento.
Puoi accendere un LED collegando il pin lungo al terminale positivo e il pin corto al terminale negativo.
Il LED si danneggerà molto rapidamente se lo fai, quindi è necessario aggiungere una resistenza da 220 ohm all'interno del circuito per proteggerlo.

Il circuito risultante è mostrato di seguito.

.. image:: img/sp221014_181625.png

Potresti chiederti: come costruisco questo circuito? Devo tenere i fili con le mani o attaccare i pin e i fili con del nastro?

In questo caso, le breadboard senza saldatura saranno i tuoi alleati più preziosi.

.. _bc_bb:

Ciao, Breadboard!
-----------------------

Una breadboard è una piastra di plastica rettangolare con un gran numero di piccoli fori. 
Questi fori permettono di inserire facilmente i componenti elettronici e di costruire circuiti elettronici. 
Le breadboard non fissano permanentemente i componenti elettronici, quindi possiamo facilmente riparare un circuito e ricominciare da capo se qualcosa va storto.

.. note::
    Non è necessario alcuno strumento speciale per utilizzare le breadboard. Tuttavia, molti componenti elettronici sono molto piccoli, quindi un paio di pinzette può aiutare a maneggiare meglio le piccole parti.

Su Internet, possiamo trovare molte informazioni sulle breadboard.

* `How to Use a Breadboard - Science Buddies <https://www.sciencebuddies.org/science-fair-projects/references/how-to-use-a-breadboard#pth-smd>`_

* `What is a BREADBOARD? - Makezine <https://cdn.makezine.com/uploads/2012/10/breadboardworkshop.pdf>`_


Ecco alcune cose che dovresti sapere sulle breadboard.

#. Ogni gruppo di mezza fila (come la colonna A-E nella riga 1 o la colonna F-J nella riga 3) è collegato. Pertanto, se un segnale elettrico entra da A1, può uscire da B1, C1, D1, E1, ma non da F1 o A2.

#. Nella maggior parte dei casi, entrambi i lati della breadboard vengono utilizzati come bus di alimentazione, e i fori in ciascuna colonna (circa 50 fori) sono collegati tra loro. In generale, le alimentazioni positive sono collegate ai fori vicino al filo rosso, e le alimentazioni negative ai fori vicino al filo blu.

#. In un circuito, la corrente scorre dal polo positivo al polo negativo dopo aver attraversato il carico. In questo caso, potrebbe verificarsi un corto circuito.

**Seguiamo la direzione della corrente per costruire il circuito!**

.. image:: img/sp221014_182229_2.png

1. In questo circuito, utilizziamo il pin 5V della scheda per alimentare il LED. Usa un cavo jumper maschio-maschio (M2M) per collegarlo al bus di alimentazione rosso.
#. Per proteggere il LED, la corrente deve passare attraverso una resistenza da 220 ohm. Collega un'estremità (qualsiasi estremità) della resistenza al bus di alimentazione rosso, e l'altra estremità alla fila libera della breadboard.

    .. note::
        L'anello colorato della resistenza da 220 ohm è rosso, rosso, nero, nero e marrone.

#. Se prendi il LED, vedrai che uno dei suoi terminali è più lungo dell'altro. Collega il terminale più lungo alla stessa fila della resistenza, e il terminale più corto all'altra fila.

    .. note::
        Il terminale più lungo è l'anodo, che rappresenta il lato positivo del circuito; il terminale più corto è il catodo, che rappresenta il lato negativo.

        L'anodo deve essere collegato al pin GPIO attraverso una resistenza; il catodo deve essere collegato al pin GND.

#. Utilizzando un cavo jumper maschio-maschio (M2M), collega il pin corto del LED al bus di alimentazione negativo della breadboard.
#. Collega il pin GND della scheda al bus di alimentazione negativo utilizzando un cavo jumper.

Attenzione ai cortocircuiti
----------------------------------
I cortocircuiti possono verificarsi quando due componenti che non dovrebbero essere collegati vengono "accidentalmente" connessi. 
Questo kit include resistori, transistor, condensatori, LED, ecc., che hanno pin metallici lunghi che possono urtarsi l'un l'altro e causare un cortocircuito. Alcuni circuiti semplicemente smettono di funzionare correttamente quando si verifica un cortocircuito. Occasionalmente, un cortocircuito può danneggiare permanentemente i componenti, specialmente tra l'alimentatore e il bus di massa, causando un surriscaldamento del circuito, fondendo la plastica sulla breadboard e persino bruciando i componenti!

Pertanto, assicurati sempre che i pin di tutti i componenti elettronici sulla breadboard non si tocchino tra loro.

Direzione del circuito
----------------------------------
I circuiti hanno un orientamento, e questo gioca un ruolo significativo in alcuni componenti elettronici. Alcuni dispositivi hanno polarità, il che significa che devono essere collegati correttamente in base ai loro poli positivo e negativo. I circuiti costruiti con l'orientamento sbagliato non funzioneranno correttamente.

.. image:: img/sp221014_182229.png

Se inverti il LED in questo semplice circuito che abbiamo costruito in precedenza, scoprirai che non funziona più.

Al contrario, alcuni dispositivi non hanno direzione, come i resistori in questo circuito, quindi puoi provare a invertirli senza influire sul normale funzionamento dei LED.

La maggior parte dei componenti e moduli con etichette come "+", "-", "GND", "VCC" o con pin di lunghezze diverse devono essere collegati al circuito in un modo specifico.


Protezione del circuito
-------------------------------------

La corrente è la velocità con cui gli elettroni scorrono attraverso un punto in un circuito elettrico completo. In termini semplici, la corrente = flusso. Un ampere (AM-pir), o amp, è l'unità internazionale utilizzata per misurare la corrente. Esprime la quantità di elettroni (talvolta chiamata "carica elettrica") che fluisce attraverso un punto in un circuito in un dato tempo.

La forza motrice (tensione) dietro il flusso di corrente è chiamata tensione ed è misurata in volt (V).

La resistenza (R) è la proprietà del materiale che limita il flusso di corrente, ed è misurata in ohm (Ω).

Secondo la legge di Ohm (finché la temperatura rimane costante), corrente, tensione e resistenza sono proporzionali.
La corrente di un circuito è proporzionale alla sua tensione e inversamente proporzionale alla sua resistenza. 

Pertanto, corrente (I) = tensione (V) / resistenza (R).

* `Ohm's law - Wikipedia <https://en.wikipedia.org/wiki/Ohm%27s_law>`_

Possiamo fare un semplice esperimento sulla legge di Ohm.

.. image:: img/sp221014_183107.png

Modificando il filo che collega 5V a 3.3V, il LED diventa più debole.
Se cambi la resistenza da 220ohm a 1000ohm (anello colorato: marrone, nero, nero, marrone e marrone), noterai che il LED diventa più debole di prima. Più grande è la resistenza, più il LED si attenua.

.. note::
    Per un'introduzione ai resistori e su come calcolare i valori di resistenza, consulta :ref:`cpn_resistor`.

La maggior parte dei moduli confezionati richiede solo l'accesso alla tensione corretta (di solito 3.3V o 5V), come il modulo ultrasonico.

Tuttavia, nei tuoi circuiti auto-costruiti, devi essere consapevole della tensione di alimentazione e dell'uso delle resistenze per i dispositivi elettrici.


Ad esempio, i LED solitamente consumano 20mA di corrente e la loro caduta di tensione è di circa 1.8V. Secondo la legge di Ohm, se utilizziamo un'alimentazione di 5V, dobbiamo collegare una resistenza minima di 160ohm ((5-1.8)/20mA) per non bruciare il LED.



Controllo del circuito con Arduino
-------------------------------------------

Ora che abbiamo una comprensione di base della programmazione di Arduino e dei circuiti elettronici, è il momento di affrontare la domanda più critica: Come controllare i circuiti con Arduino.

In poche parole, il modo in cui Arduino controlla un circuito è cambiando il livello dei pin sulla scheda. Ad esempio, quando si controlla un LED a bordo, si scrive un segnale di livello alto o basso sul pin 13.


Ora proviamo a programmare la scheda Arduino per controllare il LED lampeggiante sulla breadboard. Costruisci il circuito in modo che il LED sia collegato al pin 9.

.. image:: img/wiring_led.png
    :width: 400
    :align: center


Successivamente, carica questo sketch sulla scheda Arduino.

.. code-block:: C

    int ledPin = 9;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
    }

Questo sketch è molto simile a quello che abbiamo usato per controllare il lampeggiamento del LED a bordo, la differenza è che il valore di ``ledPin`` è stato cambiato a 9.
Questo perché stiamo cercando di controllare il livello del pin 9 questa volta.

Ora puoi vedere il LED sulla breadboard lampeggiare.

