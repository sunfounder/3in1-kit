.. _burn_firmware:

¿Cómo volver a grabar el firmware para el módulo ESP8266?
============================================================


Volver a grabar el Firmware con R3
---------------------------------------

**1. Construye el circuito**

Conecta el ESP8266 y la placa SunFounder R3.

    .. image:: img/connect_esp8266.png
        :width: 800

**2. Quemar el firmware**

* Sigue los pasos a continuación para quemar el firmware si estás utilizando **Windows**.

    #. Descarga el firmware y la herramienta de grabación.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Después de descomprimir, verás 4 archivos.

        .. .. image:: img/bat_firmware.png
    
        * ``BAT_AT_V1.7.1.0_1M.bin``: El firmware para grabar en el módulo ESP8266.
        * ``esptool.exe``: Esta es una utilidad de línea de comandos para Windows.
        * ``install_r3.bat``: Este es el paquete de comandos para el sistema Windows, hacer doble clic en este archivo ejecutará todos los comandos dentro del archivo.
        * ``install_r4.bat``: Igual que ``install_r3.bat``, pero dedicado a la placa UNO R4.

    #. Haz doble clic en ``install_r3.bat`` para comenzar la grabación del firmware. Si ves el siguiente aviso, el firmware se ha instalado con éxito.

        .. image:: img/install_firmware.png

        .. note::
            Si la grabación falla, por favor revisa los siguientes puntos.

            * Resetea el módulo ESP8266 insertando el RST en el Adaptador ESP8266 a GND y luego desenchufándolo.
            * Verifica si el cableado es correcto.
            * Si el ordenador ha reconocido correctamente tu placa, y asegúrate de que el puerto no esté ocupado.
            * Reabre el archivo install.bat.

* Para quemar el firmware, sigue estos pasos si estás utilizando un sistema **Mac OS**.

    #. Utiliza los siguientes comandos para instalar Esptool. Esptool es una utilidad basada en Python, de código abierto e independiente de la plataforma, para comunicarse con el bootloader ROM en los chips de Espressif.

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. Si esptool se ha instalado correctamente, mostrará un mensaje como [usage: esptool] si ejecutas ``python3 -m esptool``.

    #. Descarga el firmware.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Después de descomprimir, verás 3 archivos.

        .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: El firmware para grabar en el módulo ESP8266.
        * ``esptool.exe``: Esta es una utilidad de línea de comandos para Windows.
        * ``install_r3.bat``: Este es el paquete de comandos para el sistema Windows.
        * ``install_r4.bat``: Igual que ``install_r3.bat``, pero dedicado a la placa UNO R4.


    #. Abre una terminal y usa el comando ``cd`` para ir a la carpeta de firmware que acabas de descargar, luego ejecuta el siguiente comando para borrar el firmware existente y volver a grabar el nuevo firmware.

        .. code-block::

            python3 -m esptool --chip esp8266 --before default_reset erase_flash
            python3 -m esptool --chip esp8266 --before default_reset write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. Si ves el siguiente aviso, el firmware se ha instalado con éxito.

        .. image:: img/install_firmware_macos.png

        .. note::
            Si la grabación falla, por favor revisa los siguientes puntos.

            * Resetea el módulo ESP8266 insertando el RST en el Adaptador ESP8266 a GND y luego desenchufándolo.
            * Verifica si el cableado es correcto.
            * Si el ordenador ha reconocido correctamente tu placa, y asegúrate de que el puerto no esté ocupado.
            * Reabre el archivo install.bat.

**3. Prueba**

#. Sobre la base del cableado original, conecta IO1 a 3V3.

    .. image:: img/connect_esp826612.png
        :width: 800

#. Podrás ver información sobre el módulo ESP8266 si haces clic en el icono de la lupa (Monitor Serie) en la esquina superior derecha y configuras la tasa de baudios a **115200**.

    .. image:: img/sp20220524113020.png

    .. note::

        * Si no aparece ``ready``, puedes intentar reiniciar el módulo ESP8266 (conectar RST a GND) y volver a abrir el Monitor Serie.

#. Haz clic en **CAJA DESPLEGABLE DE NUEVA LÍNEA**, selecciona ``both NL & CR`` en la opción desplegable, introduce ``AT``, si devuelve OK, significa que ESP8266 ha establecido conexión con éxito con la placa R3.

    .. image:: img/sp20220524113702.png

Ahora puedes continuar siguiendo :ref:`config_esp8266` para configurar el modo de trabajo y la tasa de baudios del módulo ESP8266.



Volver a Grabar el Firmware con R4
---------------------------------------



**1. Construye el circuito**

Conecta el ESP8266 y la placa Arduino UNO R4.

    .. image:: img/faq_at_burn_bb.jpg
        :width: 800

**2. Sube el siguiente código a R4**

.. code-block:: Arduino

    void setup() {
        Serial.begin(115200);
        Serial1.begin(115200);
    }

    void loop() {
        if (Serial.available()) {      // If anything comes in Serial (USB),
            Serial1.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
        }
            if (Serial1.available()) {     // If anything comes in Serial1 (pins 0 & 1)
            Serial.write(Serial1.read());   // read it and send it out Serial (USB)
        }
    }

**3. Quemando el firmware**

* Sigue los pasos a continuación para grabar el firmware si estás utilizando **Windows**.

    #. Descarga el firmware y la herramienta de grabación.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Después de descomprimir, verás 4 archivos.

        .. .. image:: img/bat_firmware.png
    
        * ``BAT_AT_V1.7.1.0_1M.bin``: El firmware para grabar en el módulo ESP8266.
        * ``esptool.exe``: Esta es una utilidad de línea de comandos para Windows.
        * ``install_r3.bat``: Este es el paquete de comandos para el sistema Windows, hacer doble clic en este archivo ejecutará todos los comandos dentro del archivo.
        * ``install_r4.bat``: Igual que ``install_r3.bat``, pero dedicado a la placa UNO R4.

    #. Haz doble clic en ``install_r4.bat`` para empezar la grabación del firmware. Si ves el siguiente aviso, el firmware se ha instalado con éxito.

        .. image:: img/install_firmware.png

        .. note::
            Si la grabación falla, por favor revisa los siguientes puntos.

            * Resetea el módulo ESP8266 insertando el RST en el Adaptador ESP8266 a GND y luego desenchufándolo.
            * Verifica si el cableado es correcto.
            * Si el ordenador ha reconocido correctamente tu placa, y asegúrate de que el puerto no esté ocupado.
            * Vuelve a abrir el archivo install.bat.

* Para grabar el firmware, sigue estos pasos si estás utilizando un sistema **Mac OS**.

    #. Utiliza los siguientes comandos para instalar Esptool. Esptool es una utilidad basada en Python, de código abierto e independiente de la plataforma, para comunicarse con el bootloader ROM en los chips de Espressif.

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. Si esptool se ha instalado correctamente, mostrará un mensaje como [usage: esptool] si ejecutas ``python3 -m esptool``.

    #. Descarga el firmware.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Después de descomprimir, verás 4 archivos.

        .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: El firmware para grabar en el módulo ESP8266.
        * ``esptool.exe``: Esta es una utilidad de línea de comandos para Windows.
        * ``install_r3.bat``: Este es el paquete de comandos para el sistema Windows.
        * ``install_r4.bat``: Igual que ``install_r3.bat``, pero dedicado a la placa UNO R4.


    #. Abre una terminal y usa el comando ``cd`` para entrar en la carpeta del firmware que acabas de descargar, luego ejecuta el siguiente comando para borrar el firmware existente y volver a grabar el nuevo firmware.

        .. code-block::

            python3 -m esptool --chip esp8266 --before no_reset_no_sync erase_flash
            python3 -m esptool --chip esp8266 --before no_reset_no_sync write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. Si ves el siguiente aviso, el firmware se ha instalado con éxito.

        .. image:: img/install_firmware_macos.png

        .. note::
            Si la grabación falla, por favor revisa los siguientes puntos.

            * Resetea el módulo ESP8266 insertando el RST en el Adaptador ESP8266 a GND y luego desenchufándolo.
            * Verifica si el cableado es correcto.
            * Si el ordenador ha reconocido correctamente tu placa, y asegúrate de que el puerto no esté ocupado.
            * Vuelve a abrir el archivo install.bat.

**4. Prueba**

#. Sobre la base del cableado original, conecta IO1 a 3V3.

    .. image:: img/faq_at_burn_check_bb.jpg
        :width: 800

#. Podrás ver información sobre el módulo ESP8266 si haces clic en el icono de la lupa (Monitor Serie) en la esquina superior derecha y configuras la tasa de baudios a **115200**.

    .. image:: img/sp20220524113020.png

    .. note::

        * Si no aparece ``ready``, puedes intentar reiniciar el módulo ESP8266 (conectar RST a GND) y volver a abrir el Monitor Serie.

#. Haz clic en **CAJA DESPLEGABLE DE NUEVA LÍNEA**, selecciona ``both NL & CR`` en la opción desplegable, introduce ``AT``, si devuelve OK, significa que ESP8266 ha establecido conexión con éxito con tu placa.

    .. image:: img/sp20220524113702.png

Ahora puedes continuar siguiendo :ref:`config_esp8266` para configurar el modo de trabajo y la tasa de baudios del módulo ESP8266.



