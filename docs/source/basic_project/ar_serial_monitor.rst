.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ard_serial_monitor:

3.0 Serieller Monitor
=============================

In der Arduino IDE gibt es einen seriellen Monitor, der es ermöglicht, Nachrichten von Ihrem Computer zum Arduino-Board (über USB) zu senden und auch Nachrichten vom Arduino zu empfangen.

In diesem Projekt werden wir also lernen, wie man Daten vom Arduino-Board empfängt.

.. note::

    Bei Uno, Nano, Mini und Mega werden die Pins 0 und 1 zur Kommunikation mit dem Computer verwendet. Das Anschließen von Geräten an diese Pins kann die Kommunikation stören, einschließlich fehlgeschlagener Uploads zum Board.


**Verwendung des seriellen Monitors**

1. Öffnen Sie die Arduino IDE und fügen Sie den folgenden Code ein.

    .. code-block:: arduino

        // Die Setup-Routine wird einmal ausgeführt, wenn Sie Reset drücken:
        void setup() {
            // Initialisiere die serielle Kommunikation mit 9600 Baud:
            Serial.begin(9600);
        }

        // Die Loop-Routine wird immer und immer wieder ausgeführt:
        void loop() {
            int number = 100;
            Serial.println(number);
            Serial.println("Hello world");
            delay(100);         // Verzögerung zwischen den Abfragen für Stabilität
        }

   * `Serial.begin() <https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/>`_: Legt die Datenrate in Bits pro Sekunde (Baud) für die serielle Datenübertragung fest, hier auf 9600 eingestellt.
   * `Serial.println() <https://www.arduino.cc/reference/en/language/functions/communication/serial/println/>`_: Sendet Daten zum seriellen Port als menschenlesbaren ASCII-Text, gefolgt von einem Wagenrücklauf (ASCII 13 oder '\r') und einem Zeilenumbruch (ASCII 10 oder '\n'). Dieser Befehl entspricht `Serial.print() <https://www.arduino.cc/reference/en/language/functions/communication/serial/print/>`_.

2. Wählen Sie das richtige Board und den richtigen Port aus, um den Code hochzuladen.
3. Klicken Sie in der Symbolleiste auf das Lupensymbol, um den seriellen Monitor zu aktivieren.

.. image:: img/serial1.png
    :align: center

4. Hier sehen Sie den seriellen Monitor.

.. image:: img/serial2.png
    :align: center

* **1**: Option, um automatisch zu scrollen oder nicht zu scrollen.
* **2**: Option, um einen Zeitstempel vor den im seriellen Monitor angezeigten Daten anzuzeigen.
* **3**: Auswahl des Zeilenendes, wählt die Zeichen aus, die den an Arduino gesendeten Daten hinzugefügt werden. Auswahl beinhaltet:

        * **Kein Zeilenumbruch** sendet nur, was Sie eingeben; 
        * **Zeilenumbruch** ist ``\n`` und sendet nach Ihrer Eingabe einen ASCII-Zeilenumbruchcode;
        * **Wagenrücklauf** ist ``\r`` und sendet nach Ihrer Eingabe ein ASCII-Wagenrücklaufzeichen;
        * **Beides, NL & CR** ist ``\r\n`` und sendet nach Ihrer Eingabe sowohl ein Wagenrücklauf- als auch ein Zeilenumbruchzeichen.
* **4**: Wählen Sie die Kommunikationsgeschwindigkeit zwischen Arduino-Board und PC. Dieser Wert MUSS dem in ``Serial.begin()`` eingestellten Wert entsprechen.
* **5**: Löscht den gesamten Text auf der Ausgabekonsole.
* **6**: Ein Textfeld, um Zeichen an das Arduino-Board zu senden, siehe :ref:`ar_serial_read` für ein Tutorial.


