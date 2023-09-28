.. _ar_joystick:

4.3 Den Joystick betätigen
================================

Der Joystick sollte jedem, der regelmäßig Videospiele spielt, sehr vertraut sein.
Er wird normalerweise verwendet, um Charaktere zu bewegen oder den Bildschirm zu drehen.

Unsere Bewegungen können vom Joystick gelesen werden, der nach einem sehr einfachen Prinzip funktioniert.
Er besteht aus zwei Potentiometern, die senkrecht zueinander stehen.
Diese beiden Potentiometer messen den analogen Wert des Joysticks in vertikaler und horizontaler Richtung und erzeugen einen Wert (x,y) in einem planaren rechtwinkligen Koordinatensystem.

Dieses Kit enthält auch einen Joystick mit einem digitalen Eingang. Er wird aktiviert, wenn der Joystick gedrückt wird.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten:

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

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_joystick`
        - \-

**Schaltplan**

.. image:: img/circuit_5.3_joystick.png

.. note::
    Der SW-Pin ist mit einem 10K-Pull-up-Widerstand verbunden,
    der Grund dafür ist, um einen stabilen hohen Pegel am SW-Pin (Z-Achse) zu erhalten, wenn der Joystick nicht gedrückt ist;
    ansonsten befindet sich der SW in einem Schwebezustand und der Ausgangswert kann zwischen 0/1 variieren.

**Verdrahtung**

.. image:: img/4.3_toggle_the_joystick_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``4.3.toggle_the_joystick.ino`` im Pfad ``3in1-kit\learning_project\4.3.toggle_the_joystick``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f678a03f-546c-42ed-bfae-b8c7daa5eec9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Öffnen Sie nach erfolgreichem Hochladen des Codes den seriellen Monitor, um die x,y,z-Werte des Joysticks zu sehen.

* Die Werte der x-Achse und y-Achse sind analoge Werte, die von 0 bis 1023 variieren.
* Die Z-Achse ist ein digitaler Wert mit einem Status von 1 oder 0 (wenn gedrückt, ist es 0).
