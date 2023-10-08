.. _ar_pump:

1.4 Pumpen
===================

Die Wasserpumpe ist ebenfalls ein Motor, der durch eine spezielle Struktur die mechanische Energie des Motors oder andere externe Energien umwandelt, um die Flüssigkeit zu transportieren.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist sicherlich praktisch, ein komplettes Kit zu kaufen, hier ist der Link:

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

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_pump`
        - \-

**Schaltplan**

.. image:: img/circuit_1.3_wheel_l9110.png

**Verdrahtung**


.. image:: img/1.4_pumping_l9110_bb.png
    :width: 800
    :align: center


**Code**

.. note::

   * Sie können die Datei ``1.4.pumping.ino`` unter dem Pfad ``3in1-kit\basic_project\1.4.pumping`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f829508f-2475-4de6-bc2f-ab0a68d707b1/preview?F=undefined?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Fügen Sie den Schlauch zur Pumpe hinzu und platzieren Sie ihn im Becken. Nachdem der Code erfolgreich hochgeladen wurde, können Sie sehen, dass das Wasser im Becken nach einer Weile abgelassen wird.
Während dieses Experiments halten Sie bitte die Schaltung vom Wasser fern, um Kurzschlüsse zu vermeiden!
