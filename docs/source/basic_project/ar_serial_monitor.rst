.. _ard_serial_monitor:

3.0 Serieller Monitor
=============================

In der Arduino IDE gibt es einen seriellen Monitor, mit dem Sie Nachrichten von Ihrem Computer an das Arduino-Board (über USB) senden und auch Nachrichten vom Arduino empfangen können.

In diesem Projekt werden wir also lernen, wie man Daten vom Arduino-Board empfängt.

.. note::

    Bei Uno, Nano, Mini und Mega werden die Pins 0 und 1 für die Kommunikation mit dem Computer verwendet. Wenn Sie etwas an diese Pins anschließen, kann dies die Kommunikation stören, einschließlich fehlgeschlagener Uploads zum Board.


**Verwendung des seriellen Monitors**

1. Öffnen Sie die Arduino IDE und fügen Sie den folgenden Code ein.

    .. code-block:: arduino

        // the setup routine runs once when you press reset:
        void setup() {
            // initialize serial communication at 9600 bits per second:
            Serial.begin(9600);
        }

        // the loop routine runs over and over again forever:
        void loop() {
            int number = 100;
            Serial.println(number);
            Serial.println("Hello world");
            delay(100);         // delay in between reads for stability
        }

   * `Serial.begin() <https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/>`_: Legt die Datenrate in Bits pro Sekunde (Baud) für die serielle Datenübertragung fest, hier auf 9600 eingestellt.
   * `Serial.println() <https://www.arduino.cc/reference/en/language/functions/communication/serial/println/>`_: Gibt Daten als menschenlesbaren ASCII-Text an den seriellen Port gefolgt von einem Wagenrücklauf-Zeichen (ASCII 13 oder '\r') und einem Zeilenumbruch-Zeichen (ASCII 10 oder '\n') aus. Dieser Befehl hat dieselben Formen wie `Serial.print() <https://www.arduino.cc/reference/en/language/functions/communication/serial/print/>`_.

2. Wählen Sie das korrekte Board und den Port, um den Code hochzuladen.
3. Klicken Sie in der Symbolleiste auf das Vergrößerungsglas-Symbol, um den seriellen Monitor zu starten.

.. image:: img/serial1.png
    :align: center

4. Hier sehen Sie den seriellen Monitor.

.. image:: img/serial2.png
    :align: center

* **1**: Option zum automatischen Scrollen oder Nicht-Scrollen.
* **2**: Option zur Anzeige eines Zeitstempels vor den auf dem seriellen Monitor angezeigten Daten.
* **3**: Endauswahl: Auswahl der Zeichen, die an die Daten angehängt werden, die an Arduino gesendet werden. Auswahlmöglichkeiten:

        * **Kein Zeilenumbruch**: Sendet einfach, was Sie eingeben; 
        * **Neue Zeile** entspricht ``\n`` und sendet nach Ihrer Eingabe einen ASCII-Zeilenumbruch;
        * **Wagenrücklauf** entspricht ``\r``, sendet nach Ihrer Eingabe ein ASCII-Wagenrücklauf-Zeichen; 
        * **Beide NL & CR** entsprechen ``\r\n`` und senden sowohl ein Wagenrücklauf- als auch ein Zeilenumbruch-Zeichen nach Ihrer Eingabe.
* **4**: Wählen Sie die Kommunikationsgeschwindigkeit zwischen Arduino-Board und PC. Dieser Wert MUSS dem in ``Serial.begin()`` eingestellten Wert entsprechen.
* **5**: Löscht den gesamten Text auf der Ausgabekonsole.
* **6**: Ein Textfeld zum Senden von Zeichen an das Arduino-Board. Siehe :ref:`ar_serial_read` für ein Tutorial.
