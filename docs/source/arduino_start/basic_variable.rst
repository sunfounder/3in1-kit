.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Variable
========

Die Variable ist eines der mächtigsten und kritischsten Werkzeuge in einem Programm. Sie hilft uns, Daten in unseren Programmen zu speichern und abzurufen.

Die folgende Skizzen-Datei verwendet Variablen. Sie speichert die Pinnummern der Onboard-LED in der Variable ``ledPin`` und eine Zahl "500" in der Variable ``delayTime``.

.. code-block:: C
    :emphasize-lines: 1,2

    int ledPin = 13;
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

Wartet, ist das ein Duplikat von dem, was ``#define`` macht? Die Antwort ist NEIN.

* Die Rolle von ``#define`` besteht einfach darin, Text direkt zu ersetzen, er wird vom Compiler nicht als Teil des Programms betrachtet.
* Eine ``Variable`` hingegen existiert innerhalb des Programms und wird verwendet, um Wert zu speichern und abzurufen. Eine Variable kann ihren Wert auch innerhalb des Programms ändern, was ein define nicht tun kann.

Die untenstehende Skizzen-Datei fügt sich selbst der Variable hinzu und lässt die Onboard-LED nach jedem Blinken länger blinken.

.. code-block:: C

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
        delayTime = delayTime+200; //Each execution increments the value by 200
    }

Variable deklarieren
-----------------------

Eine Variable zu deklarieren bedeutet, eine Variable zu erstellen.

Um eine Variable zu deklarieren, benötigt man zwei Dinge: den Datentyp und den Variablennamen. Der Datentyp muss durch ein Leerzeichen von der Variable getrennt werden, und die Variablendeklaration muss mit einem ``;`` beendet werden.

Nehmen wir diese Variable als Beispiel.

.. code-block:: C

    int delayTime;

**Datentyp**

Hier ist ``int`` ein Datentyp namens Ganzzahltyp, der verwendet werden kann, um Ganzzahlen von -32768 bis 32766 zu speichern. Er kann auch nicht zum Speichern von Dezimalzahlen verwendet werden.

Variablen können verschiedene Arten von Daten speichern, nicht nur Ganzzahlen. Die Arduino-Sprache (die, erinnern wir uns, C++ ist) hat eingebaute Unterstützung für einige von ihnen (hier sind nur die am häufigsten verwendeten und nützlichsten aufgelistet):

* ``float``: Speichert eine Dezimalzahl, zum Beispiel 3,1415926.
* ``byte``: Kann Zahlen von 0 bis 255 speichern.
* ``boolean``: Speichert nur zwei mögliche Werte, ``True`` oder ``False``, obwohl es einen Byte im Speicher belegt.
* ``char``: Speichert eine Zahl von -127 bis 127. Weil es als ``char`` gekennzeichnet ist, wird der Compiler versuchen, es einem Zeichen aus dem |link_ascii| zuzuordnen.
* ``string``: Kann eine Zeichenkette speichern, z.B. ``Halloween``.

**Variablenname**

Sie können die Variable nach Belieben benennen, z.B. ``i``, ``apple``, ``Bruce``, ``R2D2``, ``Sectumsempra``, aber es gibt einige grundlegende Regeln zu beachten.

1. Beschreiben Sie, wofür sie verwendet wird. Hier habe ich die Variable delayTime benannt, so dass man leicht verstehen kann, was sie tut. Es funktioniert gut, wenn ich die Variable ``barryAllen`` nenne, aber es verwirrt die Person, die den Code ansieht.

2. Verwenden Sie eine gängige Nomenklatur. Sie können CamelCase verwenden, wie ich es getan habe, mit dem Anfangsbuchstaben T in ``delayTime``, so dass es leicht zu sehen ist, dass die Variable aus zwei Wörtern besteht. Sie können auch UnderScoreCase verwenden, um die Variable als ``delay_time`` zu schreiben. Es beeinflusst nicht das Laufen des Programms, aber es würde dem Programmierer helfen, den Code zu lesen, wenn Sie die Nomenklatur verwenden, die Sie bevorzugen.

3. Verwenden Sie keine Schlüsselwörter. Ähnlich wie bei der Eingabe von "int" färbt die Arduino-IDE es, um Sie daran zu erinnern, dass es ein Wort mit einem besonderen Zweck ist und nicht als Variablenname verwendet werden kann. Ändern Sie den Namen der Variable, wenn sie gefärbt ist.

4. Sonderzeichen sind nicht erlaubt. Zum Beispiel: Leerzeichen, #, $, /, +, % usw. Die Kombination aus englischen Buchstaben (Groß-/Kleinschreibung), Unterstrichen und Zahlen (aber Zahlen können nicht als erstes Zeichen eines Variablennamens verwendet werden) ist reichlich vorhanden.

**Einen Wert einer Variable zuweisen**

Nachdem wir die Variable deklariert haben, ist es an der Zeit, die Daten zu speichern. Wir verwenden den Zuweisungsoperator (d.h. ``=``), um den Wert in die Variable zu setzen.

Wir können der Variable Werte zuweisen, sobald wir sie deklariert haben.

.. code-block:: C

    int delayTime = 500;

Es ist auch möglich, ihm zu einem späteren Zeitpunkt einen neuen Wert zuzuweisen.

.. code-block:: C

    int delayTime; // no value
    delayTime = 500; // value is 500
    delayTime = delayTime +200; // value is 700
