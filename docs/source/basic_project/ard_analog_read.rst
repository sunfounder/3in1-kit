.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_analog_read:

4. Analoges Lesen
======================

Mit dem Arduino können die an den analogen Pins angeschlossenen Sensoren gelesen werden.

Das R4-Board enthält einen Mehrkanal-10-Bit-Analog-Digital-Wandler. Das bedeutet, dass es die Eingangsspannung zwischen 0 und der Betriebsspannung (5V oder 3,3V) einem ganzzahligen Wert zwischen 0 und 1023 zuordnet.

Um den Wert des analogen Pins zu lesen, benötigen Sie die Funktion ``analogRead(pin)``.

* ``analogRead(pin)``: Liest den Wert vom angegebenen analogen Pin.

   **Syntax**
      analogRead(pin)

   **Parameter**
        * ``pin``: Der Name des analogen Eingangspins, von dem gelesen werden soll (A0 bis A5).

   **Rückgabewert**
      0-1023. Datentyp: int.


**Beispiel für analoges Lesen**

.. code-block:: arduino

   int analogPin = A0; // device connected to analog pin A0
                     // outside leads to ground and +5V
   int val = 0;  // variable to store the value read

   void setup() {
      Serial.begin(9600);           //  setup serial
   }

   void loop() {
      val = analogRead(analogPin);  // read the input pin
      Serial.println(val);          // debug value
   }

**Hinweise und Warnungen**

* Die analogen Pins sind A0-A5.
* Es ist nicht notwendig, ``pinMode()`` vor dem Aufruf des analogen Pins zu verwenden, aber wenn der Pin zuvor auf ``OUTPUT`` gesetzt wurde, funktioniert die Funktion ``analogRead()`` nicht ordnungsgemäß. In diesem Fall müssen Sie ``pinMode()`` aufrufen, um ihn wieder auf ``INPUT`` zu setzen.

**Zugehörige Komponenten**

Unten sind die zugehörigen Komponenten aufgelistet. Sie können darauf klicken, um zu erfahren, wie sie verwendet werden.

.. toctree::
    :maxdepth: 2

    ar_turn_the_knob
    ar_photoresistor
    ar_joystick
    ar_moisture
    ar_thermistor