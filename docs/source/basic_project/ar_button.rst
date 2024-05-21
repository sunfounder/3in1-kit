.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_button:

3.1 Tastenwert auslesen
==============================================

In den vorherigen Projekten haben wir die Ausgabefunktion verwendet. In diesem Kapitel verwenden wir die Eingabefunktion, um den Tastenwert auszulesen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können diese auch separat über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Schaltplan**

.. image:: img/circuit_3.1_button.png

Ein Pin der Taste ist mit 5V verbunden, 
der andere Pin mit Pin 2. 
Wenn die Taste gedrückt wird, 
wird Pin 2 hochgeschaltet. Wenn die Taste jedoch nicht gedrückt wird, 
befindet sich Pin 2 in einem Schwebezustand und kann hoch oder niedrig sein. 
Um ein stabiles niedriges Signal zu erhalten, wenn die Taste nicht gedrückt ist, 
muss Pin 2 über einen 10K Pull-down-Widerstand erneut mit GND verbunden werden.

**Verkabelung**

.. image:: img/read_the_button_value_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

   * Sie können die Datei ``3.1.read_button_value.ino`` unter dem Pfad ``3in1-kit\basic_project\3.1.read_button_value`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/b456ff57-4dfb-4231-9d91-f1e9a5777de2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, klicken Sie auf das Lupensymbol in der oberen rechten Ecke der Arduino IDE (Serieller Monitor).

.. image:: img/sp220614_152922.png

Wenn Sie die Taste drücken, wird im Seriellen Monitor "1" angezeigt.



