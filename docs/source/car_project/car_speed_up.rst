.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _car_speed:

3. Beschleunigung
===================

Zusätzlich zum digitalen Signal (HIGH/LOW) kann der Eingang des L9110-Moduls auch ein PWM-Signal empfangen, um die Geschwindigkeit des Ausgangs zu steuern.

Das bedeutet, dass wir ``AnalogWrite()`` verwenden können, um die Fahrgeschwindigkeit des Autos zu steuern.

In diesem Projekt lassen wir das Auto seine Vorwärtsgeschwindigkeit schrittweise ändern, zuerst beschleunigend und dann verlangsamend.

**Verdrahtung**

Die Verkabelung für dieses Projekt ist identisch mit :ref:`car_move_code`.

**Code**

.. note::

    * Öffnen Sie die Datei ``3.speed_up.ino`` im Pfad ``3in1-kit\car_project\3.speed_up``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c15276c1-2359-4de6-ac82-a14a72e041c6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Nachdem das Programm läuft, wird das Auto schrittweise beschleunigen und dann allmählich abbremsen.

**Wie funktioniert das?**

Ziel dieses Projekts ist es, unterschiedliche PWM-Werte an die Eingangspins des L9110-Moduls zu schreiben, um die Vorwärtsgeschwindigkeit des Autos zu steuern.

#. Verwenden Sie die ``for()``-Schleife, um ``speed`` in Schritten von 5 zu setzen, schreibend Werte von 0 bis 255, damit Sie die Veränderung der Vorwärtsgeschwindigkeit des Autos sehen können.

    .. code-block:: arduino

        void loop() {
            for(int i=0;i<=255;i+=5){
                moveForward(i);
                delay(500);
            }
            for(int i=255;i>=0;i-=5){
                moveForward(i);
                delay(500);
            }
        }

#. Über die ``moveForward()`` Funktion.

    Im Gegensatz zu :ref:`car_move_code`, das direkt hohe/niedrige Pegel an die Eingangspins des L9110-Moduls gibt, übergeben wir hier einen Parameter ``speed``, dort, wo wir hohe Pegel geben müssen.

    .. code-block:: arduino

        void moveForward(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, speed);
            analogWrite(B_1B, speed);
            analogWrite(B_1A, 0);
        }

* `for <https://www.arduino.cc/reference/en/language/structure/control-structure/for/>`_

Die ``for``-Anweisung wird verwendet, um einen Anweisungsblock in geschweiften Klammern zu wiederholen. Ein Inkrementzähler wird in der Regel verwendet, um die Schleife zu inkrementieren und zu beenden. 

    .. code-block:: arduino

        for (initialization; condition; increment) {
        // statement(s);
        }

    * ``initialization``: findet zuerst und genau einmal statt.
    * ``condition``: bei jedem Durchlauf der Schleife wird condition getestet; wenn es wahr ist, wird der Anweisungsblock und das Inkrement ausgeführt, dann wird die condition erneut getestet. Wenn die condition falsch wird, endet die Schleife.
    * ``increment``: wird bei jedem Durchlauf der Schleife ausgeführt, wenn condition wahr ist.
