.. _sh_star_crossed:

2.15 SPIEL - Sternengekreuzt
===============================

In den nächsten Projekten werden wir einige spaßige Minispiele in PictoBlox spielen.

Hier verwenden wir das Joystick-Modul, um das Spiel "Sternengekreuzt" zu spielen.

Nachdem das Skript gestartet wurde, erscheinen zufällig Sterne auf der Bühne. Mit dem Joystick steuern Sie das Raumschiff, um den Sternen auszuweichen. Wenn Sie sie berühren, endet das Spiel.

.. image:: img/16_rocket.png

Was Sie lernen werden
------------------------

- Wie das Joystick-Modul funktioniert
- Das Festlegen der x- und y-Koordinaten des Sprites

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

Sie können diese auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - \-

Schaltung aufbauen
-----------------------

Ein Joystick ist ein Eingabegerät, das aus einem Stick besteht, der auf einer Basis schwenkt und seinen Winkel oder seine Richtung an das zu steuernde Gerät meldet. Joysticks werden oft verwendet, um Videospiele und Roboter zu steuern.

Um dem Computer eine vollständige Bewegungsfreiheit zu melden, muss ein Joystick die Stickposition in zwei Achsen messen – der X-Achse (links nach rechts) und der Y-Achse (oben nach unten).

Die Bewegungskoordinaten des Joysticks sind in der folgenden Abbildung dargestellt.

.. note::

    * Die x-Koordinate geht von links nach rechts, der Bereich liegt zwischen 0-1023.
    * Die y-Koordinate geht von oben nach unten, Bereich 0-1023.

.. image:: img/16_joystick.png

Bauen Sie jetzt die Schaltung gemäß dem folgenden Diagramm.

.. image:: img/circuit/joystick_circuit.png

Programmierung
------------------
Das gesamte Skript soll den Effekt erzielen, dass bei Klick auf die grüne Flagge der **Stars**-Sprite in einer Kurve auf der Bühne bewegt wird und Sie den Joystick verwenden müssen, um das **Rocketship** zu bewegen, damit es nicht vom **Stars**-Sprite berührt wird.

**1. Sprites und Hintergründe hinzufügen**

Löschen Sie den Standard-Sprite und verwenden Sie die Schaltfläche **Choose a Sprite** zum Hinzufügen des **Rocketship**-Sprites und des **Star**-Sprites. Beachten Sie, dass die Größe des **Rocket**-Sprites auf 50% eingestellt ist.

.. image:: img/16_sprite.png

Fügen Sie jetzt den **Stars**-Hintergrund durch **Choose a Backdrop** hinzu.

.. image:: img/16_sprite1.png

**2. Skripting für Raumschiff**

Der **Rocketship**-Sprite soll den Effekt erzielen, dass er an einer zufälligen Position erscheint und dann durch den Joystick gesteuert wird, um ihn nach oben, unten, links und rechts zu bewegen.

Der Ablauf ist wie folgt.

* Wenn auf die grüne Flagge geklickt wird, lassen Sie den Sprite zu einer zufälligen Position gehen und erstellen Sie 2 Variablen **x** und **y**, die die Werte lesen, die von A0 (VRX des Joysticks) bzw. A1 (VRY des Joysticks) kommen. Sie können das Skript ausführen und den Joystick hoch und runter, links und rechts kippen, um den Wertebereich für x und y zu sehen.

.. image:: img/16_roc2.png

* Der Wert von A0 liegt im Bereich 0-1023 (die Mitte liegt bei etwa 512). Verwenden Sie ``x-512>200``, um festzustellen, ob der Joystick nach rechts gekippt wird, und wenn ja, lassen Sie die x-Koordinate des Sprites +30 sein (um den Sprite nach rechts zu bewegen).

.. image:: img/16_roc3.png

* Wenn der Joystick nach links gekippt wird (``x-512<-200``), lassen Sie die x-Koordinate des Sprites -30 sein (um den Sprite nach links zu bewegen).

.. image:: img/16_roc4.png

* Da die y-Koordinate des Joysticks von oben (0) nach unten (1023) geht und die y-Koordinate des Sprites von unten nach oben geht, muss die y-Koordinate im Skript -30 sein, um den Joystick nach oben und den Sprite nach oben zu bewegen.

.. image:: img/16_roc5.png

* Wenn der Joystick nach unten gekippt wird, ist die y-Koordinate des Sprites +30.

.. image:: img/16_roc6.png

**3. Skripting für Stern**

Der Effekt, den der **Star**-Sprite erzielen soll, ist, dass er an einer zufälligen Stelle erscheint, und wenn er das **Rocketship** trifft, stoppt das Skript und das Spiel endet.

* Wenn auf die grüne Flagge geklickt wird und der Sprite zu einer zufälligen Position geht, dient der Block [turn degrees] dazu, den **Star**-Sprite mit einer leichten Winkeländerung vorwärts zu bewegen, sodass Sie sehen können, dass er sich in einer Kurve bewegt, und wenn er am Rand ist, prallt er ab.

.. image:: img/16_star1.png

* Wenn der Sprite während seiner Bewegung den **Rocketship**-Sprite berührt, stoppen Sie das Skript.

.. image:: img/16_star2.png
