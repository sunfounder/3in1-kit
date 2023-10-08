.. _ar_line_track:

3.4 Linie erkennen
===================================

Das Linienverfolgungsmodul wird verwendet, um festzustellen, ob es schwarze Bereiche auf dem Boden gibt, wie zum Beispiel schwarze Linien, die mit Isolierband geklebt wurden.

Eine seiner LEDs sendet infrarotes Licht zum Boden, und die schwarze Oberfläche hat eine relativ starke Fähigkeit, Licht zu absorbieren und eine schwächere Reflexionsfähigkeit. Weiße Oberflächen verhalten sich genau umgekehrt.
Wenn reflektiertes Licht erkannt wird, bedeutet dies, dass der Boden aktuell weiß ist. Wird keines erkannt, ist er schwarz.

So funktioniert es.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können diese auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_track`
        - |link_track_buy|

**Schaltplan**

.. image:: img/circuit_3.4_line.png

Der digitale Pin 2 wird verwendet, um das Signal des Linienverfolgungsmoduls zu lesen. Das VCC des Moduls ist mit 5V verbunden, GND mit GND und OUT mit dem digitalen Pin 2.

**Verkabelung**

.. image:: img/detect_the_line_bb.jpg
    :width: 500
    :align: center

**Code**

.. note::

   * Sie können die Datei ``3.4.detect_the_line.ino`` unter dem Pfad ``3in1-kit\basic_project\3.4.detect_the_line`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9795add6-c838-4a66-b484-0c39f252a7b4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Wenn das Linienverfolgungsmodul eine schwarze Linie erkennt, wird [1] auf dem seriellen Monitor angezeigt. Andernfalls wird [0] dargestellt.
