.. _ar_calibration:

5.14 Calibración
==========================

Cuando usas componentes de entrada analógica, como fotoresistencias, sensores de humedad del suelo, etc., puedes notar que su rango de lectura no es de 0 a 1023, sino más bien un rango como de 0 a 800 o de 600 a 1000, porque es imposible alcanzar los límites de estos dispositivos con un uso normal.

En este caso, se puede utilizar una técnica para calibrar las entradas de los sensores. Durante el inicio, haz que la placa de control mida las lecturas del sensor durante cinco segundos y registre las lecturas más altas y más bajas. Esta lectura de cinco segundos define los valores mínimos y máximos esperados de las lecturas tomadas durante el ciclo.


En este proyecto, usamos una fotoresistencia y un zumbador pasivo para implementar un juego tipo `theremin <https://en.wikipedia.org/wiki/Theremin>`_ utilizando la técnica de calibración descrita anteriormente.

.. note::
    El `theremin <https://en.wikipedia.org/wiki/Theremin>`_ es un instrumento musical electrónico que no requiere contacto físico. Genera diferentes tonos detectando la posición de las manos del jugador.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Esquemático**

.. image:: img/circuit_8.8_calibration.png

**Cableado**

.. image:: img/calibration_bb.jpg
    :width: 600
    :align: center

**Código**

.. note::

    * Abre el archivo ``5.14.calibration.ino`` en la ruta ``3in1-kit\basic_project\5.14.calibration``.
    * O copia este código en el **Arduino IDE**.
    
    * O carga el código a través del `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/9cbcaae0-3c9d-4e33-9957-548f92a9aab7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Una vez que el código se haya cargado con éxito, el LED se encenderá y tendremos 5 segundos para calibrar el rango de detección de la fotoresistencia. Esto se debe a que podemos estar en un entorno lumínico diferente cada vez que lo usamos (por ejemplo, la intensidad de la luz es diferente entre el mediodía y el atardecer).

En este momento, necesitamos mover nuestras manos hacia arriba y hacia abajo sobre la fotoresistencia, y el rango de movimiento de la mano se calibrará al rango de reproducción de este instrumento.

Después de 5 segundos, el LED se apagará y podremos mover nuestras manos sobre la fotoresistencia para tocar.

**¿Cómo funciona?**

#. Establece los valores iniciales y los pines de todos los componentes.

    .. code-block:: arduino

        const int buzzerPin = 9;
        const int ledPin = 8;
        const int photocellPin = A0;  //photoresistor attach to A2
    
        int lightLow = 1023;
        int lightHigh = 0;
    
        int sensorValue = 0;        // value read from the sensor
        int pitch = 0;           // sensor value converted into LED 'bars'
    
        unsigned long previousMillis = 0;
        const long interval = 5000;

#. Configura un proceso de calibración en ``setup()``.

    .. code-block:: arduino

        void setup()
        {
           pinMode(buzzerPin, OUTPUT); // make buzzer output
            pinMode(ledPin, OUTPUT); // make the LED pin output

            /* calibrate the photoresistor max & min values */
            previousMillis = millis();
            digitalWrite(ledPin, HIGH);
            while (millis() - previousMillis <= interval) {
                sensorValue = analogRead(photocellPin);
                if (sensorValue > lightHigh) {
                    lightHigh = sensorValue;
                }
                if (sensorValue < lightLow) {
                    lightLow = sensorValue;
                }
            }
            digitalWrite(ledPin, LOW);
        }

    El flujo de trabajo es el siguiente.

    * utilizando ``millis()`` para temporización con un intervalo de 5000 ms.

    .. code-block:: arduino

        previousMillis = millis();
        ...
        while (millis() - previousMillis <= interval) {
        ...
        }

    * Durante estos cinco segundos, mueve una mano alrededor de la fotoresistencia, se registran y asignan los valores máximos y mínimos de la luz detectada a ``lightHigh`` y ``lightLow`` respectivamente.

    .. code-block:: arduino
        
        sensorValue = analogRead(photocellPin);
        if (sensorValue > lightHigh) {
            lightHigh = sensorValue;
        }
        if (sensorValue < lightLow) {
            lightLow = sensorValue;
        }

#. Ahora puedes comenzar a tocar este Thermin. Lee el valor de la fotoresistencia en ``sensorValue`` y mapealo del rango pequeño al grande para usarlo como la frecuencia del zumbador. 

    .. code-block:: arduino

        void loop()
        {
        /* play*/
        sensorValue = analogRead(photocellPin); //read the value of A0
        pitch = map(sensorValue, lightLow, lightHigh, 50, 6000);  // map to the buzzer frequency
        if (pitch > 50) {
            tone(buzzerPin, pitch, 20);
        }
        delay(10);
        }