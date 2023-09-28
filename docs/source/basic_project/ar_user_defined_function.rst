.. _ar_ultrasonic:

5.8 Benutzerdefinierte Funktion
======================================

In C können wir ein umfangreiches Programm in grundlegende Bausteine unterteilen, die als Funktion bekannt sind. 
Eine Funktion enthält eine Menge von Programmieranweisungen, die von {} eingeschlossen sind. 
Eine Funktion kann mehrmals aufgerufen werden, um Wiederverwendbarkeit und Modularität im C-Programm zu gewährleisten. 
Mit anderen Worten, eine Sammlung von Funktionen bildet ein Programm. 
In anderen Programmiersprachen wird die Funktion auch als Prozedur oder Unterprogramm bezeichnet.

Es gibt folgende Vorteile von Funktionen:

* Mit Funktionen können wir vermeiden, dieselbe Logik/den gleichen Code in einem Programm immer wieder neu zu schreiben.
* Wir können C-Funktionen beliebig oft und von beliebigen Stellen in einem Programm aufrufen.
* Ein umfangreiches C-Programm lässt sich leichter nachverfolgen, wenn es in mehrere Funktionen unterteilt ist.
* Die Hauptleistung von C-Funktionen ist die Wiederverwendbarkeit.
* Ein Funktionsaufruf ist jedoch immer ein Overhead in einem C-Programm.

Es gibt zwei Arten von Funktionen in der C-Programmierung:

* **Library Functions**: die Funktionen, die in den C-Header-Dateien deklariert sind.
* **User-defined functions**: die Funktionen, die vom C-Programmierer erstellt wurden, damit er/sie sie mehrmals verwenden kann. Es reduziert die Komplexität eines großen Programms und optimiert den Code.

In diesem Projekt definieren wir eine Funktion, um den Wert des Ultraschallmoduls zu lesen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Schaltplan**

.. image:: img/circuit_6.3_ultrasonic.png

**Verdrahtung**

.. image:: img/5.8_ultrasonic_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.8.user_function.ino`` im Pfad ``3in1-kit\learning_project\5.8.user_function``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.

    
    


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/11717782-3ee6-4eca-bbb9-094385d9eb4b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Nachdem der Code erfolgreich hochgeladen wurde, wird der serielle Monitor den Abstand zwischen dem Ultraschallsensor und dem Hindernis vor ihm ausgeben.

**Wie funktioniert das?**

Zur Anwendung des Ultraschallsensors können wir direkt die Unterfunktion überprüfen.

.. code-block:: arduino

    float readSensorData(){// ...}

Der ``trigPin`` des Ultraschallmoduls sendet alle 2us ein 10us Quadratwellensignal.

.. code-block:: arduino

    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); 


Der ``echoPin`` empfängt ein High-Level-Signal, wenn sich ein Hindernis im Bereich befindet, und verwendet die ``pulseIn()``-Funktion, um die Zeit vom Senden bis zum Empfangen aufzuzeichnen.

.. code-block:: arduino

    microsecond=pulseIn(echoPin, HIGH);

Die Schallgeschwindigkeit beträgt 340 m/s oder 29 Mikrosekunden pro Zentimeter.

Dies gibt die von der Quadratwelle zurückgelegte Entfernung an, hin und zurück, also teilen wir durch 2, um die Entfernung des Hindernisses zu erhalten.

.. code-block:: arduino

    float distance = microsecond / 29.00 / 2;  

Beachten Sie, dass der Ultraschallsensor das Programm anhält, wenn er arbeitet, was zu Verzögerungen bei der Erstellung komplexer Projekte führen kann.

