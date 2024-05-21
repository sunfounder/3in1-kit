.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_dht11:

5.11.3 Temperatura - Humedad
===============================

La humedad y la temperatura están estrechamente relacionadas desde la cantidad física misma hasta la vida real de las personas.
La temperatura y la humedad del entorno humano afectarán directamente la función termorreguladora y el efecto de transferencia de calor del cuerpo humano.
Esto influirá aún más en la actividad del pensamiento y el estado mental, afectando así la eficiencia de nuestro estudio y trabajo.

La temperatura es una de las siete cantidades físicas básicas en el Sistema Internacional de Unidades, que se utiliza para medir el grado de calor o frío de un objeto.
El Celsius es una de las escalas de temperatura más utilizadas en el mundo, expresada por el símbolo "℃".

La humedad es la concentración de vapor de agua presente en el aire.
La humedad relativa del aire es comúnmente utilizada en la vida cotidiana y se expresa en %HR. La humedad relativa está estrechamente relacionada con la temperatura.
Para un cierto volumen de gas sellado, cuanto mayor es la temperatura, menor es la humedad relativa, y cuanto menor es la temperatura, mayor es la humedad relativa.

.. image:: img/Dht11.png

El dht11, un sensor digital de temperatura y humedad, se proporciona en este kit. Utiliza un sensor de humedad capacitivo y un termistor para medir el aire circundante y emite una señal digital en el pin de datos.

**Componentes Necesarios**

En este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS EN ESTE KIT
        - ENLACE
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

También puedes comprarlos por separado en los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_dht11`
        - \-


**Esquemático**

.. image:: img/circuit_7.3_dht11.png

**Cableado**

.. image:: img/dht11_bb.jpg

**Código**

.. note::

    * Abre el archivo ``5.11.temperature_humidity.ino`` en la ruta ``3in1-kit\basic_project\5.11.temperature_humidity``.
    * O copia este código en el **Arduino IDE**.
    * Aquí se usa la ``DHT sensor library``, puedes instalarla desde el **Library Manager**.

        .. image:: ../img/lib_dht11.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c5b4c902-f39d-45a6-9a17-1308056041a8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de que el código se haya cargado con éxito, verás que el Monitor Serial imprime continuamente la temperatura y la humedad. A medida que el programa se ejecute de manera estable, estos dos valores se volverán cada vez más precisos.

**¿Cómo funciona?**

#. Incluye la biblioteca ``DHT.h``, que proporciona funciones para interactuar con los sensores DHT. Luego, establece el pin y el tipo para el sensor DHT.

    .. code-block:: arduino

        #include "DHT.h"

        #define DHTPIN 11  // Set the pin connected to the DHT11 data pin
        #define DHTTYPE DHT11 // DHT 11 

        DHT dht(DHTPIN, DHTTYPE);

#. Inicializa la comunicación serial con una tasa de baudios de 115200 e inicializa el sensor DHT.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            Serial.println("DHT11 test!");
            dht.begin();
        }

#. En la función ``loop()``, lee los valores de temperatura y humedad del sensor DHT11 e imprímelos en el monitor serial.

    .. code-block:: arduino

        void loop() {
            // Wait a few seconds between measurements.
            delay(2000);

            // Reading temperature or humidity takes about 250 milliseconds!
            // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
            float humidity = dht.readHumidity();
            // Read temperature as Celsius (the default)
            float temperture = dht.readTemperature();

            // Check if any reads failed and exit early (to try again).
            if (isnan(humidity) || isnan(temperture)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
            // Print the humidity and temperature
            Serial.print("Humidity: "); 
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("Temperature: ");  
            Serial.print(temperture);
            Serial.println(" *C");
        }

    * Se llama a la función ``dht.readHumidity()`` para leer el valor de humedad del sensor DHT.
    * Se llama a la función ``dht.readTemperature()`` para leer el valor de temperatura del sensor DHT.
    * Se utiliza la función ``isnan()`` para verificar si las lecturas son válidas. Si el valor de humedad o temperatura es NaN (no es un número), indica una lectura fallida del sensor y se imprime un mensaje de error.

