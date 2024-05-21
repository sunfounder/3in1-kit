.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_servo:

Servo
===========

.. image:: img/servo.png
    :align: center

Ein Servo besteht in der Regel aus folgenden Teilen: Gehäuse, Welle, Getriebesystem, Potentiometer, Gleichstrommotor und eingebettetem Board.

So funktioniert es: Der Mikrocontroller sendet PWM-Signale an den Servo. Das eingebettete Board im Servo empfängt diese Signale über den Signalpin und steuert den darin befindlichen Motor an. Dadurch treibt der Motor das Getriebesystem an, welches nach einer Verzögerung die Welle antreibt. Die Welle und das Potentiometer des Servos sind miteinander verbunden. Wenn sich die Welle dreht, treibt sie das Potentiometer an. Das Potentiometer gibt ein Spannungssignal an das eingebettete Board weiter. Das Board bestimmt dann auf Basis der aktuellen Position die Drehrichtung und -geschwindigkeit, sodass es genau an der definierten Position stoppen und dort verharren kann.

.. image:: img/servo_internal.png
    :align: center

Der Winkel wird durch die Dauer eines Impulses bestimmt, der auf das Steuerkabel gegeben wird. Dies wird als Pulsweitenmodulation bezeichnet. Das Servo erwartet alle 20 ms einen Impuls. Die Länge des Impulses bestimmt, wie weit der Motor dreht. Ein 1,5ms-Impuls lässt den Motor beispielsweise auf die 90-Grad-Position (Neutralstellung) drehen. Wenn ein Impuls, der kürzer als 1,5 ms ist, an einen Servo gesendet wird, dreht sich dieser zu einer Position und hält seine Ausgangswelle einige Grade gegen den Uhrzeigersinn vom Neutralpunkt aus. Bei einem Impuls, der breiter als 1,5 ms ist, tritt das Gegenteil auf. Die minimale Impulsbreite und die maximale Impulsbreite, die den Servo zu einer gültigen Position drehen lassen, sind Funktionen jedes Servos. Üblicherweise liegt die Mindestimpulsbreite bei etwa 0,5 ms und die Maximalimpulsbreite bei 2,5 ms.

.. image:: img/servo_duty.png
    :width: 600
    :align: center

**Beispiel**

* :ref:`ar_servo` (Grundlegendes Projekt)
* :ref:`iot_gate` (IoT-Projekt)

.. * :ref:`sh_pendulum` (Scratch-Projekt)
