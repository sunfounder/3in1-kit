.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_light_ball:

2.12 Lichtempfindlicher Ball
==============================

In diesem Projekt nutzen wir einen Fotowiderstand, um den Ball auf der Bühne nach oben fliegen zu lassen. Platzieren Sie Ihre Hand über dem Fotowiderstand, um die Lichtintensität zu steuern, die er erhält. Je näher Ihre Hand am Fotowiderstand ist, desto kleiner wird sein Wert und desto höher fliegt der Ball auf der Bühne, ansonsten fällt er. Wenn der Ball die Schnur berührt, ertönt ein angenehmes Geräusch und ein funkelndes Sternenlicht erscheint.

.. image:: img/18_ball.png

Was Sie lernen werden
------------------------

- Ein Sprite mit Farben zu füllen
- Berührung zwischen den Sprites

Benötigte Komponenten
------------------------

Für dieses Projekt benötigen wir folgende Komponenten:

Es ist definitiv praktisch, ein ganzes Kit zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können diese auch einzeln über die untenstehenden Links kaufen.

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

Schaltkreis aufbauen
-----------------------

Ein Fotowiderstand oder Fotodiode ist ein lichtgesteuerter variabler Widerstand. Der Widerstand eines Fotowiderstands verringert sich mit zunehmender Lichteinstrahlung.

Bauen Sie den Schaltkreis gemäß dem folgenden Diagramm auf.

Verbinden Sie ein Ende des Fotowiderstands mit 5V, das andere Ende mit A0 und schließen Sie einen 10K Widerstand in Reihe mit GND an diesem Ende an.

Wenn also die Lichtintensität zunimmt, verringert sich der Widerstand des Fotowiderstands, die Spannungsteilung des 10K Widerstands erhöht sich und der von A0 erhaltene Wert wird größer.

.. image:: img/circuit/photoresistor_circuit.png

Programmierung
------------------

Das gewünschte Ergebnis ist, dass, je näher Ihre Hand am Fotowiderstand ist, der Ball-Sprite auf der Bühne kontinuierlich nach oben geht, sonst fällt er auf den Bowl-Sprite. Wenn er beim Aufsteigen oder Fallen den Line-Sprite berührt, gibt er einen musikalischen Klang von sich und sendet Stern-Sprites in alle Richtungen.

**1. Sprite und Hintergrund auswählen**

Löschen Sie den Standard-Sprite und wählen Sie den **Ball**, **Bowl** und **Star** Sprite aus.

.. image:: img/18_ball1.png

Verschieben Sie den **Bowl** Sprite in die untere Mitte der Bühne und vergrößern Sie seine Größe.

.. image:: img/18_ball3.png

Da wir ihn nach oben bewegen müssen, setzen Sie die Richtung des **Ball** Sprites auf 0.

.. image:: img/18_ball4.png

Stellen Sie die Größe und Richtung des **Star** Sprites auf 180 ein, da er nach unten fallen muss, oder Sie können ihn in einen anderen Winkel ändern.

.. image:: img/18_ball12.png

Jetzt fügen Sie den **Stars** Hintergrund hinzu.

.. image:: img/18_ball2.png

**2. Einen Linien-Sprite zeichnen**

Fügen Sie einen Linien-Sprite hinzu.

.. image:: img/18_ball7.png

Gehen Sie zur **Costumes**-Seite des **Line** Sprites, verringern Sie die Breite der roten Linie auf der Leinwand etwas, kopieren Sie sie dann 5-mal und richten Sie die Linien aus.

.. image:: img/18_ball8.png

Jetzt füllen Sie die Linien mit verschiedenen Farben. Wählen Sie zuerst eine Farbe, die Ihnen gefällt, klicken Sie dann auf das **Fill**-Werkzeug und fahren Sie mit der Maus über die Linie, um sie zu füllen.

.. image:: img/18_ball9.png

Verfahren Sie auf die gleiche Weise, um die Farbe der anderen Linien zu ändern.

.. image:: img/18_ball10.png

**3. Skript für den Ball-Sprite**

Setzen Sie die Anfangsposition des **Ball** Sprites. Wenn der Lichtwert kleiner als 800 ist (es kann ein anderer Wert sein, abhängig von Ihrer aktuellen Umgebung), soll der Ball nach oben bewegen.

Sie können die Variable Lichtwert auf der Bühne anzeigen lassen, um die Lichtintensitätsänderung jederzeit zu beobachten.

.. image:: img/18_ball5.png

Andernfalls wird der **Ball** Sprite fallen und seine Y-Koordinate auf ein Minimum von -100 begrenzen. Dies kann angepasst werden, damit es so aussieht, als ob er auf den **Bowl** Sprite fällt.

.. image:: img/18_ball6.png

Wenn der **Line** Sprite getroffen wird, wird die aktuelle Y-Koordinate in die Variable **ball_coor** gespeichert und eine **Bling** Nachricht gesendet.

.. image:: img/18_ball11.png

**4. Skript für den Stern-Sprite**

Wenn das Skript startet, verstecken Sie zuerst den **Star** Sprite. Wenn die **Bling** Nachricht empfangen wird, klone den **Star** Sprite.

.. image:: img/18_ball13.png

Wenn der **Star** Sprite als Klon erscheint, spiele den Soundeffekt ab und setze seine Koordinaten synchron zum **Ball** Sprite.

.. image:: img/18_ball14.png

Erstelle den Effekt des erscheinenden **Star** Sprites und passe ihn bei Bedarf an.

.. image:: img/18_ball15.png
