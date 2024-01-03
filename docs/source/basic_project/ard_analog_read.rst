.. _ar_analog_read:

4. Lectura Analógica
======================

Arduino puede leer los sensores analógicos conectados a través de los pines analógicos.

La placa R3 contiene un convertidor analógico-digital de múltiples canales y 10 bits. Esto significa que mapea el voltaje de entrada entre 0 y el voltaje de operación (5V o 3.3V) a un valor entero entre 0 y 1023.

Necesitas la función ``analogRead(pin)`` para leer el valor del pin analógico.

* ``analogRead(pin)``: Lee el valor del pin analógico especificado.

   **Sintaxis**
      analogRead(pin)

   **Parámetros**
        * ``pin``: el nombre del pin de entrada analógica a leer (de A0 a A5).

   **Retorno**
      0-1023. Tipo de dato: int.


**Ejemplo de Lectura Analógica**

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


**Notas y Advertencias**

* Los pines analógicos son A0-A5.
* No necesitas llamar a ``pinMode()`` antes de llamar al pin analógico, pero si el pin se configuró previamente como ``OUTPUT``, la función ``analogRead()`` no funcionará correctamente, en cuyo caso necesitas llamar a ``pinMode()`` para volver a configurarlo como ``INTPUT``.

**Componentes Relacionados**

A continuación se presentan los componentes relacionados, puedes hacer clic para aprender a utilizarlos.

.. toctree::
    :maxdepth: 2

    ar_turn_the_knob
    ar_photoresistor
    ar_joystick
    ar_moisture
    ar_thermistor
