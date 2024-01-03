.. _ar_74hc_7seg:

5.15 EEPROM
==============

`EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ es una memoria que conserva los datos almacenados incluso cuando se apaga la placa controladora principal. Puedes usarla para registrar algunos datos y leerlos la próxima vez que la enciendas.

Por ejemplo, puedes crear un contador deportivo que lleve la cuenta de cuántas veces saltas la cuerda cada día.

También es posible escribir datos en ella mediante un programa y leerlos en otro. Por ejemplo, en un proyecto de automóviles, si las velocidades de los dos motores son diferentes, puedes escribir un programa de calibración para registrar el valor de compensación de la velocidad del motor.

**Componentes Necesarios**

Para este proyecto, necesitamos los siguientes componentes.

Comprar un kit completo es definitivamente conveniente, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre
        - ELEMENTOS DE ESTE KIT
        - ENLACE
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

También puedes comprarlos por separado en los siguientes enlaces.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**Esquemático**

.. image:: img/circuit_515_eeprom.png

**Cableado**

.. image:: img/eeprom_servo.png

**Código**


.. note::

    * Abre el archivo ``5.15.eeproom.ino`` en la ruta ``3in1-kit\basic_project\5.15.eeproom``.
    * O copia este código en **Arduino IDE**.
    
    * O sube el código a través del `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7378341f-9c1a-4171-814f-c76c109e1e67/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Para usar este circuito, simplemente presiona el botón para comenzar a grabar e introduce la información deseada a través de un potenciómetro. Ahora, la placa repetirá tus acciones indefinidamente (y parpadeará un led en cada iteración) hasta que presiones de nuevo el botón para grabar nuevas acciones. También puedes variar la cantidad de tiempo grabado cambiando los valores de resolución y tiempo de grabación.


**¿Cómo funciona?**

#. Importa la biblioteca ``EEPROM.h`` e inicializa la memoria EEPROM.

    .. code-block:: arduino

        ...
        #include <EEPROM.h>//used to store recorded values

        ...
        float resolution = 1000;//MUST be less than EEPROM.length()
        float recordTime = 5; //delay time
        bool recording = false;
        ...
    
    Ten en cuenta que ``/MUST be less than EEPROM.length()``, en ``setup()`` se imprimirá la memoria EEPROM de tu placa, que debería ser 1024 para la placa SunFounder R3. Si estás utilizando una placa diferente, puedes cambiar el valor de la variable ``resolution``.

#. Imprime la memoria EEPROM de tu placa.

    .. code-block:: arduino

        void setup() {
            ...
            Serial.begin(9600);
            //Serial.println(EEPROM.length());
        }

    Para encontrar el tamaño de la memoria EEPROM de tu placa, descomenta la línea ``Serial.println(EEPROM.read(i))``. Esto imprimirá el tamaño de la EEPROM en el monitor serie, y puedes cambiar el valor de la variable ``resolution`` en consecuencia.

#. Tan pronto como se detecta una pulsación de botón, comienza la grabación y se introduce la información requerida a través de un potenciómetro. Ahora la placa repite tu acción indefinidamente (y hace parpadear un LED en cada repetición) hasta que presiones el botón nuevamente, grabando una nueva acción.

    .. code-block:: arduino

        void loop() {
            if (recording == true) {//record
                for (int i = 1; i <= resolution; i++) {
                    digitalWrite(ledPin, HIGH); //light status led
                    int val = map(analogRead(A0), 0, 1023, 0, 180);
                    EEPROM.write(i, val);
                    //Serial.println(EEPROM.read(i));
                    myServo.write(val);
                    delay(recordTime);
                }
                digitalWrite(ledPin, LOW); //turn off status led
                delay(1000);//give time for person
                recording = false;
            }
            else {
                for (int i = 1; i <= resolution; i++) {//playback
                    if (digitalRead(buttonPin) == 0) {//stop playback and record new values
                        recording = true;
                        break;
                    }
                    int readval = EEPROM.read(i);
                    myServo.write(readval);
                    //Serial.println(readval);
                    delay(recordTime);
                }
                digitalWrite(ledPin, HIGH); //show a new repeat
                delay(100);
                digitalWrite(ledPin, LOW);
            }
        }

    * Haz que la variable ``recording`` sea verdadera cuando se presione el botón.
    * Cuando la variable ``recording`` sea verdadera, comienza a grabar la acción en el rango de memoria.
    * Lee el valor del potenciómetro y mapealo de 0 a 180 para almacenarlo en la EEPROM y controlar la rotación del servo.
    * El LED se enciende al comienzo de la grabación y se apaga al final.
    * Repite la acción grabada con un parpadeo rápido del LED para recordarte una nueva repetición.


#. Acerca de la biblioteca ``EEPROM``.

    Aquí algunas de sus funciones.
        
    * ``write(address,value)``: Escribe un byte en la EEPROM.

        * ``address``: la ubicación donde escribir, comenzando desde 0 (int)
        * ``value``: el valor a escribir, de 0 a 255 (byte)
        * Una escritura en la EEPROM tarda 3.3 ms en completarse. La memoria EEPROM tiene una vida especificada de 100,000 ciclos de escritura/borrado, por lo que podrías necesitar tener cuidado con la frecuencia con la que escribes en ella.

    * ``Read(address)``: Lee un byte de la EEPROM. Las ubicaciones que nunca se han escrito tienen el valor de 255.

    * ``update(address,value)``: Escribe un byte en la EEPROM. El valor se escribe solo si es diferente del que ya está guardado en la misma dirección.

        * Una escritura en la EEPROM tarda 3.3 ms en completarse. La memoria EEPROM tiene una vida especificada de 100,000 ciclos de escritura/borrado, así que usar esta función en lugar de write() puede ahorrar ciclos si los datos escritos no cambian con frecuencia.

    * ``EEPROM.put(address, data)``: Escribe cualquier tipo de dato u objeto en la EEPROM.

        * ``address``: la ubicación donde leer, comenzando desde 0 (int).
        * ``data``: el dato a leer, puede ser un tipo primitivo (p.ej. float) o una estructura personalizada.
        * Esta función usa EEPROM.update() para realizar la escritura, por lo que no reescribe el valor si no ha cambiado.

    * ``EEPROM.get(address, data)``: Lee cualquier tipo de dato u objeto de la EEPROM.

        * ``address``: la ubicación donde leer, comenzando desde 0 (int).
        * ``data``: el dato a leer, puede ser un tipo primitivo (p.ej. float) o una estructura personalizada.
