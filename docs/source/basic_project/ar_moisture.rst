.. _ar_moisture:

4.4 Bodenfeuchtigkeit messen
==============================

In der Pflanzenbranche können die Kulturen selbst die anorganischen Elemente im Boden nicht direkt aufnehmen.
Das Wasser im Boden fungiert als Lösungsmittel, um diese anorganischen Elemente aufzulösen.

Kulturen nehmen Bodenfeuchtigkeit über das Wurzelsystem auf, erhalten Nährstoffe und fördern das Wachstum.

Im Prozess des Pflanzenwachstums und der Entwicklung sind die Anforderungen an die Bodentemperatur ebenfalls unterschiedlich.
Daher ist ein Bodenfeuchtigkeitssensor erforderlich.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten:

Es ist definitiv praktisch, ein komplettes Kit zu kaufen, hier ist der Link:

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
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schaltplan**

.. image:: img/circuit_5.4_soil.png

**Verdrahtung**

.. image:: img/4.4_measure_the_moisture_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``4.4.measure_soil_moisture.ino`` im Pfad ``3in1-kit\learning_project\4.4.measure_soil_moisture``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b6f7e756-0f14-4117-9bb2-ee5083b6445f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem der Code erfolgreich hochgeladen wurde, druckt der serielle Monitor den Bodenfeuchtigkeitswert aus.

Indem man das Modul in den Boden einsetzt und ihn bewässert, wird der Wert des Bodenfeuchtigkeitssensors kleiner werden.
