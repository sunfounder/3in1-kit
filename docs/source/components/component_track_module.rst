.. _cpn_track:

Linienverfolgungsmodul
================================

.. image:: img/line_track.png
    :width: 400
    :align: center

* S: Normalerweise niedriges Level, hohes Level bei Erkennung einer schwarzen Linie.
* V+：Stromversorgung, 3.3v~5V
* G: Masse

Dies ist ein 1-Kanal-Linienverfolgungsmodul, das, wie der Name schon sagt, schwarze Linien auf einem weißen Hintergrund oder weiße Linien auf einem schwarzen Hintergrund verfolgt.

.. image:: img/tcrt5000.jpg
    :width: 200
    :align: center

Das Modul verwendet einen TCRT5000 Infrarotsensor, der aus einer Infrarot-LED (blau) und einem lichtempfindlichen Triplet (schwarz) besteht.

* Die blaue Infrarot-LED sendet bei eingeschaltetem Zustand Infrarotlicht aus, das für das menschliche Auge unsichtbar ist.
* Der schwarze Fototransistor, der zum Empfang von Infrarotlicht verwendet wird, hat einen internen Widerstand, dessen Widerstand mit dem empfangenen Infrarotlicht variiert; je mehr Infrarotlicht empfangen wird, desto stärker nimmt sein Widerstand ab und umgekehrt.

Auf dem Modul befindet sich ein LM393-Komparator, der dazu dient, die Spannung des Fototransistors mit der eingestellten Spannung (durch Potentiometer angepasst) zu vergleichen. Ist sie größer als die eingestellte Spannung, beträgt der Ausgang 1; sonst beträgt der Ausgang 0.

Daher, wenn die Infrarot-Senderröhre auf eine schwarze Oberfläche leuchtet, da Schwarz Licht absorbiert, empfängt der lichtempfindliche Transistor weniger Infrarotlicht, sein Widerstand wird erhöhen (Spannungsanstieg). Nach dem LM393-Komparator wird ein hohes Niveau ausgegeben.

Ebenso, wenn er auf eine weiße Oberfläche leuchtet, wird das reflektierte Licht stärker und der Widerstand des lichtempfindlichen Transistors sinkt (Spannungsabfall); daher gibt der Komparator ein niedriges Niveau aus und die Anzeige-LED leuchtet.

* `TCRT5000 <https://www.vishay.com/docs/83760/tcrt5000.pdf>`_

**Eigenschaften**

* Verwendung des Infrarot-Emissionssensors TCRT5000
* Erfassungsentfernung: 1-8mm, Brennweite von 2.5mm
* Komparator-Ausgangssignal ist sauber, mit gutem Wellenform, Antriebskapazität größer als 15mA
* Empfindlichkeitseinstellung durch Potentiometer
* Betriebsspannung: 3.3V-5V
* Digitalausgang: 0 (weiß) und 1 (schwarz)
* Verwendet den weitspannungs LM393 Komparator.
* Größe: 42mmx10mm

**Beispiel**

* :ref:`ar_line_track` (Grundlegendes Projekt)
* :ref:`follow_the_line` (Auto-Projekt)
* :ref:`sh_protect_heart` (Scratch-Projekt)
