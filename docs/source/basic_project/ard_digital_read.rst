.. _ar_digital_read:

3. Digitaler Lesevorgang
==============================

Sensoren erfassen Informationen aus der realen Welt, welche über Pins (manche digital, manche analog) an das Hauptboard weitergegeben werden, sodass der Computer die tatsächliche Situation erkennen kann.

Daher kann das Arduino-Board den Arbeitsstatus von digitalen Sensoren erkennen, indem es den Wert digitaler Pins wie Tasten oder IR-Vermeidungsmodule liest.

Hier sind die benötigten Funktionen:

* ``pinMode(pin, mode)``: Konfiguriert den spezifischen Pin als ``INPUT`` oder ``OUTPUT``. Hier muss er auf ``INPUT`` gesetzt werden.

   **Syntax**
      pinMode(pin, mode)

   **Parameter**
    * ``pin``: Die Arduino-Pin-Nummer, für die der Modus gesetzt werden soll.
    * ``mode``: INPUT, OUTPUT oder INPUT_PULLUP.


* ``digitalRead(pin)``: Liest den Wert (Zustand) vom angegebenen digitalen Pin.

   **Syntax**
      digitalRead(pin)

   **Parameter**
    * ``pin``: Die Arduino-Pin-Nummer, die Sie lesen möchten.

   **Rückgabewert**
      HIGH oder LOW


**Beispiel für Digitalen Lesevorgang**

.. code-block:: arduino

   int ledPin = 13;  // LED verbunden mit digitalem Pin 13
   int inPin = 7;    // Taster verbunden mit digitalem Pin 7
   int val = 0;      // Variable zum Speichern des gelesenen Wertes

   void setup() {
      pinMode(ledPin, OUTPUT);  // setzt den digitalen Pin 13 als Ausgang
      pinMode(inPin, INPUT);    // setzt den digitalen Pin 7 als Eingang
   }

   void loop() {
      val = digitalRead(inPin);   // liest den Eingangspin
      digitalWrite(ledPin, val);  // setzt die LED auf den Wert des Tasters
   }

**Anmerkungen und Warnungen**

1. Pull-Up & Pull-Down.

    ``digitalRead()`` kann zufällige, unbestimmte Werte produzieren, wenn der Pin kein klares Signal erhält. Das Steuern der Eingangspins in einen bekannten Zustand kann das Projekt zuverlässiger machen.
    Bei der Verwendung einer Eingangskomponente wie einem Taster ist es normalerweise notwendig, einen Pull-Up- oder Pull-Down-Widerstand parallel zum digitalen Eingangspin anzuschließen.

    Abgesehen vom Anschluss eines Pull-up-Widerstands können Sie auch den Pin-Modus im Code auf ``INPUT_PULLUP`` setzen, zum Beispiel ``pinMode(pin, INPUT_PULLUP)``. In diesem Fall wird der Pin über die Software auf den internen Pull-up-Widerstand von Atmega zugreifen, und es hat den gleichen Effekt wie das Anschließen eines Pull-up-Widerstands.

2. Über Pin13.

    Alle digitalen Pins (1-13) auf dem R3-Board können mit ``digitalRead()`` verwendet werden.
    Aber der digitale Pin 13 ist schwieriger als Eingang zu verwenden als andere digitale Pins. 
    Da er mit einer LED und einem Widerstand verbunden ist, ist er auf den meisten Boards verlötet.
    Wenn Sie seinen internen 20k Pull-up-Widerstand aktivieren, wird er statt der erwarteten 5V bei etwa 1,7V liegen, da die onboard LED und der Serienwiderstand das Spannungsniveau senken. Das bedeutet, er gibt immer LOW zurück. Wenn Sie Pin 13 als digitalen Eingang verwenden müssen, setzen Sie seinen ``pinMode()`` auf INPUT und verwenden Sie einen externen Pull-down-Widerstand.

3. Analoge Pins.

    Wenn die digitalen Pins nicht ausreichen, können die analogen Pins (A0-A5) auch als digitale Pins verwendet werden.
    Sie müssen mit ``pinMode(pin,mode)`` auf INPUT gesetzt werden.

**Verwandte Komponenten**

Unten finden Sie die zugehörigen Komponenten. Sie können darauf klicken, um zu erfahren, wie sie verwendet werden.

.. toctree::
    :maxdepth: 2

    ar_serial_monitor
    ar_button
    ar_reed
    ar_detect_the_obstacle
    ar_detect_the_line


