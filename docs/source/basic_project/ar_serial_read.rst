.. _ar_serial_read:

5.12 Serielles Lesen
======================

Vielleicht haben Sie dies bemerkt, wenn Sie die Funktion ``Serial.print()`` verwendet haben. 
Wo es Drucken gibt, gibt es auch Lesen? Wofür wird das Textfeld im Serial Monitor verwendet?
Richtig geraten, es gibt Möglichkeiten, Programme und Schaltungen durch Eingabe von Informationen über das Textfeld im Serial Monitor zu steuern.

In diesem Projekt werden wir das I2C LCD1602 verwenden, um den im Serial Monitor eingegebenen Text anzuzeigen und die Verwendung von ``Serial.read()`` zu erleben.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

**Schaltplan**

.. image:: img/circuit_7.1_lcd1602.png

**Verdrahtung**

.. image:: img/5.11_lcd_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.12.serial_read.ino`` im Pfad ``3in1-kit\learning_project\5.12.serial_read``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Die Bibliothek ``LiquidCrystal I2C`` wird hier verwendet. Sie können sie aus dem **Library Manager** installieren.

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/a6197c53-6969-402e-8930-84a9165397b9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, können Sie Text in das Textfeld des Serial Monitors eingeben, und das LCD wird die Informationen anzeigen.

**Wie funktioniert das?**

    .. code-block:: arduino

        void loop()
        {
        // when characters arrive over the serial port...
            if (Serial.available()) {
                // wait a bit for the entire message to arrive
                delay(100);
                // clear the screen
                lcd.clear();
                // read all the available characters
                while (Serial.available() > 0) {
                    // display each character to the LCD
                    lcd.write(Serial.read());
                }
            }
        }

* Mit ``Serial.available()`` können Sie die Anzahl der verfügbaren Zeichen im eingehenden Stream abrufen, wenn Sie etwas aus dem Textfeld eingeben. Da es zwei Terminator in der Eingabe gibt, haben Sie tatsächlich 3 Zeichen, wenn Sie ``A`` eingeben, und 4 Zeichen, wenn Sie ``AB`` eingeben.
* ``Serial.read()`` nimmt das erste Zeichen aus dem eingehenden Stream. Wenn Sie beispielsweise ``AB`` eingegeben haben und ``Serial.read()`` nur einmal aufrufen, erhalten Sie das Zeichen ``A``; beim zweiten Aufruf erhalten Sie ``B``; beim dritten und vierten Aufruf erhalten Sie zwei Endsymbole. Wenn dieser Funktion aufgerufen wird und im Eingabestream keine Zeichen verfügbar sind, führt dies zu einem Fehler.

Zusammenfassend wird häufig kombiniert, die beiden oben genannten, indem eine ``while`` Schleife verwendet wird, um alle jedes Mal eingegebenen Zeichen zu lesen.

    .. code-block:: arduino

        while (Serial.available() > 0) {
            Serial.print(Serial.read());
        }

Übrigens, wenn Sie ``Serial.read()`` nicht verwenden, um Zeichen aus dem eingehenden Stream zu holen, werden die Zeichen des eingehenden Streams zusammengefügt.
Zum Beispiel, wenn Sie ``A`` gefolgt von ``AB`` eingeben, wird der eingehende Stream 7 Zeichen ansammeln.
