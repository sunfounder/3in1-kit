.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_joystick:

4.3 Den Joystick betätigen
================================

Jeder, der regelmäßig Videospiele spielt, sollte den Joystick gut kennen.
Er wird normalerweise verwendet, um Charaktere zu bewegen oder den Bildschirm zu drehen.

Unsere Bewegungen können vom Joystick erkannt werden, der nach einem sehr einfachen Prinzip funktioniert.
Er besteht aus zwei Potentiometern, die senkrecht zueinander stehen.
Diese beiden Potentiometer messen den analogen Wert des Joysticks in vertikaler und horizontaler Richtung und erzeugen einen Wert (x,y) in einem planaren rechtwinkligen Koordinatensystem.

Dieses Set beinhaltet auch einen Joystick mit digitalem Eingang. Er wird aktiviert, wenn der Joystick gedrückt wird.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen, hier ist der Link:

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
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_joystick`
        - \-

**Schaltplan**

.. image:: img/circuit_5.3_joystick.png

.. note::
    Der SW-Pin ist mit einem 10K Pull-up-Widerstand verbunden, 
    um ein stabiles Hochpegelsignal am SW-Pin (Z-Achse) zu erhalten, wenn der Joystick nicht gedrückt ist; 
    sonst befindet sich der SW in einem schwebenden Zustand, und der Ausgabewert kann zwischen 0/1 variieren.

**Verkabelung**

.. image:: img/toggle_the_joystick_bb.jpg
    :width: 800
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``4.3.toggle_the_joystick.ino`` im Pfad ``3in1-kit\basic_project\4.3.toggle_the_joystick``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f678a03f-546c-42ed-bfae-b8c7daa5eec9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Öffnen Sie den seriellen Monitor, nachdem der Code erfolgreich hochgeladen wurde, um die x,y,z-Werte des Joysticks zu sehen.

* Die Werte der x- und y-Achse sind analoge Werte, die von 0 bis 1023 variieren.
* Die Z-Achse hat einen digitalen Wert mit einem Status von 1 oder 0 (wenn gedrückt, ist es 0).
