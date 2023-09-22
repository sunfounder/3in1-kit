.. _cpn_dht11:

DHT11 Feuchtigkeits- und Temperatursensor
============================================

Der digitale Temperatur- und Feuchtigkeitssensor DHT11 ist ein kombinierter Sensor, der einen kalibrierten digitalen Ausgang für Temperatur und Feuchtigkeit bietet. 
Die Technologie einer speziellen digitalen Modulsammlung sowie die Technologie zur Temperatur- und Feuchtigkeitserfassung werden verwendet, um sicherzustellen, dass das Produkt eine hohe Zuverlässigkeit und hervorragende Langzeitstabilität aufweist.

Der Sensor beinhaltet einen resistiven Feuchtigkeitssensor und ein NTC-Temperaturmessgerät und ist mit einem leistungsstarken 8-Bit-Mikrocontroller verbunden. 

Es stehen nur drei Pins zur Verfügung: VCC, GND und DATA. 
Der Kommunikationsprozess beginnt damit, dass die DATA-Leitung Startsignale an den DHT11 sendet. Der DHT11 empfängt diese Signale und sendet ein Antwortsignal zurück. 
Anschließend empfängt der Host das Antwortsignal und beginnt mit dem Empfang von 40-Bit Feuchtigkeitsdaten (8-Bit Feuchtigkeitswert ganzzahlig + 8-Bit Feuchtigkeitswert dezimal + 8-Bit Temperaturwert ganzzahlig + 8-Bit Temperaturwert dezimal + 8-Bit Prüfsumme).

.. image:: img/dht11.png

**Merkmale**

    #. Messbereich für Feuchtigkeit: 20 - 90%RH
    #. Temperaturmessbereich: 0 - 60℃
    #. Ausgabe digitaler Signale für Temperatur und Feuchtigkeit
    #. Betriebsspannung: DC 5V; PCB-Größe: 2,0 x 2,0 cm
    #. Messgenauigkeit für Feuchtigkeit: ±5%RH
    #. Messgenauigkeit für Temperatur: ±2℃

* `DHT11 Datenblatt <http://wiki.sunfounder.cc/images/c/c7/DHT11_datasheet.pdf>`_

**Beispiel**

* :ref:`ar_dht11` (Grundlegendes Projekt)
* :ref:`iot_home` (IoT-Projekt)
* :ref:`iot_plant` (IoT-Projekt)
