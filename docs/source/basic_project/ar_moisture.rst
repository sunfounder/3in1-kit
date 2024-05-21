.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_moisture:

4.4 Bodenfeuchtigkeit messen
====================================

In der Pflanzenzucht können die Pflanzen die anorganischen Elemente im Boden nicht direkt aufnehmen.
Das Wasser im Boden dient als Lösungsmittel, um diese anorganischen Elemente zu lösen.

Die Pflanzen nehmen die Bodenfeuchtigkeit über das Wurzelsystem auf, erhalten Nährstoffe und fördern das Wachstum.

Im Prozess des Pflanzenwachstums und der Entwicklung unterscheiden sich auch die Anforderungen an die Bodentemperatur.
Daher wird ein Bodenfeuchtigkeitssensor benötigt.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schaltplan**

.. image:: img/circuit_5.4_soil.png

**Verkabelung**

.. image:: img/measure_the_moisture_bb.jpg
    :width: 800
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``4.4.measure_soil_moisture.ino`` im Pfad ``3in1-kit\basic_project\4.4.measure_soil_moisture``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b6f7e756-0f14-4117-9bb2-ee5083b6445f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nach erfolgreichem Hochladen des Codes wird der serielle Monitor den Wert der Bodenfeuchtigkeit ausgeben.

Wenn Sie das Modul in den Boden stecken und ihn bewässern, wird der Wert des Bodenfeuchtigkeitssensors kleiner.
