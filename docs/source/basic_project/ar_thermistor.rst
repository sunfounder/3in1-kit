.. _ar_temp:

4.5 Thermometer
===========================

Ein Thermometer ist ein Gerät, das die Temperatur oder ein Temperaturgefälle misst (den Grad der Wärme oder Kälte eines Objekts). 
Ein Thermometer verfügt über zwei wichtige Elemente: (1) einen Temperatursensor (z.B. die Birne eines Quecksilber-Thermometers oder den pyrometrischen Sensor eines Infrarot-Thermometers), bei dem sich bei Temperaturänderungen etwas verändert; 
und (2) eine Methode zur Umwandlung dieser Änderung in einen numerischen Wert (z.B. die sichtbare Skala, die auf einem Quecksilber-Thermometer markiert ist, oder die digitale Anzeige bei einem Infrarot-Modell).
Thermometer werden in Technologie und Industrie zur Überwachung von Prozessen, in der Meteorologie, in der Medizin und in der wissenschaftlichen Forschung häufig verwendet.

Ein Thermistor ist eine Art Temperatursensor, dessen Widerstand stark temperaturabhängig ist, und er gibt es in zwei Typen:
Negativer Temperaturkoeffizient (NTC) und Positiver Temperaturkoeffizient (PTC), 
auch bekannt als NTC und PTC. Der Widerstand des PTC-Thermistors steigt mit der Temperatur, während der Zustand des NTC dem des PTC entgegengesetzt ist.

In diesem Experiment verwenden wir einen **NTC thermistor**, um ein Thermometer herzustellen.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

**Schaltplan**

.. image:: img/circuit_5.5_thermistor.png

Jeder Thermistor hat einen Normalwiderstand. Hier beträgt er 10k Ohm, gemessen bei 25 Grad Celsius.

Wenn die Temperatur steigt, sinkt der Widerstand des Thermistors. Dann werden die Spannungsdaten vom A/D-Wandler in digitale Werte umgewandelt.

Die Temperatur in Celsius oder Fahrenheit wird über die Programmierung ausgegeben.

Hier ist die Beziehung zwischen Widerstand und Temperatur:

    **RT =RN expB(1/TK – 1/TN)** 

    * **RT** ist der Widerstand des NTC-Thermistors bei der Temperatur **TK**.
    * **RN** ist der Widerstand des NTC-Thermistors bei der Nenntemperatur TN. Hier beträgt der Wert von RN 10k.
    * **TK** ist eine Kelvin-Temperatur, und die Einheit ist K. Hier beträgt der Wert von **TK** ``273,15 + Grad Celsius``.
    * **TN** ist eine Nenntemperatur in Kelvin; die Einheit ist ebenfalls K. Hier beträgt der Wert von TN ``273,15+25``.
    * Und **B(beta)**, die Materialkonstante des NTC-Thermistors, wird auch als Wärmeempfindlichkeitsindex bezeichnet und hat den Wert ``3950``.
    * **exp** steht für exponentiell, und die Basiszahl ``e`` ist eine natürliche Zahl und beträgt ungefähr 2,7.

    Diese Beziehung wird durch die Formel ``TK=1/(ln(RT/RN)/B+1/TN)`` dargestellt, um die Kelvin-Temperatur zu erhalten, die minus 273,15 Grad Celsius entspricht.

    Dieses Verhältnis ist eine empirische Formel. Es ist nur dann genau, wenn Temperatur und Widerstand innerhalb des effektiven Bereichs liegen.

**Verdrahtung**

.. note::
    * Der Thermistor ist schwarz oder grün und mit 103 markiert.

.. image:: img/4.5_thermistor_bb.png
    :width: 600
    :align: center

**Code**

.. note::

   * Öffnen Sie die Datei ``4.5_thermometer.ino`` im Pfad ``euler-kit/arduino/4.5_thermometer``.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   Vergessen Sie nicht, das Raspberry Pi Pico Board und den korrekten Port auszuwählen, bevor Sie auf die Schaltfläche Hochladen klicken.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1ceb0ea2-a330-4052-824d-bd6762c6f0e0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem der Code erfolgreich hochgeladen wurde, gibt der serielle Monitor die Temperaturen in Celsius und Fahrenheit aus.
