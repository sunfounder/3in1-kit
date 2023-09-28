.. _ar_if_else:

5.1 If else
==============

Normalerweise verwenden wir bedingte Urteile, um die grundlegendsten Realitätsinteraktionsprojekte abzuschließen.
Hier bauen wir ein Türerkennungssystem mit einem Reed-Schalter und einer LED, um diese Logik zu zeigen.

Befestigen Sie den Magneten auf einer Seite der Tür und den Reed-Schalter (mit Schaltung) auf der anderen Seite der Tür.
Wenn die Tür geschlossen ist, nähert sich der Magnet dem Reed-Schalter, der ihn einschaltet.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

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

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENVORSTELLUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_reed`
        - \-

**Schaltplan**

.. image:: img/circuit_8.1_ifelse.png

**Verdrahtung**

.. image:: img/5.1_if_else_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.1.if_else.ino`` im Pfad ``3in1-kit\learning_project\5.1.if_else``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c7bf6236-1276-45a0-8d34-008d2d838476/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, wird die LED leuchten, wenn Sie die Tür nicht schließen, um Sie daran zu erinnern, die Tür zu schließen.

Übrigens, wenn wir den umgekehrten Effekt benötigen (LED leuchtet, wenn die Tür geschlossen ist), müssen wir nur die Bedingung im ``if`` ändern.

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    Das ``if else`` ermöglicht eine größere Kontrolle über den Codefluss als die einfache if-Anweisung, indem mehrere Tests gruppiert werden können.
