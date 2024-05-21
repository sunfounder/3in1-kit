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
===========

Die Variable ist eines der mächtigsten und wichtigsten Werkzeuge in einem Programm. Sie hilft uns, Daten in unseren Programmen zu speichern und abzurufen.

Im folgenden Skizzenbeispiel werden Variablen verwendet. Es speichert die Pin-Nummern der an Bord befindlichen LED in der Variable ``ledPin`` und eine Zahl "500" in der Variable ``delayTime``.

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

Warte mal, ist das nicht das Gleiche, was ``#define`` tut? Die Antwort ist NEIN.

* Die Rolle von ``#define`` besteht lediglich darin, Text einfach und direkt zu ersetzen; der Compiler betrachtet es nicht als Teil des Programms. 
* Eine ``Variable`` hingegen existiert innerhalb des Programms und wird verwendet, um Werte zu speichern und abzurufen. Eine Variable kann ihren Wert auch innerhalb des Programms ändern, was ein Define nicht kann.

Die folgende Skizze addiert selbst zur Variable und lässt die an Bord befindliche LED nach jedem Blinken länger blinken.

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
        delayTime = delayTime+200; //Bei jeder Ausführung wird der Wert um 200 erhöht
    }

Eine Variable deklarieren
----------------------------

Eine Variable zu deklarieren bedeutet, eine Variable zu erstellen. 

Um eine Variable zu deklarieren, benötigen Sie zwei Dinge: den Datentyp und den Variablennamen. Der Datentyp muss durch ein Leerzeichen von der Variable getrennt sein, und die Variablendeklaration muss mit einem ``;`` beendet werden.

Betrachten wir diese Variable als Beispiel.

.. code-block:: C

    int delayTime;

**Datentyp**

Hier ist ``int`` ein Datentyp, der als Integer-Typ bezeichnet wird und verwendet werden kann, um Ganzzahlen von -32768 bis 32766 zu speichern. Es kann auch nicht verwendet werden, um Dezimalzahlen zu speichern.

Variablen können neben Ganzzahlen auch andere Arten von Daten speichern. Die Arduino-Sprache (die, wie wir uns erinnern, C++ ist) hat eingebauten Support für einige von ihnen (hier sind nur die am häufigsten verwendeten und nützlichsten aufgeführt):

* ``float``: Speichert eine Dezimalzahl, zum Beispiel 3,1415926.
* ``byte``: Kann Zahlen von 0 bis 255 speichern.
* ``boolean``: Speichert nur zwei mögliche Werte, ``True`` oder ``False``, obwohl es einen Byte im Speicher belegt.
* ``char``: Speichert eine Zahl von -127 bis 127. Da es als ``char`` markiert ist, wird der Compiler versuchen, es einem Zeichen aus dem |link_ascii| zuzuordnen.
* ``string``: Kann eine Zeichenkette speichern, z.B. ``Halloween``.

**Variablenname**

Sie können der Variable einen beliebigen Namen geben, wie ``i``, ``apple``, ``Bruce``, ``R2D2``, ``Sectumsempra``, aber es gibt einige grundlegende Regeln zu beachten.

1. Beschreiben Sie, wofür es verwendet wird. Hier habe ich die Variable delayTime genannt, damit man leicht verstehen kann, was sie tut. Es wäre in Ordnung, wenn ich die Variable ``barryAllen`` nenne, aber es verwirrt die Person, die den Code anschaut.

2. Verwenden Sie eine gebräuchliche Schreibweise. Sie können CamelCase verwenden, wie ich es getan habe, mit dem anfänglichen T in ``delayTime`` , damit man leicht sehen kann, dass die Variable aus zwei Wörtern besteht. Sie können auch UnderScoreCase verwenden, um die Variable als ``delay_time`` zu schreiben. Es hat keinen Einfluss auf das Laufen des Programms, aber es würde dem Programmierer helfen, den Code zu lesen, wenn Sie die bevorzugte Schreibweise verwenden.

3. Verwenden Sie keine Schlüsselwörter. Ähnlich wie beim Tippen von "int" färbt die Arduino IDE es ein, um Sie daran zu erinnern, dass es ein Wort mit einem besonderen Zweck ist und nicht als Variablenname verwendet werden kann. Ändern Sie den Namen der Variable, wenn sie eingefärbt ist.

4. Spezialsymbole sind nicht erlaubt. Zum Beispiel: Leerzeichen, #, $, /, +, %, usw. Die Kombination aus englischen Buchstaben (Groß-/Kleinschreibung beachten), Unterstrichen und Zahlen (aber Zahlen dürfen nicht als erstes Zeichen eines Variablennamens verwendet werden) ist reichhaltig genug.

**Einen Wert einer Variable zuweisen**

Nachdem wir die Variable deklariert haben, ist es an der Zeit, die Daten zu speichern. Wir verwenden den Zuweisungsoperator (d.h. ``=``), um den Wert in die Variable zu setzen.

Wir können der Variable einen Wert zuweisen, sobald wir sie deklarieren.

.. code-block:: C

    int delayTime = 500;

Es ist auch möglich, ihr zu einem späteren Zeitpunkt einen neuen Wert zuzuweisen.

.. code-block:: C

    int delayTime; // kein Wert
    delayTime = 500; // Wert ist 500
    delayTime = delayTime +200; // Wert ist 700
