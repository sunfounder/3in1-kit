Struktur des Arduino-Programms
====================================

Werfen wir einen Blick auf die neue Skizze. Obwohl sie nur wenige Codezeilen enthält, handelt es sich tatsächlich um eine "leere" Skizze. 
Wenn Sie diese Skizze auf das Entwicklungsboard hochladen, wird nichts passieren.

.. code-block:: C

    void setup() {
    // put your setup code here, to run once:

    }

    void loop() {
    // put your main code here, to run repeatedly:

    }

Wenn wir ``setup()`` und ``loop()`` entfernen und die Skizze zu einer echten ``blank``-Datei machen, werden Sie feststellen, dass sie die Überprüfung nicht besteht. 
Sie sind das Äquivalent zum menschlichen Skelett und unverzichtbar.

Beim Skizzieren wird ``setup()`` zuerst ausgeführt, und der darin enthaltene Code (innerhalb von ``{}``) wird nach dem Einschalten oder Zurücksetzen des Boards nur einmal ausgeführt.
``loop()`` wird verwendet, um das Hauptfeature zu schreiben, und der darin enthaltene Code wird in einer Schleife nach der Ausführung von ``setup()`` ausgeführt.

Um setup() und loop() besser zu verstehen, verwenden wir vier Skizzen. Ihr Ziel ist es, die LED auf dem Arduino-Board blinken zu lassen. Bitte führen Sie jedes Experiment nacheinander durch und notieren Sie die spezifischen Effekte.

* Skizze 1: Lassen Sie die LED auf dem Board kontinuierlich blinken.

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

* Skizze 2: Lassen Sie die LED auf dem Board nur einmal blinken.

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // put your main code here, to run repeatedly:
    }

* Skizze 3: Lassen Sie die LED auf dem Board einmal langsam blinken und dann schnell blinken.

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* Skizze 4: Fehlermeldung.

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // put your main code here, to run repeatedly:
    }    

Mit Hilfe dieser Skizzen können wir mehrere Merkmale von ``setup-loop`` zusammenfassen.

* ``loop()`` wird wiederholt ausgeführt, nachdem das Board eingeschaltet wurde. 
* ``setup()`` wird nur einmal ausgeführt, nachdem das Board eingeschaltet wurde. 
* Nach dem Einschalten des Boards wird zuerst ``setup()`` und anschließend ``loop()`` ausgeführt.
* Der Code muss im ``{}``-Bereich von ``setup()`` oder ``loop()`` geschrieben werden. Außerhalb des Rahmens wird ein Fehler auftreten.

.. note::  
    Anweisungen wie ``digitalWrite(13,HIGH)`` dienen zur Steuerung der LED auf dem Board. Ihre genaue Verwendung wird in späteren Kapiteln besprochen.
