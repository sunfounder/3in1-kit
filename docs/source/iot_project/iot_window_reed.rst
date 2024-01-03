.. _iot_window:

3. Enviar Datos a Blynk
=============================

Este capítulo te mostrará cómo enviar datos a Blynk.

Aquí creamos un dispositivo de detección de puertas y ventanas. El circuito con el interruptor de lengüeta se coloca al lado de la puerta y la ventana, y el imán se monta en el borde de la puerta y la ventana.
Cuando la puerta o ventana está cerrada, el Interruptor de Lengüeta se activará por la fuerza magnética y el valor del pin correspondiente en la placa R3 cambiará.
Blynk.cloud recibirá este valor para que puedas ver si las puertas y ventanas de tu casa están cerradas incluso cuando estés lejos de casa.

Ahora usaremos un widget LED en Blynk para indicar si tus ventanas y puertas están cerradas (es decir, si el Interruptor de Lengüeta está encendido o apagado).

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
    *   - :ref:`cpn_reed`
        - \-

**1. Construir el Circuito**

.. note::

    El módulo ESP8266 requiere una alta corriente para proporcionar un entorno operativo estable, así que asegúrate de que la batería de 9V esté conectada.

.. image:: img/wiring_reed.jpg

**2. Editar el Tablero de Mandos**

1. Crea un **Datastream** de tipo **Virtual Pin** en la página **Datastream** para obtener el valor del Interruptor de Lengüeta. Establece el TIPO DE DATOS en **Integer** y MIN y MAX en **0** y **1**.

    .. image:: img/sp220609_162548.png

2. Arrastra y suelta un widget **LED widget** en la página **Web Dashboard**, con un valor de 1, se iluminará (con color), de lo contrario será blanco.

    .. image:: img/sp220609_163350.png

3. En la página de configuración del widget **LED widget**, selecciona **Datastream** como **Reed(V1)**, y guárdalo.

    .. image:: img/sp220609_163502.png

**3. Ejecutar el Código**

1. Abre el archivo ``3.push_data_to_blynk.ino`` en la ruta ``3in1-kit\iot_project\3.push_data_to_blynk``, o copia este código en el **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/e81b0024-c11e-4507-8d43-aeb3b6656c2c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

2. Reemplaza el ``Template ID``, ``Device Name`` y ``Auth Token`` con los tuyos. También necesitas introducir el ``ssid`` y ``password`` del WiFi que estás utilizando. Para tutoriales detallados, consulta :ref:`connect_blynk`.
3. Después de seleccionar la placa y puerto correctos, haz clic en el botón **Upload**.

4. Abre el monitor serial(configura la tasa de baudios a 115200) y espera a que aparezca un aviso como una conexión exitosa.

    .. image:: img/2_ready.png

    .. note::

        Si aparece el mensaje ``ESP is not responding`` al conectar, sigue estos pasos.

        * Asegúrate de que la batería de 9V esté conectada.
        * Reinicia el módulo ESP8266 conectando el pin RST a GND durante 1 segundo, luego desconéctalo.
        * Presiona el botón de reinicio en la placa R3.

        A veces, puede ser necesario repetir la operación anterior 3-5 veces, por favor sé paciente.

5. Ahora, Blynk mostrará el estado de tus puertas y ventanas. Si tus puertas y ventanas están cerradas, el widget LED será verde, de lo contrario, será gris.

6. Si quieres usar Blynk en dispositivos móviles, consulta :ref:`blynk_mobile`.



**¿Cómo funciona?**

Para este ejemplo, debes enfocarte en las siguientes líneas. "Escribir datos cada segundo al Datastream V1 de Blynk Cloud" se define con estas líneas.

.. code-block:: arduino

    BlynkTimer timer;

    void myTimerEvent()
    {
        Blynk.virtualWrite(V1, pinValue);
    }

    void setup()
    {
        timer.setInterval(1000L, myTimerEvent);
    }

    void loop()
    {
        timer.run(); // Initiates BlynkTimer
    }

La biblioteca Blynk proporciona un temporizador integrado, primero creamos un objeto temporizador.

.. code-block:: arduino

    BlynkTimer timer;

Establece el intervalo del temporizador en ``setup()``, aquí configuramos para ejecutar la función ``myTimerEvent()`` cada 1000ms.

.. code-block:: arduino

    timer.setInterval(1000L, myTimerEvent);


Ejecuta BlynkTimer en ``loop()``.

.. code-block:: arduino

    timer.run();

Edita la función personalizada ``myTimerEvent()``, el código ``Blynk.virtualWrite(V1, pinValue)`` se utiliza para escribir el valor de los datos pinValue para V1.

.. code-block:: arduino

    void myTimerEvent()
    {
        Blynk.virtualWrite(V1, pinValue);
    }

