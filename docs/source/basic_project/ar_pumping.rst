.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_pump:

1.4 Pumpen
===================

Die Wasserpumpe ist ebenfalls ein Motor, der durch eine spezielle Struktur die mechanische Energie des Motors oder eine andere externe Energie nutzt, um Flüssigkeit zu transportieren.

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
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_pump`
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
    * - B-1B(B-2A)
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
.. image:: img/1.4_pumping_bb.png
    :width: 800
    :align: center

**Code**

.. note::

   * Sie können die Datei ``1.4.pumping.ino`` unter dem Pfad ``3in1-kit\learning_project\1.4.pumping`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f829508f-2475-4de6-bc2f-ab0a68d707b1/preview?F=undefined?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Fügen Sie den Schlauch zur Pumpe hinzu und platzieren Sie ihn im Becken. Nachdem der Code erfolgreich hochgeladen wurde, werden Sie sehen, dass das Wasser im Becken nach einer Weile abgelassen wird.
Während dieses Experiments halten Sie bitte die Schaltung vom Wasser fern, um einen Kurzschluss zu vermeiden!
