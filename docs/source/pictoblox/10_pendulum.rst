.. _sh_pendulum:

2.10 Péndulo
=====================

En este proyecto, haremos un péndulo con forma de flecha mientras el servo sigue la rotación.

.. image:: img/12_pun.png

Aprenderás
---------------------

- Cómo funciona el servo y el rango de ángulos
- Dibujar un sprite y colocar el punto central en la cola.

Componentes Necesarios
--------------------------

En este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ARTÍCULOS EN ESTE KIT
        - ENLACE
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

También puedes comprarlos por separado en los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo` 
        - |link_servo_buy|

Construir el Circuito
-----------------------

Un servo es un motor engranado que solo puede girar 180 grados. Se
controla enviando pulsos eléctricos desde tu placa de circuito. Estos pulsos
le indican al servo a qué posición debe moverse.

El servo tiene tres cables: el cable marrón es GND, el rojo es VCC (conectar a 3.3V) y el naranja es el cable de señal. El rango de ángulos es de 0-180.

Ahora construye el circuito según el diagrama a continuación.

.. image:: img/circuit/servo_circuit.png

Programación
------------------

**1. Pintar un sprite**

Elimina el sprite predeterminado, selecciona el botón Sprite y haz clic en **Paint**, aparecerá un sprite en blanco **Sprite1**.

.. image:: img/12_paint1.png

En la página de **Costumes** abierta, usa la **Line tool** para dibujar una flecha.

.. note::

    * Asegúrate de comenzar a dibujar la flecha desde el centro del lienzo hacia afuera para que la flecha gire en círculo con el punto central como origen.
    * Mantén presionado Shift para que el ángulo de la línea sea recto o de 45 grados.

.. image:: img/12_paint2.png

Después de dibujar, el sprite **arrow** se mostrará en el escenario, nómbralo **arrow**. Luego haz clic en el número después de **Direction**, aparecerá un dial circular, ahora arrastra esta flecha y observa si el sprite **arrow** en el escenario gira con la cola como origen.

.. image:: img/12_paint3.png

Para hacer que el sprite **arrow** se balancee de izquierda a derecha, el rango de ángulos es de -90 a -180, 180 a 90.

.. image:: img/12_paint4.png

.. image:: img/12_paint5.png

**2. Crear una variable**.

Crea una variable llamada **servo**, que almacena el valor del ángulo y establece el valor inicial en 270.

.. image:: img/12_servo.png

**3. Balanceo de izquierda a derecha**

Ahora haz que el sprite **arrow** se balancee desde la posición de -90 grados a la izquierda hasta la posición de 90 grados a la derecha.

Con el bloque [repeat], suma -10 a la variable cada vez, y llegarás a 90 grados en 18 pasos. Luego usa [point in block] para hacer que el sprite de la flecha gire a estos ángulos.

Dado que el ángulo de rotación del sprite es de -180 ~ 180, los ángulos fuera de este rango se convierten con las siguientes condiciones.

* Si el ángulo > 180, entonces ángulo -360.

.. image:: img/12_servo1.png

**4. Girar el Servo**

Cuando hagas clic en la bandera verde, verás que la flecha gira rápidamente hacia la derecha y luego hacia la izquierda, así que usa un bloque [wait seconds] aquí para hacer la rotación más lenta. También usa el bloque [set servo on to angle] para hacer que el servo conectado a la placa Arduino gire a un ángulo específico.

.. image:: img/12_servo2.png

**5. Balanceo de derecha a izquierda**

Con el mismo método, haz que el servo y el sprite **arrow** giren lentamente de derecha a izquierda.

* Si el ángulo > 180, entonces ángulo -360.

.. image:: img/12_servo3.png
