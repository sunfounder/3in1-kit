.. _sh_follow2:

3.6 Folge deiner Hand 2
==============================

Im :ref:`sh_follow1` Projekt wurde nur das Ultraschallmodul verwendet, es kann nur vorwärts deiner Hand folgen.

In diesem Projekt verwenden wir gleichzeitig 2 IR-Hindernisvermeidungsmodule, sodass das Auto deiner Hand nach links oder rechts folgen kann.

Benötigte Komponenten
-------------------------

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

Sie können diese auch einzeln über die untenstehenden Links kaufen.

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

Die Verkabelung zwischen dem Ultraschall und dem R3-Board ist wie folgt:

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

Die Verkabelung der 2 IR-Hindernisvermeidungsmodule zum R3-Board ist wie folgt:

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

Die in diesem Projekt zu erreichende Wirkung ist wie folgt:

* Das Ultraschall erkennt deine Hand etwa 5-10 cm vor sich und lässt das Auto folgen.
* Das Infrarotmodul links erkennt deine Hand und dreht sich nach links.
* Das rechte IR-Modul erkennt deine Hand und dreht sich nach rechts.

**1. Block erstellen**

Erstellen Sie Blöcke, die das Auto vorwärts bewegen, links abbiegen, rechts abbiegen und anhalten lassen.

.. image:: img/6_follow2_1.png

**2. Vorwärts folgen**

Lesen Sie den Ultraschallwert, und wenn Ihre Hand in einem Abstand von 5-10 cm erkannt wird, lassen Sie das Auto folgen.

.. image:: img/6_follow2_2.png

**3. Links und rechts folgen**

Lesen Sie die Werte der linken und rechten IR-Module.

* Wenn das linke IR-Modul Ihre Hand erkennt, drehen Sie sich nach links.
* Wenn das rechte IR-Modul Ihre Hand erkennt, drehen Sie sich nach rechts.
* Wenn weder das IR-Modul noch das Ultraschallmodul Ihre Hand erkennen, lassen Sie das Auto anhalten.

.. image:: img/6_follow2_3.png
