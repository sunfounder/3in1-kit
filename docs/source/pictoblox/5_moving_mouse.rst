.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_moving_mouse:

2.5 Bewegende Maus
===================

Heute werden wir ein Mäusespielzeug erstellen, das mit einem Potentiometer gesteuert wird.

Wenn man auf die grüne Flagge klickt, bewegt sich die Maus auf der Bühne vorwärts. Dreht man am Potentiometer, ändert die Maus die Bewegungsrichtung.

.. image:: img/6_mouse.png

Was Sie lernen werden
------------------------

- Prinzip des Potentiometers
- Analogen Pin und dessen Bereich lesen
- Einen Bereich auf einen anderen abbilden
- Bewegen und Ändern der Richtung des Sprites

Benötigte Komponenten
------------------------

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein komplettes Kit zu kaufen, hier ist der Link:

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
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

Schaltung aufbauen
-----------------------

Das Potentiometer ist ein resistives Element mit 3 Anschlüssen. Die 2 seitlichen Pins werden an 5V und GND angeschlossen, und der mittlere Pin wird an A0 angeschlossen. Nach der Umwandlung durch den ADC-Konverter des Arduino-Boards liegt der Wertebereich zwischen 0-1023.

.. image:: img/circuit/potentiometer_circuit.png

Programmierung
------------------

**1. Wählen Sie einen Sprite**

Löschen Sie den Standard-Sprite, klicken Sie unten rechts im Sprite-Bereich auf die Schaltfläche **Choose a Sprite**, geben Sie **mouse** in das Suchfeld ein und klicken Sie dann, um ihn hinzuzufügen.

.. image:: img/6_sprite.png

**2. Eine Variable erstellen**

Erstellen Sie eine Variable namens **value**, um den gelesenen Wert des Potentiometers zu speichern.

Nach dem Erstellen sehen Sie **value** im **Variables**-Bereich und im markierten Zustand, was bedeutet, dass diese Variable auf der Bühne angezeigt wird.

.. image:: img/6_value.png

**3. Den Wert von A0 lesen**

Speichern Sie den gelesenen Wert von A0 in der Variable **value**.

* [set my variable to 0]: Den Wert der Variable festlegen.
* [read analog pin A0]: Den Wert von A0~A5 im Bereich von 0-1023 lesen.

.. image:: img/6_read_a0.png

Um durchgehend lesen zu können, müssen Sie den [forever]-Block verwenden. Klicken Sie auf dieses Skript, um es auszuführen, drehen Sie das Potentiometer in beide Richtungen, und Sie werden sehen, dass der Wertebereich 0-1023 beträgt.

.. image:: img/6_1023.png

**4. Den Sprite bewegen**

Verwenden Sie den [move steps]-Block, um den Sprite zu bewegen. Führen Sie das Skript aus, und Sie werden sehen, dass sich der Sprite von der Mitte nach rechts bewegt.

.. image:: img/6_move.png

**5. Die Richtung des Sprites ändern**

Ändern Sie nun die Bewegungsrichtung des Sprites entsprechend dem Wert von A0. Da der Wert von A0 von 0-1023 reicht, aber die Drehrichtung des Sprites von -180~180 ist, muss ein [map]-Block verwendet werden.

Fügen Sie auch [when green flag clicked] am Anfang hinzu, um das Skript zu starten.

* [`point in direction <https://en.scratch-wiki.info/wiki/Point_in_Direction_()_(block)>`_]: Den Lenkwinkel des Sprites festlegen, aus der **Bewegung**-Palette.
* [map from to]: Einen Bereich auf einen anderen abbilden.

.. image:: img/6_direction.png
