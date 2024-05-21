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

Wie wir wissen, kann Licht überlagert werden. Beispielsweise ergibt die Kombination von blauem und grünem Licht ein türkises Licht und die von rotem und grünem Licht ein gelbes Licht.
Dies wird als "Additive Farbmischung" bezeichnet.

* `Additive Farbe - Wikipedia <https://en.wikipedia.org/wiki/Additive_color>`_

Auf Basis dieser Methode können wir durch Mischen der drei Grundfarben nach verschiedenen spezifischen Gewichtungen jedes sichtbare Licht erzeugen. Beispielsweise entsteht Orange aus viel Rot und wenig Grün.

In diesem Kapitel werden wir die Geheimnisse der additiven Farbmischung mit einer RGB-LED erkunden!

Eine RGB-LED entspricht dem Kapseln einer roten, einer grünen und einer blauen LED unter einer Lampe, wobei die drei LEDs einen gemeinsamen Kathodenpin teilen.
Da das elektrische Signal für jeden Anodenpin bereitgestellt wird, kann das Licht der entsprechenden Farbe angezeigt werden. 
Durch Änderung der elektrischen Signalintensität jeder Anode kann sie dazu gebracht werden, verschiedene Farben zu erzeugen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

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

Sie können sie auch separat über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

**Schaltplan**

.. image:: img/circuit_2.2_rgb.png

Die PWM-Pins 11, 10 und 9 steuern die Rot-, Grün- und Blau-Pins der RGB-LED jeweils an und verbinden den gemeinsamen Kathodenpin mit GND.
Dadurch kann die RGB-LED durch Überlagerung von Licht auf diesen Pins mit verschiedenen PWM-Werten eine bestimmte Farbe anzeigen.

**Verdrahtung**

.. image:: img/rgb_led_sch.png

Eine RGB-LED hat 4 Pins: Der längste Pin ist der gemeinsame Kathodenpin, der normalerweise mit GND verbunden ist,
der linke Pin neben dem längsten Pin ist Rot, und die 2 Pins rechts sind Grün und Blau.

.. image:: img/colorful_light_bb.jpg
    :width: 500
    :align: center

**Code**

Hier können wir unsere Lieblingsfarbe in Zeichensoftware (wie Paint) auswählen und sie mit der RGB-LED anzeigen.

.. note::

   * Sie können die Datei ``2.2.colorful_light.ino`` im Pfad ``3in1-kit\basic_project\2.analogWrite\2.2.colorful_light`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/5d70e864-4f34-4090-b65d-904350091936/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. image:: img/edit_colors.png

Schreiben Sie den RGB-Wert in ``color_set()``, dann werden Sie sehen, wie die RGB-LED die gewünschten Farben anzeigt.

**Wie funktioniert das?**

In diesem Beispiel wird die Funktion, die Werte den drei Pins von RGB zuweist, in einer unabhängigen Unterfunktion ``color()`` verpackt.

.. code-block:: arduino

    void color (unsigned char red, unsigned char green, unsigned char blue)
    {
        analogWrite(redPin, red);
        analogWrite(greenPin, green);
        analogWrite(bluePin, blue);
    }

In ``loop()`` dient der RGB-Wert als Eingabeargument, um die Funktion ``color()`` aufzurufen und somit die RGB-LED verschiedene Farben ausstrahlen zu lassen.

.. code-block:: arduino

    void loop() 
    {    
        color(255, 0, 0); //  rot 
        delay(1000); 
        color(0,255, 0); //  grün  
        delay(1000);  
        color(0, 0, 255); //  blau  
        delay(1000);
    }
