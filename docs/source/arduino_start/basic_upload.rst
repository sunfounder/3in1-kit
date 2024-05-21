.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

Cómo subir un Sketch a la Placa
=============================================

En esta sección, aprenderás a subir el sketch creado previamente a la placa Arduino, así como conocer algunas consideraciones.

**1. Elige la Placa y el Puerto**

Las placas de desarrollo Arduino suelen venir con un cable USB. Puedes usarlo para conectar la placa a tu computadora.

Selecciona la **Board** y el **Port** correctos en el IDE de Arduino. Normalmente, las placas Arduino son reconocidas automáticamente por la computadora y se les asigna un puerto, así que puedes seleccionarlo aquí.

    .. image:: img/board_port.png

Si tu placa ya está conectada pero no es reconocida, verifica si el logotipo **INSTALLED** aparece en la sección **Arduino AVR Boards** del **Boards Manager**, si no, por favor, desplázate un poco hacia abajo y haz clic en **INSTALL**.

    .. image:: img/upload1.png

Reabrir el IDE de Arduino y volver a conectar la placa Arduino solucionará la mayoría de los problemas. También puedes hacer clic en **Tools** -> **Board** o **Port** para seleccionarlos.

**2. Verificar el Sketch**

Después de hacer clic en el botón Verificar, el sketch se compilará para ver si hay errores.

    .. image:: img/sp221014_174532.png

Puedes usarlo para encontrar errores si eliminas algunos caracteres o escribes algunas letras por error. Desde la barra de mensajes, puedes ver dónde y qué tipo de errores ocurrieron.

    .. image:: img/sp221014_175307.png

Si no hay errores, verás un mensaje como el siguiente.

    .. image:: img/sp221014_175512.png

**3. Subir sketch**

Después de completar los pasos anteriores, haz clic en el botón **Upload** para cargar este sketch en la placa.

    .. image:: img/sp221014_175614.png

Si tienes éxito, podrás ver el siguiente aviso.

.. image:: img/sp221014_175654.png

Al mismo tiempo, el LED de la placa parpadeará.

.. image:: img/1_led.jpg

La placa Arduino ejecutará automáticamente el sketch después de que se aplique energía una vez que el sketch se haya cargado. El programa en ejecución puede ser sobrescrito subiendo un nuevo sketch.
