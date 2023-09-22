.. _cpn_l298n:

L298N Modul
==================================

Dieses L298N Motor-Treiber-Modul ist ein leistungsstarkes Treibermodul zum Ansteuern von Gleichstrom- und Schrittmotoren. Es besteht aus einem L298 Motor-Treiber-IC und einem 78M05 5V-Regler. Das L298N Modul kann bis zu 4 Gleichstrommotoren steuern oder 2 Gleichstrommotoren mit Richtungs- und Geschwindigkeitsregelung.

.. image:: img/l298n_pin.jpg
    :width: 400
    :align: center

* **IN1 & IN2**: Eingangspins von Motor A. Dienen zur Steuerung der Drehrichtung von Motor A.
* **IN3 & IN4**: Eingangspins von Motor B. Dienen zur Steuerung der Drehrichtung von Motor B.
* **ENA**: Aktiviert das PWM-Signal für Motor A. Hier wurde es mit einer Jumperkappe mit 5V verbunden.
* **ENB**: Aktiviert das PWM-Signal für Motor B. Hier wurde es mit einer Jumperkappe mit 5V verbunden.
* **OUT1 & OUT2**: Ausgangspins von Motor A.
* **OUT3 & OUT4**: Ausgangspins von Motor B.
* **12V**: 12V Eingang von einer DC-Stromquelle.
* **5V**: Versorgt die Schaltlogik im L298N IC.
* **GND**: Massepin.

**Merkmale**

* Treibermodell: L298N 2A
* Treiber-Chip: Doppelte H-Brücke L298N
* Motor-Spannungsversorgung (maximal): 46V
* Motor-Stromversorgung (maximal): 2A
* Logikspannung: 5V
* Treiberspannung: 5-35V
* Treiberstrom: 2A
* Logikstrom: 0-36mA
* Maximale Leistung (W): 25W
* Stromerfassung für jeden Motor
* Kühlkörper für bessere Leistung
* LED-Anzeige für eingeschaltetes Gerät

**Betriebsprinzip**

Das Treibermodul kann zwei Motoren steuern. Die aktivierten Terminals ENA und ENB sind im High-Level aktiv.

Das Arbeitsverhältnis zwischen ENA und IN1, IN2 ist wie folgt:

.. list-table:: 
    :widths: 25 25 25 50
    :header-rows: 1

    * - ENA
      - IN1
      - IN2
      - Zustand von Motor A
    * - 0
      - X
      - X
      - Stop
    * - 1
      - 0
      - 0
      - Bremse
    * - 1
      - 0
      - 1
      - Dreht im Uhrzeigersinn
    * - 1
      - 1
      - 0
      - Dreht gegen den Uhrzeigersinn
    * - 1
      - 1
      - 1
      - Bremse

Das Arbeitsverhältnis zwischen ENB und IN3, IN4 ist wie folgt:

.. list-table:: 
    :widths: 25 25 25 50
    :header-rows: 1

    * - ENB
      - IN3
      - IN4
      - Zustand von Motor B
    * - 0
      - X
      - X
      - Stop
    * - 1
      - 0
      - 0
      - Bremse
    * - 1
      - 0
      - 1
      - Dreht im Uhrzeigersinn
    * - 1
      - 1
      - 0
      - Dreht gegen den Uhrzeigersinn
    * - 1
      - 1
      - 1
      - Bremse

**Über die 5V Aktivierungskappe**

Das L298N Motor-Treiber-Modul besteht aus einem L298 Motor-Treiber-IC, 78M05 Spannungsregler, Widerständen, Kondensator, Betriebs-LED und 5V Jumper in einer integrierten Schaltung.

.. image:: img/l298n_introduce.jpg
    :width: 500
    :align: center

Der 78M05 Spannungsregler wird nur aktiviert, wenn der Jumper gesetzt ist. Wenn die Stromversorgung 12V oder weniger beträgt, wird die interne Schaltung vom Spannungsregler versorgt und der 5V-Pin kann als Ausgangspin verwendet werden, um den Mikrocontroller zu versorgen.

Der Jumper sollte nicht gesetzt werden, wenn die Stromversorgung mehr als 12V beträgt, und eine separate 5V sollte über den 5V-Anschluss gegeben werden, um die interne Schaltung zu versorgen.

* `L298N Datenblatt <https://www.yerical.com/product/L298N?product/XXXXX?source=adg&gclid=CjwKCAjwkYGVBhArEiwA4sZLuKEC19ydceKs396z1JENqjcbJDEvedRkcsza1aH_swhuNPWzL-CYfRoCMTMQAvD_BwE#g-pd-res>`_

**Beispiel**

* :ref:`ar_motor` (Grundlegendes Projekt)
* :ref:`car_move` (Auto-Projekt)
* :ref:`car_speed` (Auto-Projekt)
* :ref:`iot_car` (IoT-Projekt)
* :ref:`sh_test` (Scratch-Projekt)

