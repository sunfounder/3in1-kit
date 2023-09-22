.. _sh_breakout_clone:

2.18 SPIEL - Breakout-Klon
============================

Hier verwenden wir das Potentiometer, um ein Breakout-Klon-Spiel zu spielen.

Nachdem Sie auf die grüne Flagge geklickt haben, müssen Sie das Potentiometer verwenden, um den Schläger auf der Bühne zu steuern, um den Ball zu fangen. Dadurch kann er nach oben steigen und die Ziegelsteine treffen. Wenn alle Ziegelsteine verschwinden, haben Sie gewonnen. Wenn Sie den Ball nicht fangen, haben Sie verloren.

.. image:: img/17_brick.png

Benötigte Komponenten
------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen, hier ist der Link:

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

Das Potentiometer ist ein Widerstandselement mit 3 Anschlüssen, die 2 seitlichen Pins sind mit 5V und GND verbunden, und der mittlere Pin ist mit A0 verbunden. Nach der Umwandlung durch den ADC-Wandler des Arduino-Boards liegt der Wertebereich zwischen 0-1023.

.. image:: img/circuit/potentiometer_circuit.png

Programmierung
------------------

Es gibt 3 Sprites auf der Bühne.

**1. Schläger-Sprite (Paddle sprite)**

Das Ziel des **Paddle** ist es, dass die Ausgangsposition in der Mitte des unteren Bühnenrandes liegt und durch ein Potentiometer gesteuert wird, um es nach links oder rechts zu bewegen.

* Löschen Sie den Standard-Sprite, verwenden Sie die Schaltfläche **Choose a Sprite**, um den **Paddle**-Sprite hinzuzufügen, und setzen Sie seine x- und y-Koordinaten auf (0, -140).

.. image:: img/17_padd1.png

* Gehen Sie zur Seite **Costumes**, entfernen Sie den Umriss und ändern Sie seine Farbe in dunkelgrau.

.. image:: img/17_padd3.png

* Jetzt skripten Sie den **Paddle**-Sprite, um seine Anfangsposition auf (0, -140) zu setzen, wenn die grüne Flagge angeklickt wird, und lesen Sie den Wert von A0 (Potentiometer) in die Variable **a0**. Da der **Paddle**-Sprite sich von links nach rechts auf der Bühne bei x-Koordinaten -195~195 bewegt, müssen Sie den [map] Block verwenden, um den Bereich der Variable **a0** von 0~1023 auf -195~195 abzubilden.

.. image:: img/17_padd2.png

* Jetzt können Sie das Potentiometer drehen und überprüfen, ob der **Paddle** sich links und rechts auf der Bühne bewegen kann.


**2. Ball-Sprite**

Der Ball-Sprite soll sich auf der Bühne bewegen und abprallen, wenn er den Rand berührt. Er prallt nach unten ab, wenn er den Block oberhalb der Bühne berührt. Er prallt nach oben ab, wenn er während des Fallens den Paddle-Sprite berührt. Tut er das nicht, wird das Skript gestoppt und das Spiel endet.

* Fügen Sie den **Ball**-Sprite hinzu.

.. image:: img/17_ball1.png

* Wenn auf die grüne Flagge geklickt wird, setzen Sie den Winkel des **Ball**-Sprites auf 45° und die Anfangsposition auf (0, -120).

.. image:: img/17_ball2.png

* Lassen Sie den **Ball**-Sprite sich auf der Bühne bewegen und abprallen, wenn er den Rand berührt. Klicken Sie auf die grüne Flagge, um den Effekt zu sehen.

.. image:: img/17_ball3.png

* Wenn der **Ball**-Sprite den **Paddle**-Sprite berührt, führen Sie eine Reflexion durch. Der einfache Weg, dies zu tun, ist, den Winkel direkt umzukehren. Dann werden Sie jedoch feststellen, dass der Pfad des Balls völlig festgelegt ist, was zu langweilig ist. Daher verwenden wir das Zentrum der beiden Sprites, um den Ball in die entgegengesetzte Richtung des Zentrums der Abschirmung abprallen zu lassen.

.. image:: img/17_ball4.png

.. image:: img/17_ball6.png

* Wenn der **Ball**-Sprite an den Rand der Bühne fällt, wird das Skript gestoppt und das Spiel endet.

.. image:: img/17_ball5.png


**3. Block1-Sprite**

Der **Block1**-Sprite soll mit dem Effekt erscheinen, 4x8 Klone von sich selbst in einer zufälligen Farbe oberhalb der Bühne zu erstellen und einen Klon zu löschen, wenn er vom **Ball**-Sprite berührt wird.

Der **Block1**-Sprite ist nicht in der **PictoBlox**-Bibliothek verfügbar. Sie müssen ihn selbst zeichnen oder mit einem vorhandenen Sprite modifizieren. Hier werden wir ihn mit dem **Button3**-Sprite modifizieren.

* Nachdem Sie den **Button3**-Sprite hinzugefügt haben, gehen Sie zur Seite **Costumes**. Löschen Sie zuerst **button-a**, verkleinern Sie dann sowohl die Breite als auch die Höhe von **button-b** und ändern Sie den Sprite-Namen in **Block1**, wie im folgenden Bild gezeigt.

.. note::

    * Für die Breite von **Block1** können Sie wahrscheinlich auf dem Bildschirm simulieren, um zu sehen, ob Sie 8 in einer Reihe platzieren können. Wenn nicht, reduzieren Sie die Breite entsprechend.
    * Beim Verkleinern des **Block1**-Sprites müssen Sie den Mittelpunkt in der Mitte des Sprites halten.

.. image:: img/17_bri2.png

* Erstellen Sie jetzt zuerst 2 Variablen, **block**, um die Anzahl der Blöcke und **roll**, um die Anzahl der Reihen zu speichern.

.. image:: img/17_bri3.png

* Wir müssen einen Klon des **Block1**-Sprites erstellen, damit er von links nach rechts, von oben nach unten, eins nach dem anderen, insgesamt 4x8 mit zufälligen Farben angezeigt wird.

.. image:: img/17_bri4.png

* Nachdem das Skript geschrieben wurde, klicken Sie auf die grüne Flagge und schauen Sie sich die Anzeige auf der Bühne an. Wenn es zu kompakt oder zu klein ist, können Sie die Größe ändern.

.. image:: img/17_bri5.png

* Schreiben Sie nun das Auslöseereignis. Wenn der geklonte **Block1**-Sprite den **Ball**-Sprite berührt, löschen Sie den Klon und senden Sie die Nachricht **crush**.

.. image:: img/17_bri6.png

* Gehen Sie zurück zum **Ball**-Sprite. Wenn die Übertragung **crush** empfangen wird (der **Ball**-Sprite berührt den Klon des **Block1**-Sprites), wird der **Ball** aus der entgegengesetzten Richtung abgeschossen.

.. image:: img/17_ball7.png






