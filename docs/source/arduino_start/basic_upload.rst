Wie lädt man die Skizze auf das Board hoch?
=============================================

In diesem Abschnitt erfahren Sie, wie Sie die zuvor erstellte Skizze auf das Arduino-Board hochladen und einige Überlegungen dazu kennen lernen.

**1. Board und Port auswählen**

Arduino-Entwicklungsboards werden in der Regel mit einem USB-Kabel geliefert. Sie können es verwenden, um das Board mit Ihrem Computer zu verbinden.

Wählen Sie das richtige **Board** und den **Port** in der Arduino IDE aus. Normalerweise werden Arduino-Boards automatisch vom Computer erkannt und einem Port zugewiesen, den Sie hier auswählen können.

    .. image:: img/board_port.png

Wenn Ihr Board bereits angeschlossen ist, aber nicht erkannt wird, überprüfen Sie, ob das **INSTALLED**-Logo im Abschnitt **Arduino AVR Boards** des **Boards-Manager** erscheint. Wenn nicht, scrollen Sie bitte etwas nach unten und klicken auf **INSTALL**.

    .. image:: img/upload1.png

Ein erneutes Öffnen der Arduino IDE und das erneute Anstecken des Arduino-Boards beheben die meisten Probleme. Sie können auch auf **Tools** -> **Board** oder **Port** klicken, um sie auszuwählen.

**2. Überprüfen der Skizze**

Nachdem Sie auf die Überprüfen-Schaltfläche geklickt haben, wird die Skizze kompiliert, um festzustellen, ob Fehler vorliegen.

    .. image:: img/sp221014_174532.png

Sie können es verwenden, um Fehler zu finden, wenn Sie einige Zeichen löschen oder versehentlich einige Buchstaben eingeben. In der Nachrichtenleiste können Sie sehen, wo und welche Art von Fehlern aufgetreten sind.

    .. image:: img/sp221014_175307.png

Wenn keine Fehler vorliegen, sehen Sie eine Nachricht wie die unten stehende.

    .. image:: img/sp221014_175512.png

**3. Skizze hochladen**

Nach Abschluss der oben genannten Schritte klicken Sie auf die **Upload**-Schaltfläche, um diese Skizze auf das Board hochzuladen.

    .. image:: img/sp221014_175614.png

Wenn der Vorgang erfolgreich war, sehen Sie den folgenden Hinweis.

.. image:: img/sp221014_175654.png

Gleichzeitig blinkt die LED auf dem Board.

.. image:: img/1_led.jpg

Das Arduino-Board führt die Skizze automatisch aus, sobald nach dem Hochladen der Skizze Strom angelegt wird. Das laufende Programm kann durch Hochladen einer neuen Skizze überschrieben werden.
