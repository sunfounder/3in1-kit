.. _ar_state_change:

5.3 Zustandsänderungserkennung
=================================

Wenn der Knopf andere Geräte steuert, kann er nicht nur arbeiten, wenn er gedrückt wird, sondern auch stoppen, wenn er losgelassen wird.
Es ist auch möglich, den Arbeitszustand jedes Mal umzuschalten, wenn der Knopf gedrückt wird.

Um diesen Effekt zu erzielen, müssen Sie wissen, wie Sie den Arbeitszustand zwischen Aus und Ein umschalten können, wenn der Knopf gedrückt wird.
Das nennt man "Zustandsänderungserkennung".

In diesem Projekt werden wir den Knopf verwenden, um den Motor zu steuern.

.. **Schaltplan**

.. .. image:: img/circuit_8.3_statechange.png

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

**Schaltplan**

.. image:: img/circuit_8.3_statechange.png

**Verdrahtung**

.. image:: img/5.3_state_change_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.3.state_change_detection.ino`` im Pfad ``3in1-kit\learning_project\5.3.state_change_detection``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/67a62a3d-46d3-4f5f-889c-364cbdf9b66f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem der Code erfolgreich hochgeladen wurde, drücken Sie den Knopf und der Motor wird sich drehen; bis Sie den Knopf erneut drücken, wird der Motor stoppen.



**Wie funktioniert das?**

#. Erstellen Sie Variablen und definieren Sie Pins für den Motor und den Knopf.

    .. code-block:: arduino

        ...
        int detectionState = 0;   
        int buttonState = 0;         
        int lastButtonState = 0;    

    * ``detectionState`` ist eine Flagge, deren Wert sich jedes Mal ändert, wenn der Knopf gedrückt wird, z.B. 0 dieses Mal, 1 das nächste Mal und so weiter abwechselnd.
    * ``buttonState`` und ``lastButtonState`` werden verwendet, um den Zustand des Knopfes dieses Mal und das letzte Mal aufzuzeichnen, um zu vergleichen, ob der Knopf gedrückt oder losgelassen wurde.

#. Initialisieren Sie jeden Pin und setzen Sie die Baudrate des seriellen Monitors.

    .. code-block:: arduino

        void setup() {
            pinMode(buttonPin, INPUT);
            Serial.begin(9600);
            pinMode(A_1A,OUTPUT);
            pinMode(A_1B,OUTPUT);
        }

#. Zuerst lesen Sie den Zustand des Knopfes, und wenn der Knopf gedrückt ist, wird die Variable ``detectionState`` ihren Wert von 0 auf 1 oder von 1 auf 0 umschalten. Wenn ``detectionState`` 1 ist, wird der Motor eingeschaltet. Es hat die Wirkung, dass dieses Mal, wenn der Knopf gedrückt wird, der Motor sich dreht, das nächste Mal, wenn der Knopf gedrückt wird, der Motor stoppt und so weiter abwechselnd.

    .. code-block:: arduino

        void loop() {
        // Toggle the detectionState each time the button is pressed
            buttonState = digitalRead(buttonPin);
            if (buttonState != lastButtonState) {
                if (buttonState == HIGH) {
                detectionState=(detectionState+1)%2;
                Serial.print("The detection state is: ");
                Serial.println(detectionState);
                } 
                delay(50);
            }
            lastButtonState = buttonState;
            
            // According to the detectionState, start the motor
            if(detectionState==1){
                digitalWrite(A_1A,HIGH);
                digitalWrite(A_1B,LOW);
            }else{
                digitalWrite(A_1A,LOW);
                digitalWrite(A_1B,LOW);
            }
        }

    Der gesamte Arbeitsablauf ist wie folgt.

    * Lesen Sie den Knopfwert.

    .. code-block:: arduino

        buttonState = digitalRead(buttonPin);

    * Wenn ``buttonState`` und ``lastButtonState`` nicht gleich sind, bedeutet dies, dass sich der Knopfzustand geändert hat. Fahren Sie mit der nächsten Beurteilung fort und speichern Sie den Knopfzustand zu diesem Zeitpunkt in die Variable ``lastButtonState``. ``delay(50)`` wird verwendet, um das Prellen zu eliminieren.
    
    .. code-block:: arduino

        if (buttonState != lastButtonState) {
        ...
            delay(50);
        }
        lastButtonState = buttonState;

    * Wenn der Knopf gedrückt wird, ist sein Wert HIGH. Hier, wenn der Knopf gedrückt wird, wird der Wert der Variable ``detectionState`` geändert, z.B. von 0 auf 1 nach einer Operation.

    .. code-block:: arduino

        if (buttonState == HIGH) {
            detectionState=(detectionState+1)%2;
            Serial.print("The detection state is: ");
            Serial.println(detectionState);
            }

    * Wenn die Variable ``detectionState`` 1 ist, lassen Sie den Motor drehen, sonst stoppen Sie ihn.

    .. code-block:: arduino

        if(detectionState==1){
            digitalWrite(A_1A,HIGH);
            digitalWrite(A_1B,LOW);
        }else{
            digitalWrite(A_1A,LOW);
            digitalWrite(A_1B,LOW);
        }

