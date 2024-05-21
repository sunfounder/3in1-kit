.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_shiftout:

5.9 ShiftOut(LED)
=======================

``shiftOut()`` lässt 74HC595 8 digitale Signale ausgeben. Das letzte Bit der Binärzahl wird an Q0 und das erste Bit an Q7 ausgegeben. In anderen Worten, wenn man die Binärzahl "00000001" schreibt, wird Q0 auf hohem Niveau ausgegeben und Q1~Q7 auf niedrigem Niveau.

In diesem Projekt lernen Sie, wie man den 74HC595 verwendet. 74HC595 besteht aus einem 8-Bit-Schieberegister und einem Speicherregister mit dreizuständigen parallelen Ausgängen. Er wandelt serielle Eingaben in parallele Ausgaben um, sodass Sie IO-Ports eines MCU sparen können.

Insbesondere kann der 74hc595 durch Schreiben einer 8-Bit-Binärzahl 8 Pins für die digitale Signalabgabe ersetzen.

* `Binärzahl - Wikipedia <https://en.wikipedia.org/wiki/Binary_number>`_

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen, hier ist der Link:

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

    *   - KOMPONENTENEINFÜHRUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
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

* Wenn MR (Pin10) auf hohem Niveau und OE (Pin13) auf niedrigem Niveau ist, wird Daten im ansteigenden Flanken von SHcp eingegeben und gelangt durch den ansteigenden Flanken von SHcp ins Speicherregister.
* Wenn die beiden Uhren miteinander verbunden sind, ist das Schieberegister immer einen Puls vor dem Speicherregister.
* Im Speicherregister gibt es einen seriellen Shift-Eingangspin (Ds), einen seriellen Ausgangspin (Q) und einen asynchronen Reset-Button (niedriges Niveau).
* Das Speicherregister gibt einen Bus mit einem parallelen 8-Bit und in drei Zuständen aus.
* Wenn OE aktiviert ist (niedriges Niveau), werden die Daten im Speicherregister auf den Bus (Q0 ~ Q7) ausgegeben.

**Verdrahtung**

.. image:: img/74hc595_bb.jpg
    :width: 800
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.9.shiftout_led.ino`` im Pfad ``3in1-kit\basic_project\5.9.shiftout_led``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/4c208eb3-67f0-40f7-999a-0eeca8b6b466/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem Sie den Code erfolgreich auf das R3-Board hochgeladen haben, sehen Sie, dass die LEDs nacheinander leuchten.

**Wie funktioniert das?**

Deklarieren Sie ein Array und speichern Sie mehrere 8-Bit-Binärzahlen, die verwendet werden, um den Arbeitszustand der acht von 74HC595 gesteuerten LEDs zu ändern.

.. code-block:: arduino

    int datArray[] = {B00000000, B00000001, B00000011, B00000111, B00001111, B00011111, B00111111, B01111111, B11111111};

Zuerst ``STcp`` auf niedriges Niveau setzen und dann auf hohes Niveau.
Dies erzeugt eine ansteigende Flanke von STcp.

.. code-block:: arduino

    digitalWrite(STcp,LOW); 

``shiftOut()`` wird verwendet, um ein Byte Daten bitweise auszugeben. 
Das bedeutet, ein Byte Daten in ``datArray[num]`` mit dem ``DS``-Pin in das Schieberegister zu verschieben. **MSBFIRST** bedeutet, von den hohen Bits zu verschieben.

.. code-block:: arduino

    shiftOut(DS,SHcp,MSBFIRST,datArray[num]);

Nach ``digitalWrite(STcp,HIGH)`` wird ``STcp`` im ansteigenden Takt sein. 
Zu diesem Zeitpunkt werden die Daten im Schieberegister ins Speicherregister verschoben.

.. code-block:: arduino

    digitalWrite(STcp,HIGH);

Ein Byte Daten wird nach 8 Mal in das Speicherregister übertragen. 
Dann werden die Daten des Speicherregisters auf den Bus (Q0-Q7) ausgegeben. 
Zum Beispiel wird ``B00000001`` die von Q0 gesteuerte LED einschalten und die von Q1~Q7 gesteuerten LEDs ausschalten.
