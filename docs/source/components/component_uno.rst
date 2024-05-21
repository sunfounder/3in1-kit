.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_uno:

Arduino Uno R4 Minima
=================================

**Überblick**

Erweitert und verbessert, ist das Arduino UNO R4 Minima mit einem leistungsstarken 32-Bit-Mikrocontroller von Renesas ausgestattet. Machen Sie sich bereit für mehr Rechenleistung, erweiterten Speicher und eine ganz neue Ebene von integrierten Peripheriegeräten. Das Beste daran? Die Kompatibilität mit bestehenden Shields und Zubehörteilen bleibt erhalten, und es sind keine Änderungen am Standard-Formfaktor oder der 5-V-Betriebsspannung erforderlich.

Als Teil des Arduino-Ökosystems ist das UNO R4 eine verlässliche Ergänzung sowohl für Anfänger als auch für erfahrene Elektronikbegeisterte. Egal, ob Sie gerade erst anfangen oder die Grenzen Ihrer Projekte erweitern möchten, dieses robuste Board liefert jedes Mal zuverlässige Leistung.

.. image:: img/uno_r4.png

Hier die Vorzüge des UNO R4 Minima:

* Hardwarekompatibilität mit UNO-Formfaktor: Das UNO R4 Minima behält den gleichen Formfaktor, Pinbelegung und 5 V Betriebsspannung wie sein Vorgänger, das UNO R3, bei. Dies gewährleistet einen reibungslosen Übergang für bestehende Shields und Projekte und nutzt das umfangreiche und einzigartige bereits etablierte Ökosystem des Arduino UNO.
* Erweiterter Speicher und schnellerer Takt: Bereiten Sie sich auf präzisere Berechnungen und die problemlose Handhabung komplexer Projekte vor. Das UNO R4 Minima bietet erweiterten Speicher und eine schnellere Taktung, was Sie in die Lage versetzt, anspruchsvolle Aufgaben mühelos zu bewältigen.
* Zusätzliche integrierte Peripheriegeräte: Das UNO R4 Minima bietet eine Reihe von integrierten Peripheriegeräten, darunter ein 12-Bit-DAC, CAN BUS und OP AMP. Diese zusätzlichen Komponenten bieten Ihnen erweiterte Fähigkeiten und Flexibilität in Ihren Designs.
* Erweiterte 24 V Toleranz: Das UNO R4 Minima unterstützt jetzt einen breiteren Eingangsspannungsbereich und ermöglicht Stromversorgungen von bis zu 24 V. Dies ermöglicht eine nahtlose Integration mit Motoren, LED-Streifen und anderen Aktuatoren, wodurch Ihre Projekte durch die Nutzung einer einzigen Stromquelle vereinfacht werden.
* SWD-Anschluss: Das Debuggen ist ein kritischer Aspekt jedes Projekts. Verbinden Sie einfach einen externen Debugger mit dem UNO R4 Minima und überwachen Sie mühelos das Innenleben Ihres Systems. Behalten Sie die Kontrolle und gewinnen Sie wertvolle Einblicke.
* HID-Unterstützung: Das UNO R4 Minima verfügt über integrierte HID (Human Interface Device) Unterstützung und kann eine Maus oder Tastatur simulieren, wenn es über ein USB-Kabel mit einem Computer verbunden ist. Diese praktische Funktion ermöglicht es, Tastenanschläge und Mausbewegungen an einen Computer zu senden, wodurch die Benutzerfreundlichkeit und Funktionalität erhöht wird.

**Technische Daten**

* Board:
    * Name: Arduino® UNO R4 Minima
    * SKU: ABX00080
* Mikrocontroller: Renesas RA4M1 (Arm® Cortex®-M4)
* USB: USB-C® Programmieranschluss
* Pins:
    * Digitale I/O-Pins: 14
    * Analogeingangspin: 6
    * DAC: 1
    * PWM-Pins: 6
* Kommunikation:
    * UART: Ja, 1x
    * I2C: Ja, 1x
    * SPI: Ja, 1x
    * CAN: Ja, 1 CAN Bus
* Energie:
    * Betriebsspannung des Kreises: 5 V
    * Eingangsspannung (VIN): 6-24 V
    * Gleichstrom pro I/O-Pin: 8 mA
* Taktgeschwindigkeit Hauptkern: 48 MHz
* Speicher RA4M1: 256 kB Flash, 32 kB RAM
* Abmessungen:
    * Breite: 68,85 mm
    * Länge: 53,34 mm

**Pinbelegung**


.. image:: img/uno_r4_pinsout.png
    :width: 800

* |link_r4_datasheet|
* |link_r4_schematic|
* |link_r4_doc|


.. SunFounder R4 Board
.. ===========================

.. .. image:: img/uno_r3.jpg
..     :width: 600
..     :align: center

.. .. note::

..     Das SunFounder R4 Board ist eine Hauptplatine mit fast den gleichen Funktionen wie das `Arduino Uno <https://store.arduino.cc/products/arduino-uno-rev3/>`_ und die beiden Platinen können austauschbar verwendet werden.

.. Das SunFounder R4 Board ist ein Mikrocontroller-Board basierend auf dem ATmega328P (`Datenblatt <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_). Es hat 14 digitale Ein-/Ausgangspins (von denen 6 als PWM-Ausgänge verwendet werden können), 6 analoge Eingänge, einen 16 MHz Keramikresonator (CSTCE16M0V53-R0), eine USB-Verbindung, eine Strombuchse, einen ICSP-Header und einen Reset-Knopf. Es enthält alles, was zur Unterstützung des Mikrocontrollers benötigt wird; schließen Sie es einfach über ein USB-Kabel an einen Computer an oder versorgen Sie es mit einem AC-DC-Adapter oder einem Akku, um loszulegen.

.. **Technische Parameter**

.. .. image:: img/uno.jpg
..     :align: center

.. * MIKROCONTROLLER: ATmega328P
.. * BETRIEBSSPANNUNG: 5V
.. * EINGANGSSPANNUNG (EMPFOHLEN): 7-12V
.. * EINGANGSSPANNUNG (GRENZWERTE): 6-20V
.. * DIGITALE I/O PINS: 14 (0-13, von denen 6 PWM-Ausgabe bieten(3, 5, 6, 9-11))
.. * PWM DIGITALE I/O PINS: 6 (3, 5, 6, 9-11)
.. * ANALOGE EINGANGSPINS: 6 (A0-A5)
.. * GLEICHSTROM PRO I/O PIN: 20 mA
.. * GLEICHSTROM FÜR 3,3V PIN: 50 mA
.. * FLASH-SPEICHER: 32 KB (ATmega328P), von denen 0,5 KB vom Bootloader verwendet werden
.. * SRAM: 2 KB (ATmega328P)
.. * EEPROM: 1 KB (ATmega328P)
.. * TAKTFREQUENZ: 16 MHz
.. * LED_BUILTIN: 13
.. * LÄNGE: 68,6 mm
.. * BREITE: 53,4 mm
.. * GEWICHT: 25 g
.. * I2C-Port: A4(SDA), A5(SCL)

.. **Weitere Informationen**

.. * `Arduino IDE <https://www.arduino.cc/en/software>`_
.. * `Arduino Programmiersprachenreferenz <https://www.arduino.cc/reference/en/>`_
.. * :ref:`install_arduino`
.. * `ATmega328P Datenblatt <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_


