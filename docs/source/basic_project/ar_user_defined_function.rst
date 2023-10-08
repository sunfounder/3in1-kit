.. _ar_ultrasonic:

5.8 Benutzerdefinierte Funktion
======================================

In C können wir ein großes Programm in die grundlegenden Bausteine unterteilen, die als Funktion bekannt sind. 
Die Funktion enthält eine Menge von Programmieranweisungen, die von {} eingeschlossen sind. 
Eine Funktion kann mehrmals aufgerufen werden, um Wiederverwendbarkeit und Modularität im C-Programm zu ermöglichen. 
Mit anderen Worten, eine Sammlung von Funktionen bildet ein Programm. 
In anderen Programmiersprachen ist die Funktion auch als Prozedur oder Unterprogramm bekannt.

Die folgenden Vorteile ergeben sich durch die Nutzung von Funktionen:

* Mit Funktionen können wir vermeiden, dieselbe Logik/den gleichen Code in einem Programm immer wieder neu zu schreiben.
* Wir können C-Funktionen beliebig oft und von überall in einem Programm aufrufen.
* Ein großes C-Programm lässt sich leichter verfolgen, wenn es in mehrere Funktionen unterteilt ist.
* Wiederverwendbarkeit ist das Hauptziel von C-Funktionen.
* Dennoch stellt der Aufruf von Funktionen immer eine Belastung in einem C-Programm dar.

In der C-Programmierung gibt es zwei Arten von Funktionen:

* **Bibliotheksfunktionen**: Funktionen, die in den C-Headerdateien deklariert sind.
* **Benutzerdefinierte Funktionen**: Funktionen, die vom C-Programmierer erstellt werden, so dass er/sie sie mehrmals verwenden kann. Dies reduziert die Komplexität eines großen Programms und optimiert den Code.

In diesem Projekt definieren wir eine Funktion, um den Wert des Ultraschallmoduls auszulesen.

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

Die Komponenten können auch einzeln über die folgenden Links erworben werden:

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Schaltplan**

.. image:: img/circuit_6.3_ultrasonic.png

**Verdrahtung**

.. image:: img/ultrasonic_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.8.user_function.ino`` im Pfad ``3in1-kit\basic_project\5.8.user_function``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/11717782-3ee6-4eca-bbb9-094385d9eb4b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Nach erfolgreichem Hochladen des Codes wird der serielle Monitor die Entfernung zwischen dem Ultraschallsensor und dem Hindernis vor ihm anzeigen.

**Wie funktioniert das?**

Zur Anwendung des Ultraschallsensors können wir direkt die Unterfunktion überprüfen.

.. code-block:: arduino

    float readSensorData(){// ...}

Das ``trigPin`` des Ultraschallmoduls sendet alle 2us ein 10us Quadratsignal.

.. code-block:: arduino

    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); 

Das ``echoPin`` empfängt ein High-Level-Signal, wenn sich ein Hindernis im Bereich befindet, und verwendet die Funktion ``pulseIn()`` um die Zeit vom Senden bis zum Empfangen aufzuzeichnen.

.. code-block:: arduino

    microsecond=pulseIn(echoPin, HIGH);

Die Schallgeschwindigkeit beträgt 340 m/s oder 29 Mikrosekunden pro Zentimeter.

Das ergibt die vom Quadratsignal zurückgelegte Entfernung, sowohl hin als auch zurück, daher teilen wir durch 2, um die Entfernung des Hindernisses zu ermitteln.

.. code-block:: arduino

    float distance = microsecond / 29.00 / 2;  

Beachten Sie, dass der Ultraschallsensor das Programm anhält, wenn er arbeitet, was bei komplexen Projekten zu Verzögerungen führen kann.

