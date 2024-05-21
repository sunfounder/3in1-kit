.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_interrupt:

5.13 Unterbrechung
=======================

Wenn Sie in einem Projekt, das Sensoren verwendet, einige ``delay()``-Befehle verwenden, werden Sie vielleicht feststellen, dass das Programm nicht reagiert, wenn diese Sensoren ausgelöst werden.
Dies liegt daran, dass die Delay-Anweisung das Programm anhält und es nicht in der Lage ist, das Signal zu empfangen, das der Sensor an die Hauptsteuerplatine sendet.

In diesem Fall kann eine Unterbrechung (Interrupt) verwendet werden. Ein Interrupt stellt sicher, dass das Programm keinen Impuls verpasst.

In diesem Kapitel verwenden wir den aktiven Summer und Tasten, um den Vorgang der Verwendung von Interrupts zu erleben.

In der ``loop()``-Funktion wird ``delay(1000)`` verwendet, um Sekunden zu zählen.
Legen Sie die Taste, die den Summer steuert, in die ISR, sodass sie nicht durch die Verzögerung gestört wird und die Aufgabe reibungslos abgeschlossen werden kann.

.. note::
    ISRs sind spezielle Funktionen, die einige einzigartige Einschränkungen haben, die die meisten anderen Funktionen nicht haben. Eine ISR kann keine Parameter haben und sollte nichts zurückgeben.
    Grundsätzlich sollte eine ISR so kurz und schnell wie möglich sein. Wenn Ihr Sketch mehrere ISRs verwendet, kann immer nur eine gleichzeitig ausgeführt werden. Andere Unterbrechungen werden nach Abschluss der aktuellen in einer Reihenfolge ausgeführt, die von ihrer Priorität abhängt.

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
    *   - :ref:`cpn_buzzer`
        - \-


**Schaltplan**

.. image:: img/circuit_8.6_interval.png

**Verdrahtung**

.. image:: img/5.13_interrupt_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.13.interrupt.ino`` unter dem Pfad ``3in1-kit\learning_project\5.13.interrupt``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/6111757d-dd63-4c4c-95b5-9d96fb0843f0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, öffnen Sie den Serial Monitor und Sie werden sehen, dass jede Sekunde eine automatisch erhöhende Nummer ausgegeben wird. Wenn Sie den Knopf drücken, wird der Summer ertönen.
Die von der Taste gesteuerte Summerfunktion und die Zeitfunktion stehen nicht in Konflikt miteinander.

**Wie funktioniert das?**

* ``attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)``: Fügt einen Unterbrecher hinzu.

    **Syntax**
        attachInterrupt(digitalPinToInterrupt(pin), ISR, mode) 

    **Parameter**
        * ``pin``: Die Arduino-Pin-Nummer. Sie sollten ``digitalPinToInterrupt(pin)`` verwenden, um den tatsächlichen Digital-Pin in eine spezifische Unterbrecher-Nummer zu konvertieren. Zum Beispiel, wenn Sie an Pin 3 anschließen, verwenden Sie sein ``digitalPinToInterrupt(3)`` als ersten Parameter.
        * ``ISR``: Die ISR, die aufgerufen wird, wenn der Unterbrecher auftritt; diese Funktion darf keine Parameter annehmen und nichts zurückgeben. Diese Funktion wird manchmal als Interrupt-Service-Routine bezeichnet.
        * ``mode``: definiert, wann der Unterbrecher ausgelöst werden sollte. Vier Konstanten sind als gültige Werte vordefiniert:

          * ``LOW``, um den Unterbrecher auszulösen, wenn der Pin niedrig ist,
          * ``CHANGE``, um den Unterbrecher auszulösen, wenn sich der Pin-Wert ändert.
          * ``RISING``, um auszulösen, wenn der Pin von niedrig auf hoch wechselt.
          * ``FALLING``, um auszulösen, wenn der Pin von hoch auf niedrig wechselt.

.. note:: 
    Verschiedene Hauptsteuerplatinen können Unterbrecherpins unterschiedlich verwenden. Auf Ihrer Platine können nur Pin 2 und Pin 3 Unterbrechungen nutzen.
