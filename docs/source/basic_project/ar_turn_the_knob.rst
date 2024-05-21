.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_potentiometer:

4.1 Den Drehknopf drehen
============================

Ein Potentiometer ist ein Widerstandskomponente mit 3 Anschlüssen, dessen Widerstandswert nach einer bestimmten Regelung variiert werden kann.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

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

Sie können diese auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|


**Schaltplan**

.. image:: img/circuit_5.1_potentiometer.png

In diesem Beispiel verwenden wir den analogen Pin (A0), um den Wert des Potentiometers auszulesen. Durch das Drehen der Achse des Potentiometers können Sie die Widerstandsverteilung zwischen diesen drei Pins ändern und so die Spannung am mittleren Pin verändern. Wenn der Widerstand zwischen dem mittleren und einem äußeren, mit 5V verbundenen Pin nahezu null ist (und der Widerstand zwischen dem mittleren und dem anderen äußeren Pin nahe 10kΩ liegt), liegt die Spannung am mittleren Pin nahe 5V. Die umgekehrte Operation (Widerstand zwischen dem mittleren und einem äußeren, mit 5V verbundenen Pin ist nahe 10kΩ) führt dazu, dass die Spannung am mittleren Pin nahe 0V liegt.

**Verkabelung**

.. image:: img/turn_thek_knob_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

   * Sie können die Datei ``4.1.turn_the_knob.ino`` im Pfad ``3in1-kit\basic_project\4.1.turn_the_knob`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d931f2c9-74bc-4a53-8531-39a21a07dbaf/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem Sie die Codes auf das Board geladen haben, können Sie den seriellen Monitor öffnen, um den gelesenen Wert des Pins zu sehen. Wenn Sie die Achse des Potentiometers drehen, wird der serielle Monitor den Wert zwischen「0」und「1023」anzeigen.
