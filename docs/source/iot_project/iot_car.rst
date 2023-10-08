.. _iot_car:

8. IoT Auto
====================

Für dieses Projekt haben wir die Blynk-APP auf dem Handy verwendet, um das Auto zu steuern. Sie müssen jedoch :ref:`car_projects` konsultieren, um das Auto zusammenzubauen und ein grundlegendes Verständnis dafür zu erhalten.
Im Zeitalter der Verbreitung des 5G-Netzwerks könnte dieser Modus zu einer der Hauptproduktionsmethoden in vielen Branchen werden. Lassen Sie uns also dieses Spiel im Voraus erleben.

**1. Schaltkreis aufbauen**

.. image:: img/wiring_iot_car.png
    :width: 800


**2. Dashboard bearbeiten**

In Blynk auf dem Handy können keine Datastreams bearbeitet werden. Daher müssen wir diese Schritte immer noch auf der Web-Seite durchführen.

#. Erstellen Sie auf der **Datastream**-Seite einen **Datastream** vom Typ **Virtual Pin**, um den X-Achsen-Wert des Joysticks zu erfassen. Setzen Sie NAME auf ``Xvalue``, DATENTYP auf ``Integer`` und MIN und MAX auf ``-10`` und ``10``.

    .. image:: img/sp220613_164507.png

#. Erstellen Sie einen **Datastream** vom Typ **Virtual Pin**, um den Y-Achsen-Wert des Joysticks zu erfassen. Setzen Sie NAME auf ``Yvalue``, DATENTYP auf ``Integer``, MIN und MAX auf ``-10`` und ``10``.

    .. image:: img/sp220613_164717.png

Führen Sie dann die folgenden Schritte auf Ihrem Handy durch.

1. Suchen Sie in GOOGLE Play oder im APP Store nach "Blynk IoT" (nicht Blynk(legacy)) und laden Sie es herunter.
2. Nach dem Öffnen der APP melden Sie sich an. Dieses Konto sollte mit dem Konto auf dem Web-Client übereinstimmen.
3. Gehen Sie dann zum Dashboard (wenn Sie keines haben, erstellen Sie eines), und Sie werden sehen, dass das Dashboard für Mobilgeräte und Web voneinander unabhängig sind.

.. image:: img/APP_1.jpg

4. Klicken Sie auf das Bearbeitungssymbol.
5. Klicken Sie auf den leeren Bereich.
6. Wählen Sie ein Joystick-Widget aus.

.. image:: img/APP_2.jpg

7. Jetzt sehen Sie ein Joystick-Widget im leeren Bereich, klicken Sie darauf.
8. Die Joystick-Einstellungen erscheinen, wählen Sie die von Ihnen in den Datastreams eingestellten Xvalue und Yvalue.
9. Kehren Sie zur Dashboard-Seite zurück, und Sie können den Joystick nach Belieben bedienen.

.. image:: img/APP_3.jpg

**3. Code ausführen**

#. Öffnen Sie die Datei ``8.iot_car.ino`` unter dem Pfad ``3in1-kit\iot_project\8.iot_car`` oder kopieren Sie diesen Code in die **Arduino IDE**.

    .. raw:: html 
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/a1db6c35-2f26-425c-8636-53d2df7936d7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Ersetzen Sie die ``Template ID``, ``Device Name`` und ``Auth Token`` durch Ihre eigenen Angaben. Geben Sie auch die ``ssid`` und das ``password`` des von Ihnen verwendeten WLANs ein. Für detaillierte Anleitungen konsultieren Sie bitte :ref:`connect_blynk`.
#. Wählen Sie das richtige Board und den Port aus und klicken Sie auf den **Upoad**-Button.

#. Öffnen Sie den Seriellen Monitor (Baudrate auf 115200 einstellen) und warten Sie, bis eine Meldung wie eine erfolgreiche Verbindung erscheint.

    .. image:: img/2_ready.png

    .. note::

        Wenn die Meldung ``ESP reagiert nicht`` erscheint, wenn Sie sich verbinden, folgen Sie bitte diesen Schritten:

        * Stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.
        * Setzen Sie das ESP8266-Modul zurück, indem Sie den Pin RST 1 Sekunde lang auf GND verbinden und dann abziehen.
        * Drücken Sie die Reset-Taste auf dem R3-Board.

        Manchmal müssen Sie die obige Operation 3-5 Mal wiederholen, bitte haben Sie Geduld.

#. Ziehen Sie jetzt das USB-Kabel ab und versorgen Sie den Wagen nur mit einer 9V-Batterie. Warten Sie, bis die LED aufleuchtet, was bedeutet, dass das Auto mit Blynk verbunden ist.
#. Öffnen Sie Blynk auf Ihrem Handy, und Sie können das Joystick-Widget verwenden, um die Bewegung des Autos zu steuern.

    .. image:: img/iot_car.jpg

**Wie funktioniert das?**

Diese Funktionen dienen zur Steuerung der Bewegung des Autos.

.. code-block:: arduino

    void moveForward(int speed) {...}
    void moveBackward(int speed) {...}
    void turnRight(int speed) {...}
    void turnLeft(int speed) {...}
    void stopMove() {...}

Der IoT-Bereich liest die Werte des Joystick-Widgets aus und weist sie den Variablen ``Xvalue`` und ``Yvalue`` zu.

.. code-block:: arduino

    int Xvalue = 0;
    int Yvalue = 0;

    BLYNK_WRITE(V9)
    {
        Xvalue = param.asInt();
    }

    BLYNK_WRITE(V10)
    {
        Yvalue = param.asInt();
    }

In ``loop()`` lässt man das Auto verschiedene Aktionen basierend auf ``Xvalue`` und ``Yvalue`` ausführen.

.. code-block:: arduino

    if (Yvalue >= 5) {
        moveForward(255);
    } else if (Yvalue <= -5) {
        moveBackward(255);
    } else if (Xvalue >= 5) {
        turnRight(150);
    } else if (Xvalue <= -5) {
        turnLeft(150);
    } else {
        stopMove();
    }

Ebenso fügen Sie eine Netzwerkstatus-Bestimmung zu ``loop()`` hinzu, um eine LED aufzuleuchten, wenn sie mit Blynk Cloud verbunden ist.

.. code-block:: arduino

    if (!Blynk.connected()) {
        digitalWrite(ledPin, LOW);
        Serial.print("offline!");
        bool result = Blynk.connect();
        Serial.println(result);
    } else {
        digitalWrite(ledPin, HIGH);
    }