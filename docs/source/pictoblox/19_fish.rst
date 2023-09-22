.. _sh_fishing:

2.19 SPIEL - Angeln
===========================

Hier spielen wir ein Angelspiel mit einem Knopf.

Wenn das Skript läuft, schwimmen die Fische links und rechts auf der Bühne. Du solltest den Knopf drücken, wenn der Fisch fast nahe am Haken ist (es wird empfohlen, länger zu drücken), um den Fisch zu fangen. Die Anzahl der gefangenen Fische wird automatisch erfasst.

.. image:: img/18_fish.png

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

Du kannst sie auch separat über die untenstehenden Links kaufen.

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

Der Knopf ist ein 4-Pin-Gerät. Da Pin 1 mit Pin 2 und Pin 3 mit Pin 4 verbunden ist, werden beim Drücken des Knopfes alle 4 Pins miteinander verbunden, wodurch der Stromkreis geschlossen wird.

.. image:: img/5_buttonc.png

Baue die Schaltung gemäß dem folgenden Diagramm auf.

* Verbinde einen der Pins auf der linken Seite des Knopfes mit Pin 12, der mit einem Pull-Down-Widerstand und einem 0,1uF (104) Kondensator verbunden ist (um Zittern zu eliminieren und ein stabiles Signal zu liefern, wenn der Knopf betätigt wird).
* Verbinde das andere Ende des Widerstands und des Kondensators mit GND und einen der Pins auf der rechten Seite des Knopfes mit 5V.

.. image:: img/circuit/button_circuit.png

Programmierung
------------------

Zuerst müssen wir einen **Underwater**-Hintergrund auswählen, dann ein **Fish**-Sprite hinzufügen und es auf der Bühne hin und her schwimmen lassen. Zeichne dann ein **Fishhook**-Sprite und steuere es mit einem Knopf, um mit dem Angeln zu beginnen. Wenn das **Fisch**-Sprite den **Fishhook**-Sprite im gehakten Zustand (wird rot) berührt, wird es gehakt.

**1. Hintergrund hinzufügen**

Nutze die **Choose a Backdrop**-Schaltfläche, um einen **Underwater**-Hintergrund hinzuzufügen.

.. image:: img/18_under.png


**2. Angelhaken-Sprite**

Der **Fishhook**-Sprite bleibt normalerweise im gelben Zustand unter Wasser; wenn der Knopf gedrückt wird, befindet er sich im Angelzustand (rot) und bewegt sich über die Bühne.

In Pictoblox gibt es keinen **Fishhook**-Sprite, wir können den **Glow-J**-Sprite so modifizieren, dass er wie ein Angelhaken aussieht.

* Füge den **Glow-J**-Sprite über **Choose a Sprite** hinzu.

.. image:: img/18_hook.png

* Gehe jetzt zur **Costumes**-Seite des **Glow-J**-Sprites, wähle die Füllung von Cyan auf dem Bildschirm aus und entferne sie. Ändere dann die Farbe von J in Rot und verringere auch seine Breite. Der wichtigste Punkt ist, dass du die Spitze genau am Mittelpunkt haben musst.

.. image:: img/18_hook1.png

* Verwende das **Line tool**, um eine möglichst lange Linie vom Mittelpunkt nach oben zu zeichnen (Linie außerhalb der Bühne). Nachdem der Sprite gezeichnet wurde, benenne den Sprite in **Fishhook** um und verschiebe ihn an die richtige Position.

.. image:: img/18_hook2.png

* Wenn die grüne Flagge angeklickt wird, setze den Farbeffekt des Sprites auf 30 (gelb) und setze seine Anfangsposition.

.. image:: img/18_hook3.png

* Wenn der Knopf gedrückt wird, setze den Farbeffekt auf 0 (rot, Angelstartzustand), warte 0,1 Sekunden und bewege den **Fishhoo**-Sprite dann nach oben auf die Bühne. Lasse den Knopf los und lass den **Fishhoo** wieder in seine Anfangsposition zurückkehren.

.. image:: img/18_hook4.png

**3. Fisch-Sprite**

Der Effekt, den der **Fish**-Sprite erzielen soll, ist, sich links und rechts auf der Bühne zu bewegen, und wenn er einen **Fishhook**-Sprite im Angelzustand trifft, schrumpft er, bewegt sich an eine bestimmte Position und verschwindet dann und klont anschließend einen neuen **fish**-Sprite.

* Füge jetzt den **fish**-Sprite hinzu und passe seine Größe und Position an.

.. image:: img/18_fish1.png

* Erstelle eine Variable **score**, um die Anzahl der gefangenen Fische zu speichern, verberge diesen Sprite und klone ihn.

.. image:: img/18_fish2.png

* Zeige den Klon des **fish**-Sprites an, wechsle sein Kostüm und setze schließlich die Anfangsposition.

.. image:: img/18_fish3.png

* Lasse den Klon des **fish**-Sprites sich links und rechts bewegen und beim Berühren des Randes zurückprallen.

.. image:: img/18_fish4.png

* Der **fish**-Sprite (vom Klon) wird nicht reagieren, wenn er am **Fishhook**-Sprite vorbeigeht; berührt er jedoch den **Fishhook**-Sprite im Angelzustand (wird rot), wird er gefangen. Zu diesem Zeitpunkt wird der Punktestand (Variable Punktestand) +1 und es wird auch eine Punkteanimation angezeigt (schrumpft um 40%, bewegt sich schnell zur Position der Punkteanzeige und verschwindet). Gleichzeitig wird ein neuer Fisch erstellt (ein neuer Fisch-Sprite-Klon) und das Spiel geht weiter.

.. note::

    Du musst in den [Touch color]-Block im Farbbereich klicken und dann das Pipettenwerkzeug auswählen, um die rote Farbe des **Fishhook**-Sprites auf der Bühne aufzunehmen. Wenn du eine Farbe willkürlich wählst, wird dieser [Touch color]-Block nicht funktionieren.

.. image:: img/18_fish5.png

