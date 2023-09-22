.. _car_remote_plus:

10. One-Touch-Start
=============================

In diesem Projekt haben wir die vorherigen Projekte - Linienverfolgung, Verfolgung, Hindernisvermeidung, autonomes Fahren usw. zusammengeführt. Sie können mit den Tasten der Fernbedienung umgeschaltet werden, sodass Sie das Auto starten und alle Funktionen auf einmal erleben können.

**Verkabelung**

.. image:: img/car_all.jpg
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``10.one_touch_start.ino`` unter dem Pfad ``3in1-kit\car_project\10.one_touch_start``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Die ``IRremote``-Bibliothek wird hier verwendet, Sie können sie aus dem **Library Manager** installieren.
    
        .. image:: ../img/lib_irremote.png
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/d48e05be-da3a-4515-a7f0-99ff965e597e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nach erfolgreichem Hochladen des Codes wird die LED bei jedem vom IR-Empfänger empfangenen Signal der Fernbedienung 3 Mal schnell blinken. Sie können die folgenden Tasten drücken, um den Wagen zu steuern.

* **+**: Beschleunigen
* **-**: Verlangsamen
* **1**: Nach links vorne bewegen
* **2**: Vorwärts
* **3**: Nach rechts bewegen
* **4**: Links abbiegen
* **6**: Rechts abbiegen
* **7**: Rückwärts nach links
* **8**: Rückwärts
* **9**: Rückwärts nach rechts
* **CYCLE**: Der Linie folgen
* **U/SD**: Autonomes Fahren
* **▷▷|**: Hindernisvermeidung mit Ultraschallmodul
* **|◁◁**: Hindernisvermeidung mit IR-Hindernismodul
* **EQ**: Der Hand folgen
* **0**: Stoppen
