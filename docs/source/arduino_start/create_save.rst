.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Wie erstellt, öffnet oder speichert man den Sketch?
=======================================================

#. Wenn Sie die Arduino IDE zum ersten Mal öffnen oder einen neuen Sketch erstellen, sehen Sie eine Seite wie diese, auf der die Arduino IDE eine neue Datei für Sie erstellt, die als "Sketch" bezeichnet wird.

    .. image:: img/sp221014_173458.png

    Diese Sketch-Dateien haben einen regelmäßigen temporären Namen, aus dem hervorgeht, an welchem Datum die Datei erstellt wurde. ``sketch_oct14a.ino`` bedeutet den ersten Sketch vom 14. Oktober, ``.ino`` ist das Dateiformat dieses Sketchs.

#. Versuchen wir nun, einen neuen Sketch zu erstellen. Kopieren Sie den folgenden Code in die Arduino IDE, um den ursprünglichen Code zu ersetzen.

        .. image:: img/create1.png

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

#. Drücken Sie ``Ctrl+S`` oder klicken Sie auf **Datei (File)** -> **Speichern (Save)**. Der Sketch wird standardmäßig unter ``C:\Users\{Ihr_Benutzername}\Documents\Arduino`` gespeichert. Sie können ihn umbenennen oder einen neuen Pfad zum Speichern finden.

    .. image:: img/create2.png

#. Nach dem erfolgreichen Speichern sehen Sie, dass der Name in der Arduino IDE aktualisiert wurde.

    .. image:: img/create3.png

Bitte fahren Sie mit dem nächsten Abschnitt fort, um zu erfahren, wie Sie diesen erstellten Sketch auf Ihr Arduino-Board hochladen.
