.. _cpn_resistor:

Widerstand
============

.. image:: img/resistor.png
    :width: 300

Ein Widerstand ist ein elektronisches Element, das den Strom in einem Zweig begrenzen kann.
Ein fester Widerstand ist eine Art von Widerstand, dessen Widerstandswert nicht verändert werden kann, während der eines Potentiometers oder eines variablen Widerstands einstellbar ist.

Es gibt zwei gebräuchliche Schaltsymbole für Widerstände. In der Regel ist der Widerstandswert darauf vermerkt. Wenn Sie diese Symbole in einer Schaltung sehen, repräsentieren sie einen Widerstand.

.. image:: img/resistor_symbol.png
    :width: 400

**Ω** ist die Einheit des Widerstands und größere Einheiten sind KΩ, MΩ usw.
Ihre Beziehung ist wie folgt: 1 MΩ = 1000 KΩ, 1 KΩ = 1000 Ω. Normalerweise ist der Widerstandswert darauf vermerkt.

Bevor man einen Widerstand verwendet, muss man dessen Widerstandswert kennen. Hier sind zwei Methoden: Sie können die Farbbänder auf dem Widerstand betrachten oder ein Multimeter verwenden, um den Widerstand zu messen. Es wird empfohlen, die erste Methode zu verwenden, da sie bequemer und schneller ist.

.. image:: img/resistance_card.jpg

Wie auf der Karte gezeigt, steht jede Farbe für eine Zahl.

.. list-table::

   * - Schwarz
     - Braun
     - Rot
     - Orange
     - Gelb
     - Grün
     - Blau
     - Violett
     - Grau
     - Weiß
     - Gold
     - Silber
   * - 0
     - 1
     - 2
     - 3
     - 4
     - 5
     - 6
     - 7
     - 8
     - 9
     - 0.1
     - 0.01

Die 4- und 5-Band-Widerstände werden häufig verwendet und haben 4 bzw. 5 Farbbänder.

Normalerweise, wenn Sie einen Widerstand erhalten, kann es schwierig sein zu entscheiden, von welchem Ende aus man die Farben lesen sollte.
Ein Tipp ist, dass der Abstand zwischen dem 4. und 5. Band vergleichsweise größer ist.

Daher können Sie die Lücke zwischen den beiden Farbbändern an einem Ende des Widerstands betrachten;
wenn sie größer als alle anderen Bandlücken ist, dann sollten Sie von der gegenüberliegenden Seite lesen.

Sehen wir uns an, wie man den Widerstandswert eines 5-Band-Widerstands wie unten gezeigt abliest.

.. image:: img/220ohm.jpg
    :width: 500

Für diesen Widerstand sollte der Widerstand von links nach rechts gelesen werden.
Der Wert sollte in diesem Format vorliegen: 1. Band 2. Band 3. Band x 10^Multiplier (Ω) und der zulässige Fehler beträgt ±Toleranz%. 
So ist der Widerstandswert dieses Widerstands 2(rot) 2(rot) 0(schwarz) x 10^0(schwarz) Ω = 220 Ω,
und der zulässige Fehler beträgt ± 1% (braun).

.. list-table::Häufige Farbband-Kombinationen von Widerständen
    :header-rows: 1

    * - Widerstand 
      - Farbbänder  
    * - 10Ω   
      - braun schwarz schwarz silber braun
    * - 100Ω   
      - braun schwarz schwarz schwarz braun
    * - 220Ω 
      - rot rot schwarz schwarz braun
    * - 330Ω 
      - orange orange schwarz schwarz braun
    * - 1kΩ 
      - braun schwarz schwarz braun braun
    * - 2kΩ 
      - rot schwarz schwarz braun braun
    * - 5.1kΩ 
      - grün braun schwarz braun braun
    * - 10kΩ 
      - braun schwarz schwarz rot braun 
    * - 100kΩ 
      - braun schwarz schwarz orange braun 
    * - 1MΩ 
      - braun schwarz schwarz grün braun 

Mehr über Widerstände können Sie hier nachlesen: `Widerstand - Wikipedia <https://en.wikipedia.org/wiki/Resistor>`_.

