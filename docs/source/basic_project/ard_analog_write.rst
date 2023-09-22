.. _ar_analog_write:

2. Analoges Schreiben
=========================

6 der 14 digitalen Pins von Arduino verfügen auch über eine PWM-Ausgabefunktion. Daher können Sie neben dem Schreiben von digitalen Signalen an diese 6 Pins auch analoge Signale (PWM-Wellensignale) an sie senden. Auf diese Weise können Sie die LEDs in unterschiedlicher Helligkeit leuchten lassen oder den Motor mit unterschiedlichen Geschwindigkeiten drehen lassen.

Pulsweitenmodulation, oder `PWM <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_, ist eine Technik, um analoge Ergebnisse mit digitalen Mitteln zu erzielen. Da die wörtliche Bedeutung schwer zu fassen sein mag, folgt hier ein Beispiel zur Steuerung der Intensität einer LED, um das Prinzip besser zu veranschaulichen.

Ein digitales Signal, das aus hohen und niedrigen Pegeln besteht, wird als Puls bezeichnet. Die Pulsbreite dieser Pins kann durch Änderung der EIN/AUS-Geschwindigkeit angepasst werden. Vereinfacht ausgedrückt: Wenn wir die LED für eine kurze Zeit (wie 20ms, die visuelle Verweildauer der meisten Menschen) ein-, aus- und wieder einschalten, werden wir nicht bemerken, dass sie ausgeschaltet war, aber die Helligkeit des Lichts wird etwas schwächer sein. In diesem Zeitraum gilt: Je länger die LED eingeschaltet ist, desto heller wird sie sein.
Das heißt, innerhalb eines Zeitraums, je breiter der Puls, desto größer ist die "elektrische Signalstärke", die vom Mikrocontroller ausgegeben wird.

Dies ist die benötigte Funktion, um die PWM-Welle zu schreiben:

* ``analogWrite(pin, value)``

    Schreibt einen analogen Wert (PWM-Welle) an einen Pin. Durch Generieren eines bestimmten Pulssignals können unterschiedliche Ausgangsspannungen (0-5V) simuliert werden. Der Pin behält dieses Signal bei, bis er durch eine neue Lese- oder Schreibanweisung aufgerufen wird.

   **Syntax**
      analogWrite(pin, value)

   **Parameter**
    * ``pin``: Der Arduino-Pin, an den geschrieben wird. Erlaubte Datentypen: int.
    * ``value``: Das Tastverhältnis: zwischen 0 (immer aus) und 255 (immer an). Erlaubte Datentypen: int.

**Beispiel für Analoges Schreiben**

.. code-block:: arduino

   int pin = 9;      // Verbindung zum PWM-Pin

   void setup() {
      pinMode(pin, OUTPUT);  // Definiert den Pin als Ausgang
   }

   void loop() {
      for (int i = 0 ;i<255 ; i++){
         analogWrite(pin, i); //analogWrite Werte von 0 bis 255
         delay(30);
      }
   }

**Anmerkungen und Warnungen**

* Wenn Sie genau auf das R3-Board schauen, haben die mit dem Symbol "~" gekennzeichneten Pins eine analoge Ausgabefunktion.
* Die an den Pins 5 und 6 erzeugten PWM-Ausgänge haben höhere Tastverhältnisse als erwartet. Dies liegt an Wechselwirkungen mit den Funktionen ``millis()`` und ``delay()``, die denselben internen Timer verwenden, der zum Erzeugen dieser PWM-Ausgänge genutzt wird. Dies wird vor allem bei niedrigen Tastverhältniseinstellungen (z. B. 0 - 10) bemerkbar und kann dazu führen, dass ein Wert von 0 den Ausgang an den Pins 5 und 6 nicht vollständig abschaltet.

**Zugehörige Komponenten**

Im Folgenden finden Sie die zugehörigen Komponenten, auf die Sie klicken können, um zu erfahren, wie sie verwendet werden.


.. toctree::
   :maxdepth: 2

   ar_fading
   ar_colorful_light