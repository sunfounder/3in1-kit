.. _connect_blynk:

1.4 Conectando la placa R3 a Blynk
--------------------------------------

1. Reconecta el módulo ESP8266 y la placa R3, aquí se usa el serial de software, por lo que TX y RX se conectan a los pines 2 y 3 de la placa R3 respectivamente.

    .. note::

        El módulo ESP8266 requiere una corriente alta para proporcionar un entorno operativo estable, así que asegúrate de que la batería de 9V esté conectada.

    .. image:: img/wiring_23.jpg

2. Abre el archivo ``1.connect.ino`` en la ruta ``3in1-kit\iot_project\1.connect``. O copia este código en el **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/1c0c1a8f-2551-484f-9f4f-d5d4117cc864/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

3. Reemplaza las siguientes tres líneas de código que puedes copiar de la página **Device info** de tu cuenta. Estas tres líneas de código permitirán que tu placa R3 encuentre tu cuenta de Blynk.

    .. code-block:: arduino

        #define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
        #define BLYNK_DEVICE_NAME "Device"
        #define BLYNK_AUTH_TOKEN "YourAuthToken"
    
    .. image:: img/sp20220614174721.png

4. Rellena el ``ssid`` y ``password`` del WiFi que estás utilizando.

    .. code-block:: arduino

        char ssid[] = "ssid";
        char pass[] = "password";

5. Sube el código a la placa R3, luego abre el monitor serial y configura la tasa de baudios a 115200. Cuando la placa R3 se comunique exitosamente con Blynk, el monitor serial mostrará el carácter ``ready``.

    .. image:: img/sp220607_170223.png

    .. note::
    
        Si aparece el mensaje ``ESP is not responding`` al conectar, sigue estos pasos.

        * Asegúrate de que la batería de 9V esté conectada.
        * Reinicia el módulo ESP8266 conectando el pin RST a GND durante 1 segundo, luego desconéctalo.
        * Presiona el botón de reinicio en la placa R3.

        A veces, puede ser necesario repetir la operación anterior 3-5 veces, por favor sé paciente.

6. El estado de Blynk cambiará de **offline** a **online**.

    .. image:: img/sp220607_170326.png

