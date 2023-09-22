.. _car_speed:

3. Geschwindigkeit erhöhen
===============================

Zusätzlich zum digitalen Signal (HIGH/LOW) kann der Eingang von L298N auch ein PWM-Signal empfangen, um die Geschwindigkeit des Ausgangs zu steuern.

Mit anderen Worten, wir können ``AnalogWrite()`` verwenden, um die Bewegungsgeschwindigkeit des Autos zu steuern.

In diesem Projekt lassen wir das Auto seine Vorwärtsgeschwindigkeit allmählich ändern, zuerst beschleunigend und dann verlangsamend.

**Verdrahtung**

Die Verdrahtung dieses Projekts entspricht :ref:`car_move_code`.

**Code**

.. note::

    * Öffnen Sie die Datei ``3.speed_up.ino`` im Pfad ``3in1-kit\car_project\3.speed_up``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
    * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/4253e39c-3990-4a47-8a2a-047497b76e2d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem das Programm ausgeführt wurde, wird das Auto allmählich beschleunigen und dann allmählich verlangsamen.

**Wie funktioniert das?**

Das Ziel dieses Projekts ist es, verschiedene PWM-Werte an IN1~IN4 zu schreiben, um die Vorwärtsgeschwindigkeit des Autos zu steuern.

#. Verwenden Sie die ``for()``-Anweisung, um ``speed`` in Schritten von 5 zu geben, schreiben Sie Werte von 0 bis 255, damit Sie die Änderung in der Vorwärtsgeschwindigkeit des Autos sehen können.

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

#. Über die Funktion ``moveForward()``.

    Im Gegensatz zu :ref:`car_move_code`, das direkt hohe/niedrige Pegel an IN1~IN4 gibt, übergeben wir hier einen Parameter ``speed`` dorthin, wo wir hohe Pegel geben müssen.

    .. code-block:: arduino

        void moveForward(int speed) {
            analogWrite(in1, 0);
            analogWrite(in2, speed);
            analogWrite(in3, speed);
            analogWrite(in4, 0);
        }

* `for <https://www.arduino.cc/reference/en/language/structure/control-structure/for/>`_

Die ``for``-Anweisung wird verwendet, um einen Block von Anweisungen in geschweiften Klammern zu wiederholen. Ein Inkrementzähler wird normalerweise verwendet, um die Schleife zu inkrementieren und zu beenden.

    .. code-block:: arduino

        for (initialization; condition; increment) {
        // statement(s);
        }

    * ``initialization``: geschieht zuerst und genau einmal.
    * ``condition``: Bei jedem Durchlauf der Schleife wird die Bedingung geprüft; wenn sie wahr ist, wird der Anweisungsblock und das Inkrement ausgeführt, dann wird die Bedingung erneut geprüft. Wenn die Bedingung falsch wird, endet die Schleife.
    * ``increment``: wird bei jedem Durchlauf der Schleife ausgeführt, wenn die Bedingung wahr ist.
