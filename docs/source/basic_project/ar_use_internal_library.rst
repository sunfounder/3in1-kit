.. _ar_servo:

5.5 Interne Bibliothek verwenden
=======================================

In der Arduino IDE können Sie viele eingebaute Bibliotheken nutzen, indem Sie die entsprechende ``.h`` Datei direkt in Ihren Code einfügen.

In diesem Projekt wird die ``Servo`` Bibliothek verwendet, um das Servo anzusteuern, damit es sich zwischen 0° und 180° drehen kann.

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
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|


**Schaltplan**

.. image:: img/circuit_6.2_servo.png

In diesem Projekt verwenden wir den PWM-Pin 9, um das Servo anzusteuern. Das orangefarbene Kabel des Servos wird mit dem PWM-Pin 9 verbunden, das rote mit 5V und das braune mit GND.

**Verdrahtung**

.. image:: img/swinging_servo_bb.jpg

**Code**

.. note::

    * Öffnen Sie die Datei ``5.5.use_internal_library.ino`` unter dem Pfad ``3in1-kit\basic_project\5.5.use_internal_library``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fa27db71-b191-4eda-b5c7-bbbe5f2652ca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Nachdem Sie die Codes auf das R3-Board hochgeladen haben, können Sie sehen, wie der Servoarm sich im Bereich von 0° bis 180° dreht.

**Wie funktioniert das?**

Durch den Aufruf der Bibliothek ``Servo.h`` können Sie das Servo einfach steuern.

.. code-block:: arduino

    #include <Servo.h> 

Bibliotheksfunktionen：

.. code-block:: arduino

    Servo

Erstellen Sie ein **Servo** Objekt, um ein Servo zu steuern.

.. code-block:: arduino

    uint8_t attach(int pin); 

Rufen Sie ``pinMode()`` auf, um einen Pin zu einem Servotreiber zu machen und geben Sie 0 bei Fehlern zurück.

.. code-block:: arduino

    void detach();

Geben Sie einen Pin vom Servo-Antrieb frei.

.. code-block:: arduino

    void write(int value); 

Stellen Sie den Winkel des Servos in Grad ein, von 0 bis 180.

.. code-block:: arduino

    int read();

Geben Sie den mit dem letzten ``write()`` gesetzten Wert zurück.

.. code-block:: arduino

    bool attached(); 

Gibt 1 zurück, wenn das Servo aktuell angeschlossen ist.
