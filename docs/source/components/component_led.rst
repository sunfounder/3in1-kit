.. _cpn_led:

LED
==========

.. image:: img/LED.png
    :width: 400

Halbleiter-Leuchtdioden sind eine Art von Bauteil, das elektrische Energie durch PN-Übergänge in Lichtenergie umwandeln kann. Nach Wellenlänge unterteilt, gibt es Laserdioden, Infrarot-Leuchtdioden und sichtbare Leuchtdioden, die im Allgemeinen als Leuchtdioden (LED) bezeichnet werden.

Dioden haben eine unidirektionale Leitfähigkeit, daher fließt der Strom im Schaltungssymbol so, wie der Pfeil es anzeigt. Man sollte nur der Anode eine positive und der Kathode eine negative Spannung zuführen. Dadurch leuchtet die LED.

.. image:: img/led_symbol.png

Eine LED hat zwei Pins. Der längere ist die Anode und der kürzere die Kathode. Achten Sie darauf, sie nicht verkehrt herum anzuschließen. In der LED gibt es eine feste Vorwärtsspannung, weshalb sie nicht direkt mit der Schaltung verbunden werden kann, da die Versorgungsspannung diesen Abfall übersteigen und die LED dadurch beschädigen kann. Die Vorwärtsspannung der roten, gelben und grünen LED beträgt 1,8 V und die der weißen LED 2,6 V. Die meisten LEDs können einen maximalen Strom von 20 mA verkraften, daher muss ein Strombegrenzungswiderstand in Reihe geschaltet werden.

Die Formel für den Widerstandswert lautet:

    R = (Vsupply – VD)/I

**R** steht für den Widerstandswert des Strombegrenzungswiderstands, **Vsupply** für die Versorgungsspannung, **VD** für den Spannungsabfall und **I** für den Betriebsstrom der LED.

Hier finden Sie eine detaillierte Einführung in die LED: `LED - Wikipedia <https://en.wikipedia.org/wiki/Light-emitting_diode>`_.

**Beispiel**

* :ref:`ar_blink` (Grundlegendes Projekt)
* :ref:`ar_fading` (Grundlegendes Projekt)
* :ref:`iot_blink` (IoT-Projekt)

.. * :ref:`sh_breathing_led` (Scratch-Projekt)
.. * :ref:`sh_table_lamp` (Scratch-Projekt)

