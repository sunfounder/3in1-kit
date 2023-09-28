.. _basic_projects:

Grundprojekte
========================

In diesem Kapitel lernen Sie, wie Sie mit Arduino elektronische Schaltungen steuern können.

Je nach den Komponenten können die grundlegenden Steuerungsmethoden von Arduino in vier Typen unterteilt werden:

* :ref:`ar_digital_write`: Setzt die Ausgangsspannung des Pins auf hoch oder niedrig, womit z.B. das Licht ein- und ausgeschaltet werden kann.
* :ref:`ar_analog_write`: Schreibt den analogen Wert (`PWM-Welle <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_) auf den Pin, um die Helligkeit des Lichts zu regulieren.
* :ref:`ar_digital_read`: Liest das Pegelsignal des digitalen Pins aus, was zum Ablesen des Arbeitszustands des Schalters verwendet werden kann.
* :ref:`ar_analog_read`: Liest die Spannung des analogen Pins aus, wodurch der Arbeitszustand eines Knopfes abgelesen werden kann.

Es gibt auch einige Komponenten, die zusätzliche Bibliotheken für ihre Verwendung benötigen. Diese sind im Abschnitt :ref:`install_libraries_ar` zusammengefasst.

Schließlich bietet das Kit auch einige :ref:`ar_funny_project`, die viele einfache und nützliche Manipulationen beinhalten.
Probieren Sie diesen Abschnitt des Codes aus, und Sie werden verstehen, wie die meisten einfachen Projekte funktionieren.


.. toctree::
    :maxdepth: 2

    ard_digital_write
    ard_analog_write
    ard_digital_read
    ard_analog_read
    ard_more_syntax
    ard_funny_project


