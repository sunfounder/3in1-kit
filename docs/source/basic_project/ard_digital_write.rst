.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_digital_write:

1. Escritura Digital
==============================

La **Escritura Digital** consiste en enviar o escribir una señal digital a un pin digital. La señal digital solo tiene dos estados, 0 o 1, 0V o 5V, lo que permite que algunos componentes, como el LED y el zumbador, estén encendidos o apagados.

En la placa Arduino R3, hay 14 pines digitales I/0 desde el 0 hasta el 13. Ahora, utiliza las funciones ``pinMode()`` y ``digitalWrite()`` para escribir un nivel alto o bajo en estos pines digitales.


* ``pinMode(pin, mode)``: Configura un pin específico como ``INPUT`` o ``OUTPUT``, aquí se necesita configurar como ``OUTPUT``. 

   **Sintaxis**
      pinMode(pin, mode)

   **Parámetros**
    * ``pin``: el número de pin de Arduino para establecer el modo.
    * ``mode``: ``INPUT``, ``OUTPUT``, o ``INPUT_PULLUP``.


* ``digitalWrite(pin, value)``: Escribe un nivel alto (5V) o bajo (0V) en un pin digital para cambiar el estado operativo del componente. Si el pin ha sido configurado como un OUTPUT con pinMode(), su voltaje se establecerá en el valor correspondiente: 5V (o 3.3V en placas de 3.3V) para HIGH, 0V (tierra) para LOW.


   **Sintaxis**
      digitalWrite(pin, value)

   **Parámetros**
    * ``pin``: el número de pin de Arduino.
    * ``value``: ``HIGH`` o ``LOW``.

**Ejemplo de Escritura Digital:**

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

**Notas y Advertencias**

* Los pines del 0 al 13 son todos pines digitales.
* No utilices los pines 0 y 1, ya que se utilizan para comunicarse con el ordenador. Conectar algo a estos pines interferirá con la comunicación, incluyendo causar que la carga de la placa falle.
* Si se agotan los pines digitales, los pines analógicos (A0-A5) también pueden usarse como pines digitales.

**Componentes Relacionados**

A continuación se presentan los componentes relacionados, puedes hacer clic para aprender a utilizarlos.

.. toctree::
   :maxdepth: 2

   ar_blinking_led
   ar_active_buzzer
   ar_turn_the_wheel
   ar_pumping
