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

1. Digital Write
==============================

**Digital Write** bedeutet, ein digitales Signal an einen digitalen Pin auszugeben. Das digitale Signal hat nur zwei Zustände, 0 oder 1, 0V oder 5V, so dass es einigen Komponenten, wie z.B. der LED und dem Summer, ermöglicht, ein- oder ausgeschaltet zu werden.

Auf dem Arduino R4-Board gibt es 14 digitale I/O-Pins von 0 bis 13. Jetzt verwenden Sie die Funktionen ``pinMode()`` und ``digitalWrite()`` um ein hohes oder niedriges Signal an diese digitalen Pins zu schreiben.

* ``pinMode(pin, mode)``: Konfigurieren Sie den bestimmten Pin als ``INPUT`` oder ``OUTPUT``. Hier muss er als ``OUTPUT`` eingestellt werden.

   **Syntax**
      pinMode(pin, mode)

   **Parameter**
    * ``pin``: Die Pin-Nummer von Arduino, für die der Modus eingestellt werden soll.
    * ``mode``: ``INPUT``, ``OUTPUT`` oder ``INPUT_PULLUP``.

* ``digitalWrite(pin, value)``: Schreiben Sie ein hohes Signal (5V) oder ein niedriges Signal (0V) an einen digitalen Pin, um den Betriebszustand der Komponente zu ändern. Wenn der Pin mit pinMode() als OUTPUT konfiguriert wurde, wird seine Spannung auf den entsprechenden Wert eingestellt: 5V (oder 3,3V bei 3,3V Boards) für HIGH, 0V (Masse) für LOW.

   **Syntax**
      digitalWrite(pin, value)

   **Parameter**
    * ``pin``: Die Pin-Nummer von Arduino.
    * ``value``: ``HIGH`` oder ``LOW``.

**Beispiel für Digital Write:**

.. code-block:: arduino

   const int pin = 13;

   void setup() {
      pinMode(pin, OUTPUT);    // sets the digital pin as output
   }

   void loop() {
      digitalWrite(pin, HIGH); // sets the digital pin on
      delay(1000);            // waits for a second
      digitalWrite(pin, LOW);  // sets the digital pin off
      delay(1000);            // waits for a second
   }

.. image:: img/1_led.jpg

**Hinweise und Warnungen**

* Die Pins 0~13 sind alle digitale Pins.
* Verwenden Sie nicht die Pins 0 und 1, da sie zur Kommunikation mit dem Computer verwendet werden. Eine Verbindung zu diesen Pins würde die Kommunikation stören, einschließlich eines fehlgeschlagenen Hochladens auf das Board.
* Wenn die digitalen Pins verbraucht sind, können die analogen Pins (A0-A5) auch als digitale Pins verwendet werden.

**Zugehörige Komponenten**

Unten finden Sie die zugehörigen Komponenten. Sie können darauf klicken, um zu erfahren, wie man sie verwendet.


.. toctree::
   :maxdepth: 2

   ar_blinking_led
   ar_active_buzzer
   ar_turn_the_wheel
   ar_pumping


