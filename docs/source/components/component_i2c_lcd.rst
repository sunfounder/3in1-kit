.. _cpn_i2c_lcd1602:

I2C LCD1602
==============

.. image:: img/i2c_lcd1602.png
    :width: 800

* **GND**: Erdung
* **VCC**: Spannungsversorgung, 5V.
* **SDA**: Serielle Datenleitung. Verbinden Sie über einen Pull-up-Widerstand mit VCC.
* **SCL**: Serielle Taktleitung. Verbinden Sie über einen Pull-up-Widerstand mit VCC.

Wie wir alle wissen, bereichern LCDs und einige andere Displays die Mensch-Maschine-Interaktion erheblich. Sie haben jedoch eine gemeinsame Schwäche. Wenn sie an einen Controller angeschlossen sind, werden mehrere IOs des Controllers belegt, der nicht viele externe Ports hat. Dies beschränkt auch andere Funktionen des Controllers.

Deshalb wurde das LCD1602 mit einem I2C-Modul entwickelt, um dieses Problem zu lösen. Das I2C-Modul verfügt über einen eingebauten PCF8574 I2C-Chip, der I2C-Serien-Daten in parallele Daten für die LCD-Anzeige umwandelt.

* `PCF8574 Datenblatt <https://www.ti.com/lit/ds/symlink/pcf8574.pdf?ts=1627006546204&ref_url=https%253A%252F%252Fwww.google.com%252F>`_

**I2C-Adresse**

Die Standardadresse ist in der Regel 0x27, in einigen Fällen kann sie 0x3F sein.

Nimmt man die Standardadresse von 0x27 als Beispiel, kann die Geräteadresse durch Kurzschließen der A0/A1/A2-Pads geändert werden; im Standardzustand sind A0/A1/A2 auf 1, und wenn das Pad kurzgeschlossen ist, sind A0/A1/A2 auf 0.

.. image:: img/i2c_address.jpg
    :width: 600

**Hintergrundbeleuchtung/Kontrast**

Die Hintergrundbeleuchtung kann durch das Aufstecken eines Jumper-Caps aktiviert werden, durch das Abziehen wird sie deaktiviert. Das blaue Potentiometer auf der Rückseite dient zur Kontrasteinstellung (Verhältnis der Helligkeit zwischen dem hellsten Weiß und dem dunkelsten Schwarz).

.. image:: img/back_lcd1602.jpg

* **Kurzschluss-Cap**: Mit diesem Cap kann die Hintergrundbeleuchtung aktiviert werden, ziehen Sie es ab, um die Beleuchtung zu deaktivieren.
* **Potentiometer**: Es wird verwendet, um den Kontrast (Klarheit des angezeigten Textes) einzustellen, der im Uhrzeigersinn erhöht und gegen den Uhrzeigersinn verringert wird.

**Beispiel**

* :ref:`ar_lcd1602` (Grundlegendes Projekt)
* :ref:`ar_serial_read` (Grundlegendes Projekt)
