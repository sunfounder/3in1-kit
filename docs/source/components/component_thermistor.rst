.. _cpn_thermistor:

Thermistor
===============

.. image:: img/thermistor.png
    :width: 150
    :align: center

Ein Thermistor ist eine Art von Widerstand, dessen Widerstand stark temperaturabhängig ist, mehr als bei Standardwiderständen. Das Wort ist eine Kombination aus den Wörtern "thermal" und "Resistor". Thermistoren werden häufig als Einschaltstrombegrenzer, Temperatursensoren (typischerweise vom Typ mit negativem Temperaturkoeffizienten oder NTC), selbstrückstellende Überstromschutzelemente und selbstregulierende Heizelemente (typischerweise vom Typ mit positivem Temperaturkoeffizienten oder PTC) eingesetzt.

* `Thermistor - Wikipedia <https://en.wikipedia.org/wiki/Thermistor>`_

Hier ist das elektronische Symbol des Thermistors.

.. image:: img/thermistor_symbol.png
    :width: 300
    :align: center

Es gibt zwei grundsätzlich entgegengesetzte Typen von Thermistoren:

* Bei NTC-Thermistoren nimmt der Widerstand mit steigender Temperatur ab, meistens aufgrund einer Zunahme von Leitungselektronen, die durch thermische Agitation aus dem Valenzband gehoben werden. Ein NTC wird häufig als Temperatursensor verwendet oder in Reihe zu einer Schaltung als Einschaltstrombegrenzer geschaltet.
* Bei PTC-Thermistoren nimmt der Widerstand mit steigender Temperatur zu, meistens aufgrund erhöhter thermischer Gitteranregungen, insbesondere von Verunreinigungen und Unvollkommenheiten. PTC-Thermistoren werden häufig in Reihe zu einer Schaltung installiert und zum Schutz vor Überstrombedingungen als rückstellbare Sicherungen verwendet.

In diesem Kit verwenden wir einen NTC-Typ. Jeder Thermistor hat einen Normalwiderstand. Hier beträgt er 10k Ohm, gemessen bei 25 Grad Celsius.

Hier ist der Zusammenhang zwischen Widerstand und Temperatur:

    RT = RN * expB(1/TK – 1/TN)

* **RT** ist der Widerstand des NTC-Thermistors bei der Temperatur TK.
* **RN** ist der Widerstand des NTC-Thermistors bei der Nenntemperatur TN. Hier beträgt der Zahlenwert von RN 10k.
* **TK** ist eine Kelvin-Temperatur und die Einheit ist K. Hier beträgt der Zahlenwert von TK 273,15 + Grad Celsius.
* **TN** ist eine Nenn-Kelvin-Temperatur; die Einheit ist ebenfalls K. Hier beträgt der Zahlenwert von TN 273,15 + 25.
* Und **B(beta)**, die Materialkonstante des NTC-Thermistors, wird auch als Wärmeempfindlichkeitsindex bezeichnet mit einem Zahlenwert von 3950.
* **exp** steht für "exponentiell", und die Basiszahl e ist eine natürliche Zahl und beträgt ungefähr 2,7.

Wandeln Sie diese Formel TK=1/(ln(RT/RN)/B+1/TN) um, um die Kelvin-Temperatur zu erhalten, die minus 273,15 Grad Celsius entspricht.

Dieser Zusammenhang ist eine empirische Formel. Sie ist nur dann genau, wenn die Temperatur und der Widerstand innerhalb des wirksamen Bereichs liegen.

**Beispiel**


* :ref:`ar_high_tem_alarm` (Grundlegendes Projekt)
* :ref:`ar_temp` (Grundlegendes Projekt)

.. * :ref:`sh_low_temperature` (Scratch-Projekt)