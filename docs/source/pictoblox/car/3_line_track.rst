.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_line:

3.3 Der Linie folgen
======================

Das Auto ist mit einem Linienverfolgungsmodul ausgestattet, mit dem es der schwarzen Linie folgen kann.

Bevor Sie mit dem Projekt beginnen, sollten Sie eine Kurvenkarte mit schwarzem Klebeband erstellen. Die empfohlene Linienbreite liegt zwischen 0,8-1,5 cm, und der Winkel der Kurve sollte nicht weniger als 90 Grad betragen.

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
    *   - :ref:`cpn_track`
        - |link_track_buy|

Schaltkreis aufbauen
-----------------------

Dies ist ein digitales Linienverfolgungsmodul. Wenn eine schwarze Linie erkannt wird, gibt es 1 aus; bei einer weißen Linie wird ein Wert von 0 ausgegeben. Zudem können Sie seinen Erfassungsabstand über das Potentiometer am Modul anpassen.

Bauen Sie den Schaltkreis entsprechend dem folgenden Diagramm auf.

.. list-table:: 

    * - Linienverfolgungsmodul
      - R3 Board
    * - S
      - 2
    * - V+
      - 5V
    * - G
      - GND

.. image:: img/car_4.png
    :width: 800

Das Modul einstellen
-----------------------

Bevor Sie mit dem Projekt beginnen, müssen Sie die Empfindlichkeit des Moduls anpassen.

Verdrahten Sie gemäß dem obigen Diagramm und schalten Sie dann das R3-Board ein (entweder direkt über das USB-Kabel oder das 9V-Batteriekabel). Laden Sie den Code noch nicht hoch.

Kleben Sie ein schwarzes Isolierband auf den Tisch und stellen Sie den Wagen darauf.

Beobachten Sie die Signalleuchte am Modul, um sicherzustellen, dass sie auf dem weißen Tisch leuchtet und auf dem schwarzen Band erlischt.

Wenn dies nicht der Fall ist, müssen Sie das Potentiometer am Modul so einstellen, dass der oben beschriebene Effekt erzielt wird.

.. image:: img/line_track_cali.JPG

Programmierung
--------------

Erstellen Sie nun 2 Blöcke, die es dem Auto ermöglichen, sich entweder nach vorne links oder nach vorne rechts zu bewegen.

**1. Nach vorne links bewegen**

Wenn der rechte Motor im Uhrzeigersinn dreht und der linke Motor stillsteht, bewegt sich das Auto leicht nach vorne links.

.. image:: img/3_forward_left.png

**2. Nach vorne rechts bewegen**

Ebenso bewegt sich das Auto leicht nach rechts, wenn der linke Motor gegen den Uhrzeigersinn dreht und der rechte Motor stillsteht.

.. image:: img/3_forward_left.png

**3. Linienverfolgung**

Lesen Sie den Wert des Linienverfolgungsmoduls. Wenn es 1 ist, wurde eine schwarze Linie erkannt. Lassen Sie das Auto nach vorne links fahren, andernfalls nach vorne rechts.

.. image:: img/3_follow.png

Nachdem Sie den Code auf das R3-Board hochgeladen haben, richten Sie das Linienverfolgungsmodul unter dem Auto auf die schwarze Linie aus, und Sie werden sehen, wie das Auto der Linie folgt.
