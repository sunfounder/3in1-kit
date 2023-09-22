.. _sh_follow1:

3.4 Ihrer Hand folgen
===========================

Stellen Sie sich dieses Auto hier als Ihr Haustier vor. Wenn Sie ihm zuwinken, kommt es zu Ihnen gelaufen.

Benötigte Komponenten
--------------------------

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

Schaltung aufbauen
-----------------------

Ein Ultraschallsensormodul ist ein Instrument, das mithilfe von Ultraschallwellen die Entfernung zu einem Objekt misst. 
Es verfügt über zwei Sonden: Eine dient zum Senden von Ultraschallwellen und die andere zum Empfangen der Wellen. Dabei wird die Sende- und Empfangszeit in eine Entfernung umgewandelt, um so die Distanz zwischen dem Gerät und einem Hindernis zu ermitteln.

Bauen Sie nun die Schaltung gemäß dem folgenden Diagramm auf.

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

.. image:: img/car_ultrasonic.jpg
    :width: 800

Programmierung
--------------------

Erstellen Sie Blöcke, um das Auto vorwärts fahren zu lassen und anzuhalten.

.. image:: img/4_hand1.png

Halten Sie Ihre Hand vor das Auto und lesen Sie dann den Wert des Ultraschallmoduls aus. Wenn die erkannte Entfernung Ihrer Hand 5-10cm beträgt, lassen Sie das Auto vorwärts fahren, ansonsten stoppen Sie es.

.. image:: img/4_hand2.png
