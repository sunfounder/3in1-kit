.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_thermistor:

Termistor
===============

.. image:: img/thermistor.png
    :width: 150
    :align: center

Un termistor es un tipo de resistor cuya resistencia depende fuertemente de la temperatura, más que en los resistores estándar. La palabra es una combinación de térmico y resistor. Los termistores se utilizan ampliamente como limitadores de corriente de arranque, sensores de temperatura (típicamente del tipo de coeficiente de temperatura negativo o NTC), protectores de sobrecorriente autoreajustables y elementos de calentamiento autorreguladores (típicamente del tipo de coeficiente de temperatura positivo o PTC).

* `Termistor - Wikipedia <https://en.wikipedia.org/wiki/Thermistor>`_

Aquí está el símbolo electrónico del termistor.

.. image:: img/thermistor_symbol.png
    :width: 300
    :align: center

Los termistores son de dos tipos fundamentales opuestos:

* Con termistores NTC, la resistencia disminuye a medida que aumenta la temperatura, generalmente debido a un aumento en los electrones de conducción impulsados por la agitación térmica desde la banda de valencia. Un NTC se utiliza comúnmente como sensor de temperatura o en serie con un circuito como limitador de corriente de arranque.
* Con termistores PTC, la resistencia aumenta a medida que aumenta la temperatura, generalmente debido a un aumento en las agitaciones de la red térmica, particularmente aquellas de impurezas e imperfecciones. Los termistores PTC se instalan comúnmente en serie con un circuito y se utilizan para proteger contra condiciones de sobrecorriente, como fusibles reajustables.

En este kit usamos uno NTC. Cada termistor tiene una resistencia normal. Aquí es de 10k ohmios, medida a 25 grados Celsius.

Aquí está la relación entre la resistencia y la temperatura:

    RT = RN * expB(1/TK – 1/TN)   

* **RT** es la resistencia del termistor NTC cuando la temperatura es TK. 
* **RN** es la resistencia del termistor NTC bajo la temperatura nominal TN. Aquí, el valor numérico de RN es 10k.
* **TK** es una temperatura en Kelvin y la unidad es K. Aquí, el valor numérico de TK es 273.15 + grados Celsius.
* **TN** es una temperatura nominal en Kelvin; la unidad también es K. Aquí, el valor numérico de TN es 273.15+25.
* Y **B(beta)**, la constante material del termistor NTC, también se llama índice de sensibilidad al calor con un valor numérico de 3950.      
* **exp** es la abreviatura de exponencial, y el número base e es un número natural y equivale aproximadamente a 2.7.  

Convierte esta fórmula TK=1/(ln(RT/RN)/B+1/TN) para obtener la temperatura en Kelvin que menos 273.15 equivale a grados Celsius.

Esta relación es una fórmula empírica. Solo es precisa cuando la temperatura y la resistencia están dentro del rango efectivo.

**Ejemplo**

* :ref:`ar_temp` (Proyecto Básico)
* :ref:`ar_high_tem_alarm` (Proyecto Básico)
* :ref:`sh_low_temperature` (Proyecto Scratch)

