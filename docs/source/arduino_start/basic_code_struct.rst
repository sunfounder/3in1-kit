.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

Estructura del Programa Arduino
==================================

Echemos un vistazo al nuevo archivo de sketch. Aunque tiene unas pocas líneas de código, en realidad es un sketch "vacío". 
Subir este sketch a la placa de desarrollo no causará ningún efecto.

.. code-block:: C

    void setup() {
    // put your setup code here, to run once:

    }

    void loop() {
    // put your main code here, to run repeatedly:

    }

Si eliminamos ``setup()`` y ``loop()`` y hacemos que el sketch sea realmente un archivo ``blank``, verás que no pasa la verificación. 
Son el equivalente al esqueleto humano, e indispensables.

Durante el sketching, ``setup()`` se ejecuta primero, y el código dentro de él (dentro de ``{}``) se ejecuta después de que la placa se encienda o se reinicie y solo una vez. 
``loop()`` se utiliza para escribir la característica principal, y el código dentro de él se ejecutará en un bucle después de que se ejecute ``setup()``.

Para entender mejor setup() y loop(), usemos cuatro sketches. Su propósito es hacer parpadear el LED integrado de Arduino. Por favor, ejecuta cada experimento por turnos y registra sus efectos específicos.

* Sketch 1: Hacer parpadear continuamente el LED integrado.

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

* Sketch 2: Hacer parpadear el LED integrado solo una vez.

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // put your main code here, to run repeatedly:
    }

* Sketch 3: Hacer parpadear lentamente el LED integrado una vez y luego parpadear rápidamente.

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* Sketch 4: Reportar un error.

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // put your main code here, to run repeatedly:
    }    

Con la ayuda de estos sketches, podemos resumir varias características de ``setup-loop``.

* ``loop()`` se ejecutará repetidamente después de que la placa se encienda.
* ``setup()`` se ejecutará solo una vez después de que la placa se encienda.
* Después de que la placa se encienda, ``setup()`` se ejecutará primero, seguido de ``loop()``.
* El código necesita ser escrito dentro del alcance de ``{}`` de ``setup()`` o ``loop()``, fuera del marco será un error.

.. note::  
    Instrucciones como ``digitalWrite(13,HIGH)`` se utilizan para controlar el LED integrado, y hablaremos en detalle sobre su uso en capítulos posteriores.
