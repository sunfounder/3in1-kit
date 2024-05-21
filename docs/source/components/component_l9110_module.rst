.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_l9110:

Módulo Controlador de Motor L9110
======================================

El módulo controlador de motor L9110 es experto en manejar dos motores en tándem. Aloja un par de chips controladores L9110S independientes, 
cada canal cuenta con una salida de corriente constante de hasta 800mA.

Con un rango de voltaje de 2.5V a 12V, el módulo se empareja cómodamente tanto con microcontroladores de 3.3V como de 5V.

Sirviendo como una solución optimizada, el módulo controlador de motor L9110 facilita el control de motores en un espectro de aplicaciones. 
Gracias a su arquitectura de doble canal, permite la orquestación independiente de dos motores, ideal para proyectos donde las operaciones de doble motor 
son fundamentales.

Dado su potente salida de corriente continua, este módulo impulsa con confianza motores desde los más pequeños hasta los de tamaño moderado, 
abriendo camino para diversos emprendimientos robóticos, de automatización y centrados en motores. Su amplio rango de voltaje inyecta además adaptabilidad, alineándose con variadas configuraciones de suministro de energía.

Diseñado pensando en la facilidad de uso, el módulo ofrece terminales de entrada y salida intuitivos, simplificando las conexiones a microcontroladores 
o dispositivos de control similares. Además, no escatima en seguridad: las protecciones integradas contra sobrecorriente y sobrecalentamiento refuerzan la fiabilidad 
y seguridad de las operaciones de los motores.

.. image:: img/l9110_module.jpg
    :width: 600
    :align: center

* **B-1A & B-1B(B-2A)**: Pines de entrada para controlar la dirección de giro del Motor B.
* **A-1A & A-1B**: Pines de entrada para controlar la dirección de giro del Motor A.
* **0A & OB(A)**: Pines de salida del Motor A.
* **0A & OB(B)**: Pines de salida del Motor B.
* **VCC**: Pin de entrada de energía (2.5V-12V).
* **GND**: Pin de tierra.

**Características**

* Dos chips de control de motor L9110S a bordo.
* Control de motor de doble canal.
* Control independiente de la dirección de giro del motor.
* Alta salida de corriente (800mA por canal).
* Amplio rango de voltaje (2.5V-12V).
* Diseño compacto.
* Terminales de entrada y salida convenientes.
* Características de protección incorporadas.
* Aplicaciones versátiles.
* Tamaño del PCB: 29.2mm x 23mm
* Temperatura de Operación: -20°C ~ 80°C
* Indicador LED de encendido

**Principio de Funcionamiento**

Aquí está la tabla de verdad del Motor B:

Esta tabla de verdad muestra los diferentes estados del Motor B basados en los valores de los pines de entrada B-1A y B-1B(B-2A). Indica la dirección de rotación (en el sentido de las agujas del reloj o en sentido contrario), frenado o detención del Motor B.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - Estado del Motor B
    * - 1
      - 0
      - Gira en el sentido de las agujas del reloj
    * - 0
      - 1
      - Gira en sentido contrario a las agujas del reloj
    * - 0
      - 0
      - Freno
    * - 1
      - 1
      - Detener

Aquí está la tabla de verdad del Motor A:

Esta tabla de verdad muestra los diferentes estados del Motor A basados en los valores de los pines de entrada A-1A y A-1B. Indica la dirección de rotación (en el sentido de las agujas del reloj o en sentido contrario), frenado o detención del Motor A.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - Estado del Motor B
    * - 1
      - 0
      - Gira en el sentido de las agujas del reloj
    * - 0
      - 1
      - Gira en sentido contrario a las agujas del reloj
    * - 0
      - 0
      - Freno
    * - 1
      - 1
      - Detener

* :ref:`ar_motor` (Proyecto Básico)
* :ref:`car_move` (Proyecto de Coche)
* :ref:`car_speed` (Proyecto de Coche)
* :ref:`iot_car` (Proyecto IoT)
