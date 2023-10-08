.. _sh_protect_heart:

2.21 SPIEL - Schütze dein Herz
=====================================

In diesem Projekt erstellen wir ein Spiel, das die Reaktionsgeschwindigkeit testet.

Auf der Bühne befindet sich ein Herz, das in einem rechteckigen Kasten geschützt ist. Pfeile fliegen aus beliebigen Positionen auf dieser Bühne auf dieses Herz zu. Die Farbe des Pfeils wechselt zufällig zwischen Schwarz und Weiß, und der Pfeil wird immer schneller fliegen.

Wenn die Farbe des rechteckigen Kastens und die Farbe des Pfeils gleich sind, wird der Pfeil blockiert und die Stufe erhöht sich um 1. Sind die Farben jedoch nicht gleich, wird der Pfeil das Herz durchschießen und das Spiel ist vorbei.

Hier wird die Farbe des rechteckigen Kastens vom Linienverfolgungsmodul gesteuert. Wenn das Modul auf einer schwarzen Oberfläche (einer reflektierenden Oberfläche) platziert wird, ist die Farbe des rechteckigen Kastens schwarz, ansonsten weiß.

Sie müssen also entscheiden, ob Sie das Linienverfolgungsmodul auf einer weißen oder einer schwarzen Oberfläche platzieren, je nach Farbe des Pfeils.

.. image:: img/22_heart.png

Benötigte Komponenten
------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist sicherlich praktisch, ein komplettes Set zu kaufen. Hier ist der Link:

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

    *   - KOMPONENTENVORSTELLUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_track` 
        - |link_track_buy|

Schaltung aufbauen
-----------------------

Dies ist ein digitales Linienverfolgungsmodul. Wenn eine schwarze Linie erkannt wird, gibt es 1 aus; wenn eine weiße Linie erkannt wird, gibt es 0 aus. Zusätzlich können Sie den Erfassungsabstand über das Potentiometer auf dem Modul einstellen.

Bauen Sie den Schaltkreis jetzt gemäß dem untenstehenden Diagramm.

.. image:: img/circuit/linetrack_circuit.png

.. note::

    Bevor Sie mit dem Projekt beginnen, müssen Sie die Empfindlichkeit des Moduls anpassen.

    Verkabeln Sie gemäß dem obigen Diagramm und schalten Sie dann die R3-Platine ein (entweder direkt über das USB-Kabel oder das 9V-Batteriekabel). Laden Sie den Code nicht hoch.

    Kleben Sie nun ein schwarzes Elektroband auf den Schreibtisch und platzieren Sie das Linienverfolgungsmodul in einer Höhe von 2 cm vom Schreibtisch entfernt.

    Mit dem Sensor nach unten gerichtet, beobachten Sie die Signalled am Modul, um sicherzustellen, dass sie auf dem weißen Tisch leuchtet und auf dem schwarzen Band erlischt.

    Wenn nicht, müssen Sie das Potentiometer am Modul so einstellen, dass es den oben beschriebenen Effekt erzielt.

Programmierung
------------------

Hier müssen wir 3 Sprites erstellen: **Heart**, **Square Box** und **Arrow1**.

* **Heart**: bleibt in der Mitte der Bühne stehen. Wenn es vom **Arrow1**-Sprite berührt wird, ist das Spiel vorbei.
* **Square Box**: Hat zwei Arten von Kostümen, schwarz und weiß, und wechselt die Kostüme entsprechend dem Wert des Linienverfolgungsmoduls.
* **Arrow**: fliegt in Schwarz/Weiß aus irgendeiner Position auf die Mitte der Bühne zu; wenn seine Farbe mit der Farbe des **Square Box**-Sprites übereinstimmt, wird er blockiert und fliegt wieder aus einer zufälligen Position auf die Mitte der Bühne zu; stimmt seine Farbe nicht mit der Farbe des **Square Box**-Sprites überein, durchfliegt er das **Heart**-Sprite und das Spiel ist vorbei.

**1. Sprite Rechteckiger Kasten hinzufügen**

Da der Pfeil1 und das Sprite des rechteckigen Kastens beide weiße Kostüme haben, müssen sie, um auf der Bühne angezeigt zu werden, nun den Hintergrund mit einer Farbe füllen, die jede Farbe außer Schwarz, Weiß und Rot sein kann.

* Klicken Sie auf **Backdrop1**, um zu seiner **Backdrops**-Seite zu gelangen.
* Wählen Sie die gewünschte Füllfarbe aus.
* Verwenden Sie das **Rectangle**-Werkzeug, um ein Rechteck in der Größe des Zeichenbretts zu zeichnen.

.. image:: img/22_heart0.png


Löschen Sie das Standard-Sprite und verwenden Sie die Schaltfläche **Choose a Sprite**, um das **Square Box**-Sprite hinzuzufügen, und setzen Sie dessen x und y auf (0, 0).

.. image:: img/22_heart1.png

Gehen Sie zur **Costumes**-Seite des **Square Box**-Sprites und legen Sie die schwarz-weißen Kostüme fest.

* Klicken Sie auf das Auswahlinstrument
* Wählen Sie das Rechteck auf der Leinwand aus
* Wählen Sie die Füllfarbe Schwarz
* und nennen Sie das Kostüm **Black**

.. image:: img/22_heart2.png

Wählen Sie das zweite Kostüm aus, stellen Sie die Füllfarbe auf Weiß, nennen Sie es Weiß und löschen Sie die restlichen Kostüme.

.. image:: img/22_heart3.png

**2. Herz-Sprite hinzufügen**

Fügen Sie auch ein **Heart**-Sprite hinzu, setzen Sie seine Position auf (0, 0) und verkleinern Sie seine Größe, sodass es so aussieht, als ob es sich innerhalb des Quadrat-Kastens befindet.

.. image:: img/22_heart5.png

Auf der **Costumes**-Seite passen Sie das lila Herz-Kostüm an, damit es aussieht, als wäre es zerbrochen.

.. image:: img/22_heart6.png

**3. Arrow1-Sprite hinzufügen**

Fügen Sie ein **Arrow1**-Sprite hinzu.

.. image:: img/22_heart7.png

Auf der **Costumes**-Seite behalten und kopieren Sie das nach rechts gerichtete Kostüm und setzen Sie seine Farbe auf Schwarz und Weiß.

.. image:: img/22_heart8.png

**4. Skripterstellung für das Quadrat-Kasten-Sprite**

Gehen Sie zurück zur **Blocks**-Seite und scripten Sie das **Square Box**-Sprite.

* Wenn der Wert des digitalen Pins 2 (Linienverfolgungsmodul) 1 ist (schwarze Linie erkannt), wechseln Sie das Kostüm zu **Black**.
* Andernfalls wechseln Sie das Kostüm zu **White**.

.. image:: img/22_heart4.png

**5. Skripterstellung für das Herz-Sprite**

Das **Heart**-Sprite wird im **Square Box** geschützt und hat standardmäßig ein rotes Kostüm. Wenn das Arrow1-Sprite berührt wird, endet das Spiel.

.. image:: img/22_heart9.png

**6. Skripterstellung für das Arrow1-Sprite**

Lassen Sie das **Arrow1**-Sprite verstecken und einen Klon erstellen, wenn die grüne Flagge angeklickt wird.

.. image:: img/22_heart10.png

Erstellen Sie einen [init]-Block, um die Position, Orientierung und Farbe des **Arrow1**-Sprites zu initialisieren.

Es erscheint an einer zufälligen Position, und wenn der Abstand zwischen ihm und dem **Heart**-Sprite weniger als 200 beträgt, bewegt es sich nach außen, bis der Abstand größer als 200 ist.

.. image:: img/22_heart11.png

Richten Sie seine Richtung auf das **Heart**-Sprite aus.

.. image:: img/22_heart12.png

Lassen Sie seine Farbe zufällig zwischen Schwarz/Weiß wechseln.

* Ist die Variable Farbe 0, wechseln Sie das Kostüm zu **White**.
* Ist die Variable Farbe 1, wechseln Sie das Kostüm zu **Black**.

.. image:: img/22_heart14.png

Lassen Sie es jetzt bewegen, es wird schneller bewegen, wenn der Wert der Variable **level** zunimmt.

.. image:: img/22_heart13.png

Legen Sie jetzt seinen Kollisions-Effekt mit dem **Square Box**-Sprite fest.

* Wenn das **Arrow1**-Sprite und das **Square Box**-Sprite dieselbe Farbe haben (die gemäß dem Wert des Linienverfolgungsmoduls geändert wird), entweder Schwarz oder Weiß, wird ein neuer Klon erstellt und das Spiel geht weiter.
* Stimmen ihre Farben nicht überein, bewegt sich das **Arrow1**-Sprite weiter und das Spiel endet, wenn es das **Heart**-Sprite trifft.

.. image:: img/22_heart15.png

.. note::
    Die beiden [touch color()]-Blöcke müssen die schwarz-weißen Kostüme von Quadrat-Kasten separat aufnehmen.

    .. image:: img/22_heart16.png

