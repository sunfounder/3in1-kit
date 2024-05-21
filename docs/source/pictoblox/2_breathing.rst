.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_breathing_led:

2.2 Atmende LED
========================

Verwenden Sie nun eine andere Methode, um die Helligkeit der LED zu steuern. Anders als im vorherigen Projekt wird hier die Helligkeit der LED langsam reduziert, bis sie vollständig erlischt.

Wenn der Sprite auf der Bühne angeklickt wird, erhöht sich die Helligkeit der LED langsam und erlischt dann sofort.

.. image:: img/3_ap.png

Was Sie lernen werden
------------------------

- Den Ausgabewert des PWM-Pins einstellen
- Variablen erstellen
- Ändern der Helligkeit des Sprites

Benötigte Komponenten
------------------------

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

    *   - KOMPONENTENÜBERSICHT
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
-----------------------

Dieses Projekt verwendet denselben Schaltkreis wie das vorherige Projekt :ref:`sh_table_lamp`. Statt jedoch HIGH/LOW zu verwenden, um die LEDs ein- oder auszuschalten, wird in diesem Projekt das `PWM - Wikipedia <https://en.wikipedia.org/wiki/Pulse-width_modulation>`_ Signal verwendet, um die LED langsam heller zu machen oder zu dimmen.

Der PWM-Signalbereich liegt zwischen 0-255. Auf dem Arduno Uno-Board können die Pins 3, 5, 6, 9, 10, 11 ein PWM-Signal ausgeben; auf dem Mega2560 sind es die Pins 2 - 13, 44 - 46.

.. image:: img/circuit/led_circuit.png

Programmierung
------------------

**1. Einen Sprite auswählen**

Löschen Sie den Standard-Sprite, klicken Sie auf die Schaltfläche **Choose a Sprite** in der unteren rechten Ecke des Sprite-Bereichs, geben Sie **button3** in das Suchfeld ein und klicken Sie dann darauf, um es hinzuzufügen.

.. image:: img/3_sprite.png

**2. Eine Variable erstellen**.

Erstellen Sie eine Variable namens **pwm**, um den Wert der PWM-Änderung zu speichern.

Klicken Sie auf die **Variables**-Palette und wählen Sie **Make a Variable**.

.. image:: img/3_ap_va.png

Geben Sie den Namen der Variable ein; es kann jeder Name sein, aber es wird empfohlen, seine Funktion zu beschreiben. Der Datentyp ist Zahl und für alle Sprites.

.. image:: img/3_ap_pwm.png

Nach dem Erstellen sehen Sie **pwm** innerhalb der **Variables**-Palette und im aktivierten Zustand. Das bedeutet, dass diese Variable auf der Bühne erscheinen wird. Sie können versuchen, sie zu deaktivieren und zu sehen, ob pwm noch auf der Bühne präsent ist.

.. image:: img/3_ap_0.png

**3. Den Anfangszustand festlegen**

Wenn der **button3**-Sprite angeklickt wird, wechseln Sie das Kostüm zu **button-b** (angeklickter Zustand) und setzen Sie den Anfangswert der Variable **pwm** auf 0.

* [set pwm to 0]: aus der **Variables**-Palette, um den Wert der Variable festzulegen.

.. image:: img/3_ap_brightness.png

**4. Die LED immer heller machen**

Da der Bereich von pwm 255 ist, wird durch den [repeat]-Block die Variable **pwm** um 5 auf 255 akkumuliert und dann in den [set PWM pin]-Block eingegeben, sodass Sie sehen können, wie die LED langsam aufleuchtet.

* [change pwm by 5]: aus der **Variablen**-Palette. Lässt die Variable jedes Mal eine bestimmte Zahl ändern. Es kann eine positive oder negative Zahl sein. Positiv bedeutet jedes Mal eine Erhöhung, negativ bedeutet jedes Mal eine Verringerung. Hier wird die Variable pwm jedes Mal um 5 erhöht.
* [set PWM pin]: aus der **Arduino Uno**-Palette, um den Ausgabewert des PWM-Pins festzulegen.

.. image:: img/3_ap_1.png

Schließlich wechseln Sie das Kostüm von button3 zurück zu **button-a** und setzen den Wert des PWM-Pins auf 0, sodass die LED langsam aufleuchtet und dann wieder erlischt.

.. image:: img/3_ap_2.png

