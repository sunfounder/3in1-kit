.. _cpn_track:

Módulo de Seguimiento de Línea
================================

.. image:: img/line_track.png
    :width: 400
    :align: center

* S: Normalmente a nivel bajo, pasa a nivel alto cuando se detecta una línea negra.
* V+: Fuente de alimentación, 3.3v~5V
* G: Tierra

Este es un módulo de Seguimiento de Línea de 1 canal que, como su nombre indica, sigue líneas negras sobre un fondo blanco o líneas blancas sobre un fondo negro.

.. image:: img/tcrt5000.jpg
    :width: 200
    :align: center

El módulo utiliza un sensor infrarrojo TCRT500, que consta de un LED infrarrojo (azul) y un triple fototransistor (negro).

* El LED infrarrojo azul, al encenderse, emite luz infrarroja que es invisible al ojo humano.
* El fototransistor negro, que se utiliza para recibir luz infrarroja, tiene una resistencia interna cuya resistencia varía con la luz infrarroja recibida; cuanto más luz infrarroja recibe, más disminuye su resistencia y viceversa.

Hay un comparador LM393 en el módulo, que se usa para comparar el voltaje del fototransistor con el voltaje ajustado (ajustado por un potenciómetro), si es mayor que el voltaje ajustado, la salida es 1; de lo contrario, la salida es 0.

Por lo tanto, cuando el tubo emisor de infrarrojos brilla sobre una superficie negra, debido a que el negro absorberá la luz, el fototransistor fotosensible recibe menos luz infrarroja, su resistencia aumentará (el voltaje aumentará), después del comparador LM393, la salida es de nivel alto.

Del mismo modo, cuando brilla sobre una superficie blanca, la luz reflejada se volverá más y la resistencia del fototransistor fotosensible disminuirá (el voltaje disminuye); por lo tanto, el comparador emite un nivel bajo y se enciende el LED indicador.

* `TCRT5000 <https://www.vishay.com/docs/83760/tcrt5000.pdf>`_

**Características**

* Uso del sensor de emisión infrarroja TCRT5000
* Distancia de detección: 1-8mm, distancia focal de 2.5mm
* Salida del comparador limpia, buena forma de onda, capacidad de conducción superior a 15mA
* Uso de potenciómetro para ajuste de sensibilidad
* Voltaje de operación: 3.3V-5V
* Salida digital: 0 (blanco) y 1 (negro)
* Usa el comparador LM393 de amplio voltaje.
* Tamaño: 42mmx10mm

**Ejemplo**

* :ref:`ar_line_track` (Proyecto Básico)
* :ref:`follow_the_line` (Proyecto de Coche)
* :ref:`sh_protect_heart` (Proyecto Scratch)
