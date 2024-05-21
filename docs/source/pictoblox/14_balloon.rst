.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_balloon:

2.14 SPIEL - Den Ballon aufblasen
=========================================

Hier werden wir ein Ballonaufblas-Spiel spielen.

Nachdem Sie auf die grüne Flagge geklickt haben, wird der Ballon immer größer und größer. Wenn der Ballon zu groß wird, wird er platzen; wenn der Ballon zu klein ist, wird er herunterfallen; Sie müssen beurteilen, wann Sie den Knopf drücken, um ihn nach oben fliegen zu lassen.

.. image:: img/13_balloon0.png

Was Sie lernen werden
-------------------------

- Ein Kostüm für den Sprite malen

Benötigte Komponenten
------------------------

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

Sie können diese auch separat über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Schaltung aufbauen
-----------------------

Der Knopf ist ein 4-Pin-Gerät, da Pin 1 mit Pin 2 und Pin 3 mit Pin 4 verbunden ist. Wenn der Knopf gedrückt wird, sind alle 4 Pins verbunden und schließen so den Stromkreis.

.. image:: img/5_buttonc.png

Bauen Sie den Schaltkreis gemäß dem folgenden Diagramm.

* Verbinden Sie einen der Pins auf der linken Seite des Knopfes mit Pin 12, der mit einem Pull-down-Widerstand und einem 0,1uF (104) Kondensator verbunden ist (um Wackeln zu eliminieren und ein stabiles Level auszugeben, wenn der Knopf arbeitet).
* Verbinden Sie das andere Ende des Widerstands und des Kondensators mit GND und einen der Pins auf der rechten Seite des Knopfes mit 5V.

.. image:: img/circuit/button_circuit.png

Programmierung
------------------

**1. Einen Sprite und einen Hintergrund hinzufügen**

Löschen Sie den Standard-Sprite, klicken Sie auf die Schaltfläche **Choose a Sprite** in der unteren rechten Ecke des Sprite-Bereichs und wählen Sie dann den **Balloon1** Sprite aus.

.. image:: img/13_balloon1.png

Fügen Sie einen **Boardwalk** Hintergrund über die Schaltfläche **Choose a backdrop** hinzu, oder andere Hintergründe, die Ihnen gefallen.

.. image:: img/13_balloon2.png

**2. Ein Kostüm für den Balloon1 Sprite malen**

Jetzt zeichnen wir ein Explosions-Effekt-Kostüm für den Ballon-Sprite.

Gehen Sie zur **Costumes** Seite für den **Balloon1** Sprite, klicken Sie auf die Schaltfläche **Choose a Costume** in der unteren linken Ecke und wählen Sie **Paint**, um ein leeres **Costume** aufzurufen.

.. image:: img/13_balloon7.png

Wählen Sie eine Farbe und verwenden Sie dann das **Brush**-Werkzeug, um ein Muster zu zeichnen.

.. image:: img/13_balloon3.png

Wählen Sie erneut eine Farbe, klicken Sie auf das Füllwerkzeug und bewegen Sie die Maus innerhalb des Musters, um es mit einer Farbe zu füllen.

.. image:: img/13_balloon4.png

Schreiben Sie abschließend den Text BOOM, sodass ein Explosions-Effekt-Kostüm fertig ist.

.. image:: img/13_balloon5.png

**3. Den Balloon Sprite programmieren**

Stellen Sie die Anfangsposition und Größe des **Balloon1** Sprites ein.

.. image:: img/13_balloon6.png

Lassen Sie dann den **Balloon** Sprite langsam größer werden.

.. image:: img/13_balloon8.png

Wenn der Knopf gedrückt wird (Wert ist 1), hört der **Balloon1** Sprite auf, größer zu werden.

* Wenn die Größe kleiner als 90 ist, wird er fallen (y-Koordinate verringert sich).
* Wenn die Größe größer als 90 und kleiner als 120 ist, wird er zum Himmel fliegen (y-Koordinate erhöht sich).

.. image:: img/13_balloon9.png

Wenn der Knopf nicht gedrückt wurde, wird der Ballon langsam größer und wenn die Größe größer als 120 ist, wird er explodieren (wechseln Sie zum Explosions-Effekt-Kostüm).

.. image:: img/13_balloon10.png
