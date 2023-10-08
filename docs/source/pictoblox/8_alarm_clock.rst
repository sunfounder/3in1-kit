.. _sh_light_alarm:

2.8 Lichtwecker
======================

Im Leben gibt es viele verschiedene Weckerarten. Lassen Sie uns jetzt einen lichtgesteuerten Wecker erstellen. Wenn der Morgen anbricht und die Helligkeit zunimmt, wird dieser Lichtwecker Sie daran erinnern, dass es Zeit ist aufzustehen.

.. image:: img/10_clock.png

Was Sie lernen werden
------------------------

- Funktionsprinzip des Fotowiderstands
- Stoppen der Soundwiedergabe und Beenden laufender Skripte

Benötigte Komponenten
------------------------

Für dieses Projekt benötigen Sie folgende Bauteile.

Es ist natürlich praktisch, ein ganzes Set zu kaufen, hier der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können die Teile auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_photoresistor` 
        - |link_photoresistor_buy|

Schaltung aufbauen
-----------------------

Ein Fotowiderstand oder Fotodiode ist ein lichtgesteuerter variabler Widerstand. Der Widerstand eines Fotowiderstands verringert sich mit zunehmender Lichteinstrahlung.

Bauen Sie die Schaltung gemäß dem folgenden Schaltplan auf.

Verbinden Sie ein Ende des Fotowiderstands mit 5V, das andere Ende mit A0 und schließen Sie einen 10K-Widerstand in Reihe mit GND an diesem Ende an.

Wenn also die Lichtintensität zunimmt, verringert sich der Widerstand des Fotowiderstands, die Spannungsteilung des 10K-Widerstands steigt und der von A0 ermittelte Wert wird größer.

.. image:: img/circuit/photoresistor_circuit.png

Programmierung
------------------

**1. Wählen Sie eine Figur**

Löschen Sie die Standardfigur, klicken Sie auf den **Choose a Sprite**-Button in der unteren rechten Ecke des Figurenbereichs, geben Sie **bell** in das Suchfeld ein und fügen Sie sie dann hinzu.

.. image:: img/10_sprite.png

**2. Wert von A0 auslesen**

Erstellen Sie zwei Variablen **before** und **current**. Wenn Sie auf die grüne Flagge klicken, lesen Sie den Wert von A0 aus und speichern ihn in der Variable **before** als Referenzwert. In [forever], lesen Sie den Wert von A0 erneut und speichern ihn in der Variable **current**.

.. image:: img/10_reada0.png

**3. Einen Ton erzeugen**

Wenn der aktuelle Wert von A0 um 50 höher ist als der vorherige, was bedeutet, dass die aktuelle Lichtintensität über dem Schwellenwert liegt, lassen Sie die Figur einen Ton erzeugen.

.. image:: img/10_sound.png

**4. Die Figur drehen**

Verwenden Sie den [turn block], um die **bell**-Figur links und rechts drehen zu lassen, um den Weckereffekt zu erzielen.

.. image:: img/10_turn.png

**5. Alles stoppen**

Stoppen Sie den Alarm, nachdem er eine Weile geklingelt hat.

.. image:: img/10_stop.png
