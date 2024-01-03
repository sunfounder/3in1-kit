.. _ar_digital_read:

3. Lectura Digital
===================

Los sensores capturan información del mundo real, que luego se comunica a la placa principal a través de pines (algunos digitales, otros analógicos) para que la computadora pueda conocer la realidad de la situación.

Por lo tanto, la placa Arduino puede conocer el estado de funcionamiento de los sensores digitales leyendo el valor de los pines digitales como botones, módulo de evitación de obstáculos IR.


Aquí están las funciones requeridas.

* ``pinMode(pin, mode)``: Configura un pin específico como ``INPUT`` o ``OUTPUT``, aquí se necesita configurar como ``INPUT``. 

   **Sintaxis**
      pinMode(pin, mode)

   **Parámetros**
    * ``pin``: el número de pin de Arduino para establecer el modo.
    * ``mode``: INPUT, OUTPUT, o INPUT_PULLUP.



* ``digitalRead(pin)``: Lee el valor (estado de nivel) del pin digital especificado.

   **Sintaxis**
      digitalRead(pin)

   **Parámetros**
    * ``pin``: el número de pin de Arduino que deseas leer

   **Retorno**
      HIGH o LOW


**Ejemplo de Lectura Digital**

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


**Notas y Advertencias**

1. Pull Up & Pull Down.

    ``digitalRead()`` puede producir valores aleatorios e indeterminados si el pin no recibe una señal de nivel. Por lo tanto, dirigir los pines de entrada a un estado conocido puede hacer que el proyecto sea más confiable.
    Al usar un componente de entrada como un botón, generalmente es necesario conectar una resistencia de pull-up o pull-down en paralelo al pin de entrada digital.

    Además de conectar una resistencia de pull-up, también puedes configurar el modo del pin a ``INPUT_PULLUP`` en el código, por ejemplo, ``pinMode(pin, INPUT_PULLUP)``. En este caso, el pin accederá a la resistencia de pull-up incorporada del Atmega a través del software, y tendrá el mismo efecto que conectar una resistencia de pull-up.

2. Acerca del Pin13.

    Todos los pines digitales (1-13) en la placa R3 se pueden usar como ``digitalRead()``.
    Pero el pin digital 13 es más difícil de usar como entrada digital que otros pines digitales.
    Debido a que conecta un LED y una resistencia, está soldado en la mayoría de las placas.
    Si habilitas su resistencia de pull-up interna de 20k, se mantendrá alrededor de 1.7V en lugar de los 5V esperados porque el LED y la resistencia en serie a bordo bajan el nivel de voltaje, lo que significa que siempre retorna LOW. Si debes usar el pin 13 como entrada digital, configura su ``pinMode()`` a INPUT y usa una resistencia de pull-down externa.

3. Pines Analógicos.

    Si los pines digitales no son suficientes, los pines analógicos (A0-A5) también pueden usarse como pines digitales.
    Necesita configurarse a INPUT con ``pinMode(pin,mode)``.


**Componentes Relacionados**

A continuación se presentan los componentes relacionados, puedes hacer clic para aprender a utilizarlos.

.. toctree::
    :maxdepth: 2

    ar_serial_monitor
    ar_button
    ar_reed
    ar_detect_the_obstacle
    ar_detect_the_line
