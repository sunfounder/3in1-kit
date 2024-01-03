.. _cpn_soil_moisture:

Módulo de Humedad del Suelo
================================

.. image:: img/soil_mositure.png

* GND: Tierra
* VCC: Fuente de alimentación, 3.3v~5V
* AOUT: Emite el valor de la humedad del suelo, cuanto más húmedo esté el suelo, menor será su valor.

Este sensor de humedad del suelo capacitivo es diferente de la mayoría de los sensores resistivos en el mercado, utilizando el principio de inducción capacitiva para detectar la humedad del suelo. Evita el problema de que los sensores resistivos sean altamente susceptibles a la corrosión y prolonga en gran medida su vida útil.

Está hecho de materiales resistentes a la corrosión y tiene una excelente vida útil. Insértelo en el suelo alrededor de las plantas y monitoree los datos de humedad del suelo en tiempo real. El módulo incluye un regulador de voltaje a bordo que le permite operar en un rango de voltaje de 3.3 ~ 5.5 V. Es ideal para microcontroladores de bajo voltaje con suministros de 3.3 V y 5 V.

El esquemático del hardware del sensor de humedad del suelo capacitivo se muestra a continuación.

.. image:: img/solid_schematic.png

Hay un oscilador de frecuencia fija, que se construye con un IC temporizador 555. La onda cuadrada generada se alimenta entonces al sensor como un capacitor. Sin embargo, para la señal de onda cuadrada, el capacitor tiene una cierta reactancia o, para el caso, un resistor con un resistor óhmico puro (resistor de 10k en el pin 3) para formar un divisor de voltaje.

Cuanto mayor es la humedad del suelo, mayor es la capacitancia del sensor. Como resultado, la onda cuadrada tiene menos reactancia, lo que reduce el voltaje en la línea de señal, y menor es el valor de la entrada analógica a través del microcontrolador.

**Especificaciones**

* Voltaje de Operación: 3.3 ~ 5.5 VDC
* Voltaje de Salida: 0 ~ 3.0VDC
* Corriente de Operación: 5mA
* Interfaz: PH2.0-3P
* Dimensiones: 3.86 x 0.905 pulgadas (L x A)
* Peso: 15g

**Ejemplo**

* :ref:`ar_moisture` (Proyecto Básico)
* :ref:`iot_plant` (Proyecto IoT)
