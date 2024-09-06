.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri nuovi prodotti.
    - **Promozioni festive e omaggi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ard_serial_monitor:

3.0 Monitor Serial
=============================

Nell'IDE di Arduino è presente un monitor seriale che consente di inviare messaggi dal computer alla scheda Arduino (tramite USB) e anche di ricevere messaggi dalla scheda.

In questo progetto impareremo come ricevere dati dalla scheda Arduino.

.. note::

    Su Uno, Nano, Mini e Mega, i pin 0 e 1 vengono utilizzati per la comunicazione con il computer. Collegare qualcosa a questi pin può interferire con tale comunicazione, causando anche errori di caricamento sulla scheda.


**Uso del Monitor Serial**

1. Apri l'IDE di Arduino e incolla il seguente codice.

    .. code-block:: arduino

        // the setup routine runs once when you press reset:
        void setup() {
            // initialize serial communication at 9600 bits per second:
            Serial.begin(9600);
        }

        // the loop routine runs over and over again forever:
        void loop() {
            int number = 100;
            Serial.println(number);
            Serial.println("Hello world");
            delay(100);         // delay in between reads for stability
        }

   * `Serial.begin() <https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/>`_: Sets the data rate in bits per second (baud) for serial data transmission, here set to 9600.
   * `Serial.println() <https://www.arduino.cc/reference/en/language/functions/communication/serial/println/>`_.

2. Seleziona la scheda e la porta corrette per caricare il codice.
3. Nella barra degli strumenti, clicca sull'icona della lente d'ingrandimento per accendere il Monitor Serial.

.. image:: img/serial1.png
    :align: center

4. Ecco il Monitor Serial.

.. image:: img/serial2.png
    :align: center

* **1**: Opzione per scegliere tra scorrimento automatico o non scorrimento.
* **2**: Opzione per visualizzare il timestamp prima dei dati mostrati sul Monitor Serial.
* **3**: Selezione della terminazione, scegli i caratteri di fine aggiunti ai dati inviati ad Arduino. Le opzioni includono:

        * **Nessuna terminazione** invia solo ciò che digiti;
        * **Nuova riga** è ``\n`` e invia un codice ASCII di nuova riga dopo quello che digiti;
        * **Ritorno a capo** è ``\r``, che invia un carattere di ritorno a capo ASCII dopo quello che digiti;
        * **Sia NL che CR** è ``\r\n`` che invia sia un ritorno a capo che un carattere di nuova riga dopo quello che digiti.
* **4**: Seleziona la velocità di comunicazione tra la scheda Arduino e il PC. Questo valore DEVE essere lo stesso impostato in ``Serial.begin()``.
* **5**: Cancella tutto il testo sulla console di output.
* **6**: Una casella di testo per inviare caratteri alla scheda Arduino, consulta :ref:`ar_serial_read` per un tutorial.

