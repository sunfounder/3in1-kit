.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _car_move:

1. Bewegung
===============

.. image:: ../components/img/l9110_module.jpg
    :width: 500
    :align: center

Bevor wir mit der Programmierung beginnen, betrachten wir das Funktionsprinzip des L9110-Moduls.

Hier ist die Wahrheitstabelle für Motor B:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - Zustand des Motors B
    * - 1
      - 0
      - Drehung im Uhrzeigersinn
    * - 0
      - 1
      - Drehung gegen den Uhrzeigersinn
    * - 0
      - 0
      - Bremse
    * - 1
      - 1
      - Stopp

Hier ist die Wahrheitstabelle für Motor A:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - Zustand des Motors A
    * - 1
      - 0
      - Drehung im Uhrzeigersinn
    * - 0
      - 1
      - Drehung gegen den Uhrzeigersinn
    * - 0
      - 0
      - Bremse
    * - 1
      - 1
      - Stopp

* :ref:`cpn_l9110`

**Vorwärts**

Verbinden Sie nun den Eingang des L9110-Moduls direkt mit 12V und GND, um das Auto zum Bewegen zu bringen.

1. Verbinden Sie das R4-Board, das L9110-Modul und die beiden Motoren.

.. image:: img/car_1.png
    :width: 800

2. Verbinden Sie B-1B(B-2A) und A-1A mit VCC und B-1A und A-1B mit GND, dann sehen Sie, wie sich das Auto vorwärts bewegt.

.. image:: img/1.move_4.png 
    :align: center

Wenn nicht beide nach vorne drehen, aber die folgenden Situationen auftreten, müssen Sie die Verkabelung der beiden Motoren neu justieren.

* Wenn beide Motoren gleichzeitig rückwärts drehen (linker Motor im Uhrzeigersinn, rechter Motor gegen den Uhrzeigersinn), tauschen Sie die Verkabelung der linken und rechten Motoren gleichzeitig. OA(A) und OB(A) tauschen, OA(B) und OB(B) tauschen.
* Wenn der linke Motor rückwärts dreht (im Uhrzeigersinn), tauschen Sie die Verkabelung von OA(B) und OB(B) des linken Motors.
* Wenn der rechte Motor rückwärts dreht (gegen den Uhrzeigersinn), tauschen Sie die Verkabelung von OA(A) und OB(A) des rechten Motors.

**Rückwärts**

Verbinden Sie B-1B(B-2A) und A-1A mit GND und B-1A und A-1B mit VCC, dann sehen Sie, wie sich das Auto rückwärts bewegt.

.. image:: img/1.move_back.png 
    :width: 800

**Nach Links abbiegen**

Wenn Sie das Auto nach links abbiegen lassen möchten, also beide Motoren im Uhrzeigersinn drehen lassen möchten. Sie müssen B-1A und A-1A mit GND und B-1B(B-2A) und A-1B mit VCC verbinden.

.. image:: img/1.move_left.png 
    :width: 800

**Nach Rechts abbiegen**

Umgekehrt, wenn Sie das Auto nach rechts abbiegen lassen möchten, also beide Motoren gegen den Uhrzeigersinn drehen lassen möchten. Sie müssen B-1A und A-1A mit VCC und B-1B(B-2A) und A-1B mit GND verbinden.

.. image:: img/1.move_right.png 
    :width: 800

**Stopp**

Um den Motor anzuhalten, verbinden Sie die Eingänge auf der gleichen Seite gleichzeitig mit 12V oder GND, z.B. B-1A und B-1B(B-2A) gleichzeitig mit 12V oder 5V verbinden und dasselbe für A-1A und A-1B.

Dies ist natürlich theoretisch und wird später bei der Steuerung mit Code benötigt. Hier kann das Entfernen der Stromversorgung vom Auto es anhalten.
