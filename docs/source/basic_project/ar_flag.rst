.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_if_else:

5.1 If else
==============

Normalerweise nutzen wir bedingte Beurteilungen, um die einfachsten Interaktionsprojekte mit der Realität abzuschließen.
Hier erstellen wir ein Türerkennungssystem mit einem Reed-Kontakt und einer LED, um diese Logik zu zeigen.

Befestigen Sie den Magneten auf einer Seite der Tür und den Reed-Kontakt (mit Schaltung) auf der anderen Seite der Tür.
Wenn die Tür geschlossen ist, ist der Magnet dem Reed-Kontakt nahe und schaltet diesen ein.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_reed`
        - \-

**Schaltplan**

.. image:: img/circuit_8.1_ifelse.png

**Verkabelung**

.. image:: img/if_else_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.1.if_else.ino`` unter dem Pfad ``3in1-kit\basic_project\5.1.if_else``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c7bf6236-1276-45a0-8d34-008d2d838476/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem der Code erfolgreich hochgeladen wurde und wenn Sie die Tür nicht schließen, leuchtet die LED auf und fordert Sie auf, die Tür zu schließen.

Übrigens, wenn wir den entgegengesetzten Effekt möchten (LED leuchtet, wenn die Tür geschlossen ist), müssen wir nur die Bedingung im ``if`` ändern.

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    Das ``if else`` ermöglicht eine bessere Kontrolle über den Code-Fluss als die grundlegende if-Anweisung, indem mehrere Tests gruppiert werden können.
