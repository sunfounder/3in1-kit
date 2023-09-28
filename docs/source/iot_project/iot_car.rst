.. _iot_car:

8. IoT-Auto
====================

Für dieses Projekt haben wir die Blynk-App auf dem Smartphone genutzt, um das Auto zu steuern. Allerdings müssen Sie zuerst den Abschnitt :ref:`car_projects` konsultieren, um das Auto zusammenzubauen und ein grundlegendes Verständnis dafür zu bekommen.
In Zeiten der 5G-Netzwerkverbreitung könnte diese Methode in vielen Industrien zu einer der Hauptproduktionsweisen werden. Daher lohnt es sich, diese Technologie vorab zu erleben.

**1. Schaltkreis aufbauen**

.. image:: img/iot_car.png
    :width: 800

**2. Dashboard bearbeiten**

Blynk für Mobilgeräte bietet keine Möglichkeit zur Bearbeitung von Datastreams, daher müssen diese Schritte weiterhin über die Web-Oberfläche erledigt werden.

#. Erstellen Sie einen **Datastream** vom Typ **Virtual Pin** auf der **Datastream**-Seite, um den X-Achsenwert des Joysticks zu speichern. Legen Sie den NAMEN auf ``Xvalue``, den DATENTYP auf ``Integer`` und MIN sowie MAX auf ``-10`` und ``10`` fest.

    .. image:: img/sp220613_164507.png

#. Erstellen Sie einen weiteren **Datastream** vom Typ **Virtual Pin**, um den Y-Achsenwert des Joysticks zu erfassen. Setzen Sie den NAMEN auf ``Yvalue``, den DATENTYP auf ``Integer``, sowie MIN und MAX auf ``-10`` und ``10``.

    .. image:: img/sp220613_164717.png

Führen Sie anschließend die folgenden Schritte auf Ihrem Smartphone durch:

1. Suchen Sie im GOOGLE Play oder im APP Store nach "Blynk IoT" (nicht Blynk(legacy)) und laden Sie die App herunter.
2. Nach dem Öffnen der App melden Sie sich an. Dieses Konto sollte mit dem Konto übereinstimmen, das Sie auf der Web-Oberfläche verwenden.
3. Navigieren Sie dann zum Dashboard (falls noch keines vorhanden ist, erstellen Sie eines). Sie werden feststellen, dass die Dashboards für Mobilgeräte und Web unabhängig voneinander sind.

.. image:: img/APP_1.jpg

4. Klicken Sie auf das Bearbeitungssymbol.
5. Tippen Sie auf einen freien Bereich. 
6. Wählen Sie ein Joystick-Widget aus.

.. image:: img/APP_2.jpg

7. Nun sollten Sie ein Joystick-Widget im freien Bereich sehen, tippen Sie darauf.
8. Die Joystick-Einstellungen werden angezeigt. Wählen Sie die zuvor in den Datastreams festgelegten Xvalue und Yvalue aus.
9. Kehren Sie zur Dashboard-Seite zurück. Nun können Sie den Joystick nach Belieben bedienen.

.. image:: img/APP_3.jpg

**3. Code ausführen**

#. Öffnen Sie die Datei ``8.iot_car.ino`` unter dem Pfad ``3in1-kit\iot_project\8.iot_car`` oder kopieren Sie diesen Code in die **Arduino IDE**.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/a1db6c35-2f26-425c-8636-53d2df7936d7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Ersetzen Sie die ``Template ID``, den ``Device Name`` und den ``Auth Token`` durch Ihre eigenen Angaben. Geben Sie zudem die ``ssid`` und das ``password`` des von Ihnen genutzten WLANs ein. Für detaillierte Anleitungen siehe :ref:`connect_blynk`.
#. Wählen Sie das richtige Board und den passenden Port aus und klicken Sie dann auf den **Upoad**-Button.

#. Öffnen Sie den Seriellen Monitor (Baudrate auf 115200 einstellen) und warten Sie, bis eine Meldung über eine erfolgreiche Verbindung erscheint.

    .. image:: img/2_ready.png

    .. note::

        Wenn die Meldung ``ESP is not responding`` beim Verbinden erscheint, folgen Sie bitte diesen Schritten.

        * Stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.
        * Setzen Sie das ESP8266-Modul zurück, indem Sie den Pin RST für 1 Sekunde mit GND verbinden, danach trennen.
        * Drücken Sie die Reset-Taste auf dem R4-Board.

        Manchmal müssen Sie die obigen Schritte 3-5 Mal wiederholen, bitte haben Sie Geduld.

#. Trennen Sie jetzt das USB-Kabel und versorgen Sie den Wagen nur mit einer 9V-Batterie. Warten Sie, bis die LED leuchtet, was darauf hinweist, dass das Auto mit Blynk verbunden ist.
#. Öffnen Sie Blynk auf Ihrem Handy und steuern Sie das Auto mithilfe des Joystick-Widgets.

    .. image:: img/iot_car.jpg

**Wie funktioniert das?**

Diese Funktionen werden zur Steuerung der Bewegungen des Autos verwendet.

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

Im ``loop()`` führt das Auto unterschiedliche Aktionen basierend auf ``Xvalue`` und ``Yvalue`` durch.

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

Fügen Sie außerdem eine Netzwerkstatusbestimmung zum ``loop()`` hinzu, die eine LED aufleuchten lässt, wenn eine Verbindung zur Blynk Cloud besteht.


.. code-block:: arduino

    if (!Blynk.connected()) {
        digitalWrite(ledPin, LOW);
        Serial.print("offline!");
        bool result = Blynk.connect();
        Serial.println(result);
    } else {
        digitalWrite(ledPin, HIGH);
    }