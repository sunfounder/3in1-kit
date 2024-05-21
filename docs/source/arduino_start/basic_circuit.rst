.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Wie man den Schaltkreis baut
================================

Viele der Dinge, die Sie täglich verwenden, werden mit Strom betrieben, wie die Lichter in Ihrem Haus und der Computer, auf dem Sie gerade lesen.

Um Elektrizität zu nutzen, müssen Sie einen elektrischen Schaltkreis bauen. Ein Schaltkreis ist im Grunde ein Pfad, durch den Elektrizität fließt, oder ein elektronischer Schaltkreis, und besteht aus elektrischen Geräten und Komponenten, die in einer bestimmten Weise verbunden sind, wie Widerstände, Kondensatoren, Stromversorgungen und Schalter.

.. image:: img/circuit.png

Ein Schaltkreis ist ein geschlossener Pfad, in dem Elektronen fließen, um einen elektrischen Strom zu erzeugen. Um den Strom fließen zu lassen, muss es einen leitenden Pfad zwischen dem positiven und dem negativen Pol der Stromquelle geben, der als geschlossener Schaltkreis bezeichnet wird (wenn er unterbrochen ist, spricht man von einem offenen Schaltkreis).

Das Arduino-Board hat einige Stromausgangspins (positiv) und einige Ground-Pins (negativ). 
Sie können diese Pins als positive und negative Seiten der Stromquelle verwenden, indem Sie die Stromquelle auf das Board stecken.

.. image:: img/arduinoPN.jpg

Mit Elektrizität können Sie Werke mit Licht, Ton und Bewegung schaffen. 
Sie können eine LED zum Leuchten bringen, indem Sie den langen Pin an den positiven Pol und den kurzen Pin an den negativen Pol anschließen.
Wenn Sie dies tun, wird die LED sehr schnell kaputt gehen, daher müssen Sie einen 1k*-Widerstand in den Schaltkreis einfügen, um ihn zu schützen.

Der von ihnen gebildete Schaltkreis ist unten dargestellt.

.. image:: img/sp221014_181625.png

Vielleicht fragen Sie sich jetzt: Wie baue ich diesen Schaltkreis? Halte ich die Drähte mit der Hand oder klebe ich die Pins und Drähte fest?

In dieser Situation werden steckbare Steckbretter Ihre stärksten Verbündeten sein.

.. _bc_bb:

Hallo, Steckbrett!
-------------------------

Ein Steckbrett ist eine rechteckige Kunststoffplatte mit vielen kleinen Löchern. 
Diese Löcher ermöglichen es uns, elektronische Komponenten einfach einzufügen und elektronische Schaltkreise aufzubauen. 
Steckbretter fixieren elektronische Komponenten nicht dauerhaft, sodass wir einen Schaltkreis bei Problemen leicht reparieren und neu starten können.

.. note::
    Für die Verwendung von Steckbrettern sind keine speziellen Werkzeuge erforderlich. Viele elektronische Komponenten sind jedoch sehr klein, und eine Pinzette kann uns helfen, kleine Teile besser aufzunehmen.

Im Internet finden wir viele Informationen über Steckbretter.

* `Wie man ein Steckbrett benutzt - Science Buddies <https://www.sciencebuddies.org/science-fair-projects/references/how-to-use-a-breadboard#pth-smd>`_

* `Was ist ein STECKBRETT? - Makezine <https://cdn.makezine.com/uploads/2012/10/breadboardworkshop.pdf>`_

Hier sind einige Dinge, die Sie über Steckbretter wissen sollten.

#. Jede halbe Reihengruppe (wie Spalte A-E in Reihe 1 oder Spalte F-J in Reihe 3) ist verbunden. Daher, wenn ein elektrisches Signal von A1 einfließt, kann es von B1, C1, D1, E1 ausfließen, aber nicht von F1 oder A2.

#. In den meisten Fällen werden beide Seiten des Steckbretts als Stromschienen verwendet, und die Löcher in jeder Spalte (etwa 50 Löcher) sind miteinander verbunden. In der Regel werden positive Stromversorgungen an die Löcher in der Nähe des roten Drahts angeschlossen und negative Stromversorgungen an die Löcher in der Nähe des blauen Drahts.

#. In einem Schaltkreis fließt der Strom vom positiven zum negativen Pol, nachdem er durch die Last geflossen ist. In diesem Fall kann ein Kurzschluss auftreten.

**Lasst uns die Richtung des Stroms folgen, um den Schaltkreis aufzubauen!**

.. image:: img/connect_led.png

1. In diesem Schaltkreis verwenden wir den 5V-Pin des Boards, um die LED mit Strom zu versorgen. Verwenden Sie ein Stecker-zu-Stecker (M2M) Jumper-Kabel, um es mit der roten Stromschiene zu verbinden.
#. Um die LED zu schützen, muss der Strom durch einen 1k Ohm-Widerstand fließen. Verbinden Sie ein Ende (beliebiges Ende) des Widerstands mit der roten Stromschiene und das andere Ende mit der freien Reihe des Steckbretts.

    .. note::
        Der Farbring des 1k Ohm-Widerstands ist braun, schwarz, schwarz, braun und braun.

#. Wenn Sie die LED aufnehmen, sehen Sie, dass einer ihrer Anschlüsse länger ist als der andere. Verbinden Sie den längeren Anschluss mit der gleichen Reihe wie der Widerstand und den kürzeren Anschluss mit der anderen Reihe.

    .. note::
        Der längere Anschluss ist die Anode, die die positive Seite des Schaltkreises repräsentiert; der kürzere Anschluss ist die Kathode, die die negative Seite repräsentiert. 

        Die Anode muss über einen Widerstand mit dem GPIO-Pin verbunden werden; die Kathode muss mit dem GND-Pin verbunden werden.

#. Verwenden Sie ein Stecker-zu-Stecker (M2M) Jumper-Kabel, um den kurzen LED-Pin mit der negativen Stromschiene des Steckbretts zu verbinden.
#. Verbinden Sie den GND-Pin des Boards mit der negativen Stromschiene mit einem Jumper.


Vorsicht vor Kurzschlüssen
------------------------------

Kurzschlüsse können auftreten, wenn zwei Komponenten, die nicht verbunden sein sollten, "versehentlich" miteinander verbunden werden. Dieses Kit enthält Widerstände, Transistoren, Kondensatoren, LEDs usw., die lange Metallstifte haben, die aneinander stoßen und einen Kurzschluss verursachen können. Einige Schaltkreise werden einfach daran gehindert, ordnungsgemäß zu funktionieren, wenn ein Kurzschluss auftritt. Gelegentlich kann ein Kurzschluss Komponenten dauerhaft beschädigen, insbesondere zwischen der Stromversorgung und der Masseleiste, wodurch der Schaltkreis sehr heiß wird, das Plastik auf dem Steckbrett schmilzt und sogar die Komponenten verbrennt!

Achten Sie daher immer darauf, dass die Stifte aller Elektronik auf dem Steckbrett sich nicht berühren.

Ausrichtung des Schaltkreises
-------------------------------

Schaltkreise haben eine Orientierung, und die Ausrichtung spielt bei bestimmten elektronischen Komponenten eine bedeutende Rolle. Es gibt einige Geräte mit Polarität, was bedeutet, dass sie basierend auf ihren positiven und negativen Polen korrekt verbunden werden müssen. Falsch ausgerichtete Schaltkreise funktionieren nicht ordnungsgemäß.

.. image:: img/connect_led_reverse.png

Wenn Sie die LED in diesem einfachen Schaltkreis, den wir zuvor gebaut haben, umkehren, werden Sie feststellen, dass sie nicht mehr funktioniert.

Im Gegensatz dazu haben einige Geräte keine Richtung, wie die Widerstände in diesem Schaltkreis, so dass Sie versuchen können, sie umzukehren, ohne den normalen Betrieb der LEDs zu beeinflussen.

Die meisten Komponenten und Module mit Bezeichnungen wie "+", "-", "GND", "VCC" oder mit Stiften unterschiedlicher Länge müssen auf eine bestimmte Weise mit dem Schaltkreis verbunden werden.

Schutz des Schaltkreises
-------------------------------------

Strom ist die Geschwindigkeit, mit der Elektronen an einem Punkt in einem vollständigen elektrischen Schaltkreis vorbeifließen. Im Grunde genommen entspricht Strom = Fluss. Ein Ampere (AM-pir) oder Amp ist die internationale Einheit zur Messung des Stroms. Es drückt die Menge der Elektronen (manchmal "elektrische Ladung" genannt) aus, die über einen gegebenen Zeitraum an einem Punkt in einem Schaltkreis vorbeifließt.

Die treibende Kraft (Spannung) hinter dem Stromfluss wird als Spannung bezeichnet und in Volt (V) gemessen.

Widerstand (R) ist die Eigenschaft des Materials, die den Stromfluss einschränkt, und er wird in Ohm (Ω) gemessen.

Laut Ohmschem Gesetz (solange die Temperatur konstant bleibt) sind Strom, Spannung und Widerstand proportional.
Ein Stromkreisstrom ist proportional zu seiner Spannung und umgekehrt proportional zu seinem Widerstand. 

Daher Strom (I) = Spannung (V) / Widerstand (R).

* `Ohmsches Gesetz - Wikipedia <https://en.wikipedia.org/wiki/Ohm%27s_law>`_

Über das Ohmsche Gesetz können wir ein einfaches Experiment durchführen.

.. image:: img/sp221014_183107.png

Wenn Sie den Draht wechseln, der 5V mit 3,3V verbindet, wird die LED schwächer leuchten.
Wenn Sie den Widerstand von 1k Ohm auf 2k Ohm ändern (Farbring: braun, schwarz, schwarz, braun und braun), werden Sie bemerken, dass die LED schwächer leuchtet als zuvor. Je größer der Widerstand, desto schwächer die LED.

.. note::
    Für eine Einführung in Widerstände und wie man Widerstandswerte berechnet, siehe :ref:`cpn_resistor`.

Die meisten verpackten Module benötigen nur Zugriff auf die richtige Spannung (normalerweise 3,3V oder 5V), wie das Ultraschallmodul.

In Ihren selbstgebauten Schaltungen müssen Sie jedoch auf die Versorgungsspannung und den Widerstandsgebrauch für elektrische Geräte achten.

Zum Beispiel verbrauchen LEDs normalerweise 20mA Strom, und ihr Spannungsabfall beträgt etwa 1,8V. Nach dem Ohmschen Gesetz müssen wir, wenn wir eine 5V Stromversorgung verwenden, einen Widerstand von mindestens 160 Ohm ((5-1,8)/20mA) in den Schaltkreis einfügen, um die LED nicht zu verbrennen.




Arduino zur Schaltkreissteuerung nutzen
----------------------------------------------

Jetzt, da wir ein grundlegendes Verständnis für Arduino-Programmierung und elektronische Schaltkreise haben, ist es an der Zeit, sich der wichtigsten Frage zu widmen: Wie steuert man Schaltkreise mit Arduino?

Einfach ausgedrückt, steuert Arduino einen Schaltkreis, indem es das Niveau der Pins auf dem Board ändert. Zum Beispiel steuert es eine onboard LED, indem es ein hohes oder niedriges Signal an Pin 13 schreibt.

Versuchen wir nun, das Arduino-Board so zu programmieren, dass die LED auf dem Steckbrett blinkt. Bauen Sie den Schaltkreis so, dass die LED an Pin 9 angeschlossen ist.

.. image:: img/wiring_led.png
    :width: 400
    :align: center

Laden Sie anschließend diesen Sketch auf das Arduino-Entwicklungsboard hoch.

.. code-block:: C

    int ledPin = 9;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
    }

Dieser Sketch ähnelt sehr dem, den wir verwendet haben, um das Blinken der onboard LED zu steuern. Der Unterschied ist, dass der Wert von ``ledPin`` nun auf 9 geändert wurde.
Das liegt daran, dass wir dieses Mal versuchen, das Niveau von Pin 9 zu steuern.

Jetzt können Sie sehen, dass die LED auf dem Steckbrett blinkt.

