.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_74hc595:

74HC595
===========

.. image:: img/74HC595.png

El 74HC595 consiste en un registro de desplazamiento de 8 bits y un registro de almacenamiento con salidas paralelas de tres estados. Convierte la entrada serial en salida paralela para que puedas ahorrar puertos de E/S de un MCU.
Cuando MR (pin 10) está a nivel alto y OE (pin 13) a nivel bajo, los datos se introducen en el borde ascendente de SHcp y van al registro de memoria a través del borde ascendente de SHcp. Si los dos relojes están conectados juntos, el registro de desplazamiento siempre está un pulso antes que el registro de memoria. Hay un pin de entrada de desplazamiento serial (Ds), un pin de salida serial (Q) y un botón de reinicio asíncrono (nivel bajo) en el registro de memoria. El registro de memoria emite un Bus con 8 bits paralelos y en tres estados. Cuando OE está activado (nivel bajo), los datos en el registro de memoria se emiten al bus.

* `Hoja de Datos del 74HC595 <https://www.ti.com/lit/ds/symlink/cd74hc595.pdf?ts=1617341564801>`_

.. image:: img/74hc595_pin.png
    :width: 600

Pines del 74HC595 y sus funciones:

* **Q0-Q7**: Pines de salida de datos paralelos de 8 bits, capaces de controlar 8 LEDs o 8 pines de un display de 7 segmentos directamente.
* **Q7'**: Pin de salida en serie, conectado al DS de otro 74HC595 para conectar múltiples 74HC595s en serie.
* **MR**: Pin de reinicio, activo a nivel bajo.
* **SHcp**: Entrada de secuencia temporal del registro de desplazamiento. En el borde ascendente, los datos en el registro de desplazamiento se mueven sucesivamente un bit, es decir, los datos en Q1 se mueven a Q2, y así sucesivamente. Mientras que en el borde descendente, los datos en el registro de desplazamiento permanecen sin cambios.
* **STcp**: Entrada de secuencia temporal del registro de almacenamiento. En el borde ascendente, los datos en el registro de desplazamiento se mueven al registro de memoria.
* **CE**: Pin de habilitación de salida, activo a nivel bajo.
* **DS**: Pin de entrada de datos seriales.
* **VCC**: Voltaje de alimentación positivo.
* **GND**: Tierra.

**Ejemplo**

* :ref:`ar_shiftout` (Proyecto Básico)
* :ref:`ar_segment` (Proyecto Básico)
* :ref:`iot_gate` (Proyecto IoT)

