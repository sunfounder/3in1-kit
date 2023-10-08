.. _cpn_ultrasonic:

Ultraschall-Modul
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

Das Ultraschall-Entfernungsmessmodul bietet eine berührungslose Messfunktion von 2 cm bis 400 cm, wobei die Messgenauigkeit bis zu 3 mm betragen kann.
Es gewährleistet, dass das Signal innerhalb von 5 m stabil ist, und das Signal wird nach 5 m allmählich abgeschwächt, bis es an der 7 m Position verschwindet.

Das Modul beinhaltet Ultraschallsender, Empfänger und Steuerschaltung. Die grundlegenden Prinzipien sind wie folgt:

#. Verarbeitung eines High-Level-Signals von mindestens 10us mit einem IO-Flipflop.

#. Das Modul sendet automatisch acht 40kHz aus und überprüft, ob ein Pulssignal zurückkommt.

#. Kehrt das Signal zurück und führt durch das hohe Level, beträgt die Dauer des hohen IO-Ausgangs die Zeit von der Aussendung der Ultraschallwelle bis zu ihrer Rückkehr. Hierbei gilt: Testentfernung = (Hohe Zeit x Schallgeschwindigkeit (340 m/s)) / 2.

Das Zeitdiagramm ist unten dargestellt.

.. image:: img/ultrasonic228.png

Sie müssen lediglich einen kurzen 10us-Impuls für den Trigger-Eingang bereitstellen, um die Entfernungsmessung zu starten, und dann sendet das Modul 
eine 8-Zyklen-Ultraschallburst mit 40 kHz aus und erhebt sein 
Echo. Sie können die Entfernung über das Zeitintervall zwischen 
dem Senden des Trigger-Signals und dem Empfangen des Echo-Signals berechnen.

Formel: us / 58 = Zentimeter oder us / 148 = Inch; oder: Entfernung = hohe
Signalzeit \* Geschwindigkeit (340M/s) / 2; es wird empfohlen, 
einen Messzyklus von über 60ms zu verwenden, um Signalüberschneidungen zwischen
Trigger-Signal und dem Echo-Signal zu verhindern.

**Beispiel**

* :ref:`ar_ultrasonic` (Grundlegendes Projekt)
* :ref:`follow_your_hand` (Auto-Projekt)
* :ref:`car_ultrasonic` (Auto-Projekt)
* :ref:`sh_parrot` (Scratch-Projekt)

