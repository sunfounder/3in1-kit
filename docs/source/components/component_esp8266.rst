.. _cpn_esp8266:

Módulo ESP8266
=================

.. image:: img/esp8266.jpg
    :align: center

El ESP8266 es un microchip Wi-Fi de bajo costo, 
con software de red TCP/IP integrado, 
y capacidad de microcontrolador, producido por Espressif Systems en Shanghái, China.

El chip llamó la atención de los creadores occidentales en agosto de 2014 con el módulo ESP-01, 
hecho por el fabricante de terceros Ai-Thinker. 
Este pequeño módulo permite a los microcontroladores conectarse a una red Wi-Fi y realizar conexiones TCP/IP simples usando comandos al estilo Hayes. 
Sin embargo, al principio, había muy poca documentación en inglés sobre el chip y los comandos que aceptaba. 
El precio muy bajo y el hecho de que había muy pocos componentes externos en el módulo, 
lo que sugería que eventualmente podría ser muy económico en volumen, 
atrajo a muchos hackers para explorar el módulo, 
el chip y el software en él, así como para traducir la documentación china.

Pines del ESP8266 y sus funciones:

.. image:: img/ESP8266_pinout.png


.. list-table:: Pines de ESP8266-01
   :widths: 25 25 100
   :header-rows: 1

   * - Pin	
     - Nombre	
     - Descripción
   * - 1	
     - TXD	
     - UART_TXD, transmisión; Entrada/Salida de Propósito General: GPIO1; No se permite la conexión a tierra durante el inicio.
   * - 2	
     - GND
     - GND
   * - 3	
     - CU_PD	
     - Funciona a nivel alto; Se apaga cuando se suministra un nivel bajo.
   * - 4		
     - GPIO2
     - Debe ser de nivel alto al encenderse, no se permite conexión a tierra por hardware; Conexión a tierra por defecto;
   * - 5	
     - RST	
     - Señal de Reinicio Externo, reinicia cuando se suministra un nivel bajo; funciona cuando se suministra un nivel alto (nivel alto por defecto);
   * - 6	
     - GPIO0	
     - Indicador de Estado de WiFi; Selección del modo de operación: Conexión a tierra: Arranque Flash, modo de operación; Sin conexión a tierra: Descarga UART, modo de descarga.
   * - 7	
     - VCC	
     - Suministro de Energía(3.3V)
   * - 8	
     - RXD	
     - UART_RXD, recepción; Entrada/Salida de Propósito General: GPIO3;


* `ESP8266 - Espressif <https://www.espressif.com/en/products/socs/esp8266>`_
* `Conjunto de Instrucciones AT de ESP8266 <https://github.com/sunfounder/3in1-kit/blob/main/iot_project/esp8266_at_instruction_set_en.pdf>`_

Adaptador ESP8266
--------------------

.. image:: img/esp8266_adapter.png
    :width: 300
    :align: center

El adaptador ESP8266 es una placa de expansión que permite utilizar el módulo ESP8266 en un protoboard.

Coincide perfectamente con los pines del propio ESP8266, y también agrega un pin de 5V para recibir el voltaje de la placa Arduino. El chip AMS1117 integrado se utiliza para alimentar el módulo ESP8266 después de reducir el voltaje a 3.3V.

El diagrama esquemático es el siguiente:

.. image:: img/sch_esp8266adapter.png


**Ejemplo**

* :ref:`iot_projects` (Proyecto IoT)
