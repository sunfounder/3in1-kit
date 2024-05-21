.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

Variable
========

La variable es una de las herramientas más poderosas y críticas en un programa. Nos permite almacenar y acceder a datos en nuestros programas.

El siguiente archivo de boceto utiliza variables. Almacena los números de pin del LED integrado en la variable ``ledPin`` y un número "500" en la variable ``delayTime``.

.. code-block:: C
    :emphasize-lines: 1,2

    int ledPin = 13;
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

Espera, ¿esto es una duplicación de lo que hace ``#define``? La respuesta es NO.

* El papel de ``#define`` es simplemente y directamente reemplazar texto, no es considerado por el compilador como parte del programa.
* Una ``variable``, por otro lado, existe dentro del programa y se utiliza para almacenar y acceder a valores. Una variable también puede modificar su valor dentro del programa, algo que un define no puede hacer.

El archivo de boceto a continuación se autoincrementa en la variable y hará que el LED integrado parpadee más tiempo después de cada parpadeo.

.. code-block:: C

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
        delayTime = delayTime+200; //Each execution increments the value by 200
    }

Declarar una variable
------------------------

Declarar una variable significa crear una variable.

Para declarar una variable, necesitas dos cosas: el tipo de dato y el nombre de la variable. El tipo de dato debe estar separado de la variable por un espacio, y la declaración de la variable debe terminar con un ``;``.

Usaremos esta variable como ejemplo.

.. code-block:: C

    int delayTime;

**Tipo de Dato**

Aquí ``int`` es un tipo de dato llamado tipo entero, que se puede usar para almacenar enteros desde -32768 hasta 32767. También no se puede usar para almacenar decimales.

Las variables pueden contener diferentes tipos de datos aparte de enteros. El lenguaje Arduino (que, recuerda, es C++) tiene soporte incorporado para algunos de ellos (solo se enumeran los más usados y útiles aquí):

* ``float``: Almacena un número decimal, por ejemplo, 3.1415926.
* ``byte``: Puede contener números de 0 a 255.
* ``boolean``: Solo admite dos valores posibles, ``True`` o ``False``, aunque ocupa un byte en la memoria.
* ``char``: Contiene un número de -127 a 127. Debido a que se marca como ``char``, el compilador intentará hacerlo coincidir con un carácter de |link_ascii|.
* ``string``: Puede almacenar una cadena de caracteres, por ejemplo, ``Halloween``.

**Nombre de la Variable**

Puedes ponerle a la variable el nombre que quieras, como ``i``, ``apple``, ``Bruce``, ``R2D2``, ``Sectumsempra``, pero hay algunas reglas básicas a seguir.

1. Describir para qué se usa. Aquí, nombré la variable delayTime, para que puedas entender fácilmente qué hace. Funcionaría bien si nombrara la variable ``barryAllen``, pero confundiría a la persona que mira el código.

2. Usar una nomenclatura común. Puedes usar CamelCase como hice yo, con la T inicial en ``delayTime`` para que sea fácil ver que la variable consta de dos palabras. También, puedes usar UnderScoreCase para escribir la variable como ``delay_time``. No afecta la ejecución del programa, pero ayudará al programador a leer el código si usas la nomenclatura que prefieras.

3. No usar palabras clave. Similar a lo que sucede cuando escribimos "int", el IDE de Arduino lo coloreará para recordarte que es una palabra con un propósito especial y no se puede usar como nombre de variable. Cambia el nombre de la variable si está coloreada.

4. No se permiten símbolos especiales. Por ejemplo, espacio, #, $, /, +, %, etc. La combinación de letras en inglés (sensible a mayúsculas y minúsculas), guiones bajos y números (pero los números no pueden usarse como el primer carácter de un nombre de variable) es lo suficientemente rica.

**Asignar un valor a una variable**

Una vez que hemos declarado la variable, es hora de almacenar los datos. Usamos el operador de asignación (es decir, ``=``) para poner valor en la variable.

Podemos asignar valores a la variable tan pronto como la declaramos.

.. code-block:: C

    int delayTime = 500;

También es posible asignarle un nuevo valor en algún momento.

.. code-block:: C

    int delayTime; // no value
    delayTime = 500; // value is 500
    delayTime = delayTime +200; // value is 700
