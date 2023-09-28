.. _ar_digital_read:

3. Digital Lesen
===================

Sensoren erfassen Informationen aus der realen Welt. Diese Informationen werden dann über Pins (einige digital, andere analog) an das Hauptboard übermittelt, damit der Computer die tatsächliche Situation erkennen kann.

Daher kann das Arduino-Board den Arbeitsstatus von digitalen Sensoren durch Lesen des Wertes von Digitalpins, wie Tasten oder IR-Vermeidungsmodule, erkennen.

Hier sind die benötigten Funktionen.

* ``pinMode(pin, mode)``: Konfiguriert den spezifischen Pin als ``INPUT`` oder ``OUTPUT``. Hier muss er als ``INPUT`` eingestellt werden.

   **Syntax**
      pinMode(pin, mode)

   **Parameter**
    * ``pin``: Die Arduino-Pinnummer, für die der Modus eingestellt werden soll.
    * ``mode``: INPUT, OUTPUT oder INPUT_PULLUP.

* ``digitalRead(pin)``: Liest den Wert (Pegelzustand) vom angegebenen Digitalpin.

   **Syntax**
      digitalRead(pin)

   **Parameter**
    * ``pin``: Die Arduino-Pinnummer, die Sie lesen möchten.

   **Rückgabewert**
      HIGH oder LOW


**Beispiel für Digital Lesen**

.. code-block:: arduino

   int ledPin = 13;  // LED connected to digital pin 13
   int inPin = 7;    // pushbutton connected to digital pin 7
   int val = 0;      // variable to store the read value

   void setup() {
      pinMode(ledPin, OUTPUT);  // sets the digital pin 13 as output
      pinMode(inPin, INPUT);    // sets the digital pin 7 as input
   }

   void loop() {
      val = digitalRead(inPin);   // read the input pin
      digitalWrite(ledPin, val);  // sets the LED to the button's value
   }

**Anmerkungen und Warnungen**

1. Pull Up & Pull Down.

    ``digitalRead()`` kann zufällige, unbestimmte Werte erzeugen, wenn der Pin kein Pegelsignal erhält. Das Lenken der Eingangspins in einen bekannten Zustand kann das Projekt zuverlässiger machen.
    Bei Verwendung einer Eingangskomponente, wie einem Taster, ist es in der Regel notwendig, einen Pull-up- oder Pull-down-Widerstand parallel zum Digital-Eingangspin anzuschließen.

    Neben dem Anschließen eines Pull-up-Widerstandes können Sie auch den Pin-Modus im Code auf ``INPUT_PULLUP`` setzen, zum Beispiel ``pinMode(pin,INPUT_PULLUP)``. In diesem Fall greift der Pin über die Software auf den eingebauten Pull-up-Widerstand von Atmega zu und hat den gleichen Effekt wie das Anschließen eines Pull-up-Widerstandes.

2. Über Pin13.

    Alle digitalen Pins (1-13) auf dem R4-Board können als ``digitalRead()`` verwendet werden.
    Aber der digitale Pin 13 ist schwieriger als andere digitale Pins als digitaler Eingang zu verwenden.
    Da er eine LED und einen Widerstand verbindet, ist er auf den meisten Boards verlötet.
    Wenn Sie seinen internen 20k Pull-up-Widerstand aktivieren, bleibt er bei etwa 1,7 V anstelle der erwarteten 5 V, da die onboard LED und der Serienwiderstand das Spannungsniveau herunterziehen, was bedeutet, dass er immer LOW zurückgibt. Wenn Sie Pin 13 unbedingt als digitalen Eingang verwenden müssen, setzen Sie seine ``pinMode()`` auf INPUT und verwenden Sie einen externen Pull-down-Widerstand.

3. Analogpins.

    Wenn die digitalen Pins nicht ausreichen, können die Analogpins (A0-A5) auch als digitale Pins verwendet werden.
    Sie müssen mit ``pinMode(pin,mode)`` auf INPUT eingestellt werden.

**Verwandte Komponenten**

Im Folgenden finden Sie die zugehörigen Komponenten. Sie können darauf klicken, um zu erfahren, wie sie verwendet werden.


.. toctree::
    :maxdepth: 2

    ar_serial_monitor
    ar_button
    ar_reed
    ar_detect_the_obstacle
    ar_detect_the_line


