.. _ar_serial_read:

5.12 Serielle Lektüre
==========================

Vielleicht haben Sie dies bemerkt, als Sie die Funktion ``Serial.print()`` verwendet haben.
Da es eine Ausgabe gibt, gibt es auch eine Eingabe? Wofür ist das Textfeld im Seriellen Monitor?
Ja, Sie haben richtig geraten. Es gibt Möglichkeiten, Programme und Schaltungen durch Eingabe von Informationen über das Textfeld des seriellen Monitors zu steuern.

In diesem Projekt verwenden wir das I2C LCD1602, um den im Seriellen Monitor eingegebenen Text anzuzeigen und die Verwendung von ``Serial.read()`` kennenzulernen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können diese auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

**Schaltplan**

.. image:: img/circuit_7.1_lcd1602.png

**Verdrahtung**

.. image:: img/lcd_bb.jpg
    :width: 800
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.12.serial_read.ino`` unter dem Pfad ``3in1-kit\basic_project\5.12.serial_read``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Hier wird die Bibliothek ``LiquidCrystal I2C`` verwendet. Sie können sie aus dem **Library Manager** installieren.

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/a6197c53-6969-402e-8930-84a9165397b9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, können Sie Text in das Textfeld des seriellen Monitors eingeben, und das LCD zeigt die Informationen an.

**Wie funktioniert das?**

    .. code-block:: arduino

        void loop()
        {
        // wenn Zeichen über die serielle Schnittstelle ankommen...
            if (Serial.available()) {
                // warten Sie kurz, damit die gesamte Nachricht ankommt
                delay(100);
                // den Bildschirm leeren
                lcd.clear();
                // lesen Sie alle verfügbaren Zeichen
                while (Serial.available() > 0) {
                    // zeigt jedes Zeichen auf dem LCD an
                    lcd.write(Serial.read());
                }
            }
        }

* ``Serial.available()`` kann die Anzahl der Zeichen in dem eingehenden Stream erhalten, wenn Sie etwas aus dem Textfeld eingeben. Da es in der Eingabe zwei Abschlusszeichen gibt, haben Sie tatsächlich 3 Zeichen, wenn Sie ``A`` eingeben und 4 Zeichen, wenn Sie ``AB`` eingeben.
* ``Serial.read()`` nimmt das erste Zeichen aus dem eingehenden Stream. Wenn Sie zum Beispiel ``AB`` eingeben und ``Serial.read()`` nur einmal aufrufen, erhalten Sie das Zeichen ``A``; Beim zweiten Aufruf erhalten Sie ``B``; beim dritten und vierten Anruf erhalten Sie zwei Endsymbole; das Aufrufen dieser Funktion, wenn keine Zeichen im Eingabestream verfügbar sind, führt zu einem Fehler.

Zusammenfassend ist es üblich, die beiden oben genannten Funktionen zu kombinieren und mit einer ``while``-Schleife alle bei jedem Eingabevorgang eingegebenen Zeichen zu lesen.

    .. code-block:: arduino

        while (Serial.available() > 0) {
            Serial.print(Serial.read());
        }

Übrigens, wenn Sie ``Serial.read()`` nicht verwenden, um Zeichen aus dem eingehenden Stream zu erhalten, werden die Zeichen des eingehenden Streams aufgestapelt. Zum Beispiel, wenn Sie ``A`` gefolgt von ``AB`` eingeben, wird der eingehende Stream 7 Zeichen anhäufen.
