.. _sh_dragon:

2.22 SPIEL - Drachen töten 
=========================== 

In diesem Spiel verwenden wir den Joystick, um einen Drachen zu bekämpfen.

Beim Klicken auf Grün wird der Drache rechts auf und ab schweben und intermittierend Feuer speien. Sie müssen den Joystick verwenden, um die Bewegung des Zauberstabs zu steuern und Sternenangriffe auf den Drachen zu starten, während Sie den von ihm abgefeuerten Flammen ausweichen und ihn schließlich besiegen.

.. image:: img/19_dragon.png 

Benötigte Komponenten
--------------------------

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

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENVORSTELLUNG 
        - KAUF-LINK 

    *   - :ref:`cpn_uno` 
        - |link_Uno_R3_buy| 
    *   - :ref:`cpn_wires` 
        - |link_wires_buy| 
    *   - :ref:`cpn_joystick` 
        - \- 

Schaltung aufbauen
-----------------------

Ein Joystick ist ein Eingabegerät, das aus einem Stick besteht, der auf einer Basis schwenkt und den Winkel oder die Richtung an das zu steuernde Gerät meldet. Joysticks werden häufig verwendet, um Videospiele und Roboter zu steuern.

Um einem Computer einen vollen Bewegungsbereich mitzuteilen, muss ein Joystick die Stickposition auf zwei Achsen messen - der X-Achse (links nach rechts) und der Y-Achse (oben nach unten).

Die Bewegungskoordinaten des Joysticks werden in der folgenden Abbildung gezeigt.

.. note:: 

    * Die x-Koordinate geht von links nach rechts, der Bereich liegt zwischen 0 und 1023.
    * Die y-Koordinate geht von oben nach unten, der Bereich liegt zwischen 0 und 1023.

.. image:: img/16_joystick.png 

Bauen Sie nun die Schaltung gemäß dem folgenden Diagramm.

.. image:: img/circuit/joystick_circuit.png 

Programmierung 
---------------- 

**1. Drache** 

**Woods**-Hintergrund hinzugefügt über den **Choose a Backdrop**-Knopf.

.. image:: img/19_dragon01.png 

* Löschen Sie das Standard-Sprite und fügen Sie das **Dragon**-Sprite hinzu.

.. image:: img/19_dragon0.png 

* Wechseln Sie zur **Costumes**-Seite und spiegeln Sie den Drachen-b und Drachen-c horizontal.

.. image:: img/19_dragon1.png 

* Stellen Sie die Größe auf 50% ein.

.. image:: img/19_dragon3.png 

* Erstellen Sie nun eine Variable - **dragon**, um die Lebenspunkte des Drachens aufzuzeichnen, und setzen Sie den Anfangswert auf 50.

.. image:: img/19_dragon2.png 

* Wechseln Sie als Nächstes das Kostüm des Sprites zu **dragon-b** und lassen Sie das **Dragon**-Sprite in einem bestimmten Bereich auf und ab bewegen.

.. image:: img/19_dragon4.png 

* Fügen Sie ein **Lightning**-Sprite als das vom **Dragon**-Sprite geblasene Feuer hinzu. Sie müssen es auf der Kostümseite um 90° im Uhrzeigersinn drehen, um das **Lightning**-Sprite in die richtige Richtung zu bewegen.

.. note:: 
    Beim Anpassen des **Lightning**-Sprites können Sie es möglicherweise aus der Mitte bewegen, was vermieden werden muss! Der Mittelpunkt muss genau in der Mitte des Sprites liegen!

.. image:: img/19_lightning1.png 



* Dann justiere das **dragon-c** Kostüm des **Dragon** Sprites, so dass sein Mittelpunkt am Schwanz des Feuers liegen sollte. Dies stellt sicher, dass die Positionen des **Dragon** Sprites und des **Lightning** Sprites korrekt sind und verhindert, dass der **Lightning** aus den Füßen des Drachen herausgeschossen wird. 

.. image:: img/19_dragon5.png

* Entsprechend muss bei **dragon-b** der Kopf des Drachen mit dem Mittelpunkt übereinstimmen.

.. image:: img/19_dragon5.png

* Passen Sie die Größe und Ausrichtung des **Lightning** Sprites an, um das Bild harmonischer wirken zu lassen.

.. image:: img/19_lightning3.png

* Jetzt das Skript für den **Lightning** Sprite erstellen. Das ist einfach, er sollte dem **Dragon** Sprite immer folgen. Zu diesem Zeitpunkt, wenn Sie auf die grüne Flagge klicken, werden Sie sehen, wie der **Dragon** sich mit einem Blitz im Mund bewegt.

.. image:: img/19_lightning4.png

* Zurück zum **Dragon** Sprite, lassen Sie ihn jetzt Feuer speien, wobei Sie darauf achten müssen, dass das Feuer nicht aus seinem Mund schießt, sondern einen Klon für den **Lightning** Sprite erstellt.

.. image:: img/19_dragon6.png

* Klicken Sie auf den **Lightning** Sprite und lassen Sie den **Lightning** Klon in einem zufälligen Winkel schießen. Er wird von der Wand abprallen und nach einer bestimmten Zeit verschwinden.

.. image:: img/19_lightning5.png

* Bei dem **Lightning** Sprite, verstecken Sie seinen Körper und zeigen den Klon.

.. image:: img/19_lightning6.png

Jetzt kann der Drache auf und ab bewegen und Feuer speien.

**2. Zauberstab**

* Erstellen Sie einen **Wand** Sprite und drehen Sie seine Richtung auf 180 Grad, um nach rechts zu zeigen.

.. image:: img/19_wand1.png

* Erstellen Sie jetzt eine Variable **hp**, um seinen Lebenswert zu erfassen, der zunächst auf 3 gesetzt wird. Dann lesen Sie den Wert des Joysticks, der zur Steuerung der Bewegung des Zauberstabs verwendet wird.

.. image:: img/19_wand2.png

* Der Drache hat Blitze und der Zauberstab, der ihn zerstört, hat seinen "magischen Schuss"! Erstellen Sie einen **Star** Sprite, verkleinern Sie ihn und lassen Sie ihn immer dem **Wand** Sprite folgen, wobei die Anzahl der Sterne auf drei begrenzt ist.

.. image:: img/19_star2.png

* Lassen Sie den **Wand** Sprite automatisch Sterne schießen. Der **Wand** Sprite schießt Sterne auf die gleiche Weise, wie der Drache Feuer speit – indem Klone erstellt werden.

.. image:: img/19_wand3.png

* Gehen Sie zurück zum **Star** Sprite und erstellen Sie ein Skript für seinen Klon, um sich drehend nach rechts zu schießen, verschwindet nach dem Verlassen der Bühne und stellt die Anzahl der Sterne wieder her. Wie beim **Lightning** Sprite, verstecken Sie den Körper und zeigen den Klon.

.. image:: img/19_star3.png

Jetzt haben wir einen Zauberstab, der Sternenkugeln schießt.

**3. Kampf!**

Der Zauberstab und der Drache stehen momentan noch im Widerspruch zueinander, und wir werden sie kämpfen lassen. Der Drache ist stark, und der Zauberstab ist der mutige Mann, der gegen den Drachen kämpft. Die Interaktion zwischen ihnen besteht aus den folgenden Teilen.

1. Wenn der Zauberstab den Drachen berührt, wird er zurückgestoßen und verliert Lebenspunkte.
2. Wenn ein Blitz den Zauberstab trifft, verliert der Zauberstab Lebenspunkte.
3. Wenn die Sternenkugel den Drachen trifft, verliert der Drache Lebenspunkte.

Sobald das geklärt ist, ändern wir die Skripte für jeden Sprite.

* Wenn der **Wand** den **Dragon** trifft, wird er zurückgestoßen und verliert Lebenspunkte.

.. image:: img/19_wand4.png

* Wenn **Lightning** (ein **Lightning** Sprite Klon) den **Wand** Sprite trifft, gibt er ein Knallgeräusch von sich und verschwindet, und der **Wand** verliert Lebenspunkte.

.. image:: img/19_lightning7.png

* Wenn ein **Star** (Klon des **Star** Sprites) den **Dragon** trifft, gibt er ein Sammelgeräusch von sich und verschwindet, stellt dabei die **Star** Anzahl wieder her, und der **Dragon** verliert Lebenspunkte.

.. image:: img/19_star4.png

**4. Bühne**

Die Schlacht zwischen dem **Wand** und dem **Dragon** wird letztlich in Gewinner und Verlierer unterteilt, was wir mit der Bühne darstellen.

* Fügen Sie den **Blue Sky** Hintergrund hinzu und schreiben Sie das Wort "GEWONNEN!" darauf, um zu zeigen, dass der Drache besiegt wurde und der Morgen angebrochen ist.

.. image:: img/19_sky0.png

* Und ändern Sie den leeren Hintergrund wie folgt, um zu zeigen, dass das Spiel verloren wurde und alles in Dunkelheit liegt.

.. image:: img/19_night.png

* Schreiben Sie jetzt ein Skript, um diese Hintergründe zu wechseln: Wenn die grüne Flagge angeklickt wird, wechseln Sie zum **Woods** Hintergrund; wenn die Lebenspunkte des Drachen weniger als 1 betragen, ist das Spiel gewonnen und wechselt zum **Blue Sky** Hintergrund; wenn die Lebenspunkte des **Wand** weniger als 1 betragen, wechseln Sie zum **Night** Hintergrund und das Spiel ist verloren.

.. image:: img/19_sky1.png

