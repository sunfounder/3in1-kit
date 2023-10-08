.. _sh_follow1:

3.4 Folge Deiner Hand
===========================

Stellen Sie sich dieses Auto hier als Ihr Haustier vor und wenn Sie ihm zuwinken, kommt es auf Sie zugelaufen.

Benötigte Komponenten
---------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen. Hier ist der Link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name
        - ARTIKEL IM SET
        - LINK
    *   - 3-in-1 Starter Set
        - 380+
        - |link_3IN1_kit|

Sie können die Teile auch einzeln über die folgenden Links erwerben:

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110` 
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

Schaltkreis aufbauen
-----------------------

Ein Ultraschallsensormodul ist ein Instrument, das den Abstand zu einem Objekt mit Hilfe von Ultraschallwellen misst.
Es verfügt über zwei Sonden. Eine dient zum Senden von Ultraschallwellen und die andere zum Empfangen der Wellen und zur Umwandlung der Sende- und Empfangszeit in eine Entfernung, wodurch der Abstand zwischen dem Gerät und einem Hindernis ermittelt wird.

Bauen Sie nun den Schaltkreis entsprechend dem folgenden Diagramm auf.

.. list-table:: 

    * - Ultraschallmodul
      - R3 Board
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

.. image:: img/car_6.png
    :width: 800

Programmierung
--------------

Erstellen Sie Blöcke, um das Auto vorwärts fahren und stoppen zu lassen.

.. image:: img/4_hand1.png

Halten Sie Ihre Hand vor das Auto und lesen Sie den Wert des Ultraschallmoduls. Wenn der erkannte Abstand Ihrer Hand zwischen 5-10 cm liegt, lassen Sie das Auto vorwärts fahren, ansonsten stoppen Sie es.

.. image:: img/4_hand2.png
