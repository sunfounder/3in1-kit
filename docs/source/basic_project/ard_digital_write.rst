.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_digital_write:

1. Digitaler Schreibvorgang
==============================

**Digitaler Schreibvorgang** dient dazu, ein digitales Signal an einen digitalen Pin auszugeben oder zu schreiben. Das digitale Signal hat nur zwei Zustände, 0 oder 1, 0V oder 5V, so dass einige Komponenten, wie die LED und der Summer, ein- oder ausgeschaltet werden können.

Auf dem Arduino R3-Board gibt es 14 digitale I/O-Pins von 0 bis 13. Verwenden Sie nun die Funktionen ``pinMode()`` und ``digitalWrite()`` um diesen digitalen Pins ein hohes oder niedriges Signal zu schreiben.

* ``pinMode(pin, mode)``: Konfiguriert den spezifischen Pin als ``INPUT`` oder ``OUTPUT``, hier muss er als ``OUTPUT`` eingestellt werden.

   **Syntax**
      pinMode(pin, mode)

   **Parameter**
    * ``pin``: Die Pin-Nummer von Arduino, für die der Modus gesetzt werden soll.
    * ``mode``: ``INPUT``, ``OUTPUT`` oder ``INPUT_PULLUP``.

* ``digitalWrite(pin, value)``: Schreiben Sie ein hohes Signal (5V) oder ein niedriges Signal (0V) auf einen digitalen Pin, um den Betriebszustand der Komponente zu ändern. Wenn der Pin mit pinMode() als OUTPUT konfiguriert wurde, wird seine Spannung auf den entsprechenden Wert gesetzt: 5V (oder 3,3V auf 3,3V-Boards) für HIGH, 0V (Erdung) für LOW.

   **Syntax**
      digitalWrite(pin, value)

   **Parameter**
    * ``pin``: Die Pin-Nummer von Arduino.
    * ``value``: ``HIGH`` oder ``LOW``.

**Beispiel für Digitaler Schreibvorgang:**

.. code-block:: arduino

   const int pin = 13;

   void setup() {
      pinMode(pin, OUTPUT);    // setzt den digitalen Pin als Ausgang
   }

   void loop() {
      digitalWrite(pin, HIGH); // schaltet den digitalen Pin ein
      delay(1000);            // wartet eine Sekunde
      digitalWrite(pin, LOW);  // schaltet den digitalen Pin aus
      delay(1000);            // wartet eine Sekunde
   }

.. image:: img/1_led.jpg

**Anmerkungen und Warnungen**

* Die Pins 0~13 sind alle digitale Pins.
* Verwenden Sie nicht die Pins 0 und 1, da sie zur Kommunikation mit dem Computer verwendet werden. Ein Anschluss an diese Pins stört die Kommunikation, einschließlich der Verhinderung des Hochladens auf das Board.
* Wenn die digitalen Pins aufgebraucht sind, können die analogen Pins (A0-A5) auch als digitale Pins verwendet werden.

**Zugehörige Komponenten**

Unten finden Sie die zugehörigen Komponenten, auf die Sie klicken können, um zu erfahren, wie sie verwendet werden.


.. toctree::
   :maxdepth: 2

   ar_blinking_led
   ar_active_buzzer
   ar_turn_the_wheel
   ar_pumping


