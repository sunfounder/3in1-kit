.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_follow2:

3.6 Deiner Hand folgen 2
==============================

Im Projekt :ref:`sh_follow1` wird nur das Ultraschallmodul verwendet, wodurch das Auto nur vorwärts deiner Hand folgen kann.

In diesem Projekt verwenden wir gleichzeitig 2 IR-Hindernisvermeidungsmodule, sodass das Auto deiner Hand nach links oder rechts folgen kann.

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

Die Verdrahtung zwischen Ultraschall und R3-Board ist wie folgt:

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

Die Verdrahtung der 2 IR-Hindernisvermeidungsmodule zum R3-Board ist wie folgt:

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

Das gewünschte Ergebnis dieses Projekts:

* Ultraschall erkennt deine Hand etwa 5-10 cm vor sich und lässt das Auto folgen.
* Das linke Infrarot-Modul erkennt deine Hand und dreht sich nach links.
* Das rechte IR-Modul erkennt deine Hand und dreht sich nach rechts.

**1. Block erstellen**

Blöcke erstellen, die es dem Auto ermöglichen, vorwärts zu fahren, nach links und rechts abzubiegen und anzuhalten.

.. image:: img/6_follow2_1.png

**2. Zum Vorwärtsbewegen folgen**

Lese den Ultraschallwert und wenn deine Hand in einem Abstand von 5-10 cm erkannt wird, dann lass das Auto folgen.

.. image:: img/6_follow2_2.png

**3. Zum Links- und Rechtsdrehen folgen**

Lese die Werte der linken und rechten IR-Module.

* Wenn das linke IR-Modul deine Hand erkennt, drehe dich nach links.
* Wenn das rechte IR-Modul deine Hand erkennt, drehe dich nach rechts.
* Wenn weder das IR-Modul noch das Ultraschallmodul deine Hand erkennen, lass das Auto stehen.

.. image:: img/6_follow2_3.png
