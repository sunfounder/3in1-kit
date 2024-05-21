.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

Cómo Construir el Circuito
===============================

Muchos de los objetos que usas a diario funcionan con electricidad, como las luces de tu casa y el ordenador que estás usando.

Para usar la electricidad, debes construir un circuito eléctrico. Básicamente, un circuito es un camino por el cual fluye la electricidad, o un circuito electrónico, y está compuesto por dispositivos y componentes eléctricos (aparatos) que están conectados de cierta manera, como resistencias, condensadores, fuentes de alimentación y interruptores.

.. image:: img/circuit.png

Un circuito es un camino cerrado por el cual se mueven los electrones para crear una corriente eléctrica. Para que fluya la corriente, debe haber un camino conductor entre el terminal positivo de la fuente de alimentación y el terminal negativo, lo que se llama un circuito cerrado (si está roto, se llama circuito abierto).

La Placa Arduino tiene algunos pines de salida de energía (positivos) y algunos pines de tierra (negativos).
Puedes usar estos pines como los lados positivo y negativo de la fuente de alimentación conectando la fuente de poder a la placa.

.. image:: img/arduinoPN.jpg

Con la electricidad, puedes crear obras con luz, sonido y movimiento.
Puedes iluminar un LED conectando el pin largo al terminal positivo y el pin corto al terminal negativo.
El LED se dañará muy rápidamente si haces esto, por lo que necesitas agregar una resistencia de 220* ohmios dentro del circuito para protegerlo.

El circuito que forman se muestra a continuación.

.. image:: img/sp221014_181625.png

Puede que te preguntes en este momento: ¿cómo construyo este circuito? ¿Sujetando los cables con la mano o pegando los pines y los cables con cinta?

En esta situación, las placas de pruebas sin soldadura serán tus mejores aliadas.

.. _bc_bb:

¡Hola, Protoboard!
------------------------------

Un protoboard es una placa de plástico rectangular con un montón de pequeños agujeros.
Estos agujeros nos permiten insertar fácilmente componentes electrónicos y construir circuitos electrónicos. 
Los protoboards no fijan permanentemente los componentes electrónicos, por lo que podemos reparar fácilmente un circuito y comenzar de nuevo si algo sale mal.

.. note::
    No se necesitan herramientas especiales para usar protoboards. Sin embargo, muchos componentes electrónicos son muy pequeños, y un par de pinzas pueden ayudarnos a recoger partes pequeñas mejor.

En Internet, podemos encontrar mucha información sobre protoboards.

* `Cómo Usar un Protoboard - Science Buddies <https://www.sciencebuddies.org/science-fair-projects/references/how-to-use-a-breadboard#pth-smd>`_

* `¿Qué es un PROTOBOARD? - Makezine <https://cdn.makezine.com/uploads/2012/10/breadboardworkshop.pdf>`_

Aquí hay algunas cosas que debes saber sobre los protoboards.

#. Cada grupo de medio renglón (como la columna A-E en el renglón 1 o la columna F-J en el renglón 3) está conectado. Por lo tanto, si una señal eléctrica entra por A1, puede salir por B1, C1, D1, E1, pero no por F1 o A2.

#. En la mayoría de los casos, ambos lados del protoboard se utilizan como buses de energía, y los agujeros en cada columna (unos 50 agujeros) están conectados entre sí. Como regla general, las fuentes de alimentación positivas se conectan a los agujeros cerca del cable rojo, y las fuentes de alimentación negativas se conectan a los agujeros cerca del cable azul.

#. En un circuito, la corriente fluye del polo positivo al polo negativo después de pasar por la carga. En este caso, puede ocurrir un cortocircuito.

**¡Sigamos la dirección de la corriente para construir el circuito!**

.. image:: img/sp221014_182229_2.png

1. En este circuito, usamos el pin de 5V de la placa para alimentar el LED. Utiliza un cable puente macho a macho (M2M) para conectarlo al bus de energía rojo.
#. Para proteger el LED, la corriente debe pasar por una resistencia de 220 ohmios. Conecta un extremo (cualquiera) de la resistencia al bus de energía rojo, y el otro extremo a una fila libre del protoboard.

    .. note::
        El anillo de color de la resistencia de 220 ohmios es rojo, rojo, negro, negro y marrón.

#. Si levantas el LED, verás que uno de sus cables es más largo que el otro. Conecta el cable más largo a la misma fila que la resistencia, y el cable más corto a otra fila.

    .. note::
        El cable más largo es el ánodo, que representa el lado positivo del circuito; el cable más corto es el cátodo, que representa el lado negativo. 

        El ánodo debe conectarse al pin GPIO a través de una resistencia; el cátodo debe conectarse al pin GND.

#. Con un cable puente macho a macho (M2M), conecta el pin corto del LED al bus de energía negativa del protoboard.
#. Conecta el pin GND de la placa al bus de energía negativa usando un puente.

Cuidado con los cortocircuitos
------------------------------
Los cortocircuitos pueden ocurrir cuando dos componentes que no deberían estar conectados se conectan "accidentalmente". 
Este kit incluye resistencias, transistores, condensadores, LEDs, etc., que tienen largos pines metálicos que pueden chocar entre sí y causar un corto. Algunos circuitos simplemente dejan de funcionar correctamente cuando ocurre un cortocircuito. Ocasionalmente, un cortocircuito puede dañar componentes permanentemente, especialmente entre la fuente de alimentación y el bus de tierra, causando que el circuito se caliente mucho, derritiendo el plástico en el protoboard e incluso quemando los componentes.

Por lo tanto, siempre asegúrate de que los pines de todos los componentes electrónicos en el protoboard no se estén tocando entre sí.

Orientación del circuito
-------------------------------
Los circuitos tienen una orientación, y esta juega un papel significativo en ciertos componentes electrónicos. Hay dispositivos con polaridad, lo que significa que deben conectarse correctamente en base a sus polos positivo y negativo. Los circuitos construidos con la orientación incorrecta no funcionarán adecuadamente.

.. image:: img/sp221014_182229.png

Si inviertes el LED en este simple circuito que construimos anteriormente, encontrarás que ya no funciona.

En cambio, algunos dispositivos no tienen dirección, como las resistencias en este circuito, por lo que puedes intentar invertirlas sin afectar el funcionamiento normal de los LEDs.

La mayoría de los componentes y módulos con etiquetas como "+", "-", "GND", "VCC" o que tienen pines de diferentes longitudes deben conectarse al circuito de una manera específica.


Protección del circuito
-------------------------------------

La corriente es la tasa a la que los electrones fluyen a través de un punto en un circuito eléctrico completo. En su forma más básica, corriente = flujo. Un amperio (AM-pir), o amp, es la unidad internacional utilizada para medir la corriente. Expresa la cantidad de electrones (a veces llamada "carga eléctrica") que fluyen por un punto en un circuito durante un tiempo determinado.

La fuerza impulsora (voltaje) detrás del flujo de corriente se llama voltaje y se mide en voltios (V).

La resistencia (R) es la propiedad del material que restringe el flujo de corriente, y se mide en ohmios (Ω).

Según la ley de Ohm (siempre que la temperatura permanezca constante), la corriente, el voltaje y la resistencia son proporcionales.
La corriente de un circuito es proporcional a su voltaje e inversamente proporcional a su resistencia.

Por lo tanto, corriente (I) = voltaje (V) / resistencia (R).

* `Ley de Ohm - Wikipedia <https://en.wikipedia.org/wiki/Ohm%27s_law>`_

Sobre la ley de Ohm podemos hacer un experimento simple.

.. image:: img/sp221014_183107.png

Al cambiar el cable que conecta 5V a 3.3V, el LED se atenúa.
Si cambias la resistencia de 220ohmios a 1000ohmios (anillo de color: marrón, negro, negro, marrón y marrón), notarás que el LED se atenúa más que antes. Cuanto mayor es la resistencia, más tenue es el LED.

.. note::
    Para una introducción a las resistencias y cómo calcular valores de resistencia, ver :ref:`cpn_resistor`.

La mayoría de los módulos empaquetados solo requieren acceso al voltaje adecuado (generalmente 3.3V o 5V), como el módulo ultrasónico.

Sin embargo, en tus circuitos autoconstruidos, necesitas estar consciente del voltaje de suministro y el uso de resistencias para dispositivos eléctricos.


Como ejemplo, los LEDs suelen consumir 20mA de corriente, y su caída de voltaje es de aproximadamente 1.8V. Según la ley de Ohm, si usamos una fuente de alimentación de 5V, necesitamos conectar una resistencia mínima de 160ohmios ((5-1.8)/20mA) para no quemar el LED.


Circuito de Control con Arduino
--------------------------------

Ahora que tenemos un conocimiento básico de la programación de Arduino y los circuitos electrónicos, es hora de enfrentar la pregunta más crítica: ¿Cómo controlar circuitos con Arduino?

En términos simples, la forma en que Arduino controla un circuito es cambiando el nivel de los pines en la placa. Por ejemplo, al controlar un LED integrado, está escribiendo una señal de nivel alto o bajo al pin 13.

Ahora intentemos programar la placa Arduino para controlar el parpadeo de un LED en el protoboard. Construye el circuito de manera que el LED esté conectado al pin 9.

.. image:: img/wiring_led.png
    :width: 400
    :align: center

A continuación, sube este boceto a la placa de desarrollo Arduino.

.. code-block:: C

    int ledPin = 9;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
    }

Este boceto es muy similar al que usamos para controlar el parpadeo del LED integrado, la diferencia es que el valor de ``ledPin`` se ha cambiado a 9.
Esto se debe a que estamos intentando controlar el nivel del pin 9 esta vez.

Ahora puedes ver el LED en el protoboard parpadeando.

