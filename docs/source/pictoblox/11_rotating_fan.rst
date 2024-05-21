.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_rotating_fan:

2.11 Drehender Ventilator
============================

In diesem Projekt erstellen wir einen sich drehenden Sternsprite und Ventilator.

Durch Klicken auf die linken und rechten Pfeilsprites auf der Bühne wird die Uhrzeigersinn- und die Gegen-Uhrzeigersinn-Drehung des Motors und des Sternsprites gesteuert. Klicken Sie auf den Sternsprite, um die Drehung zu stoppen.

.. image:: img/13_fan.png

Was Sie lernen werden
-------------------------

- Arbeitsprinzip des Motors
- Broadcast-Funktion
- Block zum Stoppen anderer Skripte im Sprite

Benötigte Komponenten
-------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch einzeln über die folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110` 
        - \-

Schaltung aufbauen
-----------------------

.. image:: img/circuit/motor_circuit.png

Programmierung
------------------
Das gewünschte Ergebnis ist, mit 2 Pfeilsprites die Uhrzeigersinn- und die Gegen-Uhrzeigersinn-Drehung des Motors und des Sternsprites zu steuern. Ein Klick auf den Sternsprite stoppt die Drehung des Motors.

**1. Sprites hinzufügen**

Löschen Sie den Standardsprite, wählen Sie dann den **Star**-Sprite und den **Arrow1**-Sprite und kopieren Sie **Arrow1** einmal.

.. image:: img/13_star.png

Unter der Option **Costumes** ändern Sie den **Arrow1**-Sprite zu einem anderen Richtungskostüm.

.. image:: img/13_star1.png

Passen Sie die Größe und Position des Sprites entsprechend an.

.. image:: img/13_star2.png

**2. Linker Pfeil-Sprite**

Wenn man auf diesen Sprite klickt, sendet er eine Nachricht - drehen, setzt dann den digitalen Pin 9 auf niedrig und Pin 10 auf hoch und setzt die Variable **flag** auf 1. Wenn Sie auf den linken Pfeil klicken, dreht sich der Motor gegen den Uhrzeigersinn. Wenn Ihre Drehung im Uhrzeigersinn ist, tauschen Sie die Positionen von Pin 9 und Pin 10.

Zwei Dinge sind hier zu beachten:

* `[broadcast <https://de.scratch-wiki.info/wiki/Broadcast>`_]: aus der **Events**-Palette, wird verwendet, um eine Nachricht an die anderen Sprites zu senden. Wenn die anderen Sprites diese Nachricht erhalten, führen sie ein bestimmtes Ereignis aus. Hier ist es **turn**. Wenn der **star**-Sprite diese Nachricht erhält, führt er das Dreh-Skript aus.
* Variable flag: Die Drehrichtung des Sternsprites wird durch den Wert von flag bestimmt. Wenn Sie die Variable **flag** erstellen, müssen Sie sicherstellen, dass sie für alle Sprites gilt.

.. image:: img/13_left.png

**3. Rechter Pfeil-Sprite**

Wenn Sie auf diesen Sprite klicken, senden Sie eine Nachricht zum Drehen, setzen Sie dann den digitalen Pin 9 hoch und Pin 10 niedrig, damit sich der Motor im Uhrzeigersinn dreht und setzen Sie die Variable **flag** auf 0.

.. image:: img/13_right.png

**4. Stern-Sprite**

Hier sind 2 Ereignisse enthalten:

* Wenn der **star**-Sprite die gesendete Nachricht zum Drehen empfängt, bestimmt er den Wert von flag; ist flag 1, dreht er sich 10 Grad nach links, sonst umgekehrt. Da es sich im [FOREVER]-Block befindet, wird es weiter drehen.
* Wenn Sie auf diesen Sprite klicken, setzen Sie beide Pins des Motors auf hoch, um ihn zu stoppen und stoppen die anderen Skripte in diesem Sprite.

.. image:: img/13_broadcast.png



