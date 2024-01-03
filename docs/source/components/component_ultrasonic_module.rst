.. _cpn_ultrasonic:

Módulo Ultrasónico
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

El módulo de medición ultrasónica ofrece una función de medición sin contacto de 2cm a 400cm, y la precisión del rango puede alcanzar los 3mm. 
Garantiza que la señal sea estable dentro de los 5m, y la señal se debilita gradualmente después de 5m, hasta desaparecer en la posición de 7m.

El módulo incluye transmisores ultrasónicos, receptor y circuito de control. Los principios básicos son los siguientes:

#. Usar un flip-flop de IO para procesar una señal de alto nivel de al menos 10us.

#. El módulo envía automáticamente ocho pulsos de 40khz y detecta si hay una señal de pulso de retorno.

#. Si la señal retorna, pasando al nivel alto, la duración de salida IO alto es el tiempo desde la transmisión de la onda ultrasónica hasta su retorno. Aquí, distancia de prueba = (tiempo alto x velocidad del sonido (340 m / s) / 2.

El diagrama de tiempo se muestra a continuación.

.. image:: img/ultrasonic228.png

Solo necesitas suministrar un breve pulso de 10us para la entrada de disparo para iniciar el rango, y luego el módulo
enviará una ráfaga de 8 ciclos de ultrasonido a 40 kHz y elevará su
eco. Puedes calcular el rango a través del intervalo de tiempo entre
enviar la señal de disparo y recibir la señal de eco.

Fórmula: us / 58 = centímetros o us / 148 = pulgadas; o: el rango = tiempo
de nivel alto \* velocidad (340M/S) / 2; se sugiere usar un
ciclo de medición superior a 60ms para evitar colisiones de señales de
la señal de disparo y la señal de eco.

**Ejemplo**

* :ref:`ar_ultrasonic` (Proyecto Básico)
* :ref:`car_ultrasonic` (Proyecto de Coche)
* :ref:`follow_your_hand` (Proyecto de Coche)
* :ref:`sh_parrot` (Proyecto Scratch)

