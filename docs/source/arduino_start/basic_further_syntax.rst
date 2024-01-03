Regla de Escritura de Sketch
================================

Si le pides a un amigo que te encienda las luces, puedes decir "Enciende las luces" o "Luces encendidas, amigo", y puedes usar cualquier tono de voz que quieras.

Sin embargo, si quieres que la placa Arduino haga algo por ti, necesitas seguir las reglas de escritura del programa Arduino para teclear los comandos.

Este capítulo contiene las reglas básicas del lenguaje Arduino y te ayudará a entender cómo traducir el lenguaje natural en código.

Por supuesto, este es un proceso que lleva tiempo familiarizarse, y también es la parte del proceso donde los novatos cometen más errores. Así que si cometes errores a menudo, está bien, solo intenta algunas veces más.


Punto y Coma ``;``
--------------------

Al igual que cuando escribes una carta, donde escribes un punto al final de cada frase como final, el lenguaje Arduino requiere que uses ``;`` para indicarle a la placa el final del comando.

Tomemos el ejemplo familiar de "parpadeo del LED integrado". Un sketch saludable debería verse así.

Ejemplo:

.. code-block:: C

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

A continuación, echemos un vistazo a los siguientes dos sketches y adivinemos si pueden ser correctamente reconocidos por Arduino antes de ejecutarlos.

Sketch A:

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

Sketch B:

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }
    
    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,
        
        LOW);
                delay(500)
        ;
    }

El resultado es que **Sketch A** reporta un error y **Sketch B** se ejecuta.

* Los errores en **Sketch A** son la ausencia de ``;`` y aunque se ve normal, Arduino no puede leerlo.
* **Sketch B**, parece anti-intuitivo, pero en realidad, la indentación, los saltos de línea y los espacios en las declaraciones son cosas que no existen en los programas de Arduino, así que para el compilador de Arduino, se ve igual que en el ejemplo.

Sin embargo, por favor no escribas tu código como **Sketch B**, porque normalmente son personas naturales las que escriben y ven el código, así que no te metas en problemas.


Llaves Curvas ``{}``
-----------------------

``{}`` es el componente principal del lenguaje de programación Arduino, y deben aparecer en pares. 
Una mejor convención de programación es insertar una estructura que requiera llaves curvas escribiendo la llave curva derecha inmediatamente después de escribir la llave curva izquierda, y luego mover el cursor entre las llaves curvas para insertar la declaración.



Comentarios ``//``
----------------------

El comentario es la parte del sketch que el compilador ignora. Suelen utilizarse para explicar a otros cómo funciona el programa.

Si escribimos dos barras diagonales adyacentes en una línea de código, el compilador ignorará cualquier cosa hasta el final de la línea.

Si creamos un nuevo sketch, viene con dos comentarios, y si eliminamos estos dos comentarios, el sketch no se verá afectado de ninguna manera.

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // put your setup code here, to run once:

    }

    void loop() {
        // put your main code here, to run repeatedly:

    }

El comentario es muy útil en la programación, y se enumeran varios usos comunes a continuación.

* Uso A: Decirte a ti mismo o a otros qué hace esta sección de código.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); //Set pin 13 to output mode, it controls the onboard LED
    }

    void loop() {
        digitalWrite(13,HIGH); // Activate the onboard LED by setting pin 13 high
        delay(500); // Status quo for 500 ms
        digitalWrite(13,LOW); // Turn off the onboard LED
        delay(500);// Status quo for 500 ms
    }

* Uso B: Invalidar temporalmente algunas declaraciones (sin borrarlas) y descomentarlas cuando necesites usarlas, así no tienes que reescribirlas. Esto es muy útil cuando se depura el código y se intenta localizar errores en el programa.

.. code-block:: C
    :emphasize-lines: 3,4,5,6

    void setup() {
        pinMode(13,OUTPUT);
        // digitalWrite(13,HIGH);
        // delay(1000);
        // digitalWrite(13,LOW);
        // delay(1000);
    }

    void loop() {
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

.. note:: 
    Utiliza el atajo ``Ctrl+/`` para ayudarte a comentar o descomentar rápidamente tu código.

Comentarios ``/**/``
----------------------

Igual que ``//`` para los comentarios. Este tipo de comentario puede tener más de una línea, y una vez que el compilador lee ``/*``, ignora todo lo que sigue hasta que encuentra ``*/``.

Ejemplo 1:

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Blink */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        The following code will blink the onboard LED
        You can modify the number in delay() to change the blinking frequency
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }


``#define``
--------------

Esta es una herramienta útil de C++.

.. code-block:: C

    #define identifier token-string

El compilador automáticamente reemplaza ``identifier`` por ``token-string`` cuando lo lee, lo que se utiliza generalmente para definiciones de constantes.

Como ejemplo, aquí hay un sketch que utiliza define, lo que mejora la legibilidad del código.

.. code-block:: C
    :emphasize-lines: 1,2

    #define ONBOARD_LED 13
    #define DELAY_TIME 500

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
        delay(DELAY_TIME); 
        digitalWrite(ONBOARD_LED,LOW); 
        delay(DELAY_TIME);
    }

Al compilador, realmente se le ve así.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

Podemos ver que el ``identifier`` es reemplazado y no existe dentro del programa.
Por lo tanto, hay varias precauciones al usarlo.

1. Un ``token-string`` solo se puede modificar manualmente y no se puede convertir en otros valores mediante aritmética en el programa.

2. Evita usar símbolos como ``;``. Por ejemplo.

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
    }

El compilador lo reconocerá como lo siguiente, lo que se informará como un error.

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;,OUTPUT); 
    }

    void loop() {
        digitalWrite(13;,HIGH); 
    }

.. note:: 
    Una convención de nomenclatura para ``#define`` es capitalizar ``identifier`` para evitar confusión con variables.
