.. _ar_reed:

3.2 Magnetismus spüren
===============================

Der gebräuchlichste Typ eines Reed-Schalters enthält ein Paar magnetisierbare, flexible Metallzungen, deren Enden durch eine kleine Lücke getrennt sind, wenn der Schalter offen ist.

Ein Magnetfeld von einem Elektromagneten oder einem Permanentmagneten bewirkt, dass sich die Zungen einander anziehen und somit einen elektrischen Stromkreis schließen.
Die Federkraft der Zungen führt dazu, dass sie sich trennen und den Stromkreis öffnen, wenn das Magnetfeld nachlässt.

Ein gängiges Beispiel für eine Anwendung eines Reed-Schalters ist die Erkennung des Öffnens einer Tür oder eines Fensters für eine Sicherheitsalarmanlage.

**Benötigte Komponenten**

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

Sie können diese auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_reed`
        - \-

**Schaltplan**

.. image:: img/circuit_3.2_reed.png

Standardmäßig ist Pin 2 niedrig; er wird hochschalten, wenn der Magnet in der Nähe des Reed-Schalters ist.

Der Zweck des 10K Widerstands besteht darin, Pin 2 auf einem stabilen niedrigen Niveau zu halten, wenn kein Magnet in der Nähe ist.

**Verkabelung**

.. image:: img/feel_the_magnetism_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

   * Sie können die Datei ``3.2.feel_the_magnetism.ino`` unter dem Pfad ``3in1-kit\basic_project\3.2.feel_the_magnetism`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/d28c942e-5144-44a1-85d8-d5e6894fc5df/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nach erfolgreichem Hochladen des Codes wird, wenn ein Magnet in der Nähe des Reed-Schalters ist, im seriellen Monitor eine 1 angezeigt.


