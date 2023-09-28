.. _ar_servo:

5.5 Interne Bibliothek nutzen
=======================================

In der Arduino IDE können Sie viele integrierte Bibliotheken nutzen, indem Sie die entsprechende ``.h``-Datei direkt in Ihren Code einfügen.

In diesem Projekt wird die Bibliothek ``Servo`` verwendet, um den Servo anzusteuern, sodass er sich zwischen 0° und 180° drehen kann.

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

Sie können diese auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

**Schaltplan**

.. image:: img/circuit_6.2_servo.png

In diesem Projekt verwenden wir den PWM-Pin 9, um den Servo anzusteuern. Das orangefarbene Kabel des Servos wird mit dem PWM-Pin 9, das rote mit 5V und das braune mit GND verbunden.

**Verdrahtung**

.. image:: img/5.5_swinging_servo_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``5.5.use_internal_library.ino`` im Pfad ``3in1-kit\learning_project\5.5.use_internal_library``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fa27db71-b191-4eda-b5c7-bbbe5f2652ca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem Sie die Codes erfolgreich auf das R4-Board hochgeladen haben, sehen Sie den Servo-Arm im Bereich von 0° bis 180° rotieren.

**Wie funktioniert das?**

Mit dem Aufruf der Bibliothek ``Servo.h`` können Sie den Servo einfach steuern.

.. code-block:: arduino

    #include <Servo.h> 

Bibliotheksfunktionen:

.. code-block:: arduino

    Servo

Erstellt ein **Servo**-Objekt zur Steuerung eines Servos.

.. code-block:: arduino

    uint8_t attach(int pin); 

Ruft ``pinMode()`` auf, um einen Pin in einen Servo-Treiber zu verwandeln und gibt bei einem Fehler 0 zurück.

.. code-block:: arduino

    void detach();

Löst einen Pin vom Servo-Treiben.

.. code-block:: arduino

    void write(int value); 

Stellt den Winkel des Servos in Grad ein, von 0 bis 180.

.. code-block:: arduino

    int read();

Gibt den Wert zurück, der mit dem letzten ``write()`` eingestellt wurde.

.. code-block:: arduino

    bool attached(); 

Gibt 1 zurück, wenn der Servo derzeit angehängt ist.
