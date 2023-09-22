.. _sh_shooting:

2.13 SPIEL - Schießen
====================================

Haben Sie schon einmal diese Schießspiele im Fernsehen gesehen? Je näher ein Teilnehmer mit einer Kugel das Ziel am Bullseye trifft, desto höher ist seine Punktzahl.

Heute machen wir ebenfalls ein Schießspiel in Scratch. In diesem Spiel soll das Fadenkreuz so nah wie möglich am Bullseye schießen, um eine höhere Punktzahl zu erzielen.

Klicken Sie auf die grüne Flagge, um zu starten. Verwenden Sie das Hindernisvermeidungsmodul, um eine Kugel abzufeuern.

.. image:: img/14_shooting.png

Was Sie lernen werden
------------------------

- Wie das Hindernisvermeidungsmodul funktioniert und welcher Winkelbereich gegeben ist
- Verschiedene Sprites malen
- Farben berühren

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

    *   - KOMPONENTENVORSTELLUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

Schaltung aufbauen
-----------------------

Das Hindernisvermeidungsmodul ist ein infraroter Annäherungssensor mit einstellbarer Entfernung, dessen Ausgabe normalerweise hoch ist und auf niedrig schaltet, wenn ein Hindernis erkannt wird.

Bauen Sie die Schaltung jetzt gemäß dem untenstehenden Diagramm auf.

.. image:: img/circuit/avoid_circuit.png

Programmierung
------------------

**1. Das Fadenkreuz-Sprite malen**

Löschen Sie das Standard-Sprite, wählen Sie den **Sprite**-Button und klicken Sie auf **Paint**. Ein leeres Sprite namens **Sprite1** erscheint. Benennen Sie es in **Crosshair** um.

.. image:: img/14_shooting0.png

Gehen Sie zur **Costumes**-Seite des **Crosshair**-Sprites. Klicken Sie auf das **Circle**-Werkzeug, entfernen Sie die Füllfarbe und legen Sie die Farbe und Breite der Kontur fest.

.. image:: img/14_shooting02.png

Zeichnen Sie nun mit dem **Circle**-Werkzeug einen Kreis. Nach dem Zeichnen können Sie mit dem **Select**-Werkzeug den Kreis verschieben, sodass der Ursprungspunkt mit der Mitte der Leinwand ausgerichtet ist.

.. image:: img/14_shooting03.png

Verwenden Sie das **Line**-Werkzeug, um ein Kreuz innerhalb des Kreises zu zeichnen.

.. image:: img/14_shooting033.png

**Das Ziel-Sprite malen**

Erstellen Sie ein neues Sprite namens **Target**.

.. image:: img/14_shooting01.png

Gehen Sie zur Kostümseite des **Target**-Sprites, klicken Sie auf das **Circle**-Werkzeug, wählen Sie eine Füllfarbe aus, entfernen Sie die Kontur und malen Sie einen großen Kreis.

.. image:: img/14_shooting05.png

Verwenden Sie dieselbe Methode, um weitere Kreise mit jeweils unterschiedlichen Farben zu zeichnen, und Sie können die Position der überlappenden Kreise mit dem Werkzeug **Forward** oder **Backbard** ändern. Beachten Sie, dass Sie auch das Werkzeug zum Verschieben der Kreise auswählen müssen, damit der Ursprung aller Kreise und die Mitte der Leinwand ausgerichtet sind.

.. image:: img/14_shooting04.png

**3. Einen Hintergrund hinzufügen**

Fügen Sie einen geeigneten Hintergrund hinzu, der vorzugsweise nicht zu viele Farben hat und nicht mit den Farben im **Target**-Sprite übereinstimmt. Hier habe ich den Hintergrund **Wall1** gewählt.

.. image:: img/14_shooting06.png

**4. Script für das Fadenkreuz-Sprite**

Legen Sie die zufällige Position und Größe des **Crosshair**-Sprites fest und lassen Sie es sich zufällig bewegen.

.. image:: img/14_shooting4.png

Wenn eine Hand vor das Hindernisvermeidungsmodul gelegt wird, gibt es ein niedriges Signal als Übertragungssignal aus.

.. image:: img/14_shooting5.png

Wenn die **schießen**-Nachricht empfangen wird, stoppt das Sprite seine Bewegung und schrumpft langsam, wodurch der Effekt eines abgefeuerten Geschosses simuliert wird.

.. image:: img/14_shooting6.png

Verwenden Sie den [Touch color ()]-Block, um die Schussposition zu bestimmen.

.. image:: img/14_shooting7.png

Wenn der Schuss innerhalb des gelben Kreises liegt, werden 10 Punkte gemeldet.

.. image:: img/14_shooting8.png

Verwenden Sie dieselbe Methode, um die Position des abgefeuerten Geschosses zu bestimmen. Wenn es nicht auf dem **Target**-Sprite eingestellt ist, bedeutet dies, dass es außerhalb des Kreises liegt.

.. image:: img/14_shooting9.png
