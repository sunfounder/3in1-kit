.. _sh_avoid2:

3.7 Hindernisvermeidung 2
==================================

Im :ref:`sh_avoid1` Projekt werden lediglich 2 IR-Hindernisvermeidungsmodule zur Hinderniserkennung eingesetzt. Allerdings ist die Erkennungsreichweite des IR-Hindernisvermeidungsmoduls begrenzt, was dazu führen kann, dass das Auto möglicherweise zu spät reagiert, um Hindernissen auszuweichen.

In diesem Projekt fügen wir zusätzlich ein Ultraschallmodul hinzu, um Distanzen über eine längere Strecke zu erfassen. So kann das Auto Hindernisse aus größerer Entfernung wahrnehmen und entsprechend reagieren.

Benötigte Komponenten
-------------------------

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

Die einzelnen Komponenten können auch über die untenstehenden Links gekauft werden.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l298n` 
        - |link_l298n_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

Schaltkreis aufbauen
-----------------------

Verbinden Sie das Ultraschallmodul und die beiden IR-Hindernisvermeidungsmodule gleichzeitig.

Verdrahten Sie das Ultraschallmodul wie folgt mit dem R3-Board.

.. list-table:: 

    * - Ultraschallmodul
      - R3-Board
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND


Die Verdrahtung der beiden IR-Hindernisvermeidungsmodule mit dem R3-Board erfolgt wie folgt.

.. list-table:: 

    * - Linkes IR-Modul
      - R3-Board
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 

    * - Rechtes IR-Modul
      - R3-Board
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_avoid_ultrasonic.jpg
    :width: 800

Programmierung
---------------

**1. Funktion erstellen**

Das Auto vorwärts und rückwärts fahren lassen.

.. image:: img/7_avoid2_1.png

Lassen Sie das Auto nach links rückwärts und nach rechts rückwärts fahren.

.. image:: img/7_avoid2_2.png

Das Auto anhalten lassen.

.. image:: img/7_avoid2_3.png

**2. Notfall-Hindernisvermeidung**

Die beiden Infrarot-Hindernisvermeidungsmodule am Auto dienen der Notfall-Hindernisvermeidung und erkennen Hindernisse auf kurzen Distanzen, Ecken oder relativ kleine Hindernisse.

* Wenn das linke Infrarot-Modul ein Hindernis erkennt, fährt das Auto nach links zurück.
* Wenn das rechte IR-Modul ein Hindernis erkennt, weicht das Auto nach rechts hinten aus.
* Wenn beide Module gleichzeitig ein Hindernis erkennen, fährt das Auto direkt rückwärts.

.. image:: img/7_avoid2_4.png

**3. Hindernisvermeidung über lange Distanz**

Lese den Wert des Ultraschallmoduls. Wenn der erkannte Wert kleiner als 10 ist, fährt das Auto rückwärts; ansonsten fährt es weiter vorwärts.

.. image:: img/7_avoid2_5.png
