.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _car_remote_plus:

10. Starten mit einem Tastendruck
====================================

In diesem Projekt haben wir die vorherigen Projekte - Linienverfolgung, Verfolgung, Hindernisvermeidung, autonomes Fahren usw. zusammengeführt. Sie können durch Tasten auf der Fernbedienung umgeschaltet werden, sodass Sie das Auto starten und alle Funktionen gleichzeitig erleben können.

**Verdrahtung**

.. image:: img/car_10.png
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``10.one_touch_start.ino`` unter dem Pfad ``3in1-kit\car_project\10.one_touch_start``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Hier wird die ``IRremote`` Bibliothek verwendet. Sie können sie über den **Library Manager** installieren.
  
        .. image:: ../img/lib_irremote.png
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d873724f-120e-4679-b4ec-8d72ad583c8c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nach erfolgreichem Hochladen des Codes wird die LED für jedes vom IR-Empfänger empfangene Signal von der Fernbedienung 3 Mal schnell blinken. Sie können die folgenden Tasten drücken, um den Wagen zu steuern.

* **+**: Beschleunigen
* **-**: Verlangsamen
* **1**: Bewegen Sie sich zur linken Vorderseite
* **2**: Vorwärts
* **3**: Bewegen Sie sich nach rechts.
* **4**: Nach links drehen
* **6**: Nach rechts drehen
* **7**: Rückwärts nach links
* **8**: Rückwärts
* **9**: Rückwärts nach rechts
* **CYCLE**: Der Linie folgen
* **U/SD**: Autonomes Fahren
* **▷▷|**: Hindernisvermeidung mit Ultraschallmodul
* **|◁◁**: Hindernisvermeidung mit IR-Hindernismodul
* **EQ**: Deiner Hand folgen
* **0**: Anhalten



