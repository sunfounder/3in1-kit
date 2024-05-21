.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_doorbell:

2.6 Türklingel
======================

Hier werden wir den Knopf und die Klingel auf der Bühne verwenden, um eine Türklingel zu erstellen.

Nachdem Sie auf die grüne Flagge geklickt haben, können Sie den Knopf drücken und die Klingel auf der Bühne wird einen Ton von sich geben.

.. image:: img/7_doorbell.png

Was Sie lernen werden
------------------------

- Wie der Knopf funktioniert
- Digitalen Pin und Bereiche lesen
- Eine bedingte Schleife erstellen
- Einen Hintergrund hinzufügen
- Ton abspielen

Benötigte Komponenten
------------------------

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

Sie können sie auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|

Schaltung aufbauen
-----------------------

Der Knopf ist ein 4-Pin-Gerät, da der Pin 1 mit Pin 2 und Pin 3 mit Pin 4 verbunden ist. Wenn der Knopf gedrückt wird, werden die 4 Pins verbunden und der Schaltkreis geschlossen.

.. image:: img/5_buttonc.png

Bauen Sie den Schaltkreis entsprechend dem folgenden Diagramm auf.

* Verbinden Sie einen der Pins auf der linken Seite des Knopfes mit Pin 12, der mit einem Pull-down-Widerstand und einem 0,1uF (104) Kondensator verbunden ist (um Schwankungen zu eliminieren und ein stabiles Signal auszugeben, wenn der Knopf in Betrieb ist).
* Verbinden Sie das andere Ende des Widerstands und des Kondensators mit GND und einen der Pins auf der rechten Seite des Knopfes mit 5V.

.. image:: img/circuit/button_circuit.png

Programmierung
------------------

**1. Einen Hintergrund hinzufügen**

Klicken Sie auf den **Choose a Backdrop**-Button in der unteren rechten Ecke.

.. image:: img/7_backdrop.png

Wählen Sie **Bedroom 1** aus.

.. image:: img/7_bedroom2.png

**2. Das Sprite auswählen**

Löschen Sie das Standard-Sprite, klicken Sie auf den **Choose a Sprite**-Button in der unteren rechten Ecke des Sprite-Bereichs, geben Sie **bell** in das Suchfeld ein und fügen Sie es dann hinzu.

.. image:: img/7_sprite.png

Wählen Sie dann das **bell**-Sprite auf der Bühne und verschieben Sie es an die richtige Position.

.. image:: img/7_doorbell.png

**3. Drücken Sie den Knopf und die Glocke gibt einen Ton von sich**

Verwenden Sie [wenn dann], um eine bedingte Anweisung zu erstellen, dass wenn der Wert des gelesenen Pin12 gleich 1 ist (der Schlüssel gedrückt wird), der Ton **xylo1** abgespielt wird.

* [read status of digital pin]: Dieser Block stammt aus der **Arduino Uno**-Palette und wird verwendet, um den Wert eines digitalen Pins zu lesen, das Ergebnis ist 0 oder 1.
* [`if then <https://en.scratch-wiki.info/wiki/If_()_Then_(block)>`_]: Dieser Block ist ein Steuerblock und stammt aus der **Steuerung**-Palette. Wenn seine boolsche Bedingung wahr ist, werden die darin enthaltenen Blöcke ausgeführt und dann wird das beteiligte Skript fortgesetzt. Wenn die Bedingung falsch ist, werden die Skripte im Block ignoriert. Die Bedingung wird nur einmal überprüft; wenn die Bedingung während der Ausführung des Skripts im Block falsch wird, wird sie weiterhin ausgeführt, bis sie abgeschlossen ist.
* [play sound until done]: aus der Sound-Palette, verwendet um bestimmte Töne abzuspielen.

.. image:: img/7_bell.png
