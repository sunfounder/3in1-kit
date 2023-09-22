.. _basic_projects:

Grundprojekte
========================

In diesem Kapitel lernen Sie, wie Sie elektronische Schaltungen mit Arduino steuern können.

Je nach Komponenten können die grundlegenden Steuermethoden von Arduino in vier Typen unterteilt werden:

* :ref:`ar_digital_write`: Setzen Sie die Ausgangsspannung des Pins auf Hoch oder Niedrig, um das Licht ein- und auszuschalten.
* :ref:`ar_analog_write`: Schreiben Sie den analogen Wert (`PWM-Welle <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_) auf den Pin, um die Helligkeit des Lichts anzupassen.
* :ref:`ar_digital_read`: Lesen Sie das Pegelsignal des digitalen Pins, um den Arbeitszustand des Schalters zu ermitteln.
* :ref:`ar_analog_read`: Lesen Sie die Spannung des analogen Pins, um den Arbeitszustand des Drehknopfs zu ermitteln.

Es gibt auch einige Komponenten, die zusätzliche Bibliotheken für ihre Verwendung benötigen, und diese sind im Abschnitt :ref:`install_libraries_ar` zusammengefasst.

Schließlich bietet das Set auch einige :ref:`ar_funny_project`, die viele einfache und nützliche Manipulationen enthalten.
Probieren Sie diesen Abschnitt des Codes aus und Sie werden verstehen, wie die meisten einfachen Projekte funktionieren.



.. toctree::
    :maxdepth: 2

    ard_digital_write
    ard_analog_write
    ard_digital_read
    ard_analog_read
    ard_more_syntax
    ard_funny_project


