.. _ar_motor:

1.3 Das Rad drehen
============================

Ein Motor ist ein typisches digitales Ausgabegerät und wird genauso verwendet wie eine LED.
Der Motor muss jedoch mit einem hohen Strom betrieben werden, 
und der hohe Strom kann das Hauptsteuerungsboard wie das R4-Board beschädigen.
Deshalb wird bei dieser Gelegenheit ein Motor-Treibermodul verwendet,
welches eine große Hilfe für das R4-Board ist, um den Motor sicher zu steuern.

.. **Schaltbild**

.. .. image:: img/circuit_1.3_wheel.png

.. IN1~IN4 sind die Eingänge des L298N-Moduls und OUT1~OUT4 die Ausgänge.

.. Eine einfache Verwendungsmethode ist: Bei einem hohen Pegel für INx gibt OUTx ebenfalls einen hohen Pegel aus; Bei einem niedrigen Pegel für INx gibt OUTx einen niedrigen Pegel aus.
.. Verbindet man die beiden Enden des Motors mit OUT1 und OUT2 und gibt gegenläufige Pegelsignale für IN1 und IN2 ein, wird der Motor drehen. OUT3 und OUT4 können auf die gleiche Weise verwendet werden.

**Benötigte Komponenten**

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
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

**Schaltplan**

.. image:: img/circuit_1.3_wheel_l9110.png


**Verdrahtung**

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L9110S
      - R4-Board
      - Motor
    * - VCC
      - 5V
      - 
    * - GND
      - GND
      - 
    * - B-1B
      - 9
      -
    * - B-1A
      - 10
      - 
    * - OA
      - 
      - ein Draht des Motors
    * - OB
      - 
      - ein Draht des Motors

.. image:: img/1.3_turn_the_wheel_bb.png
    :width: 800
    :align: center

**Code**

.. note::

   * Sie können die Datei ``1.3.turn_the_wheel.ino`` unter dem Pfad ``3in1-kit\learning_project\1.3.turn_the_wheel`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/5f8e4f33-883b-4c06-9516-f1754ea2121d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
