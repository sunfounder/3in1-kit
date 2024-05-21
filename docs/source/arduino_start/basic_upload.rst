.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Wie lädt man den Sketch auf das Board hoch?
=============================================

In diesem Abschnitt lernen Sie, wie Sie den zuvor erstellten Sketch auf das Arduino-Board hochladen und welche Aspekte dabei zu beachten sind.

**1. Board und Port auswählen**

Arduino-Entwicklungsboards werden in der Regel mit einem USB-Kabel geliefert. Sie können es verwenden, um das Board mit Ihrem Computer zu verbinden.

Wählen Sie das richtige **Board** und den richtigen **Port** in der Arduino IDE aus. Normalerweise werden Arduino-Boards vom Computer automatisch erkannt und einem Port zugewiesen, den Sie hier auswählen können.

    .. image:: img/board_port.png

Wenn Ihr Board bereits angeschlossen ist, aber nicht erkannt wird, überprüfen Sie, ob das **INSTALLED**-Logo im Abschnitt **Arduino UNO R4 Boards** des **Boards Managers** angezeigt wird. Wenn nicht, scrollen Sie bitte ein wenig nach unten und klicken Sie auf **INSTALL**.

    .. image:: img/upload1.png

Das erneute Öffnen der Arduino IDE und das erneute Anschließen des Arduino-Boards beheben die meisten Probleme. Sie können auch auf **Werkzeuge (Tools)** -> **Board** oder **Port** klicken, um diese auszuwählen.

**2. Den Sketch überprüfen**

Nachdem Sie auf die Schaltfläche Überprüfen (Verify) geklickt haben, wird der Sketch kompiliert, um zu sehen, ob Fehler vorliegen.

    .. image:: img/sp221014_174532.png

Damit können Sie Fehler finden, falls Sie einige Zeichen gelöscht oder einige Buchstaben versehentlich eingetippt haben. In der Nachrichtenzeile können Sie sehen, wo und welche Art von Fehlern aufgetreten sind.

    .. image:: img/sp221014_175307.png

Wenn keine Fehler vorhanden sind, sehen Sie eine Meldung wie die untenstehende.

    .. image:: img/sp221014_175512.png

**3. Sketch hochladen**

Nach Abschluss der oben genannten Schritte klicken Sie auf die Schaltfläche **Hochladen (Upload)**, um diesen Sketch auf das Board zu laden.

    .. image:: img/sp221014_175614.png

Wenn dies erfolgreich war, sehen Sie die folgende Aufforderung.

    .. image:: img/sp221014_175654.png

Gleichzeitig blinkt die LED auf dem Board.

    .. image:: img/1_led.jpg

Das Arduino-Board führt den Sketch automatisch aus, sobald es nach dem Hochladen des Sketchs mit Strom versorgt wird. Das laufende Programm kann durch Hochladen eines neuen Sketches überschrieben werden.
