.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_avoid2:

3.7 Hindernisvermeidung 2
==================================

Im Projekt :ref:`sh_avoid1` werden lediglich 2 IR-Hindernisvermeidungsmodule zur Hindernisvermeidung eingesetzt. Doch die Erkennungsreichweite des IR-Hindernisvermeidungsmoduls ist kurz, was dazu führen kann, dass das Auto zu spät reagiert, um Hindernissen auszuweichen.

In diesem Projekt fügen wir außerdem ein Ultraschallmodul für die Fernerkennung hinzu, sodass das Auto Hindernisse aus größerer Entfernung wahrnehmen und eine Entscheidung treffen kann.

Benötigte Komponenten
---------------------

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist definitiv praktisch, ein komplettes Set zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name
        - ARTIKEL IM SET
        - LINK
    *   - 3-in-1 Starter Set
        - 380+
        - |link_3IN1_kit|

Sie können die Teile auch einzeln über die folgenden Links erwerben:

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110` 
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

Schaltkreis aufbauen
-----------------------

Verbinden Sie das Ultraschallmodul und die beiden IR-Hindernisvermeidungsmodule gleichzeitig.

Die Verbindung des Ultraschallmoduls mit dem R3-Board ist wie folgt:

.. list-table:: 

    * - Ultraschall-Modul
      - R3-Board
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

Die Verbindung der beiden IR-Hindernisvermeidungsmodule mit dem R3-Board ist wie folgt:

.. list-table:: 

    * - Linkes IR-Modul
      - R3-Board
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 

    * - Rechtes IR-Modul
      - R3-Board
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_7_8.png
    :width: 800

Programmierung
---------------

**1. Funktion erstellen**

Lassen Sie das Auto vorwärts und rückwärts fahren.

.. image:: img/7_avoid2_1.png

Lassen Sie das Auto nach links hinten und nach rechts hinten fahren.

.. image:: img/7_avoid2_2.png

Lassen Sie das Auto stoppen.

.. image:: img/7_avoid2_3.png

**2. Notfall-Hindernisvermeidung**

Die beiden IR-Hindernisvermeidungsmodule am Auto werden für die Notfall-Hindernisvermeidung verwendet, um Hindernisse in kurzer Entfernung, Ecken oder relativ kleine Hindernisse zu erkennen.

* Wenn das linke Infrarot-Modul ein Hindernis erkennt, fährt das Auto rückwärts nach links.
* Wenn das rechte IR-Modul ein Hindernis erkennt, fährt das Auto rückwärts nach rechts.
* Wenn beide Module gleichzeitig ein Hindernis erkennen, fährt das Auto direkt rückwärts.

.. image:: img/7_avoid2_4.png

**3. Hindernisvermeidung über lange Strecken**

Lesen Sie den Wert des Ultraschallmoduls. Wenn der erkannte Wert kleiner als 10 ist, fährt das Auto rückwärts; ansonsten fährt es weiter vorwärts.

.. image:: img/7_avoid2_5.png
