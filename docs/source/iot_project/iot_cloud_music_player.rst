.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _iot_music:

4. Reproductor de Música en la Nube
=====================================

El objetivo de este proyecto es crear un reproductor de música usando Blynk.
La música se reproduce de la misma manera que en :ref:`ar_passive_buzzer`, escribiendo la canción en el programa y reproduciéndola con un zumbador pasivo.
Sin embargo, en este ejemplo, podemos hacer clic en el interruptor para reproducir/pausar y deslizar el deslizador para cambiar el progreso de reproducción.

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
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|

**1. Construir el Circuito**

.. note::

    El módulo ESP8266 requiere una alta corriente para proporcionar un entorno operativo estable, así que asegúrate de que la batería de 9V esté conectada.

.. image:: img/wiring_buzzer.jpg

**2. Editar el Tablero de Mandos**

#. Crea un **Datastream** de tipo **Virtual Pin** en la página **Datastream** como el valor modificado por el widget deslizador añadido más tarde o por código. Establece el TIPO DE DATOS en **Integer** y MIN y MAX en **0** y **30**.

    .. image:: img/sp220610_104330.png

#. También crea otro **Datastream** de tipo **Virtual Pin** para mostrar el nombre de la música, y establece el TIPO DE DATOS en ``String``.

    .. image:: img/sp220610_105932.png

#. Ve a la página **Wed Dashboard**, arrastra un widget **Switch** y establece **Datastream** en V0 (V0 ya está configurado en :ref:`iot_blink`); arrastra un widget **Label** y configúralo en V3; arrastra un widget **Slider** y configúralo en V2.

    .. image:: img/blynk_music_cloud.png

.. note::

    Tus pines virtuales pueden ser diferentes a los míos, los tuyos prevalecerán, pero necesitarás modificar el número de pin correspondiente en el código.



**3. Ejecutar el Código**

#. Abre el archivo ``4.cloud_music_player.ino`` en la ruta ``3in1-kit\iot_project\4.cloud_music_player``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/34a49c4b-9eb4-4d03-bd78-fe1daefc9f5c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Reemplaza el ``Template ID``, ``Device Name`` y ``Auth Token`` con los tuyos. También necesitas introducir el ``ssid`` y ``password`` del WiFi que estás utilizando. Para tutoriales detallados, consulta :ref:`connect_blynk`.
#. Después de seleccionar la placa y puerto correctos, haz clic en el botón **Upoad**.

#. Abre el monitor serial(configura la tasa de baudios a 115200) y espera a que aparezca un aviso como una conexión exitosa.

    .. image:: img/2_ready.png

    .. note::

        Si aparece el mensaje ``ESP is not responding`` al conectar, sigue estos pasos.

        * Asegúrate de que la batería de 9V esté conectada.
        * Reinicia el módulo ESP8266 conectando el pin RST a GND durante 1 segundo, luego desconéctalo.
        * Presiona el botón de reinicio en la placa R3.

        A veces, puede ser necesario repetir la operación anterior 3-5 veces, por favor sé paciente.

#. Ahora, puedes usar el widget de Control de Botón de Blynk para iniciar/pausar la música y el Deslizador para ajustar el progreso de reproducción, y también verás el nombre de la música.

    .. image:: img/blynk_music_cloud.png

#. Si quieres usar Blynk en dispositivos móviles, consulta :ref:`blynk_mobile`.


**¿Cómo funciona?**

El datastream **V0** se utiliza para obtener el estado del widget Interruptor y asignarlo a la variable **musicPlayFlag**, que controla la pausa y reproducción de la música.

.. code-block:: arduino

    int musicPlayFlag=0;

    BLYNK_WRITE(V0)
    {
        musicPlayFlag = param.asInt(); // START/PAUSE MUSIC
    }

El datastream **V2** se utiliza para obtener el valor del widget deslizador y asignarlo a la variable **scrubBar** cuando se mueve el deslizador.

.. code-block:: arduino

    int scrubBar=0;

    BLYNK_WRITE(V2)
    {
        scrubBar=param.asInt();
    }

Cuando el dispositivo está conectado al **Blynk Cloud**, escribe el nombre de la música para el datastream **V3** y luego muéstralo con el widget **Label**.

.. code-block:: arduino

    BLYNK_CONNECTED() {
        String songName = "Ode to Joy";
        Blynk.virtualWrite(V3, songName);
    }

El **Blynk Timer** se ejecutará cada segundo. La música se reproduce si **musicPlayFlag** no es 0, es decir, si el widget **Switch** está activado.
Tan pronto como se toquen dos notas, la variable de la barra de progreso ``scrubBar`` se incrementa en 2, y el valor se escribe luego en el **Blynk Cloud**, lo que sincroniza el valor del widget **Slider**.

.. code-block:: arduino

    void myTimerEvent()
    {
        if(musicPlayFlag!=0)
        {
            tone(buzzerPin,melody[scrubBar],250);
            scrubBar=(scrubBar+1)%(sizeof(melody)/sizeof(int));
            delay(500);
            tone(buzzerPin,melody[scrubBar],250);
            scrubBar=(scrubBar+1)%(sizeof(melody)/sizeof(int));
            Serial.println(scrubBar);    
            Blynk.virtualWrite(V2, scrubBar);
        }
    }