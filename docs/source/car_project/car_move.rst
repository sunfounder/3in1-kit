.. _car_move:

1. Bewegung
===============

.. image:: ../components/img/l9110_module.jpg
    :width: 500
    :align: center

Bevor wir mit der Programmierung beginnen, überprüfen wir das Arbeitsprinzip des L9110-Moduls.

Hier ist die Wahrheitstabelle des Motor B:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - Zustand des Motor B
    * - 1
      - 0
      - Dreht im Uhrzeigersinn
    * - 0
      - 1
      - Dreht gegen den Uhrzeigersinn
    * - 0
      - 0
      - Bremse
    * - 1
      - 1
      - Stop

Hier ist die Wahrheitstabelle des Motor A:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - Zustand des Motor A
    * - 1
      - 0
      - Dreht im Uhrzeigersinn
    * - 0
      - 1
      - Dreht gegen den Uhrzeigersinn
    * - 0
      - 0
      - Bremse
    * - 1
      - 1
      - Stop

* :ref:`cpn_l9110`

**Vorwärts**

Verbinden Sie nun den Eingang des L9110-Moduls direkt mit 12V bzw. GND, um das Auto zu bewegen.

.. raw:: html
    
  <iframe width="600" height="400" src="https://www.youtube.com/embed/ulD40OtsL7c?si=hJ9nyf8ePAWNp0-8" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

1. Verbinden Sie das R3-Board, das L9110-Modul und die 2 Motoren.

.. image:: img/car_1.png
    :width: 800

2. Verbinden Sie B-1B(B-2A) und A-1A mit VCC und B-1A sowie A-1B mit GND. Dann sollten Sie das Auto vorwärts fahren sehen.

.. image:: img/1.move_4.png 
    :align: center

Wenn beide nicht vorwärts drehen, aber die folgenden Situationen auftreten, müssen Sie die Verkabelung der beiden Motoren neu justieren.

* Wenn beide Motoren gleichzeitig rückwärts drehen (linker Motor dreht im Uhrzeigersinn, rechter Motor gegen den Uhrzeigersinn), tauschen Sie die Verkabelung der linken und rechten Motoren gleichzeitig, OA(A) und OB(A) tauschen, OA(B) und OB(B) tauschen.
* Wenn sich der linke Motor rückwärts dreht (Drehung im Uhrzeigersinn), tauschen Sie die Verkabelung von OA(B) und OB(B) des linken Motors.
* Wenn sich der rechte Motor rückwärts dreht (Drehung gegen den Uhrzeigersinn), tauschen Sie die Verkabelung von OA(A) und OB(A) des rechten Motors.

**Rückwärts**

Verbinden Sie B-1B(B-2A) und A-1A mit GND und B-1A sowie A-1B mit VCC. Dann sollten Sie das Auto rückwärts fahren sehen.

.. image:: img/1.move_back.png 
    :width: 800

**Links abbiegen**

Wenn Sie das Auto nach links abbiegen lassen möchten, also beide Motoren im Uhrzeigersinn drehen möchten, müssen Sie B-1A und A-1A mit GND und B-1B(B-2A) sowie A-1B mit VCC verbinden.

.. image:: img/1.move_left.png 
    :width: 800

**Rechts abbiegen**

Umgekehrt, wenn Sie das Auto nach rechts abbiegen lassen möchten, also beide Motoren gegen den Uhrzeigersinn drehen möchten, müssen Sie B-1A und A-1A mit VCC und B-1B(B-2A) sowie A-1B mit GND verbinden.

.. image:: img/1.move_right.png 
    :width: 800

**Stopp**

Um den Motor zu stoppen, verbinden Sie die Eingänge auf der gleichen Seite gleichzeitig mit 12V oder GND, z. B. verbinden Sie B-1A und B-1B(B-2A) gleichzeitig mit 12V oder 5V und ebenso für A-1A und A-1B.

Dies ist natürlich theoretisch und wird später beim Steuern mit Code benötigt. Hier kann das Entfernen der Stromversorgung vom Auto es stoppen.
