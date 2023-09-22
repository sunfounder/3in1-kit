.. _ar_light_flow_led:

6.1 Lichtgesteuerte fließende LEDs
=====================================

Ein Fotowiderstand oder Fotodiode ist ein lichtgesteuerter variabler Widerstand. Der Widerstand eines Fotowiderstandes nimmt mit zunehmender einfallender Lichtintensität ab; anders ausgedrückt, zeigt er Photoleitfähigkeit. Ein Fotowiderstand kann in lichtempfindlichen Detektorschaltungen und licht- und dunkelaktivierten Schaltkreisen eingesetzt werden.

Der Widerstand eines Fotowiderstandes ändert sich mit der einfallenden Lichtintensität. Wenn die Lichtintensität steigt, nimmt der Widerstand ab; sinkt sie, steigt der Widerstand.
In diesem Experiment verwenden wir acht LEDs, um die Lichtintensität darzustellen. Je höher die Lichtintensität ist, desto mehr LEDs leuchten auf. Bei ausreichend hoher Lichtintensität leuchten alle LEDs. Bei Dunkelheit erlöschen alle LEDs.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist sicherlich praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name
        - ARTIKEL IN DIESEM SET
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können diese auch einzeln über die folgenden Links kaufen.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Schaltplan**

.. image:: img/circuit_6.1_light_led.png

**Verkabelung**

.. image:: img/light_control_led.png
    :width: 800
    :align: center


**Code**

.. note::

    * Öffnen Sie die Datei ``6.1.light_control_led.ino`` im Pfad ``3in1-kit\basic_project\6.1.light_control_led``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/859e1688-5801-400e-9409-f844ca9b7da7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Jetzt leuchten Sie mit einer Lichtquelle auf den Fotowiderstand, und Sie werden sehen, dass mehrere LEDs aufleuchten. Bei noch mehr Licht leuchten noch mehr LEDs. In einer dunklen Umgebung erlöschen alle LEDs.

**Wie funktioniert das?**


.. code-block:: arduino

    void loop() 
    {
        sensorValue = analogRead(photocellPin); //liest den Wert von A0 aus
        ledLevel = map(sensorValue, 300, 1023, 0, NbrLEDs); // mappt auf die Anzahl der LEDs
        for (int led = 0; led < NbrLEDs; led++)//
        {
            if (led < ledLevel ) //Wenn led kleiner als ledLevel ist, wird der folgende Code ausgeführt.
            {
                digitalWrite(ledPins[led], HIGH); // schaltet Pins unterhalb des Levels ein
            }
            else 
            {
                digitalWrite(ledPins[led],LOW); // schaltet Pins oberhalb aus 
            }
        }
    }

Mit der Funktion ``map()`` können Sie den Wert des Fotowiderstands auf die 8 LEDs abbilden, zum Beispiel, wenn sensorValue 560 ist, dann ist ledLevel 4, also sollten in diesem Moment ledPins[0] bis ledPins[4] leuchten und ledPins[5] bis ledPins[7] aus sein.


