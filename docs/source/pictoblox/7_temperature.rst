.. _sh_low_temperature:

2.7 Niedrigtemperaturalarm
=============================

In diesem Projekt werden wir ein Alarmsystem für niedrige Temperaturen erstellen. Wenn die Temperatur unter einen bestimmten Schwellenwert fällt, erscheint das **Schneeflocke**-Symbol auf der Bühne.

.. image:: img/9_tem.png

Was Sie lernen werden
------------------------

- Funktionsweise des Thermistors
- Multivariable und subtraktive Vorgänge

Benötigte Komponenten
------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist sicherlich praktisch, ein komplettes Set zu kaufen, hier der Link:

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
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_thermistor` 
        - |link_thermistor_buy|

Schaltung aufbauen
-----------------------

Ein Thermistor ist ein Widerstand, dessen Widerstandswert stark temperaturabhängig ist. Es gibt zwei Typen von Widerständen, PTC (Widerstand steigt mit steigender Temperatur) und NTC (Widerstand nimmt mit steigender Temperatur ab).

Bauen Sie den Schaltkreis gemäß dem folgenden Diagramm.

Ein Ende des Thermistors ist mit GND verbunden, das andere Ende mit A0, und ein 10K Widerstand ist in Reihe mit 5V geschaltet.

Hier wird der NTC-Thermistor verwendet. Wenn die Temperatur steigt, verringert sich der Widerstand des Thermistors, die Spannungsteilung von A0 nimmt ab, und der von A0 erhaltene Wert nimmt ab, und umgekehrt steigt er.

.. image:: img/circuit/thermistor_circuit.png

Programmierung
------------------

**1. Wählen Sie eine Figur**

Löschen Sie die Standardfigur, klicken Sie auf den Button **Choose a Sprite** in der unteren rechten Ecke des Figurbereichs, geben Sie **Snowflake** in das Suchfeld ein und fügen Sie diese hinzu.

.. image:: img/9_snow.png

**2. Erstellen Sie 2 Variablen**

Erstellen Sie zwei Variablen, **before** und **current**, um den Wert von A0 in verschiedenen Zuständen zu speichern.

.. image:: img/9_va.png

**3. Lesen Sie den Wert von A0**

Wenn das grüne Flaggen-Symbol angeklickt wird, lesen Sie den Wert von A0 und speichern Sie ihn in der Variablen **before**.

.. image:: img/9_before.png

**4. Lesen Sie den Wert von A0 erneut**

In [forever], lesen Sie den Wert von A0 erneut und speichern Sie ihn in der Variablen **current**.

.. image:: img/9_current.png

**5. Bestimmung von Temperaturänderungen**

Verwenden Sie den [if else] Block, um festzustellen, ob der aktuelle Wert von A0 50 größer ist als zuvor, was eine Abnahme der Temperatur bedeutet. Lassen Sie in diesem Fall das **Schneeflocke**-Symbol anzeigen, sonst verbergen.

* [-] & [>]: Subtraktions- und Vergleichsoperatoren aus der **Operatoren**-Palette.

.. image:: img/9_show.png
