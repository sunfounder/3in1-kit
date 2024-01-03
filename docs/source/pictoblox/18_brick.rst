.. _sh_breakout_clone:

2.18 JUEGO - Clon de Breakout
===============================

Aquí utilizamos el potenciómetro para jugar un juego tipo Clon de Breakout.

Tras hacer clic en la bandera verde, necesitas usar el potenciómetro para controlar la paleta en el escenario y atrapar la pelota para que suba y golpee los ladrillos. Si desaparecen todos los ladrillos, ganas el juego; si no atrapas la pelota, pierdes.

.. image:: img/17_brick.png

Componentes Necesarios
------------------------

Para este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS EN ESTE KIT
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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

Construye el Circuito
-----------------------

El potenciómetro es un elemento resistivo con 3 terminales, los pines laterales se conectan a 5V y GND, y el pin central se conecta a A0. Tras la conversión por el convertidor ADC de la placa Arduino, el rango de valores es de 0-1023.

.. image:: img/circuit/potentiometer_circuit.png

Programación
------------------

Hay 3 sprites en el escenario.

**1. Sprite Paleta**

El efecto a lograr por la **Paddle** es que la posición inicial esté en el centro de la parte inferior del escenario, y sea controlada por un potenciómetro para moverse a la izquierda o a la derecha.

* Elimina el sprite por defecto, usa el botón **Choose a Sprite** para añadir el sprite **Paddle**, y ajusta sus coordenadas x e y a (0, -140).

.. image:: img/17_padd1.png

* Ve a la página **Costumes**, elimina el Contorno y cambia su color a gris oscuro.

.. image:: img/17_padd3.png


* Ahora programa el sprite **Paddle** para establecer su posición inicial en (0, -140) cuando se hace clic en la bandera verde, y lee el valor de A0 (potenciómetro) en la variable **a0**. Dado que el sprite **Paddle** se mueve de izquierda a derecha en el escenario en las coordenadas x -195~195, necesitas usar el bloque [map] para mapear el rango de la variable **a0** de 0~1023 a -195~195.

.. image:: img/17_padd2.png

* Ahora puedes girar el potenciómetro para ver si la **Paddle** puede moverse de izquierda a derecha en el escenario.

**2. Sprite Bola**

El efecto del sprite Bola es que se mueva por el escenario y rebote al tocar los bordes; rebota hacia abajo si toca el bloque sobre el escenario; rebota hacia arriba si toca el sprite Paleta durante su caída; si no lo hace, el script se detiene y el juego termina.

* Añade el sprite **Ball**.

.. image:: img/17_ball1.png

* Cuando se hace clic en la bandera verde, ajusta el ángulo del sprite **Ball** a 45° y establece la posición inicial en (0, -120).

.. image:: img/17_ball2.png

* Ahora deja que el sprite **Ball** se mueva por el escenario y rebote al tocar los bordes, y puedes hacer clic en la bandera verde para ver el efecto.

.. image:: img/17_ball3.png

* Cuando el sprite **Ball** toca el sprite **Paddle**, realiza una reflexión. La manera fácil de hacer esto es invertir directamente el ángulo, pero luego encontrarás que la trayectoria de la bola es completamente fija, lo cual es demasiado aburrido. Por lo tanto, usamos el centro de los dos sprites para calcular y hacer que la bola rebote en la dirección opuesta al centro del deflector.

.. image:: img/17_ball4.png

.. image:: img/17_ball6.png

* Cuando el sprite **Ball** cae al borde del escenario, el script se detiene y el juego termina.

.. image:: img/17_ball5.png


**3. Sprite Bloque1**

El sprite **Block1** debe aparecer con el efecto de clonarse 4x8 de sí mismo sobre el escenario en un color aleatorio y eliminar un clon si es tocado por el sprite **Ball**.

El sprite **Block1** no está disponible en la biblioteca **PictoBlox**, necesitas dibujarlo tú mismo o modificarlo con un sprite existente. Aquí vamos a modificarlo con el sprite **Button3**.

* Después de añadir el sprite **Button3**, ve a la página **Costumes**. Ahora elimina primero **button-a**, luego reduce tanto el ancho como el alto de **button-b** y cambia el nombre del sprite a **Block1**, como se muestra en la siguiente imagen.

.. note::

    * Para el ancho de **Block1**, puedes simularlo en la pantalla para ver si puedes colocar 8 en fila, si no, reduce el ancho apropiadamente.
    * En el proceso de reducir el sprite **Block1**, necesitas mantener el punto central en el medio del sprite.

.. image:: img/17_bri2.png

* Ahora crea 2 variables primero, **block** para almacenar el número de bloques y **roll** para almacenar el número de filas.

.. image:: img/17_bri3.png

* Necesitamos hacer un clon del sprite **Block1**, para que se muestre de izquierda a derecha, de arriba a abajo, uno por uno, 4x8 en total, con colores aleatorios.

.. image:: img/17_bri4.png

* Después de escribir el script, haz clic en la bandera verde y mira la exhibición en el escenario, si está demasiado compacto o demasiado pequeño, puedes cambiar el tamaño.

.. image:: img/17_bri5.png

* Ahora escribe el evento desencadenante. Si el clon del sprite **Block1** toca el sprite **Ball**, elimina el clon y emite el mensaje **crush**.

.. image:: img/17_bri6.png

* De vuelta al sprite **Ball**, cuando se recibe la emisión **crush** (el sprite **Ball** toca el clon del sprite **Block1**), la **Ball** se impulsa en la dirección opuesta.

.. image:: img/17_ball7.png
