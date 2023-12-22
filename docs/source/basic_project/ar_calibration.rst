.. _ar_calibration:

5.14 Calibration
================

Lorsque vous utilisez des composants d'entrée analogique, tels que des photorésistances, des capteurs d'humidité du sol, etc., vous pouvez constater que leur plage de lecture n'est pas de 0 à 1023, mais plutôt une plage comme 0 à 800 ou 600 à 1000, car il est impossible d'atteindre les limites de ces dispositifs en utilisation normale.

Dans ce cas, une technique de calibration des entrées du capteur peut être utilisée. Au démarrage, faites mesurer les lectures du capteur par la carte de contrôle pendant cinq secondes et enregistrez les lectures les plus hautes et les plus basses. Cette lecture de cinq secondes définit les valeurs minimales et maximales attendues des lectures prises pendant le cycle.

Dans ce projet, nous utilisons une photorésistance et un buzzer passif pour implémenter un jeu semblable au `theremin <https://en.wikipedia.org/wiki/Theremin>`_ en utilisant la technique de calibration décrite ci-dessus.

.. note::
    Le `theremin <https://en.wikipedia.org/wiki/Theremin>`_ est un instrument de musique électronique qui ne nécessite aucun contact physique. Il génère différents tons en détectant la position des mains du joueur.

**Composants requis**

Pour ce projet, nous aurons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DE CE KIT
        - LIEN
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Schéma**

.. image:: img/circuit_8.8_calibration.png

**Câblage**

.. image:: img/calibration_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.14.calibration.ino`` situé dans le dossier ``3in1-kit\basic_project\5.14.calibration``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléversez le code via l'`Éditeur Web Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/9cbcaae0-3c9d-4e33-9957-548f92a9aab7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Après le téléversement réussi du code, la LED s'allumera, et nous aurons 5 secondes pour calibrer la plage de détection de la photorésistance. Cela est dû au fait que nous pouvons être dans un environnement lumineux différent à chaque utilisation (par exemple, l'intensité de la lumière est différente entre midi et le crépuscule).

À ce moment, nous devons balancer nos mains en haut et en bas sur la photorésistance, et la plage de mouvement de la main sera calibrée à la plage de jeu de cet instrument.

Après 5 secondes, la LED s'éteindra et nous pourrons agiter nos mains sur la photorésistance pour jouer.


**Comment ça fonctionne ?**

#. Définir les valeurs initiales et les pins de tous les composants.

    .. code-block:: arduino

        const int buzzerPin = 9;
        const int ledPin = 8;
        const int photocellPin = A0;  //photoresistor attach to A2
    
        int lightLow = 1023;
        int lightHigh = 0;
    
        int sensorValue = 0;        // value read from the sensor
        int pitch = 0;           // sensor value converted into LED 'bars'
    
        unsigned long previousMillis = 0;
        const long interval = 5000;

#. Mettez en place un processus de calibration dans ``setup()``.

    .. code-block:: arduino

        void setup()
        {
            pinMode(buzzerPin, OUTPUT); // make buzzer output
            pinMode(ledPin, OUTPUT); // make the LED pin output

            /* calibrate the photoresistor max & min values */
            previousMillis = millis();
            digitalWrite(ledPin, HIGH);
            while (millis() - previousMillis <= interval) {
                sensorValue = analogRead(photocellPin);
                if (sensorValue > lightHigh) {
                    lightHigh = sensorValue;
                }
                if (sensorValue < lightLow) {
                    lightLow = sensorValue;
                }
            }
            digitalWrite(ledPin, LOW);
        }

    Le déroulement du travail est le suivant.

    * en utilisant ``millis()`` pour le chronométrage avec un intervalle de 5000 ms.

    .. code-block:: arduino

        previousMillis = millis();
        ...
        while (millis() - previousMillis <= interval) {
        ...
        }

    * Pendant ces cinq secondes, agitez une main autour de la photorésistance, les valeurs maximales et minimales ​​de la lumière détectée sont enregistrées et assignées respectivement à ``lightHigh`` et ``lightLow``.

    .. code-block:: arduino
        
        sensorValue = analogRead(photocellPin);
        if (sensorValue > lightHigh) {
            lightHigh = sensorValue;
        }
        if (sensorValue < lightLow) {
            lightLow = sensorValue;
        }

#. Vous pouvez maintenant commencer à jouer ce Theremin. Lisez la valeur de la photorésistance à ``sensorValue`` et mappez-la de la petite plage à la grande plage pour être utilisée comme fréquence du buzzer. 

    .. code-block:: arduino

        void loop()
        {
        /* play*/
        sensorValue = analogRead(photocellPin); //read the value of A0
        pitch = map(sensorValue, lightLow, lightHigh, 50, 6000);  // map to the buzzer frequency
        if (pitch > 50) {
            tone(buzzerPin, pitch, 20);
        }
        delay(10);
        }