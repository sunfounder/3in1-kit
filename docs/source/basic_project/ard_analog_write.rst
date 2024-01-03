.. _ar_analog_write:

2. Escritura Analógica
=========================

6 de los 14 pines digitales de Arduino también tienen función de salida PWM. Por lo tanto, además de escribir señales digitales en estos 6 pines, también puedes escribir señales analógicas (señales de onda PWM) en ellos. De esta manera, puedes hacer que los LED muestren diferentes brillos o hacer que el motor gire a diferentes velocidades.

La modulación por ancho de pulso, o `PWM <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_, es una técnica para obtener resultados analógicos con medios digitales. Dado que puede ser difícil comprender el significado literal, aquí hay un ejemplo de control de la intensidad de un LED para ayudarte a entender mejor.

Una señal digital compuesta por niveles altos y bajos se llama pulso. El ancho del pulso de estos pines se puede ajustar cambiando la velocidad de ENCENDIDO/APAGADO.
En pocas palabras, cuando encendemos, apagamos y volvemos a encender el LED por un corto período de tiempo (como 20ms, el tiempo de permanencia visual de la mayoría de las personas),
No veremos que se haya apagado, pero el brillo de la luz será ligeramente más débil. Durante este período, cuanto más tiempo esté encendido el LED, más brillante será.
Es decir, dentro de un período, cuanto más ancho sea el pulso, mayor será la "fuerza de la señal eléctrica" emitida por el microcontrolador.

Esta es la función necesaria para escribir la onda PWM.

* ``analogWrite(pin, value)``

    Escribe un valor analógico (onda PWM) en un pin. Se pueden simular diferentes voltajes de salida (0-5V) generando una señal de pulso especificada. El pin mantendrá esta señal hasta que sea llamado por una nueva declaración de lectura o escritura.

   **Sintaxis**
      analogWrite(pin, value)

   **Parámetros**
    * ``pin``: el pin de Arduino a escribir. Tipos de datos permitidos: int.
    * ``value``: el ciclo de trabajo: entre 0 (siempre apagado) y 255 (siempre encendido). Tipos de datos permitidos: int.


**Ejemplo de Escritura Analógica**

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

**Notas y Advertencias**

* Observando de cerca la placa R3, los pines marcados con el símbolo "~" tienen función de salida analógica.
* Las salidas PWM generadas en los pines 5 y 6 tendrán ciclos de trabajo más altos de lo esperado. Esto se debe a interacciones con las funciones ``millis()`` y ``delay()``, que comparten el mismo temporizador interno utilizado para generar esas salidas PWM. Esto se notará principalmente en configuraciones de ciclo de trabajo bajos (por ejemplo, 0 - 10) y puede resultar en que un valor de 0 no apague completamente la salida en los pines 5 y 6.


**Componentes Relacionados**

A continuación se presentan los componentes relacionados, puedes hacer clic para aprender a utilizarlos.

.. toctree::
   :maxdepth: 2

   ar_fading
   ar_colorful_light