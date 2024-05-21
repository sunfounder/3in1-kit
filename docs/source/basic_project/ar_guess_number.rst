.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_guess_number:

6.6 Nummer raten
==================

"Nummer raten" ist ein unterhaltsames Partyspiel, bei dem Sie und Ihre Freunde 
abwechselnd eine Zahl (0~99) eingeben. Der Bereich wird mit der Eingabe der 
Zahl immer kleiner, bis ein Spieler das Rätsel richtig löst. Dann wird der 
Spieler besiegt und bestraft. Zum Beispiel, wenn die Glückszahl 51 ist, die 
die Spieler nicht sehen können, und Spieler 1 gibt 50 ein, ändert sich der 
Zahlenbereich auf 50~99; gibt Spieler 2 die Zahl 70 ein, kann der Bereich der 
Zahl 50~70 sein; gibt Spieler 3 die Zahl 51 ein, ist er oder sie der 
Unglückliche. Hier verwenden wir eine IR-Fernbedienung zur Eingabe von Zahlen 
und ein LCD zur Ausgabe der Ergebnisse.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_receiver`
        - \-

**Schaltplan**

.. image:: img/circuit_guess_number.png
    :align: center

**Verdrahtung**

In diesem Beispiel ist die Verkabelung des LCD1602 und des Infrarot-Empfangsmoduls 
wie folgt:

.. image:: img/6.6_guess_number_bb.png
    :align: center



**Code**

.. note::

    * Sie können die Datei ``6.6.guess_number.ino`` direkt unter dem Pfad ``3in1-kit\learning_project\6.6.guess_number`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.
    * Hier werden die Bibliotheken ``LiquidCrystal I2C`` und ``IRremote libraries`` verwendet, die Sie über den **Library Manager** installieren können.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/6bafb36d-6763-460c-98b7-aba48120e718/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, erscheinen die Begrüßungszeichen auf dem LCD1602. Drücken Sie nun die Zahl entsprechend dem Bereichshinweis auf dem Bildschirm, die Anzeige wird immer kleiner, es sei denn, Sie erraten diese Glückszahl.

.. note::
    Wenn Code und Verkabelung in Ordnung sind, das LCD aber trotzdem keinen Inhalt anzeigt, können Sie das Potentiometer auf der Rückseite drehen, um den Kontrast zu erhöhen.

**Wie funktioniert das?**

Um das Zahlenratenspiel lebendig und lustig zu gestalten, müssen wir die folgenden Funktionen umsetzen:

1. Die Glückszahl wird angezeigt, wenn wir das Spiel starten und zurücksetzen, und der Zahlenbereichshinweis wird auf 0 ~ 99 zurückgesetzt.

2. Das LCD zeigt die eingegebene Zahl und den Bereichshinweis an.

3. Nach Eingabe von zwei Ziffern erscheint automatisch eine Ergebnisbewertung.

4. Wenn Sie eine einzelne Ziffer eingeben, können Sie die CYCLE-Taste (die Taste in der Mitte des Controllers) drücken, um die Ergebnisbewertung zu starten.

5. Wenn die Antwort nicht erraten wird, wird der neue Bereichshinweis angezeigt (wenn die Glückszahl 51 ist und Sie 50 eingeben, ändert sich der Bereichshinweis auf 50~99).

6. Das Spiel wird automatisch zurückgesetzt, nachdem die Glückszahl erraten wurde, sodass der Spieler eine neue Runde spielen kann.

7. Das Spiel kann durch direktes Drücken der POWER-Taste (die Taste in der oberen linken Ecke) zurückgesetzt werden.

Abschließend wird der Arbeitsablauf des Projekts im Flussdiagramm dargestellt.

.. image:: img/Part_three_4_Example_Explanation.png
    :align: center




