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

Wenn Sie in einem Projekt, das Sensoren verwendet, einige ``delay()``-Befehle nutzen, werden Sie vielleicht feststellen, dass bei Aktivierung dieser Sensoren das Programm eventuell keine Wirkung zeigt.
Dies liegt daran, dass die Verzögerungsanweisung das Programm anhält und das Programm das vom Sensor an die Hauptsteuerplatine gesendete Signal nicht erfassen kann.

In diesem Fall kann eine Unterbrechung (Interrupt) verwendet werden. Ein Interrupt stellt sicher, dass das Programm keinen Impuls verpasst.

In diesem Kapitel verwenden wir den aktiven Summer und Tasten, um den Prozess der Verwendung von Unterbrechungen zu erleben.

In der ``loop()``-Funktion wird ``delay(1000)`` verwendet, um Sekunden zu zählen.
Legen Sie den Knopf, um den Summer zu steuern, in den ISR, sodass er nicht durch die Verzögerung gestört wird und die Aufgabe reibungslos ausgeführt werden kann.

.. note::
    ISRs sind spezielle Funktionen mit einigen einzigartigen Einschränkungen, die die meisten anderen Funktionen nicht haben. Ein ISR kann keine Parameter haben und sollte nichts zurückgeben.
    Im Allgemeinen sollte ein ISR so kurz und schnell wie möglich sein. Wenn Ihr Skript mehrere ISRs verwendet, kann immer nur einer gleichzeitig ausgeführt werden. Andere Unterbrechungen werden nach Beendigung des aktuellen in einer Reihenfolge ausgeführt, die von ihrer Priorität abhängt.

**Benötigte Komponenten**

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

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF LINK

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
    *   - :ref:`cpn_buzzer`
        - \-

**Schaltplan**

.. image:: img/circuit_8.6_interval.png

**Verkabelung**

.. image:: img/interrupt_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

    * Öffnen Sie die Datei ``5.13.interrupt.ino`` im Pfad ``3in1-kit\basic_project\5.13.interrupt``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/6111757d-dd63-4c4c-95b5-9d96fb0843f0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, schalten Sie den Serial Monitor ein und Sie werden sehen, dass jede Sekunde eine automatisch hochzählende Zahl ausgegeben wird. Wenn Sie den Knopf drücken, gibt der Summer einen Ton aus.
Die Knopf-gesteuerte Summerfunktion und die Zeitfunktion beeinflussen einander nicht.

**Wie funktioniert das?**

* ``attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)``: Fügt einen Interrupt hinzu.

    **Syntax**
        attachInterrupt(digitalPinToInterrupt(pin), ISR, mode) 

    **Parameter**
        * ``pin``: Die Arduino-Pinnummer. Sie sollten ``digitalPinToInterrupt(pin)`` verwenden, um den eigentlichen Digitalpin in eine spezifische Interrupt-Nummer umzuwandeln. Wenn Sie zum Beispiel an Pin 3 anschließen, verwenden Sie ``digitalPinToInterrupt(3)`` als ersten Parameter.
        * ``ISR``: Der ISR, der aufgerufen wird, wenn der Interrupt auftritt; diese Funktion darf keine Parameter haben und nichts zurückgeben. Diese Funktion wird manchmal als Unterbrechungsbehandlungsroutine bezeichnet.
        * ``mode``: definiert, wann der Interrupt ausgelöst werden soll. Vier Konstanten sind als gültige Werte vordefiniert:

          * ``LOW`` um den Interrupt auszulösen, wenn der Pin niedrig ist.
          * ``CHANGE`` um den Interrupt auszulösen, wenn sich der Pinwert ändert.
          * ``RISING`` um ihn auszulösen, wenn der Pin von niedrig zu hoch wechselt.
          * ``FALLING`` um ihn auszulösen, wenn der Pin von hoch zu niedrig wechselt.

.. note:: 
    Verschiedene Hauptsteuerkarten können Interrupt-Pins unterschiedlich verwenden. Auf der R3-Platine können nur Pin 2 und Pin 3 Unterbrechungen verwenden.
