.. _sh_guide:

1.3 Schnellanleitung zu PictoBlox
====================================

Lernen wir nun, wie man PictoBlox in zwei Modi verwendet.

Es gibt auch eine On-Board-LED, die an Pin 13 auf dem R3-Board angeschlossen ist. Wir werden lernen, wie man diese LED in 2 verschiedenen Modi blinken lässt.

.. image:: img/1_led.jpg
    :width: 500
    :align: center

.. _stage_mode:

Bühnenmodus
---------------

**1. Verbindung mit dem Arduino-Board**

Schließen Sie Ihr Arduino-Board mit einem USB-Kabel an den Computer an. In der Regel wird der Computer Ihr Board automatisch erkennen und schließlich einen COM-Port zuweisen.

Öffnen Sie PictoBlox. Die Python-Programmierschnittstelle wird standardmäßig geöffnet. Wir müssen zur Blocks-Schnittstelle wechseln.

.. image:: img/0_choose_blocks.png

Dann sehen Sie in der oberen rechten Ecke die Option zum Wechseln des Modus. Standardmäßig ist der Bühnenmodus aktiviert, auf dem Tobi auf der Bühne steht.

.. image:: img/1_stage_upload.png

Klicken Sie in der oberen rechten Navigationsleiste auf **Board**, um das Board auszuwählen.

.. image:: img/1_board.png

Wählen Sie zum Beispiel **Arduino Uno**.

.. image:: img/1_choose_uno.png

Ein Verbindungsfenster wird geöffnet, in dem Sie den zu verbindenden Port auswählen können. Kehren Sie zur Startseite zurück, wenn die Verbindung hergestellt ist. Wenn Sie die Verbindung während des Gebrauchs unterbrechen, können Sie auch auf **Connect** klicken, um erneut eine Verbindung herzustellen.

.. image:: img/1_connect.png

Gleichzeitig erscheinen im **Block Palette** palettenbezogene Elemente, wie Arduino Uno, Aktuatoren usw.

.. image:: img/1_arduino_uno.png

**2. Firmware hochladen**

Da wir im Bühnenmodus arbeiten möchten, müssen wir die Firmware auf das Board hochladen. Dies gewährleistet die Echtzeitkommunikation zwischen dem Board und dem Computer. Das Hochladen der Firmware ist ein einmaliger Vorgang. Klicken Sie dazu auf die Schaltfläche Firmware hochladen.

Nach einer kurzen Wartezeit wird die Erfolgsmeldung zum Hochladen angezeigt.

.. note::

    Wenn Sie dieses Arduino-Board zum ersten Mal in PictoBlox verwenden oder wenn dieses Arduino zuvor mit der Arduino IDE hochgeladen wurde, müssen Sie auf **Upload Firmware** tippen, bevor Sie es verwenden können.

.. image:: img/1_firmware.png

**3. Programmierung**

* Skript direkt öffnen und ausführen

Natürlich können Sie die Skripte direkt öffnen und ausführen, aber laden Sie sie bitte zuerst von `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_ herunter.

Sie können auf **File** in der oberen rechten Ecke klicken und dann **Open** auswählen.

.. image:: img/0_open.png

Wählen Sie **Open from Computer**.

.. image:: img/0_dic.png

Navigieren Sie dann zu ``3in1-kit\scratch_project\code`` und öffnen Sie **1. Stage Mode.sb3**. Stellen Sie sicher, dass Sie den benötigten Code von `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_ heruntergeladen haben.

.. image:: img/0_stage.png

Klicken Sie direkt auf das Skript, um es auszuführen. Bei manchen Projekten klicken Sie auf die grüne Flagge oder auf das Sprite.

.. image:: img/1_more.png

* Schritt-für-Schritt-Programmierung

Sie können das Skript auch Schritt für Schritt schreiben, indem Sie diesen Anweisungen folgen.

Klicken Sie auf die **Arduino Uno**-Palette.

.. image:: img/1_arduino_uno.png

Die LED auf dem Arduino-Board wird vom digitalen Pin 13 gesteuert (nur 2 Zustände, HIGH oder LOW). Ziehen Sie den Block [set digital pin out as] in den Skriptbereich.

Da der Standardzustand der LED leuchtet, setzen Sie jetzt Pin 13 auf LOW und klicken Sie auf diesen Block. Sie werden sehen, dass die LED erlischt.

* [set digital pin out as]: Setzt die digitalen Pins (2~13) auf (HIGH/LOW) Level.

.. image:: img/1_digital.png

Um den Effekt der kontinuierlich blinkenden LED zu sehen, müssen Sie die Blöcke [Wait 1 seconds] und [forever] aus der **Control**-Palette verwenden. Wenn Sie auf diese Blöcke nach dem Schreiben klicken, zeigt ein gelber Halo, dass sie ausgeführt werden.

* [Wait 1 seconds]: aus der **Control**-Palette, dient zum Festlegen des Zeitintervalls zwischen 2 Blöcken.
* [forever]: aus der **Control**-Palette, ermöglicht es dem Skript, kontinuierlich zu laufen, es sei denn, es wird manuell pausiert.

.. image:: img/1_more.png


.. _upload_mode:

Hochlade-Modus
-----------------

**1. Verbindung zum Arduino-Board herstellen**

Verbinden Sie Ihr Arduino-Board über ein USB-Kabel mit dem Computer. In der Regel wird der Computer Ihr Board automatisch erkennen und schließlich einen COM-Port zuweisen.

Öffnen Sie PictoBlox und klicken Sie in der oberen rechten Navigationsleiste auf **Board**, um das Board auszuwählen.

.. image:: img/1_board.png

Wählen Sie beispielsweise **Arduino Uno**.

.. image:: img/1_choose_uno.png

Ein Verbindungsfenster wird geöffnet, in dem Sie den Port zum Verbinden auswählen können. Nach Abschluss der Verbindung kehren Sie zur Startseite zurück. Wenn die Verbindung während der Nutzung unterbrochen wird, können Sie auch auf **Connect** klicken, um sie wiederherzustellen.

.. image:: img/1_connect.png

Gleichzeitig werden im **Block Palette** Paletten in Bezug auf Arduino Uno, wie z.B. Arduino Uno, Aktuatoren usw., angezeigt.

.. image:: img/1_upload_uno.png

Nach der Auswahl des Hochlade-Modus wird die Bühne zum ursprünglichen Arduino-Codebereich wechseln.

.. image:: img/1_upload.png

**2. Programmierung**

* Skript direkt öffnen und ausführen

Sie können in der oberen rechten Ecke auf **File** klicken.

.. image:: img/0_open.png

Wählen Sie **Open from Computer**.

.. image:: img/0_dic.png

Navigieren Sie dann zum Pfad ``3in1-kit\scratch_project\code`` und öffnen Sie **1. Upload Mode.sb3**. Stellen Sie sicher, dass Sie den erforderlichen Code von `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_ heruntergeladen haben.

.. image:: img/0_upload.png

Klicken Sie abschließend auf die Schaltfläche **Upload Code**.

.. image:: img/1_upload_code.png


* Programmierung Schritt für Schritt

Sie können das Skript auch Schritt für Schritt schreiben, indem Sie diesen Anweisungen folgen.

Klicken Sie auf die **Arduino Uno**-Palette.

.. image:: img/1_upload_uno.png

Ziehen Sie [when Arduino Uno starts up] in den Skriptbereich. Dies ist für jedes Skript erforderlich.

.. image:: img/1_uno_starts.png

Die LED auf dem Arduino-Board wird durch den digitalen Pin13 gesteuert (nur 2 Zustände HIGH oder LOW). Ziehen Sie also den Block [set digital pin out as] in den Skriptbereich.

Da der Standardzustand der LED beleuchtet ist, stellen Sie Pin 13 jetzt auf LOW und klicken Sie auf diesen Block. Sie werden sehen, dass die LED erlischt.

* [set digital pin out as]: Setzt den digitalen Pin (2~13) auf den (HIGH/LOW) Zustand.

.. image:: img/1_upload_digital.png

An diesem Punkt wird der Arduino-Code auf der rechten Seite angezeigt. Wenn Sie diesen Code bearbeiten möchten, können Sie den Bearbeitungsmodus aktivieren.

.. image:: img/1_upload1.png

Um den Effekt einer kontinuierlich blinkenden LED zu sehen, müssen Sie die [Wait 1 seconds] und [forever] Blöcke aus der **Control**-Palette verwenden. Klicken Sie nach dem Schreiben auf diese Blöcke. Ein gelber Halo bedeutet, dass sie ausgeführt werden.

* [Wait 1 seconds]: aus der **Control**-Palette, um das Zeitintervall zwischen 2 Blöcken festzulegen.
* [forever]: aus der **Control**-Palette, lässt das Skript laufen, es sei denn, die Stromversorgung wird unterbrochen.

.. image:: img/1_upload_more.png

Klicken Sie abschließend auf die Schaltfläche **Upload Code**.

.. image:: img/1_upload_code.png
