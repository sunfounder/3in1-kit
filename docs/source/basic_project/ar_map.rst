.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_map:

5.6 Map
===================

Wenn Sie genau hinschauen, werden Sie feststellen, dass viele Werte in der Programmierung unterschiedliche Bereiche haben.
Zum Beispiel liegt der Wertebereich für analoge Eingänge bei (0~1023).
Der Wertebereich für den analogen Ausgang liegt bei (0~255).
Der Ausgangswinkel des Servos beträgt (0~180).

Das bedeutet, dass wir, wenn wir den Potentiometer nutzen wollen, um die Helligkeit der LED oder den Winkel des Servos zu steuern, eine Zuordnungsoperation durchführen müssen.

Lassen Sie uns nun sehen, wie dies umgesetzt wird.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link: 

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
        - \-
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

.. image:: img/5.6_map_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.6.map.ino`` im Pfad ``3in1-kit\learning_project\5.6.map``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f00e4c4c-fb13-4445-9d89-eb2857b5fe87/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem Sie den Code erfolgreich hochgeladen haben, können Sie den Potentiometer hin- und herbewegen, und die Ausgangswelle des Servos wird entsprechend rotieren.

**Wie funktioniert das?**

``map(value, fromLow, fromHigh, toLow, toHigh)``: Ordnet eine Zahl einem anderen Bereich zu.
Das bedeutet, dass ein fromLow-Wert zu toLow und ein fromHigh-Wert zu toHigh zugeordnet wird.

    **Syntax**
        map(value, fromLow, fromHigh, toLow, toHigh)

    **Parameter**
        * ``value``: die zuordnende Zahl.
        * ``fromLow``: die untere Grenze des aktuellen Bereichs des Wertes.
        * ``fromHigh``: die obere Grenze des aktuellen Bereichs des Wertes.
        * ``toLow``: die untere Grenze des Zielbereichs des Wertes.
        * ``toHigh``: die obere Grenze des Zielbereichs des Wertes.

Wenn der Potentiometer die LED steuert, können Sie ebenfalls die Funktion map verwenden, um die Aufgabe zu erfüllen.

.. code-block:: arduino

    int x = analogRead(knob);
    int y = map(x,0,1023,0,255);
    analogWrite(led,y);


**Anmerkungen und Warnungen**

* Die "untere Grenze" beider Bereiche kann größer oder kleiner sein als die "obere Grenze", was bedeutet, dass die Funktion ``map()`` verwendet werden kann, um einen Bereich von Zahlen umzukehren.

  .. code-block:: arduino

    y = map(x,0,180,180,0);

* Das Mapping funktioniert auch gut für negative Zahlen.

  .. code-block:: arduino

    y = map(x,0,1023,-90,90);

* Das Mapping verwendet Ganzzahlen, und die Dezimalstellen von Fließkommazahlen werden verworfen.
