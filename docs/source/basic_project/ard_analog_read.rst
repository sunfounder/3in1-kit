.. _ar_analog_read:

4. Analoges Auslesen
======================

Das Arduino kann die angeschlossenen analogen Sensoren über die analogen Pins auslesen.

Das R3-Board enthält einen mehrkanaligen, 10-Bit-Analog-Digital-Wandler. Das bedeutet, dass es die Eingangsspannung zwischen 0 und der Betriebsspannung (5V oder 3,3V) einem Ganzzahlwert zwischen 0 und 1023 zuordnet.

Die Funktion ``analogRead(pin)`` wird benötigt, um den Wert des analogen Pins auszulesen.

* ``analogRead(pin)``: Liest den Wert vom angegebenen analogen Pin.

   **Syntax**
      analogRead(pin)

   **Parameter**
        * ``pin``: Der Name des analogen Eingangspins, von dem gelesen werden soll (A0 bis A5).

   **Rückgabewerte**
      0-1023. Datentyp: int.

**Beispiel für analoges Auslesen**

.. code-block:: arduino

   int analogPin = A0; // Gerät an den analogen Pin A0 angeschlossen
                     // Äußere Leitungen führen zu Ground und +5V
   int val = 0;  // Variable zum Speichern des gelesenen Werts

   void setup() {
      Serial.begin(9600);           // Serielle Schnittstelle einrichten
   }

   void loop() {
      val = analogRead(analogPin);  // Eingangspin auslesen
      Serial.println(val);          // Wert zur Fehlersuche ausgeben
   }

**Hinweise und Warnungen**

* Die analogen Pins sind A0-A5.
* Es ist nicht notwendig, ``pinMode()`` vor dem Aufruf des analogen Pins aufzurufen. Wenn der Pin jedoch zuvor auf ``OUTPUT`` gesetzt wurde, funktioniert die ``analogRead()``-Funktion nicht ordnungsgemäß. In diesem Fall müssen Sie ``pinMode()`` aufrufen, um ihn wieder auf ``INPUT`` zu setzen.

**Zugehörige Komponenten**

Im Folgenden finden Sie die zugehörigen Komponenten. Klicken Sie darauf, um zu erfahren, wie sie verwendet werden.


.. toctree::
    :maxdepth: 2

    ar_turn_the_knob
    ar_photoresistor
    ar_joystick
    ar_moisture
    ar_thermistor