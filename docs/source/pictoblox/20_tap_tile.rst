.. _sh_tap_tile:

2.20 SPIEL - Klicke nicht auf das weiße Feld
===============================================

Viele von Ihnen haben dieses Spiel sicherlich schon auf Ihrem Handy gespielt. In diesem Spiel geht es darum, auf zufällig erscheinende schwarze Felder zu klicken, um Punkte zu sammeln. Die Geschwindigkeit erhöht sich stetig. Wenn man auf ein weißes Feld klickt oder ein schwarzes Feld verfehlt, ist das Spiel vorbei.

Jetzt replizieren wir es mit PictoBlox.

Setzen Sie zwei IR-Hindernisvermeidungsmodule vertikal auf das Steckbrett. Wenn Sie Ihre Hand über eines der IR-Module legen, erscheint ein blinkender Punkt auf der Bühne, der einen getätigten Klick darstellt.

Wenn Sie auf das schwarze Feld klicken, wird der Punktestand um 1 erhöht; berühren Sie das weiße Feld, wird der Punktestand um 1 verringert.

Je nach Position des schwarzen Blocks auf der Bühne müssen Sie entscheiden, ob Sie Ihre Hand über das linke oder das rechte IR-Modul legen.

.. image:: img/21_tile.png

Benötigte Komponenten
------------------------

Für dieses Projekt benötigen wir folgende Komponenten.

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
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

Schaltung aufbauen
-----------------------

Das Hindernisvermeidungsmodul ist ein infrarotbasierter Näherungssensor mit einstellbarer Entfernung, dessen Ausgang normalerweise hoch ist und niedrig wird, wenn ein Hindernis erkannt wird.

Bauen Sie die Schaltung entsprechend dem untenstehenden Diagramm.

.. image:: img/circuit/2avoid_circuit.png

Programmierung
------------------

Hier benötigen wir 3 Sprites: **Tile**, **Left IR** und **Right IR**.

* **Tile**-Sprite: Dient zur Darstellung von abwechselnd schwarzen und weißen Feldern, die nach unten gehen. In der Handy-Version dieses Spiels gibt es normalerweise 4 Spalten, hier machen wir nur zwei.
* **Left IR**-Sprite: Dient zur Darstellung des Klick-Effekts. Wenn das linke IR-Modul Ihre Hand erkennt, sendet es eine Nachricht - **left** an den **Left IR**-Sprite, um ihn zu aktivieren. Berührt er das schwarze Feld auf der Bühne, erhöht sich der Punktestand um 1, andernfalls verringert er sich um 1.
* **Right IR**-Sprite: Die Funktion ist im Wesentlichen die gleiche wie bei **Left IR**, außer dass er die Information **Right** erhält.

**1. Erstellen Sie ein Tile-Sprite**.

Löschen Sie das Standard-Sprite, bewegen Sie die Maus über das Symbol **Add Sprite**, wählen Sie **Paint** und ein leeres Sprite erscheint, welches Sie **Tile** nennen.

.. image:: img/21_tile1.png

Gehen Sie zur **Costumes**-Seite und verwenden Sie das **Rectangle**-Werkzeug, um ein Rechteck zu zeichnen.

.. image:: img/21_tile2.png

Wählen Sie das Rechteck aus und klicken Sie auf **Copy** -> **Paste**, um ein identisches Rechteck zu erstellen. Anschließend verschieben Sie die beiden Rechtecke so, dass sie bündig zueinander stehen.

.. image:: img/21_tile01.png

Wählen Sie eines der Rechtecke aus und wählen Sie eine schwarze Füllfarbe.

.. image:: img/21_tile02.png

Jetzt wählen Sie beide Rechtecke aus und verschieben Sie sie so, dass ihre Mittelpunkte mit dem Zentrum der Leinwand übereinstimmen.

.. image:: img/21_tile0.png

Duplizieren Sie das Kostüm1 und wechseln Sie die Füllfarben der beiden Rechtecke. Zum Beispiel hat Kostüm1 links die Füllfarbe Weiß und rechts die Füllfarbe Schwarz, bei Kostüm2 ist es umgekehrt.

.. image:: img/21_tile3.png


**2. Das Script für den Tile-Sprite erstellen**

Gehen Sie nun zurück zur **Blocks**-Seite und legen Sie die Anfangsposition des **Tile**-Sprites fest, damit dieser am oberen Bühnenrand positioniert ist.

.. image:: img/21_tile4.png

Erstellen Sie eine Variable - **blocks** und geben Sie ihr einen Startwert, um die Anzahl der Erscheinungen des **Tile**-Sprites zu bestimmen. Nutzen Sie den [Wiederhole bis]-Block, damit die Variable **blocks** stetig verringert wird, bis **blocks** 0 erreicht. Währenddessen sollte der Sprite **Tile** zufällig sein Kostüm wechseln.

Nachdem Sie auf die grüne Flagge geklickt haben, wird der **Tile**-Sprite auf der Bühne schnell die Kostüme wechseln.

.. image:: img/21_tile5.png

Erstellen Sie Klone des **Tile**-Sprites, während die Variable **blocks** abnimmt, und stoppen Sie das Skript, wenn blocks 0 ist. Hier werden zwei [wait () seconds]-Blöcke verwendet: Der erste begrenzt das Intervall zwischen **Tiles** Klonen und der zweite lässt die Variable blocks auf 0 sinken, ohne das Programm sofort zu stoppen, sodass dem letzten Tile-Sprite genügend Zeit zum Bewegen bleibt.

.. image:: img/21_tile6.png

Nun soll der Klon des **Tile**-Sprites langsam nach unten bewegen und gelöscht werden, sobald er den unteren Bühnenrand erreicht. Die Änderung in der y-Koordinate beeinflusst die Fallgeschwindigkeit: Je größer der Wert, desto schneller die Geschwindigkeit.

.. image:: img/21_tile7.png

Das Original verstecken und den Klon anzeigen.

.. image:: img/21_tile8.png

**3. Die Werte der 2 IR-Module auslesen**

Im Hintergrund lesen Sie die Werte der 2 IR-Module aus und führen die entsprechenden Aktionen durch.

* Wenn das linke IR-Hindernisvermeidungsmodul Ihre Hand erkennt, senden Sie eine Nachricht - **left**.
* Wenn das rechte IR-Hindernisvermeidungsmodul Ihre Hand erkennt, senden Sie eine Nachricht - **right**.

.. image:: img/21_tile9.png

**4. Left IR-Sprite**

Fahren Sie erneut mit der Maus über das **Add sprite**-Symbol und wählen Sie **Paint**, um einen neuen Sprite namens **Left IR** zu erstellen.

.. image:: img/21_tile10.png

Gehen Sie zur **Costumes**-Seite des **Left IR**-Sprites, wählen Sie eine Füllfarbe (eine beliebige Farbe außer Schwarz und Weiß) und zeichnen Sie einen Kreis.

.. image:: img/21_tile11.png

Beginnen Sie nun, den **Left IR**-Sprite zu scripten. Wenn die Nachricht - **left** empfangen wird (das IR-Empfängermodul links erkennt ein Hindernis), dann prüfen Sie, ob der schwarze Block des **Tile**-Sprites berührt wird, und wenn ja, erhöhen Sie die Variable **count** um 1, andernfalls verringern Sie sie um 1.

.. image:: img/21_tile12.png

.. note::

    Sie müssen den **Tile**-Sprite auf der Bühne anzeigen lassen und dann die Farbe des schwarzen Blocks im **Tile**-Sprite aufnehmen.

    .. image:: img/21_tile13.png

Führen Sie nun den Sensor-Effekt (Vergrößern/Verkleinern) für **Left IR** durch.

.. image:: img/21_tile14.png

Lassen Sie den **Left IR**-Sprite verstecken, wenn auf die grüne Flagge geklickt wird, zeigen Sie ihn an, wenn die Nachricht - **left** empfangen wird, und verstecken Sie ihn schließlich wieder.

.. image:: img/21_tile15.png

**5. Right IR-Sprite**

Kopieren Sie den **Left IR**-Sprite und benennen Sie ihn in **Right IR** um.

.. image:: img/21_tile16.png

Ändern Sie anschließend die empfangene Nachricht in - **right**.

.. image:: img/21_tile17.png

Nun sind alle Skripte fertig, und Sie können auf die grüne Flagge klicken, um das Skript auszuführen.
