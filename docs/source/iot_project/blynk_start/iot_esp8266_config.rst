.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _config_esp8266:

1.1 Configuración del ESP8266
===============================

El módulo ESP8266 que viene con el kit ya está pregrabado con firmware AT, pero aún necesitas modificar su configuración siguiendo los pasos a continuación.

1. Construye el circuito.

    .. image:: img/iot_1_at_set_bb.jpg
        :width: 800

2. Abre el archivo ``1.set_software_serial.ino`` en la ruta ``3in1-kit\iot_project\1.set_software_serial``. O copia este código en el **Arduino IDE**.

    .. code-block:: Arduino

        #include <SoftwareSerial.h>
        SoftwareSerial espSerial(2, 3); //Rx,Tx

        void setup() {
            // put your setup code here, to run once:
            Serial.begin(115200);
            espSerial.begin(115200);
        }

        void loop() {
            if (espSerial.available()) {
                Serial.write(espSerial.read());
            }
            if (Serial.available()) {
                espSerial.write(Serial.read());
            }
        }

3. Haz clic en el icono de lupa (Monitor Serial) en la esquina superior derecha y configura la tasa de baudios a **115200**. (Puede que tengas alguna información impresa como yo, o tal vez no, no importa, solo ve al siguiente paso.)

    .. image:: img/sp20220524113020.png

    .. warning::
        
        * Si no aparece ``ready``, puedes intentar reiniciar el módulo ESP8266(conectar RST a GND) y reabrir el Monitor Serial.

        * Además, si el resultado es ``OK``, puede que necesites volver a grabar el firmware, consulta :ref:`burn_firmware` para más detalles. Si aún no puedes resolverlo, por favor toma una captura de pantalla del monitor serial y envíala a sevice@sunfounder.com, te ayudaremos a resolver el problema lo antes posible.

4. Haz clic en **CUADRO DESPLEGABLE DE NUEVA LÍNEA**, selecciona ``both NL & CR`` en la opción desplegable, ingresa ``AT``, si retorna OK, significa que ESP8266 ha establecido conexión exitosamente con la placa R3.

    .. image:: img/sp20220524113702.png

5. Introduce ``AT+CWMODE=3`` y el modo gestionado cambiará a coexistencia de **Estación y AP**.

    .. image:: img/sp20220524114032.png

6. Para usar el serial de software más adelante, debes introducir ``AT+UART=9600,8,1,0,0`` para modificar la tasa de baudios del ESP8266 a 9600.

    .. image:: img/PIC4_sp220615_150321.png

.. 7. Ahora cambia la tasa de baudios del monitor serial a 9600, intenta introducir ``AT``, si retorna OK, significa que la configuración es exitosa.

..     .. image:: img/PIC5_sp220615_150431.png
