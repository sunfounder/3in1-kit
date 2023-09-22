.. _ar_fading:

2.1 Überblenden
=================

Dieses Projekt ähnelt :ref:`ar_blink`. Der Unterschied liegt in der Signalart.
Während das frühere Projekt die LED durch Ausgabe eines digitalen Signals (0&1) ein- oder ausschaltet, steuert dieses Projekt die Helligkeit der LED durch Ausgabe eines analogen Signals.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

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

    *   - KOMPONENTENVORSTELLUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

**Schaltplan**

.. image:: img/circuit_1.1_led.png

**Verdrahtung**

.. image:: img/wiring_led.png
    :width: 500
    :align: center

**Code**

.. note::

   * Sie können die Datei ``2.1.fading.ino`` im Pfad ``3in1-kit\basic_project\2.analogWrite\2.1.fading`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8a7e52a4-fcb3-4c3b-98ff-f3f657822d72/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, können Sie sehen, wie die LED atmet.
