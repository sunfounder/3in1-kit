.. _sh_colorful_ball:

2.3 Bunte Kugeln
=====================

In diesem Projekt werden wir die RGB-LEDs verschiedene Farben anzeigen lassen.

Wenn Sie auf verschiedene farbige Kugeln im Bühnenbereich klicken, leuchtet die RGB-LED in unterschiedlichen Farben auf.

.. image:: img/4_color.png

Was Sie lernen werden
--------------------------

- Das Prinzip der RGB-LED
- Sprites kopieren und verschiedene Kostüme auswählen
- Überlagerung der drei Grundfarben

Benötigte Komponenten
--------------------------

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

Schaltung aufbauen
---------------------

Eine RGB-LED verpackt drei LEDs in Rot, Grün und Blau in eine transparente oder halbtransparente Plastikhülle. Durch Ändern der Eingangsspannung der drei Pins und Überlagern von ihnen können, statistisch gesehen, 16.777.216 verschiedene Farben erzeugt werden.

.. image:: img/4_rgb.png
    :width: 300

.. image:: img/circuit/rgb_circuit.png

Programmierung
------------------

**1. Sprite auswählen**

Löschen Sie das Standard-Sprite und wählen Sie das **Ball**-Sprite aus.

.. image:: img/4_ball.png

Und duplizieren Sie es 5 Mal.

.. image:: img/4_duplicate_ball.png

Wählen Sie verschiedene Kostüme für diese 5 **Ball**-Sprites aus und verschieben Sie sie an die entsprechenden Positionen.

.. note::

    Die Kostümfarbe des **Ball3**-Sprites muss manuell auf Rot geändert werden.

.. image:: img/4_rgb1.png
    :width: 800

**2. RGB-LEDs in der entsprechenden Farbe leuchten lassen**

Bevor wir den Code verstehen, müssen wir das `RGB-Farbmodell <https://en.wikipedia.org/wiki/RGB_color_model>`_ verstehen.

Das RGB-Farbmodell ist ein additives Farbmodell, bei dem Rot, Grün und Blau in verschiedenen Kombinationen hinzugefügt werden, um eine Vielzahl von Farben wiederzugeben.

Additive Farbmischung: Rot zu Grün ergibt Gelb; Grün zu Blau ergibt Cyan; Blau zu Rot ergibt Magenta; alle drei Grundfarben zusammen ergeben Weiß.

.. image:: img/4_rgb_addition.png
  :width: 400

Der Code, um die RGB-LED gelb leuchten zu lassen, lautet also wie folgt.

.. image:: img/4_yellow.png

Wenn auf das Ball-Sprite (gelber Ball) geklickt wird, setzen wir Pin 11 hoch (rote LED an), Pin 10 hoch (grüne LED an) und Pin 9 niedrig (blaue LED aus), damit die RGB-LED gelb leuchtet.

Sie können auf die gleiche Weise Codes für andere Sprites schreiben, damit die RGB-LEDs in den entsprechenden Farben leuchten.

**3. Ball2-Sprite (hellblau)**

.. image:: img/4_blue.png

**4. Ball3-Sprite (rot)**

.. image:: img/4_red.png

**5. Ball4-Sprite (grün)**

.. image:: img/4_green.png

**6. Ball5-Sprite (lila)**

.. image:: img/4_purple.png
