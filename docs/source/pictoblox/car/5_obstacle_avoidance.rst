.. _sh_avoid1:

3.5 Hindernisvermeidung
==================================

Zwei Infrarot-Hindernisvermeidungsmodule sind an der Vorderseite des Autos montiert, die zur Erkennung einiger naher Hindernisse verwendet werden können.

In diesem Projekt darf das Auto frei vorwärts fahren und kann, wenn es auf ein Hindernis trifft, dieses umgehen und in andere Richtungen weiterfahren.

Benötigte Komponenten
------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen. Hier ist der Link:

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

    *   - KOMPONENTENEINFÜHRUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l298n` 
        - |link_l298n_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

Schaltung aufbauen
-----------------------

Das Hindernisvermeidungsmodul ist ein abstandseinstellbarer Infrarot-Näherungssensor, dessen Ausgang normalerweise hoch und bei Hinderniserkennung niedrig ist.

Bauen Sie nun die Schaltung gemäß dem untenstehenden Diagramm auf.

.. list-table:: 

    * - Linkes IR-Modul
      - R3 Board
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 

    * - Rechtes IR-Modul
      - R3 Board
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_avoid.jpg
    :width: 800

Modul einstellen
-----------------------

Bevor Sie mit dem Projekt beginnen, müssen Sie den Erkennungsabstand des Moduls einstellen.

Verkabeln Sie gemäß dem obenstehenden Diagramm, schalten Sie das R3-Board ein (entweder durch direktes Einstecken des USB-Kabels oder durch Anschließen des 9V-Batteriekabels), ohne den Code hochzuladen.

Platzieren Sie ein Notizbuch oder ein anderes flaches Objekt etwa 5 cm vor der IR-Hindernisvermeidung.

Verwenden Sie dann einen Schraubendreher, um das Potentiometer auf dem Modul zu drehen, bis die Signalanzeige auf dem Modul gerade aufleuchtet, um so seinen maximalen Erkennungsabstand von 5 cm einzustellen.

Verfolgen Sie die gleiche Methode, um ein weiteres Infrarot-Modul einzustellen.

.. image:: img/ir_obs_cali.jpg


Programmierung
-------------------

Das gewünschte Ergebnis:

* Wenn das linke IR-Modul ein Hindernis erkennt, fährt das Auto rückwärts nach links.
* Wenn das rechte IR-Modul ein Hindernis erkennt, fährt das Auto rückwärts nach rechts.
* Wenn beide IR-Module ein Hindernis erkennen, fährt das Auto direkt rückwärts.
* Andernfalls fährt das Auto vorwärts.

Erstellen Sie nun die entsprechenden Blöcke.

**1. Das Auto fährt rückwärts nach links**

Wenn sich der rechte Motor gegen den Uhrzeigersinn dreht und der linke Motor nicht dreht, wird das Auto rückwärts nach links fahren.

.. image:: img/5_avoid1.png

**2. Das Auto fährt rückwärts nach rechts**

Wenn sich der linke Motor im Uhrzeigersinn dreht und der rechte Motor nicht dreht, wird das Auto rückwärts nach rechts fahren.

.. image:: img/5_avoid2.png

**3. Das Auto fährt vorwärts, rückwärts und hält an**

.. image:: img/5_avoid3.png

**4. Die Werte der 2 IR-Module auslesen**

Klicken Sie in der **Variables**-Palette auf **Make a variable**.

.. image:: img/5_avoid4.png

Geben Sie den Variablennamen ein und klicken Sie auf **OK**, um eine neue Variable zu erstellen.

.. image:: img/5_avoid5.png

Lesen Sie die Werte der linken und rechten IR-Hindernisvermeidungsmodule aus und speichern Sie sie in den 2 neuen Variablen.

.. image:: img/5_avoid6.png

**5. Hindernisvermeidung**

* Wenn das linke IR-Modul 0 ist (Hindernis erkannt) und das rechte IR-Modul 1 ist, soll das Auto nach links zurückfahren.
* Wenn das rechte IR-Modul 0 ist (Hindernis erkannt), soll das Auto nach rechts zurückfahren.
* Wenn beide IR-Module gleichzeitig ein Hindernis erkennen, wird das Auto rückwärts fahren.
* Andernfalls wird das Auto weiterhin vorwärts fahren.

.. image:: img/5_avoid7.png
