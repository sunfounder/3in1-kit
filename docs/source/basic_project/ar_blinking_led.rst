.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_blink:

1.1 Hallo, LED!
=======================================

Genau wie das Ausdrucken von „Hello, world!“ der erste Schritt beim Erlernen der Programmierung ist, so ist die Anwendung eines Programms zum Steuern einer LED die traditionelle Einführung in die physische Programmierung.

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

Sie können diese auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
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

**Schaltplan**

.. image:: img/circuit_1.1_led.png

Das Prinzip dieser Schaltung ist einfach und die Stromrichtung wird in der Abbildung angezeigt. Wenn Pin 9 ein hohes Signal (5V) ausgibt, leuchtet die LED nach dem 220-Ohm-Strombegrenzungswiderstand auf. Wenn Pin 9 ein niedriges Signal (0V) ausgibt, schaltet sich die LED aus.

**Verdrahtung**

.. image:: img/wiring_led.png
    :width: 400
    :align: center

**Code**

.. note::

   * Sie können die Datei ``1.1.hello_led.ino`` unter dem Pfad ``3in1-kit\basic_project\1.1.hello_led`` öffnen. 
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.



.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/0497f915-5bf8-41a2-8e0f-b013130a57f5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nach erfolgreichem Hochladen des Codes sehen Sie die LED blinken.

**Wie funktioniert das?**

Hier verbinden wir die LED mit dem digitalen Pin 9, deshalb müssen wir zu Beginn des Programms eine int-Variable namens ledPin deklarieren und ihr den Wert 9 zuweisen.

.. code-block:: arduino

    const int ledPin = 9;

Nun initialisieren Sie den Pin in der ``setup()``-Funktion, wo Sie den Pin auf den ``OUTPUT``-Modus setzen müssen.

.. code-block:: arduino

    void setup() {
        pinMode(ledPin, OUTPUT);
    }

In ``loop()``, wird ``digitalWrite()`` verwendet, um ein 5V-High-Level-Signal für ledPin bereitzustellen, was einen Spannungsunterschied zwischen den LED-Pins verursacht und die LED einschaltet.

.. code-block:: arduino

    digitalWrite(ledPin, HIGH);

Wenn das Level-Signal auf LOW geändert wird, wird das Signal von ledPin auf 0 V zurückgesetzt, um die LED auszuschalten.

.. code-block:: arduino

    digitalWrite(ledPin, LOW);

Ein Intervall zwischen Ein- und Ausschalten ist erforderlich, damit Menschen die Änderung sehen können, deshalb verwenden wir einen ``delay(1000)``-Code, um den Controller 1000 ms lang nichts tun zu lassen.

.. code-block:: arduino

    delay(1000);   
