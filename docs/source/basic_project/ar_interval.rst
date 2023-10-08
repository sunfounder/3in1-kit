.. _ar_interval:

5.4 Intervall
================

Manchmal müssen Sie zwei Dinge gleichzeitig tun. Zum Beispiel möchten Sie
vielleicht eine LED blinken lassen, während Sie einen Tastendruck lesen. In diesem Fall können Sie 
nicht ``delay()`` verwenden, weil Arduino Ihr Programm während des ``delay()`` anhält. Wenn
die Taste gedrückt wird, während Arduino auf das Ende des ``delay()`` wartet, wird Ihr Programm den Tastendruck übersehen.

Ein Vergleich wäre, eine Pizza in Ihrer Mikrowelle aufzuwärmen und gleichzeitig 
auf eine wichtige E-Mail zu warten. Sie legen die Pizza in die Mikrowelle und stellen 
sie auf 10 Minuten. Das Analogon zur Verwendung von ``delay()`` wäre, vor der Mikrowelle zu sitzen und den Timer von 10 Minuten herunterzählen zu sehen, bis 
der Timer null erreicht. Wenn die wichtige E-Mail in dieser Zeit ankommt, 
werden Sie sie verpassen.

Was Sie im wirklichen Leben tun würden, wäre die Pizza einzuschalten, dann 
Ihre E-Mails zu überprüfen und dann vielleicht etwas anderes zu tun (das nicht 
zu lange dauert!) und von Zeit zu Zeit würden Sie zur Mikrowelle zurückkommen, um 
zu sehen, ob der Timer null erreicht hat, was bedeutet, dass Ihre Pizza fertig ist.

Dieses Sketch zeigt, wie man einen Summer ohne Verwendung von ``delay()`` tönt. 
Es schaltet den Summer ein und notiert dann die Zeit. Dann überprüft es bei jedem Durchlauf durch ``loop()``, ob das gewünschte Intervall vergangen ist.
Wenn dies der Fall ist, tönt es den Summer und notiert die neue Zeit.
Auf diese Weise tönt der Summer kontinuierlich, während die Sketch-Ausführung nie 
an einer einzigen Anweisung hängen bleibt.

Aufgrund dieses Zustands können wir den Code der Taste hinzufügen, um die LED zu steuern, 
sie wird nicht durch den Summer, der Musik spielt, gestört.

**Erforderliche Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|



**Schaltplan**

.. image:: img/circuit_8.5_interval.png


**Verdrahtung**

.. image:: img/interval_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.4.interval.ino`` unter dem Pfad ``3in1-kit\basic_project\5.4.interval``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0d430b04-ef2d-4e32-8d76-671a3a917cb1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem der Code erfolgreich hochgeladen wurde, wird der Summer Musik abspielen; jedes Mal, wenn Sie den Knopf drücken, leuchtet die LED auf. Die Funktion von LED und Summer stört sich nicht gegenseitig.

**Wie funktioniert es?**

Initialisieren Sie eine Variable namens ``previousMillis``, um die vorherige Betriebszeit des Mikrocontrollers zu speichern.

.. code-block:: arduino

    unsigned long previousMillis = 0;     

Markieren Sie, welche Note gespielt wird.

.. code-block:: arduino

    int thisNote=0; 

Das Intervall jeder Note.

.. code-block:: arduino

    long interval = 1000; 

In ``loop()``, deklarieren Sie ``currentMillis``, um die aktuelle Zeit zu speichern.

.. code-block:: arduino

    unsigned long currentMillis = millis();

Wenn das Intervall zwischen der aktuellen Betriebszeit und der letzten Aktualisierungszeit größer als 1000ms ist, werden bestimmte Funktionen ausgelöst. Aktualisieren Sie gleichzeitig die previousMillis auf die aktuelle Zeit für das nächste Auslösen, das 1 Sekunde später erfolgen soll.  

.. code-block:: arduino

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;// speichern Sie die letzte Zeit des letzten Tons
        //...
    }

Spielen Sie die Noten der Melodie nacheinander ab.

.. code-block:: arduino

    tone(buzzerPin,melody[thisNote],100);
    interval=1000/noteDurations[thisNote]; // Intervall zum Tönen
    thisNote=(thisNote+1)%(sizeof(melody)/2); // Iterieren über die Noten der Melodie

Der Knopf steuert die LED.

.. code-block:: arduino

  // Knopf & LED steuern 
  digitalWrite(ledPin,digitalRead(buttonPin));
