.. _cpn_avoid:

Hindernisvermeidungsmodul
===========================================

.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC**: Stromversorgung, 3,3 ~ 5V DC.
* **GND**: Masse
* **OUT**: Signalausgang, normalerweise im hohen Zustand, schaltet auf niedrig, wenn ein Hindernis erkannt wird.

Das IR-Hindernisvermeidungsmodul passt sich stark dem Umgebungslicht an und verfügt über ein Paar Infrarot-Sende- und Empfangsröhren.

Die Sendetube gibt eine Infrarotfrequenz ab. Trifft die Erkennungsrichtung auf ein Hindernis, wird die Infrarotstrahlung von der Empfangsröhre aufgenommen. 
Nach der Verarbeitung im Komparator-Schaltkreis leuchtet die Anzeige auf und gibt ein niedriges Signal aus.

Die Erkennungsentfernung kann mit einem Potentiometer angepasst werden, wobei der effektive Entfernungsbereich zwischen 2-30 cm liegt.

.. image:: img/IR_module.png
    :width: 600
    :align: center

**Beispiel**

* :ref:`ar_ir_obstacle` (Grundlegendes Projekt)
* :ref:`car_ir_obstacle` (Auto-Projekt)
* :ref:`self_driving` (Auto-Projekt)
* :ref:`iot_gate` (IoT-Projekt)
* :ref:`sh_shooting` (Scratch-Projekt)
* :ref:`sh_tap_tile` (Scratch-Projekt)

