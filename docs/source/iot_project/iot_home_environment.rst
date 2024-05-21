.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _iot_home:

5. Monitoreo del Ambiente Doméstico
====================================

En este capítulo, utilizaremos Blynk para crear un monitor de ambiente doméstico.
Puedes medir la temperatura, humedad e intensidad lumínica de una habitación usando el DHT11 y un fotoresistor.
Al enviar estos valores a Blynk, podrás conocer el estado del ambiente de tu hogar a través de internet.

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

**1. Construir el Circuito**

.. note::

    El módulo ESP8266 requiere una alta corriente para proporcionar un entorno operativo estable, así que asegúrate de que la batería de 9V esté conectada.

.. image:: img/wiring_dht11.jpg

**2. Editar el Tablero de Mandos**


#. Para registrar valores de humedad, crea un **Datastream** de tipo **Virtual Pin** en la página de **Datastream**. Configura el TIPO DE DATO a **Double** y el MIN y MAX a **0** y **100**. También establece las unidades a **Percentage, %**.

    .. image:: img/sp220610_145748.png

#. Luego crea un **Datastream** de tipo **Virtual Pin** para registrar la temperatura. Configura el TIPO DE DATO a ``Double``, MIN y MAX a ``-30`` y ``50``, y las unidades a **Celsius, °C**.

    .. image:: img/sp220610_145811.png

#. También crea un **Datastream** de tipo **Virtual Pin** para registrar la intensidad lumínica. Utiliza el tipo de dato predeterminado - **Integer**, con MIN y MAX configurados a ``0`` y ``1024``.

    .. image:: img/sp220610_145834.png

#. Ve a la página de **Wed Dashboard**, arrastra dos widgets **Label** y configura sus flujos de datos a **V4** y **V5** respectivamente, y arrastra un widget **Gauge** y configura el flujo de datos a **V6**. También en la configuración del widget, puedes activar **Cambiar color según el valor** y seleccionar el color apropiado para que el widget se vea mejor y más intuitivo.

.. image:: img/sp220610_150400.png
    :align: center

**3. Ejecutar el Código**

#. Abre el archivo ``5.home_environment_monitoring.ino`` en la ruta ``3in1-kit\iot_project\5.home_environment_monitoring``, o copia este código en **Arduino IDE**.

    .. note::

        * Aquí se utiliza la ``DHT sensor library``, puedes instalarla desde el **Library Manager**.

            .. image:: ../img/lib_dht11.png

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/4f0ad85e-8aff-4df9-99dd-c6741aed8219/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Sustituye el ``Template ID``, ``Device Name`` y ``Auth Token`` por los tuyos. También necesitas ingresar el ``ssid`` y la ``password`` del WiFi que estás utilizando. Para tutoriales detallados, por favor consulta :ref:`connect_blynk`.
#. Tras seleccionar la placa y puerto correctos, haz clic en el botón **Upoad**.

#. Abre el monitor Serial(configura la tasa de baudios a 115200) y espera a que aparezca un aviso como una conexión exitosa.

    .. image:: img/2_ready.png

    .. note::

        Si aparece el mensaje ``ESP is not responding`` al conectar, sigue estos pasos.

        * Asegúrate de que la batería de 9V esté conectada.
        * Restablece el módulo ESP8266 conectando el pin RST a GND durante 1 segundo, luego desenchúfalo.
        * Presiona el botón de reset en la placa R3.

        A veces, puede ser necesario repetir la operación anterior de 3 a 5 veces, por favor ten paciencia.

#. Ahora, verás la temperatura ambiental actual, la humedad y la intensidad de luz en Blynk.

    .. image:: img/sp220610_150400.png
        :align: center

#. Si quieres usar Blynk en dispositivos móviles, consulta :ref:`blynk_mobile`.

    .. image:: img/mobile_home.jpg

**¿Cómo funciona?**

Estas dos funciones se utilizan para obtener la temperatura, humedad e intensidad lumínica de la habitación.


.. code-block:: arduino

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

Con el ``Timer`` de Blynk, la temperatura ambiente, humedad e intensidad de luz se obtienen cada segundo y se envían al flujo de datos en Blynk Cloud, desde donde los widgets muestran los datos.

.. code-block:: arduino

    void myTimerEvent()
    {
        bool chk = readDHT();
        int light = readLight();
        if(chk){
            Blynk.virtualWrite(V4,humidity);
            Blynk.virtualWrite(V5,temperature);
        }
        Blynk.virtualWrite(V6,light);
    }