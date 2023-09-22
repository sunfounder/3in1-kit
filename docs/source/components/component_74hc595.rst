.. _cpn_74hc595:

74HC595
===========

.. image:: img/74HC595.png

Der 74HC595 besteht aus einem 8-Bit-Schieberegister und einem Speicherregister mit dreistufigen parallelen Ausgängen. Er wandelt serielle Eingaben in parallele Ausgaben um, sodass Sie IO-Ports eines MCU einsparen können.
Wenn MR (Pin10) auf hohem Pegel und OE (Pin13) auf niedrigem Pegel ist, werden Daten am aufsteigenden Flanken von SHcp eingegeben und gelangen über den aufsteigenden Flanken von SHcp ins Speicherregister. Wenn die beiden Taktgeber verbunden sind, liegt das Schieberegister immer einen Puls vor dem Speicherregister. Es gibt einen seriellen Schiebeeingangspin (Ds), einen seriellen Ausgangspin (Q) und einen asynchronen Reset-Taster (niedriger Pegel) im Speicherregister. Das Speicherregister gibt einen Bus mit parallelen 8 Bits und in drei Zuständen aus. Wenn OE aktiviert ist (niedriger Pegel), wird die Daten im Speicherregister auf den Bus ausgegeben.

* `74HC595 Datenblatt <https://www.ti.com/lit/ds/symlink/cd74hc595.pdf?ts=1617341564801>`_

.. image:: img/74hc595_pin.png
    :width: 600

Pins des 74HC595 und ihre Funktionen:

* **Q0-Q7**: 8-Bit-parallele Daten-Ausgangspins, können 8 LEDs oder 8 Pins einer 7-Segment-Anzeige direkt steuern.
* **Q7’**: Serieller Ausgangspin, verbunden mit DS eines anderen 74HC595, um mehrere 74HC595 in Serie zu verbinden.
* **MR**: Reset-Pin, aktiv auf niedrigem Pegel.
* **SHcp**: Zeitsequenzeingabe des Schieberegisters. Am aufsteigenden Rand bewegen sich die Daten im Schieberegister nacheinander um ein Bit, d.h. Daten in Q1 wechseln zu Q2 usw. Am fallenden Rand bleiben die Daten im Schieberegister unverändert.
* **STcp**: Zeitsequenzeingabe des Speicherregisters. Am aufsteigenden Rand wechseln die Daten im Schieberegister ins Speicherregister.
* **CE**: Ausgangsaktivierungspin, aktiv auf niedrigem Pegel.
* **DS**: Serieller Dateneingangspin.
* **VCC**: Positive Versorgungsspannung.
* **GND**: Erdung.

**Beispiel**

* :ref:`ar_shiftout` (Grundlegendes Projekt)
* :ref:`ar_segment` (Grundlegendes Projekt)
* :ref:`iot_gate` (IoT-Projekt)

