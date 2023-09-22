.. _ar_eeprom:

6.2 Elektronischer Würfel
=============================

Hier verwenden wir einen Knopf, eine 7-Segment-Anzeige und den 74hc595, um einen elektronischen Würfel zu erstellen.
Jedes Mal, wenn der Knopf gedrückt wird, wird eine zufällige Zahl zwischen 1 und 6 generiert und auf der 7-Segment-Anzeige dargestellt.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

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

Sie können diese auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|

**Schaltplan**

.. image:: img/circuit_8.9_eeprom.png

**Verkabelung**

.. image:: img/wiring_electronic_dice.png
    :width: 800
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``6.2.electronic_dice.ino`` im Pfad ``3in1-kit\basic_project\6.2.electronic_dice``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8d8ad340-b1de-4518-917b-caaf07e4baf4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nach erfolgreichem Hochladen des Codes zeigt die 7-Segment-Anzeige schnell die Zahlen 0-7 an. Wenn Sie den Knopf drücken, zeigt sie eine zufällige Zahl an und stoppt das Scrollen. Das Scrollen beginnt erneut, wenn Sie den Knopf wieder drücken.

**Wie funktioniert das?**

Dieses Projekt basiert auf :ref:`ar_segment` mit einem Knopf, um das Scrollen auf der 7-Segment-Anzeige zu starten/pausieren.

1. Initialisieren Sie jeden Pin und lesen Sie den Wert des Knopfes.

    .. code-block:: arduino

        void setup ()
        {

            ...
            attachInterrupt(digitalPinToInterrupt(buttonPin), rollDice, FALLING);
        }

    * Der Interrupt wird hier verwendet, um den Zustand des Knopfes zu lesen. Der Standardwert von ``buttonPin`` ist niedrig und ändert sich von niedrig zu hoch, wenn der Knopf gedrückt wird.
    * ``rollDice`` stellt die Funktion dar, die aufgerufen wird, wenn der Interrupt ausgelöst wird. Sie dient zum Umschalten des Werts der Variablen ``state``.
    * ``FALLING`` bedeutet, dass der Interrupt ausgelöst wird, wenn der ``buttonPin`` von niedrig zu hoch geht.

2. Wenn die Variable ``state`` 0 ist, wird die Funktion ``showNumber()`` aufgerufen, um die 7-Segment-Anzeige eine zufällige Zahl zwischen 1 und 7 anzuzeigen.

    .. code-block:: arduino

        void loop()
        {
            if (state == 0) {
                showNumber((int)random(1, 7));
                delay(50);
            }
        }

3. Über die Funktion ``rollDice()``.

    .. code-block:: arduino

        void rollDice() {
            state = !state;
        }
    
    Wenn diese Funktion aufgerufen wird, wechselt sie den Wert von state, zum Beispiel von 1 beim letzten Mal zu 0 dieses Mal.

4. Über die Funktion ``showNumber()``.

    .. code-block:: arduino

        void showNumber(int num) {
            digitalWrite(STcp, LOW); //ST_CP erden und solange niedrig halten, wie Daten übertragen werden
            shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
            //setzen Sie den Latch-Pin zurück, um dem Chip zu signalisieren, dass er 
            //nicht mehr auf Informationen hören muss
            digitalWrite(STcp, HIGH); //ST_CPST_CP hochziehen, um die Daten zu speichern
        }
    
    Dies ist der Code innerhalb von ``loop()`` im Projekt :ref:`ar_segment` in der Funktion ``showNumber()``.
