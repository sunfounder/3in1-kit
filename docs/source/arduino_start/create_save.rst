Wie erstellt, öffnet oder speichert man die Skizze?
=========================================================

#. Wenn Sie die Arduino IDE zum ersten Mal öffnen oder eine neue Skizze erstellen, sehen Sie eine Seite wie diese, auf der die Arduino IDE eine neue Datei für Sie erstellt, die als "Skizze" bezeichnet wird.

    .. image:: img/sp221014_173458.png

    Diese Skizzendateien haben einen regelmäßigen temporären Namen, aus dem Sie das Erstellungsdatum der Datei ableiten können. ``sketch_oct14a.ino`` bedeutet die erste Skizze vom 14. Oktober, ``.ino`` ist das Dateiformat dieser Skizze.

#. Jetzt versuchen wir, eine neue Skizze zu erstellen. Kopieren Sie den folgenden Code in die Arduino IDE, um den ursprünglichen Code zu ersetzen.

        .. image:: img/create1.png

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

#. Drücken Sie ``Ctrl+S`` oder klicken Sie auf **Datei (File)** -> **Speichern (Save)**. Die Skizze wird standardmäßig unter ``C:\Users\{Ihr_Benutzername}\Dokumente\Arduino`` gespeichert. Sie können sie umbenennen oder einen neuen Pfad zum Speichern auswählen.

    .. image:: img/create2.png

#. Nachdem Sie erfolgreich gespeichert haben, werden Sie feststellen, dass der Name in der Arduino IDE aktualisiert wurde.

    .. image:: img/create3.png

Bitte fahren Sie mit dem nächsten Abschnitt fort, um zu lernen, wie Sie diese erstellte Skizze auf Ihr Arduino-Board hochladen.
