.. _iot_blink:

2. Obtener Datos de Blynk
=================================

En este capítulo, aprenderás cómo controlar el circuito con Blynk. ¡Vamos a encender los LED a través de Internet!

**Componentes Necesarios**

Para este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí tienes el enlace:

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
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

**1. Construir el Circuito**

.. note::

    El módulo ESP8266 requiere una alta corriente para proporcionar un entorno operativo estable, así que asegúrate de que la batería de 9V esté conectada.

.. image:: img/wiring_led.jpg

**2. Editar el Tablero de Mandos**

1. Ve al **Quickstart Device** que creaste anteriormente, haz clic en el icono del menú en la esquina superior derecha y selecciona **edit dashboard**.

    .. image:: img/sp220609_112825.png

2. Los Datastreams permiten que los widgets en Blynk y el código en la placa R3 se reconozcan entre sí. Para experimentar el proceso de configuración completo, elimina todos los Datastreams de la página de Datastreams.

    .. image:: img/sp220609_114723.png

3. Por favor, lee la advertencia cuidadosamente y confirma que es correcta antes de eliminar los Datastreams.

    .. image:: img/sp220609_114929.png

4. Crea un Datastream de tipo **Virtual Pin**, que se usará para controlar el LED usando el interruptor de Blynk.

    .. image:: img/sp220609_115124.png

5. Configura el **Virtual Pin**. Como el botón y el LED solo necesitan estar ENCENDIDO y APAGADO, establece TIPO DE DATOS en ``Integer`` y MIN y MAX en ``0`` y ``1``.

    .. image:: img/sp220609_115520.png

6. Ve a la página **Web Dashboard** y elimina los widgets existentes.

    .. image:: img/sp220609_133707.png

7. Arrastra y suelta un widget **switch** desde el **Widget Box** a la izquierda.

    .. image:: img/sp220609_114508.png

8. Ahora para configurarlo.

    .. image:: img/sp20220615180127.png

9. Selecciona **Datastream** como el que configuraste anteriormente.

    .. image:: img/sp220609_133741.png

10. Después de seleccionar Datastream, verás algunas configuraciones personalizadas, luego presiona Guardar.

    .. image:: img/sp220609_133950.png

11. Finalmente, haz clic en **Save And Apply**.

    .. image:: img/sp220609_141733.png

**3. Ejecutar el Código**

1. Abre el archivo ``2.get_data_from_blynk.ino`` en la ruta ``3in1-kit\iot_project\2.get_data_from_blynk``, o copia este código en el **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b187a8-dabf-4866-b38c-742e0446cc3f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

2. Reemplaza el ``Template ID``, ``Device Name`` y ``Auth Token`` con los tuyos. También necesitas introducir el ``ssid`` y ``password`` del WiFi que estás utilizando. Para tutoriales detallados, consulta :ref:`connect_blynk`.

3. Después de seleccionar la placa y puerto correctos, haz clic en el botón **Upoad**.

    .. image:: img/2_upload.png

4. Abre el monitor serial(configura la tasa de baudios a 115200) y espera a que aparezca un aviso como una conexión exitosa.

    .. image:: img/2_ready.png

    .. note::

        Si aparece el mensaje ``ESP is not responding`` al conectar, sigue estos pasos.

        * Asegúrate de que la batería de 9V esté conectada.
        * Reinicia el módulo ESP8266 conectando el pin RST a GND durante 1 segundo, luego desconéctalo.
        * Presiona el botón de reinicio en la placa R3.

        A veces, puede ser necesario repetir la operación anterior 3-5 veces, por favor sé paciente.

5. De vuelta en Blynk, puedes ver que el estado ha cambiado a en línea y ahora puedes usar el widget de interruptor en Blynk para controlar el LED conectado a la placa R3.

    .. image:: img/2_blynk_button.png

6. Si quieres usar Blynk en dispositivos móviles, consulta :ref:`blynk_mobile`.


**¿Cómo funciona?**

La diferencia entre el código de este proyecto y el código del capítulo anterior :ref:`connect_blynk` son las siguientes líneas.


.. code-block:: arduino

    const int ledPin=6;

    BLYNK_WRITE(V0)
    {
        int pinValue = param.asInt(); // assigning incoming value from pin V0 to a variable
        // You can also use:
        // String i = param.asStr();
        // double d = param.asDouble();
        digitalWrite(ledPin,pinValue);
    }

    void setup()
    {
        pinMode(ledPin,OUTPUT);
    }


Respecto al ``pinMode`` y ``digitalWrite`` del ledPin, estoy seguro de que ya estás familiarizado con ellos, así que no los repasaré de nuevo. En lo que necesitas enfocarte es en la función ``BLYNK_WRITE(V0)``.

Lo que hará es que cuando el valor de ``V0`` en Blynk cambie, Blynk.Cloud le dirá a tu dispositivo "Estoy escribiendo en el **Virtual Pin** V0", y tu dispositivo podrá realizar algo una vez que reciba esta información.

Creamos el Datastream V0 en el paso anterior y lo aplicamos al Widget Switch.
Esto significa que cada vez que operemos el Widget Switch, se activará ``BLYNK_WRITE(V0)``.

Escribimos dos instrucciones en esta función.

.. code-block:: arduino

    int pinValue = param.asInt();

Obtener el valor de V0 y asignarlo a la variable ``pinValue``.

.. code-block:: arduino

    digitalWrite(ledPin,pinValue);

Escribe el valor de V0 obtenido en el ledPin, para que el widget Switch en Blynk pueda controlar el LED.


