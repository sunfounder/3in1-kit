.. _ar_segment:


5.10 ShiftOut(Segmentanzeige)
=================================

In einem früheren Beispiel haben wir die Funktion ``shiftout()`` verwendet, um acht LEDs zu beleuchten. Hier verwenden wir sie, um die Zahlen 0-9 auf der 7-Segment-Anzeige darzustellen.

Die 7-Segment-Anzeige ist im Grunde ein Gerät, das aus 8 LEDs besteht. 7 davon sind streifenförmige LEDs, die eine "8" formen, und es gibt eine etwas kleinere LED als Dezimalpunkt. Diese LEDs sind als a, b, c, d, e, f, g und dp markiert. Sie verfügen über eigene Anoden-Pins und teilen sich Kathoden. Ihre Pin-Positionen sind in der untenstehenden Abbildung dargestellt.

.. image:: img/segment_cathode.png
    :width: 600
    :align: center

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Bauteile.

Es ist durchaus praktisch, ein komplettes Set zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können diese auch einzeln über die folgenden Links erwerben.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENVORSTELLUNG
        - KAUF-LINK
    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Schaltplan**

.. image:: img/circuit_6.5_segment.png

**Verdrahtung**

.. list-table:: Verdrahtung
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - LED Segmentanzeige
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

.. image:: img/segment_bb.jpg
    :width: 600
    :align: center


**Code**

.. note::

    * Öffnen Sie die Datei ``5.10.shiftout_segment.ino`` im Pfad ``3in1-kit\basic_project\5.10.shiftout_segment``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/23b9a3ea-c648-4f33-8622-e279d94ee507/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem der Code erfolgreich hochgeladen wurde, können Sie beobachten, wie die LED Segmentanzeige die Zahlen 0~9 nacheinander anzeigt.

**Wie funktioniert das?**

``shiftOut()`` lässt den 74HC595 8 digitale Signale ausgeben.
Es gibt das letzte Bit der Binärzahl an Q0 aus 
und das erste Bit an Q7. Das bedeutet, 
dass das Schreiben der Binärzahl "00000001" dazu führt, dass Q0 ein hohes Signal und Q1~Q7 ein niedriges Signal ausgibt.

Angenommen, die 7-Segment-Anzeige zeigt die Zahl "2" an,
wir müssen ein hohes Signal für a, b, d, e und g schreiben und ein niedriges Signal für c, f und dp.
Das bedeutet, die Binärzahl "01011011" muss geschrieben werden.
Zur besseren Lesbarkeit verwenden wir die hexadezimale Notation als "0x5b".

.. image:: img/7_segment2.png

* `Hexadezimal <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `BinaryHex Konverter <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

Ebenso können wir die 7-Segment-Anzeige auf die gleiche Weise andere Zahlen anzeigen lassen.
Die folgende Tabelle zeigt die Codes, die diesen Zahlen entsprechen.

.. list-table:: Zeichen Code
    :widths: 20 20 20
    :header-rows: 1

    *   - Zahlen	
        - Binär Code
        - Hex Code  
    *   - 0	
        - 00111111	
        - 0x3f
    *   - 1	
        - 00000110	
        - 0x06
    *   - 2	
        - 01011011	
        - 0x5b
    *   - 3	
        - 01001111	
        - 0x4f
    *   - 4	
        - 01100110	
        - 0x66
    *   - 5	
        - 01101101	
        - 0x6d
    *   - 6	
        - 01111101	
        - 0x7d
    *   - 7	
        - 00000111	
        - 0x07
    *   - 8	
        - 01111111	
        - 0x7f
    *   - 9	
        - 01101111	
        - 0x6f

Geben Sie diese Codes in ``shiftOut()`` ein, um die LED Segmentanzeige die entsprechenden Zahlen anzeigen zu lassen.
