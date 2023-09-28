.. _ar_analog_write:

2. Analog schreiben
======================

6 der 14 digitalen Pins des Arduino verfügen auch über eine PWM-Ausgangsfunktion. Daher können Sie diesen 6 Pins neben digitalen Signalen auch analoge Signale (PWM-Wellensignale) schreiben. Auf diese Weise können Sie die LEDs in unterschiedlichen Helligkeiten leuchten lassen oder den Motor mit unterschiedlichen Geschwindigkeiten drehen lassen.

Pulsweitenmodulation oder `PWM <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_ ist eine Technik, um analoge Ergebnisse mit digitalen Mitteln zu erzielen. Da der buchstäbliche Sinn vielleicht schwer zu erfassen ist, folgt ein Beispiel zur Steuerung der Intensität einer LED, um das Konzept besser zu veranschaulichen.

Ein digitales Signal, das aus hohen und niedrigen Pegeln besteht, wird als Puls bezeichnet. Die Pulsbreite dieser Pins kann durch Änderung der EIN/AUS-Geschwindigkeit angepasst werden. 
Vereinfacht ausgedrückt: Wenn wir die LED kurz ein- und ausschalten (z.B. 20ms, die visuelle Verweilzeit der meisten Menschen), werden wir nicht bemerken, dass sie ausgegangen ist, aber die Helligkeit des Lichts wird etwas schwächer sein. Während dieser Zeit, je länger die LED eingeschaltet ist, desto heller wird sie sein.
Das bedeutet, innerhalb einer Periode, je breiter der Puls, desto größer die "elektrische Signalstärke", die vom Mikrocontroller ausgegeben wird.

Dies ist die Funktion, die benötigt wird, um die PWM-Welle zu schreiben.

* ``analogWrite(pin, value)``

    Schreibt einen analogen Wert (PWM-Welle) auf einen Pin. Unterschiedliche Ausgangsspannungen (0-5V) können durch Erzeugung eines bestimmten Pulssignals simuliert werden. Der Pin behält dieses Signal bei, bis er durch eine neue Lese- oder Schreibanweisung aufgerufen wird.

   **Syntax**
      analogWrite(pin, value)

   **Parameters**
    * ``pin``: Der Arduino-Pin, auf den geschrieben werden soll. Erlaubte Datentypen: int.
    * ``value``: Der Tastgrad: zwischen 0 (immer aus) und 255 (immer an). Erlaubte Datentypen: int.

**Beispiel für Analog schreiben**

.. code-block:: arduino

   int pin = 9;      //connect  to pwm pin

   void setup() {
      pinMode(pin, OUTPUT);  // sets the pin as output
   }

   void loop() {
      for (int i = 0 ;i<255 ; i++){
         analogWrite(pin, i); //analogWrite values from 0 to 255
         delay(30);
      }
   }

**Hinweise und Warnungen**

* Wenn Sie genau auf das R4-Board schauen, werden Sie feststellen, dass die Pins mit dem "~"-Symbol über eine analoge Ausgangsfunktion verfügen.
* Die auf den Pins 5 und 6 erzeugten PWM-Ausgänge werden höhere als erwartete Tastverhältnisse aufweisen. Dies liegt an Wechselwirkungen mit den Funktionen ``millis()`` und ``delay()``, die denselben internen Timer verwenden, der zur Erzeugung dieser PWM-Ausgänge verwendet wird. Dies wird vor allem bei niedrigen Tastverhältniseinstellungen (z.B. 0 - 10) bemerkt und kann dazu führen, dass ein Wert von 0 den Ausgang auf den Pins 5 und 6 nicht vollständig ausschaltet.

**Verwandte Komponenten**

Unten sind die verwandten Komponenten aufgeführt. Sie können darauf klicken, um zu erfahren, wie sie verwendet werden.


.. toctree::
   :maxdepth: 2

   ar_fading
   ar_colorful_light