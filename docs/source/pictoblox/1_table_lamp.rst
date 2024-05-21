.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_table_lamp:

2.1 Tischlampe
=================

Hier verbinden wir eine LED auf dem Steckbrett und lassen die Spielfigur (Sprite) das Blinken dieser LED steuern.

Wenn der Button-Sprite auf der Bühne angeklickt wird, blinkt die LED 5-mal und stoppt dann.

.. image:: img/2_button.png

Was Sie lernen werden
-----------------------

- Steckbrett, LEDs und Widerstände
- Aufbau einer Schaltung auf dem Steckbrett
- Sprites löschen und auswählen
- Kostüme wechseln
- Eine begrenzte Anzahl von Wiederholungsschleifen festlegen

Benötigte Komponenten
----------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

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

Sie können diese auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENEINFÜHRUNG
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

Schaltung aufbauen
----------------------

Folgen Sie dem untenstehenden Diagramm, um die Schaltung auf dem Steckbrett aufzubauen.

Da die Anode der LED (der längere Pin) über einen 220Ω-Widerstand mit Pin 9 verbunden ist und die Kathode der LED mit GND verbunden ist, können Sie die LED zum Leuchten bringen, indem Sie Pin 9 auf ein hohes Niveau setzen.

.. image:: img/circuit/led_circuit.png

Programmierung
------------------

Die gesamte Programmierung ist in 3 Teile unterteilt: Im ersten Teil wird der gewünschte Sprite ausgewählt, im zweiten Teil wird das Kostüm des Sprites gewechselt, um ihn anklickbar erscheinen zu lassen, und im dritten Teil wird die LED zum Blinken gebracht.

**1. Button3-Sprite auswählen**

Löschen Sie den vorhandenen Tobi-Sprite mit der Löschen-Taste in der oberen rechten Ecke und wählen Sie erneut einen Sprite aus.

.. image:: img/2_tobi.png

Hier wählen wir den **Button3**-Sprite aus.

.. image:: img/2_button3.png

Klicken Sie in der oberen rechten Ecke auf Kostüme und Sie werden sehen, dass der Button3-Sprite 2 Kostüme hat. Wir setzen **button3-a** auf "freigegeben" und **button3-b** auf "gedrückt".

.. image:: img/2_button3_2.png

**2. Kostümwechsel**.

Wenn der Sprite angeklickt wird (**Events**-Palette), wechselt er zum Kostüm für **button3-b** (**looks**-Palette).

.. image:: img/2_switch.png

**3. LED 5-mal blinken lassen**

Verwenden Sie den [Repeat]-Block, um die LED 5-mal blinken zu lassen (High-> LOW-Zyklus). Vergessen Sie nicht, Pin 13 auf Pin 9 zu ändern und schließlich das Kostüm zurück auf **button3-a** zu wechseln.

* [Repeat 10]: Begrenzte Anzahl von Wiederholungsschleifen. Sie können die Anzahl der Wiederholungen selbst festlegen, aus der **Control**-Palette.

.. image:: img/2_led_on_off.png
