.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_reed:

3.2 Magnetismus spüren
===============================

Die gängigste Art von Reed-Schalter enthält ein Paar magnetisierbare, flexible Metallzungen, deren Endteile durch eine kleine Lücke getrennt sind, wenn der Schalter offen ist.

Ein Magnetfeld von einem Elektromagneten oder einem Permanentmagneten bewirkt, dass sich die Zungen anziehen und so einen elektrischen Stromkreis schließen. 
Die Federkraft der Zungen bewirkt, dass sie sich trennen und den Kreislauf öffnen, wenn das Magnetfeld nachlässt.

Ein häufiges Anwendungsbeispiel für einen Reed-Schalter ist die Erkennung des Öffnens einer Tür oder eines Fensters für eine Sicherheitsalarm.

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

    *   - KOMPONENTENEINFÜHRUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - \-
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

Standardmäßig ist Pin 2 niedrig; und wird hoch gehen, wenn der Magnet in der Nähe des Reed-Schalters ist.

Der Zweck des 10K-Widerstands ist es, den Pin 2 auf einem konstant niedrigen Niveau zu halten, wenn kein Magnet in der Nähe ist.

**Verdrahtung**

.. image:: img/3.2_feel_the_magnetism_bb.png
    :width: 600
    :align: center

**Code**

.. note::

   * Sie können die Datei ``3.2.feel_the_magnetism.ino`` im Pfad ``3in1-kit\learning_project\3.2.feel_the_magnetism`` öffnen. 
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/d28c942e-5144-44a1-85d8-d5e6894fc5df/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, wird im seriellen Monitor eine 1 ausgedruckt, wenn ein Magnet in der Nähe des Reed-Schalters ist.
