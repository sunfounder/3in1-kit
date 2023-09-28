.. _ar_blink:

1.1 Hallo, LED!
=======================================

Genauso wie das Ausdrucken von "Hallo, Welt!" der erste Schritt beim Erlernen des Programmierens ist, so ist das Verwenden eines Programms zum Ansteuern einer LED die traditionelle Einführung in das Erlernen der physischen Programmierung.

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

**Schaltplan**

.. image:: img/circuit_1.1_led.png

Das Prinzip dieser Schaltung ist einfach, und die Stromrichtung ist in der Abbildung dargestellt. Wenn Pin 9 ein hohes Signal (5V) ausgibt, leuchtet die LED nach dem 220 Ohm-Strombegrenzungswiderstand auf. Wenn Pin 9 ein niedriges Signal (0V) ausgibt, erlischt die LED.

**Verdrahtung**

.. image:: img/1.1_hello_led_bb.png
    :width: 400
    :align: center

**Code**

.. note::

   * Sie können die Datei ``1.1.hello_led.ino`` unter dem Pfad ``3in1-kit\learning_project\1.1.hello_led`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/0497f915-5bf8-41a2-8e0f-b013130a57f5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, sehen Sie die LED blinken.

**Wie funktioniert das?**

Hier verbinden wir die LED mit dem digitalen Pin 9, daher müssen wir zu Beginn des Programms eine int-Variable namens ledpin deklarieren und ihr den Wert 9 zuweisen.

.. code-block:: arduino

    const int ledPin = 9;

Jetzt initialisieren Sie den Pin in der ``setup()``-Funktion, wo Sie den Pin auf den Modus ``OUTPUT`` setzen müssen.

.. code-block:: arduino

    void setup() {
        pinMode(ledPin, OUTPUT);
    }

In ``loop()`` wird ``digitalWrite()`` verwendet, um ein 5V-Hochpegelsignal für ledpin bereitzustellen, was zu einem Spannungsunterschied zwischen den LED-Pins führt und die LED zum Leuchten bringt.

.. code-block:: arduino

    digitalWrite(ledPin, HIGH);

Wenn das Pegelsignal auf LOW geändert wird, wird das Signal von ledPin auf 0 V zurückgesetzt, um die LED auszuschalten.

.. code-block:: arduino

    digitalWrite(ledPin, LOW);

Es wird ein Intervall zwischen Ein- und Ausschalten benötigt, damit die Menschen die Änderung sehen können. Daher verwenden wir den Code ``delay(1000)``, um den Controller 1000 ms lang nichts tun zu lassen.

.. code-block:: arduino

    delay(1000); 
