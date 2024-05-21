.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _iot_plant:

6. Monitor de Plantas
==========================

El propósito de este proyecto es crear un sistema inteligente de riego que detecte la temperatura actual, humedad, intensidad de luz y humedad del suelo, y muestre estos datos en Blynk.

Tan pronto como actives el interruptor de conmutación en Blynk Cloud, la bomba comenzará a funcionar y las plantas serán hidratadas.

**Componentes Necesarios**

Para este proyecto, necesitamos los siguientes componentes.

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
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_dht11`
        - \-
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_pump`
        - \-

**1. Construir el Circuito**

.. note::

    El módulo ESP8266 requiere una alta corriente para proporcionar un entorno operativo estable, así que asegúrate de que la batería de 9V esté conectada.

.. image:: img/wiring_6_plant_monitor_bb.png
    :width: 800

**2. Editar el Tablero de Mandos**

#. Los flujos de datos creados en los proyectos anteriores deben guardarse y se utilizarán también en este proyecto.

#. Para registrar la humedad del suelo, crea otro **Datastream** de tipo **Virtual Pin** en la página de **Datastream**. Configura el TIPO DE DATO a ``Integer`` y el MIN y MAX a ``0`` y ``1024``.

    .. image:: img/sp220610_155221.png

#. Ahora ve a la página de **Wed Dashboard**, arrastra 2 widgets **Label** y configura sus flujos de datos a **V4** y **V5** respectivamente; arrastra 2 widgets **Gauge** y configura sus flujos de datos para mostrar **V6** y **V7** respectivamente; y finalmente arrastra un widget **Interruptor** y configura su flujo de datos a **V0**.

    .. image:: img/sp220610_155350.png

**3. Ejecutar el Código**

Abre el archivo ``6.plant_monitoring.ino`` en la ruta ``3in1-kit\iot_project\6.plant_monitoring``, o copia este código en **Arduino IDE**.

    .. note::

        * Aquí se utiliza la ``DHT sensor library``, puedes instalarla desde el **Library Manager**.

            .. image:: ../img/lib_dht11.png

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/f738bcb5-4ee2-475b-b683-759e6b2041b0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Sustituye el ``Template ID``, ``Device Name`` y ``Auth Token`` por los tuyos. También necesitas ingresar el ``ssid`` y la ``password`` del WiFi que estás utilizando. Para tutoriales detallados, consulta :ref:`connect_blynk`.
#. Después de seleccionar la placa y puerto correctos, haz clic en el botón **Upoad**.

#. Abre el monitor Serial(configura la tasa de baudios a 115200) y espera un aviso como una conexión exitosa.

    .. image:: img/2_ready.png

    .. note::

        Si aparece el mensaje ``ESP is not responding`` al conectar, sigue estos pasos.

        * Asegúrate de que la batería de 9V esté conectada.
        * Restablece el módulo ESP8266 conectando el pin RST a GND durante 1 segundo, luego desenchúfalo.
        * Presiona el botón de reset en la placa R3.

        A veces, puede ser necesario repetir la operación anterior 3-5 veces, por favor ten paciencia.

#. De vuelta en Blynk, verás la temperatura actual, humedad, intensidad de luz y humedad del suelo. Puedes permitir que la bomba riegue las plantas si es necesario haciendo clic en el widget de Control de Botón.

    .. image:: img/sp220610_155350.png

#. Si quieres usar Blynk en dispositivos móviles, consulta :ref:`blynk_mobile`.

    .. image:: img/mobile_plant.jpg

**¿Cómo funciona?**

Este ``BLYNK_WRITE`` hace que el widget **Switch** de Blynk inicie la bomba cuando está ENCENDIDO y la apague cuando está APAGADO.

.. code-block:: arduino

    BLYNK_WRITE(V0)
    {
        if(param.asInt()==1){
            digitalWrite(pumpA,HIGH);
        }else{
            digitalWrite(pumpA,LOW); 
        }
    }


Estas tres funciones se utilizan para obtener la temperatura ambiental actual, humedad, intensidad de luz y humedad del suelo.

.. code-block:: arduino

    int readMoisture(){
        return analogRead(moisturePin);
    }

    int readLight(){
        return analogRead(lightPin);
    }

    bool readDHT() {

        // Reading temperature or humidity takes about 250 milliseconds!
        // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
        humidity = dht.readHumidity();
        // Read temperature as Celsius (the default)
        temperature = dht.readTemperature();

        // Check if any reads failed and exit early (to try again).
        if (isnan(humidity) || isnan(temperature)) {
            Serial.println("Failed to read from DHT sensor!");
            return false;
        }
        return true;
    }

Con el ``Timer`` de Blynk, la temperatura ambiente, humedad, intensidad de luz y humedad del suelo se obtienen cada segundo y se envían al flujo de datos en **Blynk Cloud**, desde donde los widgets muestran los datos.

.. code-block:: arduino

    void myTimerEvent()
    {
        bool chk = readDHT();
        int light = readLight();
        int moisture = readMoisture();
        if(chk){
            Blynk.virtualWrite(V4,humidity);
            Blynk.virtualWrite(V5,temperature);
        }
        Blynk.virtualWrite(V6,light);
        Blynk.virtualWrite(V7,moisture);
    }
