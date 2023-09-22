.. _iot_gate:

7. Strombegrenzendes Tor
==================================

In manchen Situationen, wie zum Beispiel auf Parkplätzen, ist eine Mengensteuerung erforderlich.

Hier erstellen wir ein intelligentes Tor: Ein Servo dient als Tor und ein IR-Hinderniserkennungsdetektor wird davor platziert; wird ein Objekt (wie ein Auto) erkannt, öffnet sich das Tor und die Anzahl erhöht sich um 1.
Die Anzahl wird auf einer 7-Segment-Anzeige dargestellt und auch auf die Blynk Cloud hochgeladen, damit Sie sie aus der Ferne einsehen können. Schließlich verfügt Blynk über ein Schalter-Widget, um dieses intelligente Torsystem zu aktivieren oder zu deaktivieren.

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

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|


**1. Bauen Sie den Schaltkreis**

.. note::

    Das ESP8266-Modul benötigt einen hohen Strom, um eine stabile Betriebsumgebung zu gewährleisten, also stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.

.. image:: img/wiring_servo_segment.jpg
    :width: 800

**2. Dashboard bearbeiten**

#. Um die Anzahl aufzuzeichnen, erstellen Sie einen **Datastream** vom Typ **Virtual Pin** auf der **Datastream**-Seite. Setzen Sie den DATENTYP auf ``Integer`` und MIN und MAX auf ``0`` und ``10``.

    .. image:: img/sp220610_165328.png
 
#. Gehen Sie nun zur **Wed Dashboard**-Seite, ziehen Sie ein **Switch**-Widget, um dessen Datenstrom auf **V0** und ein **Label**-Widget, um dessen Datenstrom auf **V8** zu setzen.

    .. image:: img/sp220610_165548.png

**3. Den Code ausführen**

#. Öffnen Sie die Datei ``7.current_limiting_gate.ino`` unter dem Pfad ``3in1-kit\iot_project\7.current_limiting_gate`` oder kopieren Sie diesen Code in die **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/bd829175-652f-4c3e-85b0-048c3fda4555/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Ersetzen Sie die ``Template ID``, den ``Device Name`` und den ``Auth Token`` durch Ihre eigenen. Geben Sie auch die ``ssid`` und das ``password`` des von Ihnen verwendeten WLANs ein. Für detaillierte Anleitungen verweisen Sie bitte auf :ref:`connect_blynk`.
#. Nach Auswahl des richtigen Boards und Ports klicken Sie auf die Schaltfläche **Upoad**.

#. Öffnen Sie den Serienmonitor (Baudrate auf 115200 einstellen) und warten Sie auf eine Aufforderung, wie z.B. eine erfolgreiche Verbindung.

    .. image:: img/2_ready.png

    .. note::

        Wenn die Meldung ``ESP antwortet nicht`` erscheint, wenn Sie sich verbinden, folgen Sie bitte diesen Schritten.

        * Stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.
        * Setzen Sie das ESP8266-Modul zurück, indem Sie den Pin RST für 1 Sekunde mit GND verbinden und dann trennen.
        * Drücken Sie die Reset-Taste auf dem R3-Board.

        Manchmal müssen Sie die obige Operation 3-5 Mal wiederholen, bitte haben Sie Geduld.


#. Klicken Sie jetzt auf das Button Control-Widget in Blynk, um das intelligente Türsystem zu aktivieren. Wenn das IR-Hinderniserkennungsmodul ein Hindernis erkennt, öffnet sich das Tor und die 7-Segment-Anzeige sowie das Count-Widget in Blynk werden um 1 erhöht.

    .. image:: img/sp220610_165548.png

#. Wenn Sie Blynk auf mobilen Geräten verwenden möchten, beachten Sie bitte :ref:`blynk_mobile`.

    .. image:: img/mobile_gate.jpg

**Wie funktioniert das?**

Die Funktion ``BLYNK_WRITE(V0)`` erhält den Status des **Switch**-Widgets und weist ihn der Variablen ``doorFlag`` zu, die verwendet wird, um zu bestimmen, ob das intelligente Torsystem aktiviert ist oder nicht.

.. code-block:: arduino

    BLYNK_WRITE(V0)
    {
        doorFlag = param.asInt(); // Aktiviere das Tor
    }

Im Blynk-Timer wird ``doorFlag`` jede Sekunde geprüft, und wenn es aktiviert ist, wird die Hauptfunktion des Tores ausgeführt.

.. code-block:: arduino

    void myTimerEvent()
    {
        if (doorFlag)
        {
            channelEntrance();
        }
    }

Die Hauptfunktion des Tores ist ``channelEntrance()``.
Wenn ein Objekt sich dem Tor nähert (der Sensor erkennt ein Hindernis), wird ``count`` um 1 erhöht.
Schreiben Sie ``count`` in den Datastream ``V8`` der Blynk Cloud und die 7-Segment-Anzeige auf der Schaltung und öffnen Sie das Tor.
Wenn das Objekt von vorhanden zu nicht vorhanden wechselt, d.h. das Objekt hat das Tor betreten, schließen Sie das Tor.

.. code-block:: arduino

    void channelEntrance()
    {
        int currentState = digitalRead(irPin); // 0:Hindernis 1:kein Hindernis
        if (currentState == 0 && lastState == 1) {
            count=(count+1)%10;
            Blynk.virtualWrite(V8, count);
            showNumber(count);
            operateGate(true);
        } else if ((currentState == 1 && lastState == 0)) {
            operateGate(false);
        }
        lastState = currentState;
    }

Die Funktion ``showNumber(int num)`` dient dazu, die 7-Segment-Anzeige den Wert anzeigen zu lassen.

.. code-block:: arduino

    void showNumber(int num)
    {
        digitalWrite(STcp, LOW); //ST_CP erden und so lange auf LOW halten, wie Daten übertragen werden
        shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
        digitalWrite(STcp, HIGH); //ST_CP hochziehen, um die Daten zu speichern
    }

Die Funktion ``operateGate(bool openGate)`` öffnet das Tor langsam, wenn die Referenz ``True`` ist, und schließt das Tor langsam, wenn die Referenz ``False`` ist.

.. code-block:: arduino

    void operateGate(bool openGate) {
        if (openGate == true) 
        {
            // open gate
            while (angle <= 90) { 
            angle++;
            myservo.write(angle);
            delay(5);
            }
        } else {
            // close gate
            while (angle >= 0){ 
            angle--;
            myservo.write(angle);
            delay(5);
            }
        }
    }