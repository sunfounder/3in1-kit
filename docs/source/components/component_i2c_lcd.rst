.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_i2c_lcd1602:

I2C LCD1602
==============

.. image:: img/i2c_lcd1602.png
    :width: 800

* **GND**: Tierra
* **VCC**: Suministro de voltaje, 5V.
* **SDA**: Línea de datos serie. Conectar a VCC a través de una resistencia de pull-up.
* **SCL**: Línea de reloj serie. Conectar a VCC a través de una resistencia de pull-up.

Como todos sabemos, aunque los LCD y otros displays enriquecen enormemente la interacción hombre-máquina, comparten una debilidad común. Cuando se conectan a un controlador, ocupan múltiples E/S del controlador que no tiene tantos puertos externos. También restringe otras funciones del controlador.

Por lo tanto, se ha desarrollado el LCD1602 con un módulo I2C para resolver el problema. El módulo I2C tiene un chip PCF8574 I2C incorporado que convierte los datos seriales I2C en datos paralelos para la pantalla LCD.

* `Hoja de Datos del PCF8574 <https://www.ti.com/lit/ds/symlink/pcf8574.pdf?ts=1627006546204&ref_url=https%253A%252F%252Fwww.google.com%252F>`_

**Dirección I2C**

La dirección predeterminada es básicamente 0x27, en algunos casos puede ser 0x3F.

Tomando la dirección predeterminada de 0x27 como ejemplo, la dirección del dispositivo se puede modificar puenteando los pads A0/A1/A2; en el estado predeterminado, A0/A1/A2 es 1, y si se puentea el pad, A0/A1/A2 es 0.

.. image:: img/i2c_address.jpg
    :width: 600

**Retroiluminación/Contraste**

La retroiluminación se puede habilitar con un jumper cap, desenchufar el jumper cap para desactivar la retroiluminación. El potenciómetro azul en la parte posterior se utiliza para ajustar el contraste (la relación de brillo entre el blanco más brillante y el negro más oscuro).

.. image:: img/back_lcd1602.jpg

* **Shorting Cap**: La retroiluminación se puede habilitar con este cap, desenchufar este cap para desactivar la retroiluminación.
* **Potenciómetro**: Se utiliza para ajustar el contraste (la claridad del texto mostrado), que se incrementa en el sentido de las agujas del reloj y se disminuye en el sentido contrario.

**Ejemplo**

* :ref:`ar_lcd1602` (Proyecto Básico)
* :ref:`ar_serial_read` (Proyecto Básico)
