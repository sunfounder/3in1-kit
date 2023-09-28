.. _ar_segment:


5.10 ShiftOut(Segmentanzeige)
===================================

Zuvor haben wir die Funktion ``shiftout()`` verwendet, um acht LEDs leuchten zu lassen. Hier nutzen wir sie, um 0-9 auf der 7-Segment-Anzeige darzustellen.

Die 7-Segment-Anzeige ist im Grunde ein Gerät, das aus 8 LEDs zusammengesetzt ist. Davon bilden 7 streifenförmige LEDs die Form einer "8", und es gibt eine etwas kleinere punktförmige LED als Dezimalpunkt. Diese LEDs sind als a, b, c, d, e, f, g und dp markiert. Sie haben eigene Anodenpins und teilen sich Kathoden. Ihre Pin-Positionen sind in der untenstehenden Abbildung dargestellt.

.. image:: img/segment_cathode.png
    :width: 600
    :align: center

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist sicherlich praktisch, ein komplettes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - \-
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

.. list-table:: Verkabelung
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

.. image:: img/5.10_segment_bb.png
    :width: 600
    :align: center


**Code**

.. note::

    * Öffnen Sie die Datei ``5.10.shiftout_segment.ino`` im Pfad ``3in1-kit\learning_project\5.10.shiftout_segment``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/23b9a3ea-c648-4f33-8622-e279d94ee507/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nach erfolgreichem Hochladen des Codes werden Sie sehen, dass die LED Segmentanzeige nacheinander die Zahlen 0~9 anzeigt.

**Wie funktioniert das?**

``shiftOut()`` lässt den 74HC595 8 digitale Signale ausgeben.
Er gibt das letzte Bit der Binärzahl an Q0 aus
und den Output des ersten Bits an Q7. Das bedeutet,
wenn man die Binärzahl "00000001" schreibt, wird Q0 auf hohem Niveau ausgeben und Q1~Q7 auf niedrigem Niveau.

Angenommen, die 7-Segment-Anzeige zeigt die Zahl "2",
wir müssen ein hohes Niveau für a, b, d, e und g schreiben und ein niedriges Niveau für c, f und dp.
Das bedeutet, dass die Binärzahl "01011011" geschrieben werden muss.
Zur besseren Lesbarkeit verwenden wir die hexadezimale Notation "0x5b".

.. image:: img/7_segment2.png

* `Hexadezimal <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `BinärHex Konverter <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

Ähnlich können wir die 7-Segment-Anzeige auch auf die gleiche Weise andere Zahlen anzeigen lassen.
Die folgende Tabelle zeigt die Codes, die diesen Zahlen entsprechen.

.. list-table:: Zeichencode
    :widths: 20 20 20
    :header-rows: 1

    *   - Zahlen	
        - Binärer Code
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
