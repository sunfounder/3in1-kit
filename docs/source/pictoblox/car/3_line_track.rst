.. _sh_line:

3.3 Der Linie folgen
======================

Das Auto ist mit einem Linienverfolgungsmodul ausgestattet, mit dem das Auto der schwarzen Linie folgen kann.

Bevor Sie mit dem Projekt beginnen, sollten Sie eine Kurvenkarte mit schwarzem Linienband erstellen. Die empfohlene Linienbreite liegt zwischen 0,8-1,5 cm, und der Drehwinkel sollte nicht weniger als 90 Grad betragen.

Benötigte Komponenten
------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

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
    *   - :ref:`cpn_track`
        - |link_track_buy|

Schaltung aufbauen
-----------------------

Es handelt sich um ein digitales Linienverfolgungsmodul. Wenn eine schwarze Linie erkannt wird, gibt es den Wert 1 aus; bei Erkennung einer weißen Linie den Wert 0. Zudem können Sie die Erfassungsentfernung über das Potentiometer am Modul anpassen.

Bauen Sie die Schaltung gemäß dem folgenden Diagramm auf.

.. list-table:: 

    * - Linienverfolgungsmodul
      - R3 Board
    * - S
      - 2
    * - V+
      - 5V
    * - G
      - GND

.. image:: img/car_track.jpg
    :width: 800

Das Modul einstellen
-----------------------

Bevor Sie mit dem Projekt beginnen, müssen Sie die Empfindlichkeit des Moduls einstellen.

Verdrahten Sie gemäß dem obigen Diagramm, dann schalten Sie das R3-Board ein (entweder direkt über das USB-Kabel oder das 9V-Batterie-Steckkabel), ohne den Code hochzuladen.

Kleben Sie ein schwarzes Isolierband auf den Tisch und stellen Sie den Wagen darauf.

Beobachten Sie die Signalleuchtdiode am Modul und stellen Sie sicher, dass sie auf dem weißen Tisch leuchtet und auf dem schwarzen Band erlischt.

Wenn dies nicht der Fall ist, müssen Sie das Potentiometer am Modul so einstellen, dass es den oben beschriebenen Effekt erzielt.

.. image:: img/line_track_cali.JPG

Programmierung
-----------------

Erstellen Sie nun 2 Blöcke, die es dem Auto ermöglichen, entweder nach vorne links oder nach vorne rechts zu fahren.

**1. Nach vorne links fahren**

Wenn der rechte Motor im Uhrzeigersinn gedreht wird und der linke Motor unverändert bleibt, bewegt sich das Auto leicht nach vorne links.

.. image:: img/3_forward_left.png

**2. Nach vorne rechts fahren**

Ebenso bewegt sich das Auto leicht nach rechts, wenn der linke Motor gegen den Uhrzeigersinn gedreht wird und der linke Motor nicht bewegt wird.

.. image:: img/3_forward_left.png

**3. Linienverfolgung**

Lesen Sie den Wert des Linienverfolgungsmoduls. Wenn es 1 ist, bedeutet dies, dass eine schwarze Linie erkannt wurde. Lassen Sie das Auto nach links vorwärts fahren, andernfalls nach rechts vorwärts.

.. image:: img/3_follow.png

Nach dem Hochladen des Codes auf das R3-Board richten Sie das Linienverfolgungsmodul unter dem Auto auf die schwarze Linie aus, und Sie werden sehen, wie das Auto der Linie folgt.
