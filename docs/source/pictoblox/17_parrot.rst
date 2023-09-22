.. _sh_parrot:

2.17 SPIEL - Flappy Papagei
==============================

Hier verwenden wir das Ultraschallmodul, um ein Flappy-Papagei-Spiel zu spielen.

Nachdem das Skript ausgeführt wird, wird der grüne Bambus langsam von rechts nach links auf zufälliger Höhe bewegen. Platziere nun deine Hand über dem Ultraschallmodul. Wenn der Abstand zwischen deiner Hand und dem Modul weniger als 10 cm beträgt, fliegt der Papagei nach oben, sonst fällt er nach unten.
Du musst den Abstand zwischen deiner Hand und dem Ultraschallmodul kontrollieren, sodass der Papagei den grünen Bambus (Schläger) vermeiden kann. Berührt er diesen, ist das Spiel vorbei.

.. image:: img/15_parrot.png

Benötigte Komponenten
------------------------

Für dieses Projekt benötigen wir folgende Komponenten.

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

Du kannst sie auch einzeln über die folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

Schaltung aufbauen
-----------------------

Ein Ultraschall-Sensormodul ist ein Instrument, das den Abstand zu einem Objekt mithilfe von Ultraschallwellen misst.
Es hat zwei Sonden. Eine sendet Ultraschallwellen und die andere empfängt die Wellen und wandelt die Sendungs- und Empfangszeit in eine Entfernung um, um so den Abstand zwischen dem Gerät und einem Hindernis zu bestimmen.

Baue jetzt die Schaltung gemäß dem folgenden Diagramm.

.. image:: img/circuit/ultrasonic_circuit.png

Programmierung
------------------

Das gewünschte Ergebnis ist die Steuerung der Flughöhe des Sprites **Parrot** mithilfe des Ultraschallmoduls, während er den Sprite **Paddle** vermeidet.

**1. Füge einen Sprite hinzu**

Lösche den Standardsprite und verwende die Schaltfläche **Choose a Sprite**, um den Sprite **Parrot** hinzuzufügen. Setze seine Größe auf 50% und verschiebe seine Position zum linken Zentrum.

.. image:: img/15_sprite.png

Füge jetzt den Sprite **Paddle** hinzu, setze seine Größe auf 150%, setze seinen Winkel auf 180 und verschiebe seine Anfangsposition in die obere rechte Ecke.

.. image:: img/15_sprite1.png

Gehe zur **Costumes**-Seite des Sprites **Paddle** und entferne den Umriss.

.. image:: img/15_sprite2.png

**2. Skripting für den Papagei-Sprite**

Jetzt das Skript für den **Parrot**-Sprite schreiben, der fliegt und dessen Flughöhe durch die Erkennungsentfernung des Ultraschallmoduls bestimmt wird.

* Wenn auf die grüne Flagge geklickt wird, wechsle das Kostüm alle 0,2s, sodass es ständig fliegt.

.. image:: img/15_parr1.png

* Lies den Wert des Ultraschallmoduls und speichere ihn in der Variable **distance** nachdem er mit dem [round] Block gerundet wurde.

.. image:: img/15_parr2.png

* Wenn die Ultraschall-Erkennungsentfernung weniger als 10 cm beträgt, lass den y-Koordinatenwert um 50 erhöhen, dann wird der **Parrot**-Sprite nach oben fliegen. Andernfalls wird der y-Koordinatenwert um 40 verringert und der **Parrot** wird fallen.

.. image:: img/15_parr3.png

* Wenn der Sprite **Parrot** den Sprite **Paddle** berührt, endet das Spiel und das Skript hört auf zu laufen.

.. image:: img/15_parr4.png

**3. Skripting für den Schläger-Sprite**

Schreibe jetzt das Skript für den **Paddle**-Sprite, der zufällig auf der Bühne erscheinen muss.

* Verstecke den Sprite **Paddle**, wenn auf die grüne Flagge geklickt wird, und klone ihn gleichzeitig. Der [`create clone of <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_] Block ist ein Steuerblock und ein Stapelblock. Er erstellt einen Klon des Sprites im Argument. Er kann auch den Sprite klonen, in dem er läuft, und Klone von Klonen erstellen, rekursiv.

.. image:: img/15_padd.png

* Wenn **Paddle** als Klon dargestellt wird, beträgt seine Position 220 (ganz rechts) für die x-Koordinate und seine y-Koordinate liegt zufällig zwischen (-125 bis 125) (zufällige Höhe).

.. image:: img/15_padd1.png

* Verwende den [wiederholen] Block, um seinen x-Koordinatenwert langsam zu verringern. So siehst du den Klon des **Paddle**-Sprites, der langsam von rechts nach links bewegt wird, bis er verschwindet.

.. image:: img/15_padd2.png

* Klone einen neuen **Paddle**-Sprite und lösche den vorherigen Klon.

.. image:: img/15_padd3.png
