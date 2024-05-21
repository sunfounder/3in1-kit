.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_lcd1602:

5.11.1 Flüssigkristallanzeige 
=======================================

Ein I2C LCD1602 besteht aus einem LCD1602 und einem I2C-Modul. Mit dem LCD1602 können Zeichen, Zahlen usw. angezeigt werden, was jedoch viele Pins des Hauptsteuergeräts in Anspruch nimmt. Nachdem ein I2C-Modul konfiguriert wurde, sind nur 2 I/O-Pins erforderlich, um dieses LCD1602 zu steuern.

Sehen wir uns nun an, wie dieses I2C LCD1602 funktioniert.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist sicherlich praktisch, ein gesamtes Kit zu kaufen, hier ist der Link:

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

.. note::
    Die SDA- und SCL-Pins des R4-Boards sind die Pins A4 und A5.

**Code**

.. note::

    * Öffnen Sie die Datei ``5.11.liquid_crystal_display.ino`` im Pfad ``3in1-kit\learning_project\5.11.liquid_crystal_display``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Hier wird die ``LiquidCrystal I2C``-Bibliothek verwendet. Sie können sie über den **Library Manager** installieren.

        .. image:: ../img/lib_liquidcrystal_i2c.png
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e49c4936-2530-4890-b86c-1017d11eae6e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem der Code erfolgreich hochgeladen wurde, sehen Sie "SunFounder" und "Hello World" auf dem I2C LCD1602.

.. note::
    Wenn der Code und die Verdrahtung korrekt sind, das LCD aber trotzdem keinen Inhalt anzeigt, können Sie das Potentiometer auf der Rückseite drehen.


**Wie funktioniert das?**

Mit dem Aufruf der Bibliothek ``LiquidCrystal_I2C.h`` können Sie das LCD einfach steuern.

.. code-block:: arduino

    #include "LiquidCrystal_I2C.h"

Bibliotheksfunktionen:

.. code-block:: arduino

    LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)

Erstellt eine neue Instanz der Klasse ``LiquidCrystal_I2C``, die ein
bestimmtes LCD repräsentiert, das an Ihr Arduino-Board angeschlossen ist.

* ``lcd_AddR``: Die Adresse des LCDs ist standardmäßig 0x27.
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

Löscht die Anzeige und setzt die Cursor-Position auf Null.

.. code-block:: arduino

    void setCursor(uint8_t col,uint8_t row)

Setzt die Cursor-Position auf col,row.

.. code-block:: arduino

    void print(data,BASE)

Gibt Text auf dem LCD aus.

* ``data``: Die auszudruckenden Daten (char, byte, int, long oder string).
* ``BASE (optional)``: Die Basis, in der Zahlen gedruckt werden sollen: BIN für Binär (Basis 2), DEC für Dezimal (Basis 10), OCT für Oktal (Basis 8), HEX für Hexadezimal (Basis 16).

