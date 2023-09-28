.. _ar_potentiometer:

4.1 Den Knopf drehen
=======================

Ein Potentiometer ist ein Widerstandskomponente mit 3 Anschlüssen und sein Widerstandswert kann gemäß einer regelmäßigen Variation angepasst werden.

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
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**Schaltplan**

.. image:: img/circuit_5.1_potentiometer.png

In diesem Beispiel verwenden wir den analogen Pin (A0), um den Wert des Potentiometers zu lesen. Durch das Drehen der Achse des Potentiometers können Sie die Widerstandsverteilung zwischen diesen drei Pins ändern und so die Spannung am mittleren Pin ändern. Wenn der Widerstand zwischen dem mittleren und einem äußeren, mit 5V verbundenen Pin nahe Null liegt (und der Widerstand zwischen dem mittleren und dem anderen äußeren Pin nahe 10kΩ liegt), liegt die Spannung am mittleren Pin nahe 5V. Die umgekehrte Operation (der Widerstand zwischen dem mittleren und einem äußeren, mit 5V verbundenen Pin liegt nahe 10kΩ) wird die Spannung am mittleren Pin nahe 0V bringen.

**Verkabelung**

.. image:: img/4.1_turn_thek_knob_bb.png
    :width: 600
    :align: center

**Code**

.. note::

   * Sie können die Datei ``4.1.turn_the_knob.ino`` im Pfad ``3in1-kit\learning_project\4.1.turn_the_knob`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d931f2c9-74bc-4a53-8531-39a21a07dbaf/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nach dem Hochladen des Codes auf das Board können Sie den seriellen Monitor öffnen, um den gelesenen Wert des Pins zu sehen. Beim Drehen der Achse des Potentiometers wird der serielle Monitor den Wert 「0」~「1023」 ausgeben.
