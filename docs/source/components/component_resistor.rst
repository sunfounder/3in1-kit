.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _cpn_resistor:

Resistencia
============

.. image:: img/resistor.png
    :width: 300

La resistencia es un elemento electrónico que puede limitar la corriente de una rama. 
Una resistencia fija es un tipo de resistencia cuyo valor no se puede cambiar, mientras que el de un potenciómetro o una resistencia variable sí se puede ajustar.

Se utilizan dos símbolos de circuito comunes para la resistencia. Normalmente, la resistencia está marcada en ella. Así que si ves estos símbolos en un circuito, representan una resistencia.

.. image:: img/resistor_symbol.png
    :width: 400

**Ω** es la unidad de resistencia y las unidades mayores incluyen KΩ, MΩ, etc. 
Su relación se puede mostrar de la siguiente manera: 1 MΩ = 1000 KΩ, 1 KΩ = 1000 Ω. Normalmente, el valor de la resistencia está marcado en ella.

Cuando se utiliza una resistencia, primero necesitamos conocer su valor. Aquí hay dos métodos: puedes observar las bandas en la resistencia o usar un multímetro para medir la resistencia. Se recomienda utilizar el primer método, ya que es más conveniente y rápido.

.. image:: img/resistance_card.jpg

Como se muestra en la tarjeta, cada color representa un número.

.. list-table::

   * - Negro
     - Marrón
     - Rojo
     - Naranja
     - Amarillo
     - Verde
     - Azul
     - Violeta
     - Gris
     - Blanco
     - Oro
     - Plata
   * - 0
     - 1
     - 2
     - 3
     - 4
     - 5
     - 6
     - 7
     - 8
     - 9
     - 0.1
     - 0.01

Las resistencias de 4 y 5 bandas son comúnmente utilizadas, en las que hay 4 y 5 bandas cromáticas.

Normalmente, cuando obtienes una resistencia, puede resultar difícil decidir por qué extremo comenzar a leer el color.
La pista es que el espacio entre la 4ª y la 5ª banda será comparativamente más grande.

Por lo tanto, puedes observar el espacio entre las dos bandas cromáticas en un extremo de la resistencia; 
si es más grande que cualquier otro espacio entre bandas, entonces puedes leer desde el lado opuesto.

Veamos cómo leer el valor de la resistencia de una resistencia de 5 bandas como se muestra a continuación.

.. image:: img/220ohm.jpg
    :width: 500

Entonces, para esta resistencia, el valor se debe leer de izquierda a derecha. 
El valor debe ser en este formato: 1ª Banda 2ª Banda 3ª Banda x 10^Multiplicador (Ω) y el error permisible es ±Tolerancia%. 
Así que el valor de la resistencia de esta resistencia es 2(rojo) 2(rojo) 0(negro) x 10^0(negro) Ω = 220 Ω, 
y el error permisible es ± 1% (marrón).

.. list-table::Colores comunes de bandas de resistencia
    :header-rows: 1

    * - Resistencia 
      - Banda de Color  
    * - 10Ω   
      - marrón negro negro plata marrón
    * - 100Ω   
      - marrón negro negro negro marrón
    * - 220Ω 
      - rojo rojo negro negro marrón
    * - 330Ω 
      - naranja naranja negro negro marrón
    * - 1kΩ 
      - marrón negro negro marrón marrón
    * - 2kΩ 
      - rojo negro negro marrón marrón
    * - 5.1kΩ 
      - verde marrón negro marrón marrón
    * - 10kΩ 
      - marrón negro negro rojo marrón 
    * - 100kΩ 
      - marrón negro negro naranja marrón 
    * - 1MΩ 
      - marrón negro negro verde marrón 

Puedes aprender más sobre las resistencias en Wiki: `Resistencia - Wikipedia <https://en.wikipedia.org/wiki/Resistor>`_.

