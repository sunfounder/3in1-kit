.. _ar_ir_obstacle:

3.3 Hindernis erkennen
===================================

Dieses Modul wird häufig in Autos und Robotern installiert, um das Vorhandensein von Hindernissen vor ihnen zu erkennen. Zudem wird es weit verbreitet in Handgeräten, Wasserhähnen und dergleichen verwendet.

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
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

**Schaltplan**

.. image:: img/circuit_3.3_obstacle.png

Der digitale Pin 2 wird verwendet, um das Signal des IR-Hindernisvermeidungsmoduls zu lesen. Der VCC des IR-Sensor-Moduls wird an 5V angeschlossen, GND an GND und OUT an den digitalen Pin 2.

**Verdrahtung**

.. image:: img/3.3_detect_the_obstacle_bb.png
    :width: 800
    :align: center

**Code**

.. note::

   * Sie können die Datei ``3.3.detect_the_obstacle.ino`` im Pfad ``3in1-kit\learning_project\3.3.detect_the_obstacle`` öffnen. 
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/535a0304-684e-481d-b85d-403911b3a4e2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Wenn das IR-Hindernisvermeidungsmodul etwas registriert, das sich direkt davor befindet, wird [0] im seriellen Monitor angezeigt, andernfalls wird [1] dargestellt.
