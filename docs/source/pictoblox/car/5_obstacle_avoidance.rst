.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_avoid1:

3.5 Hindernisvermeidung
==================================

Am Auto sind zwei Infrarot-Hindernisvermeidungsmodule montiert, mit denen nahegelegene Hindernisse erkannt werden können.

In diesem Projekt darf das Auto frei vorwärts fahren und kann beim Erkennen eines Hindernisses ausweichen und in andere Richtungen weiterfahren.

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
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

Schaltkreis aufbauen
-----------------------

Das Hindernisvermeidungsmodul ist ein infrarotgesteuerter Näherungssensor mit einstellbarer Distanz, dessen Ausgang normalerweise hoch ist und bei Erkennung eines Hindernisses niedrig wird.

Bauen Sie nun den Schaltkreis entsprechend dem untenstehenden Diagramm auf.

.. list-table:: 

    * - Linkes IR-Modul
      - R3 Board
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 

    * - Rechtes IR-Modul
      - R3 Board
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_5.png
    :width: 800

Das Modul einstellen
-----------------------

Vor Projektbeginn müssen Sie die Erfassungsdistanz des Moduls anpassen.

Verdrahten Sie entsprechend dem obigen Diagramm, schalten Sie das R3-Board ein (entweder durch direktes Einstecken des USB-Kabels oder durch Anschließen des 9V-Batteriekabels) und laden Sie den Code noch nicht hoch.

Platzieren Sie ein Notizbuch oder ein anderes flaches Objekt etwa 5 cm vor der IR-Hindernisvermeidung.

Dann verwenden Sie einen Schraubendreher, um das Potentiometer am Modul zu drehen, bis die Signalleuchte am Modul gerade leuchtet, um die maximale Erfassungsdistanz von 5 cm einzustellen.

Verfahren Sie auf die gleiche Weise, um ein weiteres Infrarot-Modul anzupassen.

.. image:: img/ir_obs_cali.jpg

Programmierung
---------------

Das gewünschte Ergebnis:

* Wenn das linke IR-Modul ein Hindernis erkennt, fährt das Auto rückwärts nach links.
* Wenn das rechte IR-Modul ein Hindernis erkennt, fährt das Auto rückwärts nach rechts.
* Wenn beide IR-Module gleichzeitig ein Hindernis erkennen, fährt das Auto direkt rückwärts.
* Andernfalls fährt das Auto vorwärts.

Erstellen Sie jetzt die entsprechenden Blöcke.

**1. Das Auto fährt rückwärts nach links**

Wenn der rechte Motor gegen den Uhrzeigersinn dreht und der linke Motor sich nicht dreht, wird das Auto rückwärts nach links fahren.

.. image:: img/5_avoid1.png

**2. Das Auto fährt rückwärts nach rechts**

Wenn der linke Motor im Uhrzeigersinn dreht und der rechte Motor sich nicht dreht, wird das Auto rückwärts nach rechts fahren.

.. image:: img/5_avoid2.png

**3. Das Auto fährt vorwärts, rückwärts und hält an**

.. image:: img/5_avoid3.png

**4. Werte der 2 IR-Module auslesen**

Klicken Sie in der Palette **Variables** auf **Make a variable**.

.. image:: img/5_avoid4.png

Geben Sie den Variablennamen ein und klicken Sie auf **OK**, um eine neue Variable zu erstellen.

.. image:: img/5_avoid5.png

Lesen Sie die Werte der linken und rechten IR-Hindernisvermeidungsmodule und speichern Sie sie in den 2 neuen Variablen.

.. image:: img/5_avoid6.png

**5. Hindernisvermeidung**

* Wenn das linke IR-Modul 0 ist (Hindernis erkannt) und das rechte IR-Modul 1 ist, soll das Auto nach links zurückfahren.
* Wenn das rechte IR-Modul 0 ist (Hindernis erkannt), soll das Auto nach rechts zurückfahren.
* Wenn 2 IR-Module gleichzeitig ein Hindernis erkennen, fährt das Auto rückwärts.
* Ansonsten fährt das Auto weiter vorwärts.

.. image:: img/5_avoid7.png
