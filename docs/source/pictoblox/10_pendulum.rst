.. _sh_pendulum:

2.10 Pendel
=====================

In diesem Projekt erstellen wir ein Pfeilpendel, während der Servo der Drehung folgt.

.. image:: img/12_pun.png

Was Sie lernen werden
------------------------

- Wie der Servo funktioniert und welchen Drehwinkelbereich er hat
- Ein Sprite zeichnen und den Mittelpunkt am Ende setzen.

Benötigte Komponenten
------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Kit zu kaufen. Hier ist der Link:

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo` 
        - |link_servo_buy|

Schaltung aufbauen
-----------------------

Ein Servo ist ein Zahnradmotor, der sich nur um 180 Grad drehen kann. Er wird durch das Senden von elektrischen Pulsen von Ihrer Schaltung gesteuert. Diese Pulse geben dem Servo die Position vor, in die er sich bewegen soll.

Der Servo hat drei Kabel: Das braune Kabel ist GND, das rote ist VCC (an 3.3V anschließen) und das orange ist das Signalkabel. Der Drehwinkelbereich liegt bei 0-180 Grad.

Bauen Sie den Schaltkreis gemäß dem folgenden Diagramm.

.. image:: img/circuit/servo_circuit.png

Programmierung
------------------

**1. Ein Sprite malen**

Löschen Sie das Standard-Sprite, wählen Sie den Sprite-Button und klicken Sie auf **Paint**. Ein leeres Sprite namens **Sprite1** wird angezeigt.

.. image:: img/12_paint1.png

Auf der geöffneten **Costumes**-Seite verwenden Sie das **Line tool**, um einen Pfeil zu zeichnen.

.. note::

    * Beginnen Sie, den Pfeil von der Mitte der Leinwand aus zu zeichnen, damit sich der Pfeil mit dem Mittelpunkt als Ursprung im Kreis dreht.
    * Halten Sie die Umschalttaste gedrückt, um den Linienwinkel gerade oder 45 Grad zu machen.

.. image:: img/12_paint2.png

Nach dem Zeichnen wird das **arrow**-Sprite auf der Bühne angezeigt. Nennen Sie es **arrow**. Klicken Sie dann auf die Nummer nach **Direction**. Ein kreisförmiges Zifferblatt erscheint. Ziehen Sie jetzt diesen Pfeil und prüfen Sie, ob das **arrow**-Sprite auf der Bühne sich mit dem Ende als Ursprung dreht.

.. image:: img/12_paint3.png

Damit das **arrow**-Sprite von links nach rechts schwingt, liegt der Winkelbereich bei -90 bis -180, 180 bis 90.

.. image:: img/12_paint4.png

.. image:: img/12_paint5.png

**2. Eine Variable erstellen**.

Erstellen Sie eine Variable namens **servo**, die den Winkelwert speichert und setzen Sie den Anfangswert auf 270.

.. image:: img/12_servo.png

**3. Von links nach rechts schwingen**

Lassen Sie das **arrow**-Sprite nun von der linken -90-Grad-Position zur rechten 90-Grad-Position schwingen.

Mit dem [repeat]-Block fügen Sie bei jedem Durchlauf -10 zum Variablenwert hinzu und erreichen nach 18 Durchläufen 90 Grad. Verwenden Sie dann den [point in block]-Block, damit sich das Pfeil-Sprite zu diesen Winkeln dreht.

Da der Drehwinkel des Sprites -180 ~ 180 beträgt, werden Winkel außerhalb dieses Bereichs durch die folgenden Bedingungen konvertiert.

* Wenn Winkel > 180, dann Winkel - 360.

.. image:: img/12_servo1.png

**4. Den Servo drehen**

Wenn Sie auf die grüne Flagge klicken, sehen Sie, dass der Pfeil schnell nach rechts und dann wieder nach links dreht. Verwenden Sie hier einen [wait seconds]-Block, um die Drehung zu verlangsamen. Verwenden Sie auch den [set servo on to angle]-Block, um den mit dem Arduino-Board verbundenen Servo auf einen bestimmten Winkel zu drehen.

.. image:: img/12_servo2.png

**5. Von rechts nach links schwingen**

Auf die gleiche Weise lassen Sie den Servo und das **arrow**-Sprite langsam von rechts nach links drehen.

* Wenn Winkel > 180, dann Winkel - 360.

.. image:: img/12_servo3.png

