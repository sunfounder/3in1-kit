.. _ar_ir_obstacle:

3.3 Hindernisse erkennen
===================================

Dieses Modul wird häufig in Autos und Robotern installiert, um das Vorhandensein von Hindernissen vor ihnen zu erkennen. Es findet auch breite Anwendung in Handgeräten, Wasserhähnen und weiteren.

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
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

**Schaltplan**

.. image:: img/circuit_3.3_obstacle.png

Der digitale Pin 2 wird verwendet, um das Signal des IR-Hindernisvermeidungsmoduls zu lesen. Das VCC des IR-Sensormoduls ist mit 5V verbunden, GND mit GND und OUT mit dem digitalen Pin 2.

**Verkabelung**

.. image:: img/detect_the_obstacle_bb.jpg
    :width: 800
    :align: center

**Code**

.. note::

   * Sie können die Datei ``3.3.detect_the_obstacle.ino`` unter dem Pfad ``3in1-kit\basic_project\3.3.detect_the_obstacle`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/535a0304-684e-481d-b85d-403911b3a4e2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Wenn das IR-Hindernisvermeidungsmodul ein Blockieren vor sich erkennt, wird auf dem seriellen Monitor [0] angezeigt. Andernfalls wird [1] angezeigt.
