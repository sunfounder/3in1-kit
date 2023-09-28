.. _ar_line_track:

3.4 Die Linie erkennen
===================================

Das Linienverfolgungsmodul wird verwendet, um festzustellen, ob es schwarze Bereiche auf dem Boden gibt, wie beispielsweise mit Isolierband aufgeklebte schwarze Linien.

Eine seiner LEDs sendet geeignetes Infrarotlicht auf den Boden. Die schwarze Oberfläche hat eine relativ starke Fähigkeit, Licht zu absorbieren und eine schwächere Reflexionsfähigkeit. Weiße Oberflächen sind das Gegenteil.
Wenn reflektiertes Licht erkannt wird, bedeutet dies, dass der Boden aktuell weiß ist. Wenn nicht erkannt, bedeutet es schwarz.

So funktioniert es.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_track`
        - |link_track_buy|

**Schaltplan**

.. image:: img/circuit_3.4_line.png

Der digitale Pin 2 wird verwendet, um das Signal des Linienverfolgungsmoduls zu lesen. Der VCC des Moduls wird an 5V angeschlossen, GND an GND und OUT an den digitalen Pin 2.

**Verdrahtung**

.. image:: img/3.4_detect_the_line_bb.png
    :width: 500
    :align: center

**Code**

.. note::

   * Sie können die Datei ``3.4.detect_the_line.ino`` im Pfad ``3in1-kit\learning_project\3.4.detect_the_line`` öffnen. 
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9795add6-c838-4a66-b484-0c39f252a7b4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Wenn das Linienverfolgungsmodul erkennt, dass eine schwarze Linie vorliegt, wird [1] im Serial Monitor angezeigt; andernfalls wird [0] dargestellt.
