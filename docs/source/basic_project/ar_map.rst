.. _ar_map:

5.6 Karte (Map)
===================

Wenn Sie genau hinsehen, werden Sie feststellen, dass viele Werte in der Programmierung unterschiedliche Bereiche haben.
Zum Beispiel liegt der Wertebereich für analoge Eingänge bei (0~1023).
Der Wertebereich für den analogen Ausgang liegt bei (0~255).
Der Ausgabewinkel des Servos liegt bei (0~180).

Das bedeutet, wenn wir das Potentiometer verwenden möchten, um die Helligkeit der LED oder den Winkel des Servos zu steuern, müssen wir eine Zuordnungsoperation durchführen.

Lassen Sie uns nun sehen, wie das erreicht werden kann.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENEINFÜHRUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**Schaltplan**

.. image:: img/circuit_8.3_amp.png

**Verdrahtung**

.. image:: img/map_bb.jpg
    :width: 800
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.6.map.ino`` im Pfad ``3in1-kit\basic_project\5.6.map``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f00e4c4c-fb13-4445-9d89-eb2857b5fe87/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, können Sie das Potentiometer hin und her drehen, und die Ausgangswelle des Servos wird hin und her drehen.

**Wie funktioniert das?**

``map(value, fromLow, fromHigh, toLow, toHigh)``: Ordne eine Zahl von einem Bereich einem anderen zu.
Das heißt, ein fromLow-Wert wird zu toLow zugeordnet und ein fromHigh-Wert zu toHigh.

    **Syntax**
        map(value, fromLow, fromHigh, toLow, toHigh)

    **Parameter**
        * ``value``: die zuzuordnende Zahl.
        * ``fromLow``: die untere Grenze des aktuellen Wertebereichs.
        * ``fromHigh``: die obere Grenze des aktuellen Wertebereichs.
        * ``toLow``: die untere Grenze des Zielwertebereichs.
        * ``toHigh``: die obere Grenze des Zielwertebereichs.

Wenn das Potentiometer die LED steuert, können Sie auch die Zuordnung verwenden, um die Aufgabe zu erfüllen.

.. code-block:: arduino

    int x = analogRead(knob);
    int y = map(x,0,1023,0,255);
    analogWrite(led,y);

**Anmerkungen und Warnungen**

* Die "untere Grenze" beider Bereiche kann größer oder kleiner als die "obere Grenze" sein, was bedeutet, dass die ``map()`` Funktion verwendet werden kann, um einen Zahlenbereich umzukehren.

  .. code-block:: arduino

    y = map(x,0,180,180,0);

* Die Zuordnung funktioniert auch gut für negative Zahlen.

  .. code-block:: arduino

    y = map(x,0,1023,-90,90);

* Die Zuordnung verwendet Ganzzahlen und die Dezimalstellen von Fließkommazahlen werden verworfen.
