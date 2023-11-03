6.1 Lichtempfindliches Array
=====================================

Ein Fotowiderstand oder Fotodiode ist ein lichtgesteuerter variabler Widerstand. Der Widerstand eines Fotowiderstands verringert sich mit zunehmender Lichteinstrahlung; anders ausgedrückt, zeigt er eine Photoleitfähigkeit. Ein Fotowiderstand kann in lichtempfindlichen Detektorschaltungen sowie in licht- und dunkelaktivierten Schaltkreisen eingesetzt werden.

Der Widerstand eines Fotowiderstands ändert sich mit der Lichteinstrahlung. Wenn die Lichtintensität steigt, verringert sich der Widerstand; wenn sie abnimmt, erhöht sich der Widerstand.
In diesem Experiment werden wir acht LEDs verwenden, um die Lichtintensität anzuzeigen. Je höher die Lichtintensität ist, desto mehr LEDs leuchten auf. Wenn die Lichtintensität hoch genug ist, leuchten alle LEDs. Wenn kein Licht vorhanden ist, erlöschen alle LEDs.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Schaltplan**

.. image:: img/circuit_6.1_light_led.png

**Verdrahtung**

.. image:: img/6.1_light_flow_led_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``6.1.light_control_led.ino`` im Pfad ``3in1-kit\learning_project\6.1.light_control_led``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/859e1688-5801-400e-9409-f844ca9b7da7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Jetzt leuchten Sie mit einer Lichtquelle auf den Fotowiderstand, und Sie werden sehen, dass mehrere LEDs aufleuchten. Strahlen Sie mehr Licht darauf, leuchten mehr LEDs auf. Wenn Sie ihn in eine dunkle Umgebung bringen, erlöschen alle LEDs.

**Wie funktioniert das?**

.. code-block:: arduino

    void loop() 
    {
        sensorValue = analogRead(photocellPin); //read the value of A0
        ledLevel = map(sensorValue, 300, 1023, 0, NbrLEDs); // map to the number of LEDs
        for (int led = 0; led < NbrLEDs; led++)//
        {
            if (led < ledLevel ) //When led is smaller than ledLevel, run the following code. 
            {
                digitalWrite(ledPins[led], HIGH); // turn on pins less than the level
            }
            else 
            {
                digitalWrite(ledPins[led],LOW); // turn off pins higher than
            }
        }
    }

Mit der Funktion ``map()`` können Sie den Wert des Fotowiderstands den 8 LEDs zuordnen, zum Beispiel, wenn sensorValue 560 ist, dann ist ledLevel 4, also sollten zu diesem Zeitpunkt ledPins[0] bis ledPins[4] leuchten und ledPins[5] bis ledPins[7] sollten ausgeschaltet sein.
