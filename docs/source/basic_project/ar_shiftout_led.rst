.. _ar_shiftout:

5.9 ShiftOut(LED)
=======================

``shiftOut()`` lässt den 74HC595 8 digitale Signale ausgeben. Dabei wird das letzte Bit der Binärzahl an Q0 und das erste Bit an Q7 ausgegeben. Das bedeutet, die Binärzahl "00000001" lässt Q0 ein hohes Signal ausgeben und Q1~Q7 ein niedriges Signal.

In diesem Projekt lernen Sie den 74HC595 kennen. Der 74HC595 besteht aus einem 8-Bit-Schieberegister und einem Speicherregister mit dreistufigen parallelen Ausgängen. Er wandelt serielle Eingaben in parallele Ausgaben um, sodass Sie IO-Ports eines MCU sparen können.

Spezifisch kann der 74HC595 8 Pins für den digitalen Signalausgang durch das Schreiben einer 8-Bit-Binärzahl ersetzen.

* `Binärzahl - Wikipedia <https://en.wikipedia.org/wiki/Binary_number>`_

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist sicherlich praktisch, ein ganzes Set zu kaufen, hier ist der Link:

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Schaltplan**

.. image:: img/circuit_6.4_74hc595.png

* Wenn MR (Pin10) auf hohem Niveau und OE (Pin13) auf niedrigem Niveau ist, wird das Daten in der aufsteigenden Flanke von SHcp eingegeben und geht durch die aufsteigende Flanke von SHcp in das Speicherregister.
* Wenn die beiden Uhren miteinander verbunden sind, ist das Schieberegister immer einen Puls vor dem Speicherregister.
* Es gibt einen seriellen Shift-Eingangspin (Ds), einen seriellen Ausgangspin (Q) und einen asynchronen Reset-Button (niedriges Niveau) im Speicherregister.
* Das Speicherregister gibt einen Bus mit einem parallelen 8-Bit und in drei Zuständen aus.
* Wenn OE aktiviert (niedriges Niveau) ist, werden die Daten im Speicherregister an den Bus (Q0 ~ Q7) ausgegeben.

**Verdrahtung**

.. image:: img/5.9_74hc595_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.9.shiftout_led.ino`` im Pfad ``3in1-kit\learning_project\5.9.shiftout_led``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/4c208eb3-67f0-40f7-999a-0eeca8b6b466/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem Sie die Codes auf das R4-Board hochgeladen haben, sehen Sie, wie die LEDs nacheinander angehen.

**Wie funktioniert das?**

Deklarieren Sie ein Array und speichern Sie mehrere 8-Bit-Binärzahlen, die verwendet werden, um den Arbeitszustand der acht von 74HC595 gesteuerten LEDs zu ändern.

.. code-block:: arduino

    int datArray[] = {B00000000, B00000001, B00000011, B00000111, B00001111, B00011111, B00111111, B01111111, B11111111};

Zuerst ``STcp`` auf niedriges Niveau setzen und dann auf hohes Niveau. 
Es wird eine aufsteigende Flankenimpuls von STcp erzeugt.

.. code-block:: arduino

    digitalWrite(STcp,LOW); 

``shiftOut()`` wird verwendet, um ein Byte Daten bitweise auszugeben, 
was bedeutet, ein Byte Daten in ``datArray[num]`` an das Schieberegister mit dem 
``DS``-Pin zu senden. **MSBFIRST** bedeutet, von den hohen Bits zu verschieben.

.. code-block:: arduino

    shiftOut(DS,SHcp,MSBFIRST,datArray[num]);

Nachdem ``digitalWrite(STcp,HIGH)`` ausgeführt wurde, befindet sich ``STcp`` an der aufsteigenden Flanke. 
Zu diesem Zeitpunkt werden die Daten im Schieberegister in das Speicherregister verschoben.

.. code-block:: arduino

    digitalWrite(STcp,HIGH);

Ein Byte Daten wird nach 8 Mal ins Speicherregister übertragen. 
Dann werden die Daten des Speicherregisters an den Bus (Q0-Q7) ausgegeben. 
Zum Beispiel wird shiftout ``B00000001`` die von Q0 gesteuerte LED einschalten und die von Q1~Q7 gesteuerten LEDs ausschalten.

