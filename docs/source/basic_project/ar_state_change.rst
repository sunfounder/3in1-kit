.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_state_change:

5.3 Zustandswechsel-Erkennung
=================================

Wenn der Knopf andere Geräte steuert, kann er nicht nur bei Betätigung arbeiten und bei Loslassen stoppen.
Es ist auch möglich, bei jedem Tastendruck den Arbeitszustand zu wechseln.

Um diesen Effekt zu erzielen, müssen Sie wissen, wie Sie den Arbeitszustand beim Drücken des Knopfes zwischen aus und an wechseln können.
Das nennt man "Zustandswechsel-Erkennung".

In diesem Projekt verwenden wir den Knopf, um den Motor zu steuern.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist definitiv praktisch, ein komplettes Set zu kaufen. Hier ist der Link:

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

    *   - KOMPONENTENBESCHREIBUNG
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
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

**Schaltplan**

.. image:: img/circuit_8.3_statechange.png

**Verkabelung**

.. image:: img/5.3_state_change_l9110_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.3.state_change_detection.ino`` im Pfad ``3in1-kit\basic_project\5.3.state_change_detection``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/67a62a3d-46d3-4f5f-889c-364cbdf9b66f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem der Code erfolgreich hochgeladen wurde, drücken Sie den Knopf und der Motor wird sich drehen; bis Sie den Knopf erneut drücken, wird der Motor stoppen.

**Wie funktioniert das?**

#. Variablen erstellen und Pins für den Motor und den Knopf definieren.

    .. code-block:: arduino

        ...
        int detectionState = 0;   
        int buttonState = 0;         
        int lastButtonState = 0;    

    * ``detectionState`` ist ein Flag, dessen Wert bei jedem Tastendruck geändert wird, z.B. 0 dieses Mal, 1 beim nächsten Mal, und so weiter im Wechsel.
    * ``buttonState`` und ``lastButtonState`` werden verwendet, um den aktuellen und den letzten Zustand des Knopfes zu speichern, um zu vergleichen, ob der Knopf gedrückt oder losgelassen wurde.


#. Jeden Pin initialisieren und die Baudrate des seriellen Monitors festlegen.

    .. code-block:: arduino

        void setup() {
            pinMode(buttonPin, INPUT);
            Serial.begin(9600);
            pinMode(B_1A, OUTPUT);
            pinMode(B_1B, OUTPUT);
        }


#. Zuerst den Zustand des Knopfes lesen, und wenn der Knopf gedrückt wird, wechselt die Variable ``detectionState`` ihren Wert von 0 auf 1 oder von 1 auf 0. Wenn ``detectionState`` 1 ist, wird der Motor eingeschaltet. Das hat den Effekt, dass der Motor beim ersten Drücken des Knopfes startet, beim nächsten Drücken stoppt und so weiter im Wechsel.

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
            digitalWrite(B_1A,HIGH);
            digitalWrite(B_1B,LOW);
        }else{
            digitalWrite(B_1A,LOW);
            digitalWrite(B_1B,LOW);
        }
        }

    Der gesamte Arbeitsablauf ist wie folgt.

    * Den Knopfwert lesen.

    .. code-block:: arduino

        buttonState = digitalRead(buttonPin);

    * Wenn ``buttonState`` und ``lastButtonState`` nicht gleich sind, bedeutet dies, dass sich der Knopfzustand geändert hat. Fahren Sie mit der nächsten Beurteilung fort und speichern Sie den Knopfzustand zu diesem Zeitpunkt in der Variable ``lastButtonState``. ``delay(50)`` wird verwendet, um Jitter zu eliminieren.
    
    .. code-block:: arduino

        if (buttonState != lastButtonState) {
        ...
            delay(50);
        }
        lastButtonState = buttonState;

    * Wenn der Knopf gedrückt wird, ist sein Wert HIGH. Hier, wenn der Knopf gedrückt wird, wird der Wert der Variable ``detectionState`` geändert, z.B. nach einer Operation von 0 auf 1.

    .. code-block:: arduino

        if (buttonState == HIGH) {
            detectionState=(detectionState+1)%2;
            Serial.print("The detection state is: ");
            Serial.println(detectionState);
            }

    * Wenn die Variable ``detectionState`` 1 ist, lässt den Motor drehen, ansonsten stoppen.

    .. code-block:: arduino

        if(detectionState==1){
            digitalWrite(B_1A,HIGH);
            digitalWrite(B_1B,LOW);
        }else{
            digitalWrite(B_1A,LOW);
            digitalWrite(B_1B,LOW);
        }

