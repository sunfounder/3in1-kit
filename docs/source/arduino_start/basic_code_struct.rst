Struktur eines Arduino-Programms
======================================

Werfen wir einen Blick auf die neue Skizze. Obwohl sie nur wenige Codezeilen enthält, handelt es sich tatsächlich um eine "leere" Skizze.
Das Hochladen dieser Skizze auf das Entwicklungsboard wird keine Aktion auslösen.

.. code-block:: C

    void setup() {
    // Fügen Sie Ihren Setup-Code hier ein, der einmal ausgeführt wird:

    }

    void loop() {
    // Fügen Sie Ihren Hauptcode hier ein, der wiederholt ausgeführt wird:

    }

Wenn wir ``setup()`` und ``loop()`` entfernen und die Skizze zu einer wirklichen ``leeren`` Datei machen, werden Sie feststellen, dass sie die Überprüfung nicht besteht.
Sie sind das Äquivalent zum menschlichen Skelett und unverzichtbar.

Während des Skizzierens wird ``setup()`` zuerst ausgeführt und der Code darin (innerhalb von ``{}``) wird nach dem Einschalten oder Zurücksetzen des Boards einmal ausgeführt. 
``loop()`` dient zum Schreiben der Hauptfunktion, und der darin enthaltene Code wird in einer Schleife nach der Ausführung von ``setup()`` wiederholt.

Um setup() und loop() besser zu verstehen, betrachten wir vier Skizzen. Ihr Ziel ist es, die integrierte LED des Arduino blinken zu lassen. Bitte führen Sie jedes Experiment nacheinander aus und notieren Sie die spezifischen Effekte.

* Skizze 1: Lassen Sie die integrierte LED kontinuierlich blinken.

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // Fügen Sie Ihren Setup-Code hier ein, der einmal ausgeführt wird:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // Fügen Sie Ihren Hauptcode hier ein, der wiederholt ausgeführt wird:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

* Skizze 2: Lassen Sie die integrierte LED nur einmal blinken. 

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // Fügen Sie Ihren Setup-Code hier ein, der einmal ausgeführt wird:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // Fügen Sie Ihren Hauptcode hier ein, der wiederholt ausgeführt wird:
    }

* Skizze 3: Lassen Sie die integrierte LED einmal langsam und dann schnell blinken.

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // Fügen Sie Ihren Setup-Code hier ein, der einmal ausgeführt wird:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // Fügen Sie Ihren Hauptcode hier ein, der wiederholt ausgeführt wird:
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* Skizze 4: Meldet einen Fehler.

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // Fügen Sie Ihren Setup-Code hier ein, der einmal ausgeführt wird:
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // Fügen Sie Ihren Hauptcode hier ein, der wiederholt ausgeführt wird:
    }    

Mit Hilfe dieser Skizzen können wir mehrere Merkmale von ``setup-loop`` zusammenfassen.

* ``loop()`` wird wiederholt ausgeführt, nachdem das Board eingeschaltet wurde.
* ``setup()`` wird nur einmal ausgeführt, nachdem das Board eingeschaltet wurde.
* Nach dem Einschalten des Boards wird zuerst ``setup()`` und dann ``loop()`` ausgeführt.
* Der Code muss innerhalb des ``{}``-Bereichs von ``setup()`` oder ``loop()`` geschrieben werden, außerhalb des Rahmens tritt ein Fehler auf.

.. note::  
    Anweisungen wie ``digitalWrite(13,HIGH)`` dienen zur Steuerung der integrierten LED, und ihre Verwendung wird in späteren Kapiteln ausführlich besprochen.
