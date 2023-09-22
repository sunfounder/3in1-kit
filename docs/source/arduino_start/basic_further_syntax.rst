Skizze Schreibregel
================================

Wenn Sie einen Freund bitten, das Licht für Sie einzuschalten, können Sie sagen: "Schalte das Licht ein.", oder "Licht an, Kumpel.", Sie können jeden Tonfall verwenden, den Sie möchten.

Wenn Sie jedoch möchten, dass das Arduino-Board etwas für Sie tut, müssen Sie die Arduino-Programmiersprache befolgen, um die Befehle einzugeben.

In diesem Kapitel werden die Grundregeln der Arduino-Sprache vorgestellt. Dies wird Ihnen helfen zu verstehen, wie man natürliche Sprache in Code umsetzt.

Natürlich ist dies ein Prozess, mit dem man sich erst mit der Zeit vertraut macht und der für Anfänger am fehleranfälligsten ist. Wenn Sie also oft Fehler machen, ist das in Ordnung. Versuchen Sie es einfach noch ein paar Mal.

Semikolon ``;``
------------------

Genauso wie Sie in einem Brief am Ende eines Satzes einen Punkt setzen, verlangt die Arduino-Sprache, dass Sie ``;`` verwenden, um dem Board das Ende des Befehls mitzuteilen.

Betrachten wir das bekannte Beispiel "Onboard-LED blinkt". Eine korrekte Skizze sollte so aussehen:

Beispiel:

.. code-block:: C

    void setup() {
        // Geben Sie hier Ihren Setup-Code ein, der einmal ausgeführt wird:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // Geben Sie hier Ihren Hauptcode ein, der wiederholt ausgeführt wird:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

Betrachten wir als Nächstes die folgenden beiden Skizzen und raten, ob sie von Arduino korrekt erkannt werden können, bevor wir sie ausführen.

Skizze A:

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // Geben Sie hier Ihren Setup-Code ein, der einmal ausgeführt wird:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // Geben Sie hier Ihren Hauptcode ein, der wiederholt ausgeführt wird:
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

Skizze B:

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // Geben Sie hier Ihren Setup-Code ein, der einmal ausgeführt wird:
        pinMode(13,OUTPUT);
    }

    void loop() {
        // Geben Sie hier Ihren Hauptcode ein, der wiederholt ausgeführt wird:
        digitalWrite(13,HIGH);  
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

Das Ergebnis ist, dass **Skizze A** einen Fehler meldet und **Skizze B** läuft.

* Die Fehler in **Skizze A** fehlen ``;`` und obwohl es normal aussieht, kann es Arduino nicht lesen.
* **Skizze B** sieht zwar für den Menschen merkwürdig aus, jedoch sind Einrückungen, Zeilenumbrüche und Leerzeichen in Aussagen Dinge, die in Arduino-Programmen nicht existieren. Daher sieht es für den Arduino-Compiler genaus so aus wie im Beispiel.

Bitte schreiben Sie Ihren Code jedoch nicht wie **Skizze B**, denn normalerweise sind es Menschen, die den Code schreiben und ansehen, also bringen Sie sich nicht selbst in Schwierigkeiten.

Geschweifte Klammern ``{}``
---------------------------

``{}`` sind die Hauptkomponenten der Arduino-Programmiersprache und sie müssen paarweise auftreten. 
Eine bessere Programmierkonvention ist es, eine Struktur, die geschweifte Klammern benötigt, einzufügen, indem man direkt nach dem Tippen der linken geschweiften Klammer die rechte geschweifte Klammer eintippt und dann den Cursor zwischen die geschweiften Klammern bewegt, um die Anweisung einzufügen.

Kommentar ``//``
-----------------

Ein Kommentar ist der Teil der Skizze, den der Compiler ignoriert. Sie werden normalerweise verwendet, um anderen zu erklären, wie das Programm funktioniert.

Wenn wir in einer Codezeile zwei benachbarte Schrägstriche schreiben, wird der Compiler alles bis zum Ende der Zeile ignorieren.

Erstellen wir eine neue Skizze, wird sie mit zwei Kommentaren geliefert. Wenn wir diese beiden Kommentare entfernen, wird die Skizze in keiner Weise beeinflusst.

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // Geben Sie hier Ihren Setup-Code ein, der einmal ausgeführt wird:

    }

    void loop() {
        // Geben Sie hier Ihren Hauptcode ein, der wiederholt ausgeführt wird:

    }

Kommentare sind in der Programmierung sehr nützlich und einige häufige Anwendungen sind unten aufgeführt.

* Verwendung A: Erklären Sie sich selbst oder anderen, was dieser Abschnitt des Codes macht.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); // Pin 13 auf Ausgangsmodus setzen, er steuert die Onboard-LED
    }

    void loop() {
        digitalWrite(13,HIGH); // Aktivieren der Onboard-LED durch Setzen von Pin 13 auf HIGH
        delay(500); // Status quo für 500 ms
        digitalWrite(13,LOW); // Ausschalten der Onboard-LED
        delay(500);// Status quo für 500 ms
    }


* Verwendung B: Temporäres Deaktivieren einiger Anweisungen (ohne sie zu löschen) und erneutes Kommentieren, wenn sie gebraucht werden, so dass sie nicht neu geschrieben werden müssen. Dies ist sehr nützlich, wenn man Code debuggt und versucht, Programmfehler zu lokalisieren.

.. code-block:: C
    :emphasize-lines: 3,4,5,6

    void setup() {
        pinMode(13,OUTPUT);
        // digitalWrite(13,HIGH);
        // delay(1000);
        // digitalWrite(13,LOW);
        // delay(1000);
    }

    void loop() {
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }

.. note:: 
    Verwenden Sie die Tastenkombination ``Ctrl+/``, um Ihren Code schnell zu kommentieren oder den Kommentar zu entfernen.

Kommentar ``/**/``
------------------

Gleich wie ``//`` für Kommentare. Diese Art von Kommentar kann mehr als eine Zeile lang sein. Sobald der Compiler ``/*`` liest, ignoriert er alles, was danach kommt, bis er auf ``*/`` stößt.

Beispiel 1:

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Blinken */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        Der folgende Code lässt die integrierte LED blinken.
        Sie können die Zahl in delay() ändern, um die Blinkfrequenz zu ändern.
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

``#define``
--------------

Dies ist ein nützliches C++ Werkzeug.

.. code-block:: C

    #define Bezeichner Token-Zeichenfolge

Beim Lesen ersetzt der Compiler automatisch ``Bezeichner`` durch ``Token-Zeichenfolge``, was normalerweise für Konstantendefinitionen verwendet wird.

Als Beispiel hier ein Sketch, der define verwendet, was die Lesbarkeit des Codes verbessert.

.. code-block:: C
    :emphasize-lines: 1,2

    #define BOARD_LED 13
    #define VERZÖGERUNGSZEIT 500

    void setup() {
        pinMode(BOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(BOARD_LED,HIGH); 
        delay(VERZÖGERUNGSZEIT); 
        digitalWrite(BOARD_LED,LOW); 
        delay(VERZÖGERUNGSZEIT);
    }

Für den Compiler sieht es tatsächlich so aus:

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

Wir können sehen, dass der ``Bezeichner`` ersetzt wurde und im Programm nicht existiert.
Deshalb gibt es einige Vorsichtsmaßnahmen bei der Verwendung.

1. Eine ``Token-Zeichenfolge`` kann nur manuell geändert und nicht durch Arithmetik im Programm in andere Werte umgewandelt werden.

2. Vermeiden Sie die Verwendung von Symbolen wie ``;``. Zum Beispiel:

.. code-block:: C
    :emphasize-lines: 1

    #define BOARD_LED 13;

    void setup() {
        pinMode(BOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(BOARD_LED,HIGH); 
    }

Der Compiler wird es wie folgt erkennen, was als Fehler gemeldet wird:

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;,OUTPUT); 
    }

    void loop() {
        digitalWrite(13;,HIGH); 
    }

.. note:: 
    Eine Benennungskonvention für ``#define`` besteht darin, den ``Bezeichner`` zu groß zu schreiben, um Verwirrung mit Variablen zu vermeiden.
