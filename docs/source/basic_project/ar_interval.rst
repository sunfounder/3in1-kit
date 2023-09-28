.. _ar_interval:

5.4 Intervall
===============

Manchmal müssen Sie zwei Dinge gleichzeitig tun. Zum Beispiel möchten Sie vielleicht
eine LED blinken lassen, während Sie einen Tastendruck lesen. In diesem Fall können Sie
nicht ``delay()`` verwenden, weil Arduino Ihr Programm während des ``delay()`` pausiert. Wenn
der Knopf gedrückt wird, während Arduino pausiert und auf das Ende von ``delay()`` wartet, wird Ihr Programm den Tastendruck verpassen.

Ein passendes Beispiel wäre, eine Pizza in Ihrer Mikrowelle aufzuwärmen und gleichzeitig
auf eine wichtige E-Mail zu warten. Sie legen die Pizza in die Mikrowelle und stellen
sie auf 10 Minuten ein. Das Äquivalent zur Verwendung von ``delay()`` wäre, vor der Mikrowelle zu sitzen und dem Timer zuzusehen, wie er von 10 Minuten auf Null herunterzählt. Wenn die wichtige E-Mail in dieser Zeit ankommt, werden Sie sie verpassen.

Was Sie im wirklichen Leben tun würden, wäre, die Pizza einzuschalten und dann
Ihre E-Mails zu überprüfen und vielleicht etwas anderes zu tun (was nicht allzu lange dauert!) und ab und zu würden Sie zur Mikrowelle zurückkehren, um zu sehen, 
ob der Timer Null erreicht hat und somit Ihre Pizza fertig ist.

Diese Skizze zeigt, wie man einen Buzzer ohne die Verwendung von ``delay()`` tönen kann. 
Sie schaltet den Buzzer ein und notiert dann die Zeit. Danach überprüft sie bei jedem Durchlauf von ``loop()``, ob das gewünschte Intervall abgelaufen ist.
Ist dies der Fall, wird der Buzzer getönt und die neue Zeit notiert.
Auf diese Weise tönt der Buzzer kontinuierlich, während die Sketch-Ausführung nie
bei einer einzigen Anweisung ins Stocken gerät.

Basierend auf dieser Bedingung können wir den Code des Knopfes hinzufügen, um die LED zu steuern,
sie wird nicht durch den Buzzer, der Musik spielt, gestört.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|

**Schaltplan**

.. image:: img/circuit_8.5_interval.png



**Verdrahtung**

.. image:: img/5.4_interval_bb.png
    :width: 600
    :align: center

.. note::

    * Öffnen Sie die Datei ``5.4.interval.ino`` im Verzeichnis ``3in1-kit\learning_project\5.4.interval``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0d430b04-ef2d-4e32-8d76-671a3a917cb1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nach erfolgreichem Hochladen des Codes wird der Summer Musik spielen; immer wenn Sie den Knopf drücken, leuchtet die LED auf. Die Arbeit von LED und Summer beeinflusst sich nicht gegenseitig.

**Wie funktioniert das?**


Initialisieren Sie eine Variable namens ``previousMillis``, um die vorherige Betriebszeit des Mikrocontrollers zu speichern.

.. code-block:: arduino

    unsigned long previousMillis = 0;     

Markieren Sie, welche Note gespielt wird.

.. code-block:: arduino

    int thisNote=0; 

Die Intervallzeit jeder Note.

.. code-block:: arduino

    long interval = 1000; 

In ``loop()`` deklarieren Sie ``currentMillis``, um die aktuelle Zeit zu speichern.

.. code-block:: arduino

    unsigned long currentMillis = millis();

Wenn das Intervall zwischen der aktuellen Betriebszeit und der letzten Aktualisierungszeit größer als 1000ms ist, werden bestimmte Funktionen ausgelöst. Gleichzeitig wird previousMillis auf die aktuelle Zeit aktualisiert, um das nächste Auslösen, das 1 Sekunde später stattfinden soll, vorzubereiten.

.. code-block:: arduino

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;// save the last time of the last tone
        //...
    }

Spielen Sie die Noten in der Melodie nacheinander ab.

.. code-block:: arduino

    tone(buzzerPin,melody[thisNote],100);
    interval=1000/noteDurations[thisNote]; // interval at which to tone
    thisNote=(thisNote+1)%(sizeof(melody)/2); //iterate over the notes of the melody

Der Knopf steuert die LED.

.. code-block:: arduino

  // play button & led 
  digitalWrite(ledPin,digitalRead(buttonPin));
