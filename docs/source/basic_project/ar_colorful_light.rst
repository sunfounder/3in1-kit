.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_rgb:

2.2 Buntes Licht
==============================================

Wie wir wissen, kann Licht überlagert werden. Beispielsweise ergibt die Kombination von blauem Licht und grünem Licht cyanfarbenes Licht, rotes Licht und grünes Licht ergeben gelbes Licht.
Dies wird als "Das additive Farbmischverfahren" bezeichnet.

* `Additive Farbmischung - Wikipedia <https://en.wikipedia.org/wiki/Additive_color>`_

Basierend auf dieser Methode können wir die drei Grundfarben verwenden, um das sichtbare Licht jeder Farbe gemäß unterschiedlicher spezifischer Gewichtungen zu mischen. Zum Beispiel kann Orange erzeugt werden, indem man mehr Rot und weniger Grün verwendet.

In diesem Kapitel werden wir die RGB-LED verwenden, um das Geheimnis der additiven Farbmischung zu erkunden!

Eine RGB-LED entspricht der Kapselung einer roten LED, einer grünen LED und einer blauen LED unter einem Lampenschirm, wobei die drei LEDs einen gemeinsamen Kathodenpin teilen.
Da jedem Anodenpin das elektrische Signal bereitgestellt wird, kann das Licht der entsprechenden Farbe angezeigt werden.
Durch Änderung der elektrischen Signalintensität jeder Anode können verschiedene Farben erzeugt werden.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist definitiv praktisch, ein ganzes Kit zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch einzeln über die folgenden Links kaufen.

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

**Schaltplan**

.. image:: img/circuit_2.2_rgb.png

Die PWM-Pins 11, 10 und 9 steuern die roten, grünen und blauen Pins der RGB-LED jeweils an und verbinden den gemeinsamen Kathodenpin mit GND.
Dadurch kann die RGB-LED durch Überlagern von Licht auf diesen Pins mit verschiedenen PWM-Werten eine bestimmte Farbe anzeigen.

**Verdrahtung**

.. image:: img/rgb_led_sch.png

Eine RGB-LED hat 4 Pins: Der längste Pin ist der gemeinsame Kathodenpin, der normalerweise mit GND verbunden ist,
der linke Pin neben dem längsten Pin ist Rot und die 2 Pins rechts sind Grün und Blau.

.. image:: img/2.2_colorful_light_bb.png
    :width: 600
    :align: center

**Code**

Hier können wir unsere Lieblingsfarbe in einer Zeichensoftware (wie Paint) auswählen und sie mit der RGB-LED anzeigen.

.. note::

   * Sie können die Datei ``2.2.colorful_light.ino`` im Pfad ``3in1-kit\learning_project\2.analogWrite\2.2.colorful_light`` öffnen. 
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/5d70e864-4f34-4090-b65d-904350091936/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. image:: img/edit_colors.png

Geben Sie den RGB-Wert in ``color_set()`` ein, und Sie werden sehen, dass die RGB-LED die von Ihnen gewünschten Farben anzeigt.

**Wie funktioniert das?**

In diesem Beispiel wird die Funktion zum Zuweisen von Werten an die drei Pins von RGB in einer unabhängigen Unterfunktion ``color()`` verpackt.

.. code-block:: arduino

    void color (unsigned char red, unsigned char green, unsigned char blue)
    {
        analogWrite(redPin, red);
        analogWrite(greenPin, green);
        analogWrite(bluePin, blue);
    }

In ``loop()`` arbeitet der RGB-Wert als Eingabeargument, um die Funktion ``color()`` aufzurufen, sodass die RGB unterschiedliche Farben emittieren kann.

.. code-block:: arduino

    void loop() 
    {    
        color(255, 0, 0); //  red 
        delay(1000); 
        color(0,255, 0); //  green  
        delay(1000);  
        color(0, 0, 255); //  blue  
        delay(1000);
    }
