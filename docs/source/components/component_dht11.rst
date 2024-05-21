.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_dht11:

Sensor de Humedad y Temperatura DHT11
===========================================

El sensor digital de temperatura y humedad DHT11 es un sensor compuesto que contiene una salida de señal digital calibrada de temperatura y humedad. 
La tecnología de módulos digitales dedicados de recolección y la tecnología de detección de temperatura y humedad se aplican para asegurar que el producto tenga alta fiabilidad y excelente estabilidad a largo plazo.

El sensor incluye un componente de detección húmeda resistivo y un dispositivo de medición de temperatura NTC, y está conectado con un microcontrolador de 8 bits de alto rendimiento.

Solo tres pines están disponibles para su uso: VCC, GND y DATA. 
El proceso de comunicación comienza con la línea DATA enviando señales de inicio a DHT11, y DHT11 recibe las señales y devuelve una señal de respuesta. 
Luego, el host recibe la señal de respuesta y comienza a recibir 40 bits de datos de humedad y temperatura (8 bits de humedad entera + 8 bits de humedad decimal + 8 bits de temperatura entera + 8 bits de temperatura decimal + 8 bits de verificación).

.. image:: img/dht11.png

**Características**

    #. Rango de medición de humedad: 20 - 90%RH
    #. Rango de medición de temperatura: 0 - 60℃
    #. Señales digitales de salida que indican temperatura y humedad
    #. Voltaje de trabajo: DC 5V; Tamaño del PCB: 2.0 x 2.0 cm
    #. Precisión de medición de humedad: ±5%RH
    #. Precisión de medición de temperatura: ±2℃


* `Hoja de Datos DHT11 <http://wiki.sunfounder.cc/images/c/c7/DHT11_datasheet.pdf>`_

**Ejemplo**

* :ref:`ar_dht11` (Proyecto Básico)
* :ref:`iot_home` (Proyecto IoT)
* :ref:`iot_plant` (Proyecto IoT)

