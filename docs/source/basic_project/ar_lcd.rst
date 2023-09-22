.. _ar_lcd1602:

5.11.1 Flüssigkristallanzeige
===============================

Ein I2C LCD1602 setzt sich aus einem LCD1602 und einem I2C-Modul zusammen. Das LCD1602 kann zur Anzeige von Zeichen, Zahlen usw. verwendet werden, benötigt jedoch viele Pins des Hauptcontrollers. Nach der Konfiguration eines I2C-Moduls sind nur noch 2 I/O-Pins erforderlich, um dieses LCD1602 anzusteuern.

Sehen wir uns nun an, wie dieses I2C LCD1602 funktioniert.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten:

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

Sie können sie auch separat über die untenstehenden Links kaufen.

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

.. note::
    Die SDA- und SCL-Pins des R3-Boards entsprechen den Pins A4 und A5.

**Code**

.. note::

    * Öffnen Sie die Datei ``5.11.liquid_crystal_display.ino`` unter dem Pfad ``3in1-kit\basic_project\5.11.liquid_crystal_display``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Hier wird die ``LiquidCrystal I2C``-Bibliothek verwendet, die Sie aus dem **Library Manager** installieren können.

        .. image:: ../img/lib_liquidcrystal_i2c.png
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e49c4936-2530-4890-b86c-1017d11eae6e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nach erfolgreichem Hochladen des Codes werden Sie "SunFounder", "Hallo Welt" auf dem I2C LCD1602 sehen.

.. note::
    Wenn der Code und die Verdrahtung korrekt sind, das LCD aber dennoch nichts anzeigt, können Sie das Potentiometer auf der Rückseite drehen.


**Wie funktioniert das?**

Durch den Aufruf der Bibliothek ``LiquidCrystal_I2C.h`` können Sie das LCD einfach ansteuern.

.. code-block:: arduino

    #include "LiquidCrystal_I2C.h"

Bibliotheksfunktionen:

.. code-block:: arduino

    LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)

Erstellt eine neue Instanz der Klasse ``LiquidCrystal_I2C``, die ein bestimmtes LCD repräsentiert, das an Ihr Arduino-Board angeschlossen ist.

* ``lcd_AddR``: Die Adresse des LCD ist standardmäßig auf 0x27 eingestellt.
* ``lcd_cols``: Das LCD1602 verfügt über 16 Spalten.
* ``lcd_rows``: Das LCD1602 verfügt über 2 Zeilen.

.. code-block:: arduino

    void init()

Initialisiert das LCD.

.. code-block:: arduino

    void backlight()

Schaltet die (optionale) Hintergrundbeleuchtung ein.

.. code-block:: arduino

    void nobacklight()

Schaltet die (optionale) Hintergrundbeleuchtung aus.

.. code-block:: arduino

    void display()

Schaltet das LCD-Display ein.

.. code-block:: arduino

    void nodisplay()

Schaltet das LCD-Display schnell aus.

.. code-block:: arduino

    void clear()

Löscht die Anzeige und setzt die Cursorposition auf Null.

.. code-block:: arduino

    void setCursor(uint8_t col,uint8_t row)

Setzt die Cursorposition auf col,row.

.. code-block:: arduino

    void print(data,BASE)

Gibt Text auf dem LCD aus.

* ``data``: Die auszugebenden Daten (char, byte, int, long oder string).
* ``BASE (optional)``: Die Basis, in der Zahlen gedruckt werden sollen: BIN für binär (Basis 2), DEC für dezimal (Basis 10), OCT für oktal (Basis 8), HEX für hexadezimal (Basis 16).

