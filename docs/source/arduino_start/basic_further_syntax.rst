Skizzieren von Schreibregeln
================================

Wenn Sie einen Freund bitten, das Licht für Sie anzuschalten, können Sie sagen: "Schalte das Licht ein." oder "Licht an, Kumpel.". Sie können jeden beliebigen Tonfall verwenden.

Wenn Sie jedoch möchten, dass das Arduino-Board etwas für Sie erledigt, müssen Sie die Arduino-Programmierschreibregeln befolgen, um die Befehle einzugeben.

Dieses Kapitel enthält die Grundregeln der Arduino-Sprache und wird Ihnen helfen zu verstehen, wie man natürliche Sprache in Code übersetzt.

Natürlich ist dies ein Prozess, mit dem man sich erst mit der Zeit vertraut macht und es ist auch der fehleranfälligste Teil des Prozesses für Anfänger. Also, wenn Sie oft Fehler machen, ist das in Ordnung, versuchen Sie es einfach noch ein paar Mal.

Semikolon ``;``
-------------------

Genauso wie beim Schreiben eines Briefes, bei dem Sie am Ende jeden Satzes einen Punkt als Ende setzen, verlangt die Arduino-Sprache von Ihnen, ``;`` zu verwenden, um dem Board das Ende des Befehls mitzuteilen.

Nehmen wir das bekannte Beispiel "Blinken der Onboard-LED". Eine fehlerfreie Skizze sollte so aussehen:

Beispiel:

.. code-block:: C

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

Als Nächstes schauen wir uns die folgenden zwei Skizzen an und raten, ob sie von Arduino korrekt erkannt werden können, bevor wir sie ausführen.

Skizze A:

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

Skizze B:

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

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

Das Ergebnis ist, dass **Skizze A** einen Fehler meldet und **Skizze B** läuft.

* Die Fehler in **Skizze A** sind fehlende ``;`` und obwohl sie normal aussieht, kann Arduino sie nicht lesen.
* **Skizze B** mag für Menschen unübersichtlich wirken, aber in Wirklichkeit gibt es Einrückungen, Zeilenumbrüche und Leerzeichen in Aussagen in Arduino-Programmen nicht. Daher sieht es für den Arduino-Compiler genaus so aus wie im Beispiel.

Dennoch, bitte schreiben Sie Ihren Code nicht wie in **Skizze B**, denn in der Regel sind es Menschen, die den Code schreiben und betrachten, also machen Sie sich das Leben nicht unnötig schwer.



Geschweifte Klammern ``{}``
------------------------------

``{}`` ist eine Hauptkomponente der Arduino-Programmiersprache, und sie müssen immer paarweise auftreten.
Eine bessere Programmierkonvention ist, direkt nach dem Tippen der linken geschweiften Klammer die rechte zu tippen und dann den Cursor zwischen die geschweiften Klammern zu setzen, um die Anweisung einzufügen.

Kommentare ``//``
--------------------

Kommentare sind Teile des Sketches, die vom Compiler ignoriert werden. Sie werden in der Regel verwendet, um anderen zu erklären, wie das Programm funktioniert.

Wenn wir in einer Codezeile zwei aufeinanderfolgende Schrägstriche schreiben, ignoriert der Compiler alles bis zum Ende dieser Zeile.

Wenn wir einen neuen Sketch erstellen, enthält er bereits zwei Kommentare. Werden diese beiden Kommentare entfernt, wird der Sketch in keiner Weise beeinflusst.

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // put your setup code here, to run once:

    }

    void loop() {
        // put your main code here, to run repeatedly:

    }

Kommentare sind in der Programmierung sehr nützlich, und einige gebräuchliche Verwendungen sind unten aufgeführt.

* Verwendung A: Sich selbst oder anderen mitteilen, was dieser Abschnitt des Codes tut.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); //Set pin 13 to output mode, it controls the onboard LED
    }

    void loop() {
        digitalWrite(13,HIGH); // Activate the onboard LED by setting pin 13 high
        delay(500); // Status quo for 500 ms
        digitalWrite(13,LOW); // Turn off the onboard LED
        delay(500);// Status quo for 500 ms
    }

* Verwendung B: Temporäres Deaktivieren einiger Anweisungen (ohne sie zu löschen) und ihre Reaktivierung, wenn sie benötigt werden, ohne sie neu schreiben zu müssen. Dies ist beim Debuggen von Code und beim Suchen von Programmfehlern sehr hilfreich.

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
    Verwenden Sie die Tastenkombination ``Ctrl+/``, um Ihren Code schnell zu kommentieren oder die Kommentierung aufzuheben.

Kommentare ``/**/``
-------------------

Genauso wie ``//`` für Kommentare. Diese Art von Kommentar kann über mehrere Zeilen gehen. Sobald der Compiler ``/*`` liest, ignoriert er alles Folgende, bis er auf ``*/`` stößt.

Beispiel 1:

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Blink */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        The following code will blink the onboard LED
        You can modify the number in delay() to change the blinking frequency
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }


``#define``
--------------

Dies ist ein nützliches Werkzeug in C++.

.. code-block:: C

    #define Bezeichner Token-String

Der Compiler ersetzt automatisch ``Bezeichner`` durch ``Token-String``, wenn er diesen liest. Dies wird normalerweise zur Definition von Konstanten verwendet.

Als Beispiel hier ein Sketch, der define verwendet, um die Lesbarkeit des Codes zu verbessern.

.. code-block:: C
    :emphasize-lines: 1,2

    #define ONBOARD_LED 13
    #define DELAY_TIME 500

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
        delay(DELAY_TIME); 
        digitalWrite(ONBOARD_LED,LOW); 
        delay(DELAY_TIME);
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

Man kann erkennen, dass der ``Bezeichner`` ersetzt wurde und im Programm nicht vorhanden ist.
Daher gibt es einige Vorsichtsmaßnahmen bei der Verwendung.

1. Ein ``Token-String`` kann nur manuell geändert werden und kann im Programm nicht durch arithmetische Operationen in andere Werte umgewandelt werden.

2. Vermeiden Sie die Verwendung von Symbolen wie ``;``. Zum Beispiel:

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
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
    Eine Namenskonvention für ``#define`` ist, den ``Bezeichner`` groß zu schreiben, um Verwechslungen mit Variablen zu vermeiden.
